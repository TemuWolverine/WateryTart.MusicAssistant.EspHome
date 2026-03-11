#include "music_assistant.h"
#include "commands.h"
#include "esp_random.h"
#include <cstdio>

namespace music_assistant {

static const char *TAG = "music_assistant";

// ---------------------------------------------------------------------------
// ESPHome lifecycle
// ---------------------------------------------------------------------------

void MusicAssistantComponent::setup() {
  ESP_LOGI(TAG, "Music Assistant component ready, URL: %s", url_.c_str());
}

// ---------------------------------------------------------------------------
// UUID generation (v4 format)
// ---------------------------------------------------------------------------

std::string MusicAssistantComponent::make_uuid() {
  uint32_t r0 = esp_random();
  uint32_t r1 = esp_random();
  uint32_t r2 = esp_random();
  uint32_t r3 = esp_random();

  // Force version 4: set bits 12-15 of time_hi to 0100
  r1 = (r1 & 0xFFFF0FFF) | 0x00004000;
  // Force variant bits: set bits 6-7 of clock_seq_hi to 10
  r2 = (r2 & 0x3FFFFFFF) | 0x80000000;

  char buf[37];
  snprintf(buf, sizeof(buf),
           "%08x-%04x-%04x-%04x-%04x%08x",
           r0,
           (r1 >> 16) & 0xFFFF,
           r1 & 0xFFFF,
           (r2 >> 16) & 0xFFFF,
           r2 & 0xFFFF,
           r3);
  return std::string(buf);
}

// ---------------------------------------------------------------------------
// JSON message builders
// ---------------------------------------------------------------------------

std::string MusicAssistantComponent::make_message(const char *command) {
  std::string msg = "{\"command\":\"";
  msg += command;
  msg += "\",\"message_id\":\"";
  msg += make_uuid();
  msg += "\"}";
  return msg;
}

std::string MusicAssistantComponent::make_message_with_id(const char *command,
                                                           const std::string &id,
                                                           const char *id_label) {
  std::string args = "{\"";
  args += id_label;
  args += "\":\"";
  args += id;
  args += "\"}";
  return make_message_with_args(command, args);
}

std::string MusicAssistantComponent::make_message_with_args(
    const char *command, const std::string &json_args_object) {
  std::string msg = "{\"command\":\"";
  msg += command;
  msg += "\",\"message_id\":\"";
  msg += make_uuid();
  msg += "\",\"args\":";
  msg += json_args_object;
  msg += "}";
  return msg;
}

// ---------------------------------------------------------------------------
// HTTP helpers
// ---------------------------------------------------------------------------

void MusicAssistantComponent::send(const std::string &json_body) {
  std::string endpoint = url_ + "/api";

  esp_http_client_config_t config = {};
  config.url = endpoint.c_str();
  config.method = HTTP_METHOD_POST;
  config.timeout_ms = 10000;

  esp_http_client_handle_t client = esp_http_client_init(&config);

  std::string auth_header = "Bearer " + token_;
  esp_http_client_set_header(client, "Authorization", auth_header.c_str());
  esp_http_client_set_header(client, "Content-Type", "application/json");
  esp_http_client_set_post_field(client, json_body.c_str(),
                                 static_cast<int>(json_body.size()));

  esp_err_t err = esp_http_client_perform(client);
  if (err == ESP_OK) {
    int status = esp_http_client_get_status_code(client);
    ESP_LOGD(TAG, "HTTP POST status: %d", status);
  } else {
    ESP_LOGE(TAG, "HTTP POST failed: %s", esp_err_to_name(err));
  }

  esp_http_client_cleanup(client);
}

void MusicAssistantComponent::send_with_response(
    const std::string &json_body,
    std::function<void(const std::string &)> callback) {
  std::string endpoint = url_ + "/api";

  esp_http_client_config_t config = {};
  config.url = endpoint.c_str();
  config.method = HTTP_METHOD_POST;
  config.timeout_ms = 10000;

  esp_http_client_handle_t client = esp_http_client_init(&config);

  std::string auth_header = "Bearer " + token_;
  esp_http_client_set_header(client, "Authorization", auth_header.c_str());
  esp_http_client_set_header(client, "Content-Type", "application/json");
  esp_http_client_set_post_field(client, json_body.c_str(),
                                 static_cast<int>(json_body.size()));

  esp_err_t err = esp_http_client_perform(client);
  if (err == ESP_OK) {
    int status = esp_http_client_get_status_code(client);
    ESP_LOGD(TAG, "HTTP POST (with response) status: %d", status);

    char buf[4096];
    int read = esp_http_client_read_response(client, buf, sizeof(buf) - 1);
    if (read >= 0) {
      buf[read] = '\0';
    } else {
      buf[0] = '\0';
    }
    callback(std::string(buf));
  } else {
    ESP_LOGE(TAG, "HTTP POST (with response) failed: %s", esp_err_to_name(err));
    callback(std::string());
  }

  esp_http_client_cleanup(client);
}

// ---------------------------------------------------------------------------
// Player commands
// ---------------------------------------------------------------------------

void MusicAssistantComponent::player_play_pause(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayerPlayPause, player_id));
}

void MusicAssistantComponent::player_next(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayerNext, player_id));
}

void MusicAssistantComponent::player_previous(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayerPrevious, player_id));
}

void MusicAssistantComponent::player_play(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayerPlay, player_id));
}

void MusicAssistantComponent::player_pause(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayersCmdPause, player_id));
}

void MusicAssistantComponent::player_stop(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayersCmdStop, player_id));
}

void MusicAssistantComponent::player_resume(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayersCmdResume, player_id));
}

void MusicAssistantComponent::player_volume_set(const std::string &player_id,
                                                 int volume) {
  char args[128];
  snprintf(args, sizeof(args), "{\"player_id\":\"%s\",\"volume_level\":%d}",
           player_id.c_str(), volume);
  send(make_message_with_args(Commands::PlayersCmdVolumeSet, std::string(args)));
}

void MusicAssistantComponent::player_volume_up(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayersCmdVolumeUp, player_id));
}

void MusicAssistantComponent::player_volume_down(const std::string &player_id) {
  send(make_message_with_id(Commands::PlayersCmdVolumeDown, player_id));
}

void MusicAssistantComponent::player_volume_mute(const std::string &player_id,
                                                   bool muted) {
  char args[128];
  snprintf(args, sizeof(args), "{\"player_id\":\"%s\",\"muted\":%s}",
           player_id.c_str(), muted ? "true" : "false");
  send(make_message_with_args(Commands::PlayersCmdVolumeMute, std::string(args)));
}

void MusicAssistantComponent::player_power(const std::string &player_id,
                                            bool powered) {
  char args[128];
  snprintf(args, sizeof(args), "{\"player_id\":\"%s\",\"powered\":%s}",
           player_id.c_str(), powered ? "true" : "false");
  send(make_message_with_args(Commands::PlayersCmdPower, std::string(args)));
}

void MusicAssistantComponent::player_seek(const std::string &player_id,
                                           int position) {
  char args[128];
  snprintf(args, sizeof(args), "{\"player_id\":\"%s\",\"position\":%d}",
           player_id.c_str(), position);
  send(make_message_with_args(Commands::PlayersCmdSeek, std::string(args)));
}

// ---------------------------------------------------------------------------
// State fetch methods
// ---------------------------------------------------------------------------

void MusicAssistantComponent::get_players_all(
    std::function<void(const std::string &)> callback) {
  send_with_response(make_message(Commands::PlayersAll), callback);
}

void MusicAssistantComponent::get_player_active_queue(
    const std::string &player_id,
    std::function<void(const std::string &)> callback) {
  send_with_response(
      make_message_with_id(Commands::PlayerQueuesGetActiveQueue, player_id),
      callback);
}

}  // namespace music_assistant

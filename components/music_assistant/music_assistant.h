#pragma once

#include "esphome/core/component.h"
#include "esphome/core/log.h"
#include "esp_http_client.h"
#include <functional>
#include <string>

namespace music_assistant {

class MusicAssistantComponent : public esphome::Component {
 public:
  void set_url(const std::string &url) { url_ = url; }
  void set_token(const std::string &token) { token_ = token; }

  void setup() override;
  float get_setup_priority() const override { return esphome::setup_priority::AFTER_WIFI; }

  // Player commands (fire and forget)
  void player_play_pause(const std::string &player_id);
  void player_next(const std::string &player_id);
  void player_previous(const std::string &player_id);
  void player_play(const std::string &player_id);
  void player_pause(const std::string &player_id);
  void player_stop(const std::string &player_id);
  void player_resume(const std::string &player_id);
  void player_volume_set(const std::string &player_id, int volume);
  void player_volume_up(const std::string &player_id);
  void player_volume_down(const std::string &player_id);
  void player_volume_mute(const std::string &player_id, bool muted);
  void player_power(const std::string &player_id, bool powered);
  void player_seek(const std::string &player_id, int position);

  // State fetch methods
  void get_players_all(std::function<void(const std::string &)> callback);
  void get_player_active_queue(const std::string &player_id,
                               std::function<void(const std::string &)> callback);

 private:
  std::string url_;
  std::string token_;

  std::string make_uuid();
  std::string make_message(const char *command);
  std::string make_message_with_id(const char *command, const std::string &id,
                                   const char *id_label = "player_id");
  std::string make_message_with_args(const char *command,
                                     const std::string &json_args_object);

  void send(const std::string &json_body);
  void send_with_response(const std::string &json_body,
                          std::function<void(const std::string &)> callback);
};

}  // namespace music_assistant

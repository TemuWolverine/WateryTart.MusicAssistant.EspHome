#pragma once

namespace Commands {

// Auth
constexpr const char *Auth = "auth";
constexpr const char *AuthLogin = "auth/login";
constexpr const char *AuthMe = "auth/me";
constexpr const char *AuthTokenCreate = "auth/token/create";
constexpr const char *AuthTokens = "auth/tokens";

// Player
constexpr const char *PlayerActiveQueue = "player_queues/get_active_queue";
constexpr const char *PlayerGroupVolume = "players/cmd/group_volume";
constexpr const char *PlayerGroupVolumeDown = "players/cmd/group_volume_down";
constexpr const char *PlayerGroupVolumeUp = "players/cmd/group_volume_up";
constexpr const char *PlayerNext = "players/cmd/next";
constexpr const char *PlayerPlay = "players/cmd/play";
constexpr const char *PlayerPlayPause = "players/cmd/play_pause";
constexpr const char *PlayerPrevious = "players/cmd/previous";
constexpr const char *PlayerQueueItems = "player_queues/items";
constexpr const char *PlayerQueuePlayMedia = "player_queues/play_media";
constexpr const char *PlayersAll = "players/all";
constexpr const char *PlayersCmdPause = "players/cmd/pause";
constexpr const char *PlayersCmdResume = "players/cmd/resume";
constexpr const char *PlayersCmdStop = "players/cmd/stop";
constexpr const char *PlayersCmdSeek = "players/cmd/seek";
constexpr const char *PlayersCmdVolumeSet = "players/cmd/volume_set";
constexpr const char *PlayersCmdVolumeUp = "players/cmd/volume_up";
constexpr const char *PlayersCmdVolumeDown = "players/cmd/volume_down";
constexpr const char *PlayersCmdVolumeMute = "players/cmd/volume_mute";
constexpr const char *PlayersCmdPower = "players/cmd/power";
constexpr const char *PlayersGet = "players/get";

// PlayerQueues
constexpr const char *PlayerQueuesAll = "player_queues/all";
constexpr const char *PlayerQueuesClear = "player_queues/clear";
constexpr const char *PlayerQueuesGet = "player_queues/get";
constexpr const char *PlayerQueuesGetActiveQueue = "player_queues/get_active_queue";
constexpr const char *PlayerQueuesItems = "player_queues/items";
constexpr const char *PlayerQueuesNext = "player_queues/next";
constexpr const char *PlayerQueuesPause = "player_queues/pause";
constexpr const char *PlayerQueuesPlay = "player_queues/play";
constexpr const char *PlayerQueuesPlayMedia = "player_queues/play_media";
constexpr const char *PlayerQueuesPlayPause = "player_queues/play_pause";
constexpr const char *PlayerQueuesPrevious = "player_queues/previous";
constexpr const char *PlayerQueuesRepeat = "player_queues/repeat";
constexpr const char *PlayerQueuesResume = "player_queues/resume";
constexpr const char *PlayerQueuesSeek = "player_queues/seek";
constexpr const char *PlayerQueuesShuffle = "player_queues/shuffle";
constexpr const char *PlayerQueuesStop = "player_queues/stop";

}  // namespace Commands

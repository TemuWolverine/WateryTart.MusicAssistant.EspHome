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
constexpr const char *PlayersAddCurrentlyPlayingToFavorites = "players/cmd/add_currently_playing_to_favorites";
constexpr const char *PlayersCmdGroup = "players/cmd/group";
constexpr const char *PlayersCmdGroupMany = "players/cmd/group_many";
constexpr const char *PlayersCmdGroupVolume = "players/cmd/group_volume";
constexpr const char *PlayersCmdGroupVolumeDown = "players/cmd/group_volume_down";
constexpr const char *PlayersCmdGroupVolumeUp = "players/cmd/group_volume_up";
constexpr const char *PlayersCmdNext = "players/cmd/next";
constexpr const char *PlayersCmdPause = "players/cmd/pause";
constexpr const char *PlayersCmdPlay = "players/cmd/play";
constexpr const char *PlayersCmdPlayAnnouncement = "players/cmd/play_announcement";
constexpr const char *PlayersCmdPlayPause = "players/cmd/play_pause";
constexpr const char *PlayersCmdPower = "players/cmd/power";
constexpr const char *PlayersCmdPrevious = "players/cmd/previous";
constexpr const char *PlayersCmdResume = "players/cmd/resume";
constexpr const char *PlayersCmdSeek = "players/cmd/seek";
constexpr const char *PlayersCmdSelectSource = "players/cmd/select_source";
constexpr const char *PlayersCmdSetMembers = "players/cmd/set_members";
constexpr const char *PlayersCmdStop = "players/cmd/stop";
constexpr const char *PlayersCmdUngroup = "players/cmd/ungroup";
constexpr const char *PlayersCmdUngroupMany = "players/cmd/ungroup_many";
constexpr const char *PlayersCmdVolumeDown = "players/cmd/volume_down";
constexpr const char *PlayersCmdVolumeMute = "players/cmd/volume_mute";
constexpr const char *PlayersCmdVolumeSet = "players/cmd/volume_set";
constexpr const char *PlayersCmdVolumeUp = "players/cmd/volume_up";
constexpr const char *PlayersGet = "players/get";
constexpr const char *PlayersGetByName = "players/get_by_name";
constexpr const char *PlayersPlayerControl = "players/player_control";
constexpr const char *PlayersPlayerControls = "players/player_controls";
constexpr const char *PlayersPluginSource = "players/plugin_source";
constexpr const char *PlayersPluginSources = "players/plugin_sources";

// PlayerQueues
constexpr const char *PlayerQueuesAll = "player_queues/all";
constexpr const char *PlayerQueuesClear = "player_queues/clear";
constexpr const char *PlayerQueuesDeleteItem = "player_queues/delete_item";
constexpr const char *PlayerQueuesDontStopTheMusic = "player_queues/dont_stop_the_music";
constexpr const char *PlayerQueuesGet = "player_queues/get";
constexpr const char *PlayerQueuesGetActiveQueue = "player_queues/get_active_queue";
constexpr const char *PlayerQueuesItems = "player_queues/items";
constexpr const char *PlayerQueuesMoveItem = "player_queues/move_item";
constexpr const char *PlayerQueuesNext = "player_queues/next";
constexpr const char *PlayerQueuesPause = "player_queues/pause";
constexpr const char *PlayerQueuesPlay = "player_queues/play";
constexpr const char *PlayerQueuesPlayIndex = "player_queues/play_index";
constexpr const char *PlayerQueuesPlayMedia = "player_queues/play_media";
constexpr const char *PlayerQueuesPlayPause = "player_queues/play_pause";
constexpr const char *PlayerQueuesPrevious = "player_queues/previous";
constexpr const char *PlayerQueuesRepeat = "player_queues/repeat";
constexpr const char *PlayerQueuesResume = "player_queues/resume";
constexpr const char *PlayerQueuesSeek = "player_queues/seek";
constexpr const char *PlayerQueuesShuffle = "player_queues/shuffle";
constexpr const char *PlayerQueuesSkip = "player_queues/skip";
constexpr const char *PlayerQueuesStop = "player_queues/stop";
constexpr const char *PlayerQueuesTransfer = "player_queues/transfer";

// Music — Albums
constexpr const char *MusicAddProviderMapping = "music/provider/add_mapping";
constexpr const char *MusicAlbumGet = "music/albums/get";
constexpr const char *MusicAlbumsCount = "music/albums/count";
constexpr const char *MusicAlbumLibraryItems = "music/albums/library_items";
constexpr const char *MusicAlbumTracks = "music/albums/album_tracks";
constexpr const char *MusicAlbumVersions = "music/albums/album_versions";

// Music — Artists
constexpr const char *MusicArtistAlbums = "music/artists/artist_albums";
constexpr const char *MusicArtistGet = "music/artists/get";
constexpr const char *MusicArtistsCount = "music/artists/count";
constexpr const char *MusicArtistsGet = "music/artists/library_items";
constexpr const char *MusicArtistTracks = "music/artists/artist_tracks";

// Music — Audiobooks
constexpr const char *MusicAudiobooksAudiobookVersions = "music/audiobooks/audiobook_versions";
constexpr const char *MusicAudiobooksCount = "music/audiobooks/count";
constexpr const char *MusicAudiobooksGet = "music/audiobooks/get";
constexpr const char *MusicAudiobooksLibraryItems = "music/audiobooks/library_items";

// Music — Browse & Favourites
constexpr const char *MusicBrowse = "music/browse";
constexpr const char *MusicFavouritesAddItem = "music/favorites/add_item";
constexpr const char *MusicFavouritesRemoveItem = "music/favorites/remove_item";

// Music — Genres
constexpr const char *MusicGenresCount = "music/genres/count";
constexpr const char *MusicGenresGet = "music/genres/get";
constexpr const char *MusicGenresLibraryItems = "music/genres/library_items";

// Music — Library & Items
constexpr const char *MusicGetLibraryItem = "music/get_library_item";
constexpr const char *MusicInProgressItems = "music/in_progress/items";
constexpr const char *MusicItem = "music/item";
constexpr const char *MusicItemByUri = "music/item/by_uri";
constexpr const char *MusicLibraryAddItem = "music/library/add_item";
constexpr const char *MusicLibraryRemoveItem = "music/library/remove_item";
constexpr const char *MusicMarkPlayed = "music/item/mark_played";
constexpr const char *MusicMarkUnplayed = "music/item/mark_unplayed";
constexpr const char *MusicMatchProviders = "music/provider/match_providers";

// Music — Playlists
constexpr const char *MusicPlaylistsAddPlaylistTracks = "music/playlists/add_playlist_tracks";
constexpr const char *MusicPlaylistsCount = "music/playlists/count";
constexpr const char *MusicPlaylistsCreatePlaylist = "music/playlists/create_playlist";
constexpr const char *MusicPlaylistsLibraryItems = "music/playlists/library_items";
constexpr const char *MusicPlaylistsRemovePlaylistTracks = "music/playlists/remove_playlist_tracks";
constexpr const char *MusicPlaylistsGet = "music/playlists/get";
constexpr const char *MusicPlaylistsPlaylistTracks = "music/playlists/playlist_tracks";

// Music — Podcasts
constexpr const char *MusicPodcastsCount = "music/podcasts/count";
constexpr const char *MusicPodcastsGet = "music/podcasts/get";
constexpr const char *MusicPodcastsLibraryItems = "music/podcasts/library_items";
constexpr const char *MusicPodcastsPodcastEpisode = "music/podcasts/podcast_episode";
constexpr const char *MusicPodcastsPodcastEpisodes = "music/podcasts/podcast_episodes";
constexpr const char *MusicPodcastsPodcastVersions = "music/podcasts/podcast_versions";

// Music — Radios
constexpr const char *MusicRadiosCount = "music/radios/count";
constexpr const char *MusicRadiosGet = "music/radios/get";
constexpr const char *MusicRadiosLibraryItems = "music/radios/library_items";
constexpr const char *MusicRadiosRadioVersions = "music/radios/radio_versions";

// Music — Recently Played / Added
constexpr const char *MusicRecentlyAddedTracks = "music/recently_added_tracks";
constexpr const char *MusicRecentlyPlayedItems = "music/recently_played_items";

// Music — Recommendations, Refresh, Search & Sync
constexpr const char *MusicRecommendations = "music/recommendations";
constexpr const char *MusicRefreshItem = "music/item/refresh";
constexpr const char *MusicRemoveProviderMapping = "music/provider/remove_mapping";
constexpr const char *MusicSearch = "music/search";
constexpr const char *MusicSync = "music/sync";
constexpr const char *MusicSyncTasks = "music/sync/tasks";

// Music — Tracks
constexpr const char *MusicTrackByName = "music/tracks/by_name";
constexpr const char *MusicTracksCount = "music/tracks/count";
constexpr const char *MusicTracksLibraryItems = "music/tracks/library_items";
constexpr const char *MusicTracksTrackAlbum = "music/tracks/track_album";
constexpr const char *MusicTracksTrackVersions = "music/tracks/track_versions";
constexpr const char *MusicSimilarTracks = "music/tracks/similar_tracks";

// Config
constexpr const char *ConfigCore = "config/core";
constexpr const char *ConfigCoreGet = "config/core/get";
constexpr const char *ConfigCoreGetEntries = "config/core/get_entries";
constexpr const char *ConfigCoreGetValue = "config/core/get_value";
constexpr const char *ConfigDspPresetsGet = "config/dsp_presets/get";
constexpr const char *ConfigPlayers = "config/players";
constexpr const char *ConfigPlayersGetEntries = "config/players/get_entries";
constexpr const char *ConfigPlayersGetValue = "config/players/get_value";
constexpr const char *ConfigPlayersDspGet = "config/players/dsp/get";
constexpr const char *ConfigProviders = "config/providers";
constexpr const char *ConfigProvidersGetEntries = "config/providers/get_entries";
constexpr const char *ConfigProvidersGetValue = "config/providers/get_value";

// Metadata
constexpr const char *MetadataGetTrackLyrics = "metadata/get_track_lyrics";
constexpr const char *MetadataSetDefaultPreferredLanguage = "metadata/set_default_preferred_language";
constexpr const char *MetadataSetPreferredLanguage = "metadata/set_preferred_language";
constexpr const char *MetadataUpdate = "metadata/update_metadata";

// Providers
constexpr const char *ProvidersManifests = "providers/manifests";
constexpr const char *ProvidersManifestsGet = "providers/manifests/get";

}  // namespace Commands

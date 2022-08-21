/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_VERSION_H
#define GAME_VERSION_H
#ifndef GAME_RELEASE_VERSION
#define GAME_RELEASE_VERSION "16.2.2"
#endif
#define GAME_VERSION "0.6.4, " GAME_RELEASE_VERSION
#define GAME_NETVERSION "0.6 626fce9a778df4d4"
#define CLIENT_VERSIONNR 16022
extern const char *GIT_SHORTREV_HASH;
#define GAME_NAME "DDNet"
// DDNet-Skeleton
#define GAME_MOD_NAME "DDNet-Skeleton"
#define GAME_MOD_RELEASE_VERSION "1.0.0"

#define GAME_MOD_VERSION GAME_VERSION ", " GAME_MOD_RELEASE_VERSION
#define GAME_MOD_SHORT_VERSION "0.6.4, " GAME_MOD_RELEASE_VERSION
#endif

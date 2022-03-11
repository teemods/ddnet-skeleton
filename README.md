# DDNet Skeleton

This repository aims to be the skeleton for creating modifications on top of the latest DDNet version. It currently modify the DDNet code so it can support teams, damage, ammo and pickup respawn features.

## How to create your Modification

In order to create your mod, you will need to download this repository with the following command. **Please do not fork this repository or download the ZIP file without the Git History**:
```bash
git clone https://github.com/teeframe/ddnet-skeleton
```

After downloading the repository, you will need to add your repository remote and create two branches with the following commands **inside the repository folder:**

```bash
git remote remove origin
git remote add origin YOUR_REPOSITORY_URL
git branch -M main && git push -u origin main
git branch upstream && git push -u origin upstream
```

You will create `main` and upstream. The `main` will be used to code your mod and the `upstream` will be used to keep your mod updated.

This repository comes with an automatic Github Action, **Rebase from Skeleton**, that will sync the `upstream` changes from the skeleton to your `upstream` branch every day. In order to use that you need to activate Actions within **Actions Tab** in your repository.

This repository also comes with a Github Action that syncs with the DDNet repository. **The Rebase from DDNet action should be removed from your repository.**

## What changes?

Below are the changes made on top of the DDNet version:

- Comments DDNet table creation.
- Comments all DDNet commands related.
- Comments all DDNet config options related.
- Comments DDNet score thread initializer.
- Implements a map rotation system.
- Add new configs options: `sv_self_kill` and `sv_spectable`.
- Add mod name constant that displays on chat (among with the server browser game type).
- Add version constants after DDNet version.
- Add dynamic max health and dynamic max shield support.
- Bring back the ammo amount parameter to give weapon function.
- Bring back the damage parameter to projectile entity.
- Bring back the teams system from Teeworlds.

## Important Instructions

Below are some instructions you should be aware of for game type modification.

### Mod Version

`src/game/version.h` - Change the information about your mod.

***Editable Constants***

- `GAME_MOD_NAME` - Game mod name.
- `GAME_MOD_RELEASE_VERSION` - Game mod version.
- `GAME_TYPE_NAME` - In game mod name (Server browser).
- `TEST_TYPE_NAME` - In game mod name on testing (Server browser).

### Game Type

- `src/game/server/gamecontroller.cpp ~ m_GameFlags` - Defines the type of game mode.

***Possible Values***

- `0` - Unified Team
- `GAMEFLAG_TEAMS` - Red and Blue team
- `GAMEFLAG_TEAMS | GAMEFLAG_FLAGS` - Red and Blue team with Flags

### Mod Information

- `src/game/server/ddracechat.cpp ~ ConInfo` - Changes the /info messages command.
- `src/game/server/ddracechat.cpp ~ ConCredits` - Changes the /credits messages command.
- `src/game/server/ddracechat.cpp ~ ConSettings` - Changes the /settings listing messages command.

### Game Information Flags

- `src/game/server/gamecontroller.cpp ~ pGameInfoEx->m_Flags` - Some instructions about how the server works for the client.

***Info Flags***

- `GAMEINFOFLAG_TIMESCORE` - Uses time scoring on Tab and Top 1,2 instead of points scoring.
- `GAMEINFOFLAG_UNLIMITED_AMMO` - Send information to the client that all guns have unlimited ammo.
- `GAMEINFOFLAG_RACE_RECORD_MESSAGE` - Send information to the client that the server may send a "new record" message on chat.
- `GAMEINFOFLAG_ALLOW_EYE_WHEEL` - Enable eye wheel on the emojis menu on client side.
- `GAMEINFOFLAG_ALLOW_HOOK_COLL` - ???

***Other Flags***

- `GAMEINFOFLAG_BUG_DDRACE_GHOST` - Fix a bug with ghost recording on client side.
- `GAMEINFOFLAG_BUG_DDRACE_INPUT` - Fix motion bug in specific situations on client side (Example: try to move with chat enabled).
- `GAMEINFOFLAG_PREDICT_DDRACE` - Enable DDrace prediction situations (???).
- `GAMEINFOFLAG_PREDICT_DDRACE_TILES` - Enable DDRace prediction tiles (Remove if your mod changes the DDRace tiles).
- `GAMEINFOFLAG_ENTITIES_DDNET` - Send to the client that the server uses the DDRace entities.

***Game Flags***

- `GAMEINFOFLAG_GAMETYPE_DDNET` - Send information to the client that the game mode is DDNet.
- `GAMEINFOFLAG_GAMETYPE_PLUS` - Send information to the client that the game mode is Vanilla+ (Supports Eye Wheel).

***Legacy Flags***

- `GAMEINFOFLAG_GAMETYPE_RACE` - Do the same thing as `GAMEINFOFLAG_GAMETYPE_DDNET` but for older clients.
- `GAMEINFOFLAG_GAMETYPE_DDRACE` - Do the same thing as `GAMEINFOFLAG_GAMETYPE_DDNET` but for older clients.
- `GAMEINFOFLAG_ENTITIES_DDRACE` - Do the same thing as `GAMEINFOFLAG_ENTITIES_DDNET` but for older clients.
- `GAMEINFOFLAG_ENTITIES_RACE` - Do the same thing as `GAMEINFOFLAG_ENTITIES_DDNET` but for older clients.

### Game Context

Important files/functions for how the game handles the rounds, teams, points, player management and time limit.

***Default GameController***

- `src/game/server/gamecontroller.cpp ~ IGameController` - Control the start of the game context (Set sudden death, teams points and others).
- `src/game/server/gamecontroller.cpp ~ GetTeamName` - Define the teams name (Also for unified team).
- `src/game/server/gamecontroller.cpp ~ OnEntity` - Handle spawn entities on the map.
- `src/game/server/gamecontroller.cpp ~ StartRound` - Control the start of the round (Also control if the round will start or not).
- `src/game/server/gamecontroller.cpp ~ EndRound` - Control the end the round.
- `src/game/server/gamecontroller.cpp ~ GetAutoTeam` - Define the start team for new players.
- `src/game/server/gamecontroller.cpp ~ Snap` - Control the information about team scoring, rounds limit, current round, points limits, time limits and others.
(Set CNetObj_GameData to enable team points display on right-down).

***Mod GameController***

- `src/game/server/gamemodes/DDRace.cpp ~ HandleCharacterTiles` - Handle the tiles actions when player relay on it.
- `src/game/server/gamemodes/DDRace.cpp ~ OnCharacterSpawn` - Handle the character spawn (Give specific weapons, set health, set shield).
- `src/game/server/gamemodes/DDRace.cpp ~ OnPlayerConnect` - Handle the player connection (get data, spawn, login, etc...)
- `src/game/server/gamemodes/DDRace.cpp ~ OnPlayerDisconnect` - Handle the player disconnection (get rebalanced, penalty, etc...)
- `src/game/server/gamemodes/DDRace.cpp ~ DoTeamChange` - Handle the player change team action (can be used to check if the player can change team).

***Other Contexts***

- `src/game/server/gamecontext.cpp ~ OnInit` - Control tunings such as player collision, hook collision (Also to change DDNet gun & shotgun tunning).
- `src/game/server/gamecontext.cpp ~ ResetTuning` - Change tunning reset params (Also to change DDNet gun & shotgun tunning).

- `src/game/server/score.cpp ~ CScore` - To re-enable the top score thread by DDNet.
- `src/game/server/score.cpp ~ LoadPlayerData` - To re-enable the player score thread by DDNet.

### Weapons & Damage

Important files/functions if you would like to change how weapons and projectiles works.

***Character***
- `src/game/server/entities/character.cpp ~ FireWeapon` - Handle what kind of thing every weapon will throw (To revert DDNet changes).
- `src/game/server/entities/character.cpp ~ TakeDamage` - Handle how the player hit will take the damage.

***Projectile***
- `src/game/server/entities/projectile.cpp ~ GetPos` - Handle the position calculation of the projectile.
- `src/game/server/entities/projectile.cpp ~ Tick` - Handle the tick of the projectile (if have new position, what will happen if it reach something).

***Pick Up***
- `src/game/server/entities/pickup.cpp ~ Reset` - Handle the PickUp respawn delay (To revert DDNet changes).
- `src/game/server/entities/pickup.cpp ~ Tick` - Handle the PickUp respawn time and ammo giving (To revert DDNet changes).
- `src/game/server/entities/pickup.cpp ~ TickPaused` - Handle the PickUp respawn time on paused (To revert DDNet changes).
- `src/game/server/entities/pickup.cpp ~ Snap` - Handle the PickUp visibility on cooldown (Tor revert DDNet changes).

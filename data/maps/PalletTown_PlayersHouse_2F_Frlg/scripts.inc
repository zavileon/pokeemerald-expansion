PalletTown_PlayersHouse_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
msgbox EnterCheatCode_EnterCheatCodeText, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CheatCodeExit
	special EnterCheatCode
	waitstate
	special GetCheatCodeFeedback
	goto_if_eq VAR_RESULT, 0, CheatCodeFailed
	goto_if_eq VAR_RESULT, 1, CheatCodeDexAll
	goto_if_eq VAR_RESULT, 2, CheatCodeCaughtEmAll
	goto_if_eq VAR_RESULT, 3, CheatCodeEzCatch
	goto_if_eq VAR_RESULT, 4, CheatCodeMegaStones
	end

CheatCodeFailed::
	msgbox EnterCheatCode_FailedText, MSGBOX_DEFAULT
	releaseall
	end

CheatCodeDexAll::
	msgbox EnterCheatCode_SucceededText, MSGBOX_DEFAULT
	goto_if_unset FLAG_DEXALL, CheatCodeDexAllOff
	goto_if_set FLAG_DEXALL, CheatCodeDexAllOn
	end

CheatCodeDexAllOn::
	msgbox CheatCodeDexAllOn_Text, MSGBOX_DEFAULT
	releaseall
	end

CheatCodeDexAllOff::
	msgbox CheatCodeDexAllOff_Text, MSGBOX_DEFAULT
	releaseall
	end

CheatCodeCaughtEmAll::
	msgbox EnterCheatCode_SucceededText, MSGBOX_DEFAULT
	msgbox CheatCodeCaughtEmAll_Text, MSGBOX_DEFAULT
	releaseall
	end

CheatCodeEzCatch::
	msgbox EnterCheatCode_SucceededText, MSGBOX_DEFAULT
	goto_if_unset FLAG_EZ_CATCH, CheatCodeEzCatchOff
	goto_if_set FLAG_EZ_CATCH, CheatCodeEzCatchOn
	end

CheatCodeEzCatchOn::
	msgbox CheatCodeEzCatchOn_Text, MSGBOX_DEFAULT
	releaseall
	end

CheatCodeEzCatchOff::
	msgbox CheatCodeEzCatchOff_Text, MSGBOX_DEFAULT
	releaseall
	end

CheatCodeMegaStones::
	msgbox EnterCheatCode_SucceededText, MSGBOX_DEFAULT
	giveitemfast ITEM_VENUSAURITE
	giveitemfast ITEM_CHARIZARDITE_X
	giveitemfast ITEM_CHARIZARDITE_Y
	giveitemfast ITEM_BLASTOISINITE 
	giveitemfast ITEM_BEEDRILLITE
	giveitemfast ITEM_PIDGEOTITE
	giveitemfast ITEM_ALAKAZITE
	giveitemfast ITEM_SLOWBRONITE
	giveitemfast ITEM_GENGARITE
	giveitemfast ITEM_KANGASKHANITE
	giveitemfast ITEM_PINSIRITE
	giveitemfast ITEM_GYARADOSITE
	giveitemfast ITEM_AERODACTYLITE
	giveitemfast ITEM_MEWTWONITE_X
	giveitemfast ITEM_MEWTWONITE_Y
	giveitemfast ITEM_AMPHAROSITE
	giveitemfast ITEM_STEELIXITE
	giveitemfast ITEM_SCIZORITE
	giveitemfast ITEM_HERACRONITE
	giveitemfast ITEM_HOUNDOOMINITE
	giveitemfast ITEM_TYRANITARITE
	giveitemfast ITEM_SCEPTILITE
	giveitemfast ITEM_BLAZIKENITE
	giveitemfast ITEM_SWAMPERTITE
	giveitemfast ITEM_GARDEVOIRITE
	giveitemfast ITEM_SABLENITE
	giveitemfast ITEM_MAWILITE
	giveitemfast ITEM_AGGRONITE
	giveitemfast ITEM_MEDICHAMITE
	giveitemfast ITEM_MANECTITE
	giveitemfast ITEM_SHARPEDONITE
	giveitemfast ITEM_CAMERUPTITE
	giveitemfast ITEM_ALTARIANITE
	giveitemfast ITEM_BANETTITE
	giveitemfast ITEM_ABSOLITE
	giveitemfast ITEM_GLALITITE
	giveitemfast ITEM_SALAMENCITE
	giveitemfast ITEM_METAGROSSITE
	giveitemfast ITEM_LATIASITE
	giveitemfast ITEM_LATIOSITE
	giveitemfast ITEM_LOPUNNITE
	giveitemfast ITEM_GARCHOMPITE
	giveitemfast ITEM_LUCARIONITE
	giveitemfast ITEM_ABOMASITE
	giveitemfast ITEM_GALLADITE
	giveitemfast ITEM_AUDINITE
	giveitemfast ITEM_DIANCITE
	msgbox CheatCodeMegaStonesGiven_Text, MSGBOX_DEFAULT
	releaseall
	end

CheatCodeExit::
	releaseall
	end

EnterCheatCode_EnterCheatCodeText::
	.string "It's an NES.\p"
	.string "Enter a cheat code?$"

EnterCheatCode_FailedText::
	.string "Cheat code failed.$"

EnterCheatCode_SucceededText::
	.string "Cheat code succeeded.$"

CheatCodeDexAllOn_Text::
	.string "DexAll cheat enabled.$"

CheatCodeDexAllOff_Text::
	.string "DexAll cheat disabled.$"

CheatCodeCaughtEmAll_Text::
	.string "CaughtAll cheat enabled.$"

CheatCodeEzCatchOn_Text::
	.string "EZCatch cheat enabled.$"

CheatCodeEzCatchOff_Text::
	.string "EZCatch cheat disabled.$"

CheatCodeMegaStonesGiven_Text::
	.string "All Mega Stones given.$"

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_Text_PressLRForHelp::
	.string "It's a posted notice…\p"
	.string "If you're confused, ask for HELP!\n"
	.string "Press the L or R Button!$"


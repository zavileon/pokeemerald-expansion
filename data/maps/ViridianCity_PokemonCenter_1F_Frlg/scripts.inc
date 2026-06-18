ViridianCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
	.string "Please feel free to use that PC in\n"
	.string "the corner.\p"
	.string "The receptionist told me so.\n"
	.string "It's so kind of her!$"

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
	.string "There's a POKéMON CENTER in every\n"
	.string "town ahead.\p"
	.string "They charge no money, so don't\n"
	.string "be shy about healing POKéMON.$"

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
	.string "POKéMON CENTERS heal your tired,\n"
	.string "hurt, or fainted POKéMON.\p"
	.string "They make all POKéMON completely\n"
	.string "healthy.$"

Viridian_PokemonCenter_EventScript_NatureMaster::
	lock
	faceplayer
	msgbox Viridian_PokemonCenter_EventScript_NatureMaster_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Viridian_PokemonCenter_EventScript_NatureMaster_2

Viridian_PokemonCenter_EventScript_NatureMaster_1::
	msgbox Viridian_PokemonCenter_EventScript_NatureMaster_Text_1
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq Viridian_PokemonCenter_EventScript_NatureMaster_5

Viridian_PokemonCenter_EventScript_NatureMaster_4::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq Viridian_PokemonCenter_EventScript_NatureMaster_8
	special BufferMonNickname
	msgbox Viridian_PokemonCenter_EventScript_NatureMaster_Text_3
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_4, NATURE_ADAMANT
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_5, NATURE_BASHFUL
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_6, NATURE_BOLD
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_7, NATURE_BRAVE
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_8, NATURE_CALM
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_9, NATURE_CAREFUL
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_10, NATURE_DOCILE
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_11, NATURE_GENTLE
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_12, NATURE_HARDY
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_13, NATURE_HASTY
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_14, NATURE_IMPISH
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_15, NATURE_JOLLY
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_16, NATURE_LAX
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_17, NATURE_LONELY
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_18, NATURE_MILD
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_19, NATURE_MODEST
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_20, NATURE_NAIVE
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_21, NATURE_NAUGHTY
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_22, NATURE_QUIET
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_23, NATURE_QUIRKY
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_24, NATURE_RASH
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_25, NATURE_RELAXED
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_26, NATURE_SASSY
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_27, NATURE_SERIOUS
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_28, NATURE_TIMID
	dynmultipush Viridian_PokemonCenter_EventScript_NatureMaster_Text_29, MULTI_B_PRESSED
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq Viridian_PokemonCenter_EventScript_NatureMaster_11

Viridian_PokemonCenter_EventScript_NatureMaster_10::
	copyvar VAR_0x8005, VAR_RESULT
	buffernaturename STR_VAR_2, VAR_RESULT
	msgbox Viridian_PokemonCenter_EventScript_NatureMaster_Text_30, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Viridian_PokemonCenter_EventScript_NatureMaster_14

Viridian_PokemonCenter_EventScript_NatureMaster_13::
	msgbox Viridian_PokemonCenter_EventScript_NatureMaster_Text_31
	fadescreen FADE_TO_BLACK
	special ChangeMonNature
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox Viridian_PokemonCenter_EventScript_NatureMaster_Text_32
	release
	end

Viridian_PokemonCenter_EventScript_NatureMaster_2::
	goto Viridian_PokemonCenter_EventScript_NatureMasterNo
	goto Viridian_PokemonCenter_EventScript_NatureMaster_1

Viridian_PokemonCenter_EventScript_NatureMaster_5::
	goto Viridian_PokemonCenter_EventScript_NatureMasterNo
	goto Viridian_PokemonCenter_EventScript_NatureMaster_4

Viridian_PokemonCenter_EventScript_NatureMaster_8::
	msgbox Viridian_PokemonCenter_EventScript_NatureMaster_Text_2
	release
	end

Viridian_PokemonCenter_EventScript_NatureMaster_11::
	goto Viridian_PokemonCenter_EventScript_NatureMasterNo
	goto Viridian_PokemonCenter_EventScript_NatureMaster_10

Viridian_PokemonCenter_EventScript_NatureMaster_14::
	goto Viridian_PokemonCenter_EventScript_NatureMasterNo
	goto Viridian_PokemonCenter_EventScript_NatureMaster_13


Viridian_PokemonCenter_EventScript_NatureMasterNo::
	msgbox Viridian_PokemonCenter_EventScript_NatureMasterNo_Text_0
	release
	end


Viridian_PokemonCenter_EventScript_NatureMaster_Text_0::
	.string "Hello, would you like one of your\nPokémon to change their Nature?$"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_1::
	.string "Which Pokémon?$"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_2::
	.string "I can't change the Nature of an egg.$"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_3::
	.string "Which new Nature suits {STR_VAR_1}\nbest?$"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_4::
	.string "Adamant       {COLOR RED}{SHADOW LIGHT_RED}+Atk{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-SpAtk$"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_5::
	.string "Bashful        Neutral         $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_6::
	.string "Bold             {COLOR RED}{SHADOW LIGHT_RED}+Def{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Atk       $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_7::
	.string "Brave           {COLOR RED}{SHADOW LIGHT_RED}+Atk{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Speed     $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_8::
	.string "Calm             {COLOR RED}{SHADOW LIGHT_RED}+SpDef{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Atk     $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_9::
	.string "Careful       {COLOR RED}{SHADOW LIGHT_RED}+SpDef{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-SpAtk   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_10::
	.string "Docile          Neutral         $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_11::
	.string "Gentle         {COLOR RED}{SHADOW LIGHT_RED}+SpDef{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Def     $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_12::
	.string "Hardy           Neutral         $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_13::
	.string "Hasty          {COLOR RED}{SHADOW LIGHT_RED}+Speed{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Def     $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_14::
	.string "Impish         {COLOR RED}{SHADOW LIGHT_RED}+Def{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-SpAtk   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_15::
	.string "Jolly           {COLOR RED}{SHADOW LIGHT_RED}+Speed{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-SpAtk   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_16::
	.string "Lax              {COLOR RED}{SHADOW LIGHT_RED}+Def{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-SpDef   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_17::
	.string "Lonely         {COLOR RED}{SHADOW LIGHT_RED}+Atk{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Def     $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_18::
	.string "Mild             {COLOR RED}{SHADOW LIGHT_RED}+SpAtk{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Def   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_19::
	.string "Modest        {COLOR RED}{SHADOW LIGHT_RED}+SpAtk{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Atk   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_20::
	.string "Naive          {COLOR RED}{SHADOW LIGHT_RED}+Speed{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-SpDef $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_21::
	.string "Naughty      {COLOR RED}{SHADOW LIGHT_RED}+Atk{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-SpDef   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_22::
	.string "Quiet          {COLOR RED}{SHADOW LIGHT_RED}+SpAtk{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Speed $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_23::
	.string "Quirky          Neutral         $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_24::
	.string "Rash            {COLOR RED}{SHADOW LIGHT_RED}+SpAtk{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-SpDef $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_25::
	.string "Relaxed       {COLOR RED}{SHADOW LIGHT_RED}+Def{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Speed   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_26::
	.string "Sassy          {COLOR RED}{SHADOW LIGHT_RED}+SpDef{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Speed $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_27::
	.string "Serious       Neutral         $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_28::
	.string "Timid           {COLOR RED}{SHADOW LIGHT_RED}+Speed{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/{COLOR BLUE}{SHADOW LIGHT_BLUE}-Atk   $"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_29::
	.string "Cancel$"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_30::
	.string "So {STR_VAR_1} should acquire the\n{STR_VAR_2} Nature?$"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_31:
	.string "Excellent. We shall begin at once!$"

Viridian_PokemonCenter_EventScript_NatureMaster_Text_32::
	.string "{STR_VAR_1}'s nature has been\nchanged. Come again if you need to\pchange another Pokémon's nature.$"

Viridian_PokemonCenter_EventScript_NatureMasterNo_Text_0::
	.string "I see. Come back when one of your\nPokémon needs to acquire a new Nature.$"

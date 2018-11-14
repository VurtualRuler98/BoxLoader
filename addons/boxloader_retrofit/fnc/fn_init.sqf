



if (is3DEN) exitWith {false};

//RHS
if (isClass(configFile >> "CfgPatches" >> "rhsusf_main")) then {

	{[_x,"init",{
		(_this select 0) setVariable ["boxloader_load_weight",2270];
		(_this select 0) setVariable ["boxloader_load_height",7]; //5.1
		(_this select 0) setVariable ["boxloader_crane_push",2268];
	}] call CBA_fnc_addClassEventHandler;} forEach ["rhsusf_M1084A1P2_fmtv_usarmy","rhsusf_M1084A1P2_B_M2_fmtv_usarmy"];


	//HEMTT, ~2.3m above ground, length 3-5.8m
	["rhsusf_HEMTT_A4_base","init",{
		if (({(_this select 0) isKindOf _x} count ["rhsusf_M978A4_BKIT_usarmy_wd","rhsusf_M978A4_usarmy_wd","rhsusf_M978A4_BKIT_usarmy_d","rhsusf_M978A4_usarmy_d"])>0) exitWith {};
		(_this select 0) setVariable ["boxloader_load_weight",6600];
		(_this select 0) setVariable ["boxloader_load_height",8.1]; //5.3
		//(_this select 0) setVariable ["boxloader_load_weight_high",1133];
		//(_this select 0) setVariable ["boxloader_load_height_high",8.1];
		(_this select 0) setVariable ["boxloader_crane_push",6600];
	}] call CBA_fnc_addClassEventHandler;
};
//Unsung
if (isClass(configFile >> "CfgPatches" >> "uns_main")) then {
	["uns_M113_ENG","init",{
		(_this select 0) setVariable ["boxloader_build_fill",true];
		(_this select 0) setVariable ["boxloader_build_tools",true];
		(_this select 0) setVariable ["boxloader_load_weight",1000];
		(_this select 0) setVariable ["boxloader_load_height",3.8];
		(_this select 0) setVariable ["boxloader_crane_push",10000];
	}] call CBA_fnc_addClassEventHandler;
};

//[0 rack object,1 position, 2 rotation, 3 useText, 4 unloadText, 5 toggles,6 [0 enableText,1 disableText,2 hide when disabled,3 cargo seats blocked,4 turret seats blocked,5 blocks vehicle loading],7 [selection,state], 8 addon action]


//Vanilla

	//Land


	//Offroad
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_offroad",[0,-1.7,-0.65],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[],[1,2,3,4],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["Offroad_01_civil_base_F","I_G_Offroad_01_F"];
	
	
	//Boxer
	["Van_01_transport_base_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_boxer",[0,-1.8,-0.58],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seat",false,[],[2,3,4,5,6,7,8,9,10,11],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	

	//KAMAZ
	{[_x,"init",{if ((_this select 0) isKindOf "rhs_kamaz5350") exitWith {false}; [(_this select 0),[
		[["Land_Boxloader_mem_kamaz",[0.1,-1.3,-0.76],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[2,3,4,5,6,7,8,9,10,11,12,13],[14,15],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["Truck_02_transport_Base_F","O_Truck_02_covered_F","I_Truck_02_covered_F","C_Truck_02_covered_F","C_IDAP_Truck_02_F"];
	
	//KAMAZ Medical
	["Truck_02_medical_base_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_kamaz",[0.1,-1.3,-0.76],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[2,3,4,5,6,7,8,9,10,11,12,13,14,15],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//KAMAZ repair
	["Truck_02_box_base_F","init",{if ((_this select 0) isKindOf "Truck_02_medical_base_F") exitWith {false};[(_this select 0),[
		[["Boxloader_Bucket",[0,4.5,-2],0,"Select bucket","Unload bucket",true,["Deploy bucket","Stow bucket",true,[],[],true],[],"Install bucket"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Typhoon
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_hemtt",[0.1,-2.5,-0.38],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[1,2,3,4,6,7,8,9,10,12],[5,11],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["O_Truck_03_covered_F","O_Truck_03_transport_F","O_T_Truck_03_transport_ghex_F","O_T_Truck_03_covered_ghex_F"];
	
	//Typhoon medical
	["O_Truck_03_medical_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_hemtt",[0.1,-2.5,-0.38],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[1,2,3,4,5,6,7,8,9,10,11],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;


	//IDAP Van
	["Van_02_base_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_idap",[0,-0.65,1.2],0,"Select roof rack","Unload roof rack",false,[],["roof_rack_hide",0]],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//HEMTT
	["B_Truck_01_transport_F","init",{
		if (typeOf (_this select 0)=="B_Truck_01_transport_F" || typeOf (_this select 0)=="B_T_Truck_01_transport_F" || (_this select 0) isKindOf "B_Truck_01_covered_F") then {
			[(_this select 0),[
				[["Land_Boxloader_mem_hemtt",[0.1,-2.15,-0.5],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seat",false,[1,2,3,4,5,6,8,9,10,11,12,13,14,16],[7,15],false]],"boxloader_rack0"]
			],0] spawn boxloader_retrofit_fnc_setup;
		};
		if (typeOf (_this select 0)=="B_Truck_01_mover_F" || typeOf (_this select 0)=="B_T_Truck_01_mover_F") then {
			[(_this select 0),[
				[["Land_Boxloader_flatrack",[0,-3.4,1],0,"Select flat rack","Unload flat rack",true,["Use flat rack","Store flat rack",true,[],[],true],[],"Add flat rack"],"boxloader_rack0"]
			]] spawn boxloader_retrofit_fnc_setup;
		};
	}] call CBA_fnc_addClassEventHandler;
	
	//HEMTT Medical
	["B_Truck_01_medical_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_hemtt",[0.1,-2.15,-0.5],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seat",false,[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Quad bike
	["Quadbike_01_Base_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_quad_front",[0,0.75,-0.55],0,"Select front cargo rack","Unload front cargo rack",false,[]],"boxloader_rack0"],
		[["Land_Boxloader_mem_quad",[0,-0.85,-0.45],90,"Select rear cargo rack","Unload rear cargo rack",true,["Use rear cargo rack","Use rear passenger seat",false,[0],[],false]],"boxloader_rack1"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	
	//Prowler
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_prowler",[0,-0.35,-1.2],0,"Select middle cargo space","Unload middle cargo space",false,[]],"boxloader_rack0"],
		[["Land_Boxloader_prowler_net",[0,-1.4,-0.8],0,"Select rear cargo net","Unload rear cargo net",true,["Use rear cargo net","Use rear passenger seats",true,[],[4,5],false]],"boxloader_rack1"],
		[["Land_Boxloader_prowler_roofnet",[0,-0.1,-0.1],0,"Select roof cargo net","Unload roof cargo net",true,["Attach roof cargo net","Detach roof cargo net",true,[],[0],true],[],"Add roof cargo net kit"],"boxloader_rack2"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["LSV_01_unarmed_base_F","LSV_01_light_base_F"];

	
	//M-ATV
	["B_MRAP_01_F","init",{[(_this select 0),[
		[["Land_Boxloader_Roofrack_1",[0,-2,0.65],0,"Select roof rack","Unload roof rack",true,["Set up roof rack","Take down roof rack",true,[],[],true],[],"Add roof rack kit"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Punisher
	{;[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_Roofrack_1",[0,-3,0.45],0,"Select roof rack","Unload roof rack",true,["Set up roof rack","Take down roof rack",true,[],[],true],[],"Add roof rack kit"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["O_MRAP_02_F","O_T_MRAP_02_ghex_F"];
	
	
	//Fennek
	["I_MRAP_03_F","init",{[(_this select 0),[
		[["Land_Boxloader_Roofrack_1",[0,0,0.55],0,"Select roof rack","Unload roof rack",true,["Set up roof rack","Take down roof rack",true,[],[],true],[],"Add roof rack kit"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	
	
	//SUV
	["C_SUV_01_F","init",{[(_this select 0),[
		[["Land_Boxloader_Roofrack_1",[0,-1,0.4],0,"Select roof rack","Unload roof rack",true,["Set up roof rack","Take down roof rack",true,[],[],true],[],"Add roof rack kit"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Air
	
	
	//Huron
	/*
	["Heli_Transport_03_base_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_hemtt",[0,0,-2.15],0,"Select cargo space","Unload cargo space",true,["Use cargo space","Use passenger space",false,[0,1,2,3,4,5,6,8,9,10,11,12,13],[0,0],false]],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	*/
	//Sea
	
	
	//Zodiacs
	["Rubber_duck_base_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_zodiac",[0,-0.4,-0.85],0,"Select cargo space","Unload cargo space",false,[]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Motorboat
	["Boat_Civil_01_base_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_zodiac",[0,-0.9,-1],0,"Select cargo space","Unload cargo space",false,[]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Armed boat
	["Boat_Armed_01_base_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_zodiac",[0,-1.8,-1.79],0,"Select rear cargo space","Unload rear cargo space",false,[]],"boxloader_rack0"],
		[["Land_Boxloader_mem_zodiac",[0,2.8,-2.12],0,"Select front cargo space","Unload front cargo space",false,[]],"boxloader_rack1"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;



//RHS rhs
if (isClass(configFile >> "CfgPatches" >> "rhs_main")) then {

	//Ural flatbed
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_rhsural",[0.1,-1.4,-0.18],0,"Select rear cargo bed","Unload rear cargo bed",false,[]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["RHS_Ural_Flat_MSV_01","RHS_Ural_Open_Flat_MSV_01"];
	
	//GAZ flatbed
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_rhsgaz",[0.1,-0.8,-0.57],0,"Select rear cargo bed","Unload rear cargo bed",false,[]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["rhs_gaz66o_flat_vmf","rhs_gaz66_flat_vmf"];
	

};
if (isClass(configFile >> "CfgPatches" >> "rhsusf_main")) then {
	//M113 Bulldozer
	["rhsusf_m113tank_base","init",{[(_this select 0),[
		[["Boxloader_Bucket",[0.4,3,-2.3],0,"Select bucket","Unload bucket",true,["Deploy bucket","Stow bucket",true,[],[],true],[],"Install bucket"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	//HMMWV
	["rhsusf_hmmwe_base","init",{
		_mdl = (getModelInfo (_this select 0) select 0);
		_rack = [["Land_Boxloader_mem_cuphsov",[0,-1.5,-0.95],0,"Select cargo space","Unload cargo space",false,[]],"boxloader_rack0"];
		if (_mdl == "rhsusf_m1025_m2.p3d") then {
			_rack = [["Land_Boxloader_mem_cuphsov",[0,-1.5,-1.15],0,"Select cargo space","Unload cargo space",false,[]],"boxloader_rack0"];
		};
		if (_mdl == "rhsusf_m998_2dr.p3d") then {
			_rack = [["Land_Boxloader_mem_cupm1152",[0,-1.15,-0.9],0,"Select cargo space","Unload cargo space",true,["Use rear cargo space","Use rear passenger seats",true,[1,2,4,5],[3,6],false]],"boxloader_rack0"];
		};
		if (_mdl == "rhsusf_m998_4dr.p3d") then {
			_rack = [["Land_Boxloader_mem_cuphsov",[0,-1.5,-0.9],0,"Select cargo space","Unload cargo space",true,["Use rear cargo space","Disable rear cargo space",true,[],[3,4],false]],"boxloader_rack0"];
		};
	[(_this select 0),[_rack],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
};

//CUP
if (isClass(configFile >> "CfgPatches" >> "cup_vehicles_core")) then {

	//HMMWV SOV
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_cuphsov",[0,-1.5,-1.32],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[],[2,3],false]],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["CUP_HMMWV_SOV_Base","CUP_HMMWV_SOV_M2_Base"];
	
	//M998 HMMWV
	["CUP_HMMWV_Transport_Base","init",{[(_this select 0),[
		[["Land_Boxloader_mem_cupm998",[0,-1.05,-0.59],0,"Select cargo space","Unload cargo space",false,[]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;

	//M1152 HMMWV
	["CUP_M1152_BASE","init",{[(_this select 0),[
		[["Land_Boxloader_mem_cupm1152",[0,-1.3,-1.54],0,"Select cargo bed","Unload cargo bed",false,[]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//M1025 and M1151 HMMWV
	{;[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_Roofrack_1",[0,-0.2,-0.5],90,"Select roof rack","Unload roof rack",true,["Set up roof rack","Take down roof rack",true,[],[],true],[],"Add roof rack kit"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["CUP_M1151_Unarmed_BASE","CUP_HMMWV_Unarmed_Base"];

	//MTVR
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_cupmtvr",[0.1,-1.6,-0.375],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[2,3,4,5,6,7,8,9,10,11],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["CUP_B_MTVR_USA","CUP_B_MTVR_USMC"];

	//UAZ
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_cupuaz",[0,-1.3,0.72],0,"Select rear cargo space","Unload rear cargo space",true,["Use rear cargo space","Use rear passenger seats",true,[2,5],[2,5],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["CUP_UAZ_Open_Base","CUP_UAZ_Unarmed_Base"];
	
	//Ural
	["CUP_Ural_Base","init",{_height = -0.45; if ((_this select 0) isKindOf "CUP_C_Ural_Open_Civ_01") then {_height=1.575}; [(_this select 0),[
		[["Land_Boxloader_mem_rhsural",[0.1,-1.4,_height],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seat",false,[2,3,4,5,6,7,8,9,12,13],[10,11],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Ural Empty
	["CUP_Ural_Empty_Base","init",{[(_this select 0),[
		[["Boxloader_Bucket",[0,4.5,-1.5],0,"Select bucket","Unload bucket",true,["Deploy bucket","Stow bucket",true,[],[],true],[],"Install bucket"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;

	//M113 Bulldozer
	["CUP_M113_Base","init",{_height = -2.5; if ((_this select 0) isKindOf "CUP_M113_Med_Base") then {_height = -2};[(_this select 0),[
		[["Boxloader_Bucket",[0.4,3,_height],0,"Select bucket","Unload bucket",true,["Deploy bucket","Stow bucket",true,[],[],true],[],"Install bucket"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	//V3S
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_cupv3s",[0.1,-1,-0.57],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[1,2,3,4,5,6,7,8,9,10,11,12],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["CUP_V3S_Covered_Base","CUP_O_V3S_Open_TKA","CUP_O_V3S_Open_TKM","CUP_V3S_Open_NAPA","CUP_I_V3S_Open_TKG","CUP_C_V3S_Open_TKC"];
	
	//Tatra T810 unarmed
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_kamaz",[0.1,-1.05,-0.55],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[2,3,4,5,6,7,8,9,10,11],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["CUP_B_T810_Unarmed_CZ_DES","CUP_B_T810_Unarmed_CZ_WDL"];
	
	//Tatra T810 armed
	["CUP_T810_Armed_Base","init",{[(_this select 0),[
		[["Land_Boxloader_mem_kamaz",[0.1,-1.05,-1.26],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[1,2,3,4,5,6,7,8,9,10],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Datsun
	["CUP_Datsun_civil_Base","init",{if ((_this select 0) isKindOf "CUP_C_Datsun_4seat") exitWith {
	[(_this select 0),[
		[["Land_Boxloader_mem_cupdatsun",[0,-0.9,-1.1],0,"Select front of cargo bed","Unload front of cargo bed",true,["Use front of cargo bed","Use front bed passenger seat",false,[],[2],false]],"boxloader_rack0"],
		[["Land_Boxloader_mem_cupdatsun_rear",[0,-1.8,-1.1],0,"Select rear of cargo bed","Unload rear of cargo bed",true,["Use rear of cargo bed","Use rear bed passenger seats",false,[],[0,1],false]],"boxloader_rack1"]
	],0] spawn boxloader_retrofit_fnc_setup;
	};
	[(_this select 0),[
		[["Land_Boxloader_mem_cupdatsun",[0,-0.9,-1.1],0,"Select front of cargo bed","Unload front of cargo bed",true,["Use front of cargo bed","Use front bed passenger seat",false,[],[2],false]],"boxloader_rack0"],
		[["Land_Boxloader_mem_cupdatsun_rear",[0,-1.8,-1.1],0,"Select rear of cargo bed","Unload rear of cargo bed",false,[]],"boxloader_rack1"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	
	["CUP_Datsun_PK_Base","init",{
	[(_this select 0),[
		[["Land_Boxloader_mem_cupdatsun_rear",[0,-1.8,-1.1],0,"Select rear of cargo bed","Unload rear of cargo bed",true,["Use rear of cargo bed","Use rear bed passenger seats",false,[],[0,1],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	
};
//IFA3

if (isClass(configFile >> "CfgPatches" >> "LIB_core")) then {

	//GMC
	["LIB_US_GMC_Open","init",{[(_this select 0),[
		[["Land_Boxloader_mem_ifa",[0.1,-0.6,0],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seat",false,[1,2,3,4,5,6,7,8,9,10,11,12],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	["LIB_US6_Unarmed_base","init",{if ((_this select 0) isKindOf "LIB_US6_Tent_Cargo") exitWith {false};[(_this select 0),[
		[["Land_Boxloader_mem_ifa",[0.1,-1.7,0.25],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seat",false,[1,2,3,4,5,6,7,8,9,10,11,12],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;

	["LIB_opelblitz_open_y_camo","init",{[(_this select 0),[
		[["Land_Boxloader_mem_ifa",[0.1,-1,0],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seat",false,[1,2,3,4,5,6,7,8,9,10,11,12],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;

	["LIB_Zis5v","init",{[(_this select 0),[
		[["Land_Boxloader_mem_ifazis",[0.1,-1,-0.75],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seat",false,[1,2,3,4,5,6,7,8,9,10,11,12],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	["LIB_C47_Skytrain","init",{[(_this select 0),[
		[["Land_Boxloader_mem_ifac47",[0,2,-1],0,"Select cargo area","Unload cargo area",true,["Use cargo area","Use passenger seats",false,[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	["LIB_CG4_Waco","init",{[(_this select 0),[
		[["Land_Boxloader_mem_ifawaco_rear",[0,0.1,-1.8],0,"Select tail cargo area","Unload tail cargo area",false,[],[],"",-9],"boxloader_rack0"],
		[["Land_Boxloader_mem_ifawaco_front",[0,3.7,-1.8],0,"Select seat cargo area","Unload seat cargo area",true,["Use seat cargo area","Use passenger seats",false,[0,1,2,3,4,5,6,7,8,9,10,11,12,13],[],false]],"boxloader_rack1"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	["LIB_Horsa","init",{[(_this select 0),[
		[["Land_Boxloader_mem_ifahorsa_front",[0,2.1,-2],0,"Select seat cargo area","Unload seat cargo area",true,["Use seat cargo area","Use passenger seats",false,[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
};


//CSAT Modification Project
if (isClass(configFile >> "CfgPatches" >> "CSAT_Vehicles")) then {
	//KAMAZ
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_kamaz",[0.1,-1.3,-0.76],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[2,3,4,5,6,7,8,9,10,11,12,13],[14,15],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["TEC_VH_Truck_Zamak_Covered","TEC_VH_Truck_Zamak"];
	
	//KAMAZ Medical
	["TEC_VH_Truck_Zamak_Medical_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_kamaz",[0.1,-1.3,-0.76],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[2,3,4,5,6,7,8,9,10,11,12,13,14,15],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//KAMAZ repair
	["TEC_VH_Truck_Zamak_Repair_F","init",{if ((_this select 0) isKindOf "Truck_02_medical_base_F") exitWith {false};[(_this select 0),[
		[["Boxloader_Bucket",[0,4.5,-2],0,"Select bucket","Unload bucket",true,["Deploy bucket","Stow bucket",true,[],[],true],[],"Install bucket"],"boxloader_rack0"]
	]] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Typhoon
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_hemtt",[0.1,-2.5,-0.38],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[1,2,3,4,6,7,8,9,10,12],[5,11],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["TEC_VH_Truck_Tempest","TEC_VH_Truck_Tempest_Covered"];
	
	//Typhoon medical
	["TEC_VH_Truck_Tempest_medical_F","init",{[(_this select 0),[
		[["Land_Boxloader_mem_hemtt",[0.1,-2.5,-0.38],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[1,2,3,4,5,6,7,8,9,10,11],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
};
//Unsung
if (isClass(configFile >> "CfgPatches" >> "uns_main")) then {

	//M37
	["uns_m37b1","init",{[(_this select 0),[
		[["Land_Boxloader_mem_uns_m37",[0,-1.8,-0.78],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[1,2,3,4,5,6],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//M35A2
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_rhsural",[0,-1.5,-0.5],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[3,4,5,6,7,8,9,10],[1,2],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["uns_M35A2","uns_M35A2_Open"];
	
	//ZIL-157
	["uns_zil157","init",{[(_this select 0),[
		[["Land_Boxloader_mem_cupv3s",[0,-1.2,1.45],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[1,2,3,4,5,6,7,8,9,10,11,12],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;
	
	//Ural
	{[_x,"init",{[(_this select 0),[
		[["Land_Boxloader_mem_rhsural",[0,-1.6,0.1],0,"Select rear cargo bed","Unload rear cargo bed",true,["Use rear cargo bed","Use rear passenger seats",true,[2,3,4,5,6,7,8,9,10,11,12,13,14],[],false]],"boxloader_rack0"]
	],0] spawn boxloader_retrofit_fnc_setup}] call CBA_fnc_addClassEventHandler;} forEach ["uns_nvatruck","uns_nvatruck_camo","uns_nvatruck_open"];
};
true


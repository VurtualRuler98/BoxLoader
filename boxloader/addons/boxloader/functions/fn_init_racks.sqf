if (is3DEN) exitWith {false};
if (isClass(configFile >> "CfgPatches" >> "cba_main")) then {
	["Quadbike_01_Base_F","init",{(_this select 0) call boxloader_fnc_rack_quad}] call CBA_fnc_addClassEventHandler;
	["Van_02_base_F","init",{(_this select 0) call boxloader_fnc_rack_idap}] call CBA_fnc_addClassEventHandler;
	["Offroad_01_civil_base_F","init",{(_this select 0) call boxloader_fnc_rack_offroad}] call CBA_fnc_addClassEventHandler;
	["I_G_Offroad_01_F","init",{(_this select 0) call boxloader_fnc_rack_offroad}] call CBA_fnc_addClassEventHandler;
	["B_Truck_01_transport_F","init",{(_this select 0) call boxloader_fnc_rack_hemtt}] call CBA_fnc_addClassEventHandler;
	["Van_01_transport_base_F","init",{(_this select 0) call boxloader_fnc_rack_boxer}] call CBA_fnc_addClassEventHandler;
	{[_x,"init",{(_this select 0) call boxloader_fnc_rack_kamaz}] call CBA_fnc_addClassEventHandler;} forEach ["Truck_02_transport_Base_F","O_Truck_02_covered_F","I_Truck_02_covered_F","C_Truck_02_covered_F","C_IDAP_Truck_02_F"];
	["RHS_Ural_Flat_MSV_01","init",{(_this select 0) call boxloader_fnc_rack_rhsural}] call CBA_fnc_addClassEventHandler;
	["rhs_gaz66o_flat_vmf","init",{(_this select 0) call boxloader_fnc_rack_rhsgaz}] call CBA_fnc_addClassEventHandler;
	["rhs_gaz66_flat_vmf","init",{(_this select 0) call boxloader_fnc_rack_rhsgaz}] call CBA_fnc_addClassEventHandler;
	["RHS_Ural_Open_Flat_MSV_01","init",{(_this select 0) call boxloader_fnc_rack_rhsural}] call CBA_fnc_addClassEventHandler;
} else {
	[] spawn {
		while {true} do {
			{
				if (!(_x getVariable ["boxloader_rackinit",false])) then {
					if ((_x isKindOf "Quadbike_01_Base_F")) then {
						_x call boxloader_fnc_rack_quad;
					};
					if ((_x isKindOf "Van_02_base_F")) then {
						_x call boxloader_fnc_rack_idap;
					};
					if ((_x isKindOf "Offroad_01_civil_base_F") || (_x isKindOf "I_G_Offroad_01_F")) then {
						_x call boxloader_fnc_rack_offroad;
					};
					if (_x isKindOf "B_Truck_01_transport_F") then {
						_x call boxloader_fnc_rack_hemtt;
					};
					if (_x isKindOf "Van_01_transport_base_F") then {
						_x call boxloader_fnc_rack_boxer;
					};
					if ((_x isKindOf "Truck_02_transport_Base_F") || (typeOf _x in ["O_Truck_02_covered_F","I_Truck_02_covered_F","C_Truck_02_covered_F","C_IDAP_Truck_02_F"])) then {
						_x call boxloader_fnc_rack_kamaz;
					};
					if ((_x isKindOf "RHS_Ural_Flat_MSV_01") || (_x isKindOf "RHS_Ural_Open_Flat_MSV_01")) then {
						_x call boxloader_fnc_rack_rhsural;
					};
					if ((_x isKindOf "rhs_gaz66o_flat_vmf") || (_x isKindOf "rhs_gaz66_flat_vmf")) then {
						_x call boxloader_fnc_rack_rhsgaz;
					};
				};
			} forEach vehicles;
			sleep 10;
		};
	};
};
true


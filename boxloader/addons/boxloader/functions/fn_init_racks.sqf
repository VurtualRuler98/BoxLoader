if (is3DEN) exitWith {false};
if (isClass(configFile >> "CfgPatches" >> "cba_main")) then {
	["Quadbike_01_Base_F","init",{(_this select 0) call boxloader_fnc_quadrack}] call CBA_fnc_addClassEventHandler;
	["Van_02_base_F","init",{(_this select 0) call boxloader_fnc_rack_van}] call CBA_fnc_addClassEventHandler;
	["Offroad_01_civil_base_F","init",{(_this select 0) call boxloader_fnc_rack_offroad}] call CBA_fnc_addClassEventHandler;
	["I_G_Offroad_01_F","init",{(_this select 0) call boxloader_fnc_rack_offroad}] call CBA_fnc_addClassEventHandler;
	["B_Truck_01_transport_F","init",{(_this select 0) call boxloader_fnc_rack_hemtt}] call CBA_fnc_addClassEventHandler;
	{[_x,"init",{(_this select 0) call boxloader_fnc_rack_kamaz}] call CBA_fnc_addClassEventHandler;} forEach ["Truck_02_transport_Base_F","O_Truck_02_covered_F","I_Truck_02_covered_F","C_Truck_02_covered_F","C_IDAP_Truck_02_F"];
} else {
	[] spawn {
		while {true} do {
			{
				if ((_x isKindOf "Quadbike_01_Base_F") && !(_x getVariable["boxloader_rackinit",false])) then {
					_x call boxloader_fnc_quadrack;
				};
				if ((_x isKindOf "Van_02_base_F") && !(_x getVariable["boxloader_rackinit",false])) then {
					_x call boxloader_fnc_rack_van;
				};
				if ((_x isKindOf "Offroad_01_civil_base_F") && !(_x getVariable["boxloader_rackinit",false])) then {
					_x call boxloader_fnc_rack_offroad;
				};
				if (_x isKindOf "B_Truck_01_transport_F") then {
					_x call boxloader_fnc_rack_hemtt;
				};
				if ((_x isKindOf "Truck_02_transport_Base_F") || (typeOf _x in ["O_Truck_02_covered_F","I_Truck_02_covered_F","C_Truck_02_covered_F","C_IDAP_Truck_02_F"])) then {
					_x call boxloader_fnc_rack_kamaz;
				};
			} forEach vehicles;
			sleep 10;
		};
	};
};
true


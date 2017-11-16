if (is3DEN) exitWith {false};
if (isClass(configFile >> "CfgPatches" >> "cba_main")) then {
	["Quadbike_01_Base_F","init",{(_this select 0) call boxloader_fnc_quadrack}] call CBA_fnc_addClassEventHandler;
	["Van_02_base_F","init",{(_this select 0) call boxloader_fnc_rack_van}] call CBA_fnc_addClassEventHandler;
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
			} forEach vehicles;
			sleep 10;
		};
	};
};
true


if (!hasInterface) exitWith {false};
player addEventHandler ["Respawn",{[_this select 0] call boxloader_fnc_addaction}];
[player] call boxloader_fnc_addaction;
[] spawn {
	waitUntil {time > 0};
	["unit", {
		if (!((_this select 0) getVariable ["boxloader_init",false])) then { [_this select 0] call boxloader_fnc_addaction;};
	}] call CBA_fnc_addPlayerEventHandler;
};
true


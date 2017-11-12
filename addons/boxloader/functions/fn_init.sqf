if (!hasInterface) exitWith {false};
//[player] call boxloader_fnc_addaction;
player addEventHandler ["Respawn",{[_this select 0] call boxloader_fnc_addaction}];
if (!(player getVariable ["boxloader_init",false])) then {
	[player] call boxloader_fnc_addaction;
};
true


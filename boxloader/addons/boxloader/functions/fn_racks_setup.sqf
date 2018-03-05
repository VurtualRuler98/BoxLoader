params [["_veh",objNull,[objNull]],["_racks",[],[[]]]];
if !(boxloader_retrofit_enabled) exitWith {false};
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
if (_veh getVariable ["boxloader_rackinit",false]) exitWith {false};
_veh setVariable ["boxloader_rackinit",true];
waitUntil {time > 0};
if (isServer) then {_veh setVariable ["boxloader_cargohidden",false,true]};
{[_veh,_x select 0,_x select 1] call boxloader_fnc_racks_add} forEach _racks;

true



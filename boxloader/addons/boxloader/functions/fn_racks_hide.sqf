params [["_veh",objNull,[objNull]],["_hide",false,[true]]];
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
if (!(_veh getVariable ["boxloader_rackinit",false])) exitWith {false};
_veh setVariable ["boxloader_hidecargo",_hide];
waitUntil {time > 0};
{[_veh,_x select 0,_x select 1] call boxloader_fnc_racks_add} forEach _racks;
_veh addAction ["Hide Cargo",{[(_this select 0),true] call boxloader_fnc_racks_hide;},[],0,false,true,"","(vehicle _this == _target) && !(vehicle getVariable ['boxloader_hidecargo',true])"];
_veh addAction ["Show Cargo",{[(_this select 0),false] call boxloader_fnc_racks_hide;},[],0,false,true,"","(vehicle _this == _target) && (vehicle getVariable ['boxloader_hidecargo',false])"];
true



params [["_veh",objNull,[objNull]],["_racks",[],[[]]]];
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
if (_veh getVariable ["boxloader_rackinit",false]) exitWith {false};
_veh setVariable ["boxloader_rackinit",true];
waitUntil {time > 0};
if (isServer) then {
	_veh setVariable ["boxloader_lockcargo",true,true];
	_veh setVariable ["boxloader_racks",false,true];
};
{[_veh,_x select 0,_x select 1] call boxloader_fnc_racks_add} forEach _racks;
_rackVars = [];
{_rackVars pushBack (_x select 1)} forEach _racks;

_veh addAction ["Lock Cargo",{[(_this select 0),(_this select 3 select 0),true] call boxloader_fnc_racks_lock;},[_rackVars],0,false,true,"","(vehicle _this == _target) && !(_target getVariable ['boxloader_lockcargo',true]) && (_target getVariable ['boxloader_racks',false])"];
_veh addAction ["Unlock Cargo",{[(_this select 0),(_this select 3 select 0),false] call boxloader_fnc_racks_lock;},[_rackVars],0,false,true,"","(vehicle _this == _target) && (_target getVariable ['boxloader_lockcargo',false]) && (_target getVariable ['boxloader_racks',false])"];
true



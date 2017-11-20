params [["_veh",objNull,[objNull]],["_rackVars",[],[[]]],["_lock",false,[false]]];
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
if (!(_veh getVariable ["boxloader_rackinit",false])) exitWith {false};
_veh setVariable ["boxloader_lockcargo",_lock];
_racks = [];
{_obj = (_veh getVariable [_x,[objNull]] select 0); if (!(isNull _obj) && _obj isKindOf "Boxloader_Pallet_Base") then {_racks pushBack (_obj)};} forEach _rackVars;
if (_lock) then {
	{_cargo = getVehicleCargo _x; _x setVariable ["boxloader_cargo",_cargo,true]; _x setVariable ["boxloader_cargo_locked",true,true]; {_x attachTo [_veh];} forEach _cargo;} forEach _racks;
} else {
	{_rack = _x; _cargo = _x getVariable["boxloader_cargo",[]]; {detach _x; _rack setVehicleCargo _x} forEach _cargo; _x setVariable ["boxloader_cargo_locked",false,true];} forEach _racks;
};
true



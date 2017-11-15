params [["_veh",objNull,[objNull]],["_obj","",[""]]];
if (!isServer || is3DEN) exitWith {false};
if (isNull _veh) exitWith {["You tried to init a pallet on a thing that doesn't exist!"] call bis_fnc_error; false};
if (!(_veh isKindOf "Boxloader_Pallet_base_ed")) exitWith {["That's not a pallet!"] call bis_fnc_error;false};
if (!(_obj isKindOf "Boxloader_Pallet_base")) exitWith {["We can't make something into not a pallet."] call bis_fnc_error;false};
_pallet = _obj createVehicle (position _veh);
if (isNull _pallet) exitWith {false};
_pallet setPosASL (getPosASL _veh);
[_veh,_pallet] spawn {
	params ["_veh","_pallet"];
	sleep 0.1;
	{if (_veh in curatorEditableObjects _x) then {_x addCuratorEditableObjects [[_pallet],false]}} forEach allCurators;
	deleteVehicle _veh;
};
true


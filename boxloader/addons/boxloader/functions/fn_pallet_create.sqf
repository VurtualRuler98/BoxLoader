params [["_veh",objNull,[objNull]]];
if (!isServer || is3DEN) exitWith {objNull};
if (isNull _veh) exitWith {["You tried to init a pallet on a thing that doesn't exist!"] call bis_fnc_error; objNull};
if (!(_veh isKindOf "Boxloader_Pallet_base_ed")) exitWith {["That's not a pallet!"] call bis_fnc_error;objNull};
_obj = getText (configFile >> "CfgVehicles" >> (typeOf _veh) >> "BoxloaderClass");
if (!(_obj isKindOf "Boxloader_Pallet_base")) exitWith {["We can't make something into not a pallet."] call bis_fnc_error;objNull};
_pallet = _obj createVehicle (position _veh);
if (isNull _pallet) exitWith {false};
_pallet setPosASL [getPosASL _veh select 0, getPosASL _veh select 1, (getPosASL _veh select 2)+0.1];
_pallet setVectorDirAndUp [vectorDir _veh,vectorUp _veh];
_veh enableSimulation false;
[_veh,_pallet] spawn {
	params ["_veh","_pallet"];
	sleep 0.1;
	{if (_veh in curatorEditableObjects _x) then {_x addCuratorEditableObjects [[_pallet],false]}} forEach allCurators;
	deleteVehicle _veh;
};
_pallet


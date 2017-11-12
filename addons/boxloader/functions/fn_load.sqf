params [["_veh",objNull,[objNull]],["_box",objNull,[objNull]]];
if (isNull _veh || isNull _box) exitWith {false};
if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {
	_veh setVehicleCargo _box;true
} else {false}



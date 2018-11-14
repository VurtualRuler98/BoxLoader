params [["_veh",objNull,[objNull]],["_box",objNull,[objNull]]];
if (isNull _veh || !(_veh getVariable ["boxloader_flatrack_carrier",false])) exitWith {false};
if (isNull _box) then {
	_box = _veh getVariable ["boxloader_flatrack",objNull];
	if ((attachedTo _box)==_veh) then {
		detach _box;
		_pos = _veh modelToWorld (_veh selectionPosition ["boxloader_flatrack_exit","Memory"]);
		_box setVehiclePosition [_pos,[],0,"CAN_COLLIDE"];
	};
	_veh setVariable ["boxloader_flatrack",objNull,true];
	true
} else {
	if (!(isNull (_veh getVariable ["boxloader_flatrack",objNull])) || !(isNull isVehicleCargo _box) || !(_box getVariable ["boxloader_flatrack_cargo",false]) || ((_veh distance _box)>25)) exitWith {false};
	_box attachTo [_veh,[0,0,0],"boxloader_flatrack_pos"];
	_veh setVariable ["boxloader_flatrack",_box,true];
	true
}
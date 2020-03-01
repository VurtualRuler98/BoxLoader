params [["_pallet",objNull,[objNull]],["_name","pallet",[""]]];
//if (isClass(configFile >> "CfgPatches" >> "boxloader_ace")) then {
//	_pallet setVariable ["boxloader_dontselect",true,true];
//} else {
_pallet lockCargo [0,true];
_pallet addAction ["Load "+_name+" in target",{_veh = (_this select 1 getVariable ["boxloader_tgt",objNull]); _box = (_this select 0); if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load};},[],0,false,true,"","(vehicle _this == _this) && !(isNull (_this getVariable ['boxloader_tgt',objNull])) && (((_this getVariable ['boxloader_tgt',objNull]) canVehicleCargo _target) select 0) && ((_this getVariable ['boxloader_tgt',objNull]) distance _target)<15 && (!boxloader_maxload_enabled || [_this,_target] call boxloader_fnc_getmaxlift)",5];
_pallet setVariable ["boxloader_bucketable",true];
_pallet addAction ["Rotate "+_name,{
	_ply = _this select 1;
	_box = _this select 0;
	_veh = (_ply getVariable ["boxloader_tgt",objNull]);
	_dir = (getDir _ply - getDir _box);
	if ((((_veh canVehicleCargo _box) select 1) || (_veh isKindOf "Boxloader_Bucket")) && (_dir > 345 || _dir < 15)) then {
		_box setDir floor(getDir _ply)
	};
	[_box] call boxloader_fnc_persist;
},[],0,false,true,"","(vehicle _this == _this) && (isNull attachedTo _target) && !(isNull (_this getVariable ['boxloader_tgt',objNull])) && (((_this getVariable ['boxloader_tgt',objNull]) isKindOf 'Boxloader_Bucket') || (((_this getVariable ['boxloader_tgt',objNull]) canVehicleCargo _target) select 1)) && ((_this getVariable ['boxloader_tgt',objNull]) distance _target)<15 && ((getDir _this - getDir _target)>345 || (getDir _this - getDir _target)<15)",5];
//};
true
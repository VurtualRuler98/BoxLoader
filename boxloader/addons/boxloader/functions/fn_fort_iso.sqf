//0, _box: object we are adding HESCO actions to
params [["_box",objNull,[objNull]],["_col",0,[0]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Fort_iso_Green")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (count ((position _this) nearObjects ['B_APC_Tracked_01_CRV_F',15])>0))"];
_arr = [];
if (_col==1) then {
	_arr = [["Land_Cargo_House_V1_F","Build Cargo House (Green)"],["Land_Cargo_Patrol_V1_F","Build Cargo Post (Green)"]];
};
if (_col==2) then {
	_arr = [["Land_Cargo_House_V2_F","Build Cargo House (Rusty)"],["Land_Cargo_Patrol_V2_F","Build Cargo Post (Rusty)"]];
};
if (_col==3) then {
	_arr = [["Land_Cargo_House_V3_F","Build Cargo House (Brown)"],["Land_Cargo_Patrol_V3_F","Build Cargo Post (Brown)"]];
};
if (_col==0) then {
	_arr = [["Land_Medevac_House_V1_F","Build Medical House"]];
};
{
	_box addAction [(_x select 1),{
		_con = (_this select 3 select 0) createVehicle (position (_this select 0));
		_con setPosASL getPosASL (_this select 0);
		_con setDir getdir (_this select 0);
		[_con,typeOf (_this select 0)] call boxloader_fnc_fort_iso_built;
		deleteVehicle (_this select 0);
	},[_x select 0],0,false,true,"","(isNull attachedTo _target) && (_target getVariable ['BuildMenu',false]) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (count ((position _this) nearObjects ['B_APC_Tracked_01_CRV_F',15])>0))"];
} forEach _arr;
_box setVariable ["boxloader_bucketable",true];
_box addAction ["Rotate Container",{
	_ply = _this select 1;
	_box = _this select 0;
	_veh = (_ply getVariable ["boxloader_tgt",objNull]);
	_dir = (getDir _ply - getDir _box);
	if ((((_veh canVehicleCargo _box) select 1) || (_veh isKindOf "Boxloader_Bucket")) && (_dir > 345 || _dir < 15)) then {
		_box setDir floor(getDir _ply)
	};
},[],0,false,true,"","(vehicle _this == _this) && !(isNull (_this getVariable ['boxloader_tgt',objNull])) && (((_this getVariable ['boxloader_tgt',objNull]) isKindOf 'Boxloader_Bucket') || (((_this getVariable ['boxloader_tgt',objNull]) canVehicleCargo _target) select 1)) && ((_this getVariable ['boxloader_tgt',objNull]) distance _target)<15 && ((getDir _this - getDir _target)>345 || (getDir _this - getDir _target)<15)",5];
true 
// && (count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)
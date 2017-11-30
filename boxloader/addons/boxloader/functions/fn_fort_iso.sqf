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
true 
// && (count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)
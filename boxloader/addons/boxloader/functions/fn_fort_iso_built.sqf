params [["_box",objNull,[objNull]],["_base","",[""]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_base isKindOf "Land_Boxloader_Fort_iso_Green")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_tools',false]) || (((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_tools',false]) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15))"];
_box addAction ["Pack Structure",{
	_con = (_this select 3 select 0) createVehicle (position (_this select 0));
	_con setDir (getDir (_this select 0));
	_pos = getPosASL (_this select 0);
	_con setVehiclePosition [getPosATL _con,[],0,"CAN_COLLIDE"];
	_con setPosASL _pos;
	deleteVehicle (_this select 0);
	[_con,_box] remoteExec ["boxloader_fnc_alive",2];
},[_base],0,false,true,"","(_target getVariable ['BuildMenu',false]) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_tools',false]) || (((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_tools',false]) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15))"];
true 
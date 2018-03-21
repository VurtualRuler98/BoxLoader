params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box)) exitWith {false};
_obj = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_ConBase");
_box setVariable ["BuildMenu",false];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_tools',false]) || (((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_tools',false]) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15))"];
_box addAction ["Disassemble Fortification",{
	_con = (_this select 3 select 0) createVehicle (position (_this select 0));
	_con setDir (getDir (_this select 0));
	_pos = getPosASL (_this select 0);
	_con setVehiclePosition [getPosATL _con,[],0,"CAN_COLLIDE"];
	_con setPosASL _pos;
	deleteVehicle (_this select 0);
},[_obj],0,false,true,"","(vehicle _this == _this) && (_target getVariable ['BuildMenu',false]) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_tools',false]) || (((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_tools',false]) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15))"];
//_box addEventHandler["HandleDamage",{if (((_this select 0) animationSourcePhase 'Fill_Source')<0.5) exitWith {0}}];
true 
//(count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)
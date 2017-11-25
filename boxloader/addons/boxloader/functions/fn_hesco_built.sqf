params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box)) exitWith {false};
_obj = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_ConBase");
_box addAction ["Disassemble HESCO",{
	_con = (_this select 3 select 0) createVehicle (position (_this select 0));
	_con setPosASL getPosASL (_this select 0);
	_con setDir (getDir (_this select 0));
	deleteVehicle (_this select 0);
},[_obj],0,false,true,"","vehicle _this == _this && (_target animationSourcePhase 'Fill_Source')==1"];
_box addAction ["Fill HESCO",{
	(_this select 0) animateSource ["Fill_Source",0];
	(_this select 0) animateSource ["Empty_Source",1];
},[],0,false,true,"","(({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (count ((position _this) nearObjects ['B_APC_Tracked_01_CRV_F',15])>0)) && (_target animationSourcePhase 'Fill_Source')==1"];
_box addAction ["Empty HESCO",{
	(_this select 0) animateSource ["Fill_Source",1];
	(_this select 0) animateSource ["Empty_Source",0];
},[],0,false,true,"","(({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (count ((position _this) nearObjects ['B_APC_Tracked_01_CRV_F',15])>0)) && (_target animationSourcePhase 'Fill_Source')==0"];
//_box addEventHandler["HandleDamage",{if (((_this select 0) animationSourcePhase 'Fill_Source')<0.5) exitWith {0}}];
true 
//(count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)
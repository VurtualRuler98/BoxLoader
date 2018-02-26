params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box)) exitWith {false};
_obj = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_ConBase");
_box addAction ["Disassemble Fortification",{
	_con = (_this select 3 select 0) createVehicle (position (_this select 0));
	_con setDir (getDir (_this select 0));
	_pos = getPosASL (_this select 0);
	_con setVehiclePosition [getPosATL _con,[],0,"CAN_COLLIDE"];
	_con setPosASL _pos;
	deleteVehicle (_this select 0);
},[_obj],0,false,true,"","vehicle _this == _this && (_target animationSourcePhase 'Fill_Source')==1"];
_box addAction ["Fill Fortification",{
	(_this select 0) animateSource ["Fill_Source",0];
	(_this select 0) animateSource ["Lift_Source",1];
},[],0,false,true,"","(({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_fill',false])) && (_target animationSourcePhase 'Fill_Source')==1"];
_box addAction ["Empty Fortification",{
	(_this select 0) animateSource ["Fill_Source",1];
	(_this select 0) animateSource ["Lift_Source",0];
},[],0,false,true,"","(({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) ||(vehicle _this getVariable ['boxloader_build_fill',false])) && (_target animationSourcePhase 'Fill_Source')==0"];
//_box addEventHandler["HandleDamage",{if (((_this select 0) animationSourcePhase 'Fill_Source')<0.5) exitWith {0}}];
true 
//(count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)
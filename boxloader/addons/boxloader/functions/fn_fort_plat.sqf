//0, _box: object we are adding HESCO actions to
params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Fort_Plat_Flat")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_tools',false]) || (((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_tools',false]) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15))"];
_arr = [["Land_Boxloader_Fort_Plat_5","Build Wood Platform 5x5m"],["Land_Boxloader_Fort_Plat_3","Build Wood Platform 3x3m"]];
_box addAction ["Pick up",{
	(_this select 0) attachTo [(_this select 1),[0,2,0.2]];
	(_this select 0) setDir ((_this select 0) getVariable ["BuildDir",0]);
	_ac0=(_this select 1) addAction ["Rotate Fortification",{_dir = (((_this select 3 select 0) getVariable ["BuildDir",0])+60); (_this select 3 select 0) setVariable ["BuildDir",_dir];(_this select 3 select 0) setDir _dir;},[_this select 0]];
	_ac1=(_this select 1) addAction ["Lift Fortification",{(_this select 3 select 0) attachTo [(_this select 0),[0,2,1.6]]},[_this select 0]];
	_ac2=(_this select 1) addAction ["Lower Fortification",{(_this select 3 select 0) attachTo [(_this select 0),[0,2,0.2]]},[_this select 0]];
	_ac3=(_this select 1) addAction ["Drop Fortification",{
		detach (_this select 3 select 0);
		(_this select 3 select 0) setVehiclePosition [(getposATL (_this select 3 select 0)),[],0,"CAN_COLLIDE"];
	},[_this select 0]];
	[(_this select 0),(_this select 1),[_ac0,_ac1,_ac2,_ac3]] spawn {
		waitUntil {sleep 0.1; ((isNull (_this select 0)) || (isNull (_this select 1)) || (!alive (_this select 1)) || (isNull attachedTo (_this select 0)))};
		{(_this select 1) removeAction _x} forEach (_this select 2);
		sleep 0.1;
		(_this select 0) setVelocity [0,0,0];
	};
},[],0.5,false,true,"","isNull attachedTo _target"];
{
	_box addAction [(_x select 1),{
		_con = (_this select 3 select 0) createVehicle (position (_this select 0));
		_con setPosASL getPosASL (_this select 0);
		_con setDir getdir (_this select 0);
		deleteVehicle (_this select 0);
	},[_x select 0],0,false,true,"","(isNull attachedTo _target) && (_target getVariable ['BuildMenu',false]) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_tools',false]) ||(((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_tools',false]) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15))"];
} forEach _arr;
true 
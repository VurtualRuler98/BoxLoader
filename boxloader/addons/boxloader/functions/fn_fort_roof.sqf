//0, _box: object we are adding HESCO actions to
params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Fort_Roof_Flat")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box setVariable ["BuildDir",0];
_fortName = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_ConName");
_fortObj = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_ConBase");
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target)"];
_box addAction ["Pick up",{
	(_this select 0) attachTo [(_this select 1),[0,2,0]];
	(_this select 0) setDir ((_this select 0) getVariable ["BuildDir",0]);
	_ac0=(_this select 1) addAction ["Rotate Fortification",{_dir = (((_this select 3 select 0) getVariable ["BuildDir",0])+60); (_this select 3 select 0) setVariable ["BuildDir",_dir];(_this select 3 select 0) setDir _dir;},[_this select 0]];
	_ac1=(_this select 1) addAction ["Lift Fortification",{(_this select 3 select 0) attachTo [(_this select 0),[0,2,1.5]]},[_this select 0]];
	_ac2=(_this select 1) addAction ["Lower Fortification",{(_this select 3 select 0) attachTo [(_this select 0),[0,2,0]]},[_this select 0]];
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
_box addAction [_fortName,{
	_con = (_this select 3 select 0) createVehicle (position (_this select 0));
	_con setPosASL getPosASL (_this select 0);
	_con setDir getdir (_this select 0);
	_pos = getPosASL _con;
	deleteVehicle (_this select 0);
	_con setVehiclePosition [getPosATL _con,[],0,"CAN_COLLIDE"];
	_con setPosASL _pos;
},[_fortObj],0,false,true,"","(isNull attachedTo _target) && (_target getVariable ['BuildMenu',false])"];

true 
// && (count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)
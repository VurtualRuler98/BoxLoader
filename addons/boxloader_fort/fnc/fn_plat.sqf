//0, _box: object we are adding HESCO actions to
params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Fort_Plat_Flat")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15"];
_arr = [["Land_Boxloader_Fort_Plat_5","Build Wood Platform 5x5m"],["Land_Boxloader_Fort_Plat_3","Build Wood Platform 3x3m"]];
_box addAction ["Pick up",{
	(_this select 0) attachTo [(_this select 1),[0,2,0.2]];
	(_this select 0) animateSource ["Chalk_Line",1];
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
		(_this select 0) animateSource ["Chalk_Line",0];
	};
},[],0.5,false,true,"","isNull attachedTo _target"];
{
	_box addAction [(_x select 1),{
		_con = (_this select 3 select 0) createVehicle (position (_this select 0));
		_con setPosASL getPosASL (_this select 0);
		_con setDir getdir (_this select 0);
		_level = true;
		{
			_pos = (_con modelToWorldWorld (_con selectionPosition _x));
			if (((ASLToATL _pos select 2)>0) && ({typeOf _x == "land_boxloader_fort_ground_5"} count lineIntersectsObjs [_pos,_pos,_con])==0) exitWith {_level=false}
		} forEach [
			"corner1","corner2","corner3","corner4"
		];
		if (_level) then {
			deleteVehicle (_this select 0);
		} else {
			hint "Ground is too steep.";
			deleteVehicle _con;
		};
	},[_x select 0],0,false,true,"","(isNull attachedTo _target) && (_target getVariable ['BuildMenu',false]) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_tools',false]) ||(((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_tools',false]) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15))"];
} forEach _arr;
_box addAction ["Build Foundation",{
		_con = (_this select 3 select 0) createVehicle (position (_this select 0));
		_con setPosASL getPosASL (_this select 0);
		_con setDir getdir (_this select 0);
		_level = true;
		{if (((ASLToATL (_con modelToWorldWorld (_con selectionPosition _x))) select 2)>0) exitWith {_level=false}} forEach [
			"corner1","corner2","corner3","corner4","corner5","corner6","corner7","corner8"
		];
		if (_level) then {
			deleteVehicle (_this select 0);
		} else {
			hint "Ground is too steep.";
			deleteVehicle _con;
		};
	},["Land_Boxloader_Fort_Ground_5"],0,false,true,"","(isNull attachedTo _target) && (_target getVariable ['BuildMenu',false]) && (({(!isObjectHidden _x)} count ((position _this) nearObjects ['Boxloader_Bucket',15])>0) || (vehicle _this getVariable ['boxloader_build_fill',false]) ||(((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_fill',false]) && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15))"];

true 
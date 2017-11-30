//0, _box: object we are adding HESCO actions to
//1, _big: HESCO size, 0 is regular, 1 is big, 2 is small
params [["_box",objNull,[objNull]],["_big",0,[0]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Hesco_Flat")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box setVariable ["BuildDir",0];
_arr = [];
if (_big==0) then {
	_arr=[["Build HESCO (1)","Land_Boxloader_Hesco_1"],["Build HESCO (3)","Land_Boxloader_Hesco_3"],["Build HESCO (5)","Land_Boxloader_Hesco_5"]];
};
if (_big==1) then {
	_arr=[["Build Big HESCO (1)","Land_Boxloader_Hesco_Big1"],["Build Big HESCO (3)","Land_Boxloader_Hesco_Big3"],["Build HESCO Big (5)","Land_Boxloader_Hesco_Big5"]];
};
if (_big==2) then {
	_arr=[["Build Small HESCO (1)","Land_Boxloader_Hesco_Small1"],["Build Small HESCO (6)","Land_Boxloader_Hesco_Small6"],["Build HESCO Small (10)","Land_Boxloader_Hesco_Small10"]];
};
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target)"];
_box addAction ["Pick up",{
	(_this select 0) attachTo [(_this select 1),[0,2,0.2]];
	(_this select 0) setDir ((_this select 0) getVariable ["BuildDir",0]);
	_ac0=(_this select 1) addAction ["Rotate HESCO",{_dir = (((_this select 3 select 0) getVariable ["BuildDir",0])+60); (_this select 3 select 0) setVariable ["BuildDir",_dir];(_this select 3 select 0) setDir _dir;},[_this select 0]];
	_ac1=(_this select 1) addAction ["Lift HESCO",{(_this select 3 select 0) attachTo [(_this select 0),[0,2,1.6]]},[_this select 0]];
	_ac2=(_this select 1) addAction ["Lower HESCO",{(_this select 3 select 0) attachTo [(_this select 0),[0,2,0.2]]},[_this select 0]];
	_ac3=(_this select 1) addAction ["Drop HESCO",{
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
	_box addAction [(_x select 0),{
		_con = (_this select 3 select 0) createVehicle (position (_this select 0));
		_con setPosASL getPosASL (_this select 0);
		_con setDir getdir (_this select 0);
		_pos = getPosASL _con;
		_con setVehiclePosition [getPosATL _con,[],0,"CAN_COLLIDE"];
		_con setPosASL _pos;
		deleteVehicle (_this select 0);
	},[_x select 1],0,false,true,"","(isNull attachedTo _target) && (_target getVariable ['BuildMenu',false])"];

} forEach _arr;
true 
// && (count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)
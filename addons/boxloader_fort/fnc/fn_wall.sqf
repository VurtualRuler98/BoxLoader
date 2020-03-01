//0, _box: object we are adding HESCO actions to
params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if (isNull _box) exitWith {false};
_arr = (configFile >> "CfgVehicles" >> (typeOf _box) >> "boxloader_buildables") call BIS_fnc_getCfgDataArray;
_tools = (configFile >> "CfgVehicles" >> (typeOf _box) >> "boxloader_tools") call BIS_fnc_getCfgDataBool;
_fill = (configFile >> "CfgVehicles" >> (typeOf _box) >> "boxloader_fill") call BIS_fnc_getCfgDataBool;
_snap = (configFile >> "CfgVehicles" >> (typeOf _box) >> "boxloader_snap") call BIS_fnc_getCfgDataBool;
if (_snap) then {
	_box addAction ["Disable snapping",{
		(_this select 1) setVariable ['BuildMenu_snap',false,false];
	},[],0.5,false,true,"",([_tools,_fill,true] call boxloader_fort_fnc_buildcondition) + " && (_this getVariable ['BuildMenu_snap',true])"];
	_box addAction ["Enable snapping",{
		(_this select 1) setVariable ['BuildMenu_snap',true,false];
	},[],0.5,false,true,"",([_tools,_fill,true] call boxloader_fort_fnc_buildcondition) + " && !(_this getVariable ['BuildMenu_snap',true])"];
};
[_box,_tools,_fill] call boxloader_fort_fnc_buildmenu;
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
		[_this select 3 select 0] call boxloader_fnc_persist;
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
	_x params [["_con","",[""]],["_name","ERROR",[""]],["_land",[],[[]]]];
	_box addAction [_name,{
		_con = (_this select 3 select 0) createVehicle (position (_this select 0));
		_land = (_this select 3 select 1);
		_snap = (configFile >> "CfgVehicles" >> (typeOf _con) >> "boxloader_snap") call BIS_fnc_getCfgDataBool;
		_con setPosASL getPosASL (_this select 0);
		_con setDir getdir (_this select 0);
		if (_snap && (_this select 1 getVariable ["BuildMenu_snap",true])) then {
			[_con] call boxloader_fort_fnc_snap;
		};
		if (count _land > 0 && !(boxloader_fort_allow_floating)) then {
			_level = true;
			{
				_pos = (_con modelToWorldWorld (_con selectionPosition _x));
				if (((ASLToATL _pos select 2)>0) && ({_x isKindOf "land_boxloader_fort_ground_5"} count lineIntersectsObjs [_pos,_pos,_con])==0) exitWith {_level=false}
			} forEach _land;
			if (_level) then {
				[_con,_this select 0] call boxloader_fnc_persist;
			} else {
				hint "Ground is too steep.";
				deleteVehicle _con;
			};
		} else {
			if (!_snap) then {
				_pos = getPosASL _con;
				_con setVehiclePosition [getPosATL _con,[],0,"CAN_COLLIDE"];
				_con setPosASL _pos;
			};
			[_con,_this select 0] call boxloader_fnc_persist;
		};
	},[_con,_land],0,false,true,"",[_tools,_fill] call boxloader_fort_fnc_buildcondition];
} forEach _arr;
true 
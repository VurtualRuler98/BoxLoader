params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box)) exitWith {false};
_obj = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_ConBase");
[_box,true,false] call boxloader_fort_fnc_buildmenu;
_box addAction ["Disassemble Fortification",{
	_con = (_this select 3 select 0) createVehicle (position (_this select 0));
	_con setDir (getDir (_this select 0));
	_pos = getPosASL (_this select 0);
	_con setVehiclePosition [getPosATL _con,[],0,"CAN_COLLIDE"];
	_con setPosASL _pos;
	[_con,(_this select 0)] call boxloader_fnc_persist;
},[_obj],0,false,true,"",[true,false] call boxloader_fort_fnc_buildcondition];
true 

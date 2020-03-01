params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box)) exitWith {false};
_hescoIsFilled = getNumber (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_IsFilled");
_fillObject = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_HescoFill");
[_box,false,(_hescoIsFilled==1)] call boxloader_fort_fnc_buildmenu;
if (_hescoIsFilled==0) then {
	_obj = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "Boxloader_ConBase");
	_box addAction ["Disassemble Fortification",{
		_con = (_this select 3 select 0) createVehicle (position (_this select 0));
		_con setDir (getDir (_this select 0));
		_pos = getPosASL (_this select 0);
		_con setVehiclePosition [getPosATL _con,[],0,"CAN_COLLIDE"];
		_con setPosASL _pos;
		[_con,(_this select 0)] call boxloader_fnc_persist;
	},[_obj],0,false,true,"",[false,false] call boxloader_fort_fnc_buildcondition];
};
_fillText = "Fill Fortification";
if (_hescoIsFilled==1) then {
	_fillText = "Empty Fortification";
};
_box addAction [_fillText,{
		_con = (_this select 3 select 0) createVehicle (position (_this select 0));
		_con setPosASL getPosASL (_this select 0);
		_con setVectorDirAndUp [vectorDir (_this select 0),vectorUp (_this select 0)];
		[_con,(_this select 0)] call boxloader_fnc_persist;
},[_fillObject],0,false,true,"",[false,true] call boxloader_fort_fnc_buildcondition];

true 
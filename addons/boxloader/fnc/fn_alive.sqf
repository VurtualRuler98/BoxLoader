_par = params [["_obj",objNull,[objNull]],["_obj2",objNull,[objNull]]]; 
if ((isNull _obj)) exitWith {["Attempting to persist objNull!"] call bis_fnc_error;false};
if !(isClass(configFile >> "CfgPatches" >> "alive_sys_logistics")) exitWith {false};
_id = _obj getVariable "alive_sys_logistics_id";
if ((isNil "_id") && _obj isKindOf "Land_Boxloader_Fort_Base") then {
	_id = format["%1_%2_%3_%4_%5",
		typeOf _obj,
		floor((getposASL _obj select 0)*20),
		floor((getposASL _obj select 1)*20),
		floor((getposASL _obj select 2)*20),
		floor(getDir _obj)
	];
	_obj setVariable ["alive_sys_logistics_id",_id,true];
};
[ALIVE_SYS_LOGISTICS,"updateObject",[_obj]] call alive_fnc_logistics;
if !(isNull _obj2) then {
	[ALIVE_SYS_LOGISTICS,"removeObject",[_obj2]] call alive_fnc_logistics;
	deleteVehicle _obj2;
};
true

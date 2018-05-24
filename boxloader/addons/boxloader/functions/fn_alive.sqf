_par = params [["_obj",objNull,[objNull]],["_obj2",objNull,[objNull]]]; 
if ((isNull _obj ) || !(isClass(configFile >> "CfgPatches" >> "alive_sys_logistics"))) exitWith {false};
[ALIVE_SYS_LOGISTICS,"updateObject",[_obj]] call alive_fnc_logistics;
if !(isNull _obj2) then {
	[ALIVE_SYS_LOGISTICS,"removeObject",[_obj2]] call alive_fnc_logistics;
	deleteVehicle _obj2;
};
true


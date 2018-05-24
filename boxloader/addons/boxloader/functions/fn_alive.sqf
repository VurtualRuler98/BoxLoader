_par = params [["_obj",objNull,[objNull]]]; 
if ((isNull _obj ) || !(isClass(configFile >> "CfgPatches" >> "alive_sys_logistics"))) exitWith {false};
[ALIVE_SYS_LOGISTICS,"updateObject",[_obj]] call alive_fnc_logistics;
true


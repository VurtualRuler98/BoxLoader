_par = params [["_obj",objNull,[objNull]],["_obj2",objNull,[objNull]]]; 
if (!(isNull _obj) && (isClass(configFile >> "CfgPatches" >> "alive_sys_logistics")) && (!isNil "alive_sys_logistics")) exitWith {
	[_obj,_obj2] remoteExec ["boxloader_fnc_alive",2];
	true
};
if !(isNull _obj2) then {
	deleteVehicle _obj2;
};
true

params [["_pallet",objNull,[objNull]]];
//if (isClass(configFile >> "CfgPatches" >> "boxloader_ace")) then {
//	_pallet setVariable ["boxloader_dontselect",true,true];
//} else {
_pallet addAction ["Load pallet in target",{_veh = (_this select 1 getVariable ["boxloader_tgt",objNull]); _box = (_this select 0); if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load};},[],0,false,true,"","(vehicle _this == _this) && !(isNull (_this getVariable ['boxloader_tgt',objNull])) && (((_this getVariable ['boxloader_tgt',objNull]) canVehicleCargo _target) select 0) && ((_this getVariable ['boxloader_tgt',objNull]) distance _target)<15",5];
//};
true
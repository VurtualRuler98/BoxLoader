params [["_pallet",objNull,[objNull]]];

_pallet addAction ["Load pallet in target",{_veh = (_this select 1 getVariable ["loadtest_tgt",objNull]); _box = (_this select 0); if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load};},[],0,false,true,"","(vehicle _this == _this) && !(isNull (_this getVariable ['loadtest_tgt',objNull])) && (((_this getVariable ['loadtest_tgt',objNull]) canVehicleCargo _target) select 0) && ((_this getVariable ['loadtest_tgt',objNull]) distance _target)<15",5];
true
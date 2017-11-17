params [["_ply",objNull,[objNull]]];
if (isNull _ply) exitWith {["Player or vehicle passed was null!"] call bis_fnc_error; false};
_ply setVariable ["boxloader_tgt",objNull,true];
_ply addAction ["<t color='#FF0000'>Stop loading target</t>",{(_this select 0) setVariable ["boxloader_tgt",objNull,true];},[],0,false,true,"","(vehicle _this == _target) && !isNull (_target getVariable ['boxloader_tgt',objNull])"];
_ply addAction ["Select loading target",{_veh = cursorTarget; if ((vehicleCargoEnabled _veh) && ((_veh distance (_this select 0))<15)) then {(_this select 0) setVariable["boxloader_tgt",_veh,true];};},[],0,false,true,"","(vehicle _this == _target) && (isNull (_target getVariable 'boxloader_tgt')) && vehicleCargoEnabled cursorTarget && ((cursorTarget distance _target)<15) && !(cursorTarget getVariable ['boxloader_dontload',false]) && isClass (configFile >> 'CfgVehicles' >> (typeOf cursorTarget) >> 'vehicleTransport' >> 'Carrier')"];
_ply addAction ["Load this in target",{_veh = (_this select 0 getVariable ["boxloader_tgt",objNull]); _box = cursorTarget; if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load};},[],0,false,true,"","(vehicle _this == _target) && !(isNull (_target getVariable ['boxloader_tgt',objNull])) && (((_target getVariable ['boxloader_tgt',objNull]) canVehicleCargo cursorTarget) select 0) && (cursorTarget distance _target)<5 && ((_target getVariable ['boxloader_tgt',objNull]) distance _target)<15 && !(cursorTarget isKindOf 'Boxloader_Pallet_Base')"];
_ply addAction ["Unload object",{_box = cursorTarget; if ((!isNull isVehicleCargo _box) && (_box distance (_this select 0)<10)) then {objNull setVehicleCargo _box};},[],0,false,true,"","(vehicle _this == _target) && (!isNull isVehicleCargo cursorTarget) && (cursorTarget distance _target<10) && !(cursorTarget isKindOf 'Boxloader_Pallet_Base')"];


//if (!isClass(configFile >> "CfgPatches" >> "boxloader_ace")) then {
	_ply addAction ["Unload pallet",{_box = cursorTarget; if ((!isNull isVehicleCargo _box) && (_box distance (_this select 0)<10)) then {objNull setVehicleCargo _box};},[],0,false,true,"","(vehicle _this == _target) && (!isNull isVehicleCargo cursorTarget) && (cursorTarget distance _target<10) && (cursorTarget isKindOf 'Boxloader_Pallet_Base')"];
//};
_ply setVariable["boxloader_init",true];
true


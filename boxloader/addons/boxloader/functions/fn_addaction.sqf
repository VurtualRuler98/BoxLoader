params [["_ply",objNull,[objNull]]];
if (isNull _ply) exitWith {["Player or vehicle passed was null!"] call bis_fnc_error; false};
_ply setVariable ["boxloader_tgt",objNull];
_ply addAction ["<t color='#FF0000'>Stop loading target</t>",{(_this select 0) setVariable ["boxloader_tgt",objNull,true];},[],0,false,true,"","(vehicle _this == _target) && !isNull (_target getVariable ['boxloader_tgt',objNull])"];
_ply addAction ["Select loading target",{_veh = cursorObject; if ((vehicleCargoEnabled _veh) && ((_veh distance (_this select 0))<15)) then {(_this select 0) setVariable["boxloader_tgt",_veh,true];};},[],0,false,true,"","(vehicle _this == _target) && (isNull (_target getVariable 'boxloader_tgt')) && vehicleCargoEnabled cursorObject && ((cursorObject distance _target)<15) && !(cursorObject getVariable ['boxloader_dontload',false]) && isClass (configFile >> 'CfgVehicles' >> (typeOf cursorObject) >> 'vehicleTransport' >> 'Carrier')"];
_ply addAction ["Load this in target",{_veh = (_this select 0 getVariable ["boxloader_tgt",objNull]); _box = cursorObject; if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load};},[],5,false,true,"","(vehicle _this == _target) && !(isNull (_target getVariable ['boxloader_tgt',objNull])) && (((_target getVariable ['boxloader_tgt',objNull]) canVehicleCargo cursorObject) select 0) && (cursorObject distance _target)<5 && ((_target getVariable ['boxloader_tgt',objNull]) distance _target)<15 && !(cursorObject isKindOf 'Boxloader_Pallet_Base')"];
_ply addAction ["Unload object",{_box = cursorObject; if ((!isNull isVehicleCargo _box) && (_box distance (_this select 0)<10)) then {objNull setVehicleCargo _box};},[],0,false,true,"","(vehicle _this == _target) && (!isNull isVehicleCargo cursorObject) && (cursorObject distance _target<10) && !(cursorObject isKindOf 'Boxloader_Pallet_Base')"];
_ply addAction ["Hide cargo",{[vehicle (_this select 0),true] call boxloader_fnc_hide;},[],0,false,true,"","!((vehicle _target) getVariable ['boxloader_cargohidden',false]) && (isClass (configFile >> 'CfgVehicles' >> (typeOf vehicle _target) >> 'vehicleTransport' >> 'Carrier') || ((vehicle _target) getVariable ['boxloader_rackinit',false]))"];
_ply addAction ["Show cargo",{[vehicle (_this select 0),false] call boxloader_fnc_hide;},[],0,false,true,"","((vehicle _target) getVariable ['boxloader_cargohidden',false])"];

//if (!isClass(configFile >> "CfgPatches" >> "boxloader_ace")) then {
	_ply addAction ["Unload pallet",{_box = cursorObject; if ((!isNull isVehicleCargo _box) && (_box distance (_this select 0)<10)) then {objNull setVehicleCargo _box};},[],0,false,true,"","(vehicle _this == _target) && (!isNull isVehicleCargo cursorObject) && (cursorObject distance _target<10) && (cursorObject isKindOf 'Boxloader_Pallet_Base')"];
//};
_ply addaction ["Push",{cursorObject setPosATL (getPosATL cursorObject vectorAdd (vectorDir (_this select 0) vectorMultiply 0.5))},[],5,false,false,"","(((_target getVariable ['boxloader_tgt',objNull]) canVehicleCargo cursorObject select 1) || ((_target getVariable ['boxloader_tgt',objNull]) isKindOf 'Boxloader_Bucket' && (cursorObject getVariable ['boxloader_bucketable',false]))) && ((_target getVariable ['boxloader_tgt',objNull]) distance _target)<15"];
_ply setVariable["boxloader_init",true];
true


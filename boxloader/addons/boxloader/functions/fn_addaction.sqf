params [["_ply",objNull,[objNull]]];
if (isNull _ply) exitWith {false};
_ply setVariable ["boxloader_tgt",objNull];
_ply addAction ["<t color='#FF0000'>Stop loading target</t>",{(_this select 0) setVariable ["boxloader_tgt",objNull,true];},[],0,false,true,"","(vehicle _this == _target) && !isNull (_target getVariable ['boxloader_tgt',objNull])"];
_ply addAction ["Select loading target",{_veh = cursorObject; if ((vehicleCargoEnabled _veh) && ((_veh distance (_this select 0))<15)) then {(_this select 0) setVariable["boxloader_tgt",_veh,true];};},[],0,false,true,"","(vehicle _this == _target) && (isNull (_target getVariable 'boxloader_tgt')) &&  (vehicleCargoEnabled cursorObject && isClass (configFile >> 'CfgVehicles' >> (typeOf cursorObject) >> 'vehicleTransport' >> 'Carrier')) && ((cursorObject distance _target)<15) && !(cursorObject getVariable ['boxloader_dontload',false])"];
//((cursorObject getVariable ['boxloader_flatrack_carrier',false]) || (vehicleCargoEnabled cursorObject && isClass (configFile >> 'CfgVehicles' >> (typeOf cursorObject) >> 'vehicleTransport' >> 'Carrier')))
_ply addAction ["Load this in target",{_veh = (_this select 0 getVariable ["boxloader_tgt",objNull]); _box = cursorObject; if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load};},[],5,false,true,"","(vehicle _this == _target) && !(isNull (_target getVariable ['boxloader_tgt',objNull])) && (((_target getVariable ['boxloader_tgt',objNull]) canVehicleCargo cursorObject) select 0) && (cursorObject distance _target)<5 && ((_target getVariable ['boxloader_tgt',objNull]) distance _target)<15 && !(cursorObject isKindOf 'Boxloader_Pallet_Base') && (!boxloader_maxload_enabled || [_target,cursorObject] call boxloader_fnc_getmaxlift)"];

/*_ply addAction ["Load this onto target",{
	_veh = ((_this select 0) getVariable ["boxloader_tgt",objNull]);
	_box = cursorObject;
	if ((isNull (_veh getVariable ["boxloader_flatrack",objNull])) && (_veh getVariable ["boxloader_flatrack_carrier",false]) && (_box getVariable ["Boxloader_flatrack_cargo",false])) then {
		[_veh,_box] call boxloader_fnc_pls;
	};
},[],5,false,true,"","(vehicle _this == _target) && !(isNull (_target getVariable ['boxloader_tgt',objNull])) && ((_target getVariable ['boxloader_tgt',objNull]) getVariable ['boxloader_flatrack_carrier',false]) && (cursorObject getVariable ['boxloader_flatrack_cargo',false]) && ((_target getVariable ['boxloader_tgt',objNull]) distance _target)<15 && (cursorObject distance _target)<5"]; //needs work
*/


_ply addAction ["Unload object",{_box = cursorObject; if ((!isNull isVehicleCargo _box) && (_box distance (_this select 0)<10)) then {objNull setVehicleCargo _box};},[],0,false,true,""," (vehicle _this == _target) && (!isNull isVehicleCargo cursorObject) && (cursorObject distance _target<10) && (!boxloader_maxload_enabled || [_target,cursorObject] call boxloader_fnc_getmaxlift)"];

_ply addAction ["Hide cargo",{[vehicle (_this select 0),true] call boxloader_fnc_hide;},[],0,false,true,"","(boxloader_hidecargo_enabled) && !((vehicle _target) getVariable ['boxloader_cargohidden',false]) && (isClass (configFile >> 'CfgVehicles' >> (typeOf vehicle _target) >> 'vehicleTransport' >> 'Carrier') || ((vehicle _target) getVariable ['boxloader_rackinit',false]))"];
_ply addAction ["Show cargo",{[vehicle (_this select 0),false] call boxloader_fnc_hide;},[],0,false,true,"","((vehicle _target) getVariable ['boxloader_cargohidden',false])"];

//*_ply addAction ["Unload flatrack",{_box = cursorObject; if (!(isNull attachedTo _box) && ((attachedTo _box) getVariable ['boxloader_flatrack',objNull])==_box && (_box distance (_this select 0)<10)) then {[attachedTo _box,objNull] call boxloader_fnc_pls;};},[],0,false,true,"","(vehicle _this == _target) && (cursorObject isKindOf 'Boxloader_Flatrack_Base') && !(isNull attachedTo cursorObject) && ((attachedTo cursorObject) getVariable ['boxloader_flatrack',objNull])==cursorObject"];*/
_ply addaction ["Push",{cursorObject setPosATL (getPosATL cursorObject vectorAdd (vectorDir (_this select 0) vectorMultiply 0.5))},[],5,false,false,"","!boxloader_maxload_enabled && (((_target getVariable ['boxloader_tgt',objNull]) canVehicleCargo cursorObject select 1) || ((_target getVariable ['boxloader_tgt',objNull]) isKindOf 'Boxloader_Bucket' && (cursorObject getVariable ['boxloader_bucketable',false]))) && ((_target getVariable ['boxloader_tgt',objNull]) distance _target)<15 && !(_target getVariable ['boxloader_dontpush',false])"];


//Advanced load actions
_ply addAction ["Push object",{
	_ply = _this select 0;
	_box = cursorObject;
	_pos = (getPosATL _box vectorAdd (vectorDir _ply vectorMultiply 0.5));
	_pos = [_pos select 0, _pos select 1, (_pos select 2)+0.5];
	_box setVehiclePosition [_pos,[],0,"CAN_COLLIDE"];
},[],1,false,false,"","boxloader_maxload_enabled && weaponLowered _target && (getMass cursorObject)<selectMax [_target getVariable ['boxloader_tgt',objNull] getVariable ['boxloader_maxload_push',0], (vehicle _target getVariable ['boxloader_maxload_push',0]),boxloader_maxload_push]"];





_ply setVariable["boxloader_init",true];

true


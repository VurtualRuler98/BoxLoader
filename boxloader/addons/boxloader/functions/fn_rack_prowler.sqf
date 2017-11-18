params [["_veh",objNull,[objNull]]];
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
if (!(_veh isKindOf "LSV_01_unarmed_base_F") && !(_veh isKindOf "LSV_01_light_base_F")) exitWith {["That's not an acceptable vehicle class!"] call bis_fnc_error; false};
if (_veh getVariable ["boxloader_rackinit",false]) exitWith {false};
_veh setVariable ["boxloader_dontload",true,true];
_veh setVariable ["boxloader_rackinit",true,true];


_veh addAction ["Use rear cargo net",{[(_this select 0),(_this select 1),true,false] remoteExecCall ["boxloader_fnc_rack_prowler_switch",(_this select 0)]},[],0,false,true,"","(vehicle _this == _this) && (({!(isNull (_x select 0)) && (_x select 2) in [4,5]} count fullCrew [_target, 'turret',true])==0) && ((_target getVariable ['boxloader_rack1',objNull]) getVariable ['boxloader_dontload',false])"];

_veh addAction ["Use rear passenger seats",{[(_this select 0),(_this select 1),false,false] remoteExecCall ["boxloader_fnc_rack_prowler_switch",(_this select 0)]},[],0,false,true,"","(vehicle _this == _this) && !((_target getVariable ['boxloader_rack1',objNull]) getVariable ['boxloader_dontload',true]) && ((count getVehicleCargo (_target getVariable ['boxloader_rack1',objNull]))==0)"];


_veh addAction ["Attach roof cargo net",{[(_this select 0),(_this select 1),true,true] remoteExecCall ["boxloader_fnc_rack_prowler_switch",(_this select 0)]},[],0,false,true,"","(vehicle _this == _this) && ((_target getVariable ['boxloader_rack2',objNull]) getVariable ['boxloader_dontload',false]) && vehicleCargoEnabled _target && isNull isVehicleCargo _target"];

_veh addAction ["Detach roof cargo net",{[(_this select 0),(_this select 1),false,true] remoteExecCall ["boxloader_fnc_rack_prowler_switch",(_this select 0)]},[],0,false,true,"","(vehicle _this == _this) && !((_target getVariable ['boxloader_rack2',objNull]) getVariable ['boxloader_dontload',true]) "];


_veh addAction ["Select middle cargo space",{(_this select 1) setVariable ["boxloader_tgt",((_this select 0) getVariable ["boxloader_rack0",objNull]),true]},[],0,false,true,"","(vehicle _this == _this) && (isNull (_this getVariable ['boxloader_tgt',objNull]))"];
_veh addAction ["Select rear cargo net",{(_this select 1) setVariable ["boxloader_tgt",((_this select 0) getVariable ["boxloader_rack1",objNull]),true]},[],0,false,true,"","(vehicle _this == _this) && (isNull (_this getVariable ['boxloader_tgt',objNull])) && !((_target getVariable ['boxloader_rack1',objNull]) getVariable ['boxloader_dontload',true])"];
_veh addAction ["Select roof cargo net",{(_this select 1) setVariable ["boxloader_tgt",((_this select 0) getVariable ["boxloader_rack2",objNull]),true]},[],0,false,true,"","(vehicle _this == _this) && (isNull (_this getVariable ['boxloader_tgt',objNull])) && !((_target getVariable ['boxloader_rack2',objNull]) getVariable ['boxloader_dontload',true])"];
if (!isServer) exitWith {true};
_rack0 = "Land_Boxloader_mem_prowler" createVehicle position _veh;
_rack1 = "Land_Boxloader_prowler_net" createVehicle position _veh;
_rack2 = "Land_Boxloader_prowler_roofnet" createVehicle position _veh;
_rack0 attachTo [_veh,[0,-0.35,-1.2]];
_rack1 attachTo [_veh,[0,-1.4,-0.8]];
_rack2 attachTo [_veh,[0,-0.1,-0.1]];
_rack1 hideObjectGlobal true;
_rack2 hideObjectGlobal true;
_veh addEventHandler ["Deleted",{deleteVehicle ((_this select 0) getVariable["boxloader_rack0",objNull]);deleteVehicle ((_this select 0) getVariable["boxloader_rack1",objNull]);deleteVehicle ((_this select 0) getVariable["boxloader_rack2",objNull]);}];
_veh setVariable ["boxloader_rack0",_rack0,true];
_veh setVariable ["boxloader_rack1",_rack1,true];
_veh setVariable ["boxloader_rack2",_rack2,true];
_rack1 setVariable ["boxloader_dontload",true,true];
_rack2 setVariable ["boxloader_dontload",true,true];
true


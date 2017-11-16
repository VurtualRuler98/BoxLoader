params [["_veh",objNull,[objNull]]];
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
if (!(_veh isKindOf "Quadbike_01_base_F")) exitWIth {["That's not a quadbike!"] call bis_fnc_error; false};
if (_veh getVariable ["boxloader_rackinit",false]) exitWith {false};
_veh setVariable ["boxloader_dontload",true,true];
_veh setVariable ["boxloader_rackinit",true,true];
_veh addAction ["Use rear cargo rack",{[(_this select 0),(_this select 1),true] remoteExecCall ["boxloader_fnc_quadrack_switch",(_this select 0)]},[],0,false,true,"","(vehicle _this == _this) && (isNull (fullCrew [_target,'cargo',true] select 0 select 0)) && ((_target getVariable ['boxloader_rack1',objNull]) getVariable ['boxloader_dontload',false])"];
_veh addAction ["Use rear passenger seat",{[(_this select 0),(_this select 1),false] remoteExecCall ["boxloader_fnc_quadrack_switch",(_this select 0)]},[],0,false,true,"","(vehicle _this == _this) && (isNull (fullCrew [_target,'cargo',true] select 0 select 0)) && !((_target getVariable ['boxloader_rack1',objNull]) getVariable ['boxloader_dontload',true]) && ((count getVehicleCargo (_target getVariable ['boxloader_rack1',objNull]))==0)"];
_veh addAction ["Select front rack",{(_this select 1) setVariable ["boxloader_tgt",((_this select 0) getVariable ["boxloader_rack0",objNull]),true]},[],0,false,true,"","(vehicle _this == _this) && (isNull (_this getVariable ['boxloader_tgt',objNull]))"];
_veh addAction ["Select rear rack",{(_this select 1) setVariable ["boxloader_tgt",((_this select 0) getVariable ["boxloader_rack1",objNull]),true]},[],0,false,true,"","(vehicle _this == _this) && (isNull (_this getVariable ['boxloader_tgt',objNull])) && !((_target getVariable ['boxloader_rack1',objNull]) getVariable ['boxloader_dontload',true])"];
if (!isServer) exitWith {true};
_rack0 = "Land_Boxloader_mem_90x40x100_100kg" createVehicle position _veh;
_rack1 = "Land_Boxloader_mem_90x40x100_100kg" createVehicle position _veh;
_rack0 attachTo [_veh,[0,0.75,-0.5]];
_rack1 attachTo [_veh,[0,-0.85,-0.4]];
_rack0 setDir 90;
_rack1 setDir 90;
_veh addEventHandler ["Deleted",{deleteVehicle ((_this select 0) getVariable["boxloader_rack0",objNull]);deleteVehicle ((_this select 0) getVariable["boxloader_rack1",objNull])}];
_veh setVariable ["boxloader_rack0",_rack0,true];
_veh setVariable ["boxloader_rack1",_rack1,true];
_rack1 setVariable ["boxloader_dontload",true,true];
true


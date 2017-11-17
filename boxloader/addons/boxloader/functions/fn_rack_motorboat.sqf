params [["_veh",objNull,[objNull]]];
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
if (!(_veh isKindOf "Boat_Civil_01_base_F")) exitWith {["That's not the right vehicle for the cargo mode!"] call bis_fnc_error; false};
if (_veh getVariable ["boxloader_rackinit",false]) exitWith {false};
_veh setVariable ["boxloader_rackinit",true,true];
_veh addAction ["Select cargo bed",{(_this select 1) setVariable ["boxloader_tgt",((_this select 0) getVariable ["boxloader_rack0",objNull]),true]},[],0,false,true,"","(vehicle _this == _this) && (isNull (_this getVariable ['boxloader_tgt',objNull]))"];
_veh addAction ["Unload cargo bed",{((_this select 0) getVariable ['boxloader_rack0',objNull]) setVehicleCargo objNull;},[],0,false,true,"","(driver _target == _this) && ((count getVehicleCargo (_target getVariable ['boxloader_rack0',objNull]))>0)"];
if (!isServer) exitWith {true};
_rack0 = "Land_Boxloader_mem_zodiac" createVehicle position _veh;
_rack0 attachTo [_veh,[0,-0.9,-1]];
_veh addEventHandler ["Deleted",{deleteVehicle ((_this select 0) getVariable["boxloader_rack0",objNull]);}];
_veh setVariable ["boxloader_rack0",_rack0,true];
true


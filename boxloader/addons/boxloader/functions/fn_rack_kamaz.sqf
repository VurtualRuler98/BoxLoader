params [["_veh",objNull,[objNull]]];
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
if (!(_veh isKindOf "Truck_02_transport_Base_F") && !(typeOf _veh in ["O_Truck_02_covered_F","I_Truck_02_covered_F","C_Truck_02_covered_F","C_IDAP_Truck_02_F"])) exitWith {["That's not an acceptable kamaz!"] call bis_fnc_error; false};
if (_veh getVariable ["boxloader_rackinit",false]) exitWith {false};
_veh setVariable ["boxloader_rackinit",true,true];
_veh setVariable ["boxloader_dontload",true,true];
_veh addAction ["Use rear cargo bed",{[(_this select 0),(_this select 1),true] remoteExecCall ["boxloader_fnc_rack_kamaz_switch",(_this select 0)]},[],0,false,true,"","(vehicle _this == _this) && (({!(isNull (_x select 0))} count fullCrew [_target, 'turret',true])==0) && (({!(isNull (_x select 0)) && (_x select 2)>1} count fullCrew [_target, 'cargo',true])==0) && ((_target getVariable ['boxloader_rack0',objNull]) getVariable ['boxloader_dontload',false])"];
_veh addAction ["Use rear cargo seats",{[(_this select 0),(_this select 1),false] remoteExecCall ["boxloader_fnc_rack_kamaz_switch",(_this select 0)]},[],0,false,true,"","(vehicle _this == _this) && !((_target getVariable ['boxloader_rack0',objNull]) getVariable ['boxloader_dontload',true]) && ((count getVehicleCargo (_target getVariable ['boxloader_rack0',objNull]))==0)"];
_veh addAction ["Select cargo bed",{(_this select 1) setVariable ["boxloader_tgt",((_this select 0) getVariable ["boxloader_rack0",objNull]),true]},[],0,false,true,"","(vehicle _this == _this) && (isNull (_this getVariable ['boxloader_tgt',objNull])) && !((_target getVariable ['boxloader_rack0',objNull]) getVariable ['boxloader_dontload',true])"];
_veh addAction ["Unload cargo bed",{((_this select 0) getVariable ['boxloader_rack0',objNull]) setVehicleCargo objNull;},[],0,false,true,"","(driver _target == _this) && ((count getVehicleCargo (_target getVariable ['boxloader_rack0',objNull]))>0)"];
if (!isServer) exitWith {true};
_rack0 = "Land_Boxloader_mem_470x240x160_6000kg" createVehicle position _veh;
_rack0 attachTo [_veh,[0,-1.3,-0.76]];
_veh addEventHandler ["Deleted",{deleteVehicle ((_this select 0) getVariable["boxloader_rack0",objNull]);}];
_veh setVariable ["boxloader_rack0",_rack0,true];
_rack0 setVariable ["boxloader_dontload",true,true];
true


params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Hesco_Flat")) exitWith {false};
_box addAction ["Build HESCO (1)",{_con = "Land_HBarrier_1_F" createVehicle (position (_this select 0)); _con setPosASL getPosASL (_this select 0); [_con] call boxloader_fnc_hesco_built; deleteVehicle (_this select 0)},[],0,false,true,"","(isNull attachedTo _target) && (count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)"];
_box addAction ["Build HESCO (3)",{_con = "Land_HBarrier_3_F" createVehicle (position (_this select 0)); _con setPosASL getPosASL (_this select 0); [_con] call boxloader_fnc_hesco_built; deleteVehicle (_this select 0)},[],0,false,true,"","(isNull attachedTo _target) && (count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)"];
_box addAction ["Build HESCO (5)",{_con = "Land_HBarrier_5_F" createVehicle (position (_this select 0)); _con setPosASL getPosASL (_this select 0); [_con] call boxloader_fnc_hesco_built; deleteVehicle (_this select 0)},[],0,false,true,"","(isNull attachedTo _target) && (count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)"];
true 
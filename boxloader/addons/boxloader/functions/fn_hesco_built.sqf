params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box)) exitWith {false};
_box addAction ["Disassemble HESCO",{_con = "Land_Boxloader_Hesco_Flat" createVehicle (position (_this select 0));_con setPosASL getPosASL (_this select 0);deleteVehicle (_this select 0)},[],0,false,true,"","(count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)"];
true 
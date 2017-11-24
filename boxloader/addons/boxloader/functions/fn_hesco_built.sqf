params [["_box",objNull,[objNull]],["_pos",[],[[]],[2,3]],["_dir",0,[0]]];
if (is3DEN) exitWith {false};
if ((isNull _box)) exitWith {false};
_box addAction ["Disassemble HESCO",{
	_con = "Land_Boxloader_Hesco_Flat" createVehicle (position (_this select 0));
	_con setPosASL getPosASL (_this select 0);
	_con setDir (getDir (_this select 0))-(_this select 3 select 1);
	deleteVehicle (_this select 0);
},[_pos,_dir],0,false,true,"","(count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)"];
true 
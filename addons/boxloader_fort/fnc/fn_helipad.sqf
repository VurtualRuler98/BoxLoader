params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box)) exitWith {false};
_con = "Land_HelipadEmpty_F" createVehicle (position _box);
_con setVariable ["grad_persistence_isExcluded",true,true];
_con attachTo [_box,(_box selectionPosition "helipad_pos")];
[_box,_con] spawn {
	params ["_box","_con"];
	waitUntil {sleep 1;(!alive _box)};
	deleteVehicle _con;
};
true 

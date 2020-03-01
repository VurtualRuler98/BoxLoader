_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(boxloader_tractor_bulldoze) || !(_veh isKindOf "boxloader_tractor_base")) exitWith {false};
_arr = [];
_pos = _veh modelToWorld (_veh selectionPosition "VTV_Exit_1");
_types = ["BUSH","TREE","SMALL TREE"];
if (boxloader_tractor_bulldoze_hide) then {_types pushBack "HIDE"};
if (boxloader_tractor_bulldoze_fence) then {_types pushBack "FENCE"};
if (boxloader_tractor_bulldoze_wall) then {_types pushBack "WALL"};
if (boxloader_tractor_bulldoze_wall) then {_types pushBack "ROCK"};
if (boxloader_tractor_bulldoze_ruins) then {
	//_types pushBack "RUINS"; //doesn't fix the livonian ruined buildings
	_arr = nearestObjects [_pos,["ruins"],5];
	if (count _arr > 0) then {
		{deleteVehicle _x} forEach _arr;
	};
};
_arr = nearestTerrainObjects [_pos,_types,5,false,true];
if (count _arr > 0) then {
	{_x setdamage 1; _x hideObjectGlobal true} forEach _arr;
};
_arr = nearestObjects [_pos,["Land_Boxloader_Fort_Base"],5];
{if (damage _x == 1) then {deleteVehicle _x}} forEach _arr;


true

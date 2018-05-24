_par = params [["_veh",objNull,[objNull]],["_mem","",[""]],["_rackVar","",[""]]]; 
if (isNull _veh || _mem == "" || _rackVar == "") exitWith {false};
_rack = _veh getVariable [_rackVar,[objNull,[0,0,0]]];
_tgt = _rack select 0;
if (isNull _tgt) exitWith {false};
_memPoints = getArray (configFile >> "CfgVehicles" >> (typeOf _tgt) >> "VehicleTransport" >> "Carrier" >> "cargoBayDimensions");  
_bedheight = ((_tgt selectionPosition [(_memPoints select 0),"Memory"]) select 2)+(_rack select 1 select 2); 


_veh addAction ["Load vehicle",{ 
 (_this select 3 select 0) setVehicleCargo (vehicle (_this select 1)); 
},[_tgt],1.5,false,true,"",format ["boxloader_maxload_enabled && (_this != vehicle _this) && (_this == driver vehicle _this) && ((_target modelToWorld [0,0,%2] select 2) - ((getPosATL vehicle _this select 2) min (getPosASL vehicle _this select 2)))<0.2 && ((_target modelToWorld [0,0,%2] select 2) - ((getPosATL vehicle _this select 2) min (getPosASL vehicle _this select 2)))>-1 && ((_target getVariable ['%3',[objNull]] select 0) canVehicleCargo vehicle _this) select 0 && ((vehicle _this distance _target)<15) && ([((_target getVariable ['%3',[objNull]] select 0) modelToWorld ((_target getVariable ['%3',[objNull]] select 0) selectionPosition '%1')),(getDir _target+180),30,position vehicle _this] call bis_fnc_inAngleSector)",_mem,_bedheight,_rackVar]];
_veh addAction ["Load vehicle",{
	(_this select 3 select 0) setVehicleCargo (vehicle (_this select 1));
},[_tgt],1.5,false,true,"",format ["!boxloader_maxload_enabled && (_this != vehicle _this) && (_this == driver vehicle _this) && ((_target getVariable ['%3',[objNull]] select 0) canVehicleCargo vehicle _this) select 0 && ((vehicle _this distance _target)<15) && ([((_target getVariable ['%3',[objNull]] select 0) modelToWorld ((_target getVariable ['%3',[objNull]] select 0) selectionPosition '%1')),(getDir _target+180),30,position vehicle _this] call bis_fnc_inAngleSector)",_mem,0,_rackVar]];


true


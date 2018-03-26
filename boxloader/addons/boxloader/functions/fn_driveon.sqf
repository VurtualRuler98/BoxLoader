_par = params [["_veh",objNull,[objNull]],["_mem","",[""]]]; 
if (!_par || isNull _veh) exitWith {false}; 
_memPoints = getArray (configFile >> "CfgVehicles" >> (typeOf _veh) >> "VehicleTransport" >> "Carrier" >> "cargoBayDimensions");  
_bedheight = ((_veh selectionPosition [(_memPoints select 0),"Memory"]) select 2); 
_veh addAction ["Load vehicle",{ 
 (_this select 0) setVehicleCargo (vehicle (_this select 1)); 
},[],1.5,false,true,"",format ["boxloader_maxload_enabled && (_this != vehicle _this) && (_this == driver vehicle _this) && ((_target modelToWorld [0,0,%1] select 2) - ((getPosATL vehicle _this select 2) min (getPosASL vehicle _this select 2)))<0.2 && ((_target modelToWorld [0,0,%1] select 2) - ((getPosATL vehicle _this select 2) min (getPosASL vehicle _this select 2)))>-1 && (_target canVehicleCargo vehicle _this) select 0 && ((vehicle _this distance _target)<15) && ([(_target modelToWorld (_target selectionPosition 'VTV_exit_1')),(getDir _target+180),30,position vehicle _this] call bis_fnc_inAngleSector)",_bedheight]]; 
true


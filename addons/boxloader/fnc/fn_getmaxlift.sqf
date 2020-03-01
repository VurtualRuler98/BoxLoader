params [["_ply",objNull,[objNull]],["_box",objNull,[objNull]]];
if (isNull _ply || isNull _box) exitWith {false};
_tgt = _ply getVariable ["boxloader_tgt",objNull];
if (isNull _tgt) then {_tgt = _ply};
_crane = _ply getVariable ["boxloader_crane",objNull];
_mass = getMass _box;
if (isNull _tgt || !(isClass (configFile >> 'CfgVehicles' >> (typeOf _tgt) >> 'vehicleTransport' >> 'Carrier'))) exitWith {false};
_memPoints = getArray (configFile >> "CfgVehicles" >> (typeOf _tgt) >> "VehicleTransport" >> "Carrier" >> "cargoBayDimensions"); 
_bedheight = ((_tgt modelToWorld (_tgt selectionPosition [(_memPoints select 0),"Memory"])) select 2);
if (_tgt getVariable ["boxloader_load_ramp",false]) then {
	_bedheight = ((getPosATL _tgt select 2) min (getPosASL _tgt select 2));
};
_height = (_bedheight - ((getPosATL _box select 2) min (getPosASL _box select 2)));
if ((_tgt getVariable ["boxloader_load_weight",0]>_mass) && (_tgt getVariable ["boxloader_load_height",0]>_height)) exitWith {true};
if ((vehicle _ply getVariable ["boxloader_load_weight",0]>_mass) && (vehicle _ply getVariable ["boxloader_load_height",0]>_height)) exitWith {true};
if (!(isNull _crane) && (_crane distance _box)<15 && (_crane distance _tgt)<15 && (((_crane getVariable ["boxloader_load_weight",0]>_mass) && (_crane getVariable ["boxloader_load_height",0]>_height) && (!(_crane getVariable ["boxloader_load_viv",false]) || ((isVehicleCargo _box) == _crane) || (_crane canVehicleCargo _box select 0))) || ((_crane getVariable ["boxloader_crane_push",0]>_mass) && (_height < 0.2)))) exitWith {true};
if (_height < -2) exitWith {false};
if (_height < 2.1 && _mass < boxloader_maxload_overhead) exitWith {true};
if (_height < 1.3 && _mass < boxloader_maxload_lift) exitWith {true};
if (_height < 0.2 && _mass < boxloader_maxload_push) exitWith {true};
false



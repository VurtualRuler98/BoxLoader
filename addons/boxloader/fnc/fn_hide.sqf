params [["_veh",objNull,[objNull]],["_hide",false,[false]]];
if (_hide && !(boxloader_hidecargo_enabled) && !(_veh isKindOf "boxloader_pallet_base")) exitWith {false};
_veh setVariable ["boxloader_cargohidden",_hide];
{[_x,_hide,false] call boxloader_fnc_hide_recursion;} forEach (attachedObjects _veh);
if (_veh isKindOf "boxloader_pallet_base") then {
	[_veh] spawn {
		params ["_pallet"]; 
		_arr = getVehicleCargo _pallet;
		while {alive _pallet} do {
			if !(_arr isEqualTo getVehicleCargo _pallet) then {
				_arr = getVehicleCargo _pallet;
				if (_pallet getVariable ["boxloader_cargohidden",false]) then {
					[_pallet,false] call boxloader_fnc_hide;
					_pallet animateSource ["cargonet",0];
				};
			};
			sleep 3;
		};
	};
};

true 
_par = params [["_veh",objNull,[objNull]],["_build",false,[false]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "boxloader_tractor_base")) exitWith {false};
if (_veh getVariable ["boxloader_tractor_init",false]) exitWith {false};
_veh setVariable ["boxloader_tractor_init",true];
if (is3DEN) exitWith {true};
_veh setVariable ["vurtual_tow_hitch", (_veh selectionPosition "tow_hitch")];
_veh setVariable ['boxloader_load_viv',true];
_veh setVariable ['boxloader_load_weight',1000];
_veh setVariable ['boxloader_load_height',2.9];
_veh setVariable ['boxloader_canload',true];
_veh addAction ["Select self as loading target",{_veh = vehicle (_this select 1); if (vehicleCargoEnabled _veh) then {(_this select 1) setVariable["boxloader_tgt",_veh,true];};},[],0,false,true,"","(vehicle _this == _target) && (isNull (_this getVariable ['boxloader_tgt',objNull])) && (vehicleCargoEnabled _target)"];
_veh addAction ["Load cargo in target",{_veh = (_this select 1 getVariable ["boxloader_tgt",objNull]); {_box = _x; if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load}} forEach getVehicleCargo (_this select 0); [_this select 0] spawn { sleep 0.1; if ((count getVehicleCargo (_this select 0)) > 0) then {hint "Could not load all cargo.";}}},[],5,false,true,"","(vehicle _this == _target) && !(isNull (_this getVariable ['boxloader_tgt',objNull])) && ((count getVehicleCargo _target)>0) && (_this getVariable ['boxloader_tgt',objNull] != _target) && (_this getVariable ['boxloader_tgt',objNull] distance _this)<15"];
if (_build) then {
	{
		_veh setVariable [_x,true];
	} forEach ["boxloader_work_vehicle","boxloader_build_fill","boxloader_build_tools"];
};
[_veh] spawn {
	_veh = (_this select 0);
	while {alive (_veh)} do {
		sleep 0.1;
		if (local _veh) then {
			_fordingKill = (_veh modelToWorld (_veh selectionPosition "exhaust_pos"));
			if (isNull attachedTo _veh) then {
				if ( (((_fordingKill select 2) < 0) && (surfaceIsWater _fordingKill))) then {
					_veh setHitPointDamage ["hitEngine",1];
				};
			}; 
		};

	};
};
true

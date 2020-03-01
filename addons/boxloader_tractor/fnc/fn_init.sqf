_par = params [["_veh",objNull,[objNull]],["_build",false,[false]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "boxloader_tractor_base")) exitWith {false};
if (_veh getVariable ["boxloader_tractor_init",false]) exitWith {false};
_veh setVariable ["boxloader_tractor_init",true];
if (is3DEN) exitWith {true};
_veh setVariable ["vurtual_tow_hitch", (_veh selectionPosition "tow_hitch")];
_veh setVariable ["LESH_canTow",1];
_veh setVariable ["LESH_axisOffsetTower",_veh selectionposition "tow_hitch"];
_veh setVariable ['boxloader_load_viv',true];
_veh setVariable ['boxloader_load_weight',1000];
_veh setVariable ["boxloader_crane_push",1000];
_veh setVariable ['boxloader_load_height',2.9];
_veh setVariable ['boxloader_canload',true];
_veh addAction ["Load cargo into self",{_veh = vehicle (_this select 1); _box = cursorObject; if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load};},[],0,false,true,"","(vehicle _this == _target) && {((_target canVehicleCargo cursorObject) select 0)} && {(cursorObject distance _target)<15 && (!boxloader_maxload_enabled || [_target,cursorObject] call boxloader_fnc_getmaxlift)}"];
_veh addAction ["Load cargo into target",{_veh = (_this select 1 getVariable ["boxloader_tgt",objNull]); {_box = _x; if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {[_veh,_box] call boxloader_fnc_load}} forEach getVehicleCargo (_this select 0); [_this select 0] spawn { sleep 0.1; if ((count getVehicleCargo (_this select 0)) > 0) then {hint "Could not load all cargo.";}}},[],5,false,true,"","(vehicle _this == _target) && !(isNull (_this getVariable ['boxloader_tgt',objNull])) && ((count getVehicleCargo _target)>0) && (_this getVariable ['boxloader_tgt',objNull] != _target) && (_this getVariable ['boxloader_tgt',objNull] distance _this)<15"];

if (_build) then {
	{
		_veh setVariable [_x,true];
	} forEach ["boxloader_work_vehicle","boxloader_build_fill","boxloader_build_tools"];
	_veh addAction ["Select self as construction vehicle",{(_this select 1) setVariable["boxloader_work_tgt",(_this select 0),true];},[],0,false,true,"","(vehicle _this == _target) && {(isNull (_this getVariable ['boxloader_work_tgt',objNull]))}"];
	_veh addAction ["<t color='#FF8000'>Bulldoze!</t>",{
		_pos = (_this select 0) modelToWorld ((_this select 0) selectionPosition "VTV_Exit_1");
		_arr = nearestTerrainObjects [_pos,["BUSH","TREE","FENCE","HIDE","ROCK","RUINS","SMALL TREE"],5,false,true];
		_bulldoze = false;
		if (count _arr > 0) then {
			_bulldoze = true;
		};
		_arr = nearestObjects [_pos,["ruins"],15,false];
		if (count _arr > 0) then {
			_bulldoze = true;
		};
		_arr = nearestObjects [_pos,["Land_Boxloader_Fort_Base"],15,false];
		if ({damage _x == 1} count _arr > 0) then {
			_bulldoze = true;
		};
		if (_bulldoze) then {
				[(_this select 0)] remoteExec ["boxloader_fnc_bulldoze",2];
		};
	},[],0,false,true,"","(vehicle _this == _target) && {boxloader_tractor_bulldoze && isNull attachedTo _target}"];
	
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

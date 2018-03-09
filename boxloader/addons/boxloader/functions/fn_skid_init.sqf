_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "boxloader_skidbase")) exitWith {false};
if (_veh getVariable ["boxloader_crane_push",0]>0) exitWith {false};
if (_veh isKindOf "boxloader_skid_fork") then {

	_veh setVariable ["boxloader_load_weight",6500];
	_veh setVariable ["boxloader_load_height",2.5];
	_veh setVariable ["boxloader_canload",true];
} else {
	_veh setVariable ["boxloader_build_fill",true];
	_veh setVariable ["boxloader_build_tools",true];
};
_veh setVariable ["boxloader_crane_push",6500];

true

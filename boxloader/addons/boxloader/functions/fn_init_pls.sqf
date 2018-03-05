params [["_veh",objNull,[objNull]]];
if (isNull _veh) exitWith {false};
_veh setVariable ['boxloader_flatrack_carrier',true];
_veh addAction ["Load flatrack",{
	_pos = (_this select 0 modelToWorld (_this select 0 selectionPosition ["boxloader_flatrack_exit","Memory"]));
	_box = nearestObject [_pos,"boxloader_flatrack_base"];
	if (_pos distance (getPos _box)<3) then {
		[_this select 0,_box] call boxloader_fnc_pls;
	};
},[],1.5,false,true,"","(driver _target == _this) && (isNull (_target getVariable ['boxloader_flatrack',objNull])) && (count ((_target modelToWorld (_target selectionPosition ['boxloader_flatrack_exit','Memory'])) nearObjects ['boxloader_flatrack_base',3]))>0"];
_veh addAction ["Unload flatrack",{[_this select 0,objNull] call boxloader_fnc_pls;},[],1.5,false,true,"","(driver _target == _this) && !(isNull (_target getVariable ['boxloader_flatrack',objNull]))"];
true

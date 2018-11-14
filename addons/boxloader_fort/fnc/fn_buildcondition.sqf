params [["_tools",false,[false]],["_fill",false,[false]],["_menu",true,[true]]];
_condition = "(isNull attachedTo _target)";
if (_menu) then {
	_condition = _condition + " && (_this getVariable ['BuildMenu',false])";
};
if (_tools || _fill) then {
	_condition = _condition + " && ((_this getVariable ['boxloader_work_tgt',objNull]) distance _this)<15";
};
if (_tools) then {
	_condition = _condition + " && ((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_tools',false])";
};
if (_fill) then {
	_condition = _condition + " && ((_this getVariable ['boxloader_work_tgt',objNull]) getVariable ['boxloader_build_fill',false])";
};
_condition

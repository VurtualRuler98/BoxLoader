if !(boxloader_fort_snap_editor) exitWith {true};
if (is3DEN) then {
	if (count get3DENSelected "object" > 1) exitWith {true};
	_this call boxloader_fort_fnc_snap;
} else {
	if (count (curatorSelected select 0) > 1) exitWith {true};
	_this call boxloader_fort_fnc_snap;
};
true


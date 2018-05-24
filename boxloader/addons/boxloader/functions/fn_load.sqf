params [["_veh",objNull,[objNull]],["_box",objNull,[objNull]]];
if (isNull _veh || isNull _box) exitWith {false};
if (_veh getVariable ["boxloader_dontload",false]) exitWith {false};
if (((_veh canVehicleCargo _box) select 0) && ((_box distance _veh)<15)) then {
	_veh setVehicleCargo _box;
	if (ropeAttachEnabled _box) then {
		_box enableRopeAttach false;
		[_box] spawn {
			waitUntil {sleep 1; isNull attachedTo (_this select 0)};
			(_this select 0) enableRopeAttach true;
		};
	};
	[_box] remoteExec ["boxloader_fnc_alive",2];
	true
} else {false}



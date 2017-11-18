params [["_veh",objNull,[objNull]],["_player",objNull,[objNull]],["_cargo",false,[true]],["_roof",false,[true]]];
if (isNull _veh || isNull _player) exitWith {["Vehicle or player passed was null!"] call bis_fnc_error; false};
if (!(_veh isKindOf "LSV_01_unarmed_base_F") && !(_veh isKindOf "LSV_01_light_base_F")) exitWith {["That's not an acceptable vehicle class!"] call bis_fnc_error; false};
if ((_player distance _veh)>20) exitWith {false};
if (_roof) then {
	if (!_cargo && ((count getVehicleCargo (_veh getVariable ["boxloader_rack2",objNull]))>0)) exitWith {false};
	if (!isNull isVehicleCargo _veh) exitWith {false};
	(_veh getVariable ['boxloader_rack2',objNull]) setVariable ["boxloader_dontload",!_cargo,true];
	(_veh getVariable ['boxloader_rack2',objNull]) hideObject !_cargo;
	_veh enableVehicleCargo !_cargo;
	true
} else {
	if (_cargo && (({!(isNull (_x select 0)) && ((_x select 2) in [4,5])} count fullCrew [_veh, 'turret',true])>0)) exitWith {false};
	if (!_cargo && ((count getVehicleCargo (_veh getVariable ["boxloader_rack1",objNull]))>0)) exitWith {false};
	(_veh getVariable ['boxloader_rack1',objNull]) setVariable ["boxloader_dontload",!_cargo,true];
	{_veh lockCargo [_x,_cargo];} forEach [4,5];
	(_veh getVariable ['boxloader_rack1',objNull]) hideObject !_cargo;
	true
}



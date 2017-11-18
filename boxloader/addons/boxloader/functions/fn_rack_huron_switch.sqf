params [["_veh",objNull,[objNull]],["_player",objNull,[objNull]],["_cargo",false,[true]]];
if (isNull _veh || isNull _player) exitWith {["Vehicle or player passed was null!"] call bis_fnc_error; false};
if (!(_veh isKindOf "Heli_Transport_03_base_F")) exitWith {["That's not an acceptable vehicle class!"] call bis_fnc_error; false};
if ((_player distance _veh)>20) exitWith {false};
if (_cargo && (({!(isNull (_x select 0)) && (_x select 2)>0} count fullCrew [_veh, 'cargo',true])>0)) exitWith {false};
if (!_cargo && ((count getVehicleCargo (_veh getVariable ["boxloader_rack0",objNull]))>0)) exitWith {false};
(_veh getVariable ['boxloader_rack0',objNull]) setVariable ["boxloader_dontload",!_cargo,true];
for "_x" from 0 to 13 do {_veh lockCargo [_x,_cargo];};
true


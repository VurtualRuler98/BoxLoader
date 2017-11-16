params [["_veh",objNull,[objNull]],["_player",objNull,[objNull]],["_cargo",false,[true]]];
if (isNull _veh || isNull _player) exitWith {["Vehicle or player passed was null!"] call bis_fnc_error; false};
if (!(_veh isKindOf "Quadbike_01_base_F")) exitWIth {["That's not a quadbike!"] call bis_fnc_error; false};
if ((_player distance _veh)>20) exitWith {false};
if (_cargo && !isNull (fullCrew [_veh,'cargo',true] select 0 select 0)) exitWith {false};
if (!_cargo && ((count getVehicleCargo (_veh getVariable ["boxloader_rack1",objNull]))>0)) exitWith {false};
(_veh getVariable ['boxloader_rack1',objNull]) setVariable ["boxloader_dontload",!_cargo,true];
_veh lockCargo [0,_cargo];
true


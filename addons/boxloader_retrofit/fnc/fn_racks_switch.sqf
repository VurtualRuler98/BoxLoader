//0: _veh		Vehicle object with rack
//1: _rack	Name of variable on vehicle object that refers to rack data  
//2: _cargo		True to enable cargo, false to disable it

params [["_veh",objNull,[objNull]],["_rackVar","",[""]],["_cargo",false,[true]]];
if (isNull _veh) exitWith {["Vehicle passed was null!"] call bis_fnc_error; false};
_rack = (_veh getVariable [_rackVar,[]]);
if (!((_rack call boxloader_retrofit_fnc_validate) select 0)) exitWith {["Variable passed is not rack data!"] call bis_fnc_error; false}; //You sent something that wasn't rack data


if (!(_rack select 5)) exitWith {false}; //Why are you toggling a rack that doesn't toggle?
if (!_cargo && (count getVehicleCargo (_rack select 0)>0)) exitWith {false};
if ((_rack select 6 select 5) && !(isNull isVehicleCargo _veh)) exitWith {false};

if (_cargo && ({!(isNull (_x select 0)) && ((_x select 2) in (_rack select 6 select 3))} count fullCrew [_veh, 'cargo',true])>0) exitWith {false};
if (_cargo && ({!(isNull (_x select 0)) && ((_x select 2) in (_rack select 6 select 4))} count fullCrew [_veh, 'turret',true])>0) exitWith {false};

(_rack select 0) setVariable ["boxloader_dontload",!_cargo,true];
{_veh lockCargo [_x,_cargo];} forEach (_rack select 6 select 3)+(_rack select 6 select 4);
if (_rack select 6 select 2) then {
	(_rack select 0) hideObject !_cargo;
};
if (_rack select 6 select 5) then {
	_veh enableVehicleCargo !_cargo;
};
true




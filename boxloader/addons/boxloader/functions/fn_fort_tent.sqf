//0, _box: object we are adding HESCO actions to
params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Fort_Tent_Flat_Base")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box setVariable ["boxloader_dontpush",true];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target)"];
_box addAction ["Rotate Packed Tent",{
	_ply = _this select 1;
	_box = _this select 0;
	_dir = (getDir _ply - getDir _box);
	_box setDir floor(getDir _ply);
	[_box] remoteExec ["boxloader_fnc_alive",2];
},[],0,false,true,"","(vehicle _this == _this)",5];
_box addaction ["Push",{
	_ply = _this select 1;
	_box = _this select 0;
	_pos = (getPosATL _box vectorAdd (vectorDir _ply vectorMultiply 0.5));
	_pos = [_pos select 0, _pos select 1, (_pos select 2)+0.5];
	_box setVehiclePosition [_pos,[],0,"CAN_COLLIDE"];
	[_box] remoteExec ["boxloader_fnc_alive",2];
},[],5,false,false,"","(vehicle _this == _this)"];
[
	_box,
	"Assemble Tent",
	"",
	"",
	"(_target getVariable ['BuildMenu',false])",
	"(_target getVariable ['BuildMenu',false])",
	{},
	{},
	{
		
		_conType = getText (configFile >> "CfgVehicles" >> (typeOf (_this select 0)) >> "BuildClass");
		_pos = getPosASL (_this select 0);
		_pos = [_pos select 0, _pos select 1, (_pos select 2)+0.5];
		deleteVehicle (_this select 0);
		_con = _conType createVehicle [0,0,0];
		_con setDir (getDir (_this select 0));
		_con setVehiclePosition [_pos,[],0,"CAN_COLLIDE"];
		//[_con] remoteExec ["boxloader_fnc_alive",2];
		
	},
	{},
	[],
	5,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd;
true 
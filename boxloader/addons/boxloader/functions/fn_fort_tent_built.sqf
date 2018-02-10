params [["_box",objNull,[objNull]],["_base","",[""]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Fort_Tent_Built")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box setVariable ["TentStaked",false];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target)"];
/*
[
	_box,
	"Disassemble Tent Rainfly",
	"",
	"",
	"(_target getVariable ['BuildMenu',false]) && (_target animationSourcePhase 'OuterTent_Hide')==0",
	"(_target getVariable ['BuildMenu',false]) && (_target animationSourcePhase 'OuterTent_Hide')==0",
	{},
	{},
	{(_this select 0) animateSource ["OuterTent_Hide",1];},
	{},
	[],
	10,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd; 
[
	_box,
	"Assemble Tent Rainfly",
	"",
	"",
	"(_target getVariable ['BuildMenu',false]) && (_target animationSourcePhase 'OuterTent_Hide')==1 && (_target getVariable ['TentStaked',false])",
	"(_target getVariable ['BuildMenu',false]) && (_target animationSourcePhase 'OuterTent_Hide')==1 && (_target getVariable ['TentStaked',false])",
	{},
	{},
	{(_this select 0) animateSource ["OuterTent_Hide",0];},
	{},
	[],
	10,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd;
*/
[
	_box,
	"Disassemble Tent",
	"",
	"",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true])",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true])",
	{},
	{},
	{
		
		
		_pos = getPosASL (_this select 0);
		_pos = [_pos select 0, _pos select 1, (_pos select 2)+0.5];
		(_this select 0) setPosASL [_pos select 0, _pos select 1,(_pos select 2)+100];
		deleteVehicle (_this select 0);
		_con = "Land_Boxloader_Fort_Tent_Flat" createVehicle [0,0,0];
		_con setDir (getDir (_this select 0));
		_con setVehiclePosition [_pos,[],0,"CAN_COLLIDE"];
		
	},
	{},
	[],
	10,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd;
[
	_box,
	"Stake Tent",
	"",
	"",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true])",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true])",
	{},
	{},
	{(_this select 0) setVariable ["TentStaked",true,true];},
	{},
	[],
	5,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd; 
[
	_box,
	"Un-stake Tent",
	"",
	"",
	"(_target getVariable ['BuildMenu',false]) && (_target getVariable ['TentStaked',false])",
	"(_target getVariable ['BuildMenu',false]) && (_target getVariable ['TentStaked',false])",
	{},
	{},
	{(_this select 0) setVariable ["TentStaked",false,true];},
	{},
	[],
	5,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd; 

_box addAction ["Rotate Tent",{
	_ply = _this select 1;
	_box = _this select 0;
	_dir = (getDir _ply - getDir _box);
	if (_dir > 345 || _dir < 15) then {
		_box setDir floor(getDir _ply)
	};
},[],0,false,true,"","(vehicle _this == _this) && !(_target getVariable ['TentStaked',true]) && ((getDir _this - getDir _target)>345 || (getDir _this - getDir _target)<15)"];
_box addaction ["Push",{
	_ply = _this select 1;
	_box = _this select 0;
	_pos = (getPosATL _box vectorAdd (vectorDir _ply vectorMultiply 0.5));
	_pos = [_pos select 0, _pos select 1, (_pos select 2)+0.5];
	_box setVehiclePosition [_pos,[],0,"CAN_COLLIDE"];
},[],5,false,false,"","(vehicle _this == _this) && !(_target getVariable ['TentStaked',true])"];
_box addaction ["Open Doors",{
	_this select 0 animateSource ["Door_Hide",1];
},[],5,false,false,"","(vehicle _this == _this) && (_target getVariable ['TentStaked',false]) && (_target animationSourcePhase 'Door_Hide')==0"];
_box addaction ["Close Doors",{
	_this select 0 animateSource ["Door_Hide",0];
},[],5,false,false,"","(vehicle _this == _this) && (_target getVariable ['TentStaked',false]) && (_target animationSourcePhase 'Door_Hide')==1"];
true 

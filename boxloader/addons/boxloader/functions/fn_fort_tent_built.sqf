params [["_box",objNull,[objNull]],["_base","",[""]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Fort_Tent_Built_Base")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box setVariable ["TentStaked",false];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(isNull attachedTo _target)"];

[
	_box,
	"Install/Remove Tent Body",
	"",
	"",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true])",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true])",
	{},
	{},
	{
	_anim = (_this select 0) animationSourcePhase "InnerTent_Hide";
	if (_anim==1) then {
		(_this select 0) animateSource ["InnerTent_Hide",0];
	} else {
		(_this select 0) animateSource ["InnerTent_Hide",1];
	};
	},
	{},
	[],
	2.5,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd;
[
	_box,
	"Install/Remove Tent Rainfly",
	"",
	"",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true])",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true])",
	{},
	{},
	{
	_anim = (_this select 0) animationSourcePhase "OuterTent_Hide";
	if (_anim==1) then {
		(_this select 0) animateSource ["OuterTent_Hide",0];
	} else {
		(_this select 0) animateSource ["OuterTent_Hide",1];
	};
	},
	{},
	[],
	2.5,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd;

[
	_box,
	"Disassemble Tent",
	"",
	"",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true]) && (_target animationSourcePhase 'InnerTent_Hide')==1 && (_target animationSourcePhase 'OuterTent_Hide')==1 && (isNull (_target getVariable ['tent_floor',objNull]))",
	"(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true]) && (_target animationSourcePhase 'InnerTent_Hide')==1 && (_target animationSourcePhase 'OuterTent_Hide')==1 && (isNull (_target getVariable ['tent_floor',objNull]))",
	{},
	{},
	{
		
		_conType = getText (configFile >> "CfgVehicles" >> (typeOf (_this select 0)) >> "BuildClass");
		_pos = getPosASL (_this select 0);
		_pos = [_pos select 0, _pos select 1, (_pos select 2)+0.5];
		(_this select 0) setPosASL [_pos select 0, _pos select 1,(_pos select 2)+100];
		deleteVehicle (_this select 0);
		_con = _conType createVehicle [0,0,0];
		_con setDir (getDir (_this select 0));
		_con setVehiclePosition [_pos,[],0,"CAN_COLLIDE"];
		
	},
	{},
	[],
	5,
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
_box addaction ["Install/Remove Medical Sign",{
	_anim = (_this select 0) animationSourcePhase "MedSign_Hide";
	if (_anim==1) then {
		(_this select 0) animateSource ["MedSign_Hide",0];
	} else {
		(_this select 0) animateSource ["MedSign_Hide",1];
	};
},[],5,false,false,"","(vehicle _this == _this) && (_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true]) && (_target animationSourcePhase 'InnerTent_Hide')==0"];
_box addaction ["Install/Remove Tent Floor",{
	_anim = (_this select 0) getVariable ["tent_floor",objNull];
	if (isNull _anim) then {
		_floor = "Land_MedicalTent_01_floor_dark_F" createVehicle position (_this select 0);
		_floor attachTo [(_this select 0),[0,0,0]];
		(_this select 0) setVariable ["tent_floor",_floor,true];
	} else {
		_floor = (_this select 0) getVariable ["tent_floor",objNull];
		deleteVehicle _floor;
	};
},[],5,false,false,"","(_target getVariable ['BuildMenu',false]) && !(_target getVariable ['TentStaked',true]) && (getPosATL _target select 2)<2"];
true 

params [["_box",objNull,[objNull]]];
if (is3DEN) exitWith {false};
if ((isNull _box) || !(_box isKindOf "Land_Boxloader_Hesco_Flat")) exitWith {false};
_box setVariable ["BuildMenu",false];
_box addAction ["Toggle build menu",{
	(_this select 0) setVariable ["BuildMenu",!(_this select 0 getVariable["BuildMenu",true])];
},[],0.5,false,true,"","(count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)"];
{
	_box addAction [(_x select 0),{
		_con = (_this select 3 select 1) createVehicle (position (_this select 0));
		_pos = (getPosASL (_this select 0)) vectorAdd ([(_this select 3 select 2),-(getDir (_this select 0))] call bis_fnc_rotateVector2D);
		_con setPosASL _pos;
		_con setDir (getDir (_this select 0)+(_this select 3 select 3));
		[_con,(_this select 3 select 2),(_this select 3 select 3)] call boxloader_fnc_hesco_built; 
		deleteVehicle (_this select 0);
	},_x,0,false,true,"","(isNull attachedTo _target) && (_target getVariable ['BuildMenu',false]) && (count ((position _target) nearObjects ['B_APC_Tracked_01_CRV_F',20])>0)"];

} forEach [
	["Build HESCO (1)","Land_Hbarrier_1_F",[0,0.6,0],90],
	["Build HESCO (3)","Land_Hbarrier_3_F",[0,1.7,0],90],
	["Build HESCO (5)","Land_Hbarrier_5_F",[0,2.8,0],90]
];
true 
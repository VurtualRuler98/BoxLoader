params [["_veh",objNull,[objNull]],["_obj","",[""]],["_rot",0,[0]],["_name","pallet",[""]]];
if (is3DEN) exitWith {false};
if (hasInterface) then {
	if (isNull _veh) exitWith {false};
	if (isClass(configFile >> "CfgPatches" >> "boxloader_ace")) exitWith {_pallet = ((_this select 0) getVariable["boxloader_mem",objNull]); if (!isNull _pallet) then {_pallet setVariable ["boxloader_dontselect",true,true];};true};
	_veh addAction [format["Select %1 loading target",_name],{(_this select 1) setVariable["boxloader_tgt",((_this select 0) getVariable["boxloader_mem",objNull]),true];},[],0,false,true,"","(vehicle _this == _this) && (isNull (_this getVariable 'boxloader_tgt'))"];
};
if (!isServer) exitWith {false};
if (isNull _veh) exitWith {["You tried to init a pallet on a thing that doesn't exist!"] call bis_fnc_error; false};
if (!(_obj isKindOf "Boxloader_Pallet_base")) exitWith {["We can't make something into not a pallet."] call bis_fnc_error;false};
_pallet = _obj createVehicle (position _veh);
if (isNull _pallet) exitWith {false};
_pallet attachTo [_veh,[0,0,0]];
_pallet setDir _rot;
_veh setVariable ["boxloader_mem",_pallet,true];
_pallet hideObject true;
true


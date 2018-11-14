params [["_box",objNull,[objNull]],["_tools",false,[false]],["_fill",false,[false]]];
if ((isNull _box)) exitWith {false};
_name = getText (configFile >> "CfgVehicles" >> (typeOf _box) >> "displayName");
_condition = [_tools,_fill,false] call boxloader_fort_fnc_buildcondition;
_box addAction [format["Build: %1",_name],{
	(_this select 1) setVariable ["BuildMenu",!(_this select 1 getVariable["BuildMenu",false])];
},[],0.5,false,true,"",_condition];
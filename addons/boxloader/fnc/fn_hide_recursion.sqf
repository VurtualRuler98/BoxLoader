params [["_obj",objNull,[objNull]],["_hide",false,[false]],["_sub",false,[false]]];
if (_obj getVariable ["boxloader_dontload",false]) exitWith {false};
{[_x,_hide,true] call boxloader_fnc_hide_recursion; } forEach (attachedObjects _obj);
_obj hideObjectGlobal _hide;
if (_hide) then {
	[_obj,_sub] spawn {
		_obj = (_this select 0);
		_sub = (_this select 1);
		waitUntil {sleep 1; ((isNull _obj) || (isNull attachedTo _obj) || !(isObjectHidden _obj) ||(_sub && !(isObjectHidden attachedTo _obj)))};
		if (!(isNull _obj) && (isObjectHidden _obj)) then {
			_obj hideObjectGlobal false;
		};
	};
};
true

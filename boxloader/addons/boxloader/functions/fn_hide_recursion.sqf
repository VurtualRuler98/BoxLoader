params [["_obj",objNull,[objNull]],["_hide",false,[false]]];

{[_x,_hide] call boxloader_fnc_hide_recursion; } forEach (attachedObjects _obj);
_obj hideObjectGlobal _hide;
if (_hide) then {
	[_obj] spawn {
		_obj = (_this select 0);
		waitUntil {sleep 1; ((isNull _obj) || (isNull attachedTo _obj) || !(isObjectHidden _obj) || !(isObjectHidden attachedTo _obj))};
		if (!(isNull _obj) && (isObjectHidden _obj)) then {
			[_obj,false] remoteExec ["hideObjectGlobal",2];
		};
	};
};
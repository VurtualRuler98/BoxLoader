params [["_veh",objNull,[objNull]],["_hide",false,[false]]];
_veh setVariable ["boxloader_cargohidden",_hide];
{if (_x isKindOf "Boxloader_Pallet_Base") then {{[_x,_hide] call boxloader_fnc_hide_recursion; } forEach (attachedObjects _x);[_x,_hide] remoteExec ["hideObjectGlobal",2]}} forEach (attachedObjects _veh);


true 
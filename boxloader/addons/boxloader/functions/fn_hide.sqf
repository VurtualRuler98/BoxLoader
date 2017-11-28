params [["_veh",objNull,[objNull]],["_hide",false,[false]]];
_veh setVariable ["boxloader_cargohidden",_hide];
{[_x,_hide,false] call boxloader_fnc_hide_recursion;} forEach (attachedObjects _veh);


true 
_par = params [["_con",objNull,[objNull]]];
if (!_par || (isNull _con) || !(_con isKindOf "land_boxloader_fort_base")) exitWith {false};
_snap = (configFile >> "CfgVehicles" >> (typeOf _con) >> "boxloader_snap") call BIS_fnc_getCfgDataBool;
if (!_snap) exitWith {false};
_snap_pos = (configFile >> "CfgVehicles" >> (typeOf _con) >> "boxloader_snap_pos") call BIS_fnc_getCfgDataArray;
_snap_class = [];
{_snap_class pushBack (_x select 0)} forEach _snap_pos;
if ((count _snap_class)==0) exitWith {false};
_arr = nearestObjects [_con,_snap_class,10];
_arr deleteAt (_arr find _con);
if (count _arr > 0) then {
	_snapdist = 999999;
	_snap_data = ["",0,0];
	_snapObj = objNull;
	{
		_obj=_x;
		{
		if (_obj isKindOf (_x select 0)) exitWith {
			_conpos = (_con modelToWorldWorld (_con selectionPosition "boxloader_snap_origin"));
				{
					_dist = (_obj modelToWorldWorld (_obj selectionPosition (_x select 0))) distance _conpos;
					if (_dist<_snapdist) then {
						_snapdist = _dist;
						_snap_data = _x;
						_snapObj = _obj;
					};
				} forEach (_x select 1);
			};
		} forEach _snap_pos;
	} forEach _arr;
	_snap_angle = (_snap_data select 1);
	_snap_offset = (_snap_data select 2);
	_pos = (_snapObj modelToWorldWorld (_snapObj selectionPosition (_snap_data select 0)));
	_dir = (((round ((getDir _con - getDir _snapObj-_snap_offset)/_snap_angle))*_snap_angle)+getDir _snapObj+_snap_offset);
	if (is3DEN) then {
		_con set3DENAttribute ["Position",ASLtoATL _pos];
		_con set3DENAttribute ["Rotation",[0,0,_dir]];
	} else {
		_con setPosASL _pos;
		_con setDir _dir;
	};
};
true


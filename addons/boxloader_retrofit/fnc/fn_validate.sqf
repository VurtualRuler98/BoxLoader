//[0 rack object,1 position, 2 rotation, 3 useText, 4 unloadText, 5 toggles,6 [0 enableText,1 disableText,2 hide when disabled,3 cargo seats blocked,4 turret seats blocked,5 blocks vehicle loading],7 [selection,state]], 8 roof box install string, 9 pitch
_rack params [["_obj",objNull,[objNull,""]],["_pos",[0,0,0],[[]]],["_rot",0,[0]],["_useText","",[""]],["_unloadText","",[""]],["_toggles",false,[false]],["_toggleConf",[],[[]]],["_selection",[],[[]]],["_addon","",[""]],["_pitch",0,[0]]];
if (!(_obj isKindOf "Boxloader_Pallet_Base")) exitWith {[false,[]]}; //Not a rack.
if (_toggles) then {
	_toggleConf params [["_tgTextOn","",[""]],["_tgTextOff","",[""]],["_tgHide",false,[false]],["_tgSeatsCargo",[],[[],0]],["_tgSeatsTurret",[],[[],0]],["_tgBlockLoad",false,[false]]];
	{if (typeName 0 != typeName _x) then {_tgSeatsCargo deleteAt _forEachIndex};} forEach _tgSeatsCargo;
	{if (typeName 0 != typeName _x) then {_tgSeatsCargo deleteAt _forEachIndex};} forEach _tgSeatsTurret;
	_toggleConf = [_tgTextOn,_tgTextOff,_tgHide,_tgSeatsCargo,_tgSeatsTurret,_tgBlockLoad];
};
if (count _selection>0) then {
	_selection params [["_sel","",[""]],["_selnum",0,[0]]];
	_selection = [_sel,_selnum];
};
_rack = [_obj,_pos,_rot,_useText,_unloadText,_toggles,_toggleConf,_selection,_addon,_pitch];
[true,_rack]
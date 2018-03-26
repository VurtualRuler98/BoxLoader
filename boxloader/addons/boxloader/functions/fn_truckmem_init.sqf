params [["_pallet",objNull,[objNull]],["_parent",objNull,[objNull]]];
if (isNull _pallet || isNull _parent) exitWith {false};
if (is3DEN) exitWith {true};
[_pallet,_parent] spawn {
	_pallet = _this select 0;
	_mass = getMass _pallet;
	_parent = _this select 1;
	_loop = true;
	while {alive _parent} do {
		sleep 1;
		if (_mass!=getMass _pallet) then { //Our mass changed.
				_diffmass = (getMass _pallet)-_mass; //Positive if we got more mass, negative if we lost some.
				(attachedTo _pallet) setMass ((getMass attachedTo _pallet)+_diffmass); //Adjust parent mass by ours.
				_mass = (getMass _pallet); //Update mass.
		};
	};
};
//};
true
params [["_pallet",objNull,[objNull]],["_mem","boxloader_flatrack",[""]]];
//if (isClass(configFile >> "CfgPatches" >> "boxloader_ace")) then {
//	_pallet setVariable ["boxloader_dontselect",true,true];
//} else {
_pallet lockCargo [0,true];
if (is3DEN) exitWith {true};
_pallet setVariable ["boxloader_flatrack_cargo",true];
[_pallet] spawn {
	_pallet = _this select 0;
	_mass = getMass _pallet;
	_parent = objNull;
	_loop = true;
	while {_loop} do { //don't use alive pallet because if the pallet dies we want to loop one last time
		sleep 1;
		if (alive _pallet) then { //We're alive, so check our mass stuff.
			if (!(_parent isEqualTo (attachedTo _pallet))) then { //we're not being carried by the same thing anymore.
				if ((alive _parent) && (_parent GetVariable ["boxloader_flatrack_carrier",false])) then { //Our old parent was PLS carrying us.
					_parent setMass (getMass _parent)-_mass; //Subtract our mass.
				};
				_parent = (attachedTo _pallet); //Update parent.
				if (alive _parent && (_parent getVariable ["boxloader_flatrack_carrier",false])) then { //New parent is PLS carrying us.
					_parent setMass (getMass _parent)+_mass; //Add our mass.
				};
			};
			if ((alive _parent) && (_mass!=getMass _pallet) && ((_parent getVariable ["boxloader_flatrack_carrier",false]) || ((isVehicleCargo _pallet)==_parent))) then { //Our mass changed, and we're being carried: either by a flatrack truck, or by VIV.
				_diffmass = (getMass _pallet)-_mass; //Positive if we got more mass, negative if we lost some.
				(attachedTo _pallet) setMass ((getMass attachedTo _pallet)+_diffmass); //Adjust parent mass by ours.
				_mass = (getMass _pallet); //Update mass.
			};
		} else {
			_loop = false; //Stop looping, but adjust masses one last time.
			if (alive _parent) then { //pallet died/deleted, but was attached to something
				_parent setMass (getMass _parent)-_mass; //Remove our last applied mass value.
			};
		};
	};
};
//};
true
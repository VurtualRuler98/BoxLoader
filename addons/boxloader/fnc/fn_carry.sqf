params [["_obj",objNull,[objNull]],["_pos",[0,0,0],[[]],[2,3]],["_dir",0,[0]],["_lift",0.5,[0]]];
if (isNull _obj) exitWith {false};
_obj addAction ["Pick Up Equipment",{
	params ["_obj","_ply"];
	(_this select 3) params ["_pos","_dir","_lift"];
	_obj attachTo [_ply,_pos];
	_obj setdir _dir;
	
	_ac=_ply addAction ["Drop Equipment",{
		(_this select 3) params ["_obj","_ply","_pos","_dir","_lift"];
		_obj attachTo [_ply,(_pos vectorAdd [0,0,_lift])];
		_obj setdir _dir; 
		detach _obj; 
		_obj setVehiclePosition [(getposATL _obj),[],0,"CAN_COLLIDE"]; 
	},[_obj,_ply,_pos,_dir,_lift]]; 
	
	[_obj,_ply,_ac] spawn { 
		params ["_obj","_ply","_ac"];
		waitUntil {
			sleep 0.1;
			(isNull _obj || isNull _ply || !alive _ply || (isNull attachedTo _obj))
		}; 
		_ply removeAction _ac;
		sleep 0.1; 
		_obj setVelocity [0,0,0];
	}; 
},[_pos,_dir,_lift],0.5,false,true,"","isNull attachedTo _target"];
true

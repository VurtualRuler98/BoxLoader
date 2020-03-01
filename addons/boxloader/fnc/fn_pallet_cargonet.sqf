params [["_pallet",objNull,[objNull]]];
_pallet addAction ["Pack Cargo",{[(_this select 0),true] remoteExec ["boxloader_fnc_hide",2]; (_this select 0) animateSource ["cargonet",1];},[],0,false,true,"","!((vehicle _target) getVariable ['boxloader_cargohidden',false])"];
_pallet addAction ["Unpack Cargo",{[(_this select 0),false] remoteExec ["boxloader_fnc_hide",2];(_this select 0) animateSource ["cargonet",0];},[],0,false,true,"","((vehicle _target) getVariable ['boxloader_cargohidden',false])"];
true

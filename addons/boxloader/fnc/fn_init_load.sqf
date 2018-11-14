if (is3DEN) exitWith {false};
	

["B_APC_Tracked_01_CRV_F","init",{
	(_this select 0) setVariable ["boxloader_build_fill",true];
	(_this select 0) setVariable ["boxloader_build_tools",true];
	(_this select 0) setVariable ["boxloader_load_weight",35000];
	(_this select 0) setVariable ["boxloader_load_height",7];
	(_this select 0) setVariable ["boxloader_crane_push",35000];
	(_this select 0) setVariable ["boxloader_load_viv",false];
}] call CBA_fnc_addClassEventHandler;

["Air","init",{
	(_this select 0) setVariable ["boxloader_load_ramp",((_this select 0) getVariable ["boxloader_load_ramp",true])];
}] call CBA_fnc_addClassEventHandler; //all planes and helicopters use ramps by default

["Land_RepairDepot_01_base_F","init",{
	(_this select 0) setVariable ["boxloader_build_fill",true];
	(_this select 0) setVariable ["boxloader_build_tools",true];
	(_this select 0) setVariable ["boxloader_work_vehicle",true];
	(_this select 0) setVariable ["boxloader_load_weight",4500];
	(_this select 0) setVariable ["boxloader_load_height",5];
	(_this select 0) setVariable ["boxloader_crane_push",4500];
	(_this select 0) setVariable ["boxloader_load_viv",false];
}] call CBA_fnc_addClassEventHandler;

["AllVehicles","init",{
	_repair_v = getNumber (configFile >> "CfgVehicles" >> (typeOf (_this select 0)) >> "transportRepair");
	_repair_a = getNumber (configFile >> "CfgVehicles" >> (typeOf (_this select 0)) >> "ace_repair_canRepair");
	if ((_repair_v<1) && (_repair_a<1)) exitWith {false};
	if (boxloader_allrepair_work) then {
		(_this select 0) setVariable ["boxloader_build_fill",((_this select 0) getVariable ["boxloader_build_fill",true]),true];
		(_this select 0) setVariable ["boxloader_build_tools",((_this select 0) getVariable ["boxloader_build_tools",true]),true];
		(_this select 0) setVariable ["boxloader_work_vehicle",((_this select 0) getVariable ["boxloader_work_vehicle",true]),true];
	};
	if (boxloader_allrepair_load) then {
		(_this select 0) setVariable ["boxloader_load_weight",((_this select 0) getVariable ["boxloader_load_weight",boxloader_allrepair_weight]),true];
		(_this select 0) setVariable ["boxloader_load_height",((_this select 0) getVariable ["boxloader_load_height",boxloader_allrepair_height]),true];
		(_this select 0) setVariable ["boxloader_crane_push",((_this select 0) getVariable ["boxloader_crane_push",boxloader_allrepair_push]),true];
	};
}] call CBA_fnc_addClassEventHandler;

true

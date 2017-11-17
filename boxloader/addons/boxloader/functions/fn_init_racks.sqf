if (is3DEN) exitWith {false};
["Quadbike_01_Base_F","init",{(_this select 0) call boxloader_fnc_rack_quad}] call CBA_fnc_addClassEventHandler;
["Van_02_base_F","init",{(_this select 0) call boxloader_fnc_rack_idap}] call CBA_fnc_addClassEventHandler;
["Offroad_01_civil_base_F","init",{(_this select 0) call boxloader_fnc_rack_offroad}] call CBA_fnc_addClassEventHandler;
["I_G_Offroad_01_F","init",{(_this select 0) call boxloader_fnc_rack_offroad}] call CBA_fnc_addClassEventHandler;
["B_Truck_01_transport_F","init",{(_this select 0) call boxloader_fnc_rack_hemtt}] call CBA_fnc_addClassEventHandler;
["Van_01_transport_base_F","init",{(_this select 0) call boxloader_fnc_rack_boxer}] call CBA_fnc_addClassEventHandler;
{[_x,"init",{(_this select 0) call boxloader_fnc_rack_kamaz}] call CBA_fnc_addClassEventHandler;} forEach ["Truck_02_transport_Base_F","O_Truck_02_covered_F","I_Truck_02_covered_F","C_Truck_02_covered_F","C_IDAP_Truck_02_F"];
{[_x,"init",{(_this select 0) call boxloader_fnc_rack_typhoon}] call CBA_fnc_addClassEventHandler;} forEach ["O_Truck_03_covered_F","O_Truck_03_transport_F"];
["Rubber_duck_base_F","init",{(_this select 0) call boxloader_fnc_rack_zodiac}] call CBA_fnc_addClassEventHandler;
["Boat_Civil_01_base_F","init",{(_this select 0) call boxloader_fnc_rack_motorboat}] call CBA_fnc_addClassEventHandler;


["RHS_Ural_Flat_MSV_01","init",{(_this select 0) call boxloader_fnc_rack_rhsural}] call CBA_fnc_addClassEventHandler;
["RHS_Ural_Open_Flat_MSV_01","init",{(_this select 0) call boxloader_fnc_rack_rhsural}] call CBA_fnc_addClassEventHandler;
["rhs_gaz66o_flat_vmf","init",{(_this select 0) call boxloader_fnc_rack_rhsgaz}] call CBA_fnc_addClassEventHandler;
["rhs_gaz66_flat_vmf","init",{(_this select 0) call boxloader_fnc_rack_rhsgaz}] call CBA_fnc_addClassEventHandler;

{[_x,"init",{(_this select 0) call boxloader_fnc_rack_cuphsov}] call CBA_fnc_addClassEventHandler;} forEach ["CUP_HMMWV_SOV_Base","CUP_HMMWV_SOV_M2_Base"];
["CUP_HMMWV_Transport_Base","init",{(_this select 0) call boxloader_fnc_rack_cupm998}] call CBA_fnc_addClassEventHandler;
["CUP_M1152_BASE","init",{(_this select 0) call boxloader_fnc_rack_cupm1152}] call CBA_fnc_addClassEventHandler;
["CUP_Ural_Base","init",{(_this select 0) call boxloader_fnc_rack_cupural}] call CBA_fnc_addClassEventHandler;


{[_x,"init",{(_this select 0) call boxloader_fnc_rack_ifa}] call CBA_fnc_addClassEventHandler;} forEach ["LIB_US_GMC_Open","LIB_opelblitz_open_y_camo","LIB_US6_Unarmed_base","LIB_Zis5v"];
true


["boxloader_hidecargo_enabled","CHECKBOX",["Enable ""Hide Cargo"" feature","Can be changed mid-mission."],"Boxloader",true,true] call CBA_settings_fnc_init;
["boxloader_maxload_enabled","CHECKBOX",["Enable player load weight limits","Limits the weight that players can load, push, and unload."],"Boxloader",false,true] call CBA_settings_fnc_init;
["boxloader_push_enabled","CHECKBOX",["Enable pushing of objects.","Enables the pushing system."],"Boxloader",true,true] call CBA_settings_fnc_init;
["boxloader_maxload_lift","SLIDER",["Maximum lift weight","The maximum weight a player can lift and load into something to chest height."],"Boxloader",[10,5000,50,0],true] call CBA_settings_fnc_init;
["boxloader_maxload_overhead","SLIDER",["Maximum overhead weight","The maximum weight a player can lift and load into something above their head."],"Boxloader",[10,5000,30,0],true] call CBA_settings_fnc_init;
["boxloader_maxload_push","SLIDER",["Maximum push weight","The maximum weight a player push on the ground, and load into things near ground level."],"Boxloader",[10,5000,200,0],true] call CBA_settings_fnc_init;
["boxloader_maxload_minpush","SLIDER",["Minimum push weight","Only objects with a weight above this can be pushed, anything below can still be loaded. Should be at least zero to prevent pushing ""weightless"" objects."],"Boxloader",[-1,1000,10,0],true] call CBA_settings_fnc_init;




["boxloader_allrepair_work","CHECKBOX",["Enable repair vehicles to build","Newly spawned vehicles capable of repair will be fortification construction vehicles."],"Boxloader",true,true] call CBA_settings_fnc_init;
["boxloader_allrepair_load","CHECKBOX",["Enable repair vehicles to load","Newly spawned vehicles capable of repair will have load handling equipment."],"Boxloader",true,true] call CBA_settings_fnc_init;
["boxloader_allrepair_weight","SLIDER",["Max repair vehicle load weight","(Newly spawned vehicles) The maximum weight a repair vehicle's loading equipment can load into a vehicle."],"Boxloader",[1000,50000,10000,0],true] call CBA_settings_fnc_init;
["boxloader_allrepair_height","SLIDER",["Max repair vehicle load height","(Newly spawned vehicles) The maximum height a repair vehicle's loading equipment can reach."],"Boxloader",[1,20,5,0],true] call CBA_settings_fnc_init;
["boxloader_allrepair_push","SLIDER",["Max repair vehicle push weight","(Newly spawned vehicles) The maximum weight a repair vehicle's loading equipment can push on the ground, should be as high or higher than its load weight."],"Boxloader",[1000,50000,10000,0],true] call CBA_settings_fnc_init;
true

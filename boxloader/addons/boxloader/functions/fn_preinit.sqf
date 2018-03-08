["boxloader_retrofit_enabled","CHECKBOX",["Enable retrofit cargo areas","Applies only to newly-spawned vehicles."],"Boxloader",true,true] call CBA_settings_fnc_init;
["boxloader_hidecargo_enabled","CHECKBOX",["Enable ""Hide Cargo"" feature","Can be changed mid-mission."],"Boxloader",true,true] call CBA_settings_fnc_init;
["boxloader_maxload_enabled","CHECKBOX",["Enable player load weight limits","Limits the weight that players can load, push, and unload."],"Boxloader",false,true] call CBA_settings_fnc_init;
["boxloader_maxload_lift","SLIDER",["Maximum lift weight","The maximum weight a player can lift and load into something to chest height."],"Boxloader",[10,5000,50,0],true] call CBA_settings_fnc_init;
["boxloader_maxload_overhead","SLIDER",["Maximum overhead weight","The maximum weight a player can lift and load into something above their head."],"Boxloader",[10,5000,30,0],true] call CBA_settings_fnc_init;
["boxloader_maxload_push","SLIDER",["Maximum push weight","The maximum weight a player push on the ground, and load into things near ground level."],"Boxloader",[10,5000,200,0],true] call CBA_settings_fnc_init;
true

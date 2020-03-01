//define TEMPER_GREEN "#(argb,8,8,3)color(0.181,0.212,0.136,1.0,co)"
//define TEMPER_TAN "#(argb,8,8,3)color(0.991,0.778,0.566,1.0,co)"
#define TEMPER_GREEN "\boxloader\tex\boxloader_canvas_green_co.paa"
#define TEMPER_TAN "\boxloader\tex\boxloader_canvas_tan2_co.paa"
#define TEMPER_WHITE "\boxloader\tex\boxloader_canvas_white_co.paa"
class land_boxloader_temper_base: land_boxloader_Fort_base {
	destrType="DestructBuilding";
	boxloader_tools = 1;
	armor=2000;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	scope = 0;
	boxloader_snap = 1;
	boxloader_snap_pos[] = {};
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		Dragged3DEN = "[_this select 0] call boxloader_fort_fnc_snap_editor";
		//CuratorObjectEdited = "[_this select 1] call boxloader_fort_fnc_snap_editor";	
	};
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
};
class land_boxloader_temper_section_base: land_boxloader_temper_base {
	model="\boxloader_fort\mdl\boxloader_fort_temper_section.p3d";
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_section_base",{{"tent_end1",180,0},{"tent_end2",180,0}}},
		{"land_boxloader_temper_end_base",{{"tent_end1",180,0}}}
	};
	class AnimationSources {
		class side_type {
			source = "user";
			initPhase = 0;
			animPeriod = 0.1;
		};
		class ground_hide {
			source = "user";
			initPhase = 0.5;
			animPeriod = 0.1;
		};
		class door1_open {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
		class door2_open: door1_open {};
	};
	class UserActions {
		class Door1_open {
			displayName = "Open/Close Window";
			position = "door1_action";
			radius = 3;
			onlyforplayer = false;
			condition = "true";
			statement = "this animateSource [""door1_open"",ceil (abs ((this animationSourcePhase ""door1_open"")-1))]";
		};
		class Door2_open: Door1_open {
			position = "door2_action";
			statement = "this animateSource [""door2_open"",ceil (abs ((this animationSourcePhase ""door2_open"")-1))]";
		};
	};
};
class land_boxloader_lme_base: land_boxloader_temper_base {
	boxloader_snap = 0;
	boxloader_snap_pos[] = {};
	model="\boxloader_fort\mdl\boxloader_fort_lme.p3d";
	class AnimationSources {
		class side_type {
			source = "user";
			initPhase = 0;
			animPeriod = 0.1;
		};
		class ground_hide {
			source = "user";
			initPhase = 0.5;
			animPeriod = 0.1;
		};
		class window1_open {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
		class window2_open: window1_open {};
	};
	class UserActions {
		class Window1_open {
			displayName = "Open/Close Window";
			position = "door1_action";
			radius = 3;
			onlyforplayer = false;
			condition = "true";
			statement = "this animateSource [""window1_open"",ceil (abs ((this animationSourcePhase ""window1_open"")-1))]";
		};
		class Window2_open: Window1_open {
			position = "door2_action";
			statement = "this animateSource [""window2_open"",ceil (abs ((this animationSourcePhase ""window2_open"")-1))]";
		};
	};
};

class land_boxloader_temper_end_base: land_boxloader_temper_base {
	model="\boxloader_fort\mdl\boxloader_fort_temper_end.p3d";
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_section_base",{{"tent_end1a",360,180},{"tent_end2a",360,0}}},
		{"land_boxloader_temper_vestibule_base",{{"tent_end1a",360,0},{"tent_end2a",360,180}}}
	};
	class AnimationSources {
		class door_open {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
		class window_open {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
		class ground_hide {
			source = "user";
			initPhase = 0.5;
			animPeriod = 0.1;
		};
	};
	class UserActions {
		class Door_open {
			displayName = "Open/Close Door";
			position = "door1_action";
			radius = 3;
			onlyforplayer = false;
			condition = "true";
			statement = "this animateSource [""door_open"",ceil (abs ((this animationSourcePhase ""door_open"")-1))]";
		};
		class Window_open {
			displayName = "Open/Close Window";
			position = "door1_action";
			radius = 3;
			onlyforplayer = false;
			condition = "true";
			statement = "this animateSource [""window_open"",ceil (abs ((this animationSourcePhase ""window_open"")-1))]";
		};
	};
};
class land_boxloader_temper_vestibule_base: land_boxloader_temper_base {
	model="\boxloader_fort\mdl\boxloader_fort_temper_vestibule.p3d";
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_end_base",{{"tent_end2",180,0}}},
		{"land_boxloader_temper_door_base",{{"tent_vestibule1",180,90},{"tent_vestibule2",180,90}}},
		{"land_boxloader_temper_vestibule_base",{{"tent_end1",180,0},{"tent_end2",180,0}}},
	};
	class AnimationSources {
		class ground_hide {
			source = "user";
			initPhase = 0.5;
			animPeriod = 0.1;
		};
	};
};
class land_boxloader_temper_door_base: land_boxloader_temper_section_base {
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_section_base",{{"tent_end1",180,0},{"tent_end2",180,0}}},
		{"land_boxloader_temper_end_base",{{"tent_end1",180,0}}},
		{"land_boxloader_temper_vestibule_base",{{"tent_vestibule1",180,90},{"tent_vestibule2",180,90}}}
	};
	class AnimationSources: AnimationSources {
		class side_type: side_type {
			initPhase = 0;
		};
	};
	class UserActions {
		class Door1_open {
			displayName = "Open/Close Door";
			position = "door1_action";
			radius = 3;
			onlyforplayer = false;
			condition = "true";
			statement = "this animateSource [""door1_open"",ceil (abs ((this animationSourcePhase ""door1_open"")-1))]";
		};
		class Door2_open: Door1_open {
			position = "door2_action";
			statement = "this animateSource [""door2_open"",ceil (abs ((this animationSourcePhase ""door2_open"")-1))]";
		};
	};
};


class Land_Boxloader_Temper_Flat_Base: Land_Boxloader_Fort_Base {
	boxloader_tools = 1;
	boxloader_fill = 0;
	boxloader_snap = 1;
	model = "\boxloader_fort\mdl\boxloader_fort_temper_flat.p3d";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	class VehicleTransport {
		class Cargo {
			dimensions[]				= {"VTV_Cargo_Base","VTV_Cargo_Corner"};
			parachuteClass				= "B_Parachute_02_F";
			canBeTransported            = 1;
			parachuteHeightLimit		= 99999;
		};
	};
	class AnimationSources {
		class loaded {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
	};
};

//Green, Packed

class Land_Boxloader_Temper_Door_Flat_Green: Land_Boxloader_Temper_Flat_Base {
	displayName = "TEMPER Door Section (Green, Packed)";

	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Door_Green","Build Door Section",
		{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Temper_Door_b_Green","Build Door Section (Floor)",
		{"corner1a","corner2a","corner3a","corner4a"}}
	};

	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
	scope = 2;
	scopeCurator = 2;

};
class land_boxloader_temper_window_flat_green: Land_Boxloader_Temper_Flat_Base {
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Window_Green","Build Window Section",
		{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Temper_Window_b_Green","Build Window Section (Floor)",
		{"corner1a","corner2a","corner3a","corner4a"}}
	};
	displayName = "TEMPER Window Section (Green, Packed)";
	scope = 2;
	scopeCurator = 2;
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
};


class Land_Boxloader_Temper_End_Flat_Green: Land_Boxloader_Temper_Flat_Base {
	displayName = "TEMPER End Section (Green, Packed)";
	model = "\boxloader_fort\mdl\boxloader_fort_temper_flat2.p3d";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_End_Green","Build End Section",
		{"corner1","corner2"}},
		{"Land_Boxloader_Temper_End_b_Green","Build End Section (Floor)",
		{"corner1a","corner2a","corner3a","corner4a","corner5a","corner6a"}}
	};
	scope = 2;
	scopeCurator = 2;
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
};
class Land_Boxloader_Temper_Vestibule_Flat_Green: Land_Boxloader_Temper_Flat_Base {
	displayName = "TEMPER Vestibule Section (Green, Packed)";
	model = "\boxloader_fort\mdl\boxloader_fort_temper_flat3.p3d";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Vestibule_Green","Build Vestibule Section",
		{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Temper_Vestibule_b_Green","Build Vestibule Section (Floor)",
		{"corner1a","corner2a","corner3a","corner4a","corner5a","corner6a","corner7a","corner8a"}}
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
	scope = 2;
	scopeCurator = 2;
};

class Land_Boxloader_LME_Flat_Green: Land_Boxloader_Temper_Flat_Base {
	displayName = "Maintenance Enclosure (Green, Packed)";
	model = "\boxloader_fort\mdl\boxloader_fort_lme_flat.p3d";
	boxloader_snap = 0;
	boxloader_buildables[] = {
		{"Land_Boxloader_LME_Green","Build Maintenance Enclosure",
		{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Temper_LME_b_Green","Build Maintenance Enclosure (Floor)",
		{"corner1a","corner2a","corner3a","corner4a"}}
	};

	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
	scope = 2;
	scopeCurator = 2;

};

//Tan, Packed

class land_boxloader_Temper_door_flat_tan: land_boxloader_temper_door_flat_green {
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Door_Tan","Build Door Section",
		{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Temper_Door_b_Tan","Build Door Section (Floor)",
		{"corner1a","corner2a","corner3a","corner4a"}}
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
	displayName = "TEMPER Door Section (Tan, Packed)";
};
class land_boxloader_Temper_window_flat_tan: land_boxloader_temper_window_flat_green {
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Window_Tan","Build Window Section",
		{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Temper_Window_b_Tan","Build Window Section (Floor)",
		{"corner1a","corner2a","corner3a","corner4a"}}
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
	displayName = "TEMPER Window Section (Tan, Packed)";
};
class Land_Boxloader_Temper_End_Flat_Tan: Land_Boxloader_Temper_End_Flat_Green {
	displayName = "TEMPER End Section (Tan, Packed)";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_End_Tan","Build End Section",
		{"corner1","corner2"}},
		{"Land_Boxloader_Temper_End_b_Tan","Build End Section (Floor)",
		{"corner1a","corner2a","corner3a","corner4a"}}
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
};
class Land_Boxloader_Temper_Vestibule_Flat_Tan: Land_Boxloader_Temper_Vestibule_Flat_Green {
	displayName = "TEMPER Vestibule Section (Tan, Packed)";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Vestibule_Tan","Build Vestibule Section",
		{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Temper_Vestibule_b_Tan","Build Vestibule Section (Floor)",
		{"corner1a","corner2a","corner3a","corner4a"}}
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
};

class Land_Boxloader_LME_Flat_Tan: Land_Boxloader_LME_Flat_Green {
	displayName = "Maintenance Enclosure (Tan, Packed)";

	boxloader_buildables[] = {
		{"Land_Boxloader_LME_Tan","Build Maintenance Enclosure",
		{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_LME_b_Tan","Build Maintenance Enclosure (Floor)",
		{"corner1a","corner2a","corner3a","corner4a"}}
	};

	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
	scope = 2;
	scopeCurator = 2;

};



//Green, No Floor

class land_boxloader_temper_end_green: land_boxloader_temper_end_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER End Section (Green)";
	Boxloader_ConBase = "Land_Boxloader_Temper_End_Flat_Green";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
};
class land_boxloader_temper_vestibule_green: land_boxloader_temper_vestibule_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Vestibule Section (Green)";
	Boxloader_ConBase = "Land_Boxloader_Temper_Vestibule_Flat_Green";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
};
class land_boxloader_temper_door_green: land_boxloader_temper_door_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Door Section (Green)";
	Boxloader_ConBase="Land_Boxloader_Temper_Door_Flat_Green";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
};
class land_boxloader_temper_window_green: land_boxloader_temper_section_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Window Section (Green)";
	Boxloader_ConBase="Land_Boxloader_Temper_Window_Flat_Green";
	class AnimationSources: AnimationSources {
		class side_type: side_type {
			initPhase = 1;
		};
	};
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
};

class Land_Boxloader_LME_Green: land_boxloader_lme_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "Maintenance Enclosure (Green)";
	Boxloader_ConBase="Land_Boxloader_LME_Flat_Green";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_GREEN};
};


//Green, Floor

class land_boxloader_temper_end_f_green: land_boxloader_temper_end_green {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_temper_end_b_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER End Section (Green, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};
class land_boxloader_temper_vestibule_f_green: land_boxloader_temper_vestibule_green {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_temper_vestibule_b_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Vestibule Section (Green, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};
class land_boxloader_temper_door_f_green: land_boxloader_temper_door_green {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_temper_door_b_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Door Section (Green, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};
class land_boxloader_temper_window_f_green: land_boxloader_temper_window_green {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_temper_window_b_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Window Section (Green, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};
class land_boxloader_LME_f_green: land_boxloader_LME_green {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_LME_b_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "Maintenance Enclosure (Green, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};


//Green, Floor Base

class land_boxloader_temper_end_b_green: land_boxloader_temper_end_green {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_temper_end_f_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER End Section (Green, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};
class land_boxloader_temper_vestibule_b_green: land_boxloader_temper_vestibule_green {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_temper_vestibule_f_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Vestibule Section (Green, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};
class land_boxloader_temper_door_b_green: land_boxloader_temper_door_green {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_temper_door_f_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Door Section (Green, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};
class land_boxloader_temper_window_b_green: land_boxloader_temper_window_green {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_temper_window_f_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Window Section (Green, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};

class land_boxloader_LME_b_green: land_boxloader_LME_green {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_LME_f_green";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "Maintenance Enclosure (Green, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};






//Tan, No Floor

class land_boxloader_temper_end_Tan: land_boxloader_temper_end_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER End Section (Tan)";
	Boxloader_ConBase = "Land_Boxloader_Temper_End_Flat_Tan";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
};
class land_boxloader_temper_vestibule_Tan: land_boxloader_temper_vestibule_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Vestibule Section (Tan)";
	Boxloader_ConBase = "Land_Boxloader_Temper_Vestibule_Flat_Tan";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
};
class land_boxloader_temper_door_Tan: land_boxloader_temper_door_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Door Section (Tan)";
	Boxloader_ConBase="Land_Boxloader_Temper_Door_Flat_Tan";
	class AnimationSources: AnimationSources {
		class side_type: side_type {
			initPhase = 0;
		};
		class door_open {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
	};
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
};
class land_boxloader_temper_window_Tan: land_boxloader_temper_section_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Window Section (Tan)";
	Boxloader_ConBase="Land_Boxloader_Temper_Window_Flat_Tan";
	class AnimationSources: AnimationSources {
		class side_type: side_type {
			initPhase = 1;
		};
	};
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
};

class Land_Boxloader_LME_Tan: land_boxloader_lme_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "Maintenance Enclosure (Tan)";
	Boxloader_ConBase="Land_Boxloader_LME_Flat_Tan";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {TEMPER_TAN};
};




//Tan, Floor

class land_boxloader_temper_end_f_Tan: land_boxloader_temper_end_Tan {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_temper_end_b_Tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER End Section (Tan, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};
class land_boxloader_temper_vestibule_f_Tan: land_boxloader_temper_vestibule_Tan {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_temper_vestibule_b_Tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Vestibule Section (Tan, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};
class land_boxloader_temper_door_f_Tan: land_boxloader_temper_door_Tan {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_temper_door_b_Tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Door Section (Tan, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};
class land_boxloader_temper_window_f_Tan: land_boxloader_temper_window_Tan {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_temper_window_b_Tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Window Section (Tan, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};
class land_boxloader_LME_f_tan: land_boxloader_LME_tan {
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_LME_b_tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "Maintenance Enclosure (Tan, Floor)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 0;};};
};


//Tan, Floor Base

class land_boxloader_temper_end_b_Tan: land_boxloader_temper_end_Tan {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_temper_end_f_Tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER End Section (Tan, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};
class land_boxloader_temper_vestibule_b_Tan: land_boxloader_temper_vestibule_Tan {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_temper_vestibule_f_Tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Vestibule Section (Tan, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};
class land_boxloader_temper_door_b_Tan: land_boxloader_temper_door_Tan {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_temper_door_f_Tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Door Section (Tan, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};
class land_boxloader_temper_window_b_Tan: land_boxloader_temper_window_Tan {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_temper_window_f_Tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "TEMPER Window Section (Tan, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};

class land_boxloader_LME_b_tan: land_boxloader_LME_tan {
	scope = 1;
	scopeCurator = 1;
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_LME_f_tan";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
	};
	displayName = "Maintenance Enclosure (Tan, Floor Frame)"; 
	class AnimationSources: AnimationSources {class ground_hide: ground_hide {initPhase = 1;};};
};




//Accessories

class Land_Boxloader_Temper_Divider_Flat: Land_Boxloader_Temper_Flat_Base {
	displayName = "TEMPER Partition (Packed)";
	model = "\boxloader_fort\mdl\boxloader_fort_temper_flat2.p3d";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Divider","Build Divider"}
	};
	scope = 2;
	scopeCurator = 2;
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_WHITE};
};
class land_boxloader_temper_divider: land_boxloader_temper_base {
	model="\boxloader_fort\mdl\boxloader_fort_temper_divider.p3d";
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_section_base",{{"tent_end1a",360,180},{"tent_end2a",360,0}}}
	};
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Partition";
	Boxloader_ConBase = "Land_Boxloader_Temper_Divider_Flat";
	class AnimationSources {
		class door_open {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
	};
	class UserActions {
		class Door_open {
			displayName = "Open/Close Door";
			position = "door1_action";
			radius = 3;
			onlyforplayer = false;
			condition = "true";
			statement = "this animateSource [""door_open"",ceil (abs ((this animationSourcePhase ""door_open"")-1))]";
		};
	};
};


class Land_Boxloader_Temper_Lights_Flat: Land_Boxloader_Temper_Flat_Base {
	displayName = "TEMPER Lights (Packed)";
	model = "\boxloader_fort\mdl\boxloader_fort_wall_flat.p3d";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Lights","Build Lights"}
	};
	scope = 2;
	scopeCurator = 2;
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_WHITE};
};
class land_boxloader_temper_lights: land_boxloader_temper_base {
	model="\boxloader_fort\mdl\boxloader_fort_temper_light.p3d";
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_section_base",{{"tent_pos",360,0}}}
	};
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Lights";
	Boxloader_ConBase = "Land_Boxloader_Temper_Lights_Flat";
	class Reflectors {
		class Light {
			color[] = {100, 100, 100};
			ambient[] = {1, 1, 1};
			position = "Light";
			direction = "Light_end";
			hitpoint = "Light_L";
			selection = "Light_L";
			size = 1;
			innerAngle = 180;
			outerAngle = 360;
			coneFadeCoef = 5;
			intensity = 1;
			useFlare = 0;
			class Attenuation {
				start = 1;
				constant = 0;
				linear = 0;
				quadratic = 1;
				hardLimitStart = 3.5;
				hardLimitEnd = 4.5;
			};
		};
	};
	class UserActions {
		class light_off {
			displayName = "Light Off";
			position = "light_action";
			radius = 3;
			onlyforplayer = false;
			condition = "(lightIsOn this)=='ON'";
			statement = "this switchLight 'OFF'";
		};
		class light_on: light_off {
			condition = "(lightIsOn this)!='ON'"
			displayName = "Light On";
			statement = "this switchlight 'ON'";
		};
	};
};
class Land_Boxloader_Temper_Medsign_Flat: Land_Boxloader_Temper_Flat_Base {
	displayName = "TEMPER Medical Sign (Packed)";
	model = "\boxloader_fort\mdl\boxloader_fort_temper_flat2.p3d";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Medsign","Build Medical Sign (Red Crystal)"},
		{"Land_Boxloader_Temper_Medsign2","Build Medical Sign (Red Cross)"}
	};
	scope = 2;
	scopeCurator = 2;
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {TEMPER_WHITE};
};
class land_boxloader_temper_medsign: land_boxloader_temper_base {
	model="\boxloader_fort\mdl\boxloader_fort_temper_medsign.p3d";
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_section_base",{{"tent_pos",360,0}}}
	};
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Medical Sign (Red Crystal)";
	Boxloader_ConBase = "Land_Boxloader_Temper_Medsign_Flat";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_canvas_aid_co.paa"};
};
class land_boxloader_temper_medsign2: land_boxloader_temper_medsign {
	displayName = "TEMPER Medical Sign (Red Cross)";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_canvas_aid2_co.paa"};
};

class land_boxloader_temper_camonet_green: land_boxloader_temper_base {
	model="\boxloader_fort\mdl\boxloader_fort_temper_camonet.p3d";
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_section_base",{{"tent_pos",360,0}}},
		{"land_boxloader_temper_camonet_green",{{"tent_end1",360,0},{"tent_end2",360,0},{"tent_end3",360,0},{"tent_end4",360,0}}}
	};
	scope = 2;
	scopeCurator = 2;
	displayName = "TEMPER Camonet (Green)";
	Boxloader_ConBase = "Land_Boxloader_Camonet_Green_Flat";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_camonet_green_ca.paa"};
};
class land_boxloader_temper_camonet_tan: land_boxloader_temper_camonet_green {
	displayName = "TEMPER Camonet (Tan)";
	Boxloader_ConBase = "Land_Boxloader_Camonet_Tan_Flat";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_camonet_tan_ca.paa"};
};


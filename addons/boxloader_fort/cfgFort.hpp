#define CAN_PLACE_BUILT 1
class Land_Boxloader_Fort_Base: HBarrier_base_F {
	boxloader_snap = 0;
};

#include "cfgTemper.hpp"
#define SNAP_PLAT_20 \
	{"snap1",90,0},{"snap2",90,0},{"snap3",90,0},{"snap4",90,0},{"snap5",90,0}, \
	{"snap6",90,0},{"snap7",90,0},{"snap8",90,0},{"snap9",90,0},{"snap10",90,0}, \
	{"snap11",90,0},{"snap12",90,0},{"snap13",90,0},{"snap14",90,0},{"snap15",90,0}, \
	{"snap16",90,0},{"snap17",90,0},{"snap18",90,0},{"snap19",90,0},{"snap20",90,0} 

#define SNAP_PLAT_14 \
	{"snap1",90,0},{"snap2",90,0},{"snap3",90,0},{"snap4",90,0},{"snap5",90,0}, \
	{"snap6",90,0},{"snap7",90,0},{"snap8",90,0},{"snap9",90,0},{"snap10",90,0}, \
	{"snap11",90,0},{"snap12",90,0},{"snap13",90,0},{"snap14",90,0} 

#define SNAP_PLAT_12 \
	{"snap1",90,0},{"snap2",90,0},{"snap3",90,0},{"snap4",90,0},{"snap5",90,0}, \
	{"snap6",90,0},{"snap7",90,0},{"snap8",90,0},{"snap9",90,0},{"snap10",90,0}, \
	{"snap11",90,0},{"snap12",90,0}

#define SNAP_CLASS1 \
		{"land_boxloader_fort_plat_5",{SNAP_PLAT_20}}, \
		{"land_boxloader_fort_plat_3",{SNAP_PLAT_12}}, \
		{"land_boxloader_fort_ground_5",{SNAP_PLAT_20}}, \
		{"land_boxloader_fort_ground_5_berm",{SNAP_PLAT_14}}
		
#define SNAP_CLASS2A \
{"land_boxloader_wall_2m",{{"snap1a",90,0},{"snap2a",90,0}}}

#define SNAP_CLASS2 \
	{"land_boxloader_wall_2m",{{"snap1",90,0},{"snap2",90,0}}}

#define SNAP_CLASS2B \
	{"land_boxloader_wall_2m",{{"snap1",90,0},{"snap2",90,0},{"snap1a",90,0},{"snap2a",90,0}}}

class Land_Boxloader_Hesco_Flat: Land_Boxloader_Fort_Base {
	displayName = "HESCO (Packed)";
	editorCategory="EdCat_Supplies";
	model = "\boxloader_fort\mdl\boxloader_hesco_flat.p3d";
	boxloader_tools = 0;
	boxloader_fill = 0;
	boxloader_buildables[] = {
		{"Land_Boxloader_Hesco_1","Build HESCO (1)"},
		{"Land_Boxloader_Hesco_2","Build HESCO (2)"},
		{"Land_Boxloader_Hesco_3","Build HESCO (3)"},
		{"Land_Boxloader_Hesco_5","Build HESCO (5)"}
	};
	scope = 2;
	scopeCurator = 2;
	editorSubcategory="EdSubCat_BoxloaderFort";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};

class Land_Boxloader_Hesco_BigFlat: Land_Boxloader_Hesco_Flat {
	displayName = "Big HESCO (Packed)";
	model = "\boxloader_fort\mdl\boxloader_hesco_bigflat.p3d";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	boxloader_buildables[] = {
		{"Land_Boxloader_Hesco_big1","Build Big HESCO (1)"},
		{"Land_Boxloader_Hesco_big3","Build Big HESCO (3)"},
		{"Land_Boxloader_Hesco_big5","Build Big HESCO (5)"}
	};
}
class Land_Boxloader_Hesco_SmallFlat: Land_Boxloader_Hesco_Flat {
	displayName = "Small HESCO (Packed)";
	model = "\boxloader_fort\mdl\boxloader_hesco_smallflat.p3d";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	boxloader_buildables[] = {
		{"Land_Boxloader_Hesco_small1","Build Small HESCO (1)"},
		{"Land_Boxloader_Hesco_small6","Build Small HESCO (6)"},
		{"Land_Boxloader_Hesco_small10","Build Small HESCO (10)"}
	};
}



class Land_Boxloader_Hesco_1: Land_Boxloader_Hesco_Flat {
	displayName = "HESCO 1m";
	model = "\boxloader_fort\mdl\boxloader_hesco_1.p3d";
	scope = CAN_PLACE_BUILT;
	scopeCurator = CAN_PLACE_BUILT;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_Hesco_1_Built";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	Boxloader_ConBase="Land_Boxloader_Hesco_Flat";
	class AnimationSources {
		class Fill_Source {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
		class Empty_Source {
			source = "user";
			initPhase = 0;
			animPeriod = 0;
		};
	};
	armor=1000;
	destrType="DestructTent";
	hiddenSelections[] = {"fill"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_hesco_dirt_co.paa"};
};
class Land_Boxloader_Hesco_2: Land_Boxloader_Hesco_1 {
	displayName = "HESCO 2m";
	model = "\boxloader_fort\mdl\boxloader_hesco_2.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_2_Built";
};
class Land_Boxloader_Hesco_3: Land_Boxloader_Hesco_1 {
	displayName = "HESCO 3m";
	model = "\boxloader_fort\mdl\boxloader_hesco_3.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_3_Built";
};
class Land_Boxloader_Hesco_5: Land_Boxloader_Hesco_1 {
	displayName = "HESCO 5m";
	model = "\boxloader_fort\mdl\boxloader_hesco_5.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_5_Built";
};
class Land_Boxloader_Fort_Roof_Flat: Land_Boxloader_Fort_Base {
	displayName = "Bunker Roof (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	boxloader_tools = 0;
	boxloader_fill = 0;
	boxloader_buildables[] = {{"Land_Boxloader_Fort_Roof","Build bunker roof"}};
	model = "\boxloader_fort\mdl\boxloader_fort_roof_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	Boxloader_ConBase="Land_Boxloader_Fort_Roof";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	class AnimationSources {
		class Chalk_Line {
			source = "user";
			initPhase = 0;
			animPeriod = 0;
		};
	};
};
class Land_Boxloader_Fort_Roof: Land_Boxloader_Fort_Roof_Flat {
	armor=2000;
	destrType="DestructTent";
	displayName = "Bunker Roof";
	model = "\boxloader_fort\mdl\boxloader_fort_roof.p3d";
	scope=CAN_PLACE_BUILT;
	scopeCurator=CAN_PLACE_BUILT;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	Boxloader_ConBase="Land_Boxloader_Fort_Roof_Flat";
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_Fort_Roof_Built";
	class AnimationSources {
		class Fill_Source {
			source = "user";
			initPhase = 1;
			animPeriod = 1;
		};
		class Lift_Source {
			source = "user";
			initPhase = 0;
			animPeriod = 1;
		};
	};
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};
class land_boxloader_fort_roof_built: land_boxloader_fort_roof {
	class AnimationSources: AnimationSources {
		class Fill_Source: Fill_Source {
			initPhase = 0;
		};
		class Lift_Source: Lift_Source {
			initPhase = 1;
		};
	};
	destrType="DestructBuilding";
	scope=2;
	scopeCurator=2;
	boxloader_isFilled=1;
	boxloader_hescoFill="Land_Boxloader_Fort_Roof";
};

class Land_Boxloader_Fort_Plat_Flat: Land_Boxloader_Fort_Base {
	displayName = "Wood Platform (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	model = "\boxloader_fort\mdl\boxloader_fort_roof_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	boxloader_snap = 1;
	
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	boxloader_tools = 1;
	boxloader_fill = 0;
	boxloader_buildables[] = {
		{"Land_Boxloader_Fort_Plat_5","Build Wood Platform 5x5m",
			{"corner1","corner2","corner3","corner4"}
		},
		{"Land_Boxloader_Fort_Plat_3","Build Wood Platform 3x3m",
			{"corner1","corner2","corner3","corner4"}
		},
		{"Land_Boxloader_Fort_Ground_5_frame","Build Foundation",
			{"corner1","corner2","corner3","corner4","corner5","corner6","corner7","corner8"}
		},
		{"Land_Boxloader_Fort_Ground_5_berm_frame","Build Berm",
			{"corner1","corner2","corner3","corner4","corner5","corner6","corner7","corner8"}
		}
	};
	class AnimationSources {
		class Chalk_Line {
			source = "user";
			initPhase = 0;
			animPeriod = 0;
		};
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_wood_co.paa"};
};
class Land_Boxloader_Fort_Plat_Base: Land_Boxloader_Fort_Base {
	armor=800;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	boxloader_snap = 1;
	Boxloader_ConBase="Land_Boxloader_Fort_Plat_Flat";
	boxloader_snap_pos[] = {
		SNAP_CLASS1,
		SNAP_CLASS2A
	};
	destrType="DestructBuilding";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		Dragged3DEN = "[_this select 0] call boxloader_fort_fnc_snap_editor";
	};
};

class Land_Boxloader_Fort_Plat_5: Land_Boxloader_Fort_Plat_Base {

	scope=2;
	scopeCurator=2;
	displayName = "Bunker Platform 5x5";
	model = "\boxloader_fort\mdl\boxloader_fort_plat_5m.p3d";
};
class Land_Boxloader_Fort_Plat_3: Land_Boxloader_Fort_plat_base {
	scope=2;
	scopeCurator=2;
	displayName = "Bunker Platform 3x3";
	model = "\boxloader_fort\mdl\boxloader_fort_plat_3m.p3d";
	
};
class Land_Boxloader_Fort_Ground_5_frame: Land_Boxloader_Fort_plat_base {
	scope = 1;
	scopeCurator = 1;
	displayName = "Earth Foundation 5m (Frame)";
	model = "\boxloader_fort\mdl\boxloader_fort_ground_5m_frame.p3d";
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_Fort_Ground_5";
	class EventHandlers: EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};
class land_boxloader_fort_ground_5_berm_frame: land_boxloader_Fort_ground_5_frame {
	displayName = "Earth Berm 5m (Frame)";
	model = "\boxloader_fort\mdl\boxloader_fort_ground_5m_berm_frame.p3d";
	boxloader_hescoFill = "Land_Boxloader_Fort_Ground_5_Berm";
};
class Land_Boxloader_Fort_Ground_5: Land_Boxloader_Fort_Ground_5_frame {
	scope = 2;
	scopeCurator = 2;
	armor = 99999;
	displayName = "Earth Foundation 5m";
	model = "\boxloader_fort\mdl\boxloader_fort_ground_5m.p3d";
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_Fort_Ground_5_frame";
};
class land_boxloader_fort_ground_5_berm: land_boxloader_fort_ground_5_berm_frame {
	displayName = "Earth Berm 5m";
	boxloader_hescoFill = "Land_Boxloader_Fort_Ground_5_berm_frame";
	model = "\boxloader_fort\mdl\boxloader_fort_ground_5m_berm.p3d";
	scope = 2;
	scopeCurator = 2;
	armor = 99999;
	boxloader_IsFilled = 1;
};
class Land_Boxloader_Fort_Wire_Flat: Land_Boxloader_Fort_Base {
	displayName = "Concertina Wire (Packed)";
	armor = 50;
	scope = 2;
	scopeCurator = 2;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	model = "\boxloader_fort\mdl\boxloader_fort_wire_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	boxloader_tools = 1;
	boxloader_fill = 0;
	boxloader_buildables[] = {
		{"Land_Boxloader_Fort_Wire_3m","Build Wire Fence 3m"},
		{"Land_Boxloader_Fort_Wire_5m","Build Wire Fence 5m"}
	};
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	class AnimationSources {
		class Chalk_Line {
			source = "user";
			initPhase = 0;
			animPeriod = 0;
		};
	};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 99999;
			canBeTransported            = 1;
		};
	   class Carrier {
		};
	};
};
class Land_Boxloader_Fort_Wire_5m: Land_Boxloader_Fort_Base {
	displayName = "Concertina Wire (5m)";
	armor = 100;
	scope = 2;
	scopeCurator = 2;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	model = "\boxloader_fort\mdl\boxloader_fort_wire_5m.p3d";
	destrType="DestructBuilding";
	Boxloader_ConBase="Land_Boxloader_Fort_Wire_Flat";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 99999;
			canBeTransported            = 0;
		};
	   class Carrier {
		};
	};
};
class Land_Boxloader_Fort_Wire_3m: Land_Boxloader_Fort_Wire_5m {
	displayName = "Concertina Wire (3m)";
	model = "\boxloader_fort\mdl\boxloader_fort_wire_3m.p3d";
};
class Land_Boxloader_Sandbag_Pile: Land_Boxloader_Fort_Base {
	displayName = "Sandbags";
	armor = 500;
	scope = 2;
	destrType="DestructBuilding";
	scopeCurator = 2;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderDeprecated";
	model = "\boxloader_fort\mdl\boxloader_sandbag_pile.p3d";
	scope = 2;
	scopeCurator = 2;
	boxloader_tools = 1;
	boxloader_fill = 0;
	boxloader_buildables[] = {
		{"Land_Boxloader_Sandbag_Fence","Build Sandbag Fence"},
		{"Land_Boxloader_Sandbag_Wall","Build Sandbag Wall"}
	};
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	class AnimationSources {
		class Chalk_Line {
			source = "user";
			initPhase = 0;
			animPeriod = 0;
		};
	};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 99999;
			canBeTransported            = 1;
		};
	   class Carrier {
		};
	};
};
class Land_Boxloader_Sandbag_Pile2: Land_Boxloader_Sandbag_Pile {
	displayName = "Sandbags (Big)";
	boxloader_snap = 1;
	boxloader_snap_pos[] = {};
	model = "\boxloader_fort\mdl\boxloader_sandbag_pile2.p3d";
	editorSubcategory="EdSubCat_BoxloaderFort";
	boxloader_buildables[] = {
		{"Land_Boxloader_Sandbag_Pile2_tall","Stack Tall Sandbag Pile"},
		{"Land_Boxloader_Sandbag_Wall2","Build Big Sandbag Wall"},
		{"Land_Boxloader_Sandbag_Floor","Build Big Sandbag Roof"},
		{"Land_Boxloader_Sandbag_Wall2_MG","Build Big Sandbag Wall (MG)"}
	};
};

class Land_Boxloader_Sandbag_Fence: Land_Boxloader_Fort_Base {
	displayName = "Sandbag Fence";
	armor = 1000;
	scope = 2;
	scopeCurator = 2;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderDeprecated";
	model = "\boxloader_fort\mdl\boxloader_sandbag_fence.p3d";
	Boxloader_ConBase="Land_Boxloader_Sandbag_Pile";
	destrType="DestructBuilding";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		Dragged3DEN = "[_this select 0] call boxloader_fort_fnc_snap_editor";
	};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 99999;
			canBeTransported            = 0;
		};
	   class Carrier {
		};
	};
};
class Land_Boxloader_Sandbag_Wall: Land_boxloader_Sandbag_Fence {
	displayName = "Sandbag Wall";
	model = "\boxloader_fort\mdl\boxloader_sandbag_wall.p3d";
};
class Land_Boxloader_Sandbag_Wall2: Land_Boxloader_Sandbag_Fence {
	displayName = "Big Sandbag Wall";
	model = "\boxloader_fort\mdl\boxloader_sandbag_wall2.p3d";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	boxloader_snap = 1;
	Boxloader_ConBase="Land_Boxloader_Sandbag_Pile2";
	boxloader_snap_pos[] = {
		{"land_boxloader_sandbag_wall2",{{"base1",360,180},{"base2",360,0},{"top1",360,0},{"top2",360,180}}}
	};
};
class Land_Boxloader_Sandbag_Floor: Land_Boxloader_Sandbag_Wall2 {
	displayName = "Big Sandbag Roof";
	model = "\boxloader_fort\mdl\boxloader_sandbag_floor.p3d";
};
class Land_Boxloader_Sandbag_Wall2_MG: Land_Boxloader_Sandbag_Wall2 {
	displayName = "Big Sandbag Wall (MG)";
	model = "\boxloader_fort\mdl\boxloader_sandbag_wall2_mg.p3d";
};
/* TODO
class Land_Boxloader_Sandbag_Wall2_Tall: Land_Boxloader_Sandbag_Wall2 {
	displayName = "Big Sandbag Wall (Tall)";
	model = "\boxloader_fort\mdl\boxloader_sandbag_pile2_tall.p3d";
};*/
class Land_Boxloader_Sandbag_Pile2_tall: Land_Boxloader_Sandbag_Pile2 {
	displayName = "Sandbags (Tall)";
	model = "\boxloader_fort\mdl\boxloader_sandbag_pile2_tall.p3d";
	boxloader_buildables[] = {
		{"Land_Boxloader_Sandbag_Pile2","Stack Big Sandbag Pile"},
		{"Land_Boxloader_Sandbag_Wall2","Build Big Sandbag Wall"},
		{"Land_Boxloader_Sandbag_Floor","Build Big Sandbag Roof"},
		{"Land_Boxloader_Sandbag_Wall2_MG","Build Big Sandbag Wall (MG)"}
	};
};
	
	

	
class Land_Boxloader_Fort_Wall_Flat: Land_Boxloader_Fort_Base {
	displayName = "Wood Wall (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	model = "\boxloader_fort\mdl\boxloader_fort_wall_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	boxloader_tools = 1;
	boxloader_fill = 0;
	boxloader_snap = 1;
	boxloader_buildables[] = {
		{"Land_Boxloader_Wall_2m","Build Wall 2m"},
		{"Land_Boxloader_Wall_1m","Build Wall 1.4m"},
		{"Land_Boxloader_Wall_2m_half","Build Wall 2m (half)"},
		{"Land_Boxloader_Wall_1m_half","Build Wall 1.4m (half)"},
		{"Land_Boxloader_Ramp_2m","Build Ramp 2m"},
		{"Land_Boxloader_Ramp_1m","Build Ramp 1.4m"},
		{"Land_Boxloader_Walk_2m","Build Walkway 2m"},
		{"Land_Boxloader_Rampart_1m_frame","Build Rampart 1.4m",
			{"corner1","corner2","corner3","corner4"}
		}
	};
	class AnimationSources {
		class Chalk_Line {
			source = "user";
			initPhase = 0;
			animPeriod = 0;
		};
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_wood_co.paa"};
};
class Land_Boxloader_Wall_Base: Land_Boxloader_Fort_Base {
	armor = 300;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	destrType="DestructBuilding";
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	Boxloader_ConBase="Land_Boxloader_Fort_Wall_Flat";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		Dragged3DEN = "[_this select 0] call boxloader_fort_fnc_snap_editor";
	};
};
class Land_Boxloader_Wall_2m: Land_Boxloader_Wall_Base {
	scope = 2;
	scopeCurator = 2;
	displayName = "Wall 2m";
	model = "\boxloader_fort\mdl\boxloader_fort_wall_2m.p3d";

	boxloader_snap = 1;
	boxloader_snap_pos[] = {
		SNAP_CLASS1,
		SNAP_CLASS2B
	};
};
class Land_Boxloader_Wall_2m_half: Land_Boxloader_Wall_2m {
	displayName = "Wall 2m (half)";
	model = "\boxloader_fort\mdl\boxloader_fort_wall_2m_half.p3d";
};
	
class Land_Boxloader_Wall_1m: Land_Boxloader_Wall_2m {
	displayName = "Wall 1.4m";
	model = "\boxloader_fort\mdl\boxloader_fort_wall_1m.p3d";
};

class Land_Boxloader_Wall_1m_half: Land_Boxloader_Wall_1m {
	displayName = "Wall 1.4m (half)";
	model = "\boxloader_fort\mdl\boxloader_fort_wall_1m_half.p3d";
};

class land_boxloader_rampart_1m_frame: land_boxloader_wall_2m {
	scope = 1;
	scopeCurator = 1;
	displayName = "Rampart 1.4m (Frame)";
	model = "\boxloader_fort\mdl\boxloader_fort_rampart_1m_frame.p3d";
	Boxloader_ConBase="Land_Boxloader_Fort_Wall_Flat";
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "land_boxloader_rampart_1m";
	boxloader_snap_pos[] = {
		SNAP_CLASS1,
		SNAP_CLASS2
	};
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};
class land_boxloader_rampart_1m: land_boxloader_rampart_1m_frame {
	scope = 2;
	scopeCurator = 2;
	armor = 1000;
	displayName = "Rampart 1.4m";
	model = "\boxloader_fort\mdl\boxloader_fort_rampart_1m.p3d";
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "land_boxloader_rampart_1m_frame";
};
class Land_Boxloader_Ramp_2m: Land_Boxloader_Wall_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "Ramp 2m";
	model = "\boxloader_fort\mdl\boxloader_fort_ramp_2m.p3d";
	boxloader_snap = 1;
	boxloader_snap_pos[] = {
		SNAP_CLASS1,
		SNAP_CLASS2
	};
};
class Land_Boxloader_Ramp_1m: Land_Boxloader_Wall_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "Ramp 1.4m";
	model = "\boxloader_fort\mdl\boxloader_fort_ramp_1m.p3d";
	boxloader_snap = 1;
	boxloader_snap_pos[] = {
		SNAP_CLASS1,
		SNAP_CLASS2
	};
};
class Land_Boxloader_Walk_2m: Land_Boxloader_Wall_base {
	scope = 2;
	scopeCurator = 2;
	displayName = "Walkway 2m";
	model = "\boxloader_fort\mdl\boxloader_fort_walk_2m.p3d";
	boxloader_snap = 1;
	boxloader_snap_pos[] = {
		SNAP_CLASS1,
		SNAP_CLASS2B,
		{"land_boxloader_walk_2m",{{"snap1",90,0},{"snap2",90,0},{"snap3",90,0},{"snap4",90,0}}},
		{"land_boxloader_ramp_2m",{{"snap1",360,180}}},
		{"land_boxloader_ramp_1m",{{"snap1",360,180}}}
	};
};
class Land_Boxloader_Hesco_Big1: Land_Boxloader_Hesco_1 {
	armor=2000;
	displayName = "Big HESCO 2m";
	model = "\boxloader_fort\mdl\boxloader_hesco_big1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_BigFlat";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big1_Built";
};
class Land_Boxloader_Hesco_Big3: Land_Boxloader_Hesco_Big1 {
	displayName = "Big HESCO 6m";
	model = "\boxloader_fort\mdl\boxloader_hesco_big3.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big3_Built";
};
class Land_Boxloader_Hesco_Big5: Land_Boxloader_Hesco_Big1 {
	displayName = "Big HESCO 10m";
	model = "\boxloader_fort\mdl\boxloader_hesco_big5.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big5_Built";
};

class Land_Boxloader_Hesco_Small1: Land_Boxloader_Hesco_1 {
	armor=1000;
	displayName = "Small HESCO 0.5m";
	model = "\boxloader_fort\mdl\boxloader_hesco_small1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_SmallFlat";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small1_Built";
};
class Land_Boxloader_Hesco_Small6: Land_Boxloader_Hesco_Small1 {
	displayName = "Small HESCO 3m";
	model = "\boxloader_fort\mdl\boxloader_hesco_small6.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small6_Built";
};
class Land_Boxloader_Hesco_Small10: Land_Boxloader_Hesco_Small1 {
	displayName = "Small HESCO 5m";
	model = "\boxloader_fort\mdl\boxloader_hesco_small10.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small10_Built";
};

class Land_Boxloader_Hesco_1_Built: Land_Boxloader_Hesco_1 {
	boxloader_hescoFill = "Land_Boxloader_Hesco_1";
	boxloader_IsFilled = 1;
	class AnimationSources: AnimationSources {
		class Fill_Source: Fill_Source {
			initPhase = 0;
		};
		class Empty_Source: Empty_Source {
			initPhase = 1;
		};
	};
	destrType="DestructBuilding";
	scope=2;
	scopeCurator=2;
};
class Land_Boxloader_Hesco_2_Built: Land_Boxloader_Hesco_1_Built {
	displayName = "HESCO 2m";
	model = "\boxloader_fort\mdl\boxloader_hesco_2.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_2";
};
class Land_Boxloader_Hesco_3_Built: Land_Boxloader_Hesco_1_Built {
	displayName = "HESCO 3m";
	model = "\boxloader_fort\mdl\boxloader_hesco_3.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_3";

};
class Land_Boxloader_Hesco_5_Built: Land_Boxloader_Hesco_1_Built {
	displayName = "HESCO 5m";
	model = "\boxloader_fort\mdl\boxloader_hesco_5.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_5";
};

class Land_Boxloader_Hesco_Big1_Built: Land_Boxloader_Hesco_1_Built {
	armor=2000;
	displayName = "Big HESCO 2m";
	model = "\boxloader_fort\mdl\boxloader_hesco_big1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_BigFlat";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big1";
};
class Land_Boxloader_Hesco_Big3_Built: Land_Boxloader_Hesco_Big1_Built {
	displayName = "Big HESCO 6m";
	model = "\boxloader_fort\mdl\boxloader_hesco_big3.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big3";
};
class Land_Boxloader_Hesco_Big5_Built: Land_Boxloader_Hesco_Big1_Built {
	displayName = "Big HESCO 10m";
	model = "\boxloader_fort\mdl\boxloader_hesco_big5.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big5";
};
class Land_Boxloader_Hesco_Small1_built: Land_Boxloader_Hesco_1_built {
	armor=1000;
	displayName = "Small HESCO 0.5m";
	model = "\boxloader_fort\mdl\boxloader_hesco_small1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_SmallFlat";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small1";
};
class Land_Boxloader_Hesco_Small6_built: Land_Boxloader_Hesco_Small1_built {
	displayName = "Small HESCO 3m";
	model = "\boxloader_fort\mdl\boxloader_hesco_small6.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small6";
};
class Land_Boxloader_Hesco_Small10_built: Land_Boxloader_Hesco_Small1_built {
	displayName = "Small HESCO 5m";
	model = "\boxloader_fort\mdl\boxloader_hesco_small10.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small10";
};

class Land_Boxloader_Fort_iso_Green: ThingX {
	model = "\boxloader\mdl\boxloader_iso_basic.p3d";
	editorCategory="EdCat_Supplies";
	displayName = "Container Building, Packed (Green)";
	editorSubcategory="EdSubCat_BoxloaderDeprecated";
	class AnimationSources {
		class Sign_Hide_Source {
			source = "user";
			initPhase = 0;
			animPeriod = 1;
		};
	};
	scope=2;
	class EventHandlers {
		init = "[_this select 0,1] call boxloader_fort_fnc_iso";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	BoxloaderClass = "Land_Boxloader_iso_20ft";
	hiddenSelections[] = {"container","sign"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_od_co.paa","\boxloader\tex\boxloader_isostruct_black_ca.paa"};
	slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
};
class Land_Boxloader_Fort_iso_Rusty: Land_Boxloader_Fort_iso_Green {
	displayName = "Container Building, Packed (Rusty)";
	hiddenSelections[] = {"container","sign"};
	class EventHandlers {
		init = "[_this select 0,2] call boxloader_fort_fnc_iso";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_blank_co.paa","\boxloader\tex\boxloader_isostruct_white_ca.paa"};
};
class Land_Boxloader_Fort_iso_Brown: Land_Boxloader_Fort_iso_Green {
	displayName = "Container Building, Packed (Brown)";
	class EventHandlers {
		init = "[_this select 0,3] call boxloader_fort_fnc_iso";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	hiddenSelections[] = {"container","sign"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_sand_co.paa","\boxloader\tex\boxloader_isostruct_black_ca.paa"};
};
class Land_Boxloader_Fort_iso_Aid: Land_Boxloader_Fort_iso_Green {
	displayName = "Container Building, Packed (Medical)";
	class EventHandlers {
		init = "[_this select 0,0] call boxloader_fort_fnc_iso";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	hiddenSelections[] = {"container","sign"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_aid_co.paa","\boxloader\tex\boxloader_isostruct_black_ca.paa"};
};

class Land_Boxloader_Fort_Tent_Flat_Base: Land_Boxloader_Fort_Base {
	displayName = "Large Tent (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderDeprecated";
	model = "\boxloader_fort\mdl\boxloader_fort_plat_flat.p3d";
	scope = 1;
	buildClass = "Land_Boxloader_Fort_Tent_Built_Base";
	hiddenSelections[] = {"Texture"};
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_tent";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	class AnimationSources {
		class Sign_Hide {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
	};
};
class Land_Boxloader_Fort_Tent_Flat_Green: Land_Boxloader_Fort_Tent_Flat_Base {
	displayName = "Packed Large Tent (Green)";
	scope = 2;
	scopeCurator = 2;
	buildClass = "Land_Boxloader_Fort_Tent_Built_Green";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_tropic_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Flat_Brown: Land_Boxloader_Fort_Tent_Flat_Base {
	displayName = "Packed Large Tent (Brown)";
	scope = 2;
	scopeCurator = 2;
	buildClass = "Land_Boxloader_Fort_Tent_Built_brown";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_MTP_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Flat_BrownHex: Land_Boxloader_Fort_Tent_Flat_Base {
	displayName = "Packed Large Tent (Hex, Brown)";
	scope = 2;
	scopeCurator = 2;
	buildClass = "Land_Boxloader_Fort_Tent_Built_brownhex";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_brownhex_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Flat_GreenHex: Land_Boxloader_Fort_Tent_Flat_Base {
	displayName = "Packed Large Tent (Hex, Green)";
	scope = 2;
	scopeCurator = 2;
	buildClass = "Land_Boxloader_Fort_Tent_Built_greenhex";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_greenhex_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Flat_Digital: Land_Boxloader_Fort_Tent_Flat_Base {
	displayName = "Packed Large Tent (AAF)";
	scope = 2;
	scopeCurator = 2;
	buildClass = "Land_Boxloader_Fort_Tent_Built_digital";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_digital_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Flat_White: Land_Boxloader_Fort_Tent_Flat_Base {
	displayName = "Packed Large Tent (White)";
	scope = 2;
	scopeCurator = 2;
	buildClass = "Land_Boxloader_Fort_Tent_Built_white";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_white_generic_F_CO.paa"};
};
class Land_MedicalTent_01_base_F;
class Land_Boxloader_Fort_Tent_Built_Base: Land_MedicalTent_01_base_F {
	scope = 1;
	maximumLoad=0;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderDeprecated";
	buildClass = "Land_Boxloader_Fort_Tent_Flat_Base";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_tent_built";
		deleted = "if (!isNull ((_this select 0) getVariable ['tent_floor',objNull])) then {deleteVehicle ((_this select 0) getVariable ['tent_floor',objNull])}";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_tropic_F_CO.paa"};
	class AnimationSources {
		class Door_Hide {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
		class MedSign_Hide {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
		class OuterTent_Hide {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
		class InnerTent_Hide {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
		class SolarPanel1_Hide {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
		class SolarPanel2_Hide {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
	};
};
class Land_Boxloader_Fort_Tent_Built_Green: Land_Boxloader_Fort_Tent_Built_Base {
	scope = CAN_PLACE_BUILT;
	buildClass = "Land_Boxloader_Fort_Tent_Flat_Green";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_tropic_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Built_Brown: Land_Boxloader_Fort_Tent_Built_Base {
	scope = CAN_PLACE_BUILT;
	buildClass = "Land_Boxloader_Fort_Tent_Flat_Brown";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_MTP_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Built_BrownHex: Land_Boxloader_Fort_Tent_Built_Base {
	scope = CAN_PLACE_BUILT;
	buildClass = "Land_Boxloader_Fort_Tent_Flat_BrownHex";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_brownhex_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Built_GreenHex: Land_Boxloader_Fort_Tent_Built_Base {
	scope = CAN_PLACE_BUILT;
	buildClass = "Land_Boxloader_Fort_Tent_Flat_GreenHex";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_greenhex_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Built_Digital: Land_Boxloader_Fort_Tent_Built_Base {
	scope = CAN_PLACE_BUILT;
	buildClass = "Land_Boxloader_Fort_Tent_Flat_Digital";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_digital_F_CO.paa"};
};
class Land_Boxloader_Fort_Tent_Built_White: Land_Boxloader_Fort_Tent_Built_Base {
	scope = CAN_PLACE_BUILT;
	buildClass = "Land_Boxloader_Fort_Tent_Flat_White";
	hiddenSelectionsTextures[] = {"\A3\Structures_F_Orange\Humanitarian\Camps\Data\MedicalTent_01_white_generic_F_CO.paa"};
};


/*
class land_boxloader_fort_rampart_big_frame: land_boxloader_fort_plat_5 {
	scope = 1;
	scopeCurator = 1;
	displayName = "Big Rampart (Frame)";
	model = "\boxloader_fort\mdl\boxloader_fort_ground_5m_frame.p3d";
	Boxloader_ConBase="Land_Boxloader_Fort_Plat_Flat";
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_Fort_Rampart_big";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	class AnimationSources {
		class Fill_Source {
			source = "user";
			initPhase = 1;
			animPeriod = 1;
		};
		class Empty_Source {
			source = "user";
			initPhase = 0;
			animPeriod = 1;
		};
	};
};
class land_boxloader_fort_rampart_big: land_boxloader_fort_rampart_big_frame {
	scope = 2;
	scopeCurator = 2;
	armor = 1000;
	displayName = "Big Rampart";
	model = "\boxloader_fort\mdl\boxloader_fort_rampart_2m.p3d";
	boxloader_IsFilled = 1;
	boxloader_hescoFill = "Land_Boxloader_Fort_Rampart_Big_Frame";
	class AnimationSources: AnimationSources {
		class Fill_Source: Fill_Source {
			source = "user";
			initPhase = 0;
			animPeriod = 1;
		};
	};
};
*/

class Land_Boxloader_Camonet_Green_Flat: Land_Boxloader_Fort_Base {
	displayName = "Camouflage Net (Green, Packed)";
	model = "\boxloader_fort\mdl\boxloader_fort_temper_flat2.p3d";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Camonet_Green","Build TEMPER Camonet (Green)",{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Camonet_Low_Green","Build Camonet Low (Green)",{"corner1","corner2","corner3","corner4"}}
	};
	scope = 2;
	scopeCurator = 2;
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_canvas_green_co.paa"};
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	boxloader_snap = 1;
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	boxloader_tools = 1;
	boxloader_fill = 0;
	class AnimationSources {
		class loaded {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
	};
	class VehicleTransport {
		class Cargo {
			dimensions[]				= {"VTV_Cargo_Base","VTV_Cargo_Corner"};
			parachuteClass				= "B_Parachute_02_F";
			canBeTransported            = 1;
			parachuteHeightLimit		= 99999;
		};
	};
};
class Land_Boxloader_Camonet_Tan_Flat: Land_Boxloader_Camonet_Green_Flat {
	displayName = "Camouflage Net (Tan, Packed)";
	boxloader_buildables[] = {
		{"Land_Boxloader_Temper_Camonet_Tan","Build TEMPER Camonet (Tan)",{"corner1","corner2","corner3","corner4"}},
		{"Land_Boxloader_Camonet_Low_Tan","Build Camonet Low (Tan)",{"corner1","corner2","corner3","corner4"}}
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_canvas_tan_co.paa"};
};

class land_boxloader_camonet_low_green: land_boxloader_temper_camonet_green {
	model="\boxloader_fort\mdl\boxloader_fort_camonet_low.p3d";
	boxloader_snap_pos[] = {
		{"land_boxloader_temper_camonet_green",{{"tent_end1",360,0},{"tent_end2",360,0},{"tent_end3",360,0},{"tent_end4",360,0}}}
	};
	scope = 2;
	scopeCurator = 2;
	displayName = "Camonet Low (Green)";
	Boxloader_ConBase = "Land_Boxloader_Camonet_Green_Flat";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_camonet_green_ca.paa"};
};
class land_boxloader_camonet_low_tan: land_boxloader_temper_camonet_tan {
	displayName = "Camonet Low (Tan)";
	Boxloader_ConBase = "Land_Boxloader_Camonet_Tan_Flat";
	model="\boxloader_fort\mdl\boxloader_fort_camonet_low.p3d";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_camonet_tan_ca.paa"};
};

class Land_Boxloader_Fort_Helipad_Tarp_Flat: Land_Boxloader_Fort_Base {
	displayName = "Helipad Mat (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	model = "\boxloader_fort\mdl\boxloader_fort_roof_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	boxloader_snap = 1;
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	boxloader_tools = 1;
	boxloader_fill = 0;
	boxloader_buildables[] = {
		{"Land_Boxloader_Fort_Helipad_Tarp","Build 15m Helipad Tarp",
			{"corner1","corner2","corner3","corner4"}
		},
		{"Land_Boxloader_Fort_Helipad_Tarp_Mini","Build 5m Helipad Tarp",
			{"corner1","corner2","corner3","corner4"}
		},
		{"Land_Boxloader_Fort_Helipad_Tarp_Mid","Build 10m Helipad Tarp",
			{"corner1","corner2","corner3","corner4"}
		}
	};
	class AnimationSources {
		class Chalk_Line {
			source = "user";
			initPhase = 0;
			animPeriod = 0;
		};
	};
	hiddenSelections[] = {"Texture"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_canvas_black_co.paa"};
};


class Land_Boxloader_Fort_Helipad_Tarp: Land_Boxloader_Fort_Base {
	armor=800;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	boxloader_snap = 1;
	boxloader_snap_pos[] = {
		SNAP_CLASS1
	};
	Boxloader_ConBase="Land_Boxloader_Fort_Helipad_Tarp_Flat";
	destrType="DestructBuilding";
	scope=2;
	scopeCurator=2;
	displayName = "Helipad Mat 15m";
	model = "\boxloader_fort\mdl\boxloader_fort_helipad_tarp.p3d";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_helipad; _this call boxloader_fort_fnc_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		Dragged3DEN = "[_this select 0] call boxloader_fort_fnc_snap_editor";
	};
};
class Land_Boxloader_Fort_Helipad_Tarp_Mini: Land_Boxloader_Fort_Helipad_Tarp {
	displayName = "Helipad Mat 5m";
	model = "\boxloader_fort\mdl\boxloader_fort_helipad_tarp_mini.p3d";
};
class Land_Boxloader_Fort_Helipad_Tarp_Mid: Land_Boxloader_Fort_Helipad_Tarp {
	displayName = "Helipad Mat 10m";
	model = "\boxloader_fort\mdl\boxloader_fort_helipad_tarp_mid.p3d";
};

#define CAN_PLACE_BUILT 1
class Land_Boxloader_Hesco_Flat: HBarrier_base_F {
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
class Land_Boxloader_Fort_Roof_Flat: HBarrier_base_F {
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

class Land_Boxloader_Fort_Plat_Flat: HBarrier_base_F {
	displayName = "Wood Platform (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	model = "\boxloader_fort\mdl\boxloader_fort_roof_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	
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
class Land_Boxloader_Fort_Plat_5: HBarrier_base_F {
	armor=800;
	scope=2;
	scopeCurator=2;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	destrType="DestructBuilding";
	displayName = "Bunker Platform 5x5";
	model = "\boxloader_fort\mdl\boxloader_fort_plat_5m.p3d";
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	Boxloader_ConBase="Land_Boxloader_Fort_Plat_Flat";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};
class Land_Boxloader_Fort_Plat_3: Land_Boxloader_Fort_plat_5 {
	displayName = "Bunker Platform 3x3";
	model = "\boxloader_fort\mdl\boxloader_fort_plat_3m.p3d";
	
};
class Land_Boxloader_Fort_Ground_5_frame: Land_Boxloader_Fort_Plat_5 {
	scope = 1;
	scopeCurator = 1;
	displayName = "Earth Foundation 5m (Frame)";
	model = "\boxloader_fort\mdl\boxloader_fort_ground_5m_frame.p3d";
	Boxloader_ConBase="Land_Boxloader_Fort_Plat_Flat";
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_Fort_Ground_5";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_wall_fill";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};
class land_boxloader_fort_ground_5_berm_frame: land_boxloader_Fort_ground_5_frame {
	displayName = "Earth Berm 5m (Frame)";
	model = "\boxloader_fort\mdl\boxloader_fort_ground_5m_berm_frame.p3d";
	Boxloader_ConBase="Land_Boxloader_Fort_Plat_Flat";
	boxloader_IsFilled = 0;
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
class land_boxloader_fort_ground_5_berm: land_boxloader_fort_ground_5 {
	displayName = "Earth Berm 5m";
	boxloader_hescoFill = "Land_Boxloader_Fort_Ground_5_berm_frame";
	model = "\boxloader_fort\mdl\boxloader_fort_ground_5m_berm.p3d";
};
class Land_Boxloader_Fort_Wire_Flat: HBarrier_base_F {
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
class Land_Boxloader_Fort_Wire_5m: HBarrier_base_F {
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
class Land_Boxloader_Sandbag_Pile: HBarrier_base_F {
	displayName = "Sandbags";
	armor = 500;
	scope = 2;
	destrType="DestructBuilding";
	scopeCurator = 2;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
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

class Land_Boxloader_Sandbag_Fence: HBarrier_base_F {
	displayName = "Sandbag Fence";
	armor = 1000;
	scope = 2;
	scopeCurator = 2;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	model = "\boxloader_fort\mdl\boxloader_sandbag_fence.p3d";
	Boxloader_ConBase="Land_Boxloader_Sandbag_Pile";
	destrType="DestructBuilding";
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
class Land_Boxloader_Sandbag_Wall: Land_boxloader_Sandbag_Fence {
	displayName = "Sandbag Wall";
	model = "\boxloader_fort\mdl\boxloader_sandbag_wall.p3d";
};

	
class Land_Boxloader_Fort_Wall_Flat: HBarrier_base_F {
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
	boxloader_buildables[] = {
		{"Land_Boxloader_Wall_2m","Build Wall 2m"},
		{"Land_Boxloader_Wall_1m","Build Wall 1.4m"},
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

class Land_Boxloader_Wall_2m: HBarrier_base_F {
	armor = 300;
	scope = 2;
	scopeCurator = 2;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	destrType="DestructBuilding";
	displayName = "Wall 2m";
	model = "\boxloader_fort\mdl\boxloader_fort_wall_2m.p3d";
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	Boxloader_ConBase="Land_Boxloader_Fort_Wall_Flat";
	class EventHandlers {
		init = "_this call boxloader_fort_fnc_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};
class Land_Boxloader_Wall_1m: Land_Boxloader_Wall_2m {
	displayName = "Wall 1.4m";
	model = "\boxloader_fort\mdl\boxloader_fort_wall_1m.p3d";
};

class land_boxloader_rampart_1m_frame: land_boxloader_wall_2m {
	scope = 1;
	scopeCurator = 1;
	displayName = "Rampart 1.4m (Frame)";
	model = "\boxloader_fort\mdl\boxloader_fort_rampart_1m_frame.p3d";
	Boxloader_ConBase="Land_Boxloader_Fort_Wall_Flat";
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "land_boxloader_rampart_1m";
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
class Land_Boxloader_Ramp_2m: Land_Boxloader_Wall_2m {
	displayName = "Ramp 2m";
	model = "\boxloader_fort\mdl\boxloader_fort_ramp_2m.p3d";
};
class Land_Boxloader_Ramp_1m: Land_Boxloader_Wall_2m {
	displayName = "Ramp 1.4m";
	model = "\boxloader_fort\mdl\boxloader_fort_ramp_1m.p3d";
};
class Land_Boxloader_Walk_2m: Land_Boxloader_Wall_2m {
	displayName = "Walkway 2m";
	model = "\boxloader_fort\mdl\boxloader_fort_walk_2m.p3d";
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
	editorSubcategory="EdSubCat_BoxloaderFort";
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

class Land_Boxloader_Fort_Tent_Flat_Base: HBarrier_base_F {
	displayName = "Large Tent (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
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
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
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
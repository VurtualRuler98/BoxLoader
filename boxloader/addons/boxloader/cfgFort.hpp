#define CAN_PLACE_BUILT 1
class Land_Boxloader_Hesco_Flat: HBarrier_base_F {
	displayName = "Boxloader HESCO (Packed)";
	editorCategory="EdCat_Supplies";
	model = "\boxloader\mdl\boxloader_hesco_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	editorSubcategory="EdSubCat_BoxloaderFort";
	class EventHandlers {
		init = "[_this select 0,0] call boxloader_fnc_hesco";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};

class Land_Boxloader_Hesco_BigFlat: Land_Boxloader_Hesco_Flat {
	displayName = "Boxloader Big HESCO (Packed)";
	model = "\boxloader\mdl\boxloader_hesco_bigflat.p3d";
	class EventHandlers {
		init = "[_this select 0,1] call boxloader_fnc_hesco";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
}
class Land_Boxloader_Hesco_SmallFlat: Land_Boxloader_Hesco_Flat {
	displayName = "Boxloader Small HESCO (Packed)";
	model = "\boxloader\mdl\boxloader_hesco_smallflat.p3d";
	class EventHandlers {
		init = "[_this select 0,2] call boxloader_fnc_hesco";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
}



class Land_Boxloader_Hesco_1: Land_Boxloader_Hesco_Flat {
	displayName = "Boxloader HESCO 1m";
	model = "\boxloader\mdl\boxloader_hesco_1.p3d";
	scope = CAN_PLACE_BUILT;
	scopeCurator = CAN_PLACE_BUILT;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	boxloader_IsFilled = 0;
	boxloader_hescoFill = "Land_Boxloader_Hesco_1_Built";
	class EventHandlers {
		init = "_this call boxloader_fnc_hesco_built";
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
class Land_Boxloader_Hesco_3: Land_Boxloader_Hesco_1 {
	displayName = "Boxloader HESCO 3m";
	model = "\boxloader\mdl\boxloader_hesco_3.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_3_Built";
};
class Land_Boxloader_Hesco_5: Land_Boxloader_Hesco_1 {
	displayName = "Boxloader HESCO 5m";
	model = "\boxloader\mdl\boxloader_hesco_5.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_5_Built";
};
class Land_Boxloader_Fort_Roof_Flat: HBarrier_base_F {
	displayName = "Boxloader Bunker Roof (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	model = "\boxloader\mdl\boxloader_fort_roof_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	Boxloader_ConBase="Land_Boxloader_Fort_Roof";
	Boxloader_ConName="Build bunker roof";
	class EventHandlers {
		init = "_this call boxloader_fnc_fort_roof";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};
class Land_Boxloader_Fort_Roof: Land_Boxloader_Fort_Roof_Flat {
	armor=2000;
	destrType="DestructBuilding";
	displayName = "Boxloader Bunker Roof";
	model = "\boxloader\mdl\boxloader_fort_roof.p3d";
	scope=CAN_PLACE_BUILT;
	scopeCurator=CAN_PLACE_BUILT;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	Boxloader_ConBase="Land_Boxloader_Fort_Roof_Flat";
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
		init = "_this call boxloader_fnc_fort_roof_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};

class Land_Boxloader_Fort_Plat_Flat: HBarrier_base_F {
	displayName = "Boxloader Wood Platform (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	model = "\boxloader\mdl\boxloader_fort_roof_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	class EventHandlers {
		init = "_this call boxloader_fnc_fort_plat";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	class AnimationSources {
		class Sign_Hide {
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
	scope=CAN_PLACE_BUILT;
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFortBuilt";
	destrType="DestructBuilding";
	displayName = "Boxloader Bunker Platform 5x5";
	model = "\boxloader\mdl\boxloader_fort_plat_5m.p3d";
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	Boxloader_ConBase="Land_Boxloader_Fort_Plat_Flat";
	class EventHandlers {
		init = "_this call boxloader_fnc_fort_plat_built";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
};
class Land_Boxloader_Fort_Plat_3: Land_Boxloader_Fort_plat_5 {
	displayName = "Boxloader Bunker Platform 3x3";
	model = "\boxloader\mdl\boxloader_fort_plat_3m.p3d";
};
class Land_Boxloader_Hesco_Big1: Land_Boxloader_Hesco_1 {
	armor=2000;
	displayName = "Boxloader Big HESCO 2m";
	model = "\boxloader\mdl\boxloader_hesco_big1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_BigFlat";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big1_Built";
};
class Land_Boxloader_Hesco_Big3: Land_Boxloader_Hesco_Big1 {
	displayName = "Boxloader Big HESCO 6m";
	model = "\boxloader\mdl\boxloader_hesco_big3.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big3_Built";
};
class Land_Boxloader_Hesco_Big5: Land_Boxloader_Hesco_Big1 {
	displayName = "Boxloader Big HESCO 10m";
	model = "\boxloader\mdl\boxloader_hesco_big5.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big5_Built";
};

class Land_Boxloader_Hesco_Small1: Land_Boxloader_Hesco_1 {
	armor=1000;
	displayName = "Boxloader Small HESCO 0.5m";
	model = "\boxloader\mdl\boxloader_hesco_small1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_SmallFlat";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small1_Built";
};
class Land_Boxloader_Hesco_Small6: Land_Boxloader_Hesco_Small1 {
	displayName = "Boxloader Small HESCO 3m";
	model = "\boxloader\mdl\boxloader_hesco_small6.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small6_Built";
};
class Land_Boxloader_Hesco_Small10: Land_Boxloader_Hesco_Small1 {
	displayName = "Boxloader Small HESCO 5m";
	model = "\boxloader\mdl\boxloader_hesco_small10.p3d";
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
};
class Land_Boxloader_Hesco_3_Built: Land_Boxloader_Hesco_1_Built {
	displayName = "Boxloader HESCO 3m";
	model = "\boxloader\mdl\boxloader_hesco_3.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_3";

};
class Land_Boxloader_Hesco_5_Built: Land_Boxloader_Hesco_1_Built {
	displayName = "Boxloader HESCO 5m";
	model = "\boxloader\mdl\boxloader_hesco_5.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_5";
};

class Land_Boxloader_Hesco_Big1_Built: Land_Boxloader_Hesco_1_Built {
	armor=2000;
	displayName = "Boxloader Big HESCO 2m";
	model = "\boxloader\mdl\boxloader_hesco_big1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_BigFlat";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big1";
};
class Land_Boxloader_Hesco_Big3_Built: Land_Boxloader_Hesco_Big1_Built {
	displayName = "Boxloader Big HESCO 6m";
	model = "\boxloader\mdl\boxloader_hesco_big3.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big3";
};
class Land_Boxloader_Hesco_Big5_Built: Land_Boxloader_Hesco_Big1_Built {
	displayName = "Boxloader Big HESCO 10m";
	model = "\boxloader\mdl\boxloader_hesco_big5.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_big5";
};
class Land_Boxloader_Hesco_Small1_built: Land_Boxloader_Hesco_1_built {
	armor=1000;
	displayName = "Boxloader Small HESCO 0.5m";
	model = "\boxloader\mdl\boxloader_hesco_small1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_SmallFlat";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small1";
};
class Land_Boxloader_Hesco_Small6_built: Land_Boxloader_Hesco_Small1_built {
	displayName = "Boxloader Small HESCO 3m";
	model = "\boxloader\mdl\boxloader_hesco_small6.p3d";
	boxloader_hescoFill = "Land_Boxloader_Hesco_small6";
};
class Land_Boxloader_Hesco_Small10_built: Land_Boxloader_Hesco_Small1_built {
	displayName = "Boxloader Small HESCO 5m";
	model = "\boxloader\mdl\boxloader_hesco_small10.p3d";
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
		init = "[_this select 0,1] call boxloader_fnc_fort_iso";
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
		init = "[_this select 0,2] call boxloader_fnc_fort_iso";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_blank_co.paa","\boxloader\tex\boxloader_isostruct_white_ca.paa"};
};
class Land_Boxloader_Fort_iso_Brown: Land_Boxloader_Fort_iso_Green {
	displayName = "Container Building, Packed (Brown)";
	class EventHandlers {
		init = "[_this select 0,3] call boxloader_fnc_fort_iso";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	hiddenSelections[] = {"container","sign"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_sand_co.paa","\boxloader\tex\boxloader_isostruct_black_ca.paa"};
};
class Land_Boxloader_Fort_iso_Aid: Land_Boxloader_Fort_iso_Green {
	displayName = "Container Building, Packed (Medical)";
	class EventHandlers {
		init = "[_this select 0,0] call boxloader_fnc_fort_iso";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	hiddenSelections[] = {"container","sign"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_aid_co.paa","\boxloader\tex\boxloader_isostruct_black_ca.paa"};
};

class Land_Boxloader_Fort_Tent_Flat_Base: HBarrier_base_F {
	displayName = "Boxloader Large Tent (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_BoxloaderFort";
	model = "\boxloader\mdl\boxloader_fort_plat_flat.p3d";
	scope = 1;
	buildClass = "Land_Boxloader_Fort_Tent_Built_Base";
	hiddenSelections[] = {"Texture"};
	class EventHandlers {
		init = "_this call boxloader_fnc_fort_tent";
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
		init = "_this call boxloader_fnc_fort_tent_built";
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
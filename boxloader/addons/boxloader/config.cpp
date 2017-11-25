class CfgPatches {
	class boxloader {
		units[] = {
			"Land_Boxloader_Pallet_1","Land_Boxloader_Pallet_1_ed",
			"Land_Boxloader_Pallet_2","Land_Boxloader_Pallet_2_ed",
			"Land_Boxloader_Pallet_3","Land_Boxloader_Pallet_3_ed",
			"Land_Boxloader_iso_20ft","Land_Boxloader_iso20_ed",
			"Land_Boxloader_iso_tricon","Land_Boxloader_iso_tricon_ed",
			"Land_Boxloader_Pallet_5","Land_Boxloader_Pallet_5_ed",
			"Land_Boxloader_Crate_1",
			"Land_Boxloader_Crate_Roofrack",
			"Land_Boxloader_iso_20ft_black_ed",
			"Land_Boxloader_iso_20ft_aid_ed",
			"Land_Boxloader_iso_20ft_seabee_ed",
			"Land_Boxloader_iso_tricon_black_ed",
			"Land_Boxloader_iso_tricon_aid_ed",
			"Land_Boxloader_iso_tricon_seabee_ed",
			"Land_Boxloader_iso_20ft_black",
			"Land_Boxloader_iso_20ft_aid",
			"Land_Boxloader_iso_20ft_seabee",
			"Land_Boxloader_iso_tricon_black",
			"Land_Boxloader_iso_tricon_aid",
			"Land_Boxloader_iso_tricon_seabee",
			"Land_Boxloader_Case_Green",
			"Land_Boxloader_Case_Aid",
			"Land_Boxloader_Case_Tan",
			"Land_Boxloader_Hesco_Flat",
			"Land_Boxloader_Hesco_1",
			"Land_Boxloader_Hesco_3",
			"Land_Boxloader_Hesco_5",
			"Land_Boxloader_Hesco_BigFlat"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main"};
	};
};
class CfgFunctions {
	class boxloader {
		tag = "boxloader";
		class boxloaderFunctions {
			file = "\boxloader\functions";
			class init {postInit = 1;};
			class load {};
			class addaction {};
			class pallet_create {};
			class pallet_init {};
			class pallet_addmem {};
			class init_racks {preInit = 1;};
			class hesco {};
			class hesco_built {};
			
			class racks_setup {};
			class racks_add {};
			class racks_validate {};
			class racks_switch {};
			class hide {};
			class hide_recursion {};
		};
	};
};
class CfgVehicles {
	class StaticWeapon;
	class Thing;
	class ThingX;
	class Reammobox_F;
	class HBarrier_base_F;
	class Land_Cargo20_military_green_F;
	class Boxloader_Pallet_base_ed: Thing {
		editorCategory="EdCat_Supplies";
		editorSubcategory="EdSubCat_Boxloader";
		icon = "iconObject_1x1";
		scope=1;
		side=3;
		class EventHandlers {
		init = "_this call boxloader_fnc_pallet_create";	
		};
	};
	class Land_Boxloader_Hesco_Flat: HBarrier_base_F {
		displayName = "Boxloader HESCO (Packed)";
		editorCategory="EdCat_Supplies";
		editorSubcategory="EdSubCat_Boxloader";
		model = "\boxloader\mdl\boxloader_hesco_flat.p3d";
		scope = 2;
		scopeCurator = 2;
		class EventHandlers {
			init = "[_this select 0,false] call boxloader_fnc_hesco";
		};
	};
	class Land_Boxloader_Hesco_BigFlat: Land_Boxloader_Hesco_Flat {
		displayName = "Boxloader Big HESCO (Packed)";
		model = "\boxloader\mdl\boxloader_hesco_bigflat.p3d";
		class EventHandlers {
			init = "[_this select 0,true] call boxloader_fnc_hesco";
		};
	}
	class Land_Boxloader_Hesco_1: Land_Boxloader_Hesco_Flat {
		displayName = "Boxloader HESCO 1m";
		model = "\boxloader\mdl\boxloader_hesco_1.p3d";
		class EventHandlers {
			init = "_this call boxloader_fnc_hesco_built";
		};
		scope = 1;
		scopeCurator = 1;
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
		//armor=300;
		//destrType="DestructTent";
		hiddenSelections[] = {"fill"};
		hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_hesco_dirt_co.paa"};
	};
	class Land_Boxloader_Hesco_3: Land_Boxloader_Hesco_1 {
		displayName = "Boxloader HESCO 3m";
		model = "\boxloader\mdl\boxloader_hesco_3.p3d";
	};
	class Land_Boxloader_Hesco_5: Land_Boxloader_Hesco_1 {
		displayName = "Boxloader HESCO 5m";
		model = "\boxloader\mdl\boxloader_hesco_5.p3d";
	};
	class Land_Boxloader_Hesco_Big1: Land_Boxloader_Hesco_1 {
		displayName = "Boxloader Big HESCO 2m";
		model = "\boxloader\mdl\boxloader_hesco_big1.p3d";
		Boxloader_ConBase="Land_Boxloader_Hesco_BigFlat";
	};
	class Land_Boxloader_Hesco_Big3: Land_Boxloader_Hesco_Big1 {
		displayName = "Boxloader Big HESCO 6m";
		model = "\boxloader\mdl\boxloader_hesco_big3.p3d";
	};
	class Land_Boxloader_Hesco_Big5: Land_Boxloader_Hesco_Big1 {
		displayName = "Boxloader Big HESCO 10m";
		model = "\boxloader\mdl\boxloader_hesco_big5.p3d";
	};
	class Land_Boxloader_Crate_1: Reammobox_F {
		ace_dragging_dragPosition[] = {0,1.5,0};
		class VehicleTransport {
			class Cargo {
				parachuteClass              = "B_Parachute_02_F";
				parachuteHeightLimit        = 40;
				canBeTransported            = 1;
				dimensions[]                = {"BBox_Base0", "BBox_Corner_1m"};
			};
		   class Carrier {
			};
		};
		slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		editorCategory="EdCat_Supplies";
		editorSubcategory="EdSubCat_Boxloader";
		displayName = "Boxloader Cargo Box (US Pallet)";
		model = "\boxloader\mdl\boxloader_crate1.p3d";
		icon = "iconObject_1x1";
		scope=2;
		scopeCurator=2;
		side=3;
		maximumLoad=5000;
		ace_cargo_size = 5;
		ace_cargo_canLoad = 1;
		ace_cargo_space = 4;
		ace_Cargo_hasCargo = 1;
	};
	class Land_Boxloader_Case_Green: Reammobox_F {
		ace_dragging_dragPosition[] = {0,1.5,0};
		class VehicleTransport {
			class Cargo {
				parachuteClass              = "B_Parachute_02_F";
				parachuteHeightLimit        = 5;
				canBeTransported            = 1;
			};
		};
		editorCategory="EdCat_Supplies";
		editorSubcategory="EdSubCat_Boxloader";
		displayName = "Military Case (Green)";
		model = "\boxloader\mdl\boxloader_case.p3d";
		icon = "iconObject_1x1";
		scope=2;
		scopeCurator=2;
		side=3;
		maximumLoad=5000;
		ace_cargo_size = 4;
		ace_cargo_canLoad = 1;
		ace_cargo_space = 3;
		ace_Cargo_hasCargo = 1;
		hiddenSelections[] = {"case"};
		hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_case_green_co.paa"};
	};
	class Land_Boxloader_Case_Aid: Land_Boxloader_Case_Green {
		displayName = "Military Case (Red Crystal)";
		hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_case_aid_co.paa"};
	};
	class Land_Boxloader_Case_Tan: Land_Boxloader_Case_Green {
		displayName = "Military Case (Tan)";
		hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_case_tan_co.paa"};
	};
	class Land_Boxloader_Crate_Roofrack: ThingX {
		ace_dragging_dragPosition[] = {0,1.5,0};
		class VehicleTransport {
			class Cargo {
				parachuteClass              = "B_Parachute_02_F";
				parachuteHeightLimit        = 40;
				canBeTransported            = 1;
				dimensions[]                = {"BBox_Base0", "BBox_Corner_1m"};
			};
		   class Carrier {
			};
		};
		slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		editorCategory="EdCat_Supplies";
		editorSubcategory="EdSubCat_Boxloader";
		displayName = "Boxloader roof rack Box";
		model = "\boxloader\mdl\boxloader_crate1.p3d";
		icon = "iconObject_1x1";
		scope=2;
		scopeCurator=2;
		side=3;
		ace_cargo_size = 5;
		ace_cargo_canLoad = 1;
		ace_Cargo_hasCargo = 0;
	};
	class Boxloader_Pallet_base: StaticWeapon {
		icon = "iconObject_1x1";
		scope=1;
		side=4;
		accuracy = 0.001;
		camouflage = 10;
		armor = 2000;
		destrType = "DestructNo";
		simulation = "tankX";
		nameSound = "";
		class EventHandlers {
			init = "_this call boxloader_fnc_pallet_init";	
			handleDamage = "0";
		};
		class TransportItem {};
		class Turrets {};
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.5,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_canCarry = 0;
		ace_cargo_canLoad = 0;
		class VehicleTransport {
			class Cargo {
				parachuteClass              = "B_Parachute_02_F";
				canBeTransported            = 1;
				parachuteHeightLimit		= 15;
				dimensions[]                = {"BBox_Base0", "BBox_Corner_1m"};
			};
		   class Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner_1m"};
				maxLoadMass                 = 10000;
				cargoAlignment[]            = {"front", "left"};
				cargoSpacing[]              = {0, 0, 0};
				exits[]                     = {"BBox_Base1"};
				unloadingInterval           = 2;
				loadingDistance             = 1;
				loadingAngle                = 60;
				disableHeightLimit          = 0;
				parachuteClassDefault       = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 10000;
			};
		};
		slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
	};
	class Land_Boxloader_membase_truck: Boxloader_Pallet_Base {
		class VehicleTransport: VehicleTransport {
			class Cargo {
				canBeTransported            = 0;
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoSpacing[]              = {0, 0, 0};
				cargoAlignment[]            = {"front","left"};
				exits[]						= {"BBox_Exit"};
				maxLoadMass                 = 100000;
				disableHeightLimit			= 1;
			};
		};
		slingLoadCargoMemoryPoints[] = {};
	};
	class Land_Boxloader_Prowler_Net: Land_Boxloader_membase_truck {
		model = "\boxloader\mdl\boxloader_prowler_net.p3d";
	};
	class Boxloader_Bucket: Land_Boxloader_membase_truck {
		model = "\boxloader\mdl\boxloader_bucket.p3d";
	};
	class Land_Boxloader_Prowler_Roofnet: Land_Boxloader_membase_truck {
		model = "\boxloader\mdl\boxloader_prowler_roofnet.p3d";
	};
	class Land_Boxloader_Roofrack_1: Land_Boxloader_membase_truck {
		model = "\boxloader\mdl\boxloader_roofrack1.p3d";
	};
	#include "cfgPallets.hpp"
	#include "cfgMem.hpp"
};
class CfgEditorSubcategories {
	class EdSubCat_Boxloader{
		displayName = "Boxloader";
	};
	class EdSubCat_BoxloaderCon{
		displayName = "Boxloader Containers";
	};
};
class CfgPatches {
	class boxloader {
		units[] = {
			"Land_Boxloader_Pallet_1","Land_Boxloader_Pallet_1_ed",
			"Land_Boxloader_Pallet_2","Land_Boxloader_Pallet_2_ed",
			"Land_Boxloader_Pallet_3","Land_Boxloader_Pallet_3_ed",
			"Land_Boxloader_iso20","Land_Boxloader_iso20_ed",
			"Land_Boxloader_Pallet_4","Land_Boxloader_Pallet_4_ed",
			"Land_Boxloader_Pallet_5","Land_Boxloader_Pallet_5_ed",
			"Land_Boxloader_Crate_1"
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
		class init {postInit = 1};
		class load {};
		class addaction {};
		class pallet_create {};
		class pallet_init {};
		class pallet_addmem {};
		class init_racks {preInit = 1};
		
		
		class rack_quad {}; class rack_quad_switch {};
		class rack_idap {};
		class rack_offroad {}; class rack_offroad_switch {};
		class rack_hemtt {}; class rack_hemtt_switch {};
		class rack_kamaz {}; class rack_kamaz_switch {};
		class rack_boxer {}; class rack_boxer_switch {};
		class rack_typhoon {}; class rack_typhoon_switch {};
		class rack_zodiac {};
		class rack_motorboat {};
		class rack_huron {}; class rack_huron_switch {};
		class rack_prowler {}; class rack_prowler_switch {};
		
		
		class rack_rhsural {};
		class rack_rhsgaz {};
		
		
		class rack_cupm1152 {};
		class rack_cupm998 {};
		class rack_cuphsov {}; class rack_cuphsov_switch {};
		class rack_cupural {}; class rack_cupural_switch {};
		
		
		class rack_ifa {}; class rack_ifa_switch {};
		};
	};
};
class CfgVehicles {
	class StaticWeapon;
	class Thing;
	class Reammobox_F;
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
	class Land_Boxloader_Crate_1: Reammobox_F {
		ace_dragging_dragPosition[] = {0,1.5,0};
		class VehicleTransport {
			class Cargo {
				parachuteClass              = B_Parachute_02_F;
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
	class Boxloader_Pallet_base: StaticWeapon {
		icon = "iconObject_1x1";
		scope=1;
		side=3;
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
		animated=false;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.5,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_canCarry = 0;
		ace_cargo_canLoad = 0;
		class VehicleTransport {
			class Cargo {
				parachuteClass              = B_Parachute_02_F;
				parachuteHeightLimit        = 40;
				canBeTransported            = 1;
				dimensions[]                = {"BBox_Base0", "BBox_Corner_1m"};
			};
		   class Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner_1m"};
				disableHeightLimit          = 1;
				maxLoadMass                 = 10000;
				cargoAlignment[]            = {"front", "left"};
				cargoSpacing[]              = {0, 0, 0};
				exits[]                     = {"BBox_Base1"};
				unloadingInterval           = 2;
				loadingDistance             = 1;
				loadingAngle                = 60;
				parachuteClassDefault       = B_Parachute_02_F;
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
				maxLoadMass                 = 100000;
			};
		};
		slingLoadCargoMemoryPoints[] = {};
	};
	class Land_Boxloader_Prowler_Net: Land_Boxloader_membase_truck {
		model = "\boxloader\mdl\boxloader_prowler_net.p3d";
	};
	class Land_Boxloader_Prowler_Roofnet: Land_Boxloader_membase_truck {
		model = "\boxloader\mdl\boxloader_prowler_roofnet.p3d";
	};
	#include "cfgPallets.hpp"
	#include "cfgMem.hpp"
};
class CfgEditorSubcategories {
	class EdSubCat_Boxloader{
		displayName = "Boxloader";
	};
};
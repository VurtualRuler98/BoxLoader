class CfgPatches {
	class boxloader {
		units[] = {
			"Land_Boxloader_Pallet_1","Land_Boxloader_Pallet_1_ed",
			"Land_Boxloader_Pallet_2","Land_Boxloader_Pallet_2_ed",
			"Land_Boxloader_Pallet_3","Land_Boxloader_Pallet_3_ed",
			"Land_Boxloader_iso20","Land_Boxloader_iso20_ed",
			"Land_Boxloader_Pallet_4","Land_Boxloader_Pallet_4_ed",
			"Land_Boxloader_Pallet_5","Land_Boxloader_Pallet_5_ed",
			"Land_Boxloader_Crate_1",
			"Land_Boxloader_mem_90x40x100_100kg",
			"Land_Boxloader_mem_420x140x150_300kg",
			"Land_Boxloader_mem_200x130x200_1000kg",
			"Land_Boxloader_mem_550x240x160_9100kg",
			"Land_Boxloader_mem_470x240x160_6000kg"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
		preloadAddons[] = {"ace_interact_menu"};
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
		class quadrack {};
		class rack_van {};
		class rack_offroad {};
		class rack_offroad_switch {};
		class rack_hemtt {};
		class rack_hemtt_switch {};
		class rack_kamaz {};
		class rack_kamaz_switch {};
		class quadrack_switch {};
		class init_racks {preInit = 1};
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
				disableHeightLimit          = 0;
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
	class Land_Boxloader_Pallet_1_ed: Boxloader_Pallet_base_ed {
		displayName = "Boxloader Pallet Square";
		model = "\boxloader\mdl\boxloader_pallet1.p3d";
		scope=2;
		scopeCurator=2;
		BoxloaderClass = "Land_Boxloader_Pallet_1";
	};
	class Land_Boxloader_Pallet_2_ed: Boxloader_Pallet_base_ed {
		displayName = "Boxloader EUR-1 Pallet";
		model = "\boxloader\mdl\boxloader_pallet2.p3d";
		scope=2;
		scopeCurator=2;
		BoxloaderClass = "Land_Boxloader_Pallet_2";
	};
	class Land_Boxloader_Pallet_3_ed: Boxloader_Pallet_base_ed {
		displayName = "Boxloader Pallet US";
		model = "\boxloader\mdl\boxloader_pallet3.p3d";
		scope=2;
		scopeCurator=2;
		BoxloaderClass = "Land_Boxloader_Pallet_3";
	};
	class Land_Boxloader_iso20_ed: Land_Cargo20_military_green_F {
		editorCategory="EdCat_Supplies";
		editorSubcategory="EdSubCat_Boxloader";
		displayName = "Boxloader 20ft ISO";
		scope=2;
		scopeCurator=2;
		class EventHandlers {
		init = "[_this select 0,'Land_Boxloader_iso20',90,'container'] call boxloader_fnc_pallet_addmem";
		deleted =  "deleteVehicle ((_this select 0) getVariable['boxloader_mem',objNull])";
		};
		class VehicleTransport {
			class Cargo {
				parachuteClass              = B_Parachute_02_F;
				parachuteHeightLimit        = 40;
				canBeTransported            = 1;
			};
		};
	};
	class Land_Boxloader_Pallet_4_ed: Boxloader_Pallet_base_ed {
		displayName = "Boxloader Flatrack";
		model = "\boxloader\mdl\boxloader_pallet4.p3d";
		scope=1;
		scopeCurator=1;
		BoxloaderClass = "Land_Boxloader_Pallet_4";
	};
	class Land_Boxloader_Pallet_5_ed: Boxloader_Pallet_base_ed {
		displayName = "Boxloader 463L Master Pallet";
		model = "\boxloader\mdl\boxloader_pallet5.p3d";
		scope=2;
		scopeCurator=2;
		BoxloaderClass = "Land_Boxloader_Pallet_5";
	};
	class Land_Boxloader_Pallet_1: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_pallet1.p3d";
		displayName = "Boxloader Pallet Square";
		class VehicleTransport: VehicleTransport {
			class Carrier: Carrier {
				maxLoadMass                 = 15000; //hectograms?
			};
		};
	};

	class Land_Boxloader_Pallet_2: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_pallet2.p3d";
		displayName = "Boxloader EUR-1 Pallet";
	};
	class Land_Boxloader_Pallet_3: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_pallet3.p3d";
		displayName = "Boxloader Pallet US";
	};
	class Land_Boxloader_Pallet_4: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_pallet4.p3d";
		displayName = "Boxloader Flatrack";
		class VehicleTransport: VehicleTransport {
			class Cargo {
				canBeTransported            = 0;
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoAlignment[]            = {"left","front"};
				cargoSpacing[]              = {0.05, 0.05, 0};
				maxLoadMass                 = 480000; //randomly chosen
				disableHeightLimit          = 1;
			};
		};
		class EventHandlers: EventHandlers {
			init = "_this call boxloader_fnc_rack_init";
		};
	};
	class Land_Boxloader_Pallet_5: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_pallet5.p3d";
		displayName = "463L Master Pallet";
		ace_dragging_dragPosition[] = {0,2.5,0};
		class VehicleTransport: VehicleTransport {
			class Cargo: Cargo {
				dimensions[]                = {"BBox_Base0", "BBox_Corner"};
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoAlignment[]            = {"left","front"};
				cargoSpacing[]              = {0.05, 0.05, 0};
				maxLoadMass                 = 45000;
				disableHeightLimit          = 0;
			};
		};
	};
	class Land_Boxloader_iso20: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_mem_iso20.p3d";
		class VehicleTransport: VehicleTransport {
			class Cargo {
				canBeTransported            = 0;
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoSpacing[]              = {0.05, 0.05, 0};
				maxLoadMass                 = 280000;
			};
		};
		slingLoadCargoMemoryPoints[] = {};
	};
	class Land_Boxloader_mem_90x40x100_100kg: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_mem_90x40x100.p3d";
		class VehicleTransport: VehicleTransport {
			class Cargo {
				canBeTransported            = 0;
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoSpacing[]              = {0, 0, 0};
				maxLoadMass                 = 1000;
			};
		};
		slingLoadCargoMemoryPoints[] = {};
	};
	class Land_Boxloader_mem_420x140x150_300kg: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_mem_420x140x150.p3d";
		class VehicleTransport: VehicleTransport {
			class Cargo {
				canBeTransported            = 0;
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoSpacing[]              = {0, 0, 0};
				maxLoadMass                 = 3000;
			};
		};
		slingLoadCargoMemoryPoints[] = {};
		
	};
	class Land_Boxloader_mem_200x130x200_1000kg: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_mem_200x130x200.p3d";
		class VehicleTransport: VehicleTransport {
			class Cargo {
				canBeTransported            = 0;
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoSpacing[]              = {0, 0, 0};
				maxLoadMass                 = 10000;
			};
		};
		slingLoadCargoMemoryPoints[] = {};
	};
	class Land_Boxloader_mem_550x240x160_9100kg: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_mem_550x240x160.p3d";
		class VehicleTransport: VehicleTransport {
			class Cargo {
				canBeTransported            = 0;
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoSpacing[]              = {0, 0.1, 0};
				cargoAlignment[]            = {"front","center"};
				maxLoadMass                 = 91000;
			};
		};
		slingLoadCargoMemoryPoints[] = {};
	};
	class Land_Boxloader_mem_470x240x160_6000kg: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_mem_470x240x160.p3d";
		class VehicleTransport: VehicleTransport {
			class Cargo {
				canBeTransported            = 0;
			};
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
				cargoSpacing[]              = {0, 0.1, 0};
				cargoAlignment[]            = {"front","center"};
				maxLoadMass                 = 60000;
			};
		};
		slingLoadCargoMemoryPoints[] = {};
	};
};
class CfgEditorSubcategories {
	class EdSubCat_Boxloader{
		displayName = "Boxloader";
	};
};
class CfgPatches {
	class boxloader {
		units[] = {"Land_Boxloader_Pallet_1","Land_Boxloader_Pallet_1_ed","Land_Boxloader_Pallet_2","Land_Boxloader_Pallet_2_ed","Land_Boxloader_Pallet_3","Land_Boxloader_Pallet_3_ed"};
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
		class init {postInit = 1;};
		class load {};
		class addaction {};
		class pallet_create {};
		class pallet_init {};
		class pallet_addmem {};
		};
	};
};
class CfgVehicles {
	class StaticWeapon;
	class Thing;
	class Land_Cargo20_military_green_F;
	class Boxloader_Pallet_base_ed: Thing {
		editorCategory="EdCat_Supplies";
		editorSubcategory="EdSubCat_Boxloader";
		icon = "iconObject_1x1";
		scope=1;
		side=3;
	};
	class Boxloader_Pallet_base: StaticWeapon {
		icon = "iconObject_1x1";
		scope=1;
		side=3;
		accuracy = 1000;
		armor = 2000;
		destrType = "DestructNo";
		simulation = "tankX";
		nameSound = "";
		class EventHandlers {
		init = "_this call boxloader_fnc_pallet_init";	
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
				maxLoadMass                 = 200000;
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
	};
	class Land_Boxloader_Pallet_1_ed: Boxloader_Pallet_base_ed {
		displayName = "Boxloader Pallet Square";
		model = "\boxloader\mdl\boxloader_pallet1.p3d";
		scope=2;
		scopeCurator=2;
		class EventHandlers {
		init = "[_this select 0,'Land_Boxloader_Pallet_1'] call boxloader_fnc_pallet_create";	
		};
	};
	class Land_Boxloader_Pallet_2_ed: Boxloader_Pallet_base_ed {
		displayName = "Boxloader EUR-1 Pallet";
		model = "\boxloader\mdl\boxloader_pallet2.p3d";
		scope=2;
		scopeCurator=2;
		class EventHandlers {
		init = "[_this select 0,'Land_Boxloader_Pallet_2'] call boxloader_fnc_pallet_create";	
		};
	};
	class Land_Boxloader_Pallet_3_ed: Boxloader_Pallet_base_ed {
		displayName = "Boxloader Pallet US";
		model = "\boxloader\mdl\boxloader_pallet3.p3d";
		scope=2;
		scopeCurator=2;
		class EventHandlers {
		init = "[_this select 0,'Land_Boxloader_Pallet_3'] call boxloader_fnc_pallet_create";	
		};
	};
	class Land_Boxloader_iso20_ed: Land_Cargo20_military_green_F {
		editorCategory="EdCat_Supplies";
		editorSubcategory="EdSubCat_Boxloader";
		displayName = "Boxloader 20ft ISO";
		scope=2;
		scopeCurator=2;
		class EventHandlers {
		init = "[_this select 0,'Land_Boxloader_iso20',90] call boxloader_fnc_pallet_addmem";	
		};
	};
	class Land_Boxloader_Pallet_1: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_pallet1.p3d";
		displayName = "Boxloader Pallet Square";
	};

	class Land_Boxloader_Pallet_2: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_pallet2.p3d";
		displayName = "Boxloader EUR-1 Pallet";
	};
	class Land_Boxloader_Pallet_3: Boxloader_Pallet_Base {
		model = "\boxloader\mdl\boxloader_pallet3.p3d";
		displayName = "Boxloader Pallet US";
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
			};
		};
	};
};
class CfgEditorSubcategories {
	class EdSubCat_Boxloader{
		displayName = "Boxloader";
	};
};
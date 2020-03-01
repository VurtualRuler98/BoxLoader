class CfgPatches {
	class boxloader_retrofit {
		units[] = {
			"Land_Boxloader_Crate_Roofrack"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main","boxloader"};
	};
};
class CfgFunctions {
	class boxloaderRetrofit {
		tag = "boxloader_retrofit";
		class boxloaderFunctions {
			file = "\boxloader_retrofit\fnc";
			class preinit {};
			class init {preInit = 1;};		
			class setup {};
			class add {};
			class validate {};
			class racks_switch {};
			class truckmem_init {};
			class driveon {};
		};
	};
};
class CBA_Extended_EventHandlers_base;
class Extended_Preinit_EventHandlers {
	class Boxloader_retrofit_preinit {
		init = "call boxloader_retrofit_fnc_preinit";
	};
};
class CfgVehicles {
	class StaticWeapon;
	class ThingX;
	class Boxloader_Pallet_base: StaticWeapon {
		class VehicleTransport {
			class Cargo;
			class Carrier;
		};
		class EventHandlers;
	};
	class Land_Boxloader_membase_truck: Boxloader_Pallet_Base {};
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
		editorSubcategory="EdSubCat_BoxloaderDeprecated";
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
	#include "cfgMem.hpp"
	#include "cfgMemCup.hpp"
};

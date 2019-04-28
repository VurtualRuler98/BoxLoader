#define MACRO_UNITS_ISO20(CLASS) \
__EVAL("Land_Boxloader_iso_20ft_"+#CLASS), \
__EVAL("Land_Boxloader_iso_tricon_"+#CLASS),
//__EVAL("Land_Boxloader_iso_20ft_"+#CLASS+"_ed"), 
//__EVAL("Land_Boxloader_iso_tricon_"+#CLASS+"_ed"), 
class CfgPatches {
	class boxloader {
		units[] = {"boxloader_pallet_jack","boxloader_tool_cart"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main"};
	};
};
class CfgFunctions {
	class boxloader {
		tag = "boxloader";
		class boxloaderFunctions {
			file = "\boxloader\fnc";
			class init_player {postInit = 1;};
			class init_load {preInit = 1;};
			class preinit {};
			class load {};
			class addaction {};
			class pallet_create {};
			class pallet_init {};
			class flatrack_init {};
			class pls {};
			class init_pls {};
			class pallet_addmem {};
			

			class hide {};
			class hide_recursion {};
			
			class getmaxlift {};
			//class skid_init {};
			class driveon {};
			
			class carry {};
		};
	};
};
class CBA_Extended_EventHandlers_base;
class Extended_Preinit_EventHandlers {
	class Boxloader_preinit {
		init = "call boxloader_fnc_preinit";
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
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};

	class Boxloader_Pallet_base: StaticWeapon {
		editorForceEmpty = 1;
		crew = "C_man_1";
		editorCategory="EdCat_Supplies";
		icon = "iconObject_1x1";
		editorSubcategory="EdSubCat_Boxloader";
		scope=1;
		side=3;
		faction = "CIV_F";
		accuracy = 0.001;
		camouflage = 10;
		armor = 2000;
		destrType = "DestructNo";
		simulation = "tankX";
		nameSound = "";
		class EventHandlers {
			init = "_this call boxloader_fnc_pallet_init";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			handleDamage = "0";
		};
		class TransportItem {};
		class Turrets {};
		transportSoldier = 1;
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
	class Boxloader_Flatrack_Base: Boxloader_Pallet_Base {
		editorSubcategory="EdSubCat_BoxloaderPLS";
		class EventHandlers: EventHandlers {
			init = "_this call boxloader_fnc_flatrack_init";
		};
		class VehicleTransport: VehicleTransport {
			class Cargo: Cargo {
				dimensions[]                = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
			};
		};
	};
	class Land_Boxloader_membase_truck: Boxloader_Pallet_Base {
		ace_dragging_canDrag = 0;
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
				loadingDistance             = 0;
				loadingAngle                = 0;
			};
		};
		class EventHandlers {
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			handleDamage = "0";
		};
		slingLoadCargoMemoryPoints[] = {};
	};
	class boxloader_tool_cart: ThingX {
		scope = 2;
		editorCategory="EdCat_Supplies";
		icon = "iconObject_1x1";
		editorSubcategory="EdSubCat_Boxloader";
		model = "\A3\Structures_F_Heli\Civ\Constructions\ToolTrolley_02_F.p3d";
		displayName = "Boxloader Tool Cart";
		class EventHandlers {
		init = "(_this select 0) setVariable ['boxloader_work_vehicle',true]; (_this select 0) setVariable ['boxloader_build_tools',true]; [_this select 0,[0,1,0.5],180] call boxloader_fnc_carry";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			handleDamage = "0";
		};
	};
	class boxloader_pallet_jack: boxloader_pallet_base {
		scope = 2;
		model = "\boxloader\mdl\boxloader_palletjack.p3d";
		displayName = "Boxloader Pallet Jack";
		class VehicleTransport: VehicleTransport {
			class Cargo: Cargo {
				dimensions[] = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
			};
			class Carrier: Carrier {
				cargoAlignment[]            = {"front", "center"};
				maxLoadMass = 4000;
				cargoBayDimensions[] = {"VTV_Carrier_Base", "VTV_Carrier_Corner"};
				exits[] = {"VTV_Exit_1"};
			};
		};
		slingLoadCargoMemoryPoints[] = {};
		class EventHandlers {
		init = "[(_this select 0),'jack'] call boxloader_fnc_pallet_init; (_this select 0) setVariable ['boxloader_load_viv',true]; (_this select 0) setVariable ['boxloader_load_weight',5000]; (_this select 0) setVariable ['boxloader_load_height',0.5]; [_this select 0,[0,1,0]] call boxloader_fnc_carry";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			handleDamage = "0";
		};
	};
};
class CfgEditorSubcategories {
	class EdSubCat_Boxloader{
		displayName = "Boxloader";
	};
	class EdSubCat_BoxloaderCon{
		displayName = "Boxloader Containers";
	};
	class EdSubCat_BoxloaderPLS{
		displayName = "Boxloader Flatracks";
	};
	class EdSubCat_BoxloaderFort{
		displayName = "Boxloader Fortifications";
	};
	class EdSubCat_BoxloaderFortBuilt{
		displayName = "Boxloader Fortifications (Built)";
	};
};
#define MACRO_UNITS_ISO20(CLASS) \
__EVAL("Land_Boxloader_iso_20ft_"+#CLASS), \
__EVAL("Land_Boxloader_iso_tricon_"+#CLASS),
//__EVAL("Land_Boxloader_iso_20ft_"+#CLASS+"_ed"), 
//__EVAL("Land_Boxloader_iso_tricon_"+#CLASS+"_ed"), 
class CfgPatches {
	class boxloader_fort {
		units[] = {

			"Land_Boxloader_Sandbag_Pile","Land_Boxloader_Sandbag_Fence","Land_Boxloader_Sandbag_Wall",
			"Land_Boxloader_Fort_Wall_Flat","Land_Boxloader_Wall_2m","Land_Boxloader_Wall_1m",
			"Land_Boxloader_Ramp_2m","Land_Boxloader_Ramp_1m",
			"Land_Boxloader_Fort_Wire_Flat",
			"Land_Boxloader_Fort_Wire_5m","Land_Boxloader_Fort_Wire_3m",
			"Land_Boxloader_Walk_2m","Land_Boxloader_Rampart_1m","Land_Boxloader_Rampart_1m_frame",
			"Land_Boxloader_Hesco_Flat","Land_Boxloader_Hesco_1","Land_Boxloader_Hesco_3","Land_Boxloader_Hesco_5",
			"Land_Boxloader_Hesco_2","Land_Boxloader_Hesco_2_Built",
			"Land_Boxloader_Hesco_1_Built","Land_Boxloader_Hesco_3_Built","Land_Boxloader_Hesco_5_built",
			"Land_Boxloader_Hesco_BigFlat","Land_Boxloader_Hesco_Big1","Land_Boxloader_Hesco_Big3","Land_Boxloader_Hesco_Big5",
			"Land_Boxloader_Hesco_Big1_Built","Land_Boxloader_Hesco_Big3_Built","Land_Boxloader_Hesco_Big5_built",
			"Land_Boxloader_Hesco_SmallFlat","Land_Boxloader_Hesco_Small1","Land_Boxloader_Hesco_Small6","Land_Boxloader_Hesco_Small10",
			"Land_Boxloader_Hesco_Small1_Built","Land_Boxloader_Hesco_Small6_Built","Land_Boxloader_Hesco_Small10_built",
			"Land_Boxloader_Fort_Roof_Flat","Land_Boxloader_Fort_Roof","Land_Boxloader_Fort_Roof_Built";
			"Land_Boxloader_Fort_iso_Green",
			"Land_Boxloader_Fort_iso_Rusty",
			"Land_Boxloader_Fort_iso_Brown",
			"Land_Boxloader_Fort_iso_Aid",
			"Land_Boxloader_Fort_Plat_Flat","Land_Boxloader_Fort_Plat_3","Land_Boxloader_Fort_Plat_5",
			"Land_Boxloader_Fort_Ground_5","Land_Boxloader_Fort_Ground_5_frame",
			"Land_Boxloader_Fort_Ground_5_Berm","Land_Boxloader_Fort_Ground_5_Berm_frame",
			
			"Land_Boxloader_Fort_Tent_Flat_Green","Land_Boxloader_Fort_Tent_Built_Green",
			"Land_Boxloader_Fort_Tent_Flat_Brown","Land_Boxloader_Fort_Tent_Built_Brown",
			"Land_Boxloader_Fort_Tent_Flat_BrownHex","Land_Boxloader_Fort_Tent_Built_BrownHex",
			"Land_Boxloader_Fort_Tent_Flat_GreenHex","Land_Boxloader_Fort_Tent_Built_GreenHex",
			"Land_Boxloader_Fort_Tent_Flat_Digital","Land_Boxloader_Fort_Tent_Built_Digital",
			"Land_Boxloader_Fort_Tent_Flat_White","Land_Boxloader_Fort_Tent_Built_White"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main","boxloader"};
	};
};
class CfgFunctions {
	class boxloader_fort {
		tag = "boxloader_fort";
		class boxloaderFunctions {
			file = "\boxloader_fort\fnc";
			
			class iso {};
			class iso_built {};
			class tent {};
			class tent_built {};
			class wall {};
			class preinit {};
			class wall_fill {};
			class plat_built {};
			class buildmenu {};
			class buildcondition {};
		};
	};
};
class CBA_Extended_EventHandlers_base;
class Extended_Preinit_EventHandlers {
	class Boxloader_fort_preinit {
		init = "call boxloader_fort_fnc_preinit";
	};
};
class CfgVehicles {
	class ThingX;
	class HBarrier_base_F;
	#include "cfgFort.hpp"
};
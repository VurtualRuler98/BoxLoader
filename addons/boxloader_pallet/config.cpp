#define MACRO_UNITS_ISO20(CLASS) \
__EVAL("Land_Boxloader_iso_20ft_"+#CLASS), \
__EVAL("Land_Boxloader_iso_tricon_"+#CLASS),
//__EVAL("Land_Boxloader_iso_20ft_"+#CLASS+"_ed"), 
//__EVAL("Land_Boxloader_iso_tricon_"+#CLASS+"_ed"), 
class CfgPatches {
	class boxloader_pallet {
		units[] = {
			"Land_Boxloader_Pallet_1",//"Land_Boxloader_Pallet_1_ed",
			"Land_Boxloader_Pallet_2",//"Land_Boxloader_Pallet_2_ed",
			"Land_Boxloader_Pallet_3",//"Land_Boxloader_Pallet_3_ed",
			"Land_Boxloader_iso_20ft",//"Land_Boxloader_iso20_ed",
			"Land_Boxloader_iso_tricon",//"Land_Boxloader_iso_tricon_ed",
			"Land_Boxloader_Pallet_5",//"Land_Boxloader_Pallet_5_ed",
			
			MACRO_UNITS_ISO20(green)
			MACRO_UNITS_ISO20(sand)
			MACRO_UNITS_ISO20(black)
			MACRO_UNITS_ISO20(aid)
			MACRO_UNITS_ISO20(seabee)
			"Boxloader_Flatrack_M1077"

		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main","boxloader"};
	};
};

class CBA_Extended_EventHandlers_base;

class CfgVehicles {
	class StaticWeapon;
	class Thing;
	class Boxloader_Pallet_base_ed: Thing {};
	class Boxloader_Pallet_base: StaticWeapon {
		class VehicleTransport {
			class Cargo;
		   class Carrier;
		};
		class EventHandlers;
	};
	class Boxloader_Flatrack_Base: Boxloader_Pallet_Base {};
	class Land_Boxloader_membase_truck: Boxloader_Pallet_Base {};
	#include "cfgPallets.hpp"
};
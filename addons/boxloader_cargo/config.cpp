#define WHEEL_STRENGTH 5
#define WHEEL_DAMPER 4
#define WHEEL_SPRINGS(MASS,WHEELS,STRENGTH,DAMPER) sprungMass = MASS/WHEELS; \
springStrength = (MASS/WHEELS)*STRENGTH^2; \
springDamperRate = DAMPER*2*((MASS/WHEELS)*STRENGTH^2*(MASS/WHEELS))^0.5;
class CfgPatches {
	class boxloader_cargo {
		units[] = {
			"Land_Boxloader_Case_Green",
			"Land_Boxloader_Case_Aid",
			"Land_Boxloader_Case_Tan",
			"Land_Boxloader_Crate_1",
			"Land_Boxloader_Case_Med",
			"Boxloader_drumpallet_empty",
			"Boxloader_drumpallet_fuel",
			
			"Boxloader_Flatrack_M7FRS",
			"boxloader_ammo_west",
			"boxloader_vehicleammo_west",
			"Boxloader_sixcon_fuel",
			"Boxloader_SmallPallet_Ammo",
			"Boxloader_BigPallet_repair",
			"Boxloader_Ammo_Arsenal"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"boxloader"};
	};
};
class CBA_Extended_EventHandlers_base;
class CfgVehicles {
	class Reammobox_F;
	class Boxloader_Flatrack_Base;
	class Slingload_Base_F;
	#include "cfgAmmo.hpp"
	#include "cfgCargo.hpp"
	#include "cfgFuel.hpp"
	#include "cfgRepair.hpp"


};
class CfgPatches {
	class boxloader_ace {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"ace_repair","boxloader"}; //"ace_interact_menu"
	};
};
class cfgVehicles {
	class boxloader_flatrack_base;
	class boxloader_flatrack_m7frs: boxloader_flatrack_base {
		transportRepair = 0;
		ace_repair_canrepair = 1;
	};
	class Reammobox_F;
	class Boxloader_sixcon_fuel: Reammobox_F {
		transportFuel = 0;
		ace_refuel_fuelcargo = 3406;
	};
};
/*class CfgVehicles {
	class StaticWeapon;
	class Boxloader_Pallet_Base: StaticWeapon {
		class ACE_Actions {
			class ACE_Boxloader {
				displayName = "Boxloader";
				position = "[0,0,1.1]";
				distance = 10;
				class selectPallet {
					displayName = "Select loading target";
					condition = "(isNull (_player getVariable ['boxloader_tgt',objNull]))";
					statement = "_player setVariable ['boxloader_tgt',_target,true]";
				};
				class loadPallet {
					displayName = "Load pallet in target";
					condition = "!(isNull (_player getVariable ['boxloader_tgt',objNull])) && (((_player getVariable ['boxloader_tgt',objNull]) canVehicleCargo _target) select 0)";
					statement = "[(_player getVariable ['boxloader_tgt',objNull]),_target] call boxloader_fnc_load";
				};
				class unloadPallet {
					displayName = "Unload pallet";
					condition = "(!isNull isVehicleCargo _target)";
					statement = "objNull setVehicleCargo _target";
				};
			};
		};
	};
	class Land_Boxloader_iso20: Boxloader_Pallet_Base {
		class ACE_Actions: ACE_Actions {
			class ACE_Boxloader: ACE_Boxloader {
				position = "[0,-3,0]";
			};
		};
	};
};*/
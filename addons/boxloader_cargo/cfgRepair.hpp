class Boxloader_Flatrack_M7FRS: Boxloader_Flatrack_Base {
	scope = 2;
	maximumLoad = 1500;
	transportRepair=200000000;
	model = "\boxloader_cargo\mdl\boxloader_flatrack_m7.p3d";
	displayName = "M7 Forward Repair System";
	class VehicleTransport {
		class Cargo {
			dimensions[]                = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
			parachuteClass = "B_Parachute_02_F";
			parachuteHeightLimit = 40;
			canBeTransported = 1;
		};
	};
	class EventHandlers {
		init = "_this call boxloader_fnc_flatrack_init; (_this select 0) setVariable ['boxloader_load_weight',4500]; (_this select 0) setVariable ['boxloader_load_height',5]; (_this select 0) setVariable ['boxloader_crane_push',4500];";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		handleDamage = "0";
	};
	class TransportItems { //inventory doesn't work
		class xx_ToolKit {
			name = "ToolKit";
			count = 5;
		};
	};
	transportMaxBackpacks=16;
};
class Boxloader_BigPallet_Repair:  Slingload_Base_F {
	ace_dragging_dragPosition[] = {0,2,0};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 40;
			canBeTransported            = 1;
			dimensions[]                = {"BBox_Base0", "BBox_Corner"};
		};
	   class Carrier {
		};
	};
	slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_Boxloader";
	displayName = "463L Master Pallet (Repair)";
	model = "\boxloader_cargo\mdl\boxloader_bigpallet_repair.p3d";
	icon = "iconObject_1x1";
	scope=2;
	scopeCurator=2;
	side=3;
	maximumLoad=45000;
	ace_cargo_canLoad = 0;
	ace_Cargo_hasCargo = 0;
	transportRepair=200000;
};
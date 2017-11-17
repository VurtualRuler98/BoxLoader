
//Editor entries
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


//Gameplay pallets
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
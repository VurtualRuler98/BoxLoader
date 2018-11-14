class Boxloader_drumpallet_empty: Reammobox_F {
	ace_dragging_dragPosition[] = {0,2,0};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 40;
			canBeTransported            = 1;
			dimensions[]                = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
		};
	   class Carrier {
		};
	};
	slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_Boxloader";
	displayName = "Drum Pallet (Barrels)";
	model = "\boxloader_cargo\mdl\boxloader_fuel_drumpallet.p3d";
	icon = "iconObject_1x1";
	scope=2;
	side=3;
	maximumLoad=0;
	//transportFuel=830;
	ace_cargo_canLoad = 0;
	ace_Cargo_hasCargo = 0;
	class AnimationSources {
		class Sign_Hide {
			source = "user";
			initPhase = 1;
			animPeriod = 0.1;
		};
	};
	hiddenSelections[] = {"sign"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_flammable_ca.paa"};
};
class Boxloader_drumpallet_fuel: boxloader_drumpallet_empty {
	transportFuel=830;
	displayName = "Drum Pallet (Fuel)";
	secondaryExplosion = 4000;
	class AnimationSources {
		class Sign_Hide {
			source = "user";
			initPhase = 0;
			animPeriod = 0.1;
		};
	};
};
class Boxloader_sixcon_fuel: Reammobox_F {
	ace_dragging_dragPosition[] = {0,2,0};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 40;
			canBeTransported            = 1;
			dimensions[]                = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
		};
	   class Carrier {
		};
	};
	slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_Boxloader";
	displayName = "SIXCON (Fuel)";
	model = "\boxloader_cargo\mdl\boxloader_sixcon_dar.p3d";
	icon = "iconObject_1x1";
	scope=2;
	scopeCurator=2;
	side=3;
	maximumLoad=500;
	transportFuel=3406;
	ace_cargo_canLoad = 0;
	ace_Cargo_hasCargo = 0;
};
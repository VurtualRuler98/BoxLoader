class Boxloader_Ammo_West: Reammobox_F {
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
	displayName = "463L Master Pallet (Crates)";
	model = "\boxloader_cargo\mdl\boxloader_ammo_west.p3d";
	icon = "iconObject_1x1";
	scope=2;
	scopeCurator=2;
	side=3;
	maximumLoad=45000;
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
	hiddenSelectionsTextures[] = {"\boxloader\tex\hazmat\explosive_ca.paa"};
};

class Boxloader_SmallPallet_Ammo: Reammobox_F {
	displayName = "Pallet (Ammo)";
	transportAmmo = 300;
	secondaryExplosion = 2000;
	scope = 2;
	scopeCurator = 2;
	model = "\boxloader_cargo\mdl\boxloader_pallet_ammo_west.p3d";
	side = 3;
	maximumLoad = 10000;
	ace_cargo_hasCargo = 0;
	icon = "iconObject_1x1";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_Boxloader";
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 40;
			canBeTransported            = 1;
			dimensions[]                = {"BBox_Base", "BBox_Corner"};
		};
	   class Carrier {
		};
	};
};

class Boxloader_VehicleAmmo_West: Boxloader_Ammo_West {
	displayName = "463L Master Pallet (Vehicle Ammo)";
	transportAmmo = 1200;
	secondaryExplosion = 8000;
	class AnimationSources {
		class Sign_Hide {
			source = "user";
			initPhase = 0;
			animPeriod = 0.1;
		};
	};
};
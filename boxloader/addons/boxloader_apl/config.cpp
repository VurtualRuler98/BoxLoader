
class CfgPatches {
	class boxloader_apl {
		units[] = {
			"boxloader_ammo_west",
			"boxloader_vehicleammo_west",
			"Boxloader_sixcon_fuel"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"boxloader"};
	};
};
class CfgVehicles {
	class Reammobox_F;
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
		model = "\boxloader_apl\boxloader_ammo_west.p3d";
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
		hiddenSelectionsTextures[] = {"\boxloader_apl\Data\explosives_sign_usmc_ca.paa"};
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
		model = "\boxloader_apl\boxloader_sixcon_dar.p3d";
		icon = "iconObject_1x1";
		scope=2;
		scopeCurator=2;
		side=3;
		maximumLoad=500;
		transportFuel=3406;
		ace_cargo_canLoad = 0;
		ace_Cargo_hasCargo = 0;
	};
};
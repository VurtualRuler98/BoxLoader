class Land_Boxloader_Crate_1: Reammobox_F {
	ace_dragging_dragPosition[] = {0,1.5,0};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 40;
			canBeTransported            = 1;
			dimensions[]                = {"BBox_Base0", "BBox_Corner_1m"};
		};
	   class Carrier {
		};
	};
	slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_Boxloader";
	displayName = "Boxloader Cargo Box (US Pallet)";
	model = "\boxloader\mdl\boxloader_crate1.p3d";
	icon = "iconObject_1x1";
	scope=2;
	scopeCurator=2;
	side=3;
	maximumLoad=5000;
	ace_cargo_size = 5;
	ace_cargo_canLoad = 1;
	ace_cargo_space = 4;
	ace_Cargo_hasCargo = 1;
};
class Land_Boxloader_Case_Green: Reammobox_F {
	ace_dragging_dragPosition[] = {0,1.5,0};
	class VehicleTransport {
		class Cargo {
			parachuteClass              = "B_Parachute_02_F";
			parachuteHeightLimit        = 5;
			canBeTransported            = 1;
		};
	};
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_Boxloader";
	displayName = "Military Case (Green)";
	model = "\boxloader\mdl\boxloader_case.p3d";
	icon = "iconObject_1x1";
	scope=2;
	scopeCurator=2;
	side=3;
	maximumLoad=5000;
	ace_cargo_size = 4;
	ace_cargo_canLoad = 1;
	ace_cargo_space = 3;
	ace_Cargo_hasCargo = 1;
	hiddenSelections[] = {"case"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_case_green_co.paa"};
};
class Land_Boxloader_Case_Aid: Land_Boxloader_Case_Green {
	displayName = "Military Case (Red Crystal)";
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_case_aid_co.paa"};
};
class Land_Boxloader_Case_Tan: Land_Boxloader_Case_Green {
	displayName = "Military Case (Tan)";
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_case_tan_co.paa"};
};
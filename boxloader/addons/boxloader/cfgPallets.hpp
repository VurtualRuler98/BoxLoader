
#define MACRO_ISO20(CLASS,NAME,TEX) \
class Land_Boxloader_iso_20ft_##CLASS##_ed: Land_Boxloader_iso20_ed { \
	displayName = __EVAL("20ft ISO ("+##NAME##+")"); \
	hiddenSelectionsTextures[] = {__EVAL("\boxloader\tex\boxloader_iso_"+##TEX##+"_co.paa")}; \
	BoxloaderClass = __EVAL("Land_Boxloader_iso_20ft_"+#CLASS); \
}; \
class Land_Boxloader_iso_20ft_##CLASS##: Land_Boxloader_iso_20ft { \
	displayName = __EVAL("20ft ISO ("+##NAME##+")"); \
	hiddenSelectionsTextures[] = {__EVAL("\boxloader\tex\boxloader_iso_"+##TEX##+"_co.paa")}; \
}; \
class Land_Boxloader_iso_tricon_##CLASS##_ed: Land_Boxloader_iso_tricon_ed {\
	displayName = __EVAL("TRICON ("+##NAME##+")"); \
	hiddenSelectionsTextures[] = {__EVAL("\boxloader\tex\boxloader_iso_"+##TEX##+"_co.paa")}; \
	BoxloaderClass = __EVAL("Land_Boxloader_iso_tricon_"+#CLASS); \
}; \
class Land_Boxloader_iso_tricon_##CLASS##: Land_Boxloader_iso_tricon { \
	displayName = __EVAL("TRICON ("+##NAME##+")"); \
	hiddenSelectionsTextures[] = {__EVAL("\boxloader\tex\boxloader_iso_"+##TEX##+"_co.paa")}; \
};

//Editor entries
class Land_Boxloader_Pallet_1_ed: Boxloader_Pallet_base_ed {
	displayName = "Boxloader Pallet Square";
	model = "\boxloader\mdl\boxloader_pallet1.p3d";
	scope=1;
	BoxloaderClass = "Land_Boxloader_Pallet_1";
};
class Land_Boxloader_Pallet_2_ed: Boxloader_Pallet_base_ed {
	displayName = "Boxloader EUR-1 Pallet";
	model = "\boxloader\mdl\boxloader_pallet2.p3d";
	scope=1;
	BoxloaderClass = "Land_Boxloader_Pallet_2";
};
class Land_Boxloader_Pallet_3_ed: Boxloader_Pallet_base_ed {
	displayName = "Boxloader Pallet US";
	model = "\boxloader\mdl\boxloader_pallet3.p3d";
	scope=1;
	BoxloaderClass = "Land_Boxloader_Pallet_3";
};
class Land_Boxloader_iso20_ed: Boxloader_Pallet_base_ed {
	model = "\boxloader\mdl\boxloader_iso_basic.p3d";
	displayName = "20ft ISO (Rusty)";
	editorSubcategory="EdSubCat_BoxloaderCon";
	scope=1;
	BoxloaderClass = "Land_Boxloader_iso_20ft";
	hiddenSelections[] = {"container"};
	class AnimationSources {
			class Sign_Hide_Source {
			source = "user";
			initPhase = 1;
			animPeriod = 1;
		};
	};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_blank_co.paa"};
};
class Land_Boxloader_iso_tricon_ed: Boxloader_Pallet_base_ed {
	model = "\boxloader\mdl\boxloader_iso_tricon.p3d";
	displayName = "Tricon (Rusty)";
	editorSubcategory="EdSubCat_BoxloaderCon";
	scope=1;
	BoxloaderClass = "Land_Boxloader_iso_tricon";
	hiddenSelections[] = {"container"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_blank_co.paa"};
};




class Land_Boxloader_Pallet_5_ed: Boxloader_Pallet_base_ed {
	displayName = "Boxloader 463L Master Pallet";
	model = "\boxloader\mdl\boxloader_pallet5.p3d";
	scope=1;
	BoxloaderClass = "Land_Boxloader_Pallet_5";
};


//Gameplay pallets
class Land_Boxloader_Pallet_1: Boxloader_Pallet_Base {
	scope = 2;
	model = "\boxloader\mdl\boxloader_pallet1.p3d";
	displayName = "Boxloader Pallet Square";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			maxLoadMass                 = 15000; //hectograms?
		};
	};
};

class Land_Boxloader_Pallet_2: Boxloader_Pallet_Base {
	scope = 2;
	model = "\boxloader\mdl\boxloader_pallet2.p3d";
	displayName = "Boxloader EUR-1 Pallet";
};
class Land_Boxloader_Pallet_3: Boxloader_Pallet_Base {
	scope = 2;
	model = "\boxloader\mdl\boxloader_pallet3.p3d";
	displayName = "Boxloader Pallet US";
};
class Land_Boxloader_Flatrack: Land_Boxloader_membase_truck {
	model = "\boxloader\mdl\boxloader_pallet4.p3d";
	displayName = "Boxloader Flatrack";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
			exits[]						= {"BBox_Exit"};
			cargoAlignment[]            = {"front","center"};
			cargoSpacing[]              = {0.05, 0.05, 0};
			maxLoadMass                 = 480000; //randomly chosen
			disableHeightLimit          = 1;
		};
	};
};
class Boxloader_Flatrack_M1077: Boxloader_Flatrack_Base {
	scope = 2;
	model = "\boxloader\mdl\boxloader_flatrack.p3d";
	displayName = "M1077A1 Flatrack";
	maximumLoad = 500;
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"VTV_Carrier_Base", "VTV_Carrier_Corner"};
			exits[]						= {"VTV_Exit_1"};
			cargoAlignment[]            = {"front","center"};
			cargoSpacing[]              = {0, 0, 0};
			maxLoadMass                 = 15000; 
			disableHeightLimit          = 1;
		};
	};
	transportMaxBackpacks=4;
};
class Boxloader_Flatrack_M7FRS: Boxloader_Flatrack_Base {
	scope = 2;
	maximumLoad = 1500;
	transportRepair=200000000;
	model = "\boxloader\mdl\boxloader_flatrack_m7.p3d";
	displayName = "M7 Forward Repair System";
	class VehicleTransport {
		class Cargo {
			dimensions[]                = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
			parachuteClass = "B_Parachute_02_F";
			parachuteHeightLimit = 40;
			canBeTransported = 1;
		};
	};
	class TransportItems { //inventory doesn't work
		class xx_ToolKit {
			name = "ToolKit";
			count = 5;
		};
	};
	transportMaxBackpacks=16;
};
class Land_Boxloader_Pallet_5: Boxloader_Pallet_Base {
	scope = 2;
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
class Boxloader_Container_Base: Boxloader_Pallet_Base {
	class EventHandlers: EventHandlers {
		init = "[_this select 0,'container'] call boxloader_fnc_pallet_init";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
	};
	hiddenSelections[] = {"container"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_iso_blank_co.paa"};
	editorSubcategory="EdSubCat_BoxloaderCon";
	class VehicleTransport: VehicleTransport {
		class Cargo: Cargo {
			parachuteClass              = "B_Parachute_02_F";
			canBeTransported            = 1;
			dimensions[]                = {};
		};
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
			cargoSpacing[]              = {0.01, 0.01, 0};
			maxLoadMass                 = 280000;
			exits[]                     = {"BBox_Exit1","BBox_Exit2"};
			disableHeightLimit			= 0;
		};
	};
	class AnimationSources {
		class Door_1_Source {
			source = "user";
			initPhase = 0;
			animPeriod = 1;
			sound = "GenericDoorsSound";
		};
		class Door_2_Source: Door_1_Source {};
		class Sign_Hide_Source {
			source = "user";
			initPhase = 1;
			animPeriod = 1;
		};
	};
	class UserActions {
		class OpenDoor1 {
			displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName = "Open Door";
			position = Action_1;
			priority = 0.4;
			radius = 3;
			onlyForPlayer = false;
			condition = ((this animationPhase "Door_1L_Anim")<0.5);
			statement = (this animateSource ["Door_1_Source",1]);
		};
		class OpenDoor2: OpenDoor1 {
			position = Action_2;
			condition = ((this animationPhase "Door_2L_Anim")<0.5);
			statement = (this animateSource ["Door_2_Source",1]);
		};
		class CloseDoor1: OpenDoor1 {
			displayName = "Close Door";
			condition = ((this animationPhase "Door_1L_Anim")>0.5);
			statement = (this animateSource ["Door_1_Source",0]);
		};
		class CloseDoor2: OpenDoor2 {
			displayName = "Close Door";
			condition = ((this animationPhase "Door_2L_Anim")>0.5);
			statement = (this animateSource ["Door_2_Source",0]);
		};
	};
	ace_dragging_canDrag = 0;
};
class Land_Boxloader_iso_20ft: Boxloader_Container_Base {
	model = "\boxloader\mdl\boxloader_iso_basic.p3d";
	displayName = "20ft ISO (Rusty)";
	scope = 2;
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			maxLoadMass                 = 280000;
		};
	};
};

class Land_Boxloader_iso_tricon: Boxloader_Container_Base {
	model = "\boxloader\mdl\boxloader_iso_tricon.p3d";
	displayName = "TRICON (Rusty)";
	scope = 2;
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			maxLoadMass                 = 56000;
		};
	};
	class UserActions {
		class OpenDoor1 {
			displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName = "Open Door";
			position = Action_1;
			priority = 0.4;
			radius = 3;
			onlyForPlayer = false;
			condition = ((this animationPhase "Door_1L_Anim")<0.5);
			statement = (this animateSource ["Door_1_Source",1]);
		};
		class CloseDoor1: OpenDoor1 {
			displayName = "Close Door";
			condition = ((this animationPhase "Door_1L_Anim")>0.5);
			statement = (this animateSource ["Door_1_Source",0]);
		};
	};
};
MACRO_ISO20(green,"Green","od");
MACRO_ISO20(sand,"Sand","sand");
MACRO_ISO20(black,"Black","black");
MACRO_ISO20(aid,"Red Crystal","aid");
MACRO_ISO20(seabee,"Equipment","seabee");


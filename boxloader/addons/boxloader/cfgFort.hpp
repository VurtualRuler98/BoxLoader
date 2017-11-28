class Land_Boxloader_Hesco_Flat: HBarrier_base_F {
	displayName = "Boxloader HESCO (Packed)";
	editorCategory="EdCat_Supplies";
	editorSubcategory="EdSubCat_Boxloader";
	model = "\boxloader\mdl\boxloader_hesco_flat.p3d";
	scope = 2;
	scopeCurator = 2;
	class EventHandlers {
		init = "[_this select 0,0] call boxloader_fnc_hesco";
	};
};

class Land_Boxloader_Hesco_BigFlat: Land_Boxloader_Hesco_Flat {
	displayName = "Boxloader Big HESCO (Packed)";
	model = "\boxloader\mdl\boxloader_hesco_bigflat.p3d";
	class EventHandlers {
		init = "[_this select 0,1] call boxloader_fnc_hesco";
	};
}
class Land_Boxloader_Hesco_SmallFlat: Land_Boxloader_Hesco_Flat {
	displayName = "Boxloader Small HESCO (Packed)";
	model = "\boxloader\mdl\boxloader_hesco_smallflat.p3d";
	class EventHandlers {
		init = "[_this select 0,2] call boxloader_fnc_hesco";
	};
}



class Land_Boxloader_Hesco_1: Land_Boxloader_Hesco_Flat {
	displayName = "Boxloader HESCO 1m";
	model = "\boxloader\mdl\boxloader_hesco_1.p3d";
	class EventHandlers {
		init = "_this call boxloader_fnc_hesco_built";
	};
	scope = 1;
	scopeCurator = 1;
	ace_dragging_canCarry = 0;
	ace_cargo_canLoad = 0;
	Boxloader_ConBase="Land_Boxloader_Hesco_Flat";
	class AnimationSources {
		class Fill_Source {
			source = "user";
			initPhase = 1;
			animPeriod = 0;
		};
		class Empty_Source {
			source = "user";
			initPhase = 0;
			animPeriod = 0;
		};
	};
	//armor=300;
	//destrType="DestructTent";
	hiddenSelections[] = {"fill"};
	hiddenSelectionsTextures[] = {"\boxloader\tex\boxloader_hesco_dirt_co.paa"};
};
class Land_Boxloader_Hesco_3: Land_Boxloader_Hesco_1 {
	displayName = "Boxloader HESCO 3m";
	model = "\boxloader\mdl\boxloader_hesco_3.p3d";
};
class Land_Boxloader_Hesco_5: Land_Boxloader_Hesco_1 {
	displayName = "Boxloader HESCO 5m";
	model = "\boxloader\mdl\boxloader_hesco_5.p3d";
};



class Land_Boxloader_Hesco_Big1: Land_Boxloader_Hesco_1 {
	displayName = "Boxloader Big HESCO 2m";
	model = "\boxloader\mdl\boxloader_hesco_big1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_BigFlat";
};
class Land_Boxloader_Hesco_Big3: Land_Boxloader_Hesco_Big1 {
	displayName = "Boxloader Big HESCO 6m";
	model = "\boxloader\mdl\boxloader_hesco_big3.p3d";
};
class Land_Boxloader_Hesco_Big5: Land_Boxloader_Hesco_Big1 {
	displayName = "Boxloader Big HESCO 10m";
	model = "\boxloader\mdl\boxloader_hesco_big5.p3d";
};

class Land_Boxloader_Hesco_Small1: Land_Boxloader_Hesco_1 {
	displayName = "Boxloader Small HESCO 0.5m";
	model = "\boxloader\mdl\boxloader_hesco_small1.p3d";
	Boxloader_ConBase="Land_Boxloader_Hesco_SmallFlat";
};
class Land_Boxloader_Hesco_Small6: Land_Boxloader_Hesco_Small1 {
	displayName = "Boxloader Small HESCO 3m";
	model = "\boxloader\mdl\boxloader_hesco_small6.p3d";
};
class Land_Boxloader_Hesco_Small10: Land_Boxloader_Hesco_Small1 {
	displayName = "Boxloader Small HESCO 5m";
	model = "\boxloader\mdl\boxloader_hesco_small10.p3d";
};
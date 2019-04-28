if (isClass(configFile >> "CfgPatches" >> "BaBe_EM")) then {
	[] spawn {
		waitUntil {sleep 0.1; !(isNil "em_blacklist_obj")};
		{em_blacklist_obj pushBack _x} forEach [
			"Land_Boxloader_Fort_Wire_3m",
			"Land_Boxloader_Fort_Wire_5m"
		];
	};
};
true

class CfgPatches {
	class boxloader {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgFunctions {
	class boxloader {
		tag = "boxloader";
		class boxloaderFunctions {
			file = "\boxloader\functions";
		class init {postInit = 1;};
		class load {};
		class addaction {};
		};
	};
};
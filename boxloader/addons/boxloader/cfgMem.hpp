#include "cfgMemCup.hpp"
class Land_Boxloader_iso20: Boxloader_Pallet_Base {
	model = "\boxloader\mdl\boxloader_mem_iso20.p3d";
	class VehicleTransport: VehicleTransport {
		class Cargo {
			canBeTransported            = 0;
		};
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
			cargoSpacing[]              = {0.05, 0.05, 0};
			maxLoadMass                 = 280000;
		};
	};
	slingLoadCargoMemoryPoints[] = {};
};
class Land_Boxloader_mem_quad: Boxloader_Pallet_Base {
	model = "\boxloader\mdl\boxloader_mem_quad.p3d";
	class VehicleTransport: VehicleTransport {
		class Cargo {
			canBeTransported            = 0;
		};
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
			cargoSpacing[]              = {0, 0, 0};
			maxLoadMass                 = 1000;
			cargoAlignment[]            = {"left","center"};
		};
	};
	slingLoadCargoMemoryPoints[] = {};
};
class Land_Boxloader_mem_quad_front: Boxloader_Pallet_Base {
	model = "\boxloader\mdl\boxloader_mem_quad_front.p3d";
	class VehicleTransport: VehicleTransport {
		class Cargo {
			canBeTransported            = 0;
		};
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
			cargoSpacing[]              = {0, 0, 0};
			maxLoadMass                 = 1000;
			cargoAlignment[]            = {"back","center"};
		};
	};
	slingLoadCargoMemoryPoints[] = {};
};
class Land_Boxloader_mem_idap: Boxloader_Pallet_Base {
	model = "\boxloader\mdl\boxloader_mem_idap.p3d";
	class VehicleTransport: VehicleTransport {
		class Cargo {
			canBeTransported            = 0;
		};
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
			cargoSpacing[]              = {0, 0, 0};
			maxLoadMass                 = 3000;
		};
	};
	slingLoadCargoMemoryPoints[] = {};
	
};
class Land_Boxloader_mem_offroad: Boxloader_Pallet_Base {
	model = "\boxloader\mdl\boxloader_mem_offroad.p3d";
	class VehicleTransport: VehicleTransport {
		class Cargo {
			canBeTransported            = 0;
		};
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
			cargoSpacing[]              = {0, 0, 0};
			maxLoadMass                 = 10000;
		};
	};
	slingLoadCargoMemoryPoints[] = {};
};
class Land_Boxloader_mem_hemtt: Land_Boxloader_membase_truck {
	model = "\boxloader\mdl\boxloader_mem_hemtt.p3d";
};
class Land_Boxloader_mem_kamaz: Land_Boxloader_membase_truck {
	model = "\boxloader\mdl\boxloader_mem_kamaz.p3d";
};
class Land_Boxloader_mem_typhoon: Land_Boxloader_membase_truck {
	model = "\boxloader\mdl\boxloader_mem_typhoon.p3d";
};
class Land_Boxloader_mem_rhsural: Land_Boxloader_membase_truck {
	model = "\boxloader\mdl\boxloader_mem_rhsural.p3d";
};
class Land_Boxloader_mem_rhsgaz: Land_Boxloader_membase_truck {
	model = "\boxloader\mdl\boxloader_mem_rhsgaz.p3d";
};
class Land_Boxloader_mem_boxer: Boxloader_Pallet_Base {
	model = "\boxloader\mdl\boxloader_mem_boxer.p3d";
	class VehicleTransport: VehicleTransport {
		class Cargo {
			canBeTransported            = 0;
		};
		class Carrier: Carrier {
			cargoBayDimensions[]        = {"BBox_Base1", "BBox_Corner"};
			cargoSpacing[]              = {0, 0.1, 0};
			cargoAlignment[]            = {"front","center"};
			maxLoadMass                 = 10000;
		};
	};
};

class Land_Boxloader_mem_zodiac: Land_Boxloader_membase_truck {
	model = "\boxloader\mdl\boxloader_mem_zodiac.p3d";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			cargoAlignment[]            = {"back","center"};
			maxLoadMass                 = 5000;
		};
	};
};
class Land_Boxloader_mem_quad: Boxloader_Pallet_Base {
	ace_dragging_canDrag = 0;
	model = "\boxloader_retrofit\mdl\boxloader_mem_quad.p3d";
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
	ace_dragging_canDrag = 0;
	model = "\boxloader_retrofit\mdl\boxloader_mem_quad_front.p3d";
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
	model = "\boxloader_retrofit\mdl\boxloader_mem_idap.p3d";
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
	ace_dragging_canDrag = 0;
	model = "\boxloader_retrofit\mdl\boxloader_mem_offroad.p3d";
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
	model = "\boxloader_retrofit\mdl\boxloader_mem_hemtt.p3d";
};
class Land_Boxloader_mem_kamaz: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_kamaz.p3d";
};
class Land_Boxloader_mem_boxer: Boxloader_Pallet_Base {
	ace_dragging_canDrag = 0;
	model = "\boxloader_retrofit\mdl\boxloader_mem_boxer.p3d";
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
	model = "\boxloader_retrofit\mdl\boxloader_mem_zodiac.p3d";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			cargoAlignment[]            = {"back","center"};
			maxLoadMass                 = 5000;
		};
	};
};

class Land_Boxloader_mem_prowler: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_prowler.p3d";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			cargoAlignment[]            = {"back","center"};
			disableHeightLimit          = 0;
		};
	};
};
class Land_Boxloader_Prowler_Net: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_prowler_net.p3d";
};
class Boxloader_Bucket: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_bucket.p3d";
};
class Land_Boxloader_Prowler_Roofnet: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_prowler_roofnet.p3d";
};
class Land_Boxloader_Roofrack_1: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_roofrack1.p3d";
};

class Land_Boxloader_mem_rhsural: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_rhsural.p3d";
};
class Land_Boxloader_mem_rhsgaz: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_rhsgaz.p3d";
};


class Land_Boxloader_mem_ifa: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_ifa.p3d";
};
class Land_Boxloader_mem_ifazis: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_ifazis.p3d";

};
class Land_Boxloader_mem_ifac47: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_ifac47.p3d";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			disableHeightLimit = 0;
		};
	};
};
class Land_Boxloader_mem_ifawaco_rear: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_ifawaco_rear.p3d";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			disableHeightLimit = 0;
		};
	};
};
class Land_Boxloader_mem_ifawaco_front: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_ifawaco_front.p3d";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			disableHeightLimit = 1;
			cargoAlignment[]            = {"back","center"};
		};
	};
};
class Land_Boxloader_mem_ifahorsa_front: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_ifahorsa_front.p3d";
	class VehicleTransport: VehicleTransport {
		class Carrier: Carrier {
			disableHeightLimit = 1;
			cargoAlignment[]            = {"back","center"};
		};
	};
};
class Land_Boxloader_mem_uns_m37: Land_Boxloader_membase_truck {
	model = "\boxloader_retrofit\mdl\boxloader_mem_uns_m37.p3d";
};
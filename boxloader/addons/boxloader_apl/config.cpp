#define WHEEL_STRENGTH 5
#define WHEEL_DAMPER 4
#define WHEEL_SPRINGS(MASS,WHEELS,STRENGTH,DAMPER) sprungMass = MASS/WHEELS; \
springStrength = (MASS/WHEELS)*STRENGTH^2; \
springDamperRate = DAMPER*2*((MASS/WHEELS)*STRENGTH^2*(MASS/WHEELS))^0.5;
class CfgPatches {
	class boxloader_apl {
		units[] = {
			"boxloader_ammo_west",
			"boxloader_vehicleammo_west",
			"Boxloader_sixcon_fuel",
			"boxloader_skid_bucket",
			"boxloader_skid_fork"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"boxloader"};
	};
};
class CBA_Extended_EventHandlers_base;
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
	class Car;
	
	class Car_F : Car {
		class AnimationSources;	
		
		
		class HitPoints {
			class HitLFWheel;	
			class HitLF2Wheel;	
			class HitRFWheel;	
			class HitRF2Wheel;	
			class HitGlass1;	
			class HitGlass2;	
			class HitGlass3;	
			class HitGlass4;	
			class HitGlass5;	
			class HitGlass6;	
		};
	};
	class Quadbike_01_base_F: Car_F {};
	class boxloader_skidbase: Quadbike_01_base_F {
		slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		class SpeechVariants {
			class Default {
				speechSingular[] = {"veh_vehicle_car_s"};
				speechPlural[] = {"veh_vehicle_car_p"};
			};
		};
		class Turrets {};
		maxSpeed = 14;
		textSingular = "$STR_A3_nameSound_veh_vehicle_car_s";
		textPlural = "$STR_A3_nameSound_veh_vehicle_car_p";
		nameSound = "veh_vehicle_car_s";
		author = "vurtual";
		_generalMacro = "";
		scope = 0; 
		Model = "\boxloader_apl\boxloader_skidloader.p3d";
		//model = "\A3\Soft_F\Quadbike_01\Quadbike_01_F.p3d";
		mapSize = 3;
		displayName = "Skid loader";
		crew = "B_Soldier_F";
		typicalCargo[] = {};
		side = 1;
		faction = "BLU_F";
		wheelCircumference = 2.5707;
		driverCompartments = "Compartment1";
		crewVulnerable = true;
		ejectDeadDriver = false;
		crewCrashProtection = 0.5;
		magazines[] = {};
		armor = 80;
		damageResistance = 0.03;
		turnCoef = 4;
		terrainCoef = 2;
		cost = 2000;
		precision = 20;
		armorWheels = 0.7;
		maximumLoad = 500;
		transportSoldier = 0;
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class VehicleTransport {
			class Cargo {
				parachuteClass				= "B_Parachute_02_F";
				canBeTransported            = 1;
				parachuteHeightLimit		= 10;
			};
		};
		driverAction = "driver_offroad01";
		// threat (VSoft, VArmor, VAir), how threatening vehicle is to unit types
		threat[] = {0, 0, 0};

		driverLeftHandAnimName = "";
		driverRightHandAnimName = "";
		
		class TransportMagazines {};
		
		class TransportItems {};
		
		class TransportWeapons {};
		
		idleRpm = 800;
		redRpm = 2200;
		brakeIdleSpeed = 1;
		fuelCapacity = 80;
		
		class complexGearbox {
			GearboxRatios[] = {"R1", -4, "N", 0, "D1", 4};
			TransmissionRatios[] = {"High", 6};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		simulation = "carx";
		differentialType = "all_limited";
		frontRearSplit = 0.5;
		frontBias = 1.1;
		rearBias = 1.1;
		centreBias = 1.1;
		clutchStrength = 65.0;
		enginePower = 55;
		maxOmega = 230;
		peakTorque = 265;
		torqueCurve[] = {
			{"10/25", "240/265"},
			{"12/25", "250/265"},
			{"14/25", "260/265"},
			{"16/25", "265/265"},
			{"18/25", "262/265"},
			{"20/25", "257/265"},
			{"22/25", "250/265"},
			{"24/25", "240/265"},
			{"25/25", "237/265"}
		};
		changeGearMinEffectivity[] = {0.95, 0.15, 0.95};
		switchTime = 0.1;
		latency = 1;
		maxFordingDepth=0;
		numberPhysicalWheels=4;
		class BaseWheel {
			mass = 20;
			MOI = 10;
			dampingRate = 0.1;
			dampingRateDamaged = 1;
			dampingRateDestroyed = 1000;
			maxBrakeTorque = 3000;
			maxHandBrakeTorque = 0;
			suspTravelDirection[] = {0, -1, 0};
			maxCompression = 0.5;
			mMaxDroop = 0.25;
			longitudinalStiffnessPerUnitGravity = 5000;
			latStiffX = 35;
			latStiffY = 180;
			frictionVsSlipGraph[] = {{0, 0.8}, {0.5, 0.9}, {1, 1}};
			width = 0.2;
		};
		class Wheels {
			class LF: BaseWheel {
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center   = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				WHEEL_SPRINGS(4000*1.5,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class LR : LF
			{
				steering = 0;
				boneName = "wheel_1_2_damper";
				center   = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				WHEEL_SPRINGS(4000,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			
			class RF : LF
			{
				boneName = "wheel_2_1_damper";
				center   = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				side = "right";
			};
			class RR : RF
			{
				steering = 0;
				boneName = "wheel_2_2_damper";
				center   = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				WHEEL_SPRINGS(4000,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
		};
		//viewDriverInExternal = 1;
		class Exhausts {};
		class HitPoints : HitPoints {
			
			class HitLFWheel : HitLFWheel {
				armor = 0.3;
			};
			
			class HitLBWheel : HitLF2Wheel {
				armor = 0.3;
			};
			
			class HitRFWheel : HitRFWheel {
				armor = 0.3;
			};
			
			class HitRBWheel : HitRF2Wheel {
				armor = 0.3;
			};
			
			class HitFuel {
				armor = 2;
				material = -1;
				name = "palivo";
				visual = "";
				passThrough = true;
			};
		};
		class Reflectors {};

		
		class RenderTargets {};
		class EventHandlers {
			init = "_this call boxloader_fnc_skid_init";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
		class AnimationSources {
			class Bucket_Hide {
				source = "user";
				initPhase = 0;
				animPeriod = 0.1;
			};
		};
	};
	class boxloader_skid_bucket: boxloader_skidbase {
		scope = 2;
		displayname = "Loader (Bucket)";
	};
	class boxloader_skid_fork: boxloader_skidbase {
		scope = 2;
		displayname = "Loader (Pallet Fork)";
		class AnimationSources {
			class Bucket_Hide {
				source = "user";
				initPhase = 1;
				animPeriod = 0.1;
			};
		};
	};
};
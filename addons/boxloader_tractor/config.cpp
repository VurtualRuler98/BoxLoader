#define WHEEL_STRENGTH 10
#define WHEEL_DAMPER 3
#define WHEEL_SPRINGS(MASS,WHEELS,STRENGTH,DAMPER) sprungMass = MASS/WHEELS; \
springStrength = (MASS/WHEELS)*STRENGTH^2; \
springDamperRate = DAMPER*2*((MASS/WHEELS)*STRENGTH^2*(MASS/WHEELS))^0.5;
class CfgPatches {
	class boxloader_tractor {
		units[] = {
			"Boxloader_tractor_build",
			"boxloader_tractor_fork"

		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main"};
	};
};
class CfgMovesBasic {
	class DefaultDie;	// External class reference
	
	class ManActions {
		boxloader_tractor_driver = "boxloader_tractor_driver";
	};
};
class CfgMovesMaleSdr : CfgMovesBasic {
	class States {
		class Crew;	// External class reference
		class AmovPercMstpSnonWnonDnon;	// External class reference
		
		class boxloader_tractor_kia_driver : DefaultDie {
			actions = "DeadActions";
			file = "\boxloader_tractor\data\kia_tractor_driver.rtm";
			speed = 0.5;
			looped = "false";
			terminal = true;
			connectTo[] = {"Unconscious", 0.1};
			soundEnabled = false;
		};
		
		class boxloader_tractor_driver : Crew {
			file = "\boxloader_tractor\data\tractor_driver.rtm";
			interpolateTo[] = {"boxloader_tractor_kia_driver", 1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};
	};
};
class CfgFunctions {
	
	class boxloader_tractor {
		tag = "boxloader_Tractor";
		class boxloader_tractorFunctions {
			file = "\boxloader_tractor\fnc";
			class init {};
		};
	};
};
class CBA_Extended_EventHandlers_base;

class CfgVehicles {
	class LandVehicle;
	class Car: LandVehicle {
		class AnimationSources;
	};
	class Car_F : Car {
		class AnimationSources: AnimationSources {
			class HitLFWheel;
			class HitRFWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitGlass1;
		};
		
		class HitPoints {
			class HitHull;
			class HitBody;
			class HitEngine;
			class HitFuel;
			class HitLFWheel;	// External class reference
			class HitLF2Wheel;	// External class reference
			class HitRFWheel;	// External class reference
			class HitRF2Wheel;	// External class reference
			class HitGlass1;	// External class reference
			class HitGlass2;	// External class reference
			class HitGlass3;	// External class reference
			class HitGlass4;	// External class reference
		};
	};
	class boxloader_tractor_base: Car_F {
		#include "sounds.hpp"
		insideSoundCoef = 0.9;
		attenuationEffectType = "OpenCarAttenuation";
		driverAction = "boxloader_tractor_driver";
		scope = 0;
		displayName = "Work Tractor";
		model = "\boxloader_tractor\boxloader_tractor.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\boxloader_tractor\Data\tractor_2_green_co.paa"};
		class textureSources {
			class green {
				displayname = "Green";
				author = "vurtual";
				textures[] = {"\boxloader_tractor\Data\tractor_2_green_co.paa"};
				factions[] = {};
			};
			class red {
				displayname = "Red";
				author = "vurtual";
				textures[] = {"\boxloader_tractor\Data\tractor_2_co.paa"};
				factions[] = {};
			};
		};
		class AnimationSources: AnimationSources {
			class roof_hide {
				source = "user";
				initPhase = 0;
				animPeriod = 0.1;
				displayName = "Remove roof";
			};
			class tool_hide: roof_hide {
				displayName = "Hide Tool";
			};
			class bucket_hide {
				source = "user";
				initPhase = 1;
				animPeriod = 0.1;
			};
			class fork_hide: bucket_hide {};
			class HitLFWheel: HitLFWheel {
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitRFWheel {
				source = "Hit";
				hitpoint = "HitRFWheel";
				raw = 1;
			};
			class HitLF2Wheel: HitLF2Wheel {
				source = "Hit";
				hitpoint = "HitLF2Wheel";
				raw = 1;
			};
			class HitRF2Wheel: HitRF2Wheel {
				source = "Hit";
				hitpoint = "HitRF2Wheel";
				raw = 1;
			};
			class HitGlassDoorLeft: HitGlass1 {
				source = "Hit";
				hitpoint = "HitGlassDoorLeft";
				raw = 1;
			};
			class HitGlassDoorRight: HitGlass1 {
				source = "Hit";
				hitpoint = "HitGlassDoorRight";
				raw = 1;
			};
		};
		crew = "B_soldier_F";
		side = 1;
		faction = BLU_F;
		class VehicleTransport {
			class Cargo {
				dimensions[]				= {"VTV_Cargo_Base","VTV_Cargo_Corner"};
				parachuteClass				= "B_Parachute_02_F";
				canBeTransported            = 1;
				parachuteHeightLimit		= 10;
			};
			class Carrier {
				cargoBayDimensions[]        = {"VTV_Carrier_Base_Bucket", "VTV_Carrier_Corner_Bucket"};
				cargoSpacing[]              = {0, 0, 0};
				cargoAlignment[]            = {"back","center"};
				maxLoadMass                 = 1002;
				disableHeightLimit			= 1;
				exits[]						= {"VTV_exit_1"};
				unloadingInterval			= 2;
				loadingDistance				= 0;
				loadingAngle				= 0;
				parachuteClassDefault       = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 10000;
			};
		};
		brakeIdleSpeed = 0.1;
		fuelCapacity = 20; //TODO
		explosionShielding = 0.8;
		simulation = "carx";
		dampersBumpCoef = 6.0;
		differentialType = "rear_open";
		maxFordingDepth=1000;
		hasGunner = false;
		armor = 80;
		terrainCoef=0.5;
		wheelCircumference=3.768;
		maxSpeed = 40;
		class Wheels {
			class LF {
				boneName = "wheel_1_1";
				steering = 1;
				side = "left";
				center = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				width = 0.126;
				mass = 30;
				MOI = 12.8;
				dampingRate = 0.1;
				dampingRateDamaged = 0.5;
				dampingRateDestroyed = 1000;
				maxBrakeTorque = 10000;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0, -1, 0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.05;
				mMaxDroop = 0.1;
				WHEEL_SPRINGS(800,4,WHEEL_STRENGTH,WHEEL_DAMPER)
				longitudinalStiffnessPerUnitGravity = 8000;
				latStiffX = 25;
				latStiffY = 180;
				frictionVsSlipGraph[] = {{0, 1}, {0.5, 1}, {1, 1}};
			};
			class LR: LF {
				boneName = "wheel_1_2";
				steering = 0;
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3500;
			};
			class RF: LF {
				boneName = "wheel_2_1";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				steering = 1;
				side = "right";
			};
			class RR: RF {
				boneName = "wheel_2_2";
				steering = 0;
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 3500;
			};
		};
		class SoundEvents {
			class AccelerationOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tractor\ext\ext-Tractor-acce-1", db-5, 1.0, 280};
				limit = "0.5";
				expression = "engineOn*gmeterZ";
			};
		};
		class Sounds {
			class EngineLowOut
			{
				sound[] =  {"\ca\sounds\Vehicles\Wheeled\Tractor\ext\ext-tractor-low-4", db0, 1.1, 300};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "engineOn*(thrust factor[0.7, 0.2])";
			};
			class EngineHighOut
			{
				sound[] = {"\ca\sounds\Vehicles\Wheeled\Tractor\ext\ext-tractor-high-2a", db0, 0.8, 350};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "engineOn*(thrust factor[0.5, 1.0])";
			};
			class IdleOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tractor\ext\ext-tractor-idle-5", db-5, 1.0, 200};
				frequency = "1";
				volume = "engineOn*(rpm factor[0.35, 0])";
			};
			class NoiseOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Noises\ext\noise2", db-10, 1.0, 30};
				frequency = "1";
				volume = "(damper0 max 0.04)*(speed factor[0, 8])";
			};
		};
		class EventHandlers {
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
		class HitPoints : HitPoints {
			class HitHull: HitHull {
				armorComponent = "hit_hull";
				name = "hit_hull_p";
				depends = "Total-0.1";
				armor = 999;
				passThrough = 0;
				explosionShielding = 0;
				minimalHit = 0;
				visual = "-";
			};
			class HitBody: HitBody {
				armor = -300;
				explosionShielding = 0.2;
				passThrough = 0.2;
				name = "hit_body_p";
				armorComponent = "hit_body";
				radius = 0.15;
			};
			class Light_L {
				armorComponent = "hit_light_L";
				name = "hit_light_L_p";
				armor = -30;
				passThrough = 0;
				explosionShielding = 0;
				minimalHit = 0;
				visual = "-";
				radius = 0.15;
			};
			class Light_R: Light_L {
				armorComponent = "hit_light_R";
				name = "hit_light_R_p";
			};
	
			class HitLFWheel: HitLFWheel {
				armor = -100;
				explosionShielding = 4;
				minimalHit = 0.0167;
				name = "hit_wheel_1_1_p";
				armorComponent = "wheel_1_1_hide";
				
			};
			class HitRFWheel: HitRFWheel {
				armor = -100;
				explosionShielding = 4;
				minimalHit = 0.0167;
				name = "hit_wheel_2_1_p";
				armorComponent = "wheel_2_1_hide";
			};
			class HitLF2Wheel: HitLF2Wheel {
				armor = -100;
				explosionShielding = 4;
				minimalHit = 0.0167;
				armorComponent = "wheel_1_2_hide";
				name = "hit_wheel_1_2_p";
			};
			class HitRF2Wheel: HitRF2Wheel {
				armor = -100;
				explosionShielding = 4;
				minimalHit = 0.0167;
				name = "hit_wheel_2_2_p";
				armorComponent = "wheel_2_2_hide";
			};
			class HitGlass1: HitGlass1 {
				armor = 0.1;
				visual = "glass1";
				armorComponent = "glass1";
				name = "hit_glass1_p";
			};
			class HitGlass2: HitGlass2 {
				armor = 0.1;
				visual = "glass2";
				armorComponent = "glass2";
				name = "hit_glass2_p";
			};
			class HitGlass3: HitGlass3 {
				armor = 0.1;
				visual = "glass3";
				armorComponent = "glass3";
				name = "hit_glass3_p";
			};
			class HitGlass4: HitGlass4 {
				armor = 0.1;
				visual = "glass4";
				armorComponent = "glass4";
				name = "hit_glass4_p";
			};
			class HitGlassDoorLeft: HitGlass1 {
				visual = "door_left_glass";
				armorComponent = "door_left_glass";
				name = "hit_door_left_glass_p";
			};
			class HitGlassDoorRight: HitGlass1 {
				visual = "door_right_glass";
				armorComponent = "door_right_glass";
				name = "hit_door_right_glass_p";
			};
			class HitFuel {
				armor = 1.4;
				material = -1;
				name = "hit_fuel_p";
				visual = "-";
				passThrough = 0;
				armorComponent = "hit_fuel";
				radius = 0.15;
				explosionShielding = 0.1;
			};
			class HitEngine: HitEngine {
				passThrough = 0.2;
				radius = 0.01;
				armor = -300;
				visual = "dmg_engine";
				armorComponent = "hit_engine";
				name = "hit_engine_p";
			};
		};
		class Damage { 
			tex[] = {};
			mat[] = {
				"boxloader_tractor\Data\traktor_2.rvmat",
				"boxloader_tractor\Data\traktor_2.rvmat",
				"boxloader_tractor\Data\traktor_2_destruct.rvmat",
				
				"boxloader_tractor\Data\traktor_2_skla.rvmat",
				"boxloader_tractor\Data\traktor_2_skla_destruct.rvmat",
				"boxloader_tractor\Data\traktor_2_skla_destruct.rvmat"
			};
		};
		class Exhausts {
			class Exhaust1 {
				position = "exhaust_pos";
				direction = "exhaust_dir";
				effect = "ExhaustEffectOffroad";
			};
		};
		class Turrets {};
		//driverdoor = "door_left";
		class Reflectors {
			class LightCarHeadL01 {
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				position = "Light_L";
				direction = "Light_L_dir";
				hitpoint = "hit_light_L_p";
				selection = "Light_L";
				size = 1;
				innerAngle = 45;
				outerAngle = 110;
				coneFadeCoef = 5;
				intensity = 1;
				useFlare = 1;
				dayLight = 0;
				flareSize = 1;
				
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			class LightCarHeadR01 : LightCarHeadL01 {
				position = "Light_R";
				direction = "Light_R_Dir";
				hitpoint = "hit_light_R_p";
				selection = "Light_R";
			};
		};
		aggregateReflectors[] = {
			{"LightCarHeadL01","LightCarHeadR01"}
		};
		class RenderTargets {
			class LeftMirror {
				renderTarget = "rendertarget0";
				
				class CameraView1 {
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 4;
					fov = 0.7;
				};
			};
		};
		class complexGearbox {
				GearboxRatios[] = {"R1", -2.08, "N", 0, "D1", 2.48};
				//TransmissionRatios[] = {"High", 1*1.92*2.56};
				TransmissionRatios[] = {"High", 1*1.92*2.65};
				gearBoxMode = "auto";
				moveOffGear = 1;
				driveString = "D";
				neutralString = "N";
				reverseString = "R";
		};
		idleRpm = 650;
		redRpm = 2000;
		enginePower = 18;
		maxOmega = 209;
		peakTorque = 100;
		torqueCurve[] = {
			{0.0, "18/24"},
			{"16/36", "23/24"},
			{"20/36", "23.5/24"},
			{"21/36", "24/24"},
			{"24/36", "23.5/24"},
			{"28/36", "23.2/24"},
			{"30/36", "23/24"},
			{"36/36", "21/24"}
		};
		changeGearOmegaRatios[] = {
			36/36, 5/36, //R
			14/36, 0, //N
			37/36, 5/36 //1
		};
		changeGearType = "rpmratio";
		switchTime = 0.11;
		latency = 0.5;
	};
	class boxloader_tractor_build: boxloader_tractor_base {
		displayName = "Work Tractor (Construction)";
		scope = 2;
		class AnimationSources: AnimationSources {
			class bucket_hide: bucket_hide {
				initPhase = 0;
			};
		};
		class EventHandlers: EventHandlers {
			init = "[_this select 0,true] call boxloader_tractor_fnc_init";
		};
		class VehicleTransport: VehicleTransport {
			class Carrier: Carrier {
				cargoAlignment[]            = {"back","left"};
			};
		};
	};
	class boxloader_tractor_fork: boxloader_tractor_base {
		scope = 2;
		displayName = "Work Tractor (Forklift)";
		class AnimationSources: AnimationSources {
			class fork_hide: fork_hide {
				initPhase = 0;
			};
		};
		class EventHandlers: EventHandlers {
			init = "[_this select 0,false] call boxloader_tractor_fnc_init";
		};
		class VehicleTransport: VehicleTransport {
			class Carrier: Carrier {
				cargoBayDimensions[]        = {"VTV_Carrier_Base_Fork", "VTV_Carrier_Corner_Fork"};
			};
		};
	};
};

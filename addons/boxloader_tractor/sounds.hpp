		soundGetIn[] = {"", 0.562341, 1};
		soundGetOut[] = {"", 0.562341, 1, 20};
		soundDammage[] = {"", 0.562341, 1};
		soundEngineOnInt[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_int_start", 0.707946, 0.8};
		soundEngineOnExt[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_start", 0.707946, 0.8, 200};
		soundEngineOffInt[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_int_stop", 0.707946, 0.8};
		soundEngineOffExt[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_stop", 0.707946, 0.8, 200};
		buildCrash0[] = {"A3\sounds_f\Vehicles\armor\noises\tank_building_01", 1.77828, 1, 200};
		buildCrash1[] = {"A3\sounds_f\Vehicles\armor\noises\tank_building_02", 1.77828, 1, 200};
		buildCrash2[] = {"A3\sounds_f\Vehicles\armor\noises\tank_building_03", 1.77828, 1, 200};
		buildCrash3[] = {"A3\sounds_f\Vehicles\armor\noises\tank_building_04", 1.77828, 1, 200};
		soundBuildingCrash[] = {"buildCrash0", 0.25, "buildCrash1", 0.25, "buildCrash2", 0.25, "buildCrash3", 0.25};
		WoodCrash0[] = {"A3\sounds_f\Vehicles\armor\noises\tank_wood_01", 1.77828, 1, 200};
		WoodCrash1[] = {"A3\sounds_f\Vehicles\armor\noises\tank_wood_02", 1.77828, 1, 200};
		WoodCrash2[] = {"A3\sounds_f\Vehicles\armor\noises\tank_wood_03", 1.77828, 1, 200};
		WoodCrash3[] = {"A3\sounds_f\Vehicles\armor\noises\tank_wood_04", 1.77828, 1, 200};
		soundWoodCrash[] = {"woodCrash0", 0.25, "woodCrash1", 0.25, "woodCrash2", 0.25, "woodCrash3", 0.25};
		ArmorCrash0[] = {"A3\sounds_f\Vehicles\armor\noises\tank_vehicle_01", 1.77828, 1, 200};
		ArmorCrash1[] = {"A3\sounds_f\Vehicles\armor\noises\tank_vehicle_02", 1.77828, 1, 200};
		ArmorCrash2[] = {"A3\sounds_f\Vehicles\armor\noises\tank_vehicle_03", 1.77828, 1, 200};
		ArmorCrash3[] = {"A3\sounds_f\Vehicles\armor\noises\tank_vehicle_04", 1.77828, 1, 200};
		soundArmorCrash[] = {"ArmorCrash0", 0.25, "ArmorCrash1", 0.25, "ArmorCrash2", 0.25, "ArmorCrash3", 0.25};
		soundBushCollision1[] = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_1", 1.0, 1, 100};
		soundBushCollision2[] = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_2", 1.0, 1, 100};
		soundBushCollision3[] = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_3", 1.0, 1, 100};
		soundBushCrash[] = {"soundBushCollision1", 0.33, "soundBushCollision2", 0.33, "soundBushCollision3", 0.33};
		Crash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1", 1.0, 1, 900};
		Crash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2", 1.0, 1, 900};
		Crash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3", 1.0, 1, 900};
		Crash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4", 1.0, 1, 900};
		soundCrashes[] = {"Crash0", 0.25, "Crash1", 0.25, "Crash2", 0.25, "Crash3", 0.25};
		
		class Sounds {
			class Idle_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_0800", 0.562341, 0.8, 200};
				frequency = "0.95	+	((rpm/	3200) factor[(300/	3200),(950/	3200)])*0.15";
				volume = "engineOn*(((rpm/	3200) factor[(300/	3200),(600/	3200)])	*	((rpm/	3200) factor[(960/	3200),(800/	3200)]))";
			};
			
			class Engine {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_1000rpm", 0.630957, 0.8, 200};
				frequency = "0.8	+	((rpm/	3200) factor[(800/	3200),(1500/	3200)])*0.2";
				volume = "engineOn*(((rpm/	3200) factor[(800/	3200),(900/	3200)])	*	((rpm/	3200) factor[(1500/	3200),(1100/	3200)]))";
			};
			
			class Engine1_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_1400rpm", db-3, 0.8, 200};
				frequency = "0.8	+	((rpm/	3200) factor[(1100/	3200),(1950/	3200)])*0.2";
				volume = "engineOn*(((rpm/	3200) factor[(1050/	3200),(1450/	3200)])	*	((rpm/	3200) factor[(1900/	3200),(1600/	3200)]))";
			};
			
			class Engine2_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_2000rpm", db-2, 0.8, 250};
				frequency = "0.8	+	((rpm/	3200) factor[(1600/	3200),(2300/	3200)])*0.2";
				volume = "engineOn*(((rpm/	3200) factor[(1560/	3200),(1880/	3200)])	*	((rpm/	3200) factor[(2350/	3200),(2000/	3200)]))";
			};
			
			class Engine3_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_2400rpm", db1, 0.8, 300};
				frequency = "0.8	+	((rpm/	3200) factor[(2000/	3200),(2650/	3200)])*0.1";
				volume = "engineOn*(((rpm/	3200) factor[(1980/	3200),(2300/	3200)])	*	((rpm/	3200) factor[(2660/	3200),(2400/	3200)]))";
			};
			
			class Engine4_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_2600rpm", db3, 0.8, 350};
				frequency = "0.8	+	((rpm/	3200) factor[(2400/	3200),(3000/	3200)])*0.1";
				volume = "engineOn*(((rpm/	3200) factor[(2380/	3200),(2640/	3200)])	*	((rpm/	3200) factor[(2990/	3200),(2770/	3200)]))";
			};
			
			class Engine5_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_3200rpm", db5, 0.8, 400};
				frequency = "0.8	+	((rpm/	3200) factor[(2700/	3200),(3200/	3200)])*0.1";
				volume = "engineOn*((rpm/	3200) factor[(2700/	3200),(2900/	3200)])";
			};
			
			class IdleThrust {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_0800_exhaust", db0, 0.8, 250};
				frequency = "0.8	+	((rpm/	3200) factor[(300/	3200),(950/	3200)])*0.15";
				volume = "engineOn*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3200) factor[(300/	3200),(600/	3200)])	*	((rpm/	3200) factor[(960/	3200),(800/	3200)]))";
			};
			
			class EngineThrust {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_1000rpm_exhaust", db2, 0.8, 300};
				frequency = "0.8	+	((rpm/	3200) factor[(800/	3200),(1500/	3200)])*0.2";
				volume = "engineOn*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3200) factor[(800/	3200),(900/	3200)])	*	((rpm/	3200) factor[(1500/	3200),(1100/	3200)]))";
			};
			
			class Engine1_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_1400rpm_exhaust", db3, 0.8, 350};
				frequency = "0.8	+	((rpm/	3200) factor[(1100/	3200),(1950/	3200)])*0.2";
				volume = "engineOn*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3200) factor[(1050/	3200),(1450/	3200)])	*	((rpm/	3200) factor[(1900/	3200),(1600/	3200)]))";
			};
			
			class Engine2_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_2000rpm_exhaust", db4, 0.8, 400};
				frequency = "0.8	+	((rpm/	3200) factor[(1600/	3200),(2300/	3200)])*0.2";
				volume = "engineOn*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3200) factor[(1560/	3200),(1880/	3200)])	*	((rpm/	3200) factor[(2350/	3200),(2000/	3200)]))";
			};
			
			class Engine3_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_2400rpm_exhaust", db6, 0.8, 450};
				frequency = "0.8	+	((rpm/	3200) factor[(2000/	3200),(2650/	3200)])*0.1";
				volume = "engineOn*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3200) factor[(1980/	3200),(2300/	3200)])	*	((rpm/	3200) factor[(2660/	3200),(2400/	3200)]))";
			};
			
			class Engine4_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_2600rpm_exhaust", db6, 0.8, 450};
				frequency = "0.8	+	((rpm/	3200) factor[(2400/	3200),(3000/	3200)])*0.1";
				volume = "engineOn*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3200) factor[(2380/	3200),(2640/	3200)])	*	((rpm/	3200) factor[(2990/	3200),(2770/	3200)]))";
			};
			
			class Engine5_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_3200rpm_exhaust", 2.23872, 0.8, 500};
				frequency = "0.8	+	((rpm/	3200) factor[(2700/	3200),(3200/	3200)])*0.1";
				volume = "engineOn*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	3200) factor[(2700/	3200),(2900/	3200)])";
			};
			
			
			class Movement {
				sound = "soundEnviron";
				frequency = "1";
				volume = "0";
			};
			
			class TiresRockOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1", db0, 1.0, 60};
				frequency = 1;
				volume = "rock*(speed factor[2, 20])";
			};
			
			class TiresSandOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1", db0, 1.0, 60};
				frequency = 1;
				volume = "sand*(speed factor[2, 20])";
			};
			
			class TiresGrassOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2", db0, 1.0, 60};
				frequency = 1;
				volume = "grass*(speed factor[2, 20])";
			};
			
			class TiresMudOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2", db0, 1.0, 60};
				frequency = 1;
				volume = "mud*(speed factor[2, 20])";
			};
			
			class TiresGravelOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1", db0, 1.0, 60};
				frequency = 1;
				volume = "gravel*(speed factor[2, 20])";
			};
			
			class TiresAsphaltOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2", db0, 1.0, 60};
				frequency = 1;
				volume = "asphalt*(speed factor[2, 20])";
			};
			
			class NoiseOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3", db0, 1.0, 90};
				frequency = 1;
				volume = "(damper0 max 0.02)*(speed factor[0, 8])";
			};
			
			class breaking_ext_road {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04", db0, 1, 100};
				frequency = 1;
				volume = "engineOn*(LongSlipDrive factor[-0.2, -0.4])*(speed factor[2, 10])";
			};
			
			class acceleration_ext_road {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db0, 1, 100};
				frequency = 1;
				volume = "engineOn*(LongSlipDrive factor[0.2, 0.4])*(speed factor[10, 1])";
			};
			
			class turn_left_ext_road {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db0, 1, 100};
				frequency = 1;
				volume = "engineOn*(latSlipDrive factor[0.15, 0.4])*(speed factor[0, 10])";
			};
			
			class turn_right_ext_road {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db0, 1, 100};
				frequency = 1;
				volume = "engineOn*(latSlipDrive factor[-0.15, -0.4])*(speed factor[0, 10])";
			};
			
			class breaking_ext_dirt {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04", db0, 1, 100};
				frequency = 1;
				volume = "engineOn*(LongSlipDrive factor[-0.2, -0.4])*(speed factor[2, 10])";
			};
			
			class acceleration_ext_dirt {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db0, 1, 100};
				frequency = 1;
				volume = "engineOn*(LongSlipDrive factor[0.2, 0.4])*(speed factor[10, 1])";
			};
			
			class turn_left_ext_dirt {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db0, 1, 100};
				frequency = 1;
				volume = "engineOn*(latSlipDrive factor[0.15, 0.4])*(speed factor[0, 10])";
			};
			
			class turn_right_ext_dirt {
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db0, 1, 100};
				frequency = 1;
				volume = "engineOn*(latSlipDrive factor[-0.15, -0.4])*(speed factor[0, 10])";
			};
			
			
			class RainExt {
				sound[] = {"A3\Sounds_F\vehicles\noises\rain2_ext", db0, 1.0, 100};
				frequency = 1;
				volume = "(rain - rotorSpeed/2) * 2";
			};
			
		};
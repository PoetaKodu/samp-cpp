#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

enum class CarModType
{
	Spoiler		= 0,
	Hood		= 1,
	Roof		= 2,
	SideSkirt	= 3,
	Lamps		= 4,
	Nitro		= 5,
	Exhaust		= 6,
	Wheels		= 7,
	Stereo		= 8,
	Hydraulics	= 9,
	FrontBumper	= 10,
	RearBumper	= 11,
	VentRight	= 12,
	VentLeft	= 13
};

enum class VehicleParams
{
	Unset	= -1,
	Off		= 0,
	On		= 1
};

enum class VehicleModelInfo
{
	Size			= 1,
	FrontSeat		= 2,
	RearSeat		= 3,
	PetrolCap		= 4,
	WheelsFront		= 5,
	WheelsRear		= 6,
	WheelsMid		= 7,
	FrontBumperZ	= 8,
	RearBumperZ		= 9
};

class Vehicle
{
public:
	enum Model
	{
		Landstalker				= 400,
		Bravura					= 401,
		Buffalo					= 402,
		Linerunner				= 403,
		Perrenial				= 404,
		Sentinel				= 405,
		Dumper					= 406,
		Firetruck				= 407,
		Trashmaster				= 408,
		Stretch					= 409,
		Manana					= 410,
		Infernus				= 411,
		Voodoo					= 412,
		Pony					= 413,
		Mule					= 414,
		Cheetah					= 415,
		Ambulance				= 416,
		Leviathan				= 417,
		Moonbeam				= 418,
		Esperanto				= 419,
		Taxi					= 420,
		Washington				= 421,
		Bobcat					= 422,
		MrWhoopee				= 423,
		BFInjection				= 424,
		Hunter					= 425,
		Premier					= 426,
		Enforcer				= 427,
		Securicar				= 428,
		Banshee					= 429,
		Predator				= 430,
		Bus						= 431,
		Rhino					= 432,
		Barracks				= 433,
		Hotknife				= 434,
		ArticleTrailer1			= 435,
		Previon					= 436,
		Coach					= 437,
		Cabbie					= 438,
		Stallion				= 439,
		Rumpo					= 440,
		RCBandit				= 441,
		Romero					= 442,
		Packer					= 443,
		Monster					= 444,
		Admiral					= 445,
		Squalo					= 446,
		Seasparrow				= 447,
		Pizzaboy				= 448,
		Tram					= 449,
		ArticleTrailer2			= 450,
		Turismo					= 451,
		Speeder					= 452,
		Reefer					= 453,
		Tropic					= 454,
		Flatbed					= 455,
		Yankee					= 456,
		Caddy					= 457,
		Solair					= 458,
		BerkleysRCVan			= 459,
		Skimmer					= 460,
		PCJ600					= 461,
		Faggio					= 462,
		Freeway					= 463,
		RCBaron					= 464,
		RCRaider				= 465,
		Glendale				= 466,
		Oceanic					= 467,
		Sanchez					= 468,
		Sparrow					= 469,
		Patriot					= 470,
		Quad					= 471,
		Coastguard				= 472,
		Dinghy					= 473,
		Hermes					= 474,
		Sabre					= 475,
		Rustler					= 476,
		Zr350					= 477,
		Walton					= 478,
		Regina					= 479,
		Comet					= 480,
		BMX						= 481,
		Burrito					= 482,
		Camper					= 483,
		Marquis					= 484,
		Baggage					= 485,
		Dozer					= 486,
		Maverick				= 487,
		SanNewsMaverick			= 488,
		Rancher					= 489,
		FBIRancher				= 490,
		Virgo					= 491,
		Greenwood				= 492,
		Jetmax					= 493,
		HotringRacer			= 494,
		Sandking				= 495,
		BlistaCompact			= 496,
		PoliceMaverick			= 497,
		Boxville				= 498,
		Benson					= 499,
		Mesa					= 500,
		RCGoblin				= 501,
		HotringRacerA			= 502,
		HotringRacerB			= 503,
		BloodringBanger			= 504,
		RancherLure				= 505,
		SuperGT					= 506,
		Elegant					= 507,
		Journey					= 508,
		Bike					= 509,
		MountainBike			= 510,
		Beagle					= 511,
		Cropdust				= 512,
		Stuntplane				= 513,
		Tanker					= 514,
		Roadtrain				= 515,
		Nebula					= 516,
		Majestic				= 517,
		Buccaneer				= 518,
		Shamal					= 519,
		Hydra					= 520,
		FCR900					= 521,
		NRG500					= 522,
		HPV1000					= 523,
		CementTruck				= 524,
		TowTruck				= 525,
		Fortune					= 526,
		Cadrona					= 527,
		FBITruck				= 528,
		Willard					= 529,
		Forklift				= 530,
		Tractor					= 531,
		Combine					= 532,
		Feltzer					= 533,
		Remington				= 534,
		Slamvan					= 535,
		Blade					= 536,
		Freight					= 537,
		Brownstreak				= 538,
		Vortex					= 539,
		Vincent					= 540,
		Bullet					= 541,
		Clover					= 542,
		Sadler					= 543,
		FireTruckLA				= 544,
		Hustler					= 545,
		Intruder				= 546,
		Primo					= 547,
		Cargobob				= 548,
		Tampa					= 549,
		Sunrise					= 550,
		Merit					= 551,
		UtilityVan				= 552,
		Nevada					= 553,
		Yosemite				= 554,
		Windsor					= 555,
		MonsterA				= 556,
		MonsterB				= 557,
		Uranus					= 558,
		Jester					= 559,
		Sultan					= 560,
		Stratum					= 561,
		Elegy					= 562,
		Raindance				= 563,
		RCTiger					= 564,
		Flash					= 565,
		Tahoma					= 566,
		Savanna					= 567,
		Bandito					= 568,
		FreightFlatTrailer		= 569,
		StreakTrailer			= 570,
		Kart					= 571,
		Mower					= 572,
		Duneride				= 573,
		Sweeper					= 574,
		Broadway				= 575,
		Tornado					= 576,
		AT400					= 577,
		DFT30					= 578,
		Huntley					= 579,
		Stafford				= 580,
		BF400					= 581,
		Newsvan					= 582,
		Tug						= 583,
		PetrolTrailer			= 584,
		Emperor					= 585,
		Wayfarer				= 586,
		Euros					= 587,
		Hotdog					= 588,
		Club					= 589,
		FreightBoxTrailer		= 590,
		ArticleTrailer3			= 591,
		Andromada				= 592,
		Dodo					= 593,
		RCCam					= 594,
		Launch					= 595,
		PoliceCarLSPD			= 596,
		PoliceCarSFPD			= 597,
		PoliceCarLVPD			= 598,
		PoliceRanger			= 599,
		Picador					= 600,
		SWAT					= 601,
		Alpha					= 602,
		Phoenix					= 603,
		GlendaleShit			= 604,
		SadlerShit				= 605,
		BaggageTrailerA			= 606,
		BaggageTrailerB			= 607,
		TugStairsTrailer		= 608,
		Boxburg					= 609,
		FarmTrailer				= 610,
		UtilityTrailer			= 611,
	};

	Vehicle(int32_t id_)
		: _id(id_)
	{
	}

	
	int32_t id() const { return _id; }

	bool valid() const;

	// A shorthand for this->getVirtualWorld()
	int32_t world() const { return this->getVirtualWorld(); }

	// A shorthand for this->getPosition()
	Vec3f pos() const { return this->getPosition(); }

	// A shorthand for this->getVelocity()
	Vec3f vel() const { return this->getVelocity(); }

	// A shorthand for this->getHealth()
	float hp() const { return this->getHealth(); }

	// A shorthand for this->getDistanceFromPoint()
	float dist(Vec3f const& point_) const { return this->getDistanceFromPoint(point_); }

	// A shorthand for this->getRotationQuat()
	Quat rotQuat() const { return this->getRotationQuat(); }

	static Vehicle create(Model model_, float x_, float y_, float z_, float rotation_, int color1_, int color2_, int respawnDelay_, bool addSiren_);
	static bool manualEngineAndLights();
	static int getComponentType(int component_);
	static bool getModelInfo(Model model_, VehicleModelInfo type_, float * X_, float * Y_, float * Z_);

	float getDistanceFromPoint(Vec3f const& point_) const;
	float getDistanceFromPoint(float x_, float y_, float z_) const;
	bool destroy();
	bool isStreamedIn(int forPlayerIdx_) const;
	Vec3f getPosition() const;
	bool setPosition(Vec3f const& pos_);
	bool setPosition(float x_, float y_, float z_);
	float getZAngle() const;
	Quat getRotationQuat() const;
	bool setZAngle(float angle_);
	bool setParamsForPlayer(int playerIdx_, int objective_, int doorsLocked_);
	bool setParamsEx(int engine_, int lights_, int alarm_, int doors_, int bonnet_, int boot_, int objective_);
	bool getParamsEx(int * engine, int * lights, int * alarm, int * doors, int * bonnet, int * boot, int * objective) const;
	int getSirenState() const;
	bool setCarDoorParams(int driver_, int passenger_, int backleft_, int backright_);
	bool getCarDoorParams(int * driver, int * passenger, int * backleft, int * backright) const;
	bool setCarWindowParams(int driver_, int passenger_, int backleft_, int backright_);
	bool getCarWindowParams(int * driver, int * passenger, int * backleft, int * backright) const;
	bool setToRespawn();
	bool linkToInterior(int interiorIdx_);
	bool addComponent(int componentIdx_);
	bool removeComponent(int componentIdx_);
	bool changeColor(int color1_, int color2_);
	bool changePaintjob(int paintjobIdx_);
	bool setHealth(float health_);
	float getHealth() const;
	bool attachTrailer(Vehicle trailer_);
	bool detachTrailer();
	bool isTrailerAttached() const;
	Vehicle getTrailer() const;
	bool setNumberPlate(std::string const& numberplate_);
	bool setNumberPlate(char const* numberplate_);
	Model getModel() const;
	int getComponentInSlot(int slot_) const;
	bool repair();
	Vec3f getVelocity() const;
	bool setVelocity(Vec3f const& vel_);
	bool setVelocity(float x_, float y_, float z_);
	bool setAngularVelocity(Vec3f const& vel_);
	bool setAngularVelocity(float x_, float y_, float z_);
	bool getDamageStatus(int * panels, int * doors, int * lights, int * tires) const;
	bool updateDamageStatus(int panels_, int doors_, int lights_, int tires_);
	bool setVirtualWorld(int worldIdx_);
	int getVirtualWorld() const;
private:
	int32_t _id;
};

}
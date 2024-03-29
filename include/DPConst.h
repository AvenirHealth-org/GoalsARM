#ifndef DPCONST_H
#define DPCONST_H

namespace DP {
	// +=+ Sex and circumcision constants +======================================+
	enum sex_t {
		FEMALE = 0,
		MALE = 1,  // males, regardless of circumcision status
		MALE_U = 1,  // males, uncircumcised
		MALE_C = 2,  // males, circumcised

		// Bounds, use when looping over sexes and circumcision states
		SEX_MIN = 0,
		SEX_MAX = 1,

		SEX_MC_MIN = 0,
		SEX_MC_MAX = 2
	};

	// Count the number of sexes
	const int N_SEX = SEX_MAX - SEX_MIN + 1;          // sex only
	const int N_SEX_MC = SEX_MC_MAX - SEX_MC_MIN + 1; // sex and circumcision status

	// Map from sex and circumcision status (FEMALE, MALE_U, MALE_C) to sex alone
	const sex_t sex[N_SEX_MC] = { DP::FEMALE, DP::MALE, DP::MALE };

	// +=+ Age types and constants +=============================================+
	// Bounds, use when defining loops over ages
	const int AGE_MIN = 0;
	const int AGE_MAX = 80;
	const int AGE_CHILD_MIN = AGE_MIN;
	const int AGE_CHILD_MAX = 14;
	const int AGE_ADULT_MIN = AGE_CHILD_MAX + 1;
	const int AGE_ADULT_MAX = AGE_MAX;
	const int AGE_BIRTH_MIN = AGE_ADULT_MIN; // minimum reproductive age
	const int AGE_BIRTH_MAX = 49;            // maximum reproductive age

	// Count the number of ages in age ranges 
	const int N_AGE = AGE_MAX - AGE_MIN + 1;
	const int N_AGE_CHILD = AGE_CHILD_MAX - AGE_CHILD_MIN + 1; // number of child ages
	const int N_AGE_ADULT = AGE_ADULT_MAX - AGE_ADULT_MIN + 1; // number of adult ages
	const int N_AGE_BIRTH = AGE_BIRTH_MAX - AGE_BIRTH_MIN + 1; // number of reproductive ages

	// +=+ Risk population types and constants +=================================+
	enum pop_t {
		POP_NOSEX = 0, // male or female, never had sex
		POP_NEVER = 1, // male or female, never married
		POP_UNION = 2, // male or female, married or in stable union
		POP_SPLIT = 3, // male or female, previously married
		POP_PWID  = 4, // male or female, people who inject drugs
		POP_FSW   = 5, // female only, female sex workers
		POP_CSW   = 5, // male only, clients of female sex workers
		POP_BOTH  = 5, // male or female, female sex workers or male clients of female sex workers (TODO: revert to POP_KEY)
		POP_MSM   = 6, // male only, men who have sex with men
		POP_TGW   = 7, // male only, transgender women

		// Bounds, use when looping over populations
		POP_MIN = 0,
		POP_MAX = 7,

		POP_KEY_MIN = 4, // key population bounds
		POP_KEY_MAX = 7,

		POP_FEMALE_MIN = 0, // female population bounds
		POP_FEMALE_MAX = 5,

		POP_MALE_MIN = 0, // male population bounds
		POP_MALE_MAX = 7,
	};

	// Count the number of populations
	const int N_POP = POP_MAX - POP_MIN + 1;
	const int N_POP_SEX[N_SEX] = {POP_FEMALE_MAX - POP_FEMALE_MIN + 1, POP_MALE_MAX - POP_MALE_MIN + 1};

	const int N_POP_KEY = POP_KEY_MAX - POP_KEY_MIN + 1;

	// Partnership or relationship types ("bond" isn't so verbose)
	enum bond_t {
		BOND_UNION  = 0, // heterosexual marital or cohabitating
		BOND_CASUAL = 1, // heterosexual everything else
		BOND_PAID   = 2, // heterosexual with sex worker
		BOND_SAME   = 3, // same-sex partnerships (effectively means MSM, not WSW)

		BOND_MIN = 0,
		BOND_MAX = 3
	};

	const int N_BOND = BOND_MAX - BOND_MIN + 1;

	// +=+ HIV infection stage constants +=======================================+

	enum hiv_t {
		// child categories (CD4 percent), ages 0-4
		HIV_PRC_GT_30 = 0,
		HIV_PRC_26_30 = 1,
		HIV_PRC_21_25 = 2,
		HIV_PRC_16_20 = 3,
		HIV_PRC_11_15 = 4,
		HIV_PRC_05_10 = 5,
		HIV_PRC_LT_05 = 6,

		// child categories, ages 5-14
		HIV_PED_GEQ_1000 = 0,
		HIV_PED_750_1000 = 1,
		HIV_PED_500_750 = 2,
		HIV_PED_350_500 = 3,
		HIV_PED_200_350 = 4,
		HIV_PED_LT_200 = 5,
		HIV_PED_INVALID = 6, // Not used

		// Adult (ages 15+) categories, defined by CD4 counts
		HIV_PRIMARY = 0,
		HIV_GEQ_500 = 1,
		HIV_350_500 = 2,
		HIV_200_350 = 3,
		HIV_100_200 = 4,
		HIV_050_100 = 5,
		HIV_000_050 = 6,

		// Bounds, use when looping over adult HIV infection stages
		HIV_CHILD_PRC_MIN = 0, // Children aged 0-4
		HIV_CHILD_PRC_MAX = 6, // Children aged 0-4
		HIV_CHILD_PED_MIN = 0, // Children aged 5-14
		HIV_CHILD_PED_MAX = 5, // Children aged 5-14

		HIV_CHILD_MIN = 0,
		HIV_CHILD_MAX = 6,

		HIV_ADULT_MIN = 0,
		HIV_ADULT_MAX = 6,

		HIV_MIN = 0,
		HIV_MAX = 6
	};

	const int N_HIV_CHILD = HIV_CHILD_MAX - HIV_CHILD_MIN + 1;
	const int N_HIV_CHILD_PED = HIV_CHILD_PED_MAX - HIV_CHILD_PED_MIN + 1;
	const int N_HIV_ADULT = HIV_ADULT_MAX - HIV_ADULT_MIN + 1;
	const int N_HIV = HIV_MAX - HIV_MIN + 1;

	// broad stages used to characterize HIV infectiousness
	enum stage_t {
		STAGE_PRIMARY = 0,
		STAGE_CHRONIC = 1,
		STAGE_SYMPTOM = 2,

		STAGE_MIN = 0,
		STAGE_MAX = 2
	};

	const int N_STAGE = STAGE_MAX - STAGE_MIN + 1;

	// Map from CD4 categories (hiv_t) to infectiousness stages
	const stage_t stage[N_HIV_ADULT] = {STAGE_PRIMARY,  // HIV_PRIMARY
									    STAGE_CHRONIC,  // HIV_GEQ_500
									    STAGE_CHRONIC,  // HIV_350_500
									    STAGE_CHRONIC,  // HIV_200_350
									    STAGE_SYMPTOM,  // HIV_100_200
									    STAGE_SYMPTOM,  // HIV_050_100
									    STAGE_SYMPTOM}; // HIV_000_050

	// +=+ HIV diagnosis (Dx) and treatment (Tx) constants +=====================+

	enum dtx_t {
		DTX_UNAWARE = 0, // HIV-positive but status-unaware
		DTX_AWARE   = 1, // HIV-positive and status-aware but not on ART
		DTX_PREV_TX = 2, // HIV-positive and previously on ART
		DTX_ART1    = 3, // Months [0,6) on ART
		DTX_ART2    = 4, // Months [6,12) on ART
		DTX_ART3    = 5, // Months [12,\infty) on ART

		// Bounds, use when looping over HIV diagnosis and treatment states
		DTX_MIN = 0,
		DTX_MAX = 5,

		// Bounds for looping just for off-ART states
		DTX_OFF_MIN = 0,
		DTX_OFF_MAX = 2,

		// Bounds for looping just over on-ART states
		DTX_ART_MIN = 3,
		DTX_ART_MAX = 5
	};

	const int N_DTX = DTX_MAX - DTX_MIN + 1;
	const int N_ART = DTX_ART_MAX - DTX_ART_MIN + 1;

	// +=+ Viral load constants +================================================+
	enum viral_load_t {
		VL_OFF_ART = 0, // not on ART, assumed virally unsuppressed
		VL_SUCCESS = 1, // on ART and virally suppressed
		VL_FAILURE = 2, // on ART and virally unsuppressed (may include people who recently started ART)
		VL_MIN = 0,
		VL_MAX = 2
	};

	const int N_VL = VL_MAX - VL_MIN + 1;

	// +=+ STI symptomatic status constants +====================================+
	enum sti_t {
		STI_NONE = 0, // STI symptoms present in neither partner
		STI_HIVN = 1, // STI symptoms present in HIV-negative partner only
		STI_HIVP = 2, // STI symptoms present in HIV-positive partner only
		STI_BOTH = 3, // STI symptoms present in both partners
		STI_MIN = 0,
		STI_MAX = 3
	};

	const int N_STI = STI_MAX - STI_MIN + 1;

	// +=+ Time steps per year for HIV dynamics +=+
	const int HIV_TIME_STEPS = 10;
	const double HIV_STEP_SIZE = 1.0 / HIV_TIME_STEPS;

	// +=+ Constants for dynamics assumptions +==================================+

	// Bounds on CD4 cell counts in adults living with HIV
#ifndef SPECTRUM_CD4
	const int CD4_ADULT_LOWER[N_HIV_ADULT] = { 500, 500, 350, 200, 100,  50,  0 };
	const int CD4_ADULT_UPPER[N_HIV_ADULT] = { 999, 999, 500, 350, 200, 100, 50 };
#else
	// Enabling SPECTRUM_CD4 changed the interpretation of adult CD4 categories
	// to match Spectrum categories: >500, [350,500), [250,350), [200,250), [100, 200), [50, 100), [0,50)
	const int CD4_ADULT_LOWER[N_HIV_ADULT] = { 500, 350, 250, 200, 100,  50,  0 };
	const int CD4_ADULT_UPPER[N_HIV_ADULT] = { 999, 500, 350, 250, 200, 100, 50 };
#endif

#ifndef SPECTRUM_CD4
	// adults who initiate ART while in stage h and ART duration d return to 
	// infection stage ART_EXIT_STAGE[h][d] at ART interruption. We use -1 as the 
	// destination for people off ART (d=DTX_UNAWARE, d=DTX_AWARE, d=DTX_PREV_TX) as
	// ART interruption is not valid in those states
	const int ART_EXIT_STAGE[N_HIV_ADULT][N_DTX] = {
		{-1, -1, -1, HIV_GEQ_500, HIV_GEQ_500, HIV_GEQ_500}, // baseline h=HIV_PRIMARY
		{-1, -1, -1, HIV_GEQ_500, HIV_GEQ_500, HIV_GEQ_500}, // baseline h=HIV_GEQ_500
		{-1, -1, -1, HIV_350_500, HIV_350_500, HIV_GEQ_500}, // baseline h=HIV_350_500 
		{-1, -1, -1, HIV_200_350, HIV_200_350, HIV_350_500}, // baseline h=HIV_200_350 
		{-1, -1, -1, HIV_100_200, HIV_100_200, HIV_200_350}, // baseline h=HIV_100_200 
		{-1, -1, -1, HIV_050_100, HIV_050_100, HIV_100_200}, // baseline h=HIV_050_100 
		{-1, -1, -1, HIV_000_050, HIV_000_050, HIV_050_100}, // baseline h=HIV_000_050 
	};
#else
	const int ART_EXIT_STAGE[N_HIV_ADULT][N_DTX] = {
		{-1, -1, -1, HIV_PRIMARY, HIV_PRIMARY, HIV_PRIMARY}, // Goals HIV_PRIMARY represents Spectrum CD4>500
		{-1, -1, -1, HIV_GEQ_500, HIV_GEQ_500, HIV_PRIMARY}, // Goals HIV_GEQ_500 represents Spectrum 350-500
		{-1, -1, -1, HIV_350_500, HIV_350_500, HIV_GEQ_500}, // Goals HIV_350_500 represents Spectrum 250-350
		{-1, -1, -1, HIV_200_350, HIV_200_350, HIV_350_500}, // Goals HIV_200_350 represents Spectrum 200-250
		{-1, -1, -1, HIV_100_200, HIV_100_200, HIV_200_350}, // Goals HIV_100_200 represents Spectrum 100-200
		{-1, -1, -1, HIV_050_100, HIV_050_100, HIV_100_200}, // Goals HIV_050_100 represents Spectrum  50-100
		{-1, -1, -1, HIV_000_050, HIV_000_050, HIV_050_100}, // Goals HIV_000_050 represents Spectrum   0-50
	};
#endif

	// constant array used to assign partnership types for non-marital, non-cohabiting
	// partnerships based on sex and behavioral risk group. We use BOND_SAME for
	// same-sex partnerships, BOND_PAID for heterosexual partnerships involving an
	// FSW, and BOND_CASUAL for everything else. -1 indicates invalid pairings that
	// involve at least one sexually inactive partner.
	const int BOND_TYPE[N_SEX][N_POP][N_SEX][N_POP] {
	   // NOSEX,    NEVER,       UNION,       SPLIT,        PWID,     FSW/MSM,       TRANS
	   {{{-1,          -1,          -1,          -1,          -1,          -1,          -1},   // [FEMALE][NOSEX][FEMALE][...]
		 {-1,          -1,          -1,          -1,          -1,          -1,          -1}},  // [FEMALE][NOSEX][MALE  ][...]
		{{-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME},   // [FEMALE][NEVER][FEMALE][...]
		 {-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL}},  // [FEMALE][NEVER][MALE  ][...]
		{{-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME},   // [FEMALE][UNION][FEMALE][...]
		 {-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL}},  // [FEMALE][UNION][MALE  ][...]
		{{-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME},   // [FEMALE][SPLIT][FEMALE][...]
		 {-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL}},  // [FEMALE][SPLIT][MALE  ][...]
		{{-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME},   // [FEMALE][PWID ][FEMALE][...]
		 {-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL}},  // [FEMALE][PWID ][MALE  ][...]
		{{-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME},   // [FEMALE][FSW  ][FEMALE][...]
		 {-1,   BOND_PAID,   BOND_PAID,   BOND_PAID,   BOND_PAID,   BOND_PAID,   BOND_PAID}},  // [FEMALE][FSW  ][MALE  ][...]
		{{-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME},   // [FEMALE][TRANS][FEMALE][...]
		 {-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL}}}, // [FEMALE][TRANS][ MALE ][...]
		 
	   {{{-1,          -1,          -1,          -1,          -1,          -1,          -1},   // [MALE][NOSEX][FEMALE][...]
		 {-1,          -1,          -1,          -1,          -1,          -1,          -1}},  // [MALE][NOSEX][MALE  ][...]
		{{-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL,   BOND_PAID, BOND_CASUAL},   // [MALE][NEVER][FEMALE][...]
		 {-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME}},  // [MALE][NEVER][MALE  ][...]
		{{-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL,   BOND_PAID, BOND_CASUAL},   // [MALE][UNION][FEMALE][...]
		 {-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME}},  // [MALE][UNION][MALE  ][...]
		{{-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL,   BOND_PAID, BOND_CASUAL},   // [MALE][SPLIT][FEMALE][...]
		 {-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME}},  // [MALE][SPLIT][MALE  ][...]
		{{-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL,   BOND_PAID, BOND_CASUAL},   // [MALE][PWID ][FEMALE][...]
		 {-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME}},  // [MALE][PWID ][MALE  ][...]
		{{-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL,   BOND_PAID, BOND_CASUAL},   // [MALE][MSM  ][FEMALE][...]
		 {-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME}},  // [MALE][MSM  ][MALE  ][...]
		{{-1, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL, BOND_CASUAL,   BOND_PAID, BOND_CASUAL},   // [MALE][TRANS][FEMALE][...]
		 {-1,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME,   BOND_SAME}}}  // [MALE][TRANS][ MALE ][...]
	};

	// Maps from CD4 percentages to CD4 counts when HIV+ children reach age 5
	// These were taken from AIM on 2023-06-02 (doi:10.1002/jia2.25778), rounded to 6 digits
	const double CD4_MAP_AGE_5[N_HIV][N_HIV] = {
		//>1000    750-999   500-749   350-499   200-349   <200      Invalid
		{0.608439, 0.185181, 0.105789, 0.055594, 0.018498, 0.026497, 0.0},  // h=HIV_PRC_GT_30
		{0.338734, 0.222622, 0.293529, 0.093509, 0.035504, 0.016102, 0.0},  // h=HIV_PRC_26_30
		{0.200400, 0.256200, 0.363600, 0.107400, 0.057900, 0.014500, 0.0},  // h=HIV_PRC_21_25
		{0.095000, 0.169300, 0.308200, 0.249700, 0.144900, 0.032900, 0.0},  // h=HIV_PRC_16_20
		{0.038804, 0.090309, 0.275928, 0.259926, 0.255726, 0.079308, 0.0},  // h=HIV_PRC_11_15
		{0.018616, 0.018616, 0.099218, 0.165066, 0.363501, 0.334984, 0.0},  // h=HIV_PRC_05_10
		{0.000000, 0.001400, 0.009901, 0.007101, 0.049605, 0.931993, 0.0}}; // h=HIV_PRC_LT_05

}

#endif // DPCONST_H

/////////////////////////////////////////////////////////////////////
//Plugin to add the strangeness particles Lambda(1405) and Sigma(1385)
//
//Pids are 70-73
//
//This plugin is automatically enabled. If you don't like it, call
//makeDistributionManager()->Disable("strangeness");
//in the very beginning of your macro
//
//////////////////////////////////////////////////////////////////////

#include "PStrangenessPlugin.h"

#include "PDistributionManager.h"
#include "PResonanceDalitz.h"

PStrangenessPlugin::PStrangenessPlugin(const Char_t *id, const Char_t *de):
    PDistributionCollection(id, de) {
    is_initialized = 0;
    //    RequiresPlugin("elementary");
}

Bool_t PStrangenessPlugin::Activate(void) {
    return kTRUE;
}

PStrangenessPlugin::~PStrangenessPlugin() {
}


Bool_t PStrangenessPlugin::ExecCommand(const char *command, Double_t) {

    if (strcmp (command,"init") == 0) {
	if (!is_initialized) {
	    is_initialized = 1;

	    Double_t *system_alloc_verbosity = makeStaticData()->GetBatchValue("_system_alloc_verbosity");
	    Double_t old = (*system_alloc_verbosity);
	    (*system_alloc_verbosity) = 0;

	    if (makeStaticData()->AddParticle(70, "Lambda1405", 1.406) > 0) {
		makeStaticData()->AddAlias("Lambda1405", "Lambda(1405)");

		makeStaticData()->SetParticleTotalWidth("Lambda1405", 0.05);
		makeStaticData()->SetParticleBaryon("Lambda1405", 1);


		makeStaticData()->AddDecay("Lambda(1405)0 --> Sigma+ + pi-", "Lambda1405",
					   "Sigma+,pi-", .3333 );
		makeStaticData()->AddDecay("Lambda(1405)0 --> Sigma- + pi+", "Lambda1405",
					   "Sigma-,pi+", .3333 );
		makeStaticData()->AddDecay("Lambda(1405)0 --> Sigma0 + pi0", "Lambda1405",
					   "Sigma0,pi0", .3333 );


		makeStaticData()->AddParticle(71, "Sigma1385+", 1.3828);
		makeStaticData()->AddAlias("Sigma1385+", "Sigma(1385)+");
		makeStaticData()->SetParticleTotalWidth("Sigma1385+", 0.0358);
		makeStaticData()->SetParticleBaryon("Sigma1385+", 1);
		makeStaticData()->SetParticleLMass("Sigma1385+", 1.2);

		makeStaticData()->AddDecay("Sigma(1385)+ --> Lambda + pi+", "Sigma1385+",
					   "Lambda,pi+", .8815 );
		makeStaticData()->AddDecay("Sigma(1385)+ --> Sigma+ + pi0", "Sigma1385+",
					   "Sigma+, pi0", .05925);
		makeStaticData()->AddDecay("Sigma(1385)+ --> Sigma0 + pi+", "Sigma1385+",
					   "Sigma0, pi+", .05925);



		makeStaticData()->AddParticle(72, "Sigma1385-", 1.3872);
		makeStaticData()->AddAlias("Sigma1385-", "Sigma(1385)-");
		makeStaticData()->SetParticleTotalWidth("Sigma1385-", 0.0394);
		makeStaticData()->SetParticleBaryon("Sigma1385-", 1);
		makeStaticData()->SetParticleLMass("Sigma1385-", 1.2);

		makeStaticData()->AddDecay("Sigma(1385)- --> Lambda + pi-", "Sigma1385-",
					   "Lambda,pi-", .8815 );
		makeStaticData()->AddDecay("Sigma(1385)- --> Sigma- + pi0", "Sigma1385-",
					   "Sigma-, pi0", .05925);
		makeStaticData()->AddDecay("Sigma(1385)- --> Sigma0 + pi-", "Sigma1385-",
					   "Sigma0, pi-", .05925);



		makeStaticData()->AddParticle(73, "Sigma13850", 1.3837);
		makeStaticData()->AddAlias("Sigma13850", "Sigma(1385)0");
		makeStaticData()->SetParticleTotalWidth("Sigma13850", 0.0365);
		makeStaticData()->SetParticleBaryon("Sigma13850", 1);
		makeStaticData()->SetParticleLMass("Sigma13850", 1.2);

		makeStaticData()->AddDecay("Sigma(1385)0 --> Lambda + pi0", "Sigma13850",
					   "Lambda,pi0", .87000 );
		makeStaticData()->AddDecay("Sigma(1385)0 --> Lambda + g", "Sigma13850",
					   "Lambda,g", .01300 );
		makeStaticData()->AddDecay("Sigma(1385)0 --> Sigma+ + pi-", "Sigma13850",
					   "Sigma+, pi-", .05850);
		makeStaticData()->AddDecay("Sigma(1385)0 --> Sigma- + pi+", "Sigma13850",
					   "Sigma-, pi+", .05850);


                makeStaticData()->AddParticle(74,"Lambda15200", 1.5195);
                makeStaticData()->AddAlias("Lambda15200","Lambda(1520)0");
                makeStaticData()->SetParticleTotalWidth("Lambda15200",0.0156);
                makeStaticData()->SetParticleBaryon("Lambda15200",1);
                makeStaticData()->SetParticleSpin("Lambda15200",3);
                makeStaticData()->SetParticleParity("Lambda15200",1);

                makeStaticData()->AddDecay("Lambda(1520)0 --> Sigma0 + pi0", "Lambda15200",
                                           "Sigma0, pi0", .139096); // -
                makeStaticData()->AddDecay("Lambda(1520)0 --> Sigma0 + pi0 + pi0", "Lambda15200",
                                           "Sigma0, pi0, pi0", .009/5.0); // -
                makeStaticData()->AddDecay("Lambda(1520)0 --> Sigma0 + pi+ + pi-", "Lambda15200",
                                           "Sigma0, pi+, pi-", .009/5.0); // -
                makeStaticData()->AddDecay("Lambda(1520)0 --> Lambda + pi0 + pi0", "Lambda15200",
                                           "Lambda, pi0, pi0", .1/3.0); // -
                makeStaticData()->AddDecay("Lambda(1520)0 --> Lambda + g", "Lambda15200",
                                           "Lambda, g", .0085);

                makeStaticData()->AddDecay("Lambda(1520)0 --> Lambda + dilepton", "Lambda15200",
                                           "Lambda, dilepton", .007948/137.);

                PResonanceDalitz * L15200_dalitz = new PResonanceDalitz("Lambda15200_dalitz@Lambda15200_to_Lambda_dilepton","dgdm from Zetenyi/Wolf", -1);
                L15200_dalitz->setGm(0.719);
                makeDistributionManager()->Add(L15200_dalitz);


                makeStaticData()->AddParticle(79, "Delta2050++", 2.05);
                makeStaticData()->AddAlias("Delta2050++", "Delta(2050)++");
                makeStaticData()->SetParticleTotalWidth("Delta2050++", 0.25);
                makeStaticData()->SetParticleBaryon("Delta2050++", 1);

                makeStaticData()->AddDecay("Delta(2050)++ --> Sigma(1385)+ + K+",
                                           "Delta2050++", "Sigma1385+,K+", 1.0);

	    } else {
		Error("ExecCommand", "PIDs blocked, plugin disabled");
	    }

	    (*system_alloc_verbosity) = old;
	}
	return kTRUE;
    }

    return kFALSE;
}


ClassImp(PStrangenessPlugin)


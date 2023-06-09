/////////////////////////////////////////////////////////////////////
//Plugin to add the N* resonances for PWA analysis
//
//Pids are 70-73
//
//This plugin is automatically enabled. If you don't like it, call
//makeDistributionManager()->Disable("pwa_resonances");
//in the very beginning of your macro
//
//////////////////////////////////////////////////////////////////////

#include "PPWAResonancesPlugin.h"

#include "PDistributionManager.h"
#include "PResonanceDalitz.h"

Bool_t PPWAResonancesPlugin::verbose_mode{kFALSE};

PPWAResonancesPlugin::PPWAResonancesPlugin(const Char_t *id, const Char_t *de): PDistributionCollection(id, de),
    is_initialized(0) {
}

Bool_t PPWAResonancesPlugin::Activate(void) {
    return kTRUE;
}

PPWAResonancesPlugin::~PPWAResonancesPlugin() {
}


Bool_t PPWAResonancesPlugin::ExecCommand(const char *command, Double_t) {

    if (strcmp (command,"init") == 0) {
        if (!is_initialized) {
            is_initialized = 1;

            Double_t *system_alloc_verbosity = makeStaticData()->GetBatchValue("_system_alloc_verbosity");
            Double_t old = (*system_alloc_verbosity);
            (*system_alloc_verbosity) = 0;

            const int nstar_cnt = 8;
            const int nstar_num[nstar_cnt] = {1650, 1710, 1720, 1875, 1880, 1895, 1900, 2190};
            const float nstar_mass[nstar_cnt] = {1.655, 1.710, 1.720, 1.875, 1.870, 1.895, 1.900, 2.190};
            const float nstar_width[nstar_cnt] = {0.150, 0.200, 0.250, 0.220, 0.235, 0.090, 0.250, 0.0250};

            for (int i = 0; i < nstar_cnt; ++i)
            {
                char* res_decay = new char[200];
                char* res_name = new char[200];

                sprintf(res_name, "N*(%d)+", nstar_num[i]);
                sprintf(res_decay, "%s --> Lambda + K+", res_name);
                makeStaticData()->AddParticle(-1, res_name, nstar_mass[i]); // Mass in GeV/c2
                makeStaticData()->SetParticleTotalWidth(res_name, nstar_width[i]);
                makeStaticData()->SetParticleBaryon(res_name, 1);
                makeStaticData()->AddDecay(res_decay, res_name, "Lambda,K+", 1);

                if (verbose_mode) listParticle(res_name);
            }

            (*system_alloc_verbosity) = old;
        }
        return kTRUE;
    }

    return kFALSE;
}


ClassImp(PPWAResonancesPlugin)


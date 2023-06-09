// Author: R. Lalik
// Written: 08.06.2023
// Revised:
//


#ifndef _PPWARESONANCES_PLUGIN_H_
#define _PPWARESONANCES_PLUGIN_H_

#include "TROOT.h"

#include "PChannelModel.h"
#include "PDistributionManagerUtil.h"
#include "PDistributionCollection.h"

using namespace std;

class PPWAResonancesPlugin : public PDistributionCollection {

 public:

    //constructor
    PPWAResonancesPlugin(const Char_t *id, const Char_t *de);
    //destructor
    ~PPWAResonancesPlugin();

    Bool_t ExecCommand(const char *command, Double_t value);
    Bool_t Activate(void);

    static void EnableVerboseMode(Bool_t verbose) { verbose_mode = verbose; }

 private:

    Int_t is_initialized;

    static Bool_t verbose_mode;

    ClassDef(PPWAResonancesPlugin, 0)
};

#endif //_PPWARESONANCES_PLUGIN_H_








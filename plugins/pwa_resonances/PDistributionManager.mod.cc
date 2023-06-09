//this line is added to the PDistributionManager.cc

PPWAResonancesPlugin *pwa_res = new PPWAResonancesPlugin("pwa_resonances", "PWA Resonances");
AddPlugin(pwa_res);
Enable("pwa_resonances");
PluginInfo("Baryonic resonances for PWA analysis");


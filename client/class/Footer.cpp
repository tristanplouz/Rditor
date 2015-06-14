#include "../class/Footer.h"

Footer::Footer(): footerBox(true),version(),nbrLigne(),status(),saved(){

  version.push("0.1.0");
  nbrLigne.push("Not Supported");
  status.push("Ready");
  footerBox.pack_start(version);
  footerBox.pack_start(status);
  footerBox.pack_start(saved);
  footerBox.pack_start(nbrLigne);


}

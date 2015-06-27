#ifndef DEF_FENETRE
#define DEF_FENETRE

//#include <gtkmm.h>
//ATTENTION ENTETE SIMPLIFIE
#include <gtkmm/box.h>
#include <gtkmm/messagedialog.h>
#include "../class/Menu.h"
#include "../class/Body.h"
#include "../class/Footer.h"
#include "../class/Snippet.h"
#include "../class/Netconnection.h"



class Fenetre : public Gtk::Window {
    public :
        Fenetre();

    private :
      Menu menu;
      Body body;
      Footer footer;
      Snippet snippet;
      Netconnection networkManager;
      Gtk::VBox boiteV;
      int mode;//1:code 2:texte 3:dessin

};

#endif

#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtkmm.h>
#include "../class/Menu.h"
#include "../class/Body.h"
#include "../class/Footer.h"
#include "../class/Snippet.h"



class Fenetre : public Gtk::Window {
    public :
        Fenetre();

    private :
      Menu menu;
      Body body;
      Footer footer;
      Snippet snippet;
      Gtk::VBox boiteV;

};

#endif

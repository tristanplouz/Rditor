#ifndef DEF_FOOTER
#define DEF_FOOTER

#include <gtkmm.h>

class Footer: public Gtk::Window{

  public:
    Footer();
    Gtk::HBox footerBox;
    Gtk::Statusbar status;
    Gtk::Statusbar saved;

  private:
    Gtk::Statusbar version;
    Gtk::Statusbar nbrLigne;



};

#endif

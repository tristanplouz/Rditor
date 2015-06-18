#ifndef DEF_FOOTER
#define DEF_FOOTER

#include <gtkmm.h>

class Footer: public Gtk::Window {

  public:
    Footer();
    Gtk::HBox footerBox;
    Gtk::Statusbar status;
    Gtk::Statusbar saved;
    Gtk::Statusbar nbrLigne;

  private:
    Gtk::Statusbar version;




};

#endif

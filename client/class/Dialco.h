#ifndef DEF_DIALCO
#define DEF_DIALCO

#include <gtkmm.h>

class Dialco:public Gtk::Dialog{
  public:
    Dialco(std::string titre, Gtk::Window* parent);
    void getData();
    std::string pseudo, ip;
    int room,port;
    Gtk::SpinButton salon,zonePort;
    Gtk::Entry zonePseudo,zoneIp;

  private:
    Gtk::Box* boiteV;

    Glib::RefPtr<Gtk::Adjustment> adjustSalon,adjustPort;


};

#endif

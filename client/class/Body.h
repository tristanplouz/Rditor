#ifndef DEF_BODY
#define DEF_BODY

#include <gtkmm.h>

class Body: public Gtk::Window {

    public:
      Body();
      Gtk::VBox bodyBox;
      void openText(std::string text);
      void addText(std::string data);
      std::string getData();
      Glib::RefPtr<Gtk::TextBuffer> bufferText;
      Gtk::TextView zoneTexte;

    private:

      Gtk::ScrolledWindow scroll;

};

#endif

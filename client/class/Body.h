#ifndef DEF_BODY
#define DEF_BODY

#include <gtkmm.h>

class Body: public Gtk::Window {

    public:
      Body();
      //Conteneur
      Gtk::HBox bodyBox;

      //Contenu
      Glib::RefPtr<Gtk::TextBuffer> bufferProg;
      Gtk::Label indev;
      Gtk::Expander chatBox;
      Gtk::ScrolledWindow scrollProg;

      //Function
      void openText(std::string text);
      void addText(std::string data);
      std::string getData();

    private:
      Gtk::TextView zoneProg;

      //chat
      Gtk::VBox chat;
      Gtk::Label chatContent;
      Gtk::Entry chatTextSend;
      Gtk::Button bouton;

};

#endif

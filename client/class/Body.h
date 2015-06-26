#ifndef DEF_BODY
#define DEF_BODY

#include <gtkmm.h>
#include <gtksourceviewmm.h>

class Body: public Gsv::Buffer {

    public:
      Body();
      //Conteneur
      Gtk::HBox bodyBox;

      //Contenu
      //Glib::RefPtr<Gtk::TextBuffer> bufferProg;
      Glib::RefPtr<Gsv::Buffer> bufferProg;
      Gtk::Label indev;
      Gtk::Expander chatBox;
      Gtk::ScrolledWindow scrollProg;

      //Function
      void openText(std::string text);
      void addText(std::string data);
      std::string getData();

    private:
      Gsv::View zoneProg;

      //chat
      Gtk::VBox chat;
      Gtk::HBox sender;
      Gtk::Label chatContent;
      Gtk::Entry chatTextSend;
      Gtk::Button boutonSend;

};

#endif

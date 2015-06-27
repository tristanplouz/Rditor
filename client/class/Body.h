#ifndef DEF_BODY
#define DEF_BODY

//#include <gtkmm.h>
//ATTENTION ENTETE SIMPLIFIE
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/expander.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/entry.h>
#include <gtkmm/stockitem.h>
#include <gtkmm/stock.h>

#include <gtksourceviewmm/buffer.h>
#include <gtksourceviewmm/view.h>

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

#ifndef DEF_SNIPPET
#define DEF_SNIPPET

#include <string>
//ATENTION ENTETE SIMPLIFIE
#include <gtkmm/messagedialog.h>

class Snippet: public Gtk::Window {

    public:
      Snippet();
      std::string html,contidion,boucleFor, boucleWhile;
};

#endif

#include <iostream>
#include <string>
#include <gtkmm.h>
#include "class/Fenetre.h"

//class main du programme
int main(int argc, char* argv[]) {
    Gtk::Main app(argc, argv);
    Fenetre fenetre;
    Gtk::Main::run(fenetre);
    return 0;
}

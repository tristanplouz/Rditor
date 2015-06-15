#ifndef DEF_MENU
#define DEF_MENU

#include <gtkmm.h>

//class pas tres propre gerant les differents menus

class Menu: public Gtk::Window {
    public:
        Menu();

        //boite resultante
        Gtk::VBox boiteMenu;

        //Contenu sous menu Mode
        Gtk::RadioButtonGroup grModeRadio;
        Gtk::RadioMenuItem code,text,dessin;

        //Action
        Glib::RefPtr<Gtk::Action> ouvrirAc;
        Glib::RefPtr<Gtk::Action> enregistrerAc;
        Glib::RefPtr<Gtk::Action> connectAc;

        //barre de menu dedier
        Gtk::MenuBar barreProg;
        Gtk::MenuBar barreText;
        Gtk::MenuBar barreDessin;

        //snippet
        Gtk::MenuItem html;
        Gtk::MenuItem bouclefor;
        Gtk::MenuItem bouclewhile;
        Gtk::MenuItem condition;

        //Data
        std::string actualFile;

        //Fonction
        bool sauverFunction(std::string data);
        std::string ouvrirFunction();

    private:

      //Menu et toolbarre
      Gtk::MenuBar barreMenu;
      Gtk::Toolbar barreOutils;

      //Menu
      Gtk::MenuItem menuItemFichier;
      Gtk::MenuItem menuItemEdition;
      Gtk::MenuItem menuItemReseau;
      Gtk::MenuItem menuItemMode;


      Gtk::MenuItem menuItemSnippet;

      //Sous menu (conteneur du contenu)
      Gtk::Menu menuFichier;
      Gtk::Menu menuSnippet;
      Gtk::Menu menuReseau;
      Gtk::Menu menuMode;

      //Contenu sous menu Fichier
      Gtk::ImageMenuItem fermer;
      //Save et Open en public

      //Separateur
      Gtk::SeparatorMenuItem separateur;
      Gtk::SeparatorToolItem separateurBarreOutils;

      //fonctions
      std::string ouvrirFichier(std::string fileName);


};

#endif

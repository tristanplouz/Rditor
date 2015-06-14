#ifndef DEF_MENU
#define DEF_MENU

#include <gtkmm.h>


class Menu: public Gtk::Window {
    public:
        Menu();
        Gtk::MenuBar barreMenu;
        Gtk::Toolbar barreOutils;

        //Action
        Glib::RefPtr<Gtk::Action> ouvrirAc;
        Glib::RefPtr<Gtk::Action> enregistrerAc;
        Glib::RefPtr<Gtk::Action> connectAc;

        //Data
        std::string actualFile;

        //Fonction
        bool sauverFunction(std::string data);
        std::string ouvrirFunction();

        //snippet
        Gtk::MenuItem html;
        Gtk::MenuItem bouclefor;
        Gtk::MenuItem bouclewhile;
        Gtk::MenuItem condition;

    private:

      //Menu
      Gtk::MenuItem menuItemFichier;
      Gtk::MenuItem menuItemEdition;
      Gtk::MenuItem menuItemSnippet;
      Gtk::MenuItem menuItemReseau;

      //Sous menu (conteneur du contenu)
      Gtk::Menu menuFichier;
      Gtk::Menu menuSnippet;
      Gtk::Menu menuReseau;

      //Contenu sous menu Fichier
      Gtk::ImageMenuItem fermer;
      //Save et Open en public

      //Contenu sous menu Snippet


      //Contenu sous menu reseau
      Gtk::ImageMenuItem host;
      Gtk::ImageMenuItem connect;

      //Separateur
      Gtk::SeparatorMenuItem separateur;
      Gtk::SeparatorToolItem separateurBarreOutils;

      //fonctions
      std::string ouvrirFichier(std::string fileName);


};

#endif

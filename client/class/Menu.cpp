#include "../class/Menu.h"
#include <fstream>
#include <iostream>

//menuFichier.append(*(actionNouveau->create_menu_item()));


Menu::Menu():  barreMenu(),
                          menuItemFichier("Fichier"),menuFichier(),ouvrirAc(Gtk::Action::create("Ouvrir",Gtk::Stock::OPEN)),enregistrerAc(Gtk::Action::create("Enregistrer",Gtk::Stock::SAVE_AS)),fermer(Gtk::Stock::CLOSE),
                          menuItemEdition("Edition"),
                          menuItemReseau("Réseau"),menuReseau(),host("Heberger"),connectAc(Gtk::Action::create("Se connecter",Gtk::Stock::CONNECT)),
                          menuItemSnippet("Snippet"),menuSnippet(),html("HTML"),bouclefor("For"),bouclewhile("While"),condition("If"),
                          separateur()  {

  menuItemFichier.set_submenu(menuFichier);
  menuFichier.append(*(ouvrirAc->create_menu_item()));
  menuFichier.append(*(enregistrerAc->create_menu_item()));
  menuFichier.append(separateur);
  menuFichier.append(fermer);

  menuItemSnippet.set_submenu(menuSnippet);
  menuSnippet.append(html);
  menuSnippet.append(bouclefor);
  menuSnippet.append(bouclewhile);
  menuSnippet.append(condition);

  menuItemReseau.set_submenu(menuReseau);
  menuReseau.append(*(connectAc->create_menu_item()));


  barreMenu.append(menuItemFichier);
  //barreMenu.append(menuItemEdition);
  barreMenu.append(menuItemReseau);
  barreMenu.append(menuItemSnippet);

  //Ajout des signaux pour le menu
  fermer.signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));
  //menuOuvrir.signal_activate().connect(sigc::mem_fun(*this,&Menu::ouvrirFunction)); Deplacé dans le Fenetre.cpp


  //Toolbar
  barreOutils.append(*(ouvrirAc->create_tool_item()));
  barreOutils.append(*(enregistrerAc->create_tool_item()));
  barreOutils.append(separateurBarreOutils);
  barreOutils.append(*(connectAc->create_tool_item()));


}


//Fonctions recuperées sur Openclassroom http://openclassrooms.com/courses/creer-des-interfaces-graphiques-en-c-avec-gtkmm/
std::string Menu::ouvrirFunction(){

  Gtk::FileChooserDialog ouverture(*this, "Ouverture d'un fichier");
  ouverture.set_current_folder(Glib::get_home_dir());
  ouverture.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
  ouverture.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

  std::string texte;
  int reponse = ouverture.run();
  if(reponse == Gtk::RESPONSE_OK) {
    std::string file = ouverture.get_filename();
    actualFile = file;
    texte = Menu::ouvrirFichier(file);
    ouverture.hide();
  }
  else{
    ouverture.hide();
    Gtk::MessageDialog dialogue(*this, "Aucun fichier selectionné!", false, Gtk::MESSAGE_INFO);
    dialogue.run();
  }
  return texte;
  //Gtk::MessageDialog dialogue(*this, "ficher" + texte + ".", false, Gtk::MESSAGE_INFO);
  //dialogue.run();
}


std::string Menu::ouvrirFichier(std::string fileName){

  std::ifstream fichier(fileName.c_str(), std::ios::in);

  std::string texte, ligne;
  if(fichier) {

      while(getline(fichier, ligne)) {
          texte += ligne + "\n";
      }

      fichier.close();
  }
  else {
      Gtk::MessageDialog dialogue(*this, "Erreur lors de l'ouverture du fichier " + fileName + ".", false, Gtk::MESSAGE_INFO);
      dialogue.run();
  }

  return texte;
  //Obtenir le buffer de la zone de texte.
  //Glib::RefPtr<Gtk::TextBuffer> buffer = zoneTexte.get_buffer();
  //buffer->set_text(texte); //Modifier le texte du buffer.

}

bool Menu::sauverFunction(std::string data){

  std::string file;
  Gtk::FileChooserDialog enregistrement(*this, "Sauvegarde du fichier", Gtk::FILE_CHOOSER_ACTION_SAVE);
  enregistrement.set_do_overwrite_confirmation();
  //Permettre la création de dossiers.
  enregistrement.set_create_folders();
  //Ajout de boutons.
  enregistrement.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
  enregistrement.add_button(Gtk::Stock::SAVE, Gtk::RESPONSE_OK);

  int resultat = enregistrement.run();
  if(resultat == Gtk::RESPONSE_OK) {
    file = enregistrement.get_filename();
    std::ofstream fichier(file, std::ios::out);  //déclaration du flux et ouverture du fichier
          if(fichier)  // si l'ouverture a réussi
          {
              fichier << data;
              fichier.close();  // on referme le fichier
          }
    enregistrement.hide();
    return true;
  }
  else{
    enregistrement.hide();
    Gtk::MessageDialog dialogue(*this, "Aucun fichier selectionné!", false, Gtk::MESSAGE_INFO);
    dialogue.run();
    return false;
  }


}

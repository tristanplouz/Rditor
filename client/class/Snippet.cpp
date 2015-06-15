#include "../class/Snippet.h"
#include <fstream>
#include <iostream>


Snippet::Snippet():html(),contidion(), boucleFor(), boucleWhile() {
  std::ifstream fHtml("ressource/snippet/html.txt", std::ios::in);//ressource/snippet/html.txt
  std::ifstream fCondition("ressource/snippet/if.txt", std::ios::in);
  std::ifstream fBoucleFor("ressource/snippet/for.txt", std::ios::in);
  std::ifstream fBoucleWhile("ressource/snippet/while.txt", std::ios::in);

  std::string texte, ligne;
  if(fHtml) {

      while(getline(fHtml, ligne)) {
          texte += ligne + "\n";
      }

      fHtml.close();
      html=texte;
      texte="";
  }
  else{
    Gtk::MessageDialog dialogue(*this,"Erreur d'ouverture d'un  fichier ressource" , false, Gtk::MESSAGE_ERROR);
    dialogue.set_secondary_text("ressource/snippet/html.txt");
    dialogue.set_title("Fichier manquant");
    dialogue.run();
  }
  if(fCondition) {

      while(getline(fCondition, ligne)) {
          texte += ligne + "\n";
      }

      fCondition.close();
      contidion=texte;
      texte="";
  }
  else{
    Gtk::MessageDialog dialogue(*this,"Erreur d'ouverture d'un  fichier ressource" , false, Gtk::MESSAGE_ERROR);
    dialogue.set_secondary_text("ressource/snippet/if.txt");
    dialogue.set_title("Fichier manquant");
    dialogue.run();
  }
  if(fBoucleFor) {

      while(getline(fBoucleFor, ligne)) {
          texte += ligne + "\n";
      }

      fBoucleFor.close();
      boucleFor=texte;
      texte="";
  }
  else{
    Gtk::MessageDialog dialogue(*this,"Erreur d'ouverture d'un  fichier ressource" , false, Gtk::MESSAGE_ERROR);
    dialogue.set_secondary_text("ressource/snippet/for.txt");
    dialogue.set_title("Fichier manquant");
    dialogue.run();
  }
  if(fBoucleWhile) {

      while(getline(fBoucleWhile, ligne)) {
          texte += ligne + "\n";
      }

      fBoucleWhile.close();
      boucleWhile=texte;
      texte="";
  }
  else{
    Gtk::MessageDialog dialogue(*this,"Erreur d'ouverture d'un  fichier ressource" , false, Gtk::MESSAGE_ERROR);
    dialogue.set_secondary_text("ressource/snippet/while.txt");
    dialogue.set_title("Fichier manquant");
    dialogue.run();
  }


};

#include "../class/Fenetre.h"

Fenetre::Fenetre()  {

    set_title("Rditor");//Titre de la fenetre
    set_icon_from_file("ressource/logos/logo_x256.png");//logo de la fenetre
    set_default_size(1500, 1000);//taile de la fenetre
    boiteV.pack_start(menu.boiteMenu, Gtk::PACK_SHRINK);//ajout du menu au conteneur de la fenetre
    boiteV.pack_start(body.bodyBox,Gtk::PACK_EXPAND_WIDGET);//ajout du body au conteneur de la fenetre
    boiteV.pack_end(footer.footerBox,Gtk::PACK_SHRINK);//ajout du footer au conteneur de la fenetre

    add(boiteV);//ajout du conteneur a la fenetre

    show_all();//montre tout les widgets

    //Utilisation
    menu.ouvrirAc->signal_activate().connect([this]() {
        body.openText(menu.ouvrirFunction());
        footer.status.push(menu.actualFile);
    });//Action du bouton ouvrir

    menu.enregistrerAc->signal_activate().connect([this](){
      if(menu.sauverFunction(body.getData())){
        footer.saved.push("Saved");
      }
    });//action de la sauvegarde

    menu.connectAc->signal_activate().connect([this](){
      if(networkManager.connect()){
        Gtk::MessageDialog dial(*this, "Bien connecté", false, Gtk::MESSAGE_INFO);
        networkManager.connected=true;
        dial.run();
      }
    });//Action de la connection

    body.bufferProg-> signal_end_user_action().connect([this](){
      footer.saved.push("Not saved");
      footer.nbrLigne.push(std::to_string(body.bufferProg->get_line_count()));
      networkManager.send(3,networkManager.room,"data changed");
    }); //evenement lors de la modification de la zone de texte

    menu.code.signal_toggled().connect([this](){ //ATTENTION CODE TRES CHELOU MAIS CA FONCTIONNE
      //Pourrai etre refait avec des .hide()
      switch(mode){
        case 1 :
          menu.boiteMenu.remove(menu.barreProg);
          body.bodyBox.remove(body.scrollProg);
          break;
        case 2 :
          menu.boiteMenu.remove(menu.barreText);
          body.bodyBox.remove(body.indev);
          break;
        case 3 :
          menu.boiteMenu.remove(menu.barreDessin);
          body.bodyBox.remove(body.indev);
          break;
        default:
          break;
      }

      if(menu.code.get_active()) {
        menu.boiteMenu.pack_start(menu.barreProg);
        body.bodyBox.pack_start(body.scrollProg,Gtk::PACK_EXPAND_WIDGET);
        mode = 1;
      }
      else if(menu.text.get_active()) {
        menu.boiteMenu.pack_start(menu.barreText);
        body.bodyBox.pack_start(body.indev,Gtk::PACK_EXPAND_WIDGET);
        mode = 2;
      }
      else if(menu.dessin.get_active()) {
        menu.boiteMenu.pack_start(menu.barreDessin);
        body.bodyBox.pack_start(body.indev,Gtk::PACK_EXPAND_WIDGET);
        mode =3;
      }
      show_all();
    });//Evenement de changement de mode

    body.boutonSend.signal_activate().connect([this](){

      networkManager.send(2,networkManager.room,body.chatTextSend.get_text());
    });


    //Gestion des snippets
    menu.htmlSnip.signal_activate().connect([this]{body.addText(snippet.html);});
    menu.condition.signal_activate().connect([this]{body.addText(snippet.contidion);});
    menu.bouclefor.signal_activate().connect([this]{body.addText(snippet.boucleFor);});
    menu.bouclewhile.signal_activate().connect([this]{body.addText(snippet.boucleWhile);});

}

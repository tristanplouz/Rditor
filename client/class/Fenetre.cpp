#include "../class/Fenetre.h"

Fenetre::Fenetre():menu(),boiteV(),body(),footer()  {

    set_title("Home");//Titre de la fenetre
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
      if(netCo.connect()){
        Gtk::MessageDialog dial(*this, "bien connecté", false, Gtk::MESSAGE_INFO);
        dial.run();
      }
    });//Action de la connection

    body.bufferText->signal_changed().connect([this](){
      footer.saved.push("Not saved");
    });//evenement lors de la modification de la zone de texte

    menu.code.signal_toggled().connect([this](){
      Gtk::MessageDialog dial(*this, "Radio changed", false, Gtk::MESSAGE_INFO);
      dial.run();
      if(menu.code.get_active()) {
        menu.boiteMenu.pack_start(menu.barreProg);
        menu.boiteMenu.remove(menu.barreText);
        menu.boiteMenu.remove(menu.barreDessin);
      }
      else if(menu.text.get_active()) {
        menu.boiteMenu.pack_start(menu.barreText);
      }
      else if(menu.dessin.get_active()) {
        menu.boiteMenu.pack_start(menu.barreDessin);
      }
    });//Evenement de changement de mode

    //Gestion des snippets
    menu.html.signal_activate().connect([this]{body.addText(snippet.html);});
    menu.condition.signal_activate().connect([this]{body.addText(snippet.contidion);});
    menu.bouclefor.signal_activate().connect([this]{body.addText(snippet.boucleFor);});
    menu.bouclewhile.signal_activate().connect([this]{body.addText(snippet.boucleWhile);});




}

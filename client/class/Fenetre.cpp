#include "../class/Fenetre.h"

Fenetre::Fenetre():menu(),boiteV(),body(),footer()  {

    set_title("Home");
    set_default_size(1500, 1000);
    boiteV.pack_start(menu.barreMenu, Gtk::PACK_SHRINK);
    boiteV.pack_start(menu.barreOutils, Gtk::PACK_SHRINK);
    boiteV.pack_start(body.bodyBox,Gtk::PACK_EXPAND_WIDGET);
    boiteV.pack_end(footer.footerBox,Gtk::PACK_SHRINK);
    add(boiteV);

    show_all();


    //Utilisation
    menu.ouvrirAc->signal_activate().connect([this]() {body.openText(menu.ouvrirFunction());
                                                        footer.status.push(menu.actualFile);});
    menu.enregistrerAc->signal_activate().connect([this](){if(menu.sauverFunction(body.getData())){footer.saved.push("Saved");}});

    body.bufferText->signal_changed().connect([this](){footer.saved.push("Not saved");});

    menu.html.signal_activate().connect([this]{body.addText(snippet.html);});
    menu.condition.signal_activate().connect([this]{body.addText(snippet.contidion);});
    menu.bouclefor.signal_activate().connect([this]{body.addText(snippet.boucleFor);});
    menu.bouclewhile.signal_activate().connect([this]{body.addText(snippet.boucleWhile);});
    //Gtk::MessageDialog dialogue(*this, body.getData(), false, Gtk::MESSAGE_INFO);

}

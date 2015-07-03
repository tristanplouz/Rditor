#include "../class/Dialco.h"

Dialco::Dialco(std::string titre, Gtk::Window* parent) : Gtk::Dialog(titre, *parent), boiteV(get_vbox()){ //Récupération de la boîte verticale avec get_vbox().

    adjustSalon = Gtk::Adjustment::create(1,1, 100, 1);
    adjustPort= Gtk::Adjustment::create(9876, 100,100000, 5);
    salon.set_adjustment(adjustSalon);
    zonePort.set_adjustment(adjustPort);
    salon.set_numeric();
    zonePort.set_numeric();

    boiteV->pack_start(zonePseudo);
    boiteV->pack_start(zoneIp);
    boiteV->pack_start(zonePort);
    boiteV->pack_start(salon);

    zonePseudo.set_text("Pseudo");
    zoneIp.set_text("Adresse");

    //Ajout de boutons à la boîte de dialogue.
    add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);

    show_all();


}

void Dialco::getData(){
  pseudo = zonePseudo.get_text();
  ip = zoneIp.get_text();
  port = zonePort.get_value_as_int();
  room = salon.get_value_as_int();
}

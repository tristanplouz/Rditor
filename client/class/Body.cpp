#include "../class/Body.h"

Body::Body():bodyBox(),zoneTexte(), scroll(),bufferText(){

  scroll.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  zoneTexte.set_wrap_mode(Gtk::WRAP_WORD);
  scroll.add(zoneTexte);
  bodyBox.pack_start(scroll);
  bufferText = zoneTexte.get_buffer();

}

void Body::openText(std::string text){
  if(text!=""){
    bufferText->set_text(text);
  }

}

std::string Body::getData(){
  std::string data =  bufferText->get_text();
  return data;
}

void Body::addText(std::string data){
  std::string temp = bufferText->get_text();
  bufferText->set_text(temp+data);
}

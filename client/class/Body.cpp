#include "../class/Body.h"

Body::Body():indev("INDEV"),chatBox("Chat"),bouton(Gtk::Stock::OK){

  //Init de la zone de texte de programation
  scrollProg.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  zoneProg.set_wrap_mode(Gtk::WRAP_WORD);
  scrollProg.add(zoneProg);
  bufferProg = zoneProg.get_buffer();
  //Init du chat
  chat.pack_start(chatContent);
  chat.pack_start(chatTextSend);
  chat.pack_start(bouton);
  chatBox.add(chat);

  bodyBox.pack_end(chatBox,Gtk::PACK_SHRINK);


}

void Body::openText(std::string text){
  if(text!=""){
    bufferProg->set_text(text);
  }

}

std::string Body::getData(){
  std::string data =  bufferProg->get_text();
  return data;
}

void Body::addText(std::string data){
  bufferProg->insert_at_cursor(data);
}

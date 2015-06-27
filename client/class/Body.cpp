#include "../class/Body.h"

Body::Body():indev("INDEV"),chatBox("Chat"),boutonSend(Gtk::Stock::OK){

  //Init de la zone de texte de programation
  //Mise en place
  scrollProg.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  zoneProg.set_wrap_mode(Gtk::WRAP_WORD);
  scrollProg.add(zoneProg);
  //Declaration
  //bufferProg = zoneProg.get_source_buffer();
  bufferProg=Gsv::Buffer::create();
  zoneProg.set_source_buffer(bufferProg);
  zoneProg.set_show_line_numbers(true);



  //Init du chat
  sender.pack_start(chatTextSend);
  sender.pack_start(boutonSend);
  chat.pack_start(chatContent);
  chat.pack_start(sender);
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

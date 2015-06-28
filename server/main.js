var dgram = require('dgram');
var http = require('http');

var address,port,userNbr=0;
var socket = dgram.createSocket('udp4');

console.log("Socket created\n");
socket.bind();

socket.on("message",function (msg,rinfo) {
  var brut=msg.toString();
  var data = brut.substr(6, brut.length+1);
  console.log("Received message "+brut);

  switch(brut.charAt(4)){
    case '0' :
      console.log("New connection from "+data);
      userNbr++;
      break;
    case '1' :
      console.log("New chat message : "+data);
      break;
    case '2' :
      console.log("Data modified!!");
      break;
    default:
      console.log("Err");
      break;
  }
});
socket.on("listening", function () {
  address = socket.address().address;
  port = socket.address().port;
  console.log("server listening " +
      address + ":" + port);
});

var serverH = http.createServer(function(req, res) {
  res.writeHead(200);
  res.end("Vous pouvez vous connecte sur "+address+":"+port+"\nIl y a deja "+userNbr+"personnes de connecte");
});
serverH.listen(8080);

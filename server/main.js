var dgram = require('dgram');
var http = require('http');

var address,port,userNbr=0;
var socket = dgram.createSocket('udp4');

var client=[];

console.log("Socket created\n");
socket.bind(5000);
socket.on("message",function (msg,rinfo) {
  var brut=msg.toString();
  var data = brut.substr(6, brut.length+1);
  console.log("Received message "+brut);
  switch(brut.charAt(4)){
    case '0' :
      userNbr--;
      break;
    case '1' :
      console.log("New connection from "+data);
      client.push({"name":data,
                              "room":brut.charAt(5),
                              "ip":rinfo.address});
      userNbr++;
      break;
    case '2' :
      console.log("New chat message : "+data);
      break;
    case '3' :
      console.log("Data modified!!");
      break;
    default:
      console.log("Err");
      break;
  }
  console.log(client);
});
socket.on("listening", function () {
  address = socket.address().address;
  port = socket.address().port;
  console.log("server listening " +
      address + ":" + port);
});

var serverH = http.createServer(function(req, res) {
  res.writeHead(200);
  res.end("Vous pouvez vous connecte sur "+address+":"+port+"\nIl y a deja "+userNbr+" personnes de connecte.\nDont"+client);
});
serverH.listen(8080);

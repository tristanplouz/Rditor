/*var net = require("net");

var server = net.createServer(function(c) { //'connection' listener
  console.log('client connected');

  c.on('data', function(data){
    console.log(data.toString());
  });

  c.on('end', function() {
    console.log('client disconnected');
  });
});

server.listen({host: 'localhost', port: 9876}, function() { //'listening' listener
  console.log('server bound');
});
*/
var dgram = require('dgram');
var server = dgram.createSocket('udp4');

console.log("Socket created\n");
server.bind(9876);

server.on("message",function (msg,rinfo) {
  var brut=msg.toString();
  var data = brut.substr(6, brut.length+1);
  console.log("Received message "+brut);

  switch(brut.charAt(4)){
    case '0' :
      console.log("New connection from "+data);
      break;
    case '1' :
      console.log("New chat message : "+data);
      break;
    default:
      console.log("Err");
      break;
  }
  });

var net = require("net");

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

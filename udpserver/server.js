const dgram = require('dgram');

const server = dgram.createSocket('udp4');

server.on('listening', () => {
  console.log(`UDP server listening on port 3000`);
});


server.on('message', (message, info) => {
  console.log(`Received message: ${message.toString()}`);
  var reversemsg = "";
  reversemsg=message.toString().split(' ').reverse().join(' ');
  
  server.send(reversemsg, info.port, info.address, (err) => {
    if (err) {
      console.error(`Error sending response: ${err}`);
    } else {
      console.log(`Sent reverse msgd message: ${reversemsg}`);
    }
  });
});

server.bind(3000);

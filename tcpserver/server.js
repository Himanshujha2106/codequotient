const net = require('net');

var pool = [];

const server = net.createServer((socket) => {
  pool.push(socket);

  socket.on('data', (data) => {
    console.log('message received from client');
    const message = `Client message: ${data.toString()}`;
    pool.forEach((s) => {
    
        s.write(message);
      
    });
  });


  socket.on('close', () => {
    console.log('Client disconnected:', socket.remoteAddress, socket.remotePort);
    pool = pool.filter((s) => s !== socket);
  });
});

server.listen(3000, () => {
  console.log('Server listening on port 3000');
});

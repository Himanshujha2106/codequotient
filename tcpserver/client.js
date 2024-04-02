const net = require("net");

const message = process.argv[4] || "Hello from the client!";
const client = net.createConnection(3000, () => {
  console.log("Connected to server:");
 setInterval(()=>{
    client.write(message);

 },4000);
  
});

client.on("data", (data) => {
  console.log("Received data from server:", data.toString());
});

client.on("close", () => {
  console.log("Connection closed");
});

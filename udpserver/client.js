const dgram = require("dgram");
const client = dgram.createSocket("udp4");
const readline = require("readline");

// const rl = readline.createInterface({
//     input: process.stdin,
//     output: process.stdout,
// });

var message = "";
 var message = process.argv[2];
// rl.question("Enter your message: ", (msg) => {
//     message = msg;
    
    // rl.close();
    client.send(message, 3000, "localhost", (err) => {
        if (err) {
            console.log(err);
        }
    });
// });

client.on("message", (msg) => {
    console.log(`Received response: ${msg.toString()}`);
});

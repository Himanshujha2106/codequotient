const http = require("http");
const { json } = require("stream/consumers");
const url = require("url");

const server = http.createServer((req, res) => {
  if (url === "/favicon.ico") {
    return;
  }
  let = "";
  req.on("data", (data) => {
    Data += data;
  });
  req.on("end", (Data) => {
    Data = JSON.parse(Data);
    console.log(Data);
  });
  res.end(`hi`);
});

server.listen(3000, () => {
  console.log(`Server running `);
});

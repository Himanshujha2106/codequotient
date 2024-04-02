const http = require("http");
const url = require("url");
const arr = [];

for (let i = 0; i < 10; i++) {
  const newObj = { value: i };
  arr.push(newObj);
}

const server = http.createServer((req, res) => {
  if (req.url === "/favicon.ico") {
    res.end(); 
    return;
  }
  
  const parsedUrl = url.parse(req.url, true);
  const queryData = parsedUrl.query;

  const dataA = queryData.i;

  console.log("Received data:", dataA);
  
  if (dataA >= 10) {
    res.writeHead(400, { "Content-Type": "text/plain" });
    res.end("Missing required data parameters , no object found");
    return;
  }
  let response="";
  res.writeHead(200, { "Content-Type": "text/plain" });
  for (let i = 0; i < dataA; i++) {
    response+=arr[i].value +' ' ; }
  res.end(response);
});

server.listen(3000, "127.0.0.1", () => {
  console.log("Server running on http://localhost:3000/");
});

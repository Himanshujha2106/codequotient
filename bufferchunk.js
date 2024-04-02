const fs = require("fs");

async function readstream(filePath) {
  try {
    const stats = await fs.promises.stat(filePath);
    const fileSize = stats.size;
    const bufferSize = Math.max(1024, Math.floor(fileSize / 10));
    const stream = fs.createReadStream(filePath, { highWaterMark: bufferSize });

    stream.on("data", (chunk) => {
      console.log("Received data chunk:", chunk);
      console.log("Received data chunk:", chunk.toString());
    });
  
    stream.on("end", () => {
      console.log("Finished reading the file");
    });

    stream.on("error", (err) => {
      console.error("Error reading file:", err);
    });
  } catch (error) {
    console.error("Error:", error);
  }
}

const filePath = "./ans.txt";
readstream(filePath);

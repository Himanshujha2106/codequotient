const fs = require('fs');
const path = require('path');
const filesFolder = './textfile';
const combineFilePath = './combined.txt';

var data='';
for (let i = 1; i < 4; i++) {
    data += fs.readFileSync(path.join(filesFolder, `${i}.txt`), 'utf8') + '\n';
  }
fs.writeFileSync(combineFilePath, data);

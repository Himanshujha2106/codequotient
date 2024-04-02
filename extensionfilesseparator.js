const fs = require('fs');
const path = require('path');

const folder = './extentions';
const fileTypes = {
    '.txt': './txtFiles',
    '.exe': './exeFiles',
    '.js': './JsFiles',
};
fs.readdir(folder, (err, fileList) => { 
    if (err) {
        console.error(err);
        return;
    }
    fileList.forEach((file) => {
        const filePath = path.join(folder, file);
        const fileExt = path.extname(file);
        if (fileTypes[fileExt]) {
            const destinationFolder = fileTypes[fileExt];
            fs.renameSync(filePath, path.join(destinationFolder, file))
        }
    });
});
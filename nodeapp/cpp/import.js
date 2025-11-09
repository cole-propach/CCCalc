const { spawn } = require('child_process');
const path = require('path');

const cppExecutable = path.join(__dirname, 'importout.exe');

const runImport = (output, board, numRows, numCols) => {
  const myPromise = new Promise( (resolve, reject) =>{
          const runProcess = spawn(cppExecutable, [board, numRows, numCols]);
          runProcess.stdout.on('data', (data) => {  
            console.log(`import program output: ${data}`);
            output[0] = "" + data; 
          });

          runProcess.stderr.on('data', (data) => {
            console.error(`import program error: ${data}`);
          });

          runProcess.on("close", ()=> {
            resolve();
          });
      });
  return myPromise;
};

module.exports = runImport;


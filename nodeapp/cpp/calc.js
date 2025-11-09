const { spawn } = require('child_process');
const path = require('path');

const cppExecutable = path.join(__dirname, 'calcout.exe');

const runCalc = (output, board, color, animal) => {
  const myPromise = new Promise( (resolve, reject) =>{
          const runProcess = spawn(cppExecutable, [board, color, animal]);
          runProcess.stdout.on('data', (data) => {  
            console.log(`calc program output: ${data}`);
            output[0] = "" + data; 
          });

          runProcess.stderr.on('data', (data) => {
            console.error(`calc program error: ${data}`);
          });

          runProcess.on("close", ()=> {
            resolve();
          });
      });
  return myPromise;
};

module.exports = runCalc;


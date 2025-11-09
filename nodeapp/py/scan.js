const { spawn } = require('child_process');
const path = require('path');



const runScan = (scanOutput) => {
  const myPromise = new Promise( (resolve, reject) =>{
        const runProcess = spawn('py', [path.join(__dirname, 'scan.py')]);
          runProcess.stdout.on('data', (data) => {  
            console.log(`scan program output: ${data}`);
            scanOutput[0] = "" + data;
          });

          runProcess.stderr.on('data', (data) => {
            console.error(`scan program error: ${data}`);
          });

          runProcess.on("close", ()=> {
            resolve();
          });
      });
  return myPromise;
};

module.exports = runScan;


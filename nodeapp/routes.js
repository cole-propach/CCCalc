const path = require('path');

//find a way to run my c++ file and return its answer

function setupRoutes(app) {
    // module start

    // index.html
    app.get('/', function (req, res) {
        res.sendFile(path.join(__dirname + '/index.html'));
    });

    app.get('/back.js', function (req, res) {
        res.sendFile(path.join(__dirname + '/back.js'));
    });

    app.get('/calc.js/:bor/:colo/:ani', function (req, res){
        const color = req.params.colo;
        const animal = req.params.ani;
        const board = req.params.bor;
        let output = [];
        require("./cpp/calc.js")(output, board, color, animal)
            .then( function(){
                res.json( { output: output[0] } );
            });
    });
    app.get('/import.js/:bor/:rows/:cols', function (req, res){
        const numRows = req.params.rows;
        const numCols = req.params.cols;
        const board = req.params.bor;
        let output = [];
        require("./cpp/import.js")(output, board, numRows, numCols)
            .then( function(){
                res.json( { output: output[0] } );
            });
    });
    app.get('/scan.js', function (req, res){
        let scanOutput = [];
        require("./py/scan.js")(scanOutput)
            .then( function(){
                res.json( { scanOutput: scanOutput[0] } );
            });
    });
    

    /*
    // Websocket game connection
    app.ws('/game', function (ws, req) {
        ws.on('message', function (msg) {
            wsRouter.giveMessage(ws, msg);
        });
    });
    */
}

module.exports = setupRoutes;
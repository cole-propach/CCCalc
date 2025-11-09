
function calcClick(){
    const colors = document.getElementById("colors");
    const animals = document.getElementById("animals");
    const selectedColor = colors.value;
    const selectedAnimal = animals.value;
    const importContainer = document.getElementById("importContainer");
    const board = importContainer.textContent;
    fetch("./calc.js/"+board+"/"+selectedColor+"/"+selectedAnimal)
    .then( data => {
        return data.json();
    })
    .then( data => {
        const stringData = data.output;
        const calcContainer = document.getElementById("calcContainer");
        calcContainer.textContent = stringData;
    });
}
function importClick(){
    const calcContainer = document.getElementById("calcContainer");
    calcContainer.textContent = " ";
    const rows = document.getElementById("numRows");
    const cols = document.getElementById("numCols");
    const numRows = rows.value;
    const numCols = cols.value;
    const importContainer = document.getElementById("importConfirmation");
    importContainer.textContent = "Importing your board...";
    fetch('./scan.js')
    .then( data => {
        return data.json();
    })
    .then( data =>{
        const scanData = data.scanOutput;
        //numCards = scanData.length;
        console.log("Scanned Data: " + scanData);

        fetch("./import.js/"+scanData+"/"+numRows+"/"+numCols)
        .then( data => {
            return data.json();
        })
        .then( data => {
            console.log("Imported Data: "+ data.output);
            const importContainer = document.getElementById("importContainer");
            importContainer.textContent = data.output;
            const importConfirmation = document.getElementById("importConfirmation");
            importConfirmation.textContent = "Import Successful";
        });
    });
}
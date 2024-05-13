const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
  });
  
  function simulateInstall() {
    console.log("Installing cool stuff...");
    console.log("Downloading packages...");
    console.log("Compiling code...");
    console.log("Success!");
  }
  
  function simulateMaliciousInstall() {
    console.log(`
      __
   _   / /
  (_) | | 
   _  | | 
  (_) | | 
       \\_\\
       
  Uh oh! You just got pwned!
    `);
    console.log("Sending all your passwords to our database...");
    console.log("Stealing all your data...");
    console.log("Sending your internet history to your mom...");
    console.log("Leaking that photo of you from Kyle's party...");
    console.log("Opening your calculator (just to show that we can)...");
  }
  
  function simulateNpmInstall() {
    readline.question("This app simulates using a terminal and how a simple typo using npm can result in a virus due to it's open source nature.\nType 'npm install legitpackage' to simulate a normal download.\nType 'npm install legitpackagw' to simulate a malicious download.\n", (userInput) => {
      if (userInput === 'exit') {
        readline.close();
      } else if (userInput === "npm install legitpackage") {
        simulateInstall();
        readline.close();
      } else if (userInput === "npm install legitpackagw") {
        simulateMaliciousInstall();
        readline.close();
      } else {
        console.log("No such package found. (simulated)");
        readline.clos
      }
    });
  }
  
  simulateNpmInstall();
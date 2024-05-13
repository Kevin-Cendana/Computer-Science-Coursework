#!/usr/bin/env node
const { exec } = require('child_process');

function openCalculator() {
  switch (process.platform) {
    case 'win32': // Windows
      exec('start calc', (error, stdout, stderr) => {
        if (error) {
          console.error(`Error: ${error.message}`);
          return;
        }
        if (stderr) {
          console.error(`Error: ${stderr}`);
          return;
        }
        console.log(stdout);
      });
      break;
    case 'darwin': // macOS
      exec('open /System/Applications/Calculator.app', (error, stdout, stderr) => {
        if (error) {
          console.error(`Error: ${error.message}`);
          return;
        }
        if (stderr) {
          console.error(`Error: ${stderr}`);
          return;
        }
        console.log(stdout);
      });
      break;
    case 'linux': // Linux
      exec('gnome-calculator', (error, stdout, stderr) => {
        if (error) {
          console.error(`Error: ${error.message}`);
          return;
        }
        if (stderr) {
          console.error(`Error: ${stderr}`);
          return;
        }
        console.log(stdout);
      });
      break;
    default:
      console.error('Unsupported platform');
      break;
  }
}
function simulateMaliciousInstall() {
  console.log(`
        __
   _   / /
  (_) | | 
   _  | | 
  (_) | | 
       \_\
        
       
  Uh oh! You just got pwned!
  `);
  console.log("Simulating sending all your passwords to our database...");
  console.log("Simulating stealing all your data...");
  console.log("Simulating sending your internet history to your mom...");
  console.log("Simulating leaking that photo of you from Kyle's party...");
  console.log("Opening your calculator (just to show that we can)...");
  openCalculator();
}

simulateMaliciousInstall();
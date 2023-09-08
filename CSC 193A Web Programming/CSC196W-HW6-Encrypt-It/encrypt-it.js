//good practice, executes automatically, avoid scope issues i.e. global vars
(function() {
  //call init() on website load
  window.addEventListener("load", init);

  //vars for button, input text, output encrypted text
  var encryptButton = document.getElementById("encrypt-it");
  var resetButton = document.getElementById("reset");
  var inputText = document.getElementById("input-text");
  var result = document.getElementById("result");

  //make button call handleClick() on click
  encryptButton.addEventListener("click", handleClick);
  resetButton.addEventListener("click", resetClick);

  //function to run on website load
  function init() {}

  //function to run on encrypt  button click
  function handleClick() {
    console.log("Button clicked!");
    for (let i = 0; i < inputText.value.length; i++) {
      if (inputText.value[i] == "z" || inputText.value[i] == "Z") {  //edge case: "z"
        result.innerHTML += "a";
      } else {
        result.innerHTML += String.fromCharCode(inputText.value.charCodeAt(i) + 1);
      }
    }
    }

    //function to run on reset button click
    function resetClick() {
      console.log("Reset clicked!");
      result.innerHTML = "";
      inputText.value = "";
    }
})();
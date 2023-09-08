function helloWorld() {
    alert('Hello world!');
}
function toUpper() {
    var inputText = document.getElementById("inputText");
    inputText.value = inputText.value.toUpperCase();
}
function mooSuffix () {
    var inputText = document.getElementById("inputText");
    var wordArr = inputText.value.split(".");           //removes all occurences of char and ends the array index there
                                                        //["Hi there.". "I'm Kevin.", "Goodbye."]
    inputText.value = "";
    // for (let i = 0; i < wordArr.length - 1; i++) {
    //     inputText.value += (wordArr[i] + "-moo.");
    // }
    inputText.value=wordArr.join("-moo.");
}

function enlargeText() {
    var inputText = document.getElementById("inputText");
    inputText.style.fontSize = "24px";
}
function fancify() {
    var inputText = document.getElementById("inputText");
    inputText.style.fontWeight = ("bold");
    inputText.style.color = ("blue");
    inputText.style.textDecoration = "underline";
}
function removeStyle() {
    var inputText = document.getElementById("inputText");
    inputText.style.fontWeight = ("");
    inputText.style.color = ("");
    inputText.style.textDecoration = "";
}

function showAlert() {
    alert("Your text has been fancified!");
}
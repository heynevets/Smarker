var canvas = document.getElementsByTagName("canvas")[0];
var context = canvas.getContext("2d");
var height = canvas.height = window.innerHeight;
var width = canvas.width = window.innerWidth;
var mouseClicked = false; mouseReleased = true;

document.addEventListener("click", onMouseClick, false);
document.addEventListener("mousemove", onMouseMove, false);

var startX;
var startY;

var allX = [];
var allY = [];
function onMouseClick(e) {
    mouseClicked = !mouseClicked;
    startX = e.pageX*.25;
    startY = e.pageY*.25;
    if (mouseClicked == false) {
      console.log(allX);
      console.log(allY);
    }
}
function onMouseMove(e) {
    if (mouseClicked) {
        context.beginPath();
        context.arc(e.clientX, e.clientY, 7.5, 0, Math.PI * 2, false);
        context.lineWidth = 5;
        context.strokeStyle = "#fff";
        context.stroke();


        var x;
        var y;
        if (e.pageX || e.pageY) {
          x = e.pageX;
          y = e.pageY;
        }
        else {
          x = e.clientX + document.body.scrollLeft + document.documentElement.scrollLeft;
          y = e.clientY + document.body.scrollTop + document.documentElement.scrollTop;
        }
        x -= context.offsetLeft;
        y -= context.offsetTop;
        allX.push(e.pageX*.25 - startX);
        allY.push(-(e.pageY*.25 - startY));
        // console.log(e.pageX*.25 - startX);
        // console.log(-(e.pageY*.25 - startY));
    }
}
function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++ ) {
        color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}
context.strokeStyle = "#fff";
context.strokeStyle = getRandomColor();

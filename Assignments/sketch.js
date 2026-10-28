/*
P5.JS SERIAL READ
*/

let serial; // declare variable for an instance of the serialport library
let portName = 'COM9';  // fill in your serial port name here
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code
let inData = 0; // declare variable for storing incoming serial data

let toggle =  false;
 
function setup() //setup function runs once at beginning
{
  //P5 SerialPort Setup
  serial = new p5.SerialPort();             // make a new instance of the serialport library
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
 
  serial.list();                            // list the serial ports
  serial.open(portName, options);           // open a serial port
  

  //TYPICAL P5.JS SETUP
  createCanvas(800, 800); //set size of canvas
  textSize(72); // set text size
  textAlign(CENTER, CENTER);  // set text alignment

  // x = diameter;
  // y = diameter;
}

// function draw() //  draw function loops forever at frame rate
// {

//   background(200, 255, 255,1);  // clear frame with background color each draw loop

//   fill(0); // set fill color using incoming serial data
//   let diameter = map(inData, 0, 255, 10, width - 10); // scale incoming data from 0 to 255 into circle diameter  // draw circle in center of canvas with diameter based on serial data




//   if(toggle){
//     circle(diameter, hold ,10);
//   }

//   else{
//     circle(hold, diameter ,10);
//   }
     
  
// }

// function keyPressed() {
  
//   if (key === 'o') {
//     hold = diameter;
//     toggle = true;
//   } else if (key === 'p') {
//     hold = diameter;
//     toggle = false;
//   }
// }
 





function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERVER");
}
 
function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}
 
function serialEvent() //gets called when new data arrives
{
  inData = Number(serial.read()); //Store incoming data as a number
  //print(inData);
}
 
function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}
 
function portClose() //gets called when the serial port closes
{
  print("*____SERIAL PORT CLOSED");
}
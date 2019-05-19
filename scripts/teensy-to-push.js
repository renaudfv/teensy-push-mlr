var midi = require('midi');

// Set up a new input.
var input = new midi.input();
// Count the available input ports.
for(var i = 0; i < input.getPortCount(); i++) {
  console.log(i, input.getPortName(i));
}

var output = new midi.output();
// Configure output to the index of Ableton Push User Port
output.openPort(4);

var mess;
input.on('message', function(deltaTime, message) {
  mess = message;
  console.log('m:' + message + ' d:' + deltaTime);
  // 240 added as header twice
  mess.shift();
  // 247 added as footer twice
  mess.pop();
  console.log(mess);
  output.sendMessage(mess);
});

// Change port for the index corresponding to Teensy MIDI
input.openPort(5);

// Sysex, timing, and active sensing messages are ignored
// by default. To enable these message types, pass false for
// the appropriate type in the function below.
// Order: (Sysex, Timing, Active Sensing)
// For example if you want to receive only MIDI Clock beats
// you should use
// input.ignoreTypes(true, false, true)
input.ignoreTypes(false, false, false);

// Close the port when done.
// input.closePort();
// output.closePort();

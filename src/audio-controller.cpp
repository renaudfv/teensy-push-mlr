#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include

// GUItool: begin automatically generated code
AudioPlaySdWav           track3; //xy=401,504
AudioPlaySdWav           track4; //xy=405,561
AudioPlaySdWav           track2; //xy=406,454
AudioPlaySdWav           track1;     //xy=407,403
AudioMixer4              leftMixer;         //xy=745,406
AudioMixer4              rightMixer; //xy=746,475
AudioOutputI2S           i2s1;           //xy=930,431
AudioConnection          patchCord1(track3, 0, leftMixer, 2);
AudioConnection          patchCord2(track3, 1, rightMixer, 2);
AudioConnection          patchCord3(track4, 0, leftMixer, 3);
AudioConnection          patchCord4(track4, 1, rightMixer, 3);
AudioConnection          patchCord5(track2, 0, leftMixer, 1);
AudioConnection          patchCord6(track2, 1, rightMixer, 1);
AudioConnection          patchCord7(track1, 0, leftMixer, 0);
AudioConnection          patchCord8(track1, 1, rightMixer, 0);
AudioConnection          patchCord9(leftMixer, 0, i2s1, 0);
AudioConnection          patchCord10(rightMixer, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1030,624
// GUItool: end automatically generated code

#include "teensy3/Arduino.h"
#include "Audio.h"
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "sense/audio-engine.h"
#include "model/audio-settings.h"
#include "model/track.h"

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14


// #include "Audio.h"
// // GUItool: begin automatically generated code
// AudioPlaySdWav           track3; //xy=401,504
// AudioPlaySdWav           track4; //xy=405,561
// AudioPlaySdWav           track2; //xy=406,454
// AudioPlaySdWav           track1;     //xy=407,403
// AudioMixer4              leftMixer;         //xy=745,406
// AudioMixer4              rightMixer; //xy=746,475
// AudioOutputI2S           i2s1;           //xy=930,431
// AudioConnection          patchCord1(track3, 0, leftMixer, 2);
// AudioConnection          patchCord2(track3, 1, rightMixer, 2);
// AudioConnection          patchCord3(track4, 0, leftMixer, 3);
// AudioConnection          patchCord4(track4, 1, rightMixer, 3);
// AudioConnection          patchCord5(track2, 0, leftMixer, 1);
// AudioConnection          patchCord6(track2, 1, rightMixer, 1);
// AudioConnection          patchCord7(track1, 0, leftMixer, 0);
// AudioConnection          patchCord8(track1, 1, rightMixer, 0);
// AudioConnection          patchCord9(leftMixer, 0, i2s1, 0);
// AudioConnection          patchCord10(rightMixer, 0, i2s1, 1);
// AudioControlSGTL5000     sgtl5000_1;     //xy=1030,624
// // GUItool: end automatically generated code

AudioEngine::AudioEngine(
  AudioSettings* settings,
  Track* t1,
  Track* t2,
  Track* t3,
  Track* t4
): settings_(settings), track1_(t1), track2_(t2), track3_(t3), track4_(t4)
{


  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(8);

  // Comment these out if not using the audio adaptor board.
  // This may wait forever if the SDA & SCL pins lack
  // pullup resistors
  sgtl5000_.enable();
  sgtl5000_.volume(0.5);

  this->_setupSDCard();
}

AudioEngine::~AudioEngine() {
  delete settings_;
  delete track1_;
  delete track2_;
  delete track3_;
  delete track4_;
}

void AudioEngine::_setupSDCard() {
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("ERROR > Unable to access the SD card");
      delay(500);
    }
  }
}

void AudioEngine::_setupAudioRouting() {
  // Register as an observer of the AudioSettings object
  // settings_->subscribe(this);
}


// void playFile(const char *filename)
// {
//   Serial.print("Playing file: ");
//   Serial.println(filename);
//
//   // Start playing the file.  This sketch continues to
//   // run while the file plays.
//   playWav1.play(filename);
//
//   // A brief delay for the library read WAV info
//   delay(5);
//
//     // Simply wait for the file to finish playing.
//     while (playWav1.isPlaying()) {
//
//   }
// }

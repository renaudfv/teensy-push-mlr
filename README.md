# teensy-push-mlr
Teensy based implementation of Monome's MLR, meant to be used with Ableton Push 1.

## Design
Based on the GoF Observer design pattern, it follows the same principles as the MVC architecture.
I'd rather call it MSC (Model Sense Controller), since it does not only involve viewing things but hearing, recording, touching physical interfaces and perceiving time.

## to-do
- [x] 16 step sequencer
- [ ] multitrack
- [ ] ableton push 1 (ap1) init
- [ ] ap1 leds
- [ ] ap1 input -> offset track sequence
- [ ] ap1 start/stop
- [ ] ap1 bpm
- [ ] audio file playback per track
- [ ] audio file segmentation
- [ ] audio seek
- [ ] audio file load/selection + ap1 LCD
- [ ] track amount of steps
- [ ] track volume
- [ ] track pitch
- [ ] track octave
- [ ] track reverse
- [ ] teensy input recording to microSD

## Style guide
This projects uses [Google's C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

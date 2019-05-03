
/*
 * audio-engine.h
 *
 *  Created on: 01/05/2019
 *      Author: Renaud Vincent
 */

#ifndef AUDIO_ENGINE_H_
#define AUDIO_ENGINE_H_

#pragma once

// Teensy audio lib
#include "Audio.h"
// Local lib
#include "observer.h"
// Src headers
#include "audio-settings.h"
#include "track.h"

class AudioEngine: public Observer {
	public:
		AudioEngine(AudioSettings*, Track*, Track*, Track*, Track*);
		~AudioEngine();

    virtual void update();

	private:
    AudioSettings* settings_;
    Track* track1_;
    Track* track2_;
    Track* track3_;
    Track* track4_;

    AudioOutputI2S output_;
    AudioMixer4 leftMixer_;
    AudioMixer4 rightMixer_;
    AudioControlSGTL5000 sgtl5000_; // The hardware audio interface

    void _setupSDCard();
    void _setupAudioRouting();
};

#endif /* AUDIO_ENGINE_H_ */

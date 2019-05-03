
/*
 * audio-settingss.h
 *
 *  Created on: 01/05/2019
 *      Author: Renaud Vincent
 */

#ifndef AUDIO_SETTINGS_H_
#define AUDIO_SETTINGS_H_

#pragma once

#include "Subject.h"

class AudioSetting: public Subject {
	public:
		AudioSetting();
		~AudioSetting();

    void setVolume(float);

	private:
    float volume_;
};

#endif /* AUDIO_SETTINGS_H_ */

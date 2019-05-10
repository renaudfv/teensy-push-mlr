
/*
 * audio-settingss.h
 *
 *  Created on: 01/05/2019
 *      Author: Renaud Vincent
 */
#ifndef TRACK_H_
#define TRACK_H_

#pragma once

#include "subject.h"

class Track: public Subject {
	public:
		Track(char);
		~Track();

    void setVolume(float);
    float getVolume();
    char getFileName();

	private:
    float volume_;
    char fileName_[];
};

#endif /* TRACK_H_ */

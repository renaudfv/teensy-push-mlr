
/*
 * bpm.h
 *
 *  Created on: 25/04/2019
 *      Author: Renaud Vincent
 */

#ifndef BPM_H_
#define BPM_H_

#pragma once

#include "subject.h"

class Bpm: public Subject {
	public:
		Bpm(int);
		~Bpm();

		void setBeatsPerMinute(const int bpm);
	  int getBeatsPerMinute();
	  int getBeatLenghtMs();

	private:
	  int beatsPerMinute_;
};

#endif /* BPM_H_ */


/*
 * bpm.h
 *
 *  Created on: 25/04/2019
 *      Author: Renaud Vincent
 */

#ifndef BPM_H_
#define BPM_H_

#pragma once

class Bpm {
	public:
		Bpm(int);

		void SetBeatsPerMinute(const int bpm);
	  int GetBeatsPerMinute();
	  int GetBeatLenghtMs();

	private:
	  int beatsPerMinute;
	  int period;
};

#endif /* BPM_H_ */

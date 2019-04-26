
/*
 * bpm.h
 *
 *  Created on: 25/04/2019
 *      Author: Renaud Vincent
 */

#ifndef SEQUENCER_CONTROLLER_H_
#define SEQUENCER_CONTROLLER_H_

#pragma once

#include "bpm.h"

class SequencerController {
	public:
		SequencerController(Bpm);

    void start();

	private:
	  Bpm beatsPerMinute;
};

#endif /* SEQUENCER_CONTROLLER_H_ */

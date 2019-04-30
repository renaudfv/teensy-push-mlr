
/*
 * sequencer-controller.h
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
		SequencerController(Bpm*);
		~SequencerController();

    void start();

	private:
	  Bpm* bpm_;
};

#endif /* SEQUENCER_CONTROLLER_H_ */

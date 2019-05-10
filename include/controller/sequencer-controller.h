
/*
 * sequencer-controller.h
 *
 *  Created on: 25/04/2019
 *      Author: Renaud Vincent
 */
#ifndef SEQUENCER_CONTROLLER_H_
#define SEQUENCER_CONTROLLER_H_

#pragma once

#include "sense/sequencer.h"

class SequencerController {
	public:
		SequencerController(Sequencer*);
		~SequencerController();

    void start();

	private:
		Sequencer* sequencer_;

};

#endif /* SEQUENCER_CONTROLLER_H_ */


/*
 * sequencer.h
 *
 *  Created on: 25/04/2019
 *      Author: Renaud Vincent
 */
#ifndef SEQUENCER_H_
#define SEQUENCER_H_

#pragma once

#include "subject.h"

#include "model/bpm.h"
#include "model/sequence.h"

class Sequencer: public Subject {
	public:
		Sequencer(Bpm*, Sequence*,  Sequence*,  Sequence*,  Sequence*);
		~Sequencer();

		void step();

	private:
		Bpm* bpm_;
		Sequence* seq1_;
		Sequence* seq2_;
		Sequence* seq3_;
		Sequence* seq4_;
};

#endif /* SEQUENCER_H_ */

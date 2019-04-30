
/*
 * sequencer-controller.h
 *
 *  Created on: 25/04/2019
 *      Author: Renaud Vincent
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#pragma once

#include "subject.h"

class Sequence: public Subject {
	public:
		Sequence(int, int);
		~Sequence();

		void nextStep();
		void setStart(int);
		void setEnd(int);
		int getCurrent();

	private:
	 int start_;
   int current_;
   int end_;
};

#endif /* SEQUENCE_H_ */

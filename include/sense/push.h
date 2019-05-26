
/*
 * push.h
 *
 *  Created on: 09/05/2019
 *      Author: Renaud Vincent
 */
#ifndef PUSH_H_
#define PUSH_H_

#pragma once

#include "observer.h"
#include "model/sequence.h"

class Push: public Observer {
	public:
		Push(Sequence*,  Sequence*,  Sequence*,  Sequence*);
		~Push();

    void init();
		virtual void update();

	private:
		Sequence* s1_;
		Sequence* s2_;
		Sequence* s3_;
		Sequence* s4_;

		void _sequenceOn(uint8_t, uint8_t, uint8_t, uint8_t);
		void _sequenceOff(uint8_t, uint8_t, uint8_t, uint8_t);
};

#endif /* PUSH_H_ */

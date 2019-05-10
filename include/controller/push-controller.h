
/*
 * push-controller.h
 *
 *  Created on: 09/05/2019
 *  Author: Renaud Vincent
 */
#ifndef PUSH_CONTROLLER_H_
#define PUSH_CONTROLLER_H_

#pragma once

#include "sense/push.h"
#include "sense/sequencer.h"

class PushController {
	public:
		PushController(Push*);
		~PushController();

    void start();

	private:
		Push* push_;

};

#endif /* PUSH_CONTROLLER_H_ */

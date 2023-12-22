/*
 * Joyforcar.h
 *
 *  Created on: Dec 22, 2023
 *      Author: dkdll
 */

#ifndef INC_JOYFORCAR_H_
#define INC_JOYFORCAR_H_

#include "main.h"

#define field1 1
#define field2 2
#define field3 3
#define field4 4

typedef struct _CAR{
	int Direction;
	double RS;
	double LS;
}CAR;

typedef struct _JOY{
	double E, W, N, S;
	double x, y;
	double Degree;
}JOY;

#endif /* INC_JOYFORCAR_H_ */

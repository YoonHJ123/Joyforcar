/*
 * Joyforcar.c
 *
 *  Created on: Dec 22, 2023
 *      Author: dkdll
 */
#include "Joyforcar.h"
#include <math.h>

void JoyVal(JOY* joy, CAR* car, double* buffer)
{
	joy->E = buffer[0];
	joy->W = buffer[1];
	joy->N = buffer[2];
	joy->S = buffer[3];

	joy->x = joy->E + joy->W;
	joy->y = joy->N + joy->S;
	joy->Degree = atan2(joy->y, joy->x)*180/M_PI;
}

void CarMove(JOY* joy, CAR* car, int maxvalue)
{
	if(0 < joy->Degree && joy->Degree <= 90){
		car->Direction = field1;
	}
	else if(90 < joy->Degree && joy->Degree <= 180){
		car->Direction = field2;
	}
	else if(180 < joy->Degree && joy->Degree <= 270){
		car->Direction = field3;
	}
	else{
		car->Direction = field4;
	}

	switch(car->Direction){
	case field1:
		car->LS = sqrt(pow(joy->x, 2) + pow(joy->y, 2));
		car->RS = -maxvalue * cos(joy->Degree);
	case field2:
		car->LS = maxvalue * cos(joy->Degree - 90);
		car->RS = sqrt(pow(joy->x, 2) + pow(joy->y, 2));
	case field3:
		car->LS = -sqrt(pow(joy->x, 2) + pow(joy->y, 2));
		car->RS = maxvalue * cos(joy->Degree - 180);
	case field4:
		car->LS = -maxvalue * cos(joy->Degree - 270);
		car->RS = -sqrt(pow(joy->x, 2) + pow(joy->y, 2));
	}
}

/*
 * udacity traffic final project.c
 *
 * Created: 7/30/2022 3:57:25 AM
 * Author : mohye
 */ 

					/*includes*/
#include "application/APPLICATION_INTERFACE.h"

int main(void)
{
	/*initializing the car traffic lights and the peds traffic lights*/
	CarTraffic_init();
	PedTraffic_init();
	/*starting the ped traffic light as an interrupt working with a push button*/
	PedTraffic_working();
	/*super loop of the application*/
    while (1) 
    {
		/*starting the car traffic light to be running as long as the program is running*/
		CarTraffic_working();
    }
}


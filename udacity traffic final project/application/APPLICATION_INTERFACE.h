/*
 * APPLICATION_INTERFACE.h
 *
 * Created: 7/30/2022 4:33:30 AM
 *  Author: mohye
 */ 


#ifndef APPLICATION_INTERFACE_H_
#define APPLICATION_INTERFACE_H_

/*application enum status*/
typedef enum AppErrorStatus
{
	App_ok,App_CarTraffic_error,App_PedTraffic_error
}AppErrorStatus;




/*a function to initialize the car traffic lights*/
AppErrorStatus CarTraffic_init(void);

/*a function for the car traffic working*/
AppErrorStatus CarTraffic_working(void);

/*a function to initialize the pedestarian traffic lights*/
AppErrorStatus PedTraffic_init(void);

/*a function for the car traffic working*/
AppErrorStatus PedTraffic_working(void);


/* a function to check for the traffic light of cars and change to ped mode*/
AppErrorStatus PedTraffic_change(void);

#endif /* APPLICATION_INTERFACE_H_ */
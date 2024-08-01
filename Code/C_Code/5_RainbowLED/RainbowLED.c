/**********************************************************************
* Filename    : ColorfulLED.c
* Description : Random color change ColorfulLED
* Author      : www.freenove.com
* modification: 2024/07/29
**********************************************************************/
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

#define ledPinRed    5
#define ledPinGreen  6
#define ledPinBlue   13

void setupLedPin(void)
{
	softPwmCreate(ledPinRed,  0, 100);	//Creat SoftPWM pin for red
	softPwmCreate(ledPinGreen,0, 100);  //Creat SoftPWM pin for green
	softPwmCreate(ledPinBlue, 0, 100);  //Creat SoftPWM pin for blue
}

void setLedColor(int r, int g, int b)
{
	softPwmWrite(ledPinRed,   r);	//Set the duty cycle 
	softPwmWrite(ledPinGreen, g);   //Set the duty cycle 
	softPwmWrite(ledPinBlue,  b);   //Set the duty cycle 
}

int main(void)
{
	int r,g,b;
	
	printf("Program is starting ...\n");
	
	wiringPiSetupGpio();//Initialize wiringPi. Use BCM Number.
	
	setupLedPin();
	while(1){
		r=random()%100;  //get a random in (0,100)
		g=random()%100;  //get a random in (0,100)
		b=random()%100;  //get a random in (0,100)
		setLedColor(r,g,b);//set random as the duty cycle value 
		printf("r=%d,  g=%d,  b=%d \n",r,g,b);
		delay(1000);
	}
	return 0;
}

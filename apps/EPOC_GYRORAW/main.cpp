/****************************************************************************
**
** Copyright 2014 by Emotiv. All rights reserved
** Example 6 - GyroData: MODIFIED
** This example allows built-in 2-axis gyroscope position
** Simply turn your head from left to right, up and down.
** You will also notice the red indicator dot move in accordance with
** the movement of your head/gyroscope
**
****************************************************************************/

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif

#include <iostream>

#ifdef __linux__
#include <unistd.h>
#endif

#include <cmath>
#include <vector>

#include "edk.h"
#include "edkErrorCode.h"
#include "EmoStateDLL.h"

#define PI 3.1418

bool  oneTime    = true,
      outOfBound = false;
float currX      = 0,
      currY      = 0;
float xmax       = 0,
      ymax       = 0,
      x          = 0;
float preX       = 0,
      preY       = 0;
int   incOrDec   = 10;
int   count      = 0;
float oldXVal    = 0,
      oldYVal    = 0;
double maxRadius = 10000;
unsigned long pass = 0,
              globalElapsed = 0;

void changeXY(int x) // x = 0 : idle
{	
	if( currX >0 )
	{
		float temp = currY/currX;					
		currX -= incOrDec;
		currY = temp*currX;
	}
	else if( currX < 0)
	{ 
		float temp = currY/currX;		
		currX += incOrDec;
		currY = temp*currX;
	}
	else 
	{
		if( currY > 0 ) currY -= incOrDec;
		else if( currY <0 ) currY += incOrDec;
	}				
	if( x == 0)
	{
        if( (std::abs(currX) <= incOrDec) && (std::abs(currY) <= incOrDec))
		{
			xmax = 0;
			ymax = 0;
		}
		else
		{
			xmax = currX;
			ymax = currY;
		}
	}
	else
	{
        if( (std::abs(currX) <= incOrDec) && (std::abs(currY) <= incOrDec))
		{
			xmax = 0;
			ymax = 0;
		}
	}
}


std::vector<float> updateValues(void)
{	  
   int gyroX = 0,gyroY = 0;
   EE_HeadsetGetGyroDelta(0,&gyroX,&gyroY);
   xmax += gyroX;
   ymax += gyroY;

   if( outOfBound )
   {
	   if( preX != gyroX && preY != gyroY )
	   {
		   xmax = currX;
		   ymax = currY;
	   }
   }

   double val = sqrt((float)(xmax*xmax + ymax*ymax));
  
   //std::cout <<"xmax : " << xmax <<" ; ymax : " << ymax << std::endl;
   std::vector<float> ValoresGiro;

   ValoresGiro.push_back(xmax);
   ValoresGiro.push_back(ymax);

   
   if( val >= maxRadius )
   {
	   changeXY(1);	
	   outOfBound = true;
	   preX = gyroX;
	   preY = gyroY;
   }
   else
   {		
	   outOfBound = false;
		if(oldXVal == gyroX && oldYVal == gyroY)
		{
			++count;
			if( count > 10 )
			{									
				changeXY(0);
			}
		}
		else
		{
			count = 0;
			currX = xmax;
			currY = ymax;
			oldXVal = gyroX;
			oldYVal = gyroY;			
		}
   }
#ifdef _WIN32
      Sleep(15);
#endif
#ifdef __linux__
      sleep(1);
#endif
   return ValoresGiro;
}


#ifdef __linux__
double GetTickCount()
{
    struct timespec now;
    if (clock_gettime(CLOCK_MONOTONIC, &now))
      return 0;
    return now.tv_sec * 1000.0 + now.tv_nsec / 1000000.0;
}
#endif

/* 
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
   EmoEngineEventHandle hEvent = EE_EmoEngineEventCreate();
   EmoStateHandle eState = EE_EmoStateCreate();
   unsigned int userID = -1;
   EE_EngineConnect();	
   if(oneTime)
   {
      std::cout << "Start after 8 seconds\n";
#ifdef _WIN32
	  Sleep(8000);
#endif
#ifdef __linux__
      sleep(8);
#endif
	  oneTime = false;
   }

#ifdef _WIN32
   globalElapsed = GetTickCount();
#endif
#ifdef __linux__
   globalElapsed = ( unsigned long ) GetTickCount();
#endif


   std::vector<float> DatosGiro;
   for (int i = 0; i < atoi(argv[1]); i++)
   {
	   DatosGiro = updateValues();
	   if (DatosGiro.size() > 0){
		   printf("Num. Data = %d - ", DatosGiro.size());
		   for (int k = 0; k < DatosGiro.size(); k++)
		   {
			   printf(" %f ", DatosGiro.at(k));
		   }
		   printf("\n");
	   }
	   else
	   {
		   printf("NO DATA!\n");
	   }
	   DatosGiro.clear();
   }
      
   EE_EngineDisconnect();
   EE_EmoStateFree(eState);
   EE_EmoEngineEventFree(hEvent);	

   return 0;
}

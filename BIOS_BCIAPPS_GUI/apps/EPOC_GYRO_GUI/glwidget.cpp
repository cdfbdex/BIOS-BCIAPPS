#include <qmessagebox.h>

#include "glwidget.h"

//// Procedure to get info of gyroscope
//Preprocessing directives

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <iostream>

#ifdef __linux__
#include <unistd.h>
#endif

#include <cmath>

#include "edk.h"
#include "edkErrorCode.h"
#include "EmoStateDLL.h"

#define PI 3.1418


using namespace std;

// Global variables
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
int   counter      = 0;
float oldXVal    = 0,
      oldYVal    = 0;
double maxRadius = 10000;
unsigned long pass = 0,
              globalElapsed = 0;

// Emotiv variables
unsigned int userID = -1;
EmoEngineEventHandle hEvent;
EmoStateHandle eState;

// Functions
void drawCircle( float Radius, int numPoints )
{
  glBegin( GL_LINE_STRIP );
    for( int i=0; i<numPoints; i++ )
    {
		float Angle = i * (2.0*PI/numPoints); // use 360 instead of 2.0*PI if
		float X = cos( Angle )*Radius;  // you use d_cos and d_sin
		float Y = sin( Angle )*Radius;
		glVertex2f( X, Y );		
	}
  glEnd();
}

void drawFilledCircle(float radius)
{
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glPointSize(radius);
}

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


#ifdef __linux__
double GetTickCount()
{
    struct timespec now;
    if (clock_gettime(CLOCK_MONOTONIC, &now))
      return 0;
    return now.tv_sec * 1000.0 + now.tv_nsec / 1000000.0;
}
#endif


//// Class of the widget

GLWidget::GLWidget(QWidget *parent):
	QGLWidget(parent)
{
	//connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
	connect(&timer,SIGNAL(timeout()),this,SLOT(updateDisplay()));
	timer.start(20);

}

void GLWidget::initializeGL()
{
	hEvent = EE_EmoEngineEventCreate();
	eState = EE_EmoStateCreate();
	EE_EngineConnect();
//	if(oneTime)
//	{
//		//std::cout << "Start after 3 seconds\n";
//#ifdef _WIN32
//	Sleep(3000);
//#endif
//#ifdef __linux__
//	sleep(3);
//#endif
//		oneTime = false;
//	}

#ifdef _WIN32
	globalElapsed = GetTickCount();
#endif
#ifdef __linux__
	globalElapsed = ( unsigned long ) GetTickCount();
#endif

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);


	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);

	//QMessageBox msgbox;
	//msgbox.setText("Inicializado");
	//msgbox.exec();

}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
  
	glColor3f(1.0,1.0,1.0);
	drawCircle(800,100);
	glColor3f(0.0,0.0,1.0);
	drawCircle(maxRadius-4000,800);
	glColor3f(0.0,1.0,1.0);
	drawCircle(maxRadius,1000);
  
	glColor3f(1.0, 0.0, 0.0);   
	glRectf(currX-400.0, currY-400.0, currX+400.0, currY+400.0);
   
	glPopMatrix();
	//glutSwapBuffers();
}

void GLWidget::updateDisplay(void)
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
  
   
    //cout <<"xmax : " << xmax <<" ; ymax : " << ymax << endl;

   
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
			++counter;
			if( counter > 10 )
			{									
				changeXY(0);
			}
		}
		else
		{
			counter = 0;
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
	//glutPostRedisplay(); 
}

void GLWidget::resizeGL(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20000.0, 20000.0, -20000.0, 20000.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glViewport(0,0,w,h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(45, float(w/h), 0.01, 100.0);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(0,0,5, 0,0,0, 0,1,0);
}
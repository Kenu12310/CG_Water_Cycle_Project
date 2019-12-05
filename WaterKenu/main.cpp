#include<math.h>
#include<GL/glut.h>

int f = 2;

void *fonts[]=
{
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_18,
	GLUT_BITMAP_HELVETICA_12
};

void rain(float x1,float y1)
{
	glColor3f(0.0,0.0,0.8);
	glLineWidth(2.0);
	glPushMatrix();
	glTranslatef(0.0,20.0,0.0);
	for(float i = y1;i >= y1 - 250;i -= 20)
	{
		for(float j = x1;j <= x1 + 100;j += 10)
		{
			glBegin(GL_LINES);
			glVertex2f(j, i);
			glVertex2f(j, i - 10);
			glEnd();
			glFlush();
		}

		for(int k = 0;k <= 10000000;k++);
	}
glPopMatrix();
}

void circle(GLfloat r1,GLfloat r2,GLfloat r3)
{
	float x1,y1,x2,y2;
	float angle;
	float radius = r3;
	x1 = r1,y1 = r2;
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	for(angle = 1.0;angle <= 360.0f;angle += 0.2)
	{
		x2 = x1 + cos(angle) * radius;
		y2 = y1 + sin(angle) * radius;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2,y2);
	}
	glEnd();
}

void cloud1()
{
	glColor3f(0.627,0.627,0.627);
	circle(90.0,500.0,35.0);
	circle(130.0,510.0,45.0);
	circle(170.0,495.0,35.0);
	circle(150.0,460.0,30.0);
	circle(115.0,470.0,35.0);

}

void cloud2()
{
	glColor3f(0.627,0.627,0.627);
	circle(390.0,540.0,35.0);
	circle(430.0,550.0,45.0);
	circle(470.0,535.0,35.0);
	circle(450.0,500.0,30.0);
	circle(415.0,510.0,35.0);

}

void cloud3()
{
	glColor3f(0.627,0.627,0.627);
	circle(740.0,500.0,35.0);
	circle(780.0,510.0,45.0);
	circle(820.0,495.0,35.0);
	circle(800.0,460.0,30.0);
	circle(765.0,470.0,35.0);

}

void sun()
{
	glColor3f(0.995,0.443,0.078);
	circle(200,500,40);
}

void evaporation(float x,float y)
{
	int i;
	glColor3f(0.0,0.0,0.8);
	glBegin(GL_POINTS);
	for(float i = y;i >= y - 10;i--)
	{
		glVertex2f(x,i);
		x++;
	}
	for(i = y-10;i >= y - 20;i--)
	{
		glVertex2f(x,i);
		x += 0.5;
	}
	for(i = y - 20;i >= y-30;i--)
	{
		glVertex2f(x,i);
		x += 0.2;
	}
	for(i = y - 30;i >= y-40;i--)
	{
		glVertex2f(x,i);
		x -= 0.2;
	}
	for(i = y - 40;i >= y - 50;i--)
	{
		glVertex2f(x,i);
		x -= 0.5;
	}
	for(i = y - 50;i >= y-60;i--)
	{
		glVertex2f(x,i);
		x--;
	}
	for(i = y - 60;i >= y - 70;i--)
	{
		glVertex2f(x,i);
		x--;
	}
	for(i = y - 70;i >= y - 80;i--)
	{
		glVertex2f(x,i);
		x -= 0.5;
	}
	for(i = y - 80;i >= y - 90;i--)
	{
		glVertex2f(x,i);
		x -= 0.2;
	}
	for(i = -90;i >= y - 89.7;i--)
	{
		glVertex2f(x,i);
		x += 0.2;
	}
	for(i = y - 89.7;i >= y - 110;i--)
	{
		glVertex2f(x,i);
		x += 0.5;
	}
	for(i = y - 110;i >= y - 120;i--)
	{
		glVertex2f(x,i);
		x++;
	}
	glEnd();
	glFlush();
	for(int k = 0;k < 100000000;k++);
}


void rays()
{

	glColor3f(0.995,0.443,0.078);
	glLineWidth(4.0);
	glBegin(GL_LINES);

	glVertex2f(200.0,460.0); //down ray
	glVertex2f(200.0,350.0);

	glPointSize(4.0);
	glVertex2f(240.0,500.0); //right ray
	glVertex2f(340.0,500.0);

	glPointSize(4.0);
	glVertex2f(200.0,540.0); //up ray
	glVertex2f(200.0,630.0);

	glPointSize(4.0);
	glVertex2f(160.0,500.0); //left ray
	glVertex2f(60.0,500.0);

	glPointSize(4.0);
	glVertex2f(180.0,520.0); //NE ray
	glVertex2f(80.0,610.0);

	glPointSize(4.0);
	glVertex2f(220.0,520.0); //NW ray
	glVertex2f(320.0,610.0);

	glPointSize(4.0);
	glVertex2f(180.0,480.0); //SE ray
	glVertex2f(80.0,390.0);

	glPointSize(4.0);
	glVertex2f(220.0,480.0); //SW ray
	glVertex2f(320.0,390.0);
	glEnd();
}

void output(int x, int y, char *string,void *font)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//sea
	glColor3f(0.0,0.4,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,300.0);
	glVertex2f(600.0,300.0);
	glVertex2f(1000.0,0.0);
	glEnd();
	//land
	glColor3f(0.0,0.6,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(600.0,300.0);
	glVertex2f(1000.0,300.0);
	glVertex2f(1000.0,0.0);
	glEnd();
	//first mountain
	glColor3f(0.6,0.298,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(600.0,300.0);
	glVertex2f(700.0,450.0);
	glVertex2f(805.0,300.0);
	glEnd();
	//second mountain
	glColor3f(0.6,0.298,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(805.0,300.0);
	glVertex2f(900.5,450.0);
	glVertex2f(1000.0,300.0);
	glEnd();
	//river
	glColor3f(0.0,0.4,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(790.00,300.0);
	glVertex2f(700.0,150.0);
	glVertex2f(815.0,100.0);
	glVertex2f(815.0,300.0);
	glEnd();
}

void display1()
{
	display();
	sun();
	rays();
	glFlush();
}

void display2()
{

	display();
	sun();
	rays();
	evaporation(100.0,325.0);
	evaporation(200.0,325.0);
	evaporation(300.0,325.0);
	evaporation(400.0,325.0);
	evaporation(500.0,325.0);

	glColor3f(0.0,0.0,0.0);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(530.0,260.0);
	glVertex2f(530.0,360.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(515.0,360.0);
	glVertex2f(545.0,360.0);
	glVertex2f(530.0,375.0);
	glEnd();
	output(450,380,"EVAPORATION",fonts[3]);
	glFlush();
}

void display3()
{

	display();
	evaporation(300.0,325.0);
	evaporation(400.0,325.0);
	cloud1();
	cloud2();
	glColor3f(0.0,0.0,0.0);
	output(250,450,"CONDENSATION",fonts[3]);
	glFlush();

}

void display4()
{

	display();
	cloud1();
	cloud2();
	cloud3();
	rain(80.0,450.0);
	rain(380.0,490.0);
	rain(730.0,450.0);
	glColor3f(0.0,0.0,0.0);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(250.0,450.0);
	glVertex2f(250.0,500.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(235.0,450.0);
	glVertex2f(265.0,450.0);
	glVertex2f(250.0,435.0);
	glEnd();
	output(200,420,"PRECIPITATION",fonts[3]);
	output(250.0,150.0,"COLLECTION",fonts[3]);
	glFlush();
}

void display5()
{
	glColor3f(0.0,0.0,0.0);
	output(420,370,"THANK YOU!",fonts[3]);
	glFlush();
}

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1024,0,700);
}

void menu()
{
	glColor3f(0.8,.1,.2);
	output(380, 580, "WATER CYCLE",fonts[2]);
	glColor3f(0.1,0.1,0.1);
	glColor3f(0.5,.6,.1);
	output(440,300,"MENU",fonts[3]);
	glColor3f(0.6,0.3,0.7);
	output(400,270,"1. START",fonts[0]);
	output(400,240,"2. INTRODUCTION",fonts[0]);
	output(400,210,"3. HELP",fonts[0]);
	output(400,180,"4. EXIT",fonts[0]);
}

void help()
{
	glColor3f(0.8,0.1,0.2);
	output(440, 580, "HELP",fonts[2]);
	output(300,400,"-> Press 'n' to go to the next stage of the Water Cycle.",fonts[3]);
	glColor3f(0.8,0.1,0.2);
	output(300,350,"-> Press 'p' to go to the previous stage of the Water Cycle.",fonts[3]);
	glColor3f(1,0,1);
	output(300,300,"-> Press 'Esc' key to exit the program at any time.",fonts[3]);
	glColor3f(0.1,0.1,0.1);
	output(350,125," <Press 'b' to go back to menu>",fonts[0]);
	glColor3f(0.5,.6,.1);
}
void drawBOX(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x0, y0);
        glVertex2f(x1, y0);
        glVertex2f(x1, y1);
        glVertex2f(x0, y1);
    glEnd();
}
void intro()
{
	glColor3f(0.8,.1,.2);
	output(340, 580, "INTRODUCTION TO WATER CYCLE",fonts[2]);
	glColor3f(1,0,1);
	output(10,500,"-> Evaporation: Heat from the sun causes water from oceans, lakes, streams, ice and soils to rise into the air and turn into water vapour.",fonts[3]);
	output(10,480,"	    Water vapour droplets join together to make clouds!",fonts[3]);
	output(10,430,"-> Condensation: This is when water vapour in the air cools down and turns back into liquid water.",fonts[3]);
	output(10,380,"-> Precipitation: This is when water (in the form of rain, snow, hail or sleet) falls from clouds in the sky.",fonts[3]);
	output(10,330,"-> Collection: This is when water that falls from the clouds as rain, snow, hail or sleet, collects in the oceans, rivers, lakes, streams. ",fonts[3]);
	output(10,310,"	    Most will infiltrate (soak into) the ground and will collect as underground water.",fonts[3]);
	output(10,260,"	    *MORE: The water cycle is powered by the sun's energy and by gravity. The sun kickstarts the whole cycle by heating all the Earth's water and making it evaporate.",fonts[3]);
	output(10,240,"	    Gravity makes the moisture fall back to Earth.",fonts[3]);

    drawBOX(200.0, 350.0, 400.0, 500.0);
    drawBOX(500.0, 350.0, 700.0, 500.0);
    drawBOX(200.0, 150.0, 400.0, 300.0);
    drawBOX(500.0, 150.0, 700.0, 300.0);

	glColor3f(0.1,0.1,0.1);
	output(330,125," <Press 'b' to go back to menu>",fonts[0]);
	glColor3f(0.5,.6,.1);
}


void dis()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 0.0, 650,-2000,1500);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	if(f == 1)
		display1();

	else if(f==2)
		menu();

	else if(f==3)
		help();

	else if(f==4)
		intro();

	else if(f==5)
		display2();

	else if(f==6)
		display3();

	else if(f==7)
		display4();

	else if(f==8)
		display5();

	glFlush();
	glutSwapBuffers();
}


void Keyboard(GLubyte key, GLint x, GLint y)
{
	if(key == 27)exit(0);	//Esc-key

	if(f==2)	//menu
	{
		switch(key)
		{
			case '1':f=1;	break;
			case '2':f=4;	break;
			case '3':f=3;	break;
			case '4':	exit(0);
		}
		glutPostRedisplay();
	}
	else if(f==3)	//help
	{
		if(key=='b'||key=='B')
			f=2;
		glutPostRedisplay();
	}
	else if(f==4)	//intro
	{
		if(key=='b'||key=='B')
			f=2;
		glutPostRedisplay();
	}

	else if(f==1)   //if in 1st slide goto 2nd
	{
		if(key=='n')
			f=5;
		glutPostRedisplay();
	}
	 else if(f==5)   //if in 2nd slide goto 3rd
	 {
	 	if(key=='n')
	 		f=6;
        else if(key=='p')
            f=1;
	 	glutPostRedisplay();
	 }
	 else if(f==6)   //if in 3rd slide goto 4th
	 {
	 	if(key=='n')
	 		f=7;
        else if(key=='p')
            f=5;
	 	glutPostRedisplay();
	 }
	else if(f==7)   //if in 4th slide goto thankyou slide
	{
		if(key=='n')
			f=8;
        else if(key=='p')
            f=6;
		glutPostRedisplay();
	}
	else if(f==8)   //if in 4th slide goto thankyou slide
	{
		if(key=='n')
			f=2;
        else if(key=='p')
            f=7;
		glutPostRedisplay();
	}

	dis();
}

void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glOrtho(-2.0,2.0,-2.0 * (GLfloat)h / (GLfloat)w,2.0 * (GLfloat)h / (GLfloat)w,-10.0,10.0);
	else
		glOrtho(-2.0 * (GLfloat)w / (GLfloat)h,2.0 * (GLfloat)w / (GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}
main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1024,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("WATER CYCLE");
	glutDisplayFunc(dis);
	glutReshapeFunc(myReshape);
    glutKeyboardFunc(Keyboard);         /*Normal key is pressed */
	init();
	glutMainLoop();
}


#include<windows.h>
#include<cstdio>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 20.0      //speed of traffic

float i=0.0;    //movement of car
float m=0.0;    //movement of clouds
float n=0.0;    //movement of plane along x-axis
float o=0.0;    //  and y-axis
float c=0.0;    //movement of comet	SS

int light=1;      //1 for green-light, 0 for red-light
int day=1;        //1 for day ,0 for night
int plane=0;      //1 for plane
int comet=0;      //1 for comet


void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
int l;
if(day==1)
{
//sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();

//sun


	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(100,625,l);
}


//plane


//cloud1


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}

//cloud2


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}




	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
}
glBegin(GL_QUADS);
     glColor3f(1.0f,0.5f,0.0f);
     glVertex2f(700.0f-m,660.0f);
      glVertex2f(700.0f-m, 640.0f);
      glVertex2f(870.0f-m,640.0f);
      glVertex2f(870.0f-m,660.0f);    ///////////////////// plane
   glEnd();

glBegin(GL_TRIANGLES);
     glColor3f(0.0f,0.0f,1.0f);
     glVertex2f(720.0f-m,660.0f);
      glVertex2f(870.0f-m,660.0f);
      glVertex2f(730.0f-m,680.0f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(730.0f-m,675.0f);
      glVertex2f(725.0f-m, 665.0f);
      glVertex2f(745.0f-m,665.0f);
      glVertex2f(745.0f-m,675.0f);    ///////////////////// plane
   glEnd();
    glBegin(GL_TRIANGLES);
     glColor3f(0.3f, 0.3f, 0.3f);
     glVertex2f(840.0f-m,660.0f);
      glVertex2f(870.0f-m,660.0f);
      glVertex2f(880.0f-m,680.0f);
    glEnd();
glBegin(GL_TRIANGLES);
     glColor3f(0.3f, 0.3f, 0.3f);
     glVertex2f(730.0f-m,650.0f);
      glVertex2f(810.0f-m,620.0f);
    glVertex2f(770.0f-m,650.0f);

     glEnd();
glBegin(GL_TRIANGLES);
     glColor3f(0.3f, 0.3f, 0.3f);
     glVertex2f(800.0f-m,650.0f);
      glVertex2f(870.0f-m,620.0f);
      glVertex2f(840.0f-m,650.0f);
    glEnd();







//grass


//random



//pond
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(25,350);
glVertex2f(25,375);
glVertex2f(50,400);
glVertex2f(75,410);
glVertex2f(100,420);
glVertex2f(200,420);
glVertex2f(225,410);
glVertex2f(250,405);
glVertex2f(275,390);
glVertex2f(300,375);
glVertex2f(310,350);
glVertex2f(300,320);
glVertex2f(275,300);
glVertex2f(250,295);
glVertex2f(225,290);
glVertex2f(200,285);
glVertex2f(175,280);
glVertex2f(150,280);
glVertex2f(125,280);
glVertex2f(100,290);
glVertex2f(75,300);
glVertex2f(50,310);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,0.4);
 glVertex2f(0,270);
glVertex2f(1100,270);
 glVertex2f(1100,460);
glVertex2f(0,460);
glEnd();
glColor3f(0.0,0.0,0.4);
glBegin(GL_LINES);
 glVertex2f(0,270);
glVertex2f(1100,270);
glEnd();
//road boundary
//road
//bulidingggggg

glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
        glVertex2f(80.0f,500.0f);
      glVertex2f(80.0f, 270.0f);
      glVertex2f(180.0f,270.0f);
        glVertex2f(180.0f,500.0f);    ///////building blue2
   glEnd();
   glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(1.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,270);
glVertex2f(80,500);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(1.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(180,270);
glVertex2f(180,500);
glEnd();
   glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(130,270);
glVertex2f(130,500);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(5.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(160,270);
glVertex2f(160,500);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(5.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(100,270);
glVertex2f(100,500);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,300);
glVertex2f(180,300);
glEnd();

  glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,330);
glVertex2f(180,330);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,360);
glVertex2f(180,360);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,390);
glVertex2f(180,390);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,420);
glVertex2f(180,420);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,450);
glVertex2f(180,450);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,480);
glVertex2f(180,480);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,500);
glVertex2f(180,500);
glEnd();

   glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
        glVertex2f(90.0f,430.0f);
      glVertex2f(90.0f, 270.0f);
      glVertex2f(0.0f,270.0f);
        glVertex2f(0.0f,430.0f);    ///////building blue
   glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
        glVertex2f(70.0f,430.0f);
      glVertex2f(70.0f, 450.0f);
      glVertex2f(20.0f,450.0f);
        glVertex2f(20.0f,430.0f);    ///////building blue
   glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(60.0f,300.0f);
      glVertex2f(60.0f, 270.0f);
      glVertex2f(30.0f,270.0f);
        glVertex2f(30.0f,300.0f);    ///////building blue
   glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue landscape
  glVertex2f(0,320);
glVertex2f(90,320);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue landscape
  glVertex2f(0,355);
glVertex2f(90,355);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue landscape
  glVertex2f(0,395);
glVertex2f(90,395);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue landscape
  glVertex2f(0,425);
glVertex2f(90,425);
glEnd();

   glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(0,430);
glVertex2f(0,430);
glEnd();

  glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(10.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(30,320);
glVertex2f(30,430);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(10.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(60,320);
glVertex2f(60,430);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(10.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(86,320);
glVertex2f(86,430);
glEnd();
 glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(10.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(0,320);
glVertex2f(0,430);
glEnd();



 glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
        glVertex2f(220.0f,500.0f);
      glVertex2f(220.0f, 270.0f);
      glVertex2f(300.0f,270.0f);
        glVertex2f(300.0f,500.0f);    ///////building blue
   glEnd();

    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(210.0f,600.0f);
      glVertex2f(210.0f, 270.0f);
      glVertex2f(300.0f,270.0f);
        glVertex2f(300.0f,600.0f);
        glEnd();       ///////building red
glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);      /////vertical line
  glVertex2f(210,580);
glVertex2f(300,580);
glEnd();
glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,550);
glVertex2f(300,550);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,520);
glVertex2f(300,520);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,490);
glVertex2f(300,490);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,460);
glVertex2f(300,460);
glEnd();
glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,430);
glVertex2f(300,430);
glEnd();
glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(9.5);
glBegin(GL_LINES);    ////////////////////////lines red bulding
 glVertex2f(230,600);
glVertex2f(230,270);
 glEnd();

 glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(9.5);
glBegin(GL_LINES);
 glVertex2f(255,600);
glVertex2f(255,270);
 glEnd();

  glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(9.5);
glBegin(GL_LINES);
 glVertex2f(280,600);
glVertex2f(280,270);
 glEnd();


glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(350.0f,500.0f);///////building yellow
      glVertex2f(350.0f, 270.0f);
      glVertex2f(450.0f,270.0f);
        glVertex2f(450.0f,500.0f);
   glEnd();
           glBegin(GL_QUADS);
     glColor3f(0.5f, 0.5f, 0.7f);
        glVertex2f(430.0f,650.0f);
      glVertex2f(430.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,650.0f);    ///////building yellow top
   glEnd();
   glColor3f(0.4f,0.1f,0.5f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(440,550);
glVertex2f(440,650);     //////ok
glEnd();

      glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(410.0f,630.0f);
      glVertex2f(410.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,630.0f);    ///////building yellow top
   glEnd();

   glBegin(GL_QUADS);
     glColor3f(0.4f, 0.1f, 0.5f);
        glVertex2f(390.0f,610.0f);
      glVertex2f(390.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,610.0f);    ///////building yellow top
   glEnd();

   glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(370.0f,590.0f);
      glVertex2f(370.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,590.0f); ///////building yellow top
                  glEnd();


    glBegin(GL_QUADS);
     glColor3f(0.4f, 0.1f, 0.5f);
        glVertex2f(350.0f,570.0f);
      glVertex2f(350.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,570.0f);    ///////building yellow top
   glEnd();

         glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(330.0f,450.0f);
      glVertex2f(330.0f, 270.0f);
      glVertex2f(420.0f,270.0f);
        glVertex2f(420.0f,450.0f);    ///////building pink2
   glEnd();

           glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(7.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,300);
glVertex2f(420,300);
glEnd();

         glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,320);
glVertex2f(420,320);     //////ok
glEnd();
      glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,335);
glVertex2f(420,335);     //////ok
glEnd();
  glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,350);
glVertex2f(420,350);     //////ok
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,365);
glVertex2f(420,365);     //////ok
glEnd();

glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,380);
glVertex2f(420,380);     //////ok
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,395);
glVertex2f(420,395);     //////ok zikzek bulding
glEnd();

glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,410);
glVertex2f(420,410);     //////ok zikzek bulding
glEnd();

glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,425);
glVertex2f(420,425);     //////ok zikzek bulding
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,440);
glVertex2f(420,440);     //////ok zikzek bulding
glEnd();

          glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(11.2);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(335,450);
glVertex2f(335,300);
glEnd();
        glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(8.5);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(375,450);
glVertex2f(375,300);
glEnd();
    glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(11.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(415,450);
glVertex2f(415,300);
glEnd();

glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(200.0f,430.0f);
      glVertex2f(200.0f, 270.0f);
      glVertex2f(150.0f,270.0f);
        glVertex2f(150.0f,430.0f);    ///////building pink11111111111111111111111111111
   glEnd();
   glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(185.0f,315.0f);
      glVertex2f(185.0f, 280.0f);
      glVertex2f(165.0f,280.0f);
        glVertex2f(165.0f,315.0f);    ///////building pink11111111111111111111111111111
   glEnd();

    glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(185.0f,360.0f);
      glVertex2f(185.0f, 320.0f);
      glVertex2f(165.0f,320.0f);
        glVertex2f(165.0f,360.0f);    ///////building pink11111111111111111111111111111
   glEnd();
    glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(185.0f,400.0f);
      glVertex2f(185.0f, 365.0f);
      glVertex2f(165.0f,365.0f);
        glVertex2f(165.0f,400.0f);    ///////building pink11111111111111111111111111111
   glEnd();


         glBegin(GL_QUADS);
     glColor3f(0.5f, 0.5f, 0.0f);
        glVertex2f(280.0f,430.0f);
      glVertex2f(280.0f, 270.0f);
      glVertex2f(330.0f,270.0f);
        glVertex2f(330.0f,430.0f);    ///////buildingpink1
           glEnd();

 glBegin(GL_QUADS);
     glColor3f(1.5f, 1.5f, 0.0f);
        glVertex2f(295.0f,315.0f);
      glVertex2f(295.0f, 280.0f);
      glVertex2f(315.0f,280.0f);
        glVertex2f(315.0f,315.0f);    ///////buildingpink1111111111111111
           glEnd();
 glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(295.0f,360.0f);
      glVertex2f(295.0f, 320.0f);
      glVertex2f(315.0f,320.0f);
        glVertex2f(315.0f,360.0f);    ///////building pink11111111111111111111111111111
   glEnd();
    glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(295.0f,400.0f);
      glVertex2f(295.0f, 365.0f);
      glVertex2f(315.0f,365.0f);
        glVertex2f(315.0f,400.0f);    ///////building pink11111111111111111111111111111
   glEnd();


             glBegin(GL_QUADS);
     glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(200.0f,390.0f);
      glVertex2f(200.0f, 270.0f);
      glVertex2f(280.0f,270.0f);
        glVertex2f(280.0f,390.0f);    ///////buildingpink1
           glEnd();
 glBegin(GL_QUADS);
     glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(225.0f,320.0f);
      glVertex2f(225.0f, 270.0f);
      glVertex2f(255.0f,270.0f);
        glVertex2f(255.0f,320.0f);    ///////buildingpink1
           glEnd();
glBegin(GL_TRIANGLES);
     glColor3f(1.5f, 0.5f, 0.0f);
       glVertex2f(225.0f,320.0f);
      glVertex2f(255.0f, 320.0f);
         glVertex2f(240.0f,340.0f);    ///////buildingpink1
           glEnd();







      glBegin(GL_QUADS);
     glColor3f(0.8f, 0.5f, 0.4f);
     glVertex2f(460.0f,320.0f);
      glVertex2f(460.0f, 270.0f);
    glVertex2f(580.0f,270.0f);
        glVertex2f(580.0f,320.0f);    ///////building main
   glEnd();
   glBegin(GL_QUADS);
   glColor3f(0.0f, 1.5f, 1.0f);
   glVertex2f(460.0f,400.0f);
      glVertex2f(460.0f, 320.0f);
         glVertex2f(580.0f,320.0f);
        glVertex2f(580.0f,400.0f);    ///////building main
           glEnd();

           glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
      glVertex2f(475.0f,420.0f);
      glVertex2f(475.0f, 400.0f);
    glVertex2f(565.0f,400.0f);
    glVertex2f(565.0f,420.0f);    ///////building m
   glEnd();
        glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(475,270);
glVertex2f(475,400);     /////main bulding lines
glEnd();
   glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,270);
glVertex2f(490,450);     /////main bulding lines
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(505,270);
glVertex2f(505,450);     /////main bulding lines
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(520,270);
glVertex2f(520,450);     /////main bulding lines
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(535,270);
glVertex2f(535,450);     /////main bulding lines
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(550,270);
glVertex2f(550,450);     /////main bulding lines
glEnd();
    glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(565,270);
glVertex2f(565,400);     /////main bulding lines
glEnd();

glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(11.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,300);
glVertex2f(580,300);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,340);
glVertex2f(580,340);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,360);
glVertex2f(580,360);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,380);
glVertex2f(580,380);     /////main bulding lines landscape
glEnd();

glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,400);
glVertex2f(580,400);     /////main bulding lines landscape
glEnd();
   glBegin(GL_QUADS);
     glColor3f(0.0f, 0.5f, 1.0f);
      glVertex2f(485.0f,500.0f);
      glVertex2f(485.0f, 420.0f);
    glVertex2f(555.0f,420.0f);
    glVertex2f(555.0f,500.0f);    ///////building m
   glEnd();

   glBegin(GL_QUADS);
     glColor3f(0.3f, 0.4f, 0.4f);
     glVertex2f(495.0f,480.0f);
     glVertex2f(495.0f, 440.0f);
    glVertex2f(545.0f,440.0f);
    glVertex2f(545.0f,480.0f);    ///////building m
   glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(520,440);
glVertex2f(520,480);     /////main bulding lines vertical
glEnd();

    glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
      glVertex2f(495.0f,600.0f);
      glVertex2f(495.0f, 500.0f);
    glVertex2f(545.0f,500.0f);
      glVertex2f(545.0f,600.0f);    ///////building m
   glEnd();

   glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,600);
glVertex2f(550,600);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,580);
glVertex2f(550,580);     /////main bulding lines landscape
glEnd();

glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,560);
glVertex2f(550,560);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,540);
glVertex2f(550,540);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,520);
glVertex2f(550,520);     /////main bulding lines landscape window
glEnd();


    glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
      glVertex2f(505.0f,620.0f);
      glVertex2f(505.0f, 600.0f);
      glVertex2f(535.0f,600.0f);
      glVertex2f(535.0f,620.0f);    ///////building m
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f(540.0f, 620.0f);
    glVertex2f(500.0f,620.0f);
       glVertex2f(520.0f,660.0f);    ///////MAIN building TOP
   glEnd();

   ///////right side buildings
   /////first red building
   glBegin(GL_QUADS);
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2f(650.0f,270.0f);
     glVertex2f(750.0f,270.0f);
     glVertex2f(750.0f,450.0f);
     glVertex2f(650.0f,450.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(670.0f,450.0f);
     glVertex2f(730.0f,450.0f);
     glVertex2f(730.0f,470.0f);
     glVertex2f(670.0f,470.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(670.0f,300.0f);
     glVertex2f(730.0f,300.0f);
     glVertex2f(730.0f,420.0f);
     glVertex2f(670.0f,420.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2f(670.0f,320.0f);
     glVertex2f(730.0f,320.0f);
     glVertex2f(670.0f,340.0f);
     glVertex2f(730.0f,340.0f);
     glVertex2f(670.0f,360.0f);
     glVertex2f(730.0f,360.0f);
     glVertex2f(670.0f,380.0f);
     glVertex2f(730.0f,380.0f);
     glVertex2f(670.0f,400.0f);
     glVertex2f(730.0f,400.0f);
     glEnd();




/////blue right building
    glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
     glVertex2f(600.0f,270.0f);
     glVertex2f(700.0f,270.0f);
     glVertex2f(700.0f,400.0f);
     glVertex2f(600.0f,400.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(620.0f,290.0f);
     glVertex2f(680.0f,290.0f);
     glVertex2f(680.0f,380.0f);
     glVertex2f(620.0f,380.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(8.5);
     glColor3f(0.0f, 1.5f, 1.0f);
     glVertex2f(620.0f,300.0f);
     glVertex2f(680.0f,300.0f);
     glVertex2f(620.0f,330.0f);
     glVertex2f(680.0f,330.0f);
     glVertex2f(620.0f,360.0f);
     glVertex2f(680.0f,360.0f);
     glEnd();


     /////purple building
      glBegin(GL_QUADS);
     glColor3f(0.7f, 0.0f, 0.9f);
     glVertex2f(750.0f,270.0f);
     glVertex2f(850.0f,270.0f);
     glVertex2f(850.0f,500.0f);
     glVertex2f(750.0f,500.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(770.0f,290.0f);
     glVertex2f(830.0f,290.0f);
     glVertex2f(830.0f,480.0f);
     glVertex2f(770.0f,480.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(8.5);
     glColor3f(0.7f, 0.0f, 0.9f);
     glVertex2f(770.0f,310.0f);
     glVertex2f(830.0f,310.0f);
     glVertex2f(770.0f,330.0f);
     glVertex2f(830.0f,330.0f);
     glVertex2f(770.0f,350.0f);
     glVertex2f(830.0f,350.0f);
     glVertex2f(770.0f,370.0f);
     glVertex2f(830.0f,370.0f);
     glVertex2f(770.0f,390.0f);
     glVertex2f(830.0f,390.0f);
     glVertex2f(770.0f,410.0f);
     glVertex2f(830.0f,410.0f);
     glVertex2f(770.0f,430.0f);
     glVertex2f(830.0f,430.0f);
     glVertex2f(770.0f,450.0f);
     glVertex2f(830.0f,450.0f);
     glVertex2f(770.0f,470.0f);
     glVertex2f(830.0f,470.0f);
     glVertex2f(790.0f,480.0f);
     glVertex2f(790.0f,290.0f);
     glVertex2f(810.0f,480.0f);
     glVertex2f(810.0f,290.0f);

     glEnd();
/////yellow building
       glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(860.0f,270.0f);
     glVertex2f(1000.0f,270.0f);
     glVertex2f(1000.0f,600.0f);
     glVertex2f(860.0f,600.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(880.0f,560.0f);
     glVertex2f(980.0f,560.0f);
     glVertex2f(980.0f,580.0f);
     glVertex2f(880.0f,580.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(880.0f,520.0f);
     glVertex2f(980.0f,520.0f);
     glVertex2f(980.0f,540.0f);
     glVertex2f(880.0f,540.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(880.0f,480.0f);
     glVertex2f(980.0f,480.0f);
     glVertex2f(980.0f,500.0f);
     glVertex2f(880.0f,500.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(880.0f,440.0f);
     glVertex2f(980.0f,440.0f);
     glVertex2f(980.0f,460.0f);
     glVertex2f(880.0f,460.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(880.0f,400.0f);
     glVertex2f(980.0f,400.0f);
     glVertex2f(980.0f,420.0f);
     glVertex2f(880.0f,420.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(880.0f,360.0f);
     glVertex2f(980.0f,360.0f);
     glVertex2f(980.0f,380.0f);
     glVertex2f(880.0f,380.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(880.0f,320.0f);
     glVertex2f(980.0f,320.0f);
     glVertex2f(980.0f,340.0f);
     glVertex2f(880.0f,340.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(900.0f,270.0f);
     glVertex2f(960.0f,270.0f);
     glVertex2f(960.0f,290.0f);
     glVertex2f(900.0f,290.0f);
     glEnd();
     ////blue
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.6f);
     glVertex2f(1000.0f,270.0f);
     glVertex2f(1100.0f,270.0f);
     glVertex2f(1100.0f,420.0f);
     glVertex2f(1000.0f,420.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1000.0f,290.0f);
     glVertex2f(1100.0f,290.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1000.0f,310.0f);
     glVertex2f(1100.0f,310.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1000.0f,330.0f);
     glVertex2f(1100.0f,330.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1000.0f,350.0f);
     glVertex2f(1100.0f,350.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1000.0f,370.0f);
     glVertex2f(1100.0f,370.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1000.0f,390.0f);
     glVertex2f(1100.0f,390.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1000.0f,410.0f);
     glVertex2f(1100.0f,410.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(40);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1040.0f,280.0f);
     glVertex2f(1060.0f,280.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(40);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1040.0f,275.0f);
     glVertex2f(1060.0f,275.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(40);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(1040.0f,270.0f);
     glVertex2f(1060.0f,270.0f);
     glEnd();

}


else
{

//sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();

//moon
int l;

	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(100,625,l);
	}

//star1

glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(575,653);
glVertex2f(570,645);
glVertex2f(580,645);
glVertex2f(575,642);
glVertex2f(570,650);
glVertex2f(580,650);
glEnd();

//star2
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(975,643);
glVertex2f(970,635);
glVertex2f(980,635);
glVertex2f(975,632);
glVertex2f(970,640);
glVertex2f(980,640);
glEnd();

//star3
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(875,543);
glVertex2f(870,535);
glVertex2f(880,535);
glVertex2f(875,532);
glVertex2f(870,540);
glVertex2f(880,540);
glEnd();

//star4
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(375,598);
glVertex2f(370,590);
glVertex2f(380,590);
glVertex2f(375,587);
glVertex2f(370,595);
glVertex2f(380,595);
glEnd();

//star5
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,628);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,618);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();

//star6
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(200,628);
glVertex2f(195,620);
glVertex2f(205,620);
glVertex2f(200,618);
glVertex2f(195,625);
glVertex2f(205,625);
glEnd();

//star7
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(500,543);
glVertex2f(495,535);
glVertex2f(505,535);
glVertex2f(500,532);
glVertex2f(495,540);
glVertex2f(505,540);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);

        glVertex2f(80.0f,500.0f);
      glVertex2f(80.0f, 270.0f);
      glVertex2f(180.0f,270.0f);
        glVertex2f(180.0f,500.0f);
        glEnd();


//comet
if(comet==1)
{
	for(l=0;l<=7;l++)
	{
		glColor3f(1.0,0.0,1.0);
		draw_circle(300+c,675,l);
	}

glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(200+c,675);
	glVertex2f(300+c,682);
	glVertex2f(300+c,668);
	glEnd();
}

//Plane
if(plane==1)
{

	for(l=0;l<=1;l++)
	{
		glColor3f(1.0,0.0,0.0);
		draw_circle(950+n,625+o,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(954+n,623+o,l);

	}



}

//grass


//pond
glColor3f(0.0,0.0,0.4);
glBegin(GL_POLYGON);
glVertex2f(25,350);
glVertex2f(25,375);
glVertex2f(50,400);
glVertex2f(75,410);
glVertex2f(100,420);
glVertex2f(200,420);
glVertex2f(225,410);
glVertex2f(250,405);
glVertex2f(275,390);
glVertex2f(300,375);
glVertex2f(310,350);
glVertex2f(300,320);
glVertex2f(275,300);
glVertex2f(250,295);
glVertex2f(225,290);
glVertex2f(200,285);
glVertex2f(175,280);
glVertex2f(150,280);
glVertex2f(125,280);
glVertex2f(100,290);
glVertex2f(75,300);
glVertex2f(50,310);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,0.4);
 glVertex2f(0,270);
glVertex2f(1100,270);
 glVertex2f(1100,460);
glVertex2f(0,460);
glEnd();

glColor3f(0.0,0.0,0.4);
glBegin(GL_LINES);
 glVertex2f(0,270);
glVertex2f(1100,270);
glEnd();
//road boundary
//road
//bulidingggggg

glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(80.0f,500.0f);
      glVertex2f(80.0f, 270.0f);
      glVertex2f(180.0f,270.0f);
        glVertex2f(180.0f,500.0f);    ///////building blue2
   glEnd();
   glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(1.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,270);
glVertex2f(80,500);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(1.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(180,270);
glVertex2f(180,500);
glEnd();
   glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(130,270);
glVertex2f(130,500);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(5.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(160,270);
glVertex2f(160,500);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(5.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(100,270);
glVertex2f(100,500);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,300);
glVertex2f(180,300);
glEnd();

  glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,330);
glVertex2f(180,330);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,360);
glVertex2f(180,360);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,390);
glVertex2f(180,390);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,420);
glVertex2f(180,420);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,450);
glVertex2f(180,450);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,480);
glVertex2f(180,480);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue 2
  glVertex2f(80,500);
glVertex2f(180,500);
glEnd();

   glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
        glVertex2f(90.0f,430.0f);
      glVertex2f(90.0f, 270.0f);
      glVertex2f(0.0f,270.0f);
        glVertex2f(0.0f,430.0f);    ///////building blue
   glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
        glVertex2f(70.0f,430.0f);
      glVertex2f(70.0f, 450.0f);
      glVertex2f(20.0f,450.0f);
        glVertex2f(20.0f,430.0f);    ///////building blue
   glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(60.0f,300.0f);
      glVertex2f(60.0f, 270.0f);
      glVertex2f(30.0f,270.0f);
        glVertex2f(30.0f,300.0f);    ///////building blue
   glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue landscape
  glVertex2f(0,320);
glVertex2f(90,320);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue landscape
  glVertex2f(0,355);
glVertex2f(90,355);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue landscape
  glVertex2f(0,395);
glVertex2f(90,395);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue landscape
  glVertex2f(0,425);
glVertex2f(90,425);
glEnd();

   glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(14.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(0,430);
glVertex2f(0,430);
glEnd();

  glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(10.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(30,320);
glVertex2f(30,430);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(10.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(60,320);
glVertex2f(60,430);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(10.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(86,320);
glVertex2f(86,430);
glEnd();
 glColor3f(0.0f,0.0f,0.0f);
  glLineWidth(10.5);
glBegin(GL_LINES);      /////vertical line blue
  glVertex2f(0,320);
glVertex2f(0,430);
glEnd();



 glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(220.0f,500.0f);
      glVertex2f(220.0f, 270.0f);
      glVertex2f(300.0f,270.0f);
        glVertex2f(300.0f,500.0f);    ///////building blue
   glEnd();

    glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(210.0f,600.0f);
      glVertex2f(210.0f, 270.0f);
      glVertex2f(300.0f,270.0f);
        glVertex2f(300.0f,600.0f);
        glEnd();       ///////building red
glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);      /////vertical line
  glVertex2f(210,580);
glVertex2f(300,580);
glEnd();
glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,550);
glVertex2f(300,550);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,520);
glVertex2f(300,520);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,490);
glVertex2f(300,490);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,460);
glVertex2f(300,460);
glEnd();
glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(11.5);
glBegin(GL_LINES);           /////vertical line
  glVertex2f(210,430);
glVertex2f(300,430);
glEnd();
glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(9.5);
glBegin(GL_LINES);    ////////////////////////lines red bulding
 glVertex2f(230,600);
glVertex2f(230,270);
 glEnd();

 glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(9.5);
glBegin(GL_LINES);
 glVertex2f(255,600);
glVertex2f(255,270);
 glEnd();

  glColor3f(1.0f,0.0f,0.0f);
  glLineWidth(9.5);
glBegin(GL_LINES);
 glVertex2f(280,600);
glVertex2f(280,270);
 glEnd();


           glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(350.0f,500.0f);///////building yellow
      glVertex2f(350.0f, 270.0f);
      glVertex2f(450.0f,270.0f);
        glVertex2f(450.0f,500.0f);
   glEnd();
           glBegin(GL_QUADS);
     glColor3f(0.5f, 0.5f, 0.7f);
        glVertex2f(430.0f,650.0f);
      glVertex2f(430.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,650.0f);    ///////building yellow top
   glEnd();
   glColor3f(0.4f,0.1f,0.5f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(440,550);
glVertex2f(440,650);     //////ok
glEnd();

      glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(410.0f,630.0f);
      glVertex2f(410.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,630.0f);    ///////building yellow top
   glEnd();

   glBegin(GL_QUADS);
     glColor3f(0.4f, 0.1f, 0.5f);
        glVertex2f(390.0f,610.0f);
      glVertex2f(390.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,610.0f);    ///////building yellow top
   glEnd();

   glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(370.0f,590.0f);
      glVertex2f(370.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,590.0f); ///////building yellow top
                  glEnd();


    glBegin(GL_QUADS);
     glColor3f(0.4f, 0.1f, 0.5f);
        glVertex2f(350.0f,570.0f);
      glVertex2f(350.0f, 500.0f);
      glVertex2f(450.0f,500.0f);
        glVertex2f(450.0f,570.0f);    ///////building yellow top
   glEnd();


         glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(330.0f,450.0f);
      glVertex2f(330.0f, 270.0f);
      glVertex2f(420.0f,270.0f);
        glVertex2f(420.0f,450.0f);    ///////building pink2
   glEnd();

           glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(7.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,300);
glVertex2f(420,300);
glEnd();

         glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,320);
glVertex2f(420,320);     //////ok
glEnd();
      glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,335);
glVertex2f(420,335);     //////ok
glEnd();
  glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,350);
glVertex2f(420,350);     //////ok
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,365);
glVertex2f(420,365);     //////ok
glEnd();

glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,380);
glVertex2f(420,380);     //////ok
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,395);
glVertex2f(420,395);     //////ok zikzek bulding
glEnd();

glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,410);
glVertex2f(420,410);     //////ok zikzek bulding
glEnd();

glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,425);
glVertex2f(420,425);     //////ok zikzek bulding
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(330,440);
glVertex2f(420,440);     //////ok zikzek bulding
glEnd();

          glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(11.2);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(335,450);
glVertex2f(335,300);
glEnd();
        glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(8.5);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(375,450);
glVertex2f(375,300);
glEnd();
    glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(11.0);
glBegin(GL_LINES);           /////vertical line pink2
  glVertex2f(415,450);
glVertex2f(415,300);
glEnd();

glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(200.0f,430.0f);
      glVertex2f(200.0f, 270.0f);
      glVertex2f(150.0f,270.0f);
        glVertex2f(150.0f,430.0f);    ///////building pink11111111111111111111111111111
   glEnd();
   glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(185.0f,315.0f);
      glVertex2f(185.0f, 280.0f);
      glVertex2f(165.0f,280.0f);
        glVertex2f(165.0f,315.0f);    ///////building pink11111111111111111111111111111
   glEnd();

    glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(185.0f,360.0f);
      glVertex2f(185.0f, 320.0f);
      glVertex2f(165.0f,320.0f);
        glVertex2f(165.0f,360.0f);    ///////building pink11111111111111111111111111111
   glEnd();
    glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(185.0f,400.0f);
      glVertex2f(185.0f, 365.0f);
      glVertex2f(165.0f,365.0f);
        glVertex2f(165.0f,400.0f);    ///////building pink11111111111111111111111111111
   glEnd();


         glBegin(GL_QUADS);
     glColor3f(0.5f, 0.5f, 0.0f);
        glVertex2f(280.0f,430.0f);
      glVertex2f(280.0f, 270.0f);
      glVertex2f(330.0f,270.0f);
        glVertex2f(330.0f,430.0f);    ///////buildingpink1
           glEnd();

 glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(295.0f,315.0f);
      glVertex2f(295.0f, 280.0f);
      glVertex2f(315.0f,280.0f);
        glVertex2f(315.0f,315.0f);    ///////buildingpink1111111111111111
           glEnd();
 glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(295.0f,360.0f);
      glVertex2f(295.0f, 320.0f);
      glVertex2f(315.0f,320.0f);
        glVertex2f(315.0f,360.0f);    ///////building pink11111111111111111111111111111
   glEnd();
    glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(295.0f,400.0f);
      glVertex2f(295.0f, 365.0f);
      glVertex2f(315.0f,365.0f);
        glVertex2f(315.0f,400.0f);    ///////building pink11111111111111111111111111111
   glEnd();


             glBegin(GL_QUADS);
     glColor3f(0.0f, 0.7f, 0.0f);
        glVertex2f(200.0f,390.0f);
      glVertex2f(200.0f, 270.0f);
      glVertex2f(280.0f,270.0f);
        glVertex2f(280.0f,390.0f);    ///////buildingpink1
           glEnd();
 glBegin(GL_QUADS);
     glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(225.0f,320.0f);
      glVertex2f(225.0f, 270.0f);
      glVertex2f(255.0f,270.0f);
        glVertex2f(255.0f,320.0f);    ///////buildingpink1
           glEnd();
glBegin(GL_TRIANGLES);
     glColor3f(1.5f, 0.5f, 0.0f);
       glVertex2f(225.0f,320.0f);
      glVertex2f(255.0f, 320.0f);
         glVertex2f(240.0f,340.0f);    ///////buildingpink1
           glEnd();







      glBegin(GL_QUADS);
     glColor3f(0.8f, 0.5f, 0.4f);
     glVertex2f(460.0f,320.0f);
      glVertex2f(460.0f, 270.0f);
    glVertex2f(580.0f,270.0f);
        glVertex2f(580.0f,320.0f);    ///////building main
   glEnd();
   glBegin(GL_QUADS);
   glColor3f(0.0f, 1.5f, 1.0f);
   glVertex2f(460.0f,400.0f);
      glVertex2f(460.0f, 320.0f);
         glVertex2f(580.0f,320.0f);
        glVertex2f(580.0f,400.0f);    ///////building main
           glEnd();

           glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
      glVertex2f(475.0f,420.0f);
      glVertex2f(475.0f, 400.0f);
    glVertex2f(565.0f,400.0f);
    glVertex2f(565.0f,420.0f);    ///////building m
   glEnd();
        glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(475,270);
glVertex2f(475,400);     /////main bulding lines
glEnd();
   glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,270);
glVertex2f(490,450);     /////main bulding lines
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(505,270);
glVertex2f(505,450);     /////main bulding lines
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(520,270);
glVertex2f(520,450);     /////main bulding lines
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(535,270);
glVertex2f(535,450);     /////main bulding lines
glEnd();
glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(550,270);
glVertex2f(550,450);     /////main bulding lines
glEnd();
    glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(6.0);
glBegin(GL_LINES);           /////
  glVertex2f(565,270);
glVertex2f(565,400);     /////main bulding lines
glEnd();

glColor3f(1.0f,1.0f,1.0f);
   glLineWidth(11.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,300);
glVertex2f(580,300);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,340);
glVertex2f(580,340);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,360);
glVertex2f(580,360);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,380);
glVertex2f(580,380);     /////main bulding lines landscape
glEnd();

glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(460,400);
glVertex2f(580,400);     /////main bulding lines landscape
glEnd();
   glBegin(GL_QUADS);
     glColor3f(0.0f, 0.5f, 1.0f);
      glVertex2f(485.0f,500.0f);
      glVertex2f(485.0f, 420.0f);
    glVertex2f(555.0f,420.0f);
    glVertex2f(555.0f,500.0f);    ///////building m
   glEnd();

   glBegin(GL_QUADS);
     glColor3f(0.3f, 0.4f, 0.4f);
     glVertex2f(495.0f,480.0f);
     glVertex2f(495.0f, 440.0f);
    glVertex2f(545.0f,440.0f);
    glVertex2f(545.0f,480.0f);    ///////building m
   glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(5.0);
glBegin(GL_LINES);           /////
  glVertex2f(520,440);
glVertex2f(520,480);     /////main bulding lines vertical
glEnd();

    glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
      glVertex2f(495.0f,600.0f);
      glVertex2f(495.0f, 500.0f);
    glVertex2f(545.0f,500.0f);
      glVertex2f(545.0f,600.0f);    ///////building m
   glEnd();

   glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,600);
glVertex2f(550,600);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,580);
glVertex2f(550,580);     /////main bulding lines landscape
glEnd();

glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,560);
glVertex2f(550,560);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,540);
glVertex2f(550,540);     /////main bulding lines landscape
glEnd();
glColor3f(0.0f,0.0f,0.0f);
   glLineWidth(9.0);
glBegin(GL_LINES);           /////
  glVertex2f(490,520);
glVertex2f(550,520);     /////main bulding lines landscape window
glEnd();


    glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
      glVertex2f(505.0f,620.0f);
      glVertex2f(505.0f, 600.0f);
      glVertex2f(535.0f,600.0f);
      glVertex2f(535.0f,620.0f);    ///////building m
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f(540.0f, 620.0f);
    glVertex2f(500.0f,620.0f);
       glVertex2f(520.0f,660.0f);    ///////MAIN building TOP
   glEnd();
   ///////right side buildings
   /////first red building
   glBegin(GL_QUADS);
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2f(650.0f,270.0f);
     glVertex2f(750.0f,270.0f);
     glVertex2f(750.0f,450.0f);
     glVertex2f(650.0f,450.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(670.0f,450.0f);
     glVertex2f(730.0f,450.0f);
     glVertex2f(730.0f,470.0f);
     glVertex2f(670.0f,470.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(670.0f,300.0f);
     glVertex2f(730.0f,300.0f);
     glVertex2f(730.0f,420.0f);
     glVertex2f(670.0f,420.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2f(670.0f,320.0f);
     glVertex2f(730.0f,320.0f);
     glVertex2f(670.0f,340.0f);
     glVertex2f(730.0f,340.0f);
     glVertex2f(670.0f,360.0f);
     glVertex2f(730.0f,360.0f);
     glVertex2f(670.0f,380.0f);
     glVertex2f(730.0f,380.0f);
     glVertex2f(670.0f,400.0f);
     glVertex2f(730.0f,400.0f);
     glEnd();




/////blue right building
    glBegin(GL_QUADS);
     glColor3f(0.0f, 1.5f, 1.0f);
     glVertex2f(600.0f,270.0f);
     glVertex2f(700.0f,270.0f);
     glVertex2f(700.0f,400.0f);
     glVertex2f(600.0f,400.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(620.0f,290.0f);
     glVertex2f(680.0f,290.0f);
     glVertex2f(680.0f,380.0f);
     glVertex2f(620.0f,380.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(8.5);
     glColor3f(0.0f, 1.5f, 1.0f);
     glVertex2f(620.0f,300.0f);
     glVertex2f(680.0f,300.0f);
     glVertex2f(620.0f,330.0f);
     glVertex2f(680.0f,330.0f);
     glVertex2f(620.0f,360.0f);
     glVertex2f(680.0f,360.0f);
     glEnd();


     /////purple building
      glBegin(GL_QUADS);
     glColor3f(0.7f, 0.0f, 0.9f);
     glVertex2f(750.0f,270.0f);
     glVertex2f(850.0f,270.0f);
     glVertex2f(850.0f,500.0f);
     glVertex2f(750.0f,500.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(770.0f,290.0f);
     glVertex2f(830.0f,290.0f);
     glVertex2f(830.0f,480.0f);
     glVertex2f(770.0f,480.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(8.5);
     glColor3f(0.7f, 0.0f, 0.9f);
     glVertex2f(770.0f,310.0f);
     glVertex2f(830.0f,310.0f);
     glVertex2f(770.0f,330.0f);
     glVertex2f(830.0f,330.0f);
     glVertex2f(770.0f,350.0f);
     glVertex2f(830.0f,350.0f);
     glVertex2f(770.0f,370.0f);
     glVertex2f(830.0f,370.0f);
     glVertex2f(770.0f,390.0f);
     glVertex2f(830.0f,390.0f);
     glVertex2f(770.0f,410.0f);
     glVertex2f(830.0f,410.0f);
     glVertex2f(770.0f,430.0f);
     glVertex2f(830.0f,430.0f);
     glVertex2f(770.0f,450.0f);
     glVertex2f(830.0f,450.0f);
     glVertex2f(770.0f,470.0f);
     glVertex2f(830.0f,470.0f);
     glVertex2f(790.0f,480.0f);
     glVertex2f(790.0f,290.0f);
     glVertex2f(810.0f,480.0f);
     glVertex2f(810.0f,290.0f);

     glEnd();
/////yellow building
       glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(860.0f,270.0f);
     glVertex2f(1000.0f,270.0f);
     glVertex2f(1000.0f,600.0f);
     glVertex2f(860.0f,600.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(880.0f,560.0f);
     glVertex2f(980.0f,560.0f);
     glVertex2f(980.0f,580.0f);
     glVertex2f(880.0f,580.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(880.0f,520.0f);
     glVertex2f(980.0f,520.0f);
     glVertex2f(980.0f,540.0f);
     glVertex2f(880.0f,540.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(880.0f,480.0f);
     glVertex2f(980.0f,480.0f);
     glVertex2f(980.0f,500.0f);
     glVertex2f(880.0f,500.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(880.0f,440.0f);
     glVertex2f(980.0f,440.0f);
     glVertex2f(980.0f,460.0f);
     glVertex2f(880.0f,460.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(880.0f,400.0f);
     glVertex2f(980.0f,400.0f);
     glVertex2f(980.0f,420.0f);
     glVertex2f(880.0f,420.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(880.0f,360.0f);
     glVertex2f(980.0f,360.0f);
     glVertex2f(980.0f,380.0f);
     glVertex2f(880.0f,380.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(880.0f,320.0f);
     glVertex2f(980.0f,320.0f);
     glVertex2f(980.0f,340.0f);
     glVertex2f(880.0f,340.0f);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(900.0f,270.0f);
     glVertex2f(960.0f,270.0f);
     glVertex2f(960.0f,290.0f);
     glVertex2f(900.0f,290.0f);
     glEnd();
     ////blue
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.6f);
     glVertex2f(1000.0f,270.0f);
     glVertex2f(1100.0f,270.0f);
     glVertex2f(1100.0f,420.0f);
     glVertex2f(1000.0f,420.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1000.0f,290.0f);
     glVertex2f(1100.0f,290.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1000.0f,310.0f);
     glVertex2f(1100.0f,310.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1000.0f,330.0f);
     glVertex2f(1100.0f,330.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1000.0f,350.0f);
     glVertex2f(1100.0f,350.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1000.0f,370.0f);
     glVertex2f(1100.0f,370.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1000.0f,390.0f);
     glVertex2f(1100.0f,390.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(10);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1000.0f,410.0f);
     glVertex2f(1100.0f,410.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(40);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1040.0f,280.0f);
     glVertex2f(1060.0f,280.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(40);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1040.0f,275.0f);
     glVertex2f(1060.0f,275.0f);
     glEnd();
     glBegin(GL_LINES);
     glLineWidth(40);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(1040.0f,270.0f);
     glVertex2f(1060.0f,270.0f);
     glEnd();


}
glColor3f(0.0,0.0,0.4);
glBegin(GL_LINES);
 glVertex2f(0,270);
glVertex2f(1100,270);
glEnd();
//road boundary
//road
//bulidingggggg

glBegin(GL_QUADS);
glColor3f(0.0,0.5,0.5);
glVertex2f(0,230);
glVertex2f(1100,230);
glVertex2f(1100,270);
glVertex2f(0,270);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.5,0.5,0.5);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,230);
glVertex2f(0,230);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1,0.1,0.1);
glVertex2f(0,0);
glVertex2f(1100,0);
glVertex2f(1100,160);
glVertex2f(0,160);
glEnd();




//signal
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();


	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.7,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}

//car 1
 glColor3f(0.5,0.1,1.0);
glBegin(GL_POLYGON);
glVertex2f(50+i,100);  //////red window violet
glVertex2f(50+i,70);
 glVertex2f(160+i,70);
glVertex2f(160+i,100);              /////////////////////black car
 glVertex2f(140+i,100);
glVertex2f(120+i,130);
glVertex2f(80+i,130);/////PERFECT
glEnd();

 glColor3f(1.0,0.5,9.5);
glBegin(GL_POLYGON);
glVertex2f(105+i,125);  //////red window
 glVertex2f(105+i,100);
 glVertex2f(130+i,100);
glVertex2f(115+i,125);
glEnd();
 glBegin(GL_POLYGON);
glVertex2f(60+i,100);  //////red window
 glVertex2f(95+i,100);
 glVertex2f(95+i,125);
glVertex2f(85+i,125);/////PERFECT
glEnd();

	glColor3f(0.0,0.0,0.0);
	draw_circle(80+i,70,7);
	draw_circle(120+i,70,7);


///////////////////////////////////////
 ////car2
   glColor3f(0.7,1.7,0.9);
glBegin(GL_POLYGON);
glVertex2f(100+i,240);  //////red window fade bus
glVertex2f(100+i,200);
glVertex2f(100+i,150);                  //////light green bus
glVertex2f(250+i,150);
glVertex2f(250+i,200);
glVertex2f(220+i,200);     ///////perfect
glVertex2f(220+i,240);
 glEnd();
glColor3f(0.0,0.0,0.0);
 glBegin(GL_POLYGON);
glVertex2f(220+i,240);  //////red window
glVertex2f(220+i,200);
glVertex2f(250+i,200);
 glEnd();

 glBegin(GL_POLYGON);
glVertex2f(180+i,235);  //////red window
glVertex2f(180+i,200);
glVertex2f(215+i,200);
glVertex2f(215+i,235);
glEnd();
 glBegin(GL_POLYGON);
glVertex2f(140+i,235);  //////red window
glVertex2f(140+i,200);
glVertex2f(175+i,200);
glVertex2f(175+i,235);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(105+i,235);  //////red window
glVertex2f(105+i,200);
glVertex2f(135+i,200);
glVertex2f(135+i,235);
glEnd();


	glColor3f(0.0,0.0,0.0);
	draw_circle(140+i,150,7);
	draw_circle(200+i,150,7);

///////////
   //new car
glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(400+i,160);  //////red window greenbus
 glVertex2f(400+i,80);
glVertex2f(550+i,80);
glVertex2f(550+i,130);
glVertex2f(530+i,160);     ///////perfect
  glEnd();

  glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(405+i,155);  //////red window
 glVertex2f(405+i,130);
glVertex2f(425+i,130);
glVertex2f(425+i,155);
   glEnd();
   glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(430+i,155);  //////red window
 glVertex2f(430+i,130);
glVertex2f(450+i,130);
glVertex2f(450+i,155);
   glEnd();
   glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(455+i,155);  //////red window
 glVertex2f(455+i,130);
glVertex2f(475+i,130);
glVertex2f(475+i,155);
   glEnd();

   glBegin(GL_POLYGON);
glVertex2f(480+i,155);  //////red window
 glVertex2f(480+i,130);
glVertex2f(500+i,130);
glVertex2f(500+i,155);
   glEnd();

   glBegin(GL_POLYGON);
glVertex2f(510+i,155);  //////red window
 glVertex2f(510+i,130);
glVertex2f(540+i,130);
glVertex2f(520+i,155);
   glEnd();

	glColor3f(0.0,0.0,0.0);
	draw_circle(450+i,80,7);
	draw_circle(500+i,80,7);



   glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100+i,160);
 glVertex2f(-130+i,150); //////red window blackcar
 glVertex2f(-130+i,130);
glVertex2f(10+i,130);
glVertex2f(10+i,150);
glVertex2f(-30+i,160);
   glEnd();
glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100+i,190);
glVertex2f(-100+i,160);
 glVertex2f(-30+i,160); //////red window
 glVertex2f(-30+i,190);
 glEnd();
 glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
 glVertex2f(-95+i,185);
 glVertex2f(-95+i,165);
 glVertex2f(-70+i,165);
 glVertex2f(-70+i,185);
  glEnd();
  glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
 glVertex2f(-65+i,185);
 glVertex2f(-65+i,165);
 glVertex2f(-40+i,165);
  glVertex2f(-40+i,185);
  glEnd();

 //for(l=0;l<20;l++)
  // {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-90+i,130,7); //////////////////////done
	draw_circle(-50+i,130,7);
  // }

   glColor3f(0.0,1.8,1.9);
glBegin(GL_POLYGON);
glVertex2f(580+i,70);
 glVertex2f(580+i,10); //////red window lightblue
 glVertex2f(710+i,10);                               ////done
glVertex2f(710+i,70);    ///////perfect
  glEnd();

  glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(690+i,70);
 glVertex2f(690+i,50); //////red window
 glVertex2f(710+i,50);
glVertex2f(710+i,70);    ///////perfect
  glEnd();
  glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(665+i,70);
 glVertex2f(665+i,50); //////red window
 glVertex2f(685+i,50);
glVertex2f(685+i,70);    ///////perfect
  glEnd();

   glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(640+i,70);
 glVertex2f(640+i,50); //////red window
 glVertex2f(660+i,50);
glVertex2f(660+i,70);    ///////perfect
  glEnd();

  glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(615+i,70);
 glVertex2f(615+i,50); //////red window
 glVertex2f(635+i,50);
glVertex2f(635+i,70);    ///////perfect
  glEnd();
  glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(585+i,70);
 glVertex2f(585+i,50); //////red window
 glVertex2f(610+i,50);
glVertex2f(610+i,70);    ///////perfect
  glEnd();
//for(l=0;l<20;l++)
  // {
	glColor3f(0.0,0.0,0.0);
	draw_circle(620+i,10,7);
	draw_circle(680+i,10,7);
   //}



////////////////////////////////////////////////////////////////cars
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(690+i,120);
 glVertex2f(690+i,100); //////red window
 glVertex2f(820+i,100);
glVertex2f(820+i,120);    ///////perfect
  glEnd();

glColor3f(1.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(700+i,150);
 glVertex2f(690+i,150); //////red window
 glVertex2f(690+i,120);
glVertex2f(820+i,120);    ///////perfect
glVertex2f(820+i,150);    ///////perfect
glVertex2f(790+i,150);    ///////perfect
 glVertex2f(770+i,190);    ///////perfect
 glVertex2f(720+i,190);    ///////perfect
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(725+i,185);
 glVertex2f(710+i,150); //////red window
 glVertex2f(740+i,150);
glVertex2f(740+i,185);    ///////p
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(745+i,185);
 glVertex2f(745+i,150); //////red window
 glVertex2f(780+i,150);
glVertex2f(765+i,185);    ///////p
glEnd();

  for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(730+i,100,8);
	draw_circle(770+i,100,8);
   }

  glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
  glVertex2f(-160+i,70);
glVertex2f(-160+i,40);    ///////p
glVertex2f(0+i,40);    ///////p
glVertex2f(0+i,70);    ///////p

glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
  glVertex2f(-40+i,100);
glVertex2f(-40+i,70);    ///////p
glVertex2f(0+i,70);    ///////p
glVertex2f(-20+i,100);    ///////p
glEnd();

glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
  glVertex2f(-35+i,95);
glVertex2f(-35+i,70);    ///////p
glVertex2f(-5+i,70);    ///////p
glVertex2f(-25+i,95);    ///////p
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
  glVertex2f(-140+i,85);
glVertex2f(-160+i,70);    ///////p
glVertex2f(-40+i,70);    ///////p
glVertex2f(-40+i,85);    ///////p
glEnd();

  for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-110+i,40,8);
	draw_circle(-50+i,40,8);
   }
glFlush();
}



void traffic_light()
{
	int l;
if(light==1)
	  {
for(l=0;l<=20;l++)
		{

glColor3f(0.0,0.7,0.0);
		draw_circle(1065,475,l);

		//glColor3f(1.0,1.0,0.0);
		//draw_circle(1065,425,l);

		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,375,l);
		}
	  }

	else
	  {

for(l=0;l<=20;l++)
		{
		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,475,l);

	    //glColor3f(0.0,0.0,0.0);
	//draw_circle(1065,425,l);

		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
		}
	  }
}


void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
if(light==0 && (i>=330 && i<=750)) //value of i when first batch vehicle is near the traffic-signal
 {

	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(light==0 && (i>=830 && i<=1100)) //value of i when second batch vehicle is near the traffic-signal
 {

	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(light==0 && (i>=1200 && i<=1620))// value of i when third vehicle is near the traffic signal
 {

	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(light==0)
 {
	 i=i;
	 ++m;
	n-=2;
	 o+=0.2;
	c+=2;

 }

else
 {

     i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>1630)
	 i=0.0;
if(m>1100)
	 m=0.0;

glutPostRedisplay();

}



void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
exit(0);
}







void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'g':
case 'G':
light=1;
break;

	case 'r':
	case 'R':
		light=0;
		break;

case 'd':
	case 'D':
		day=1;
		break;

	case 'n':
case 'N':
		day=0;
		break;

    };

}






void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	plane=1;
		 o=n=0.0;
	 }
	break;

	case 2:
	if(index==2)
	 {
		comet=1;
		 c=0.0;
	 }
	break;
	}
}





void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
draw_object();
traffic_light();
glFlush();
}






int main(int argc,char** argv)
{
int c_menu;


	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cityscape Traffic signal");
	glutDisplayFunc(display);
glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();


	c_menu=glutCreateMenu(main_menu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();
	return 0;
}



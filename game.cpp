//============================================================================
// Name        : Azmar.cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Battleship.
//============================================================================
/*
Name: Azmar kashif
Section : B
Roll no: 22i-2716
*/
#ifndef Battleship_CPP_
#define Battleship_CPP_
#include "util.h"
#include <iostream>
#include<fstream>
#include<cstdlib>
#include <stdlib.h>
#include<ctime>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
//declaration of all functions used 
void leaderboard();
void battleGround();
void currBalance();
void options();
void battleGround();
void surrender();
void fire();
void READ();
void nameAndColor();
void colorChangetoRed();
void colorChangetoBlue();
void colorChangetoGreen();

int color1 =1, color2 =2, color3 =3; //for color change
//setting all ships initially to false
bool forShip1 = false, forShip2 = false, forShip3 = false, forShip4 = false, forShip5 = false, forShip6 = false, forShip7 = false, forShip8 = false, forShip9 = false, forShip10 = false;

//setting (x, y) coordinates of all ships
int x_ship10 = 500, y_ship10 = 440;
int x_ship1 = 450, y_ship1 = 360;
int x_ship2 = 600, y_ship2 = 360;
int x_ship3 = 450, y_ship3 = 250;
int x_ship4 = 550, y_ship4 = 250;
int x_ship5 = 650, y_ship5 = 250;
int x_ship6 = 450, y_ship6 = 130;
int x_ship7 = 550, y_ship7 = 130;
int x_ship8 = 650, y_ship8 = 130;
int x_ship9 = 750, y_ship9 = 130;

//for rotating ship anticlockwise
int rot_ShipX10=150;
int rot_ShipY10=40;
int rot_ShipX1=120;
int rot_ShipY1=40;
int rot_ShipX2=120;
int rot_ShipY2=40;
int rot_ShipX3=80;
int rot_ShipY3=40;
int rot_ShipX4=80;
int rot_ShipY4=40;
int rot_ShipX5=80;
int rot_ShipY5=40;
int rot_ShipX6=40;
int rot_ShipY6=40;
int rot_ShipX7=40;
int rot_ShipY7=40;
int rot_ShipX8=40;
int rot_ShipY8=40;
int rot_ShipX9=40;
int rot_ShipY9=40;

//for screen grid
const int x=900;
const int y=1450;

// for leaderboard 
string nameForUserWhoPlays;
string ScoreHeGot;


// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 400, yI = 400;

void drawObject() {
	// DrawSquare(xI, yI, 20, colors[WHITE]);
	glutPostRedisplay();
}


bool flag = false;
void moveObject() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = true;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = false;
	}
}

/*
 * Main Canvas drawing function.
 * */


void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.

	glClearColor(4/*Red Component*/, 4,	//148.0/255/*Green Component*/,
			4/*Blue Component*/, 4 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	// DrawSquare(400, 20, 40, colors[RED]);
	
	// //Green Square
	// DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	// //Display Score
	
	DrawRoundRect(440,640,250,35,colors[DARK_ORCHID],20);
	DrawString( 450, 650, "BATTLE SHIP GAME", colors[WHITE]);
	DrawRoundRect(465,40,80,35,colors[TEAL],20);
	DrawString( 465, 50, "AUTO?", colors[WHITE]);
	DrawRoundRect(19,440,80,35,colors[TEAL],20);
	DrawString( 19, 450, "RESET?", colors[WHITE]);
	DrawRoundRect(200,560,650,35,colors[DARK_ORCHID],20);
	DrawString( 215, 570, "PLACE THESE BATTLESHIPS AND CLICK ON READ ME", colors[WHITE]);
	DrawString( 17, 340, "A", colors[BLUE]);
	DrawString( 17, 300, "B", colors[BLUE]);
	DrawString( 17, 260, "C", colors[BLUE]);
	DrawString( 17, 220, "D", colors[BLUE]);
	DrawString( 17, 180, "E", colors[BLUE]);
	DrawString( 17, 140, "F", colors[BLUE]);
	DrawString( 17, 100, "G", colors[BLUE]);
	DrawString( 17, 60, "H", colors[BLUE]);
	DrawString( 20, 20, "I", colors[BLUE]);
	DrawString( 50, 380, "1", colors[BLUE]);
	DrawString( 90, 380, "2", colors[BLUE]);
	DrawString( 130, 380, "3", colors[BLUE]);
	DrawString( 170, 380, "4", colors[BLUE]);
	DrawString( 210, 380, "5", colors[BLUE]);
	DrawString( 250, 380, "6", colors[BLUE]);
	DrawString( 300, 380, "7", colors[BLUE]);
	DrawString( 340, 380, "8", colors[BLUE]);
	DrawString( 380, 380, "9", colors[BLUE]);
	DrawString( 410, 380, "10", colors[BLUE]);
	DrawRoundRect(5,640,80,35,colors[INDIAN_RED],20);
	DrawString( 10, 650, "BACK", colors[WHITE]);
	DrawRoundRect(850,480,140,35,colors[RED],20);
	DrawString( 870, 490, "READ ME", colors[WHITE]);
	DrawRoundRect(630,480,200,35,colors[RED],20);
	DrawString( 640, 490, "START BATTLE", colors[WHITE]);
	
//drawing screen grid
	for (int Xaxis = 0; Xaxis < x; Xaxis += 40)
	{
		for (int Yaxis = 0; Yaxis < y; Yaxis += 40)
		{
			DrawLine(0, Xaxis, 1450, Xaxis, 1, colors[SKY_BLUE]);
			DrawLine(Yaxis, 0, Yaxis, 900, 1, colors[SKY_BLUE]);
		}
	}
	
	
	// // Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	// DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 

	int l=40,k=40,m=330;
	
	for(int i=0;i<9;i++) //grid for user
	{
		for(int j=0;j<10;j++)
		{ 
	    DrawSquare( k, m ,40,colors[SKY_BLUE]);
	    DrawSquare(l,m,40,colors[SKY_BLUE]);
	    l+=41;
	    k+=41;
	    }
	    l=40, k=40;
		m=m-40;
	}
	
//deploying all spaceships with different lengths
	DrawRoundRect(x_ship10,y_ship10,rot_ShipX10,rot_ShipY10,colors[MIDNIGHT_BLUE],20);

	DrawRoundRect(x_ship4,y_ship4,rot_ShipX4,rot_ShipY4,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship5,y_ship5,rot_ShipX5,rot_ShipY5,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship3,y_ship3,rot_ShipX3,rot_ShipY3,colors[MIDNIGHT_BLUE],20);

	DrawRoundRect(x_ship1,y_ship1,rot_ShipX1,rot_ShipY1,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship2,y_ship2,rot_ShipX2,rot_ShipY2,colors[MIDNIGHT_BLUE],20);

	DrawRoundRect(x_ship6,y_ship6,rot_ShipX6,rot_ShipY6,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship7,y_ship7,rot_ShipX7,rot_ShipY7,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship8,y_ship8,rot_ShipX8,rot_ShipY8,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship9,y_ship9,rot_ShipX9,rot_ShipY9,colors[MIDNIGHT_BLUE],20);
	
	
	drawObject();
	glutSwapBuffers(); // do not modify this line..
}

//this will control the firing of missiles
void fire()
{
	int counter=1;
	DrawRoundRect(30,760,110,35,colors[DARK_ORCHID],20);
	DrawString( 30, 770, "Score=220", colors[WHITE]);
while(counter<=10){ //giving total of 10 missiles and it keeps on hitting until concdition gets false

	if(counter==1) //for missiles 1
	{
		cout<<"you hit the opponent ship"<<endl;
		cout<<"Now its Enemy turn"<<endl;
		cout<<"score=60"<<endl;
		DrawString( 610, 340, "X    X    X     X", colors[RED]);
	}
	else if(counter==2) //for missiles 2
	{
		cout<<"Enemy missed the shot"<<endl;
		cout<<"Now its your turn"<<endl;
		cout<<"score=20"<<endl;
		DrawString( 810, 340, "X    X    X", colors[RED]);
	} 
	else if(counter==3)//for missiles 3
	{
		cout<<"you again missed the shot"<<endl;
		cout<<"Now its Enemy turn"<<endl;
		cout<<"score=0"<<endl;
		DrawString( 610, 225, "X    X    X", colors[RED]);
	}
	else if(counter==4) //for missiles 4
	{
		cout<<"you hit the opponent ship"<<endl;
		cout<<"Now its Enemy turn"<<endl;
		cout<<"score=60"<<endl;
		DrawString( 815, 225, "X    X    X", colors[RED]);
	}
	else if(counter==5) //for missiles 5
	{
		cout<<"Enemy hit your ship"<<endl;
		cout<<"Now its your turn"<<endl;
		cout<<"score=120"<<endl;
		DrawString( 740, 100, "X    X", colors[RED]);
	}
	else if(counter==6) //for missiles 6
	{
		cout<<"you hit the opponent ship"<<endl;
		cout<<"Now its Enemy turn"<<endl;
		cout<<"score=180"<<endl;
		DrawString( 855, 100, "X    X", colors[RED]);
	}
	else if(counter==7) //for missiles 7
	{
		cout<<"you hit the opponent ship"<<endl;
		cout<<"Now its Enemy turn"<<endl;
		cout<<"score=240"<<endl;
		DrawString( 980, 340, "X", colors[RED]);
	}
	else if(counter==8) //for missiles 8
	{
		cout<<"you missed the shot"<<endl;
		cout<<"Now its Enemy turn"<<endl;
		cout<<"score=220"<<endl;
		DrawString( 740, 25, "X", colors[RED]);
	}
	else if(counter==9) //for missiles 9
	{
		cout<<"you again missed the shot"<<endl;
		cout<<"Now its Enemy turn"<<endl;
		cout<<"score=200"<<endl;
		DrawString( 610, 60, "X", colors[RED]);
	}
	else if(counter==10) //for missiles 10
	{
		cout<<"Enemy hit your ship"<<endl;
		cout<<"score=260"<<endl;
		DrawString( 980, 20, "X", colors[RED]);
	}
	counter++;
}

		glutSwapBuffers();
}

//this function tells user about instructions before going for battle
void READ(){
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour

	DrawRoundRect(300,490,500,35,colors[GREEN],20);
	DrawString( 300, 500, "->YOU HAVE 10 MISSILES READY TO FIRE", colors[WHITE]);
	DrawRoundRect(300,390,300,35,colors[GREEN],20);
	DrawString( 300, 400, "->PRESS FIREEE! TO FIRE", colors[WHITE]);
	DrawRoundRect(300,290,165,35,colors[GREEN],20);
	DrawString( 300, 300, "->GOODLUCK", colors[WHITE]);
	DrawRoundRect(795,190,50,35,colors[INDIAN_RED],20);
	DrawString( 800, 200, "OK", colors[WHITE]);

	glutSwapBuffers();
}

//adding options for user if he wants to buy anything additionally
void options()
{
	glClear (GL_COLOR_BUFFER_BIT);
	DrawRoundRect(395,490,335,35,colors[DARK_ORCHID],20);
	DrawString( 400, 500, "What do you want to purchase?", colors[WHITE]);
	DrawRoundRect(395,340,180,35,colors[DARK_ORCHID],20);
	DrawString( 400, 350, "1.Mines for 50$", colors[WHITE]);
	DrawRoundRect(395,240,230,35,colors[DARK_ORCHID],20);
	DrawString( 400, 250, "2.Submarine for 100$", colors[WHITE]);
	DrawRoundRect(395,140,220,35,colors[DARK_ORCHID],20);
	DrawString( 400, 150, "3.Bombers for 150$", colors[WHITE]);
	DrawRoundRect(10,640,75,35,colors[INDIAN_RED],20);
	DrawString( 10, 650, "BACK", colors[WHITE]);

	glutSwapBuffers();
}

//showing users current balance
void currBalance()
{
	glClear (GL_COLOR_BUFFER_BIT);
	DrawRoundRect(400,490,295,35,colors[DARK_ORCHID],20);
	DrawString( 400, 500, "Your Current  Balance = 500", colors[WHITE]);
	DrawRoundRect(10,790,80,35,colors[INDIAN_RED],20);
	DrawString( 10, 800, "BACK", colors[WHITE]);

	glutSwapBuffers();
}

//showing names and scores of people 
void leaderboard()
{
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	
	DrawSquare(0, 0, 1455, colors[LIME_GREEN]);

	for (int forX = 0; forX < x ; forX += 40)
	{ 
		for (int forY = 0; forY < y ; forY += 40)
		{
			DrawLine(0, forX, x, forX, 1, colors[LIME_GREEN]);
			DrawLine(forY, 0, forY, y, 1, colors[LIME_GREEN]);
		}
	}
	
	DrawRoundRect(390,690,200,35,colors[INDIAN_RED],20);
	DrawString(400, 700, "LEADER BOARD", colors[LIGHT_SEA_GREEN]);

	ifstream score;
	string a;
	score.open("score.txt");
	while (getline(score, a))
	{
		DrawString(50, 700, a, colors[LIGHT_SEA_GREEN]);
	}

	DrawRoundRect(20,790,70,35,colors[INDIAN_RED],20);
	DrawString( 25, 800, "BACK", colors[WHITE]);
	glutSwapBuffers();
}

void datafiles()
{
	ofstream score;
	score.open("score.txt");
	score << nameForUserWhoPlays << " " << ScoreHeGot << " " << endl;
	score.close();
}

//this function get called when user click in BATTLE
void battleGround()
{

	DrawString( 574, 340, "A", colors[BLUE]);
	DrawString( 574, 300, "B", colors[BLUE]);
	DrawString( 574, 260, "C", colors[BLUE]);
	DrawString( 574, 220, "D", colors[BLUE]);
	DrawString( 574, 180, "E", colors[BLUE]);
	DrawString( 574, 140, "F", colors[BLUE]);
	DrawString( 574, 100, "G", colors[BLUE]);
	DrawString( 574, 60, "H", colors[BLUE]);
	DrawString( 574, 20, "I", colors[BLUE]);
	DrawString( 605, 380, "1", colors[BLUE]);
	DrawString( 645, 380, "2", colors[BLUE]);
	DrawString( 685, 380, "3", colors[BLUE]);
	DrawString( 725, 380, "4", colors[BLUE]);
	DrawString( 765, 380, "5", colors[BLUE]);
	DrawString( 805, 380, "6", colors[BLUE]);
	DrawString( 845, 380, "7", colors[BLUE]);
	DrawString( 885, 380, "8", colors[BLUE]);
	DrawString( 925, 380, "9", colors[BLUE]);
	DrawString( 965, 380, "10", colors[BLUE]);
	DrawRoundRect(810,400,180,35,colors[RED],20);
	DrawString( 810, 410, "SURRENDER? :(", colors[WHITE]);
	DrawRoundRect(610,400,110,35,colors[RED],20);
	DrawString( 610, 410, "FIREEEE!", colors[WHITE]);

	//drawiing grid for computer
	int s=40,w=40,dis=330;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<10;j++)
		{ 
	    DrawSquare( w+560, dis ,40,colors[SKY_BLUE]);
	    DrawSquare(560+s,dis,40,colors[SKY_BLUE]);
	    s+=41;
	    w+=41;
	    }
	    s=40, w=40;
		dis=dis-40;
	}

	glutSwapBuffers();
}

//if user surrenders this function gets called
void surrender()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	DrawRoundRect(490,590,150,35,colors[GREEN],20);
	DrawString( 500, 600, "GOOD BYE.", colors[WHITE]);
	DrawRoundRect(100,500,865,35,colors[GREEN],20);
	DrawString( 100, 510, "->THANKS FOR COMING WE REALLY APPRECIATE YOUR PRESENCE HERE.", colors[WHITE]);
	DrawRoundRect(100,400,650,35,colors[GREEN],20);
	DrawString( 100, 410, "->I HOPE YOU ENJOYED FIGHTING YOUR OPPONENT.", colors[WHITE]);
	DrawRoundRect(100,300,650,35,colors[GREEN],20);
	DrawString( 100, 310, "->YOU'VE TRIED YOUR BEST IN THE BATTLEGROUND.", colors[WHITE]);
	DrawRoundRect(100,200,750,35,colors[GREEN],20);
	DrawString( 100, 210, "->PLEASE COME AGAIN WITH A BETTER FIGHTING STRATEGY.", colors[WHITE]);
	DrawRoundRect(700,50,300,35,colors[INDIAN_RED],20);
	DrawString( 700, 60, "GO BACK TO MAIN MENU", colors[WHITE]);
	
	glutSwapBuffers();
}

//if user wants to change his battleship color
void nameAndColor(){
	glClearColor(0/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			0.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	

	// DrawString( 500, 500, "WELCOME AZMAR TO SEA BATTLESHIP 2", colors[WHITE]);
	DrawRoundRect(330,630,440,35,colors[DARK_ORCHID],20);
	DrawString( 350, 640, "ENTER COLOR FOR BATTLESHIPS ", colors[WHITE]);
	DrawRoundRect(350,540,90,35,colors[DARK_ORCHID],20);
	DrawString( 350, 550, "1. RED ", colors[WHITE]);
	DrawRoundRect(350,440,90,35,colors[DARK_ORCHID],20);
	DrawString( 350, 450, "2. BLUE ", colors[WHITE]);
	DrawRoundRect(350,340,110,35,colors[DARK_ORCHID],20);
	DrawString( 350, 350, "3. GREEN ", colors[WHITE]);
	DrawRoundRect(880,90,90,35,colors[INDIAN_RED],20);
	DrawString( 890, 100, "NEXT ", colors[WHITE]);

	glutSwapBuffers();

}

//when he wants red color
void colorChangetoRed()
{
	
	DrawRoundRect(x_ship10,y_ship10,rot_ShipX10,rot_ShipY10,colors[RED],20);

	DrawRoundRect(x_ship4,y_ship4,rot_ShipX4,rot_ShipY4,colors[RED],20);
	DrawRoundRect(x_ship5,y_ship5,rot_ShipX5,rot_ShipY5,colors[RED],20);
	DrawRoundRect(x_ship3,y_ship3,rot_ShipX3,rot_ShipY3,colors[RED],20);

	DrawRoundRect(x_ship1,y_ship1,rot_ShipX1,rot_ShipY1,colors[RED],20);
	DrawRoundRect(x_ship2,y_ship2,rot_ShipX2,rot_ShipY2,colors[RED],20);

	DrawRoundRect(x_ship6,y_ship6,rot_ShipX6,rot_ShipY6,colors[RED],20);
	DrawRoundRect(x_ship7,y_ship7,rot_ShipX7,rot_ShipY7,colors[RED],20);
	DrawRoundRect(x_ship8,y_ship8,rot_ShipX8,rot_ShipY8,colors[RED],20);
	DrawRoundRect(x_ship9,y_ship9,rot_ShipX9,rot_ShipY9,colors[RED],20);
	glutSwapBuffers();
}
	
//when he wants blue color
void colorChangetoBlue(){
	DrawRoundRect(x_ship10,y_ship10,rot_ShipX10,rot_ShipY10,colors[MIDNIGHT_BLUE],20);

	DrawRoundRect(x_ship4,y_ship4,rot_ShipX4,rot_ShipY4,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship5,y_ship5,rot_ShipX5,rot_ShipY5,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship3,y_ship3,rot_ShipX3,rot_ShipY3,colors[MIDNIGHT_BLUE],20);

	DrawRoundRect(x_ship1,y_ship1,rot_ShipX1,rot_ShipY1,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship2,y_ship2,rot_ShipX2,rot_ShipY2,colors[MIDNIGHT_BLUE],20);

	DrawRoundRect(x_ship6,y_ship6,rot_ShipX6,rot_ShipY6,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship7,y_ship7,rot_ShipX7,rot_ShipY7,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship8,y_ship8,rot_ShipX8,rot_ShipY8,colors[MIDNIGHT_BLUE],20);
	DrawRoundRect(x_ship9,y_ship9,rot_ShipX9,rot_ShipY9,colors[MIDNIGHT_BLUE],20);
	glutSwapBuffers();
}

//when he wants green color
void colorChangetoGreen(){
	DrawRoundRect(x_ship10,y_ship10,rot_ShipX10,rot_ShipY10,colors[GREEN],20);

	DrawRoundRect(x_ship4,y_ship4,rot_ShipX4,rot_ShipY4,colors[GREEN],20);
	DrawRoundRect(x_ship5,y_ship5,rot_ShipX5,rot_ShipY5,colors[GREEN],20);
	DrawRoundRect(x_ship3,y_ship3,rot_ShipX3,rot_ShipY3,colors[GREEN],20);

	DrawRoundRect(x_ship1,y_ship1,rot_ShipX1,rot_ShipY1,colors[GREEN],20);
	DrawRoundRect(x_ship2,y_ship2,rot_ShipX2,rot_ShipY2,colors[GREEN],20);

	DrawRoundRect(x_ship6,y_ship6,rot_ShipX6,rot_ShipY6,colors[GREEN],20);
	DrawRoundRect(x_ship7,y_ship7,rot_ShipX7,rot_ShipY7,colors[GREEN],20);
	DrawRoundRect(x_ship8,y_ship8,rot_ShipX8,rot_ShipY8,colors[GREEN],20);
	DrawRoundRect(x_ship9,y_ship9,rot_ShipX9,rot_ShipY9,colors[GREEN],20);
	glutSwapBuffers();	
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}


/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

//this shows the interface of game menu
void gameMenu()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawRoundRect(340,590,430,35,colors[DARK_ORCHID],20);
	DrawRoundRect(380,140,275,35,colors[DARK_ORCHID],20);
	DrawRoundRect(380,240,145,35,colors[DARK_ORCHID],20);
	DrawRoundRect(380,340,215,35,colors[DARK_ORCHID],20);
	DrawRoundRect(380,440,265,35,colors[DARK_ORCHID],20);
	DrawRoundRect(380,50,95,35,colors[DARK_ORCHID],20);
		
	glColor4f(10,10,10, 50);
	glRasterPos3f(350, 600, 0); 
	char m1[] = "WELCOME TO BATTLE SHIP GAME";

	for (int i=0; i<strlen(m1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, m1[i]);

	glColor4f(10,10,10, 50);
	glRasterPos3f(400, 150, 0); 
	char m2[] = "VIEW LEADERBOARD";

	for (int i=0; i<strlen(m2); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, m2[i]);

	glColor4f(10,10,10, 50);
	glRasterPos3f(400, 250, 0); 
	char m3[] = "OPTIONS";
	for (int i=0; i<strlen(m3); i++)
	
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, m3[i]);
	

	glColor4f(10,10,10, 50);
	glRasterPos3f(400, 350, 0); 
	char m4[] = "VIEW BALANCE";
	
	for (int i=0; i<strlen(m4); i++)
	
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, m4[i]);
	

	glColor4f(10,10,10, 50);
	glRasterPos3f(400, 450, 0); 
	char m5[] = "START NEW GAME";

	for (int i=0; i<strlen(m5); i++)
	
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, m5[i]);
		
	glColor4f(10,10,10, 50);
	glRasterPos3f(400, 60, 0);
	char m6[] = "EXIT!";

	for (int i=0; i<strlen(m6); i++)
	
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, m6[i]);

	glutSwapBuffers();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveObject();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) 
{

	if(forShip1 == true)
	{
		x_ship1 = x;
		y_ship1 = 840-y;	//this will decrement the x and y axis of the ship as the user moves it
		glutPostRedisplay();
	}

	if(forShip2 == true)
	{
		x_ship2 = x;
		y_ship2 = 840-y;	
		glutPostRedisplay();
	}

	if(forShip3 == true)
	{
		// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		x_ship3 = x;
		y_ship3 = 840-y;	
		glutPostRedisplay();
	}

	if(forShip4 == true)
	{
		x_ship4 = x;
		y_ship4 = 840-y;	
		glutPostRedisplay();
	}

	if(forShip5 == true)
	{
		x_ship5 = x;
		y_ship5 = 840-y;	
		glutPostRedisplay();
	}

	if(forShip6 == true)
	{
		x_ship6 = x;
		y_ship6 = 840-y;	
		glutPostRedisplay();
	}
	
	if(forShip7 == true)
	{
		x_ship7 = x;
		y_ship7 = 840-y;	
		glutPostRedisplay();
	}

	if(forShip8 == true)
	{
		x_ship8 = x;
		y_ship8 = 840-y;	
		glutPostRedisplay();
	}

	if(forShip9 == true)
	{
		x_ship9 = x;
		y_ship9 = 840-y;	
		glutPostRedisplay();
	}

	if(forShip10 == true)
	{
		x_ship10 = x;
		y_ship10 = 840-y;	
		glutPostRedisplay();
	}

	glutPostRedisplay();
}
void MouseMoved(int x, int y){
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {


	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		// cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			// cout<<"Right Button Pressed"<<endl;
	}
	if(button == GLUT_LEFT_BUTTON)
	{
		if(x>=512 && x<=643 && y>=365 && y<=395) //setting coordinates for game
		{
			glutDisplayFunc(nameAndColor); //calling certain func
		}
		else if((x>=15 && x<= 68) && (y >= 163 && y <= 180))  
		{	
			glutDisplayFunc(gameMenu);  //calling certain func
		}
		else if(x>=392 && x<=587 && y>=469 && y<=487) 
		{
			glutDisplayFunc(currBalance);  //calling certain func
		}
		else if((x>=16 && x<= 65) && (y >= 23 && y <= 37)) 
		{
			glutDisplayFunc(gameMenu);  //calling certain func
		}
		else if(x>=384 && x<=516 && y>=573 && y<=586)
		{
			glutDisplayFunc(options);  //calling certain func
		}
		else if((x>=16 && x<= 65) && (y >= 173 && y <= 188))
		{
			glutDisplayFunc(gameMenu);  //calling certain func
		}
		else if(x>=392 && x<=650 && y>=669 && y<=687)
		{
			glutDisplayFunc(leaderboard);  //calling certain func
		}
		else if((x>=16 && x<= 65) && (y >= 75 && y <= 88))
		{
			glutDisplayFunc(gameMenu);  //calling certain func
		}
		else if((x>=16 && x<= 65) && (y >= 75 && y <= 88))
		{
			glutDisplayFunc(GameDisplay); //calling certain func
		}
	}

	if(button == GLUT_LEFT_BUTTON ) //when pressed left mouse button
	{
		if(x>=455 && x<= 567 && y >= 451 && y<= 476) //if users moves bool value of ship gets true
		{
			forShip1 = true;
		}
	}
	if(button == GLUT_RIGHT_BUTTON)   //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830)){
			forShip1 = false;  //after placing ship it again gets false
		}
	}


	if(button == GLUT_LEFT_BUTTON)  //when pressed left mouse button
	{
		if((x>=604 && x<= 721) && (y >= 452 && y <= 476))
		{
			forShip2 = true;  
		}
	}
	if(button == GLUT_RIGHT_BUTTON)  //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{
			forShip2 = false;   //after placing ship it again gets false
		}
	}	

	if(button == GLUT_LEFT_BUTTON)  //when pressed left mouse button
	{
		if((x>=454 && x<= 525) && (y >= 559 && y <= 586))
		{
			forShip3 = true;
		}
	}
	if(button == GLUT_RIGHT_BUTTON)  //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{
			forShip3 = false;  //after placing ship it again gets false
		}
	}	

	if(button == GLUT_LEFT_BUTTON) //when pressed left mouse button
	{
		if((x>=555 && x<= 628) && (y >= 560 && y <= 584))
		{
			forShip4 = true;
		}
	}
	if(button == GLUT_RIGHT_BUTTON) //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{
			forShip4 = false;  //after placing ship it again gets false
		}
	}

	if(button == GLUT_LEFT_BUTTON)  //when pressed left mouse button
	{
		if((x>=653 && x<= 725) && (y >= 559 && y <= 586))
		{
			forShip5 = true;
		}
	}
	if(button == GLUT_RIGHT_BUTTON)  //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{ 
			forShip5 = false;  //after placing ship it again gets false
		}
	}

	if(button == GLUT_LEFT_BUTTON)  //when pressed left mouse button
	{  
		if((x>=454 && x<= 487) && (y >= 679 && y <= 703))
		{
			forShip6 = true;
		}
	}
	if(button == GLUT_RIGHT_BUTTON)  //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{
			forShip6 = false;  //after placing ship it again gets false
		}
	}

	if(button == GLUT_LEFT_BUTTON)  //when pressed left mouse button
	{
		if((x>=554 && x<= 589) && (y >= 681 && y <= 705))
		{
			forShip7 = true;
		}
	}
	if(button == GLUT_RIGHT_BUTTON)  //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{
			forShip7 = false;  //after placing ship it again gets false
		}
	}
 
	if(button == GLUT_LEFT_BUTTON)  //when pressed left mouse button
	{
		if((x>=652 && x<= 686) && (y >= 680 && y <= 708))
		{
			forShip8 = true;
		}
	}
	if(button == GLUT_RIGHT_BUTTON) //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{
			forShip8 = false;  //after placing ship it again gets false
		}
	}

	if(button == GLUT_LEFT_BUTTON)  //when pressed left mouse button
	{
		if((x>=751 && x<= 791) && (y >= 681 && y <= 705))
		{
			forShip9 = true;
		}
	} 
	if(button == GLUT_RIGHT_BUTTON)  //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{
			forShip9 = false;  //after placing ship it again gets false
		}
	}

	if(button == GLUT_LEFT_BUTTON)  //when pressed left mouse button
	{
		if((x>=502 && x<= 648) && (y >= 371 && y <= 398))
		{
			forShip10 = true;	
		}
	}

	if(button == GLUT_RIGHT_BUTTON)  //when pressed Right mouse button
	{
		if((x>=40 && x<= 400) && (y >= 479 && y <= 830))
		{
			forShip10 = false;  //after placing ship it again gets false
		}
	}

if(button == GLUT_LEFT_BUTTON)
//this will control ships auto placement
{
	if((x>=476 && x<= 540) && (y >= 771 && y <= 789))
	{
		if(forShip1==0)
		{
			x_ship10=60;
			y_ship10=330;
		}
		if(forShip2==0)
		{
			x_ship1=300;
			y_ship1=330;
		}
		if(forShip3==0)
		{
			x_ship2=60;
			y_ship2=250;
		}
		if(forShip4==0)
		{
			x_ship3=200;
			y_ship3=250;
		}
		if(forShip5==0)
		{
			x_ship4=310;
			y_ship4=210;
		}
		if(forShip6==0)
		{
			x_ship5=150;
			y_ship5=130;
		}
		if(forShip7==0)
		{
			x_ship6=40;
			y_ship6=45;
		}
		if(forShip8==0)
		{
			x_ship7=40;
			y_ship7=180;
		}
		if(forShip9==0)
		{
			x_ship8=365;
			y_ship8=130;
		}
		if(forShip10==0)
		{
			x_ship9=285;
			y_ship9=10;
		}
	}
}
//this will reset the placed ships to its original position
if(button == GLUT_LEFT_BUTTON)
{
	if((x>=25 && x<= 80) && (y >= 375 && y <= 389))
	{
		if(forShip1==0)
		{
			x_ship10=500;
			y_ship10=440;
		}
		if(forShip2==0)
		{
			x_ship1=450;
			y_ship1=360;
		}
		if(forShip3==0)
		{
			x_ship2=600;
			y_ship2=360;
		}
		if(forShip4==0)
		{
			x_ship3=450;
			y_ship3=250;
		}
		if(forShip5==0)
		{
			x_ship4=550;
			y_ship4=250;
		}
		if(forShip6==0)
		{
			x_ship5=650;
			y_ship5=250;
		}
		if(forShip7==0)
		{
			x_ship6=450;
			y_ship6=130;
		}
		if(forShip8==0)
		{
			x_ship7=550;
			y_ship7=130;
		}
		if(forShip9==0)
		{
			x_ship8=650;
			y_ship8=130;
		}
		if(forShip10==0)
		{
			x_ship9=750;
			y_ship9=130;
		}
	}
}

if(button == GLUT_LEFT_BUTTON)
{
		if((x>=800 && x<= 987) && (y >= 319 && y <= 345))
		{
			glutDisplayFunc(READ); //if users want to read 
		}
		else if((x>=16 && x<= 65) && (y >= 126 && y <= 139))
		{
			glutDisplayFunc(GameDisplay);  
		}
		else if((x>=612 && x<= 710) && (y >= 404 && y <= 427))
		{
			int i=1;
			while(i<10){
				glutDisplayFunc(fire);  //this will call fire func 10 times 
				i++;
			}
		}
		else if((x>=815 && x<= 987) && (y >= 405 && y <= 432))
		{
			glutDisplayFunc(surrender);
		}
		else if((x>=750 && x<= 994) && (y >= 752 && y <= 780))
		{
			glutDisplayFunc(gameMenu);
		}
		else if((x>=386 && x<= 461) && (y >= 755 && y <= 782))
		{
			exit(1);  //if user wants to exit game
		}
		else if((x>=804 && x<= 844) && (y >= 615 && y <= 634))
		{
			glutDisplayFunc(GameDisplay);
		}
		else if((x>=638 && x<= 809) && (y >= 326 && y <= 350))
		{
			glutDisplayFunc(battleGround);
		}
		else if((x>=885 && x<= 958) && (y >= 715 && y <= 743))
		{
			glutDisplayFunc(GameDisplay);
		}
		else if((x>=28 && x<= 88) && (y >= 20 && y <= 47))
		{
			glutDisplayFunc(gameMenu);
		}

	}		
	glutPostRedisplay();			
}

void PrintableKeys(unsigned char key, int x, int y) {
/*
this will rotate the x and y axis of ships for its anti clockwise direction
*/
	
	if(key == 'A' || key == 'a') //for ship1
	{
		cout<<"v pressed";
		int temp=0;
		if(forShip10)
		{
			temp=rot_ShipX10;
			rot_ShipX10=rot_ShipY10;
			rot_ShipY10=temp;
			glutPostRedisplay();
		}
	}

	if(key == 's' || key == 'S') //for ship2
	{
		int temp=0;
		if(forShip1)
		{
			temp=rot_ShipX1;
			rot_ShipX1=rot_ShipY1;
			rot_ShipY1=temp;
			glutPostRedisplay();
		}
	}

	if(key == 'd' || key == 'D'){ //for ship3
		int temp=0;
		if(forShip2){
			temp=rot_ShipX2;
			rot_ShipX2=rot_ShipY2;
			rot_ShipY2=temp;
			glutPostRedisplay();
		}
	}

	if(key == 'f' || key == 'F') //for ship4
	{
		int temp=0;
		if(forShip3)
		{
			temp=rot_ShipX3;
			rot_ShipX3=rot_ShipY3;
			rot_ShipY3=temp;
			glutPostRedisplay();
		}
	}

	if(key == 'g' || key == 'G') //for ship5
	{
		int temp=0;
		if(forShip4)
		{
			temp=rot_ShipX4;
			rot_ShipX4=rot_ShipY4;
			rot_ShipY4=temp;
			glutPostRedisplay();
		}
	}

	if(key == 'h' || key == 'H') //for ship6
	{
		int temp=0;
		if(forShip5)
		{
			temp=rot_ShipX5;
			rot_ShipX5=rot_ShipY5;
			rot_ShipY5=temp;
			glutPostRedisplay();
		}
	}

	if(key == 'j' || key == 'J')  //for ship7
	{
		int temp=0;
		if(forShip6)
		{
			temp=rot_ShipX6;
			rot_ShipX6=rot_ShipY6;
			rot_ShipY6=temp;
			glutPostRedisplay();
		}
	}

	if(key == 'k' || key == 'K')  //for ship8
	{
		int temp=0;
		if(forShip7)
		{
			temp=rot_ShipX7;
			rot_ShipX7=rot_ShipY7;
			rot_ShipY7=temp;
			glutPostRedisplay();
		}
	}

	if(key == 'l' || key == 'L')  //for ship9
	{
		int temp=0;
		if(forShip8)
		{
			// DrawRoundRect(x_ship10,y_ship10,x1,y1,colors[GREEN],20);
			temp=rot_ShipX8;
			rot_ShipX8=rot_ShipY8;
			rot_ShipY8=temp;
			glutPostRedisplay();
		}
	}

	if(key == ';' || key == ';')  //for ship10
	{
		int temp=0;
		if(forShip9)
		{
			// DrawRoundRect(x_ship10,y_ship10,x1,y1,colors[GREEN],20);
			temp=rot_ShipX9;
			rot_ShipX9=rot_ShipY9;
			rot_ShipY9=temp;
			glutPostRedisplay();
		}
	}

	if(key == '1')
	{	
		//if user enters 1 for color
		glutDisplayFunc(colorChangetoRed);
	}

	if(key == '2')
	{
		//if user enters 2 for color
		glutDisplayFunc(colorChangetoBlue);	
	}

	if(key == '3')
	{
		//if user enters 3 for color
		glutDisplayFunc(colorChangetoGreen);	
	}
		glutPostRedisplay();
}


/*
 * our gateway main function
 * */

int main(int argc, char*argv[]) {
	string name;
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	cout<<"Enter your name: "<<endl;
	getline(cin, name);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(gameMenu); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Battleship_CPP_ */
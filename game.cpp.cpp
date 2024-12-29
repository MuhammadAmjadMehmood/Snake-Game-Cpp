#include<iostream>
#include<windows.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdio.h>
void instructions();
void menu();
void snakegame();
void exit();
void gameover();
void restartGame();
void exit2();


using namespace std;
int gd=DETECT,gm,keydir,foodx,foody,snakex[200],snakey[200];

int delaytime=30;
	int food=0;
    int x;
	int olddir=1;
	int snake_length=0;
	int hurdle_x1 = 310, hurdle_y1 = 100, hurdle_width1 = 10, hurdle_height1 = 120;
    int hurdle_x2 = 310, hurdle_y2 = 300, hurdle_width2 = 10, hurdle_height2 = 120;
	int hurdle_x3 = 80, hurdle_y3 = 250, hurdle_width3 = 500, hurdle_height3 = 10;
	bool game=true;
	
    
int main()
{
    initgraph(&gd,&gm,(char*)"");
    menu();

    
}

void menu() {
    

    // Display menu options
    readimagefile("m.jpg", 0, 0, 640, 480);

    // Get user input
    int choice = getch();

    // Perform action based on user input
    switch (choice) {
    case '1':
	readimagefile("str.jpg",0,0,640,480);
	Sleep(1500);
        snakegame();
        break;

	 case '2':
        // Display instructions
         instructions();
        break;
    case '3':
        // Quit the game
        exit();
        break;
    default:
        // Invalid input
        menu();
}
  
  }






void snakegame()
{
for(int i=0;i<200;i++)
	{
		snakex[i]=0;
		snakey[i]=0;
	}
	snakex[0]=200,snakey[0]=200;
	foodx=200,foody=200;
	keydir=1;
	//game  chal ge ab
	while(game)
	{
		//game wali jaga
		readimagefile("p.jpg",0,0,640,480);
		 setfillstyle(SOLID_FILL, RED);
    rectangle(hurdle_x1, hurdle_y1, hurdle_x1 + hurdle_width1, hurdle_y1 + hurdle_height1);
    floodfill(hurdle_x1 + 1, hurdle_y1 + 1, WHITE);
        setfillstyle(SOLID_FILL, YELLOW);
    rectangle(hurdle_x2, hurdle_y2, hurdle_x2 + hurdle_width2, hurdle_y2 + hurdle_height2);
    floodfill(hurdle_x2 + 1, hurdle_y2 + 1, WHITE);
	
    //rectangle(hurdle_x3, hurdle_y3, hurdle_x3 + hurdle_width3, hurdle_y3 + hurdle_height3);
    //floodfill(hurdle_x3 + 1, hurdle_y3 + 1, WHITE);
		
		// jab snake food ko touch hota
		if(snakex[0]==foodx && snakey[0]==foody)
		{
			snake_length=snake_length+1;
			food=food+1;
			delaytime=delaytime;
			// kahin food border yeh face pa na ajai
			do {
    foodx = (10 + rand() % 600);
    foody = (10 + rand() % 40);

    // Check if food is on the boundaries of the screen
    if (foodx < 10 || foodx > 600 || foody < 10 || foody > 400) continue;
	if (foodx >= hurdle_x1 && foodx <= hurdle_x1 + hurdle_width1 && foody >= hurdle_y1 && foody <= hurdle_y1 + hurdle_height1) continue;
   if (foodx >= hurdle_x2 && foodx <= hurdle_x2 + hurdle_width2 && foody >= hurdle_y2 && foody <= hurdle_y2 + hurdle_height2) continue;
   // if (foodx >= hurdle_x3 && foodx <= hurdle_x3 + hurdle_width3 && foody >= hurdle_y3 && foody <= hurdle_y3 + hurdle_height3) continue;
			}while(getpixel(foodx,foody)!=0 && foodx>10 && foody>10);
			foodx=foodx/10;
			foodx=foodx*10;
			foody=foody/10;
			foody=foody*10;
			if(foodx==10)
			{
				foodx=rand()%10+5;
				foodx=foodx*10;
				
			}
			else if(foody==10)
			{
				foody=rand()%10+5;
				foody=foody*10;
			}
		}
		//food graphics ma circle and bar two options ellipse be hai usa coordinates zyda
		
		circle(foodx,foody,5);
		setfillstyle(SOLID_FILL,RED);
		floodfill(foodx,foody,WHITE);
		
	
		//movement jo user key press kara us hisab sa
		
		if(GetAsyncKeyState(VK_RIGHT))
		{
			keydir=1;
			
		}
		else if(GetAsyncKeyState(VK_LEFT))
		{
			keydir=2;
		}
		else if(GetAsyncKeyState(VK_UP))
		{
			keydir=3;
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			keydir=4;
		}
		else
		{
			keydir=0;
		}
		switch(keydir) {
  case 0:
    // Snake continues in its previous direction
    if (olddir == 1) 
	{
      snakex[0] = snakex[0] + 10;
    } 
	else if (olddir == 2)
   {
      snakex[0] = snakex[0] - 10;
    } 
	else if (olddir == 3) 
	{
      snakey[0] = snakey[0] - 10;
    } 
	else if (olddir == 4)
	{
      snakey[0] = snakey[0] + 10;
    } 
	else
	 {
      keydir = 0;
    }
    break;

  case 1:
    // Snake moves right
    if (olddir != 2) {  // Don't allow the snake to go back to its own body
      snakex[0] = snakex[0] + 10;
      olddir = 1;
    }
    break;
  case 2:
    // Snake moves left
    if (olddir != 1) {  // Don't allow the snake to go back to its own body
      snakex[0] = snakex[0] - 10;
      olddir = 2;
    }
    break;
  case 3:
    // Snake moves up
    if (olddir != 4) {  // Don't allow the snake to go back to its own body
      snakey[0] = snakey[0] - 10;
      olddir = 3;
    }
    break;
  case 4:
    // Snake moves down
    if (olddir != 3) {  // Don't allow the snake to go back to its own body
      snakey[0] = snakey[0] + 10;
      olddir = 4;
    }
    break;
}
				//snake bara horha is loop ma
				//ellipse(snakex[0],snakey[0],7,10,9,9);	
				circle(snakex[0],snakey[0],8);
				setfillstyle(SOLID_FILL,GREEN);
			    floodfill(snakex[0],snakey[0],WHITE);
				setfillstyle(SOLID_FILL, BLACK);
             
			
				for(int i=0;i<snake_length;i++)
				{
					
					
					circle(snakex[i],snakey[i],6);	
					
					setfillstyle(SOLID_FILL,GREEN);
					
					floodfill(snakex[i],snakey[i],WHITE);
				

					
				}
				//body of snake behind face 
				for(int i=199;i>0;i--)
				{
					snakex[i]=snakex[i-1];
					snakey[i]=snakey[i-1];
					
				}
		
			
			delay(delaytime);
			//bumping in boundary
			//left,-,-,necha
			if(snakex[0]>=620||snakex[0]<=19||snakey[0]<=19||snakey[0]>=458){
				
				game=false;
			}
			//bumping apna andr
			for(int i=snake_length-1;i>1;i--)
 			{
				if(snakex[0]==snakex[i] && snakey[0] == snakey[i])
				
   				game = false; 
			}
			if (snakex[0] >= hurdle_x1 && snakex[0] <= hurdle_x1 + hurdle_width1 && snakey[0] >= hurdle_y1 && snakey[0] <= hurdle_y1 + hurdle_height1)
			 {
              game = false;
			}

    // Check for collision with hurdle 2
if (snakex[0] >= hurdle_x2 && snakex[0] <= hurdle_x2 + hurdle_width2 && snakey[0] >= hurdle_y2 && snakey[0] <= hurdle_y2 + hurdle_height2) 
{
        game = false;
}
//if (snakex[0] >= hurdle_x3 && snakex[0] <= hurdle_x3 + hurdle_width3 && snakey[0] >= hurdle_y3 && snakey[0] <= hurdle_y3 + hurdle_height3)
 //{
        //game = false;
 //}
    
 
	}
	 gameover();
}
    


void instructions()
{ 
	  readimagefile("ins.jpg", 0, 0, 640, 480);
  char btm = getch();
   switch (btm) {
    case 'M':
         menu();
        break;
    case 'm':
    menu();
   
  default:
  instructions();
  break;
   }


}
void exit()
{
	readimagefile("exit.jpg",0,0,640,480);

	 char choice = getch();
	switch (choice) {
    case 'Y':
      
	   readimagefile("EX2.jpg",0,0,640,480);
       Sleep(2000);
      closegraph();
       exit(0);
        break;
    case 'y':
      
	   readimagefile("EX2.jpg",0,0,640,480);
       Sleep(2000);
      closegraph();
       exit(0);
	  case 'n':
	  menu();
	  break;
	  case 'N':
	  menu();
   
  default:
 exit();
  break;
	}
	getch();
}
void gameover() {

// Display game over message
readimagefile("GO.jpg",0,0,640,480);


// Display score
char score[10];
settextstyle(BOLD_FONT,0, 7);
sprintf(score, " %d", food-1);
outtextxy(350, 165, score);


int choice = getch();


switch (choice) {
case 'r':
{
	readimagefile("res.jpg",0,0,640,480);
	Sleep(1500);
	 restartGame();
    break;
}
case 'R':
{


   readimagefile("res.jpg",0,0,640,480);
	Sleep(1500);
    restartGame();
    break;
}
case 'e':
{
	 exit2();
	 break;
	
}
case 'E':
{
    
    exit2();
    break;
}
default:
    // Invalid input
    gameover();
}
}

void restartGame() {
// Reset variables and start the game again
food = 0;
delaytime = 30;
snake_length = 0;
foodx=200,foody=200;
keydir=1;
game = true;
snakegame();
}

void exit2() {


// Display exit message
readimagefile("EX2.jpg",0,0,640,480);

// Delay before closing
Sleep(2000);

// Close the program
closegraph();
exit(0);
}
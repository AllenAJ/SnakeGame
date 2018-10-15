/*Developed by:**********************************************************Û
-------------------------------------------------------------------------Û
È Allen Joseph                                                           Û
È Aman Mohan                                                             Û
È Shaum Mampilly                                                         Û
*************************************************************************Û
*/
#include<stdio.h>
#include<iostream.h>
#include<fstream.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define TOP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int opt;                    //menu option variable[integer]
char name[20];              //name variable[string]
static unsigned long sc=0;  //score variable[integer]

void score(int s=1)          //score function
{
    window(70,22,78,23);
    if(s)
    {
	sc=sc+100;
	cprintf("      ");
	window(70,22,78,23);
	cprintf("%ld",sc);
    }
    else
	sc=0;
}

void save()          //file-handling function
{
 ofstream fout;
 fout.open("saving",ios::app);
 if(!fout){cout<<"error";};
fout<<"NAME:"<<name;
fout<<" ";
fout<<"SCORE:"<<sc;
fout<<"\n";
 fout.close();
}

void status(char *s,int c=WHITE)  //player status function
{
    window(70,23,78,25);
    textcolor(c);
    cprintf("%s",s);
    for(int x=strlen(s);x<7;x++)
    cprintf(" ");
    textcolor(WHITE);
}

void main()                          // Main function
{
 clrscr();
 cout<<"Enter your name ?";
 gets(name);
 clrscr();
			 // Menu Screen [ ASCII CODE -  987] "Û";
 cout<<"                ÛÛÛÛÛÛ ÛÛÛÛ    ÛÛ ÛÛÛÛÛÛÛ ÛÛ  ÛÛ ÛÛÛÛÛ \n";
 cout<<"		ÛÛ     ÛÛ ÛÛ   ÛÛ ÛÛ   ÛÛ ÛÛ ÛÛ  ÛÛ    \n";
 cout<<"       	        ÛÛÛÛÛÛ ÛÛ  ÛÛ  ÛÛ ÛÛ   ÛÛ ÛÛÛÛ   ÛÛÛÛÛ \n";
 cout<<"                    ÛÛ ÛÛ   ÛÛ ÛÛ ÛÛÛÛÛÛÛ ÛÛ ÛÛ  ÛÛ    \n";
 cout<<"                ÛÛÛÛÛÛ ÛÛ    ÛÛÛÛ ÛÛ   ÛÛ ÛÛ  ÛÛ ÛÛÛÛÛ \n";
 cout<<"                -------------------------------------- \n";
 cout<<"                Project done by -Allen Joseph \n";
 cout<<"                                -Aman Mohan \n";
 cout<<"                                -Shaun M  \n";
 cout<<"                --------------------------------------  \n";
 cout<<"                ENTER 1 to PLAY   \n";
 cout<<"                ENTER 2 to VIEW LOG   \n";
 cout<<"                ENTER 3 to EXIT \n";

cin>>opt;
if(opt==3){
cout<<"EXIT";}
 if(opt==2){
    clrscr();
  textcolor(RED);
    cprintf("LOGS"); cout<<"\n";
    ifstream fin;
    fin.open("saving",ios::in);
    char ho[30];
    while(fin.getline(ho,20)){
    puts(ho);}
    getch();
   // fin.close;
    }
if(opt==1)
{
    clrscr();
    _setcursortype(_NOCURSOR);           // Function to remove the cursor;
    textcolor(WHITE);                    // Changing text color back to white;
				 //CREATING THE GAMEPLAY Arena;
    cprintf("\n   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ");
    for(int i=0;i<17;i++)
    cprintf("   ³                                                                         ³  ");
    cprintf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ  ");
    cprintf("                              Press 'x' to Exit            ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ ");
    cprintf("                              Press 'p' to Pause and Play  Û SCORE : 0        Û ");
    cprintf("                                                           Û STATUS: Playing  Û ");
    cprintf("                                                           ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ ");
    int snkx[20],snky[20],d=LEFT,p=0,sz=6,restart=1;
    while(1)
    {
	if(restart)             // Setting up the gameplay ;
	{
	    for(i=0;i<6;i++)
	    snkx[i]=30+i*2;
	    for(i=6;i<20;i++)
	    snkx[i]=0;
	    for(i=0;i<20;i++)
	    snky[i]=9;
	    sz=6;
	    p=0;
	    d=LEFT;
	    restart=0;
	    score();
	    window(6,3,76,19);
	    for(i=0;i<610;i++)
	    cprintf("  ");
	}
	int x,y;
	if(p!=1)
	{
	    randomize();               //Randomising the point vector;
	    do{
			x=random(70)+6;
		    }while(x%2==1);
		    y=random(16)+3;
	    p=1;
	    window(x,y,x+1,y+1);
	    textcolor(LIGHTGREEN);
	    cprintf("%c",1);
	    textcolor(WHITE);
	}
	while(!kbhit())                  // Function to refresh the framerate;
	{
	    status("Playing",LIGHTGREEN); // updating status
	    window(snkx[sz-1],snky[sz-1],snkx[sz-1]+2,snky[sz-1]+2);
	    cprintf(" ");
	    for(i=0;i<sz-1;i++)
	    {
		window(snkx[i],snky[i],snkx[i]+1,snky[i]+1);
		cprintf("");   //ASCII CODE -258 "";
	    }
	    for(i=sz-1;i>=1;i--)
	    {
		snkx[i]=snkx[i-1];        //Updating vector[snake] position;
		snky[i]=snky[i-1];
	    }
	    switch(d)                      //Keyboard Interface
	    {
		case RIGHT : snkx[0]+=2; break;
		case LEFT  : snkx[0]-=2; break;
		case TOP   : snky[0]-=1; break;
		case DOWN  : snky[0]+=1;
	    }
	    delay(200);                    //To control the vector speed
	    if(x==snkx[0] && y==snky[0])
	    {
		int f=0;
		do{
		    do{
			x=random(70)+6;
		    }while(x%2==1);
		    y=random(16)+3;
		    for(i=0;i<sz;i++)
			if(snkx[i]==x && snky[i]==y)
			    f=1;
		}while(f);
		p=1;                     //Randomly positioning the point
		window(x,y,x+1,y+1);
		textcolor(LIGHTGREEN);
		cprintf("%c",1);
		textcolor(WHITE);

		score();
		sz++;

		switch(d)                   //Cheking for Vector conflict
		{
		    case RIGHT : snkx[sz-1]+=2;
				 snky[sz-1]=snky[sz-2];
				 break;
		    case LEFT  : snkx[sz-1]-=2;
				 snky[sz-1]=snky[sz-2];
				 break;
		    case TOP   : snky[sz-1]-=1;
				 snkx[sz-1]=snkx[sz-2];
				 break;
		    case DOWN  : snky[sz-1]+=1;
				 snkx[sz-1]=snkx[sz-2];
		}
	    }
	    int sflag=0;
	    for(i=0;i<sz-1;i++)
		if(snkx[sz-1]==snkx[i] && snky[sz-1]==snky[i])
		{
		    sflag=1;
		    break;
		}
	    if(snkx[0]<5 || snkx[0]>76 || snky[0]<3 || snky[0]>19)
		sflag=1;
	    if(sflag)
	    {
		textcolor(LIGHTRED);
		for(i=1;i<sz;i++)
		{
		    window(snkx[i],snky[i],snkx[i]+1,snky[i]+1);
		    cprintf("");
		}
		status("Stoped",LIGHTRED);
		save();
		score(0);
		restart=1;
		break;
	    }
	}
	char ch=getch();              // char variable to get gameplay options
	switch(tolower(ch))
	{
	    case 'x' : return;        // Exiting from the game
	    case 'p' :
			status("Paused"); //Pausing the gameplay
			getch();
			break;
	    case 0 : {
			char chh=getch();
			switch(chh)
			{
			    case 72 :{
				    if(d==LEFT || d== RIGHT)
				    d=TOP;
				    } break;
			    case 80 :{
				    if(d==LEFT || d== RIGHT)
				    d=DOWN;
				    } break;
			    case 75 :{
				    if(d==TOP || d==DOWN)
				    d=LEFT;
				    } break;
			    case 77 :{
				    if(d==TOP || d==DOWN)
				    d=RIGHT;
				    }
			}
		    } break;
		}
	   }
     }

}   // main end
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<bios.h>
#include<fstream.h>
#include<string.h>

class score
{
public:
int Score,sc,t,barvelo,setlevel;
char Name[80];
int dev;
void sldisp();
void scupload();
score()
{
dev=0;
setlevel=1;
barvelo=7;
t=7;
Score=0;
sc=2;
}
}player;

void score::scupload()
{
delay(500);
ofstream S("Score.txt",ios::app);
cout<<"Enter Name:";
gets(Name);
S<<Name<<" Score="<<Score<<" Level="<<setlevel<<endl;
S.close();
}

void score::sldisp()
{
void Text3D(int,int,int,int,int,char*);
setcolor(WHITE);
settextstyle(0,0,3);
char S[128],L[128];
sprintf(S,"Score %d",Score);
sprintf(L,"Level %d",setlevel);
Text3D(150,getmaxy()-20,2,5,14,S);
Text3D(getmaxx()-150,getmaxy()-20,2,5,9,L);
}

class bg
{
public:
int bgx[1000],bgy[1000],bgc[1000];
void bginit();
}bug;

class ball
{
public:
int xvelo,yvelo,x,y;
float radius;
ball()
{
xvelo=1;
yvelo=1;
radius=8;
}
}p;

class levelcreate
{
public:
int A[6][6],xdraw,ydraw,block;
void init();
void drawlevel(int,int);
levelcreate()
{
block=2;
}
}q;

void levelcreate::init()
{
randomize();
for(int i=0;i<6;i++)
for(int j=0;j<6;j++)
for(int k=0;k<10;k++)
A[i][j]=random(block);
}

void levelcreate::drawlevel(int x,int y)
{
int col=0;
ydraw=30;
for(int i=0;i<6;i++)
{
xdraw=110;
for(int j=0;j<6;j++)
{
if(x+p.radius>=xdraw-40 && x-p.radius<=xdraw+40 && p.y-p.radius==ydraw+12 && q.A[i][j]!=0)
{
p.yvelo*=(-1);
q.A[i][j]--;
player.Score+=player.sc;
}
else if(x+p.radius>=xdraw-40 && x-p.radius<=xdraw+40 && p.y+p.radius==ydraw-12 && q.A[i][j]!=0)
{
p.yvelo*=(-1);
q.A[i][j]--;
player.Score+=player.sc;
}
else if(x-p.radius==xdraw+40 && p.y-p.radius<=ydraw+12 && p.y+p.radius>=ydraw-12 && q.A[i][j]!=0)
{
p.xvelo*=(-1);
q.A[i][j]--;
player.Score+=player.sc;
}
else if(x+p.radius==xdraw-40 && p.y-p.radius<=ydraw+12 && p.y+p.radius>=ydraw-12 && q.A[i][j]!=0)
{
p.xvelo*=(-1);
q.A[i][j]--;
player.Score+=player.sc;
}

if(q.A[i][j]==3)
{
col=4;
setcolor(col);
}
else if(q.A[i][j]==2)
{
col=1;
setcolor(col);
}
else if(q.A[i][j]==1)
{
col=15;
setcolor(col);
}
if(q.A[i][j]!=0)
{
setfillstyle(1,col);
rectangle(xdraw-40,ydraw-12,xdraw+40,ydraw+12);
floodfill(xdraw,ydraw,col);
}
xdraw+=84;
}
ydraw+=28;
}
}

void Text3D(int x, int y, int depth, int bgcolor, int fgcolor, char *caption)
{
	int i;
	setcolor(bgcolor);
	for(i=0;i<depth;i++)
		outtextxy(x+i,y+i,caption);
	setcolor(fgcolor);
	outtextxy(x+i,y+i,caption);

}

void highscore()
{
void menu();
int key;
clrscr();
cleardevice();
   fstream F1("SCORE.TXT",ios::in);
   char input[80],*p,C[80][80],test[80][80],*endptr,temp[80];
   int k=0,q=0,t;
   long n[80];
   while(!F1.eof())
   {
   F1.getline(input,80);
   strcpy(test[q++],input);
   p = strtok(input, "=");
   p = strtok(NULL, " ");
   {
   n[k] = strtol(p, &endptr, 10);
   strcpy(C[k++],p);
   }
   }
   for(int i=0;i<k;i++)
   {
   for(int j=0;j<k;j++)
   if(n[i]>n[j])
   {
   strcpy(temp,test[i]);
   strcpy(test[i],test[j]);
   strcpy(test[j],temp);
   t=n[i];
   n[i]=n[j];
   n[j]=t;
   }
   }
   for(i=0;i<k;i++)
   {
   puts(test[i]);
   //cout<<n[i]<<" ";
   }
   F1.close();
int token=0;
while (bioskey(1) == 0);
key = bioskey(0);
if(key==283 && token==0)
{
remove("SCORE.TXT");
token=1;
ofstream temp("SCORE.TXT");
temp.close();
menu();
}
else
menu();
}

void load()
{
 int x=317,y=236;
 int v1=0,v2=0,v3=0,num=0,n=0,key;
 while(1)
 {
  cleardevice();
  //show loaded percent
  gotoxy(40,15);
  cout<<num<<"%";
  settextstyle(0,HORIZ_DIR,3);
  setcolor(WHITE);
  outtextxy(220,60,"Loading..");
  //draw the arcs
  setlinestyle(0,0,3);
  setcolor(GREEN);
  arc(x,y,270+v2,90+v2,40);
  setcolor(7);
  arc(x,y,320-v2,120-v2,70);
  arc(x,y,320-v2,120-v2,72);
  setcolor(CYAN);
  arc(x,y,30+v1,160+v1,92);
  setcolor(BLUE);
  arc(x,y,300-v1,40-v1,111);
  setcolor(RED);
  arc(x,y,300+v3,140+v3,131);
  arc(x,y,300+v3,140+v3,133);

  if(num>=100)	//when loading gets completed
  {
	num+=0;
	delay(500);
	cleardevice();
	setlinestyle(0,0,0);
	void menu();
	menu();
  }
  // assigning increase and decrease values to arc

  v1+=4+rand()%8;
  v2+=6+rand()%8;
  v3+=3+rand()%8;
  randomize();
  num=num+n;
  n=rand()%2;
  delay(30);
  if(kbhit()!=0){
  key = bioskey(0);
  if(key==283)
  {
   setlinestyle(0,0,0);
   void menu();
   menu();
  }
}
}
}

void menu()
{
//score player;
//bg bug;
//ball p;
//levelcreate q;

top:
void bg();
int key,xco,midx=getmaxx()/2,midy=getmaxy()/2,maxx=getmaxx(),maxy=getmaxy();
cleardevice();
bg();
setcolor(RED);
//setfillstyle(1,0);
//gotoxy(40,15);
//setlinestyle(0,0,0);
settextstyle(0,0,5);
settextjustify(LEFT_TEXT,TOP_TEXT);
Text3D(50,60,6,1,4,"ATARI BREAKOUT");
delay(500);
int n=0,position=0;
char opt[][20]={"PLAY GAME","INSTRUCTIONS","HIGHSCORES","EXIT"};

setfillstyle(1,0);
settextjustify(CENTER_TEXT,CENTER_TEXT);

xco=midx;       //earlier it was midx-100
   settextstyle(0,0,3);
   setcolor(0);
   setfillstyle(1,15);
   bar(xco-150,midy+(35*position)-18,xco+150,midy+18+(35*position));
   outtextxy(xco,midy+(35*position),opt[position]);

   settextstyle(0,HORIZ_DIR,2);
   setcolor(15);
   outtextxy(xco,midy+35,"INSTRUCTIONS");
   outtextxy(xco,midy+70,"HIGHSCORES");
   outtextxy(xco,midy+105,"EXIT");

settextstyle(6,HORIZ_DIR,1);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(100,maxy-20,"(Use arrow keys to choose.Press ENTER key to continue)");
settextjustify(CENTER_TEXT,CENTER_TEXT);
   while(n==0)
   {
     while (bioskey(1) == 0);
     key = bioskey(0);

     if(key==18432 && position>=0)
     {
     settextstyle(0,0,2);
     setcolor(15);
     setfillstyle(1,0);
     bar(xco-150,midy+(35*position)-18,xco+150,midy+18+(35*position));
      outtextxy(xco,midy+(35*position),opt[position]);
	if(position==0)
	position=3;
	else
	position--;
     settextstyle(0,0,3);
     setcolor(0);
     setfillstyle(1,15);
     bar(xco-150,midy+(35*position)-18,xco+150,midy+18+(35*position));
     outtextxy(xco,midy+(35*position),opt[position]);
     }

     else if(key==20480 && position<=3)
     {
     settextstyle(0,0,2);
     setcolor(15);
     setfillstyle(1,0);
     bar(xco-150,midy+(35*position)-18,xco+150,midy+18+(35*position));
     outtextxy(xco,midy+(35*position),opt[position]);
	if(position==3)
	position=0;
	else
	position++;
     settextstyle(0,0,3);
     setcolor(0);
     setfillstyle(1,15);
     bar(xco-150,midy+(35*position)-18,xco+150,midy+18+(35*position));
     outtextxy(xco,midy+(35*position),opt[position]);
     }

     else if(key==7181)
     break;
     bg();
   }

  if(position==0)
  {
  void create();
  create();
  }
  else if(position==1)
  {void instructions();
  instructions();}
  else if(position==2)
  {void highscore();
  highscore();
  goto top;
  }
  else if(position==3)
  exit(0);
}
void instructions()
{ int midx=getmaxx()/2,midy=getmaxy()/2;
  cleardevice();
  settextjustify(CENTER_TEXT,CENTER_TEXT);
  settextstyle(0,HORIZ_DIR,6);
  setcolor(11);
  Text3D(midx,50,3,4,7,"INSTRUCTIONS");
  setcolor(MAGENTA);
  //Text3D(midx,120,3,7,5,"_________________________________________________________________");
  line(midx-200,120,midx+200,120);
  settextstyle(3,HORIZ_DIR,1);
  setcolor(11);
  outtextxy(midx,150,"The aim of the game is simple.");
  outtextxy(midx,170,"You have to bounce the ball on the red bar (not the daru one).");
  outtextxy(midx,190,"Level 1 has only white bricks that break in 1 shot.");
  outtextxy(midx,210,"Blue bricks are introduced in level 2 which break in 2 shots.");
  outtextxy(midx,230,"In level 3, the strongest bricks(red)");
  outtextxy(midx,250,"come which need 3 shots to be broken.");
  outtextxy(midx,270,"As the level increases, the speed of the ball too increases.");
  outtextxy(midx,290,"Use your left and right arrow keys to steer the red bar");
  outtextxy(midx,310,"Use 'P' (not your susu) for pausing the game");
  outtextxy(midx,330,"Keep breaking bricks and enter the ATARI BREAKOUT HALL OF FAME!");
  settextstyle(0,HORIZ_DIR,4);
  setcolor(GREEN);
  Text3D(midx,370,3,7,2,"GOOD LUCK!");
  setcolor(WHITE);
  settextstyle(3,HORIZ_DIR,1);
  outtextxy(midx,getmaxy()-20,"(Press any key to continue).");
  getch();
  menu();
 }

void main()
{
clrscr();
int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
errorcode=graphresult();
if(errorcode!=grOk)
{
cout<<"Graphics error:\n"<<grapherrormsg(errorcode);
cout<<"Press any key to halt";
getch();
exit(1);
}
cleardevice();
bug.bginit();
void load();
load();
getch();
closegraph();
}

void bg::bginit()
{
for(int i=0;i<1000;i++)
{
bgx[i]=random(640);
bgy[i]=random(475);
bgc[i]=random(16);
}
}

void bg()
{
randomize();
for(int i=0;i<1000;i++)
putpixel(bug.bgx[i],bug.bgy[i],bug.bgc[i]);
}

void chkwin()
{
int flag=0;
for(int i=0;i<6;i++)
for(int j=0;j<6;j++)
{
if(q.A[i][j]!=0)
{
flag=1;
break;
}
}
if(flag==0)
{
outtextxy(getmaxx()/2,getmaxy()/2,"LEVEL COMPLETE");
delay(1000);
player.setlevel++;
//if(player.setlevel==3)
//{q.block=3;}
//else if(player.setlevel==5)
//{q.block=4;}
if(q.block<4)
q.block++;
if(player.t>1)
player.t--;
void create();
create();
}
}

void create()
{
cleardevice();
q.init();
player.sldisp();
bg();
p.x=getmaxx()/2;
p.y=getmaxy()-85-p.radius;
int xbar=getmaxx()/2,sc=getmaxy()-20,temp,key,bcol=4;
for(;;)
{
if(player.dev==1)
{
xbar=p.x;   //for developers only
}
setcolor(LIGHTCYAN);
line(0,0,0,getmaxy());//Vleft
line(0,0,getmaxx(),0);//HUP
line(getmaxx(),0,getmaxx(),getmaxy());//VRight
line(0,getmaxy()-60,getmaxx(),getmaxy()-60);//HDW
line(0,getmaxy(),getmaxx(),getmaxy());//HDW
if(player.Score!=temp)
{
start:
chkwin();
cleardevice();
bg();
setfillstyle(1,BLACK);
bar(1,getmaxy()-59,getmaxx()-1,getmaxy()-1);
player.sldisp();
}
temp=player.Score;
if(kbhit()!=0){
key = bioskey(0);
if(key==283)
menu();
else if(key==19200 && xbar-31>=0)
xbar-=player.barvelo;
else if(key==19712 && xbar+29<=getmaxx())
xbar+=player.barvelo;
else if(key==6512)
{
setcolor(10);
setfillstyle(1,10);
circle(p.x,p.y,p.radius);
floodfill(p.x, p.y,10);
setcolor(11);
outtextxy(getmaxx()/2,getmaxy()/2,"PAUSED");
break;
}
setfillstyle(0,BLACK);
floodfill(xbar,getmaxy()-75,0);
}
setcolor(bcol);
rectangle(xbar-30,getmaxy()-80,xbar+30,getmaxy()-70);
setfillstyle(1,bcol);
floodfill(xbar,getmaxy()-75,bcol);
if(p.y>=getmaxy()-p.radius-60)
{
if(player.dev==1)
{
p.yvelo*=(-1);   //for developers only
}
else if(player.dev==0)
{
outtextxy(getmaxx()/2,getmaxy()/2,"GAME OVER");
player.scupload();
player.Score=0;
player.setlevel=1;
menu();
}
}
if(p.y<=p.radius)
p.yvelo*=(-1);
if(p.y>=getmaxy()-80-p.radius && p.x>=xbar-30 && p.x<=xbar+30)
p.yvelo*=(-1);
if(p.x>=getmaxx()-p.radius || p.x<=p.radius)
p.xvelo*=(-1);
int mn;
mn=10;
setcolor(mn);
setfillstyle(1,mn);
circle(p.x,p.y,p.radius);
floodfill(p.x, p.y,mn);
delay(player.t);
setfillstyle(0,BLACK);
floodfill(p.x,p.y,0);
p.x=p.x+p.xvelo;
p.y=p.y-p.yvelo;
q.drawlevel(p.x,p.y);
if(player.dev==1)
{
setfillstyle(0,BLACK);
floodfill(xbar,getmaxy()-75,0);
}
}
pause:
key = bioskey(0);
if(key==6512)
goto start;
else
goto pause;
}




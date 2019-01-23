#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>

int i=280,j=280,p=40,q=40,count=0;

void bar()
{
setcolor(1);
rectangle(i,380,i+80,390);
setfillstyle(1,1);
floodfill(i+30,385,1);

setcolor(1);
rectangle(j,20,j+80,30);
setfillstyle(1,1);
floodfill(j+30,25,1);

delay(100);
}

void ball()
{
setcolor(1);
circle(p,q,10);
setfillstyle(1,1);
floodfill(p,q,1);
if(count==0)
{p=p+5;
q=q+5;}
else if(count==1)
{p=p+5;
q=q-5;}
else if(count==2)
{p=p-5;
q=q+5;}
else if(count==3)
{p=p-5;
q=q-5;}
}


void navigate()
{ int ch;
ch=getch();
switch(ch)
{
case 75:
if(i>10);
i=i-40; break;

case 77:
if(i<630)
i=i+40; break;

case 'a':
if(j>10);
j=j-40; break;

case 'd':
if(j<630)
j=j+40; break;

case 27: exit(0);
}
}

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\bgi");
setbkcolor(15);
while(1)
{cleardevice();
ball();
bar();
if(kbhit())
{navigate();
cleardevice();}
if(count==0&&q+10==380&&p>i-10&&p<i+90)
count=1;
else if(count==1&&q-10==30&&p>j-10&&p<j+90)
count=0;
else if(count==1&&p+10==630)
count=3;
else if(count==0&&p+10==630)
count=2;
else if(count==3&&q-10==30&&p>j-10&&p<j+90)
count=2;
else if(count==2&&p-10==0)
count=0;
else if(count==2&&q+10==380&&p>i-10&&p<i+90)
count=3;
else if(count==3&&p-10==0)
count=1;
else if(count==3&&q-10==30&&p>j-10&&p<j+90)
count=2;

if(q+10>390||q-10<20)
{//settextstyle(0,HORI_DIR,1);
outtextxy(320,240,"GAME OVER");
delay(3000);
exit(0);
}
}
}
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

int f=0,p=1;

COORD coord;
void gotoxy(int x,int y)
{ coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
SMALL_RECT rect;
struct item
{char name[30];
 float c,b;
};
struct item1
{ char name1[30];
 float pr,tpr;  int q;};

struct item s;
void add()
 { FILE *fp; int d;
 system("cls");
 printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t | ITEM DESCRIPTION |");
 printf("\n\t\t\t\t\t\t\t\t\t======================");
fp=fopen("myfile.dat","ab");
fflush(stdin);
printf("\n\n\t\tEnter item name = ");
gets(s.name);
printf("\n\t\tEnter quantity of item = ");
scanf("%f",&s.b);
printf("\n\t\tEnter price = ");
scanf("%f",&s.c);
fwrite(&s,sizeof(s),1,fp);
f++;
fclose(fp);
 }


 void bill()
 { struct item s2;
   struct item1 ss[20];
 char fg,cno[15],cname[30];
   FILE *fp,*fp2,*fp3;
   float u,c,sum=0,ds,rec,rec1; int t=0,i,j,f2=0,l,ak;

  printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t | BILLING  DESK |");
    printf("\n\t\t\t\t\t\t\t\t\t===================");

 fflush(stdin);
 printf("\n\n\tEnter customer name = ");
 gets(cname);

 printf("\tEnter customer mobile no. = ");
 gets(cno);
 printf("\n\n\tEnter no. of purchased item = ");
 scanf("%d",&t);

 for(i=0;i<t;i++)
    {
 m: fg=0;
 fp=fopen("myfile.dat","rb");
 fp2=fopen("temp1.dat","wb");
   ds=0;
  fflush(stdin);
printf("\tEnter %d item name = ",i+1);
gets(s2.name);

while(fread(&s,sizeof(s),1,fp)>0)
{if(strcmp(s.name,s2.name)==0)
    { fg=1;
     strcpy(ss[i].name1,s.name);
   n: printf("\n\n\tEnter quantity of %d item = ",i+1);
     scanf("%d",&ss[i].q);
      s2.b=s.b;
      if (s2.b>=ss[i].q&&s2.b>0)
    {
     s2.c=s.c;
     {fwrite(&s2,sizeof(s2),1,fp2);
           }}
     else
     { printf("\n\tS0RRY.....\n\tONLY %.0f ITEM IS AVAILABLE",s.b);
         goto n;
     }

     printf("\tEnter discount(%%) per item = ");
     scanf("%f",&ds);
     printf("\n\n");
     ss[i].pr =(s.c-(ds/100)*s.c);
     ss[i].tpr =(ss[i].pr*ss[i].q);
     continue;

    }
      else
     {fwrite(&s,sizeof(s),1,fp2);}
}
fclose(fp2);
fclose(fp);
switch (fg)
 {case 0:
 {printf("\n\n\t\tITEM NAME NOT FOUND");
  printf("\n");
    goto m;}
 default:
 {
     remove("myfile.dat");
     rename("temp1.dat","myfile.dat");
     f2++; }
     }}
     if(f2==t)
   { gotoxy(70,10);
 printf("=============================================================================================");
 gotoxy(80,12);
 printf("NAME = %s",cname);
 fp3=fopen("rep.dat","rb");
 fread(&rec,sizeof(rec),1,fp3);
 gotoxy(135,12);
 printf(" RECEIPT NO. = %.0f",rec);
 rec1=rec;
 fclose(fp3);
 remove("rep.dat");
 fp3=fopen("rep.dat","wb");
 rec=rec1+1;
 fwrite(&rec,sizeof(rec),1,fp3);
 fclose(fp3);
 gotoxy(80,13);
 printf("MOB NO. = %s",cno);
 gotoxy(70,14);
 printf("_____________________________________________________________________________________________");
 gotoxy(73,16);
 printf("S.NO.");
 gotoxy(82,16);
 printf("ITEM NAME");
 gotoxy(112,16);
 printf("PRICE PER ITEM");
 gotoxy(133,16);
 printf("QUANTITY");
 gotoxy(147,16);
 printf("PRICE");
 gotoxy(70,17);
 printf("_____________________________________________________________________________________________");
 for(j=0;j<t;j++)
{gotoxy(74,19+j);
printf("%d).",j+1);
gotoxy(83,19+j);
printf("%s",ss[j].name1);
gotoxy(115,19+j);
printf("%.2f",ss[j].pr);
gotoxy(135,19+j);
printf("%d",ss[j].q);
gotoxy(148,19+j);
printf("%.2f",ss[j].tpr);

sum=(sum+ss[j].tpr);}
gotoxy(70,19+j);
 printf("_____________________________________________________________________________________________");
 gotoxy(133,21+j);
printf("TOTAL AMOUNT = %.2f",sum);

 gotoxy(70,23+j);
 printf("=============================================================================================");

for(l=10;l<=23+t;l++)
{gotoxy(69,l);
printf("|");
  gotoxy(162,l);
  printf("|");
}
 gotoxy(72,25+j);
 printf("PRESS <1> IF BILL IS PAID OTHERWISE PRESS ANY KEY  ");
 scanf("%d",&ak);
 }
 if(ak==1)
 {
for(i=0;i<t;i++)
{
fp=fopen("myfile.dat","rb");
fp2=fopen("temp1.dat","wb");
while(fread(&s,sizeof(s),1,fp)>0)
{ if(strcmp(ss[i].name1,s.name)==0)
  {
       strcpy(s2.name,s.name);
     s2.b = s.b-ss[i].q;
     s2.c = s.c;
     if(s2.b>0)
     {fwrite(&s2,sizeof(s2),1,fp2);}
      }
      else
       {fwrite(&s,sizeof(s),1,fp2);}
}
fclose(fp);
fclose(fp2);
remove("myfile.dat");
rename("temp1.dat","myfile.dat");
} }

}

 void edit1()
{ struct item s1;
    FILE *fp1,*fp;
 float c,b; int z,f1=0;
 system("cls");
 printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t | ITEM DESCRIPTION |");
 printf("\n\t\t\t\t\t\t\t\t\t======================");
 fp=fopen("myfile.dat","rb");
 fp1=fopen("temp.dat","wb");
 gotoxy(40,15);
 printf("Enter item name which to be edit = ");
 fflush(stdin);
 gets(s1.name);
while(fread(&s,sizeof(s),1,fp)>0)
{if(strcmp(s.name,s1.name)==0)
    { f1=1;
     gotoxy(10,10);
     printf("Press <1> to edit quantity of item");
     gotoxy(10,11);
     printf("Press <2> to edit price of item");
     gotoxy(10,12);
     printf("Press <3> to edit name of item");
     gotoxy(10,13);
     printf("Press <4> to remove this item");
     gotoxy(41,20);
     printf("Enter your choice = ");
     scanf("%d",&z);
   y :if(z==1)
     {
      printf("\n\n\t\t\t\t\tEnter new quantity of item = ");
      scanf("%f",&s1.b);
      s1.c=s.c;
       printf("\n\n\t\t\t\t\tQUANTITY IS SUCCSSFULLY ADDED......");
      {fwrite(&s1,sizeof(s1),1,fp1);
           continue;}

     }
      else if(z==2)
      {
      printf("\n\n\t\t\t\t\tEnter new price of item = ");
      scanf("%f",&s1.c);
      s1.b=s.b;
       printf("\n\n\t\t\t\t\tPRICE IS SUCCESSFULLY ADDED......");
      {fwrite(&s1,sizeof(s1),1,fp1);
           continue;}

      }
      else if(z==3)
      {
       printf("\n\n\t\t\t\t\tEnter new item name = ");
       fflush(stdin);
       gets(s1.name);
       s1.b=s.b;
       s1.c=s.c;
       printf("\n\n\t\t\t\t\tITEM NAME IS SUCCESSFULLY CHANGED......");
       {fwrite(&s1,sizeof(s1),1,fp1);
           continue;}
      }
      else if(z==4)
      {
       printf("\n\n\t\t\t\t\tITEM IS SUCCESSFULLY REMOVED......");
      }

      else
        {
           printf("\n\t\t\t\t\tYOU HAVE ENTERED WRONG CHOICE");
           printf("\n\n\t\t\t\t\tEnter your choice = ");
           scanf("%d",&z);
          goto y;}
    }
     else
     {fwrite(&s,sizeof(s),1,fp1);}
}
fclose(fp1);
  fclose(fp);
 if(f1==0)
 {printf("\n\n\t\t\t\t\tITEM NAME NOT FOUND");
  getch();}
 else
 {   remove("myfile.dat");
     rename("temp.dat","myfile.dat");
 }
}
 void item()
{ int a,d,i; float b,c;
FILE *fp;
 x: system("cls");
 printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t | ITEM DESCRIPTION |");
 printf("\n\t\t\t\t\t\t\t\t\t======================");
 printf("\n\n\tpress <1> to edit the current item");
 printf("\n\tpress <2> to add new item");
 printf("\n\tpress <3> to go to bill desk");
 printf("\n\tpress <4> to exit");
 printf("\n\n\n\n_______________________________________________________________________________________________________________________________________");
 printf("\n|       |\t\t\t\t|\t\t\t\t|                               |                              |");
 printf("\n| S No. |\tITEM NAME      \t\t|\t   ITEM NUMBER   \t|\t    QUANTITIES     \t|\tPRICE                  |");

 printf("\n|_______|_______________________________|_______________________________|_______________________________|______________________________|\n");


 if(fp=fopen("myfile.dat","rb"))
{while(fread(&s,sizeof(s),1,fp)>0)
    {f++;}
    fclose(fp);}


 if(fp=fopen("myfile.dat","rb"))
{ p=1;i=p;
 while(fread(&s,sizeof(s),1,fp)>0)
 {
     gotoxy(3,23+p);
    printf("%d).",i);
     gotoxy(16,23+p);
    printf("%s",s.name);
     gotoxy(52,23+p);
    printf("AN%d",i);
     gotoxy(85,23+p);
    printf("%.0f",s.b);
     gotoxy(110,23+p);
    printf("%.2f",s.c);

    p++,i++;
  }
  fclose(fp);}

{printf("\n\n\t\tEnter your choice :");
scanf("%d",&a);}
if(a==1)
{
  edit1();
  getch();

  goto x;}
 else if (a==2)
   {add();
   printf("\n\n\t\t\t\t\tITEM IS SUCCESSFULL ADDED........");
   getch();
   goto x;}
   else if(a==3)
   {  system("cls");
      bill();
      getch();
      goto x;
   }
   else if(a==4)
   {printf("\n\n\n\t\t\t\t\t\t\t\t\tTHANKING YOU...............\n\n\n\n");
    }
   else
   {
   printf("\n\n\n\t\t\t\t\t\t\tYOU HAVE ENTERED WRONG CHOICE\n\n\n\n\n");
   }
}
void login()
{  char uname[10],pw[10];
     int i;
	 x: system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t | LOGIN PANEL |");
    printf("\n\t\t\t\t\t\t\t\t\t=================");
    gotoxy(41,10);
    printf("USERNAME: ");
     gotoxy(41,12);
    printf("PASSWORD: ");
    gotoxy(50,10);
	scanf("%s",&uname);
	fflush(stdin);
      gotoxy(50,12);
	for(i=0;i<4;i++)
	{
	    pw[i]=getch();
	    pw[i+1]='\0';
	    printf("*");
	}
	if(strcmp(pw,"pass")==0 && strcmp(uname,"user")==0)
	{printf("\n\n\n\n\t\t\t\t\t\t\t\tLOGIN SUCCESSFUL \n\t\t\t\t\t\t\tPress any key to continue......");
	getch();}
	else
	{
		printf("\n\n\n\n\t\t\t\t\t\t\t\t YOU HAVE ENTER WRONG PASSWORD OR USERNAME \n");
		getch();
		goto x;
	}
}
void fullscreen()
{
    coord=GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
    rect.Top=0;
    rect.Left=0;
    rect.Bottom=coord.Y-1;
    rect.Right=coord.X-1;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE,&rect);
}

void main()
{   fullscreen();
	login();
	item();
}



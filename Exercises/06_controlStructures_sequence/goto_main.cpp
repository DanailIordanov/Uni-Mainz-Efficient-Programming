// #include "goto_version"
#define PROGRAMM_NAME      "goto"
#define PROGRAMM_COPYRIGHT "(c) 03.03.2020 v1.0"
#define PROGRAMM_AUTHOR    "Fredie Kern"

#include <stdio.h>    // printf()
#include <stdlib.h>   // exit()
#include <math.h>     // sqrt()
#include <string.h>   // strcmp()

bool debug=true;  //Mit  Kontroll-Ausgaben?

enum cmds {quit=0,moveto=1,lineto=2,closeto=3,finish=4};

/* ----- Ein (schlechter) Parser ----------------------------- */
/* -- In diesem Bereich sind keine Änderungen erforderlich! -- */
char program[]="moveto 11 12 lineto 21 22 finish "
               "moveto  31  32 lineto 41 42 lineto 51 52 closeto 61 62";

char *pprogramm=program;
char *pa=pprogramm;   // "Programmzaehler"


cmds getnexttoken(int i)
{
  char *p=pa;
  cmds ret=quit;
  char str[256];

  while(*p!='\x0' && *p!=' ') p++;
  if (*pa!='\x0')
  {
    sscanf(pa,"%s",str);  // besser memcpy()
    if (strcmp(str,"moveto")==0)
    {
      ret = moveto;
      if (debug) printf("moto\n");
    }
    else if (strcmp(str,"lineto")==0)
    {
      ret = lineto;
      if (debug) printf("lito\n");
    }
    else if (strcmp(str,"closeto")==0)
    {
      ret = closeto;
      if (debug) printf("clto\n");
    }
    else if (strcmp(str,"finish")==0)
    {
      ret = finish;
      if (debug) printf("fin\n");
    }
    else
    {
      if (debug) printf("unknown keyword\n");
      exit(2);
      //goto S30;
    }
    while(*p!='\x0' && *p==' ') p++;
  }
  pa = p;

  return ret;
}

float getnexttoken(float f)
{
  char *p=pa;
  float ret;

  while(*p!='\x0' && *p!=' ') p++;
  if (*pa!='\x0')
  {
    sscanf(pa,"%f",&ret);  // besser atof()
    while(*p!='\x0' && *p==' ') p++;
  }
  pa = p;
  return ret;
}
/* ---Ende ---- Parser ----------------- */

float strecke(float x1,float y1,float x2,float y2)
{
  return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

/* ------Goto - Labyrinth ---------------------------------------------- */
int main(int argc,char *argv[])
{
  int    ival;
  float  fval;
  cmds   cmd;
  int    flag;
  float  x,y,X,Y,X0,Y0;
  float  s;

S1:
  cmd = getnexttoken(ival);
  if (cmd==quit)
    return 0;

  if (cmd==moveto)
  {
    flag = 1;
    goto S0;
S4:
    X  = x;  Y = y;
    X0 = X; Y0 = Y;
    s = 0;
    goto S1;
  }
  if (cmd==lineto)
  {
    flag = 2;
    goto S0;
S5:
    flag = 1;
    goto S11;
S20:
    //if (flag==4) goto S10;
    goto S1;
  }
  if (cmd==closeto)
  {
    flag = 3;
    goto S0;
S6:
    flag = 2;
    goto S11;
S21:
    goto S10;
  }
  if (cmd==finish)
    goto S10;

S10:
  printf("s=%8.3f\n",s);
  X  = 0; Y  = 0;
  X0 = X; Y0 = Y;
  s  = 0;
  goto S1;

S11:
  s += strecke(X,Y,X+x,Y+y);
  X += x; Y += y;
  switch(flag)
  {
    case 1:
      goto S20;
    case 2:
      goto S21;
  }

S0:
  x   = getnexttoken(fval);
  y   = getnexttoken(fval);
  switch(flag)
  {
    case 1:
      goto S4;
    case 2:
      goto S5;
    case 3:
      goto S6;
  }

S30:
  return 1;
}

/* --- Ende ---Goto - Labyrinth ---------------------------------------------- */

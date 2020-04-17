/* TODO: transform the main method in goto_main.cpp into a method free of 'goto'
 * 
 * The whole program is based on the code in the 'goto_main.cpp' file,
 * please refer to it, should there be any inconsistencies!
 */

#include <iostream>

using namespace std;

int ternaryOperator(int a, int b, int c)
{
	int min;

	//Replace the following if/else statements with a ternary operator
	/*if (a < b) {
		if (a < c) {
			min = a;
		}
		else {
			min = c;
		}
	}
	else if (a < c) {
		min = a;
	}
	else if (b < c) {
		min = b;
	}
	else {
		min = c;
	}*/

	min = a < b ? (a < c ? a : c) : (a < c || b < c ? (a < c ? a : b) : c);

	return min;
}

bool debug = true;  //Should there be test outputs?

enum cmds { quit = 0, moveto = 1, lineto = 2, closeto = 3, finish = 4 };

/* -------------------- A (bad) parser ------------------- */
/* ------- In this area no changes should be made! ------- */
char program[] = "moveto 11 12 lineto 21 22 finish "
"moveto  31  32 lineto 41 42 lineto 51 52 closeto 61 62";

char* pprogramm = program;
char* pa = pprogramm;   // "Program counter"


cmds getnexttoken(int i)
{
	char* p = pa;
	cmds ret = quit;
	char str[256];

	while (*p != '\x0' && *p != ' ') p++;
	if (*pa != '\x0')
	{
		sscanf_s(pa, "%s", str);  // better memcpy()
		if (strcmp(str, "moveto") == 0)
		{
			ret = moveto;
			if (debug) printf("moto\n");
		}
		else if (strcmp(str, "lineto") == 0)
		{
			ret = lineto;
			if (debug) printf("lito\n");
		}
		else if (strcmp(str, "closeto") == 0)
		{
			ret = closeto;
			if (debug) printf("clto\n");
		}
		else if (strcmp(str, "finish") == 0)
		{
			ret = finish;
			if (debug) printf("fin\n");
		}
		else
		{
			if (debug) printf("unknown keyword\n");
			exit(2);
		}
		while (*p != '\x0' && *p == ' ') p++;
	}
	pa = p;

	return ret;
}

float getnexttoken(float f)
{
	char* p = pa;
	float ret;

	while (*p != '\x0' && *p != ' ') p++;
	if (*pa != '\x0')
	{
		sscanf_s(pa, "%f", &ret);  // better atof()
		while (*p != '\x0' && *p == ' ') p++;
	}
	pa = p;
	return ret;
}
/* -------------------- End of parser -------------------- */

float strecke(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(int argc, char* argv[])
{
	//but before that the first part of the exercise:
	int a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;

	cout << ternaryOperator(a, b, c);

	//now the main part
	int    ival;
	float  fval;
	cmds   cmd;
	int    flag;
	float  x, y, X, Y, X0, Y0;
	float  s;

	while ((cmd = getnexttoken(ival)) != quit) 
	{
		if (cmd == moveto)
		{
			x = getnexttoken(fval);
			y = getnexttoken(fval);

			X = x;  Y = y;
			X0 = X; Y0 = Y;
			s = 0;
		}
		else if (cmd == lineto)
		{
			x = getnexttoken(fval);
			y = getnexttoken(fval);

			s += strecke(X, Y, X + x, Y + y);
			X += x; Y += y;
		}
		else if (cmd == closeto)
		{
			x = getnexttoken(fval);
			y = getnexttoken(fval);

			s += strecke(X, Y, X + x, Y + y);
			X += x; Y += y;

			printf("s=%8.3f\n", s);
			X = 0; Y = 0;
			X0 = X; Y0 = Y;
			s = 0;
		}
		else if (cmd == finish) {
			printf("s=%8.3f\n", s);
			X = 0; Y = 0;
			X0 = X; Y0 = Y;
			s = 0;
		}
	}
}
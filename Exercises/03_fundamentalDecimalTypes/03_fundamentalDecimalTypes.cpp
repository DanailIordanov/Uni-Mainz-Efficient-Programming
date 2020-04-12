#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double degreeToRadian(double value)
{
	return value * M_PI / 180;
}

int main()
{
	double a, b, n;

	a = 6377397.15508;
	b = 6356078.96290;

	n = (a - b) / (a + b);

	double alpha = ((a + b) / 2) * (1 + pow(n, 2) / 4 + pow(n, 4) / 64);
	double beta = -3 * n / 2 + 9 * pow(n, 3) / 16 - 3 * pow(n, 5) / 32;
	double gamma = 15 * pow(n, 2) / 16 - 15 * pow(n, 4) / 32;
	double delta = -35 * pow(n, 3) / 48 + 105 * pow(n, 5) / 256;
	double epsilon = 315 * pow(n, 4) / 512;
	
	double phiDecimal = 47.119498750;
	double phiRadian = degreeToRadian(phiDecimal);

	double length = alpha * (phiRadian + beta * sin(2 * phiRadian) + gamma * sin(4 * phiRadian) + delta * sin(6 * phiRadian) + epsilon * sin(8 * phiRadian));
	
	cout << "B(phi) = " << std::to_string(length) << " m";

	return EXIT_SUCCESS;
}
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!\n"; // This is a single-line comment

    /*
    This
    is
    a
    multi-line
    comment
    */

    const string myMultiLineString = "This is a \
multi-line \
string \
with a\t<- tabulation \
and a\nnew line";
    
    // definition
    double speedOfLight, pi, conversionFactorDegreeToGon;

    // initialization
    speedOfLight = 2.99792458e8; // meters / second
    pi = 3.1415926535897932385;
    conversionFactorDegreeToGon = 1.1111111111;

    // printing on the console
    cout << myMultiLineString << endl;
    cout << speedOfLight << endl;
    cout << pi << endl;
    cout << conversionFactorDegreeToGon << endl;

    cout << "Decimal: " << 10 << endl; //10
    cout << "Hexadecimal: " << 0xAFFE << endl; // 45054
    cout << "Binary: " << 0b11011 << endl; // 27
    cout << "Octal: " << 04711 << endl; // 2505
    // There is no pre-defined literal for a number with base 4

    char hashtag = 35;
    cout << hashtag; // #

    return EXIT_SUCCESS;
}
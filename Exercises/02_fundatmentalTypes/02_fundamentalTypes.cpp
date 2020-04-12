#include <iostream>

using namespace std;

long long binomialCoefficient(int n, int k) {
	long long nFactorial, kFactorial, nMinusKFactorial;

	nFactorial = 1;

	for (int i = 1; i <= n; i++) {
		nFactorial *= i;
	}

	kFactorial = 1;

	for (int i = 1; i <= k; i++) {
		kFactorial *= i;
	}
	 
	nMinusKFactorial = 1;

	for (int i = 1; i <= n - k; i++) {
		nMinusKFactorial *= i;
	}

	long long result = nFactorial / (nMinusKFactorial * kFactorial);

	return result;
}

int binomialCoefficientRec(int n, int k) {
	return k == 0 || k == n ? 1 : binomialCoefficientRec(n, k - 1) * (n - k + 1) / k;
}

int main() {
	cout << "On your system:" << endl;
	cout << "Char is: " << sizeof(char) << " byte" << endl; // 1 byte on both x32 and x64 target system

	cout << "String is: " << sizeof(string) << " byte" << endl; // 28 byte on x32 and 40 byte on x64 target system
	
	cout << "Short is: " << sizeof(short) << " byte" << endl; // 2 byte on both x32 and x64 target system

	cout << "Int is: " << sizeof(int) << " byte" << endl; // 4 byte on both x32 and x64 target system

	cout << "Long is: " << sizeof(long) << " byte" << endl; // 4 byte on both x32 and x64 target system

	cout << "Long Long is: " << sizeof(long long) << " byte" << endl; //8 byte on both x32 and x64 target system

	cout << "Float is: " << sizeof(float) << " byte" << endl; // 4 byte on both x32 and x64 target system

	cout << "Double is: " << sizeof(double) << " byte " << endl; // 8 byte on both x32 and x64 target system

	int n, k;

	cout << endl << "Recursive: " << endl;
	cout << "Please enter a value for N: ";
	cin >> n;

	cout << "Please enter a value for K: ";
	cin >> k;

	cout << "Binomial Coefficient: " << binomialCoefficientRec(n, k) << endl;

	cout << endl << "Normal: " << endl;
	cout << "Do you want to keep same values (y/n)? ";

	char answer;
	cin >> answer;

	if (answer == 'n') {
		cout << "Please enter a value for N: ";
		cin >> n;

		cout << "Please enter a value for K: ";
		cin >> k;

		cout << "Binomial Coefficient: " << binomialCoefficient(n, k) << endl;
	}
	else if (answer == 'y') {
		cout << "Binomial Coefficient: " << binomialCoefficient(n, k) << endl;
	}
	else {
		cout << "Wrong input...";
	}


}

#include <iostream>

using namespace std;

static int A[100] = { 17,3,9,23,18 };
static int n = sizeof(A) / sizeof(A[0]);
static int ACount = 5;

int find_and_insert(int value)
{
	int i{};

	while (i < n)
	{
		if (i == ACount)
		{
			A[i] = value;
			ACount++;
			break;
		}

		if (A[i] == value) {
			break;
		}

		i++;
	}

	return i;
}

int main()
{
	//first part of the exercise
	cout << find_and_insert(47) << endl;
	cout << find_and_insert(35) << endl;
	cout << find_and_insert(47) << endl;
	cout << find_and_insert(17) << endl;
}

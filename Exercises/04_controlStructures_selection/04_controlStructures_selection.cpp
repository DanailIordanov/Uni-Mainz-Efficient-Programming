#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Please run this program again and enter input parameters in the following format:" << endl;
		cout << "<programName> <inputFileName.dat> -o <outputFileName.dat> -[c|f|k]";

		return EXIT_FAILURE;
	}

	string inputFileName, outputFileName, convertTo;

	inputFileName = argv[1];
	outputFileName = argv[3];
	convertTo = argv[4];

	string line;
	ifstream inputFile(inputFileName);

	ofstream outputFile(outputFileName);

	while (getline(inputFile, line)) 
	{
		istringstream lineAsStream(line);
		vector<string> lineParams((istream_iterator<string>(lineAsStream)), istream_iterator<string>());

		if (lineParams.size() < 2 || lineParams.size() > 3)
		{
			continue;
		}

		string city = lineParams[0];
		string temp = lineParams[1];
		string convertFrom = lineParams.size() == 3 ? lineParams[2] : "C";

		double newTemp{};

		if (convertTo == "-f")
		{
			if (convertFrom == "F")
			{
				newTemp = stod(lineParams[1]);
			}
			else if (convertFrom == "K")
			{
				newTemp = stod(lineParams[1]) * 1.8 - 459.67;
			}
			else if (convertFrom == "C")
			{
				newTemp = stod(lineParams[1]) * 1.8 + 32;
			}

			outputFile << city << " " << newTemp << " " << "F" << endl;
		}
		else if (convertTo == "-k")
		{
			if (convertFrom == "F")
			{
				newTemp = (stod(lineParams[1]) + 459.67) * 5 / 9;
			}
			else if (convertFrom == "K")
			{
				newTemp = stod(lineParams[1]);
			}
			else if (convertFrom == "C")
			{
				newTemp = stod(lineParams[1]) + 273.15;
			}

			outputFile << city << " " << newTemp << " " << "K" << endl;
		}
		else
		{
			if (convertFrom == "F")
			{
				newTemp = (stod(lineParams[1]) - 32) * 5 / 9;
			}
			else if (convertFrom == "K")
			{
				newTemp = stod(lineParams[1]) - 273.15;
			}
			else if (convertFrom == "C")
			{
				newTemp = stod(lineParams[1]);
			}

			outputFile << city << " " << newTemp << " " << "C" << endl;
		}
	}

	outputFile.close();
	return EXIT_SUCCESS;
}
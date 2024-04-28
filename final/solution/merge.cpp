#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

int main()
{
	int lineLength = 10000;
	std::ofstream outfile("merged.txt");
	for(int i = 1; i <= 10; ++i)
	{
		std::string infileS = "final" + std::to_string(i) + ".txt";
		std::ifstream infile(infileS);
		if(!infile.is_open())
		{
			printf("Error opening files!\n");
			return 1;
		}
		std::string line;
		getline(infile, line);
		if(line.length() < lineLength)
		{
			lineLength = line.length();
		}
	}
	printf("Line length: %d", lineLength);
	for(int i = 1; i <= 10; ++i)
	{
		std::string inPosFileS = "final" + std::to_string(i) + ".txt";
		std::string inNegFileS = "negFinal" + std::to_string(i) + ".txt";
		std::ifstream inPosFile(inPosFileS);
		std::ifstream inNegFile(inNegFileS);
		if(!inPosFile.is_open() || !inNegFile.is_open())
		{
			printf("Error opening files!\n");
			return 1;
		}
		std::string lineP;
		std::string lineN;
		while(getline(inPosFile, lineP))
		{
			getline(inNegFile, lineN);
			outfile << "1 " << lineP.substr(0, lineLength) << std::endl;
			outfile << "0 " << lineN.substr(0, lineLength) << std::endl;
		}
		inPosFile.close();
		inNegFile.close();

	}
	outfile.close();
	
	return 0;
}

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

int main()
{
	std::ifstream infile("merged.txt");
	std::ofstream trainFile("train.txt");
	std::ofstream testFile("test.txt");
	if(!infile.is_open())
	{
		printf("error opening files!");
		return 1;
	}
	int lineCount = 0;
	std::string line;
	while(getline(infile, line))
	{
		lineCount++;
	}
	infile.clear();
	infile.seekg(0);
	//int trainCount = (lineCount * 80) / 100;
	//int testCount = (lineCount * 20) / 100;
	int trainCount = 1000;
	int testCount = 800;
	int turnTracker = 0;
	while(getline(infile, line))
	{
		if(turnTracker < 3)
		{
			if(trainCount > 0)
			{
				trainFile << line << std::endl;
				trainCount--;
			}
			turnTracker++;
		}else if(turnTracker >= 3 && turnTracker < 6){
			if(testCount > 0)
			{
				testCount--;
				testFile << line << std::endl;
			}
			turnTracker++;
		}else{
			turnTracker = 0;
		}
	}
	infile.close();
	trainFile.close();
	testFile.close();

	return 0;
}

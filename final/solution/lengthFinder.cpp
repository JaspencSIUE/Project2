#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	bool gtg = false;
	int number = 0;
	if(argc == 3 && std::string(argv[1]) == "-a")
	{
		number = std::atoi(argv[2]);
		if(number != 0 || std::string(argv[2]) == "0")
		{
			gtg = true;
		}else{
			std::cout << "Error: the second argument is not an integer" << std::endl;
		}
	}else{
		std::cout << "Error: please enter -a and a integer" << std::endl;
	}

	if(gtg)
	{
		std::string inSMaker = "output" + std::to_string(number) + ".txt";
		std::string outSMaker = "length" + std::to_string(number) + ".txt";
		std::ifstream infile(inSMaker);
		std::ofstream outfile(outSMaker);
		if(!infile.is_open() || !outfile.is_open())
		{
			printf("Error opening files!");
			return 1;
		}
		std::string line;
		while(getline(infile, line))
		{
			if(line.rfind(">", 0) == 0)
			{
				size_t colonPos = line.find(':');
				size_t dashPos = line.find('-', colonPos);
				if(colonPos != std::string::npos && dashPos != std::string::npos)
				{
					int start = std::stoi(line.substr(colonPos + 1, dashPos - colonPos - 1));
					int end = std::stoi(line.substr(dashPos + 1));
					int length = end - start;

					outfile << length << std::endl;
				}
			}
		}
		infile.close();
		outfile.close();
	}
	return 0;
}

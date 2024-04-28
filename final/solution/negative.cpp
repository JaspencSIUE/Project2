#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

int main(int argc, char* argv[])
{
	
	if(argc == 3 && std::string(argv[1]) == "-a")
	{
		int number = std::atoi(argv[2]);
		std::string inf = std::string(argv[2]);
		if(number != 0 || std::string(argv[2]) == "0")
		{
			std::ifstream infile("output" + inf + ".txt");
			std::ofstream outfile("negative" + std::to_string(number) + ".bed");

			if(!infile.is_open() || !outfile.is_open())
			{
				std::cerr << "Error opening files!" << std::endl;
				return 1;
			}
			int val2;
			int val1;
			std::string line;
			bool first = true;
			while(getline(infile, line))
			{
				if(line.rfind(">", 0) == 0)
				{
					if(first)
					{
						size_t colonPos = line.find(':');
						size_t dashPos = line.find('-');
						if(colonPos != std::string::npos && dashPos != std::string::npos)
						{
							val1 = std::stoi(line.substr(dashPos + 1));
						}
						first = false;

					}else{
						size_t colonPos = line.find(':');
						size_t dashPos = line.find('-', colonPos);
						if(colonPos != std::string::npos && dashPos != std::string::npos)
						{
							val2 = std::stoi(line.substr(colonPos + 1, dashPos - colonPos - 1));
							val1++;
							val2--;
							if(val1 < val2)
							{
								std::string output = "chr1\t" + std::to_string(val1) + "\t" + std::to_string(val2);
								outfile << output << std::endl;
							}
							val1 = std::stoi(line.substr(dashPos + 1));
						}
					}
				}
			}
			infile.close();
			outfile.close();
		}
	}
	return 0;
}


#include <iostream>
#include <vector>
int main()
{
	int pocet = 0;
	for (int j = 0; j < 200; j++) {
		std::string nic;
		std::string ciselka[10];
		std::vector<std::string> patky;
		std::vector<std::string> sestky;
		for (size_t i = 0; i < 11; i++)
		{
			std::cin >> nic;
			if (nic.length() == 2)
			{
				ciselka[1] = nic;
			}
			else if (nic.length() == 3)
			{
				ciselka[7] = nic;
			}
			else if (nic.length() == 4)
			{
				ciselka[4] = nic;
			}
			else if (nic.length() == 7)
			{
				ciselka[8] = nic;
			}

			else if (nic.length() == 5)
			{
				//if ((nic.find(ciselka[1][0]) != std::string::npos) && (nic.find(ciselka[1][1]) != std::string::npos))
					//ciselka[3] = nic; // found
				//else
				patky.push_back(nic); // not found
			}
			else if (nic.length() == 6)
			{
				//if ((nic.find(ciselka[1][0]) != std::string::npos) && (nic.find(ciselka[1][1]) != std::string::npos))
					//ciselka[6] = nic; // found
				//else
				sestky.push_back(nic); // not found
			}
		}
		for (size_t i = 0; i < sestky.size(); i++)
		{
			if ((sestky[i].find(ciselka[1][0]) != std::string::npos) && (sestky[i].find(ciselka[1][1]) != std::string::npos))
				// found
				if ((sestky[i].find(ciselka[4][0]) != std::string::npos) && (sestky[i].find(ciselka[4][1]) != std::string::npos) && (sestky[i].find(ciselka[4][2]) != std::string::npos) && (sestky[i].find(ciselka[4][3]) != std::string::npos))
					ciselka[9] = sestky[i];
				else
				{
					ciselka[0] = sestky[i];
				}
			else ciselka[6] = sestky[i];
		}
		for (size_t i = 0; i < patky.size(); i++)
		{
			if ((patky[i].find(ciselka[1][0]) != std::string::npos) && (patky[i].find(ciselka[1][1]) != std::string::npos))
				ciselka[3] = patky[i]; // found
			else if ((ciselka[6].find(patky[i][0]) != std::string::npos) && (ciselka[6].find(patky[i][1]) != std::string::npos) && (ciselka[6].find(patky[i][3]) != std::string::npos) && (ciselka[6].find(patky[i][4]) != std::string::npos) && (ciselka[6].find(patky[i][2]) != std::string::npos))
				ciselka[5] = patky[i];
			else
			{
				ciselka[2] = patky[i];
			}
		}
		std::string nieco;
		int nasobok = 1000;
		int vysledok = 0;
		int medzisucet = 0;
		for (size_t i = 0; i < 4; i++)
		{
			medzisucet = 0;
			std::cin >> nieco;
			//std::cout << nieco.length();
			for (size_t j = 0; j < 10; j++)
			{
				if (nieco.size() == ciselka[j].size()) {
					int p = 0;

					for (size_t k = 0; k < nieco.size(); k++)
					{
						if (ciselka[j].find(nieco[k]) != std::string::npos)
						{
							p++;
						}
					}
					if (p == nieco.size()) {
						medzisucet = nasobok * j;
					}
				}
			}
			vysledok += medzisucet;
			nasobok = nasobok / 10;
		}
		pocet += vysledok;
	}
	std::cout << pocet;
}
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//std::ifstream input("den6vstup.txt");
//std::ofstream output(".txt");
int main()
{	
	std::string subi = "1subor.txt";
	std::string subo = "2subor.txt";
	std::vector<int>rybicky;
	int pocet_rybiciek = 300;
	for (size_t i = 0; i < 256 ; i++)
	{	
		std::ifstream subori(subi);
		std::ofstream suboro(subo);
		int x;
		int p = 0;
		for (size_t j = 0; j < pocet_rybiciek; j++)
		{
			subori >> x;
			if (x == 0) {
				p++;
				suboro << 6 << std::endl;
			}
			else
			{
				suboro << x - 1 << std::endl;
			}
		}
		pocet_rybiciek += p;
		for (size_t k = 0; k < p; k++)
		{
			suboro << 8 << std::endl;
		}
		subori.close();
		suboro.close();
		std::ofstream s(subi);
		s.close();
		std::swap(subi, subo);
		std::cout << i<<std::endl;
	}
	std::cout << pocet_rybiciek;
	int das;
	std::cin >> das;
}

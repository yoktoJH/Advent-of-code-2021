
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
std::vector<std::tuple<std::string, int, int, int, int, int, int>> kocky ;
int main()
{	
	std::string v;
	int x1, x2, y1, y2, z1, z2;
	for (size_t i = 0; i < 420; i++)
	{
		std::cin >> v;
		std::cin >> x1;
		std::cin >> x2;
		std::cin >> y1;
		std::cin >> y2;
		std::cin >> z1;
		std::cin >> z2;
		kocky.push_back(std::make_tuple(v, x1, x2, y1, y2, z1, z2));
	}
	unsigned long long sucet=0;
	for (int x = -97175; x <=99124 ; x++)
	{
		for (int y = -96016; y <= 98300; y++)
		{
			for (int z = -98635; z < 93039; z++)
			{
				char p = 0;
				for (std::tuple<std::string, int, int, int, int, int, int> bod:kocky)
				{
					if (std::get<1>(bod)<=x< std::get<2>(bod))
					{
						if (std::get<3>(bod) <= y < std::get<4>(bod))
						{
							if (std::get<5>(bod) <= z < std::get<6>(bod))
							{
								if (std::get<0>(bod) == "on") p = 1;
								else
								{
									p = 0;
								}
							}
						}
					}
				}
				sucet += p;
			}
		}
	}
	std::cout << sucet;
}


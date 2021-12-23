
#include <iostream>
#include <vector>
#include <string>
std::vector<std::string>kocky;
int main()
{   
	std::string t;
	std::cin >> t;
	int x1, x2, y1, y2, z1, z2;
	std::cin >> x1; std::cin >> x2; std::cin >> y1; std::cin >> y2; std::cin >> z1; std::cin >> z2;
	
	if (t == "on")
	{

		for (size_t i = x1 +120000; i <= x2 +120000; i++)
		{
			for (size_t j = y1 +120000; j <= y2 +120000; j++)
			{
				for (size_t k = z1 +120000; k <= z2 +120000; k++)
				{
					std::string x;
					x = std::to_string(i) + "-" + std::to_string(j) + "-" + std::to_string(k);
					if (std::find(kocky.begin(), kocky.end(), x) == kocky.end())
					{
						kocky.push_back(x);
					}

				}
			}
		}
	}
	else
	{
		for (size_t i = x1 +120000; i <= x2 +120000; i++)
		{
			for (size_t j = y1 +120000; j <= y2 +120000; j++)
			{
				for (size_t k = z1 +120000; k <= z2 +120000; k++)
				{
					std::string x;
					x = std::to_string(i) + "-" + std::to_string(j) + "-" + std::to_string(k);
					if (std::find(kocky.begin(), kocky.end(), x) == kocky.end())
					{
						kocky.erase(std::remove(kocky.begin(), kocky.end(), x), kocky.end());
					}
				}
			}
		}
	}
    std::cout << kocky.size();
}


#include <iostream>
#include <vector>
int main()
{
	int x = 0;
	std::vector<char>rybicky;
	while (x != 9)
	{
		std::cin >> x;
		if (x != 9)
		{
			rybicky.push_back(x);
		}
	}
	long long hodnoty[6];
	for (size_t i = 1; i < 6; i++)
	{
		std::vector<char>ryba;
		ryba.push_back(i);
		for (long long i = 0; i < 256; i++)
		{
			for (long long k = 0; k < ryba.size(); k++)
			{
				long p = 0;
				if (ryba[k] == 0) {
					ryba[k] = 6;
					p++;
				}
				else
				{
					ryba[k] -= 1;
				}
				for (long long l = 0; l < p; l++)
				{
					ryba.push_back(9);
				}
			}
		}
		hodnoty[i] = ryba.size();
		ryba.clear();
	}
	long long poceryb = 0;
	for (size_t j = 0; j < rybicky.size(); j++)
	{
		poceryb += hodnoty[rybicky[j]];
	}
	std::cout << poceryb;

	int das;
	std::cin >> das;
}
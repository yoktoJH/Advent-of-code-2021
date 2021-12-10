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
	long long poceryb=0;
	for (size_t j = 0; j < rybicky.size(); j++)
	{
		
		std::vector<char>ryba;
		ryba.push_back(rybicky[j]);
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
		poceryb += ryba.size();
		ryba.clear();
	}
	std::cout << poceryb;

	int das;
	std::cin >> das;
}
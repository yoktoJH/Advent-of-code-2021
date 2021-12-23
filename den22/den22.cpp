

#include <iostream>
int kocky[100][100][100];
int main()
{
	for (size_t l = 0; l <20; l++)
	{
		std::string t;
		std::cin >> t;
		int x1, x2, y1, y2, z1, z2;
		std::cin >> x1; std::cin >> x2; std::cin >> y1; std::cin >> y2; std::cin >> z1; std::cin >> z2;
		if (t=="on")
		{
			
			for (size_t i = x1+50; i <= x2+50; i++)
			{
				for (size_t j = y1+50; j <= y2+50; j++)
				{
					for (size_t k = z1+50; k <= z2+50; k++)
					{
						kocky[i][j][k] = 1;
					}
				}
			}
		}
		else
		{
			for (size_t i = x1 + 50; i <= x2 + 50; i++)
			{
				for (size_t j = y1 + 50; j <= y2 + 50; j++)
				{
					for (size_t k = z1 + 50; k <= z2 + 50; k++)
					{
						kocky[i][j][k] = 0;
					}
				}
			}
		}
	}
	int p=0;
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			for (size_t k = 0; k < 100; k++)
			{
				if (true)
				{
					if (kocky[i][j][k]==1)
					{
						p++;
					}
				}
			}
		}
	}
    std::cout << p;
}


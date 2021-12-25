
#include <iostream>
#include <vector>
int main()
{
	std::vector<std::vector<char>> dno;
	for (size_t i = 0; i < 137; i++)
	{
		std::string riadok;
		std::cin >> riadok;
		std::vector<char> r;
		for (char x : riadok)
		{
			r.push_back(x);
		}
		dno.push_back(r);
	}
	
	std::vector<std::vector<char>> dno2;
	int pohyb = 1,krok = 0;
	while (pohyb ==1)
	{
		krok++;
		pohyb = 0;

	
	for (size_t i = 0; i < dno.size(); i++)
	{
		std::vector<char> r2;
		for (size_t j = 0; j < dno[0].size(); j++)
		{
			if (dno[i][j] == '>')
			{
				if (j + 1 != dno[0].size())
				{
					if (dno[i][j + 1] == '.')
					{
						r2.push_back('.'); r2.push_back('>');
						pohyb = 1;
						j++;
					}
					else
					{
						r2.push_back(dno[i][j]);
					}
				}
				else
				{
					if (dno[i][0] == '.')
					{
						r2.push_back('.'); r2[0] = '>';
						j++;
						pohyb = 1;
					}
					else
					{
						r2.push_back(dno[i][j]);
					}
				}
			}
			else
			{
				r2.push_back(dno[i][j]);
			}
		}
		dno2.push_back(r2);
	}
	dno = dno2;
	for (size_t i = 0; i < dno.size(); i++)
	{
		for (size_t j = 0; j < dno[0].size(); j++)
		{
			dno2[i][j] = '.';
		}
	}
	for (size_t i = 0; i < dno.size(); i++)
	{
		for (size_t j = 0; j < dno[0].size(); j++)
		{
			if (dno[i][j] == 'v')
			{
				if (i + 1 != dno.size())
				{
					if (dno[i + 1][j] == '.')
					{
						dno2[i + 1][j] = 'v';
						pohyb = 1;
					}
					else
					{
						dno2[i][j] = dno[i][j];
					}
				}
				else
				{
					if (dno[0][j] == '.')
					{
						dno2[0][j] = 'v';
						pohyb = 1;
					}
					else
					{
						dno2[i][j] = dno[i][j];
					}
				}
			}
			else if (dno[i][j] == '>')
			{
				dno2[i][j] = '>';
			}

		}
	}
	dno = dno2;
	dno2.clear();
	std::cout << "\n";
	/*for (size_t i = 0; i < dno.size(); i++)
	{
		for (size_t j = 0; j < dno[0].size(); j++)
		{
			std::cout<<dno[i][j];
		}
		std::cout << "\n";
	}*/

	}
    std::cout <<krok;
}


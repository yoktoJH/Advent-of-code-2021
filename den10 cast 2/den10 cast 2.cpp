#include <iostream>
#include <vector>
#include <algorithm>
long long vysledok = 0;
int body(char x ) {
	if (x == 40) return 1;
	else if (x == 91) return 2;
	else if (x == 123) return 3;
	else if (x == 60) return 4;
}
int main()
{
	std::vector<long long> hodnoty;
	for (size_t i = 0; i < 98; i++)
	{
		std::vector<char> riadok;
		std::string vstup;
		int j = 0, hodnota = 0, spravnost = 1;
		std::cin >> vstup;

		while (j < vstup.size())
		{
			if (((vstup[j] == 40) || (vstup[j] == 91)) || ((vstup[j] == 123) || (vstup[j] == 60)))
			{
				riadok.emplace(riadok.begin(), vstup[j]);
			}
			else if ((vstup[j] - riadok[0] == 1) || (vstup[j] - riadok[0] == 2))
			{
				riadok.erase(riadok.begin());
			}
			else
			{
				j = vstup.size();
				spravnost = 0;
			}
			j++;
		}
		if (spravnost == 1) {
			long long y = 0;
			for (size_t i = 0; i < riadok.size(); i++)
			{
				y = (y * 5) + body(riadok[i]);
			}
			hodnoty.push_back(y);
		}
		
		riadok.clear();

	}
	std::sort(hodnoty.begin(), hodnoty.end());
	int t;
	t = hodnoty.size() / 2;
	vysledok = hodnoty[t];
	std::cout << vysledok << std::endl;
}




#include <iostream>
#include <vector>
int vysledok =0;
int pocet = 0;
void body(char x) {
	if (x == 41) vysledok += 3;
	else if (x == 93) vysledok += 57;
	else if (x == 125) vysledok += 1197;
	else if (x == 62) vysledok += 25137;
	pocet++;
}
int main()
{
	std::vector<std::string> spravne;
	for (size_t i = 0; i < 98; i++)
	{
		std::vector<char> riadok;
		std::string vstup;
		int j = 0,hodnota =0,spravnost =1;
		std::cin>>vstup;
		
		while (j<vstup.size())
		{	
			if (((vstup[j]==40)||(vstup[j]==91))|| ((vstup[j] == 123) || (vstup[j] == 60)))
			{
				riadok.emplace(riadok.begin(), vstup[j]);
			}
			else if((vstup[j]-riadok[0]==1)|| (vstup[j] - riadok[0] == 2))
			{
				riadok.erase(riadok.begin());
			}
			else
			{
				body(vstup[j]);
				j = vstup.size();
				spravnost = 0;
			}
			j++;
		}
		if (spravnost==1)
		{
			spravne.push_back(vstup);
		}
		riadok.clear();

	}
	
	std::cout << vysledok << std::endl;
	std::cout << pocet << std::endl;
	for (size_t i = 0; i < spravne.size(); i++)
	{
		std::cout << spravne[i] << std::endl;
	}
}


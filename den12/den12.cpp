
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::vector<int>> graf;
std::vector<std::string> hlavicka;
std::vector<int> velke;
int pocet_tras = 0;
std::vector<std::vector<std::string>> zoznam_tras;
void cestovanie(std::vector<int> t, int aktualna_poloha) {
	t.push_back(aktualna_poloha);
	int povol=1;
	for (int bod:t)
	{
		if (std::find(velke.begin(), velke.end(), bod) == velke.end())
		{
			if (std::count(t.begin(), t.end(), bod) == 2) povol = 0;
		}
	}
	for (int a:graf[aktualna_poloha])
	{	
		if (hlavicka[a] != "start") {
			
			if (hlavicka[a]=="end")
			{	
				
				pocet_tras += 1;
				std::vector<std::string> z;
				for (int l : t) { z.push_back(hlavicka[l]); }
				z.push_back(hlavicka[a]);
				zoznam_tras.push_back(z);
			}
			else if (std::find(velke.begin(), velke.end(), a) != velke.end())
			{

				cestovanie(t, a);
			}
			else if (std::count(t.begin(), t.end(), a) ==0)
			{
				cestovanie(t, a);
			}
			
			else if ((std::count(t.begin(), t.end(), a) ==1) && povol == 1)
			{
				cestovanie(t, a);
			}

		}
	}
}

int main()
{	
	int p=24;
	std::vector<int> asd;
	graf.push_back(asd);
    hlavicka.push_back("start");

	for (int i = 0; i < p*2; i++)
	{	
		std::string vstup;
		std::cin >> vstup;
		if (std::find(hlavicka.begin(), hlavicka.end(), vstup) == hlavicka.end())
		{
			hlavicka.push_back(vstup);
			if (vstup[0]<91)
			{
				velke.push_back(hlavicka.size() - 1);
			}
			graf.push_back(asd);
		}


	}
	std::cout << "znovu vstup" << std::endl;
	for (int i = 0; i < p; i++)
	{
		std::string x,y;
		int cx, cy;
		std::cin >> x;
		std::cin >> y;
		for (int k = 0; k < hlavicka.size(); k++)
		{
			if (hlavicka[k] == x) cx = k;
			else if (hlavicka[k] == y) cy = k;
		}
		graf[cx].push_back(cy);
		graf[cy].push_back(cx);

	}
	std::vector<int> trasa;
	cestovanie(trasa,0);
	std::cout << pocet_tras << std::endl;
	int das;
	std::cin >> das;
}

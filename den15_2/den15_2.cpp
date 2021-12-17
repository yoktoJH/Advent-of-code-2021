#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<int> h;
std::vector<std::string> jaskyna;
std::vector<std::vector<std::pair<std::pair<int, int>, int> >> graf[500];
int prejdene[500][500];
int pocitadlo = 250000;
std::vector<long long> dist[500];

// y ide zvislo x ide vodorovne aka prve pisem y potom x
void pridaj_graf(int y, int x) {
	std::vector<std::pair<int, int>> susedia;
	if (x == 0) {
		susedia.push_back(std::make_pair(y, x + 1));
	}
	else if (x == 499)
	{
		susedia.push_back(std::make_pair(y, x - 1));
	}
	else
	{
		susedia.push_back(std::make_pair(y, x + 1));
		susedia.push_back(std::make_pair(y, x - 1));
	}
	if (y == 0) {
		susedia.push_back(std::make_pair(y + 1, x));
	}
	else if (y == 499)
	{
		susedia.push_back(std::make_pair(y - 1, x));
	}
	else
	{
		susedia.push_back(std::make_pair(y + 1, x));
		susedia.push_back(std::make_pair(y - 1, x));
	}
	std::vector<std::pair<std::pair<int, int>, int> > p;
	graf[y].push_back(p);
	for (auto vrchol : susedia)
	{

		graf[y][x].push_back(std::make_pair(vrchol, jaskyna[vrchol.first][vrchol.second] - 48));
	}
}

std::pair<int, int> najdi_najmensie(std::vector<long long> d[500]) {
	long long n = LLONG_MAX;
	int y, x;
	for (size_t i = 0; i < 500; i++)
	{
		for (size_t j = 0; j < 500; j++)
		{
			if ((d[i][j] < n) && (prejdene[i][j] == 0))
			{
				n = d[i][j];
				y = i;
				x = j;
			}
		}
	}
	return std::make_pair(y, x);
}

int main()
{
	std::string riadok;

	for (size_t i = 0; i < 500; i++)
	{
		std::getline(std::cin, riadok);
		jaskyna.push_back(riadok);
	}
	for (size_t i = 0; i < 500; i++)//i == y
	{
		for (size_t j = 0; j < 500; j++)//j == x
		{
			pridaj_graf(i, j);
			prejdene[i][j] = 0;
			if ((j == 0) && (i == 0))
			{
				dist[i].push_back(0);
			}
			else
			{
				dist[i].push_back(LLONG_MAX);
			}
		}
	}
	//djikstra intensifies
	while (pocitadlo > 0)
	{
		std::pair<int, int> najm;
		najm = najdi_najmensie(dist);
		prejdene[najm.first][najm.second] = 1;
		pocitadlo--;
		for (std::pair<std::pair<int, int>, int> node : graf[najm.first][najm.second])
		{
			if (dist[node.first.first][node.first.second] > (dist[najm.first][najm.second] + node.second))
			{
				dist[node.first.first][node.first.second] = (dist[najm.first][najm.second] + node.second);
			}
		}
	}
	std::cout << dist[499][499];


}

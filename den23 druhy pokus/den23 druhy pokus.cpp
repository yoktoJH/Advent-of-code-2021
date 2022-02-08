
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
int mintrasa = LONG_MAX;
std::vector<char> zthaov;

void tah(std::vector<std::vector<char> > jamy, std::vector<char> riadok,int score, std::vector<char> zaznam) {
	if (score < mintrasa)
	{


		if ((jamy[0].size() == 4) && (jamy[1].size() == 4) && (jamy[2].size() == 4) && (jamy[3].size() == 4)) {
			int aspr = 1, bspr = 1, cspr = 1, dspr = 1;
			for (auto x : jamy[0]) {
				if (x != '0')
				{
					aspr = 0;
					break;
				}
			}
			for (auto x : jamy[1]) {
				if (x != '1')
				{
					bspr = 0;
					break;
				}
			}
			for (auto x : jamy[2]) {
				if (x != '2')
				{
					cspr = 0;
					break;
				}
			}
			for (auto x : jamy[3]) {
				if (x != '3')
				{
					dspr = 0;
					break;
				}
			}
			if ((aspr == 1) && (bspr == 1) && (cspr == 1) && (dspr == 1))
			{
				if (score < mintrasa)
				{
					//std::cout << score;
					mintrasa = score;
					zthaov = zaznam;
					//std::cout << mintrasa << "\n";
				}
				return;
			}
		}
		int prebehlo = 0;
		for (size_t i = 0; i < riadok.size(); i++)
		{
			if (riadok[i] != 'e') {

				int volne = 1;
				if (i > 2 * (riadok[i] - 96))
				{
					for (size_t j = 2 * (riadok[i] - 96); j < i; j++)
					{
						if (riadok[j] != 'e')
						{
							volne = 0;
							break;
						}
					}
				}
				else
				{
					for (size_t j = i + 1; j <= 2 * (riadok[i] - 96); j++)
					{
						if (riadok[j] != 'e')
						{
							volne = 0;
							break;
						}
					}
				}


				if (volne == 1)
				{
					int vhodne = 1;
					for (size_t j = 0; j < jamy[(riadok[i] - 97)].size(); j++)
					{
						if (riadok[i] != jamy[(riadok[i] - 97)][j] + 49)
						{
							vhodne = 0;
							break;
						}
					}
					if (vhodne == 1)
					{
						int i2 = i, pohyb = 0;
						long double tahy = i2 - 2 * (riadok[i] - 96);
						pohyb = abs(tahy) + (4 - jamy[(riadok[i] - 97)].size());
						pohyb *= pow(10, riadok[i] - 97);
						std::vector<char> dummy_riadok;
						for (size_t j = 0; j < 11; j++)
						{
							dummy_riadok.push_back(riadok[j]);
						}
						//nahradne jamy 
						std::vector<std::vector<char>> dummy_jamy = { {}, {}, {}, {} };
						for (size_t ii = 0; ii < jamy.size(); ii++)
						{
							for (size_t j = 0; j < jamy[ii].size(); j++)
							{
								dummy_jamy[ii].push_back(jamy[ii][j]);
							}

						}
						dummy_jamy[(riadok[i] - 97)].push_back(riadok[i] - 49);
						dummy_riadok[i] = 'e';
						prebehlo = 1;
						std::vector<char> z = zaznam;
						z.push_back(riadok[i]);
						z.push_back(i + 48);
						z.push_back('j');
						tah(dummy_jamy, dummy_riadok, score + pohyb,z);

					}
				}
			}
		}

		if (prebehlo == 0)
		{


			for (size_t i = 0; i < jamy.size(); i++)
			{
				if (jamy[i].size() != 0)
				{
					if (jamy[i].back() > 96)//tu som skončil :))))))))
					{
						std::vector<int> volne_polia = {};
						for (int j = 2 * (i + 1); j >= 0; j--)
						{
							if (riadok[j] == 'e')
							{
								if (j % 2 != 0)
								{
									volne_polia.push_back(j);
								}
								else if ((j / 2 < 1) || (j / 2 > 4))
								{
									volne_polia.push_back(j);
								}
							}
							else
							{
								break;
							}
						}

						for (size_t j = 2 * (i + 1); j < 11; j++)
						{
							if (riadok[j] == 'e')
							{
								if (j % 2 != 0)
								{
									volne_polia.push_back(j);
								}
								else if ((j / 2 < 1) || (j / 2 > 4))
								{
									volne_polia.push_back(j);
								}
							}
							else
							{
								break;
							}
						}

						for (auto policko : volne_polia)
						{
							int posun = 0;
							int pols = policko - 2 * (i + 1);
							posun = (5 - jamy[i].size()) + (abs(pols));
							posun *= pow(10, jamy[i].back() - 97);
							std::vector<std::vector<char>> dummy_jamy = { {}, {}, {}, {} };
							for (size_t ii = 0; ii < jamy.size(); ii++)
							{
								for (size_t j = 0; j < jamy[ii].size(); j++)
								{
									dummy_jamy[ii].push_back(jamy[ii][j]);
								}

							}
							std::vector<char> dummy_riadok;
							for (size_t j = 0; j < 11; j++)
							{
								dummy_riadok.push_back(riadok[j]);
							}
							int pismenko = dummy_jamy[i].back();
							dummy_riadok[policko] = pismenko;
							dummy_jamy[i].pop_back();
							std::vector<char> z = zaznam;
							z.push_back(jamy[i].back());
							z.push_back(i + 48);
							z.push_back(policko+48);
							tah(dummy_jamy, dummy_riadok, score + posun,z);
						}
					}
				}
			}
		}


	}
}

int main(){
	using namespace std;
	vector<char> jamaa = {'c','d','d','a'}, jamab = {'c','b','c','d'}, jamac = {'d','a','b','a'}, jamad = {'b','c','a','b'}, riadok = {'e','e','e','e','e','e','e','e','e','e','e'};
	vector<vector<char>> jamy = {jamaa,jamab,jamac,jamad};
	tah(jamy, riadok, 0, {});
	cout << mintrasa<<"\n";
	for (size_t i = 0; i < zthaov.size(); i+=3)
	{
		cout << zthaov[i] <<" "<< zthaov[i+1] << " " << zthaov[i + 2] << "\n";
	}
}
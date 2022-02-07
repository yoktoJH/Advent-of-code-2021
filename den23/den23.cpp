

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
int mintrasa = LONG_MAX;
struct Node
{
	char pismenko = 'e';
	int body = 0,pocet_tahov = 0,spravna_jama = 0;
};
Node* newNode( char pp) {
	Node* temp = new Node;
	temp->body = pow(10,pp-97);
	temp->pismenko = pp;

	return temp;
}

bool test(std::vector<Node*> riadok){
	std::vector<char> t = { 'e','e','e','e','e','e','e','e','e','e','d' };
	int tt = 1;
	for (size_t i = 0; i < 11; i++)
	{
		if (riadok[i]->pismenko!=t[i])
		{
			tt = 0;
			break;
		}
	}
	if (tt==1)
	{
		return true;
	}
	return false;
}

std::vector<Node*> newRiadok(std::vector<Node*> rr)
{
	std::vector<Node*> vystup;
	for (size_t i = 0; i < 11; i++)
	{
		vystup.push_back(newNode(rr[i]->pismenko));
	}
	return vystup;
}
std::vector<std::vector<Node*>> newJamy(std::vector<std::vector<Node*>> jj)
{
	std::vector<std::vector<Node*>> vystup = { {}, {}, {}, {} };
	for (size_t i = 0; i < jj.size(); i++)
	{
		for (size_t j = 0; j < jj[i].size(); j++)
		{
			vystup[i].push_back(newNode(jj[i][j]->pismenko));
		}
		
	}
	return vystup;
}
void tah(std::vector<std::vector<Node*>> jamy, std::vector<Node*> r, int score) {
	// všetko je ok check
	int prebehlo2 = 0;
	if ((jamy[0].size()==4)&& (jamy[1].size() == 4)&& (jamy[2].size() == 4)&& (jamy[3].size() == 4))
	{	
		int aspr = 1, bspr = 1, cspr = 1, dspr = 1;
		for (auto x : jamy[0]) {
			if (x->pismenko!='a')
			{
				aspr = 0;
				break;
			}
		}
		for (auto x : jamy[1]) {
			if (x->pismenko != 'b')
			{
				bspr = 0;
				break;
			}
		}
		for (auto x : jamy[2]) {
			if (x->pismenko != 'c')
			{
				cspr = 0;
				break;
			}
		}
		for (auto x : jamy[3]) {
			if (x->pismenko != 'd')
			{
				dspr = 0;
				break;
			}
		}
		if ((aspr==1)&& (bspr == 1)&& (cspr == 1)&& (dspr == 1))
		{
			if (score<mintrasa)
			{
				std::cout << score;
				mintrasa = score;
				
			}
			prebehlo2 = 1;
		}
	}
	int prebehlo = 0;
	if (prebehlo2 == 0)
	{


		for (size_t i = 0; i < r.size(); i++)
		{
			if (r[i]->pismenko != 'e') {

				int volne = 1;
				if (i > r[i]->pismenko - 95)
				{
					for (size_t j = r[i]->pismenko - 95; j < i; j++)
					{
						if (r[j]->pismenko != 'e')
						{
							volne = 0;
							break;
						}
					}
				}
				else
				{
					for (size_t j = i + 1; j < r[i]->pismenko - 95; j++)
					{
						if (r[j]->pismenko != 'e')
						{
							volne = 0;
							break;
						}
					}
				}


				if (volne == 1)
				{
					int vhodne = 1;
					for (size_t j = 0; j < jamy[(r[i]->pismenko - 97)].size(); j++)
					{
						if (r[i]->pismenko != jamy[(r[i]->pismenko - 97)][j]->pismenko)
						{
							vhodne = 0;
							break;
						}
					}
					if (vhodne == 1)
					{
						int ii = i, pohyb;
						long double tahy = ii - (r[i]->pismenko - 97);
						pohyb = abs(tahy) + (4 - jamy[(r[i]->pismenko - 97)].size());
						pohyb *= r[i]->body;
						std::vector<std::vector<Node*>> dummy_jamy = newJamy(jamy);
						std::vector<Node*> dummy_riadok = newRiadok(r);
						dummy_riadok[i]->spravna_jama = 1;
						dummy_jamy[(r[i]->pismenko - 97)].push_back(dummy_riadok[i]);
						dummy_riadok[i] = new Node;
						prebehlo = 1;
						tah(dummy_jamy, dummy_riadok, score + pohyb);

					}
				}
			}
		}
	}
	// riesene jam
	if (prebehlo==0&&prebehlo2==0)
	{


		for (size_t i = 0; i < jamy.size(); i++)
		{
			if (jamy[i].size() != 0)
			{
				if (jamy[i].back()->spravna_jama == 0)
				{
					std::vector<int> volne_polia = {};
					for (int j = 2 * (i + 1); j >= 0; j--)
					{
						if (r[j]->pismenko == 'e')
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
						if (r[j]->pismenko == 'e')
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
						posun *= jamy[i].back()->body;
						std::vector<std::vector<Node*>> dummy_jamy = newJamy(jamy);
						std::vector<Node*> dummy_riadok = newRiadok(r);
						dummy_riadok[policko] = dummy_jamy[i].back();
						dummy_jamy[i].pop_back();
						tah(dummy_jamy, dummy_riadok, score + posun);
					}
				}
			}
		}
	}
}

int main()
{
	using namespace std;
	vector<Node*> jamaa = { newNode('a'),newNode('d'),newNode('d'),newNode('b') }, jamab = { newNode('d'),newNode('b'),newNode('c'),newNode('c') }, jamac{ newNode('c'),newNode('a'),newNode('b'),newNode('b') }, jamad{ newNode('a'),newNode('c'),newNode('a'),newNode('d') }, riadok = { new Node,new Node ,new Node ,new Node ,new Node,new Node,new Node,new Node,new Node,new Node,new Node };
	jamaa[0]->spravna_jama = 1;
	jamac[0]->spravna_jama = 1;
	vector<vector<Node*>> jamy = { jamaa,jamab,jamac,jamad };
    tah(jamy,riadok,0);
	cout << mintrasa;
}

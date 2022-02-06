

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

void tah(std::vector<std::vector<Node*>> jamy, std::vector<Node*> r, int score) {
	// všetko je ok check
	if ((jamy[0].size()==4)&& (jamy[1].size() == 4)&& (jamy[2].size() == 4)&& (jamy[3].size() == 4))
	{	
		int aspr = 1, bspr = 1, cspr = 1, dspr = 1;
		for (auto x : jamy[0]) {
			if (x->pismenko!='a')
			{
				aspr = 0;
			}
		}
		for (auto x : jamy[1]) {
			if (x->pismenko != 'b')
			{
				bspr = 0;
			}
		}
		for (auto x : jamy[2]) {
			if (x->pismenko != 'c')
			{
				cspr = 0;
			}
		}
		for (auto x : jamy[3]) {
			if (x->pismenko != 'd')
			{
				dspr = 0;
			}
		}
		if ((aspr==1)&& (bspr == 1)&& (cspr == 1)&& (dspr == 1))
		{
			if (score<mintrasa)
			{
				std::cout << score;
				mintrasa = score;
			}
		}
	}
	for (size_t i = 0; i < r.size(); i++)
	{
		if (r[i]->pismenko != 'e') {
			if (r[i]->pismenko == 'a') {
				int volne = 1;
				if (i> r[i]->pismenko-95)
				{
					for (size_t j = r[i]->pismenko - 95; j < i; j++)
					{
						if (r[j]->pismenko!='e')
						{
							volne = 0;
							break;
						}
					}
				}
				else
				{
					for (size_t j = i; j < r[i]->pismenko - 95; j++)
					{
						if (r[j]->pismenko != 'e')
						{
							volne = 0;
							break;
						}
					}
				}

				
				if (volne==1)
				{	
					int vhodne = 1;
					for (size_t j = 0; j < jamy[r[i]->pismenko - 97].size(); j++)
					{
						if (r[i]->pismenko!=jamy[r[i]->pismenko - 97][j]->pismenko)
						{
							vhodne = 0;
							break;
						}
					}
					if (vhodne==1)
					{
						long double tahy = i - r[i]->pismenko - 97;
						r[i]->pocet_tahov += abs(tahy) + (4 - jamy[r[i]->pismenko - 97].size());
						r[i]->spravna_jama = 1;
						score += r[i]->pocet_tahov * r[i]->body;
						jamy[r[i]->pismenko - 97].push_back(r[i]);
						r[i] = new Node;
						tah(jamy, r, score);
					}
				}
			}
			else if (r[i]->pismenko == 'b')
			{
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
					for (size_t j = i; j < r[i]->pismenko - 95; j++)
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
					for (size_t j = 0; j < jamy[r[i]->pismenko - 97].size(); j++)
					{
						if (r[i]->pismenko != jamy[r[i]->pismenko - 97][j]->pismenko)
						{
							vhodne = 0;
							break;
						}
					}
					if (vhodne == 1)
					{
						long double tahy = i - r[i]->pismenko - 97;
						r[i]->pocet_tahov += abs(tahy) + (4 - jamy[r[i]->pismenko - 97].size());
						r[i]->spravna_jama = 1;
						score += r[i]->pocet_tahov * r[i]->body;
						jamy[r[i]->pismenko - 97].push_back(r[i]);
						r[i] = new Node;
						tah(jamy, r, score);
					}
				}
			}
			else if (r[i]->pismenko == 'c')
			{
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
					for (size_t j = i; j < r[i]->pismenko - 95; j++)
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
					for (size_t j = 0; j < jamy[r[i]->pismenko - 97].size(); j++)
					{
						if (r[i]->pismenko != jamy[r[i]->pismenko - 97][j]->pismenko)
						{
							vhodne = 0;
							break;
						}
					}
					if (vhodne == 1)
					{
						long double tahy = i - r[i]->pismenko - 97;
						r[i]->pocet_tahov += abs(tahy) + (4 - jamy[r[i]->pismenko - 97].size());
						r[i]->spravna_jama = 1;
						score += r[i]->pocet_tahov * r[i]->body;
						jamy[r[i]->pismenko - 97].push_back(r[i]);
						r[i] = new Node;
						tah(jamy, r, score);
					}
				}
			}
			else
			{
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
				for (size_t j = i; j < r[i]->pismenko - 95; j++)
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
				for (size_t j = 0; j < jamy[r[i]->pismenko - 97].size(); j++)
				{
					if (r[i]->pismenko != jamy[r[i]->pismenko - 97][j]->pismenko)
					{
						vhodne = 0;
						break;
					}
				}
				if (vhodne == 1)
				{
					long double tahy = i - r[i]->pismenko - 97;
					r[i]->pocet_tahov += abs(tahy) + (4 - jamy[r[i]->pismenko - 97].size());
					r[i]->spravna_jama = 1;
					score += r[i]->pocet_tahov * r[i]->body;
					jamy[r[i]->pismenko - 97].push_back(r[i]);
					r[i] = new Node;
					tah(jamy, r, score);
				}
			}
			}
		}
	}

	// riesene jam
	for (size_t i = 0; i < jamy.size(); i++)
	{
		if (jamy[i].back()->spravna_jama==0)
		{
			std::vector<int> volne_polia = {};
			for (size_t j = 2 * (i + 1); j >= 0; j--)
			{
				if (r[j]->pismenko=='e')
				{
					if ((j/2<1)||(j/2>4))
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
					if ((j / 2 < 1) || (j / 2 > 4))
					{
						volne_polia.push_back(j);
					}
				}
				else
				{
					break;
				}
			}

			for (auto policko:volne_polia)
			{

			}
		}
	}
}

int main()
{
	using namespace std;
	vector<Node*> jamaa = { newNode('c'),newNode('d'),newNode('d'),newNode('a') }, jamab = { newNode('c'),newNode('b'),newNode('c'),newNode('d') }, jamac{ newNode('d'),newNode('a'),newNode('b'),newNode('a') }, jamad{ newNode('b'),newNode('c'),newNode('a'),newNode('b') }, riadok = { new Node,new Node ,new Node ,new Node ,new Node,new Node,new Node,new Node,new Node,new Node,new Node };
	vector<vector<Node*>> jamy = { jamaa,jamab,jamac,jamad };
    tah(jamy,riadok,0);
	cout << mintrasa;
}

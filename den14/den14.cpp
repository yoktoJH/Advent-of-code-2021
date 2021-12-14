

#include <iostream>
#include <vector>
#include <algorithm>
//bool zorad(std::vector<long long> vstup1, std::vector<long long> vstup2) { return vstup1[0] > vstup2[0]; }
int main()
{
	std::string a;
	std::cin >> a;
	std::vector<std::string> dvojica;
	std::vector<std::string> vysledok;
	std::string s1,s2;
	std::vector<char> napotom;
	std::vector<std::vector<unsigned long long>> po20dnoch;
	std::vector<unsigned long long> pocty,pocty_final;
	std::vector<char> dna;
	for (unsigned long long i = 0; i < 16; i++)
	{
		std::cin >> s1;
		std::cin >> s2;
		dvojica.push_back(s1);
		vysledok.push_back(s2);
			if (std::find(napotom.begin(), napotom.end(), s2[0]) == napotom.end())
			{
				napotom.push_back(s2[0]);
				pocty.push_back(0);
				pocty_final.push_back(0);
			}
		
		
	}
	std::vector<std::vector<int>> vysledkyc;
	for (int i = 0; i < vysledok.size(); i++)
	{
		std::vector<int> p;
		std::string y;
		y = dvojica[i][0] + vysledok[i];
		for (unsigned long long j = 0; j < dvojica.size(); j++)
		{
			if (dvojica[j] == y)
			{
				p.push_back(j);
			}
		}
		y = vysledok[i] + dvojica[i][1];
		for (unsigned long long j = 0; j < dvojica.size(); j++)
		{
			if (dvojica[j] == y)
			{
				p.push_back(j);
			}
		}
		vysledkyc.push_back(p);
	}


	std::vector<char> dna1;
	for (unsigned long long i = 0; i < a.size() - 1; i++)
	{
		std::string y;
		y = a[i];
		y += a[i + 1];
		for (unsigned long long j = 0; j < dvojica.size(); j++)
		{
			if (dvojica[j] == y)
			{
				dna1.push_back(j);
			}
		}
	}
	std::vector<char> pomocna_dna;
	
	for (int pls =0;pls<dna1.size();pls++ )
	{
		dna.clear();
		dna.push_back(dna1[pls]);
		for (int i = 0; i < 20; i++) {
			//std::cout << i;
			pomocna_dna = dna;
			dna.clear();
			for (int x : pomocna_dna)
			{
				dna.push_back(vysledkyc[x][0]);
				dna.push_back(vysledkyc[x][1]);
			}
			pomocna_dna.clear();
		}
		
	}
	std::vector<char> pomocna_dna20;
	std::vector<char> dna20;
	for (int pls = 0; pls < vysledkyc.size(); pls++)
	{
		dna20.clear();
		dna20.push_back(pls);
		for (int i = 0; i < 20; i++) {
			//std::cout << i;
			pomocna_dna20 = dna;
			dna20.clear();
			for (int x : pomocna_dna20)
			{
				dna20.push_back(vysledkyc[x][0]);
				dna20.push_back(vysledkyc[x][1]);
			}
			pomocna_dna20.clear();
		}
		for (char x : dna20)
		{
			for (int j = 0; j < napotom.size(); j++)
			{
				if (napotom[j] == dvojica[x][0])
				{
					pocty[j]++;
				}
			}

		}
		for (int j = 0; j < napotom.size(); j++)
		{
			if (napotom[j] == dvojica[dna.back()][1])
			{
				pocty[j]++;
			}
		}
		po20dnoch.push_back(pocty);
		for (size_t kk = 0; kk < pocty.size(); kk++)
		{
			pocty[kk] = 0;
		}
	}
	int fdssaafdsa;
	for (long long plsfunguj = 0; plsfunguj < dna.size(); plsfunguj++) {
		for (size_t i = 0; i < pocty_final.size(); i++)
		{
			pocty_final[i] += po20dnoch[dna[plsfunguj]][i];
		}
	}
	unsigned long long mn = 0, mx = 0;
	mx = *max_element(pocty_final.begin(), pocty_final.end());
	mn = *min_element(pocty_final.begin(), pocty_final.end());
	std::cout << mx - mn;
	int das;
	std::cin >> das;
}

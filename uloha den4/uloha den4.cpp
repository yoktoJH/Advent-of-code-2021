#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vyhra(int tabulka[5][5]) { 
	for (int j = 0; j < 5; j++)
	{
		int b = 0;
		for (int k = 0; k < 5; k++)
		{
			if (tabulka[j][k]==-1)
			{
				b++;
			}

		}
		if (b==5)
		{
			return 1;
		}
	}

	for (int j = 0; j < 5; j++)
	{
		int b = 0;
		for (int k = 0; k < 5; k++)
		{
			if (tabulka[k][j] == -1)
			{
				b++;
			}

		}
		if (b == 5)
		{
			return 1;
		}
	}

	return 0;
}

void vypis(int tabulka[5][5],int c) {
	int s = 0;
	for (int j = 0; j < 5; j++)
	{

		for (int k = 0; k < 5; k++)
		{
			if (tabulka[j][k]!=-1)
			{
				s += tabulka[j][k];
			}

		}
	}
	cout << (s*c) <<endl;
}

int main()
{	
	vector<int>obsadene;
    vector<int>cisla;
    int tabulky[100][5][5];
	char odpad;
	int x;
	cin >> x;
	while (x!=-1)
	{
		cisla.push_back(x);
		cin >> x;
	}
	for (size_t i = 0; i < 100; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
			for (int k = 0; k < 5; k++)
			{
				cin >> tabulky[i][j][k];

			}
		}
		//cin >> odpad;
	}


	for (int y : cisla)
	{
		for (size_t i = 0; i < 100; i++)
		{
			for (int j = 0; j < 5; j++)
			{

				for (int k = 0; k < 5; k++)
				{
					if (tabulky[i][j][k]==y)
					{
						tabulky[i][j][k] = -1;


					}
					

				}
			}
			
		}
		for (size_t i = 0; i < 100; i++)
		{
			int v = vyhra(tabulky[i]);
			if (v==1)
			{
				if (find(obsadene.begin(), obsadene.end(), i) != obsadene.end())
				{
					int prazdne=99;
				}
				else
				{
					vypis(tabulky[i], y);
					obsadene.push_back(i);
				}
			}
		}
		
	}
}


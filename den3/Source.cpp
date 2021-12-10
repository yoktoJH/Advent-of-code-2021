#include <iostream>
#include<vector>
using namespace std;

int main() 
{
	string riadok;
	int sas = 1;
	vector<string> b;
	while (sas==1)
	{
		cin >> riadok;
		if (riadok != "end") {
			b.push_back(riadok);
		}
		else { sas = 0; }
	}
	cout << "vysledok" << endl;
	int p;
	char v;
	int x=0;
	for (size_t i = 0; i < 12; i++)
	{
		x = 0;
		vector<string> c;
		for (size_t j = 0; j < b.size(); j++)
		{
			x += b[j][i] - 48;
		}
		if (x<b.size()/2)
		{
			v = '0';
		}
		else
		{
			v = '1';
		}
		for (size_t j = 0; j < b.size(); j++)
		{
			
			if (b[j][i] == v) { c.push_back(b[j]); }
			
		}

		if (c.size() == 1)
		{
			cout << c[0] << endl;
		}
		else
		{
			b = c;
		}
	}
	cin >> p;


}




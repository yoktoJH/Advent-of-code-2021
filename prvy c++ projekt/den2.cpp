
#include <iostream>
using namespace std;
int main()
{
	int vstup=1;
	string smer;
	int dlzka;
	int hlbka = 0;
	int vzdialenost = 0;
	int aim = 0;
	while (vstup==1)
	{
		cin >> smer;
		cin >> dlzka;
		if (smer == "end") {
			vstup = 0;
		}
		else
		{
			if (smer == "forward") {
				vzdialenost = vzdialenost + dlzka;
				hlbka = hlbka + (aim * dlzka);
			}
			else if(smer == "up") {
				//hlbka = hlbka - dlzka;
				aim = aim - dlzka;
			}
			else
			{
				//hlbka = hlbka + dlzka;
				aim = aim + dlzka;
			}
		}
	}
	cout << (hlbka * vzdialenost)<<endl;
}



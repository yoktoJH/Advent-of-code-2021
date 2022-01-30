
#include <iostream>
#include<array>
unsigned long long p1win = 0, p2win = 0;
std::array<int, 10> a = { 1,1,1,1,3,6,7,6,3,1 };
void hra(int poz1, int score1, int poz2, int score2, unsigned long long vesmir,int hrac) {
	for (size_t i = 3; i < 10; i++)
	{
		if (hrac ==1)
		{	
			int poz;
			poz =poz1+ i;
			poz = poz % 10;
			if (poz == 0)
			{
				poz = 10;
			}
			if (poz+score1 >=21)
			{
				p1win += vesmir * a[i];
			}
			else
			{
				hra(poz, score1 + poz, poz2, score2, vesmir * a[i], 2);
			}
			

		}
		else
		{
			int poz;
			poz = poz2 + i;
			poz = poz % 10;
			if (poz == 0)
			{
				poz = 10;
			}
			if (poz + score2 >= 21)
			{
				p2win += vesmir * a[i];
			}
			else
			{
				hra(poz1, score1, poz, score2+poz, vesmir * a[i], 1);
			}
		}

	}
}
int main()
{
	hra(8, 0, 4, 0, 1, 1);
	using namespace std;
	cout << p1win << "\n";
	cout << p2win << endl;
}


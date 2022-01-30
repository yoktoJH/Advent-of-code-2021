

#include <iostream>
#include <vector>
#include <thread>
#include <map>
#include <array>

unsigned long long p1win = 0,p2win = 0;
std::map<int,unsigned long long > hrac1,hrac2;
std::array<int, 10> a = { 1,1,1,1,3,6,7,6,3,1 };
void hody1(int poz, int score,int pocet_tahov, unsigned long long vesmir) {
	if (score>=21)
	{
		hrac1[pocet_tahov] += vesmir;
	}
	else
	{	
		pocet_tahov++;
		for (size_t i = 3; i < 10; i++)
		{
			
			poz += i;
			poz %= 10;
			if (poz==0)
			{
				poz = 10;
			}
			hody1(poz, score + poz, pocet_tahov, vesmir + a[i]);
				
		}
	}
}
void hody2(int poz2, int score2, int pocet_tahov2, unsigned long long vesmir2) {
	if (score2 >= 21)
	{
		hrac2[pocet_tahov2] += vesmir2;
	}
	else
	{
		pocet_tahov2++;
		for (size_t i = 3; i < 10; i++)
		{
			
			poz2 += i;
			poz2 %= 10;
			if (poz2 == 0)
			{
				poz2 = 10;
			}
			hody2(poz2, score2 + poz2, pocet_tahov2, vesmir2 + a[i]);
				
		}
	}
}
int main()
{	
	for (size_t i = 0; i < 20; i++)
	{
		hrac1[i] = 0;
		hrac2[i] = 0;
	}
	//std::thread th1(hody1, 8,0,0,1);
	//std::thread th2(hody2, 4,0,0,1);
	//th1.join();
	//th2.join();
	hody1(4, 0, 0, 1);
	hody2(8, 0, 0, 1);
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (i<=j)
			{
				p1win += hrac2[j]* hrac1[i];
			}
			else
			{
				p2win += hrac2[j] * hrac1[i];
			}
		}
	}
	using namespace std;
	cout << p1win << "\n";
	cout << p2win << endl;
}


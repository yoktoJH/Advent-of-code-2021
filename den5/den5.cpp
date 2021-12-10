

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector< vector<int> > morske_dno;
	for (size_t i = 0; i < 990; i++)
	{
		vector<int> v1;
		for (int j = 0; j < 990; j++)
		{
			v1.push_back(0);
		}
		morske_dno.push_back(v1);
	}
	int koleso = 1; 
	while (koleso==1)
	{
		int x1, x2, y1, y2;
		cin>>x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;
		if (x1==1000)
		{
			koleso = 0;
		}
		else if ((x1==x2 )|| (y1 ==y2))
		{
			
			int zx, kx, zy, ky;
			if (x1>x2)
			{
				zx = x2;
				kx = x1;
			}
			else
			{
				zx = x1;
				kx = x2;
			}
			if (y1 > y2)
			{
				zy = y2;
				ky = y1;
			}
			else
			{
				zy = y1;
				ky = y2;
			}


			for (int i = zy; i <= ky; i++)
			{
				for (int j = zx; j <= kx; j++)
				{
					morske_dno[i][j] += 1;
				}
			}
		}
		else
		{
			int xp, yp,l;
			if (x1 > x2)
			{
				xp = -1;
				l = x1 - x2 + 1;
			}
			else
			{
				xp = 1;
				l = x2 - x1 + 1;
			}
			if (y1 > y2)
			{
				yp = -1;
			}
			else
			{
				yp = 1;
			}
			for (size_t i = 0; i < l; i++)
			{
				morske_dno[y1][x1] += 1;
				x1 += xp;
				y1 += yp;
			}
		}
	}
	int p = 0;
	for (int i = 0; i < 990; i++)
	{
		
		for (int j = 0; j < 990; j++)
		{
			if (morske_dno[i][j] >= 2)p += 1;
		}
		
	}
	cout << p;
}

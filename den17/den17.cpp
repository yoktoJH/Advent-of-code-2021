
#include <iostream>
#include <vector>
#include <algorithm>
int ppp=0;
int vystrel(int yvel, int xvel) {
	int xsur = 0, ysur = 0;
	int my = INT_MIN;
	while (true)
	{
		
		xsur += xvel;
		ysur += yvel;
		if (xvel > 0)xvel--;
		yvel--;
		if (my < ysur)my = ysur;
		if (((70 <= xsur)&&(xsur <= 125)) && ((-159 <= ysur)&&(ysur <= -121)))
		{
			ppp++;
			return my;
			
		}
		else if ((xsur > 125)||(ysur<(-159)))
		{
			return -200;
		}
	}
	
}
int main()
{
	std::vector<int> vv;
	for (int i = -200; i <999; i++)
	{
		for (int j = -100; j < 180; j++)
		{
			int p;
			p = vystrel(i, j);
			if (p != -200)
			{	
				//std::cout << j << "," << i << std::endl;
				vv.push_back(p);
			}
		}
	}
	std::cout << vv.size()<<std::endl;
	int mx;
	mx = *max_element(vv.begin(), vv.end());
	std::cout << mx <<std::endl;
	int das;
	std::cin >> das;
}


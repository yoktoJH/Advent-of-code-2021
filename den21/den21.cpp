
#include <iostream>

int main()
{
    int p1 = 8, p2 = 4,win=1,dice = 0,scorep1 = 0,scorep2 = 0,pocitadlo=0;
	
	while (win == 1)
	{
		int p = 0;
		for (size_t i = 0; i < 3; i++)
		{
			dice += 1;
			if (dice <= 100)
			{
				p += dice;
			}
			else
			{
				dice = 1;
				p += dice;
			}
		}
		pocitadlo += 3;
		p1 = p1 + p;
		if (p1 % 10 == 0)
		{
			scorep1 += 10;
			p1 = 10;
		}
		else
		{
			scorep1 += p1 % 10;
			p1 = p1 % 10;
		}
		//std::cout<<"PLAYER 1: " << scorep1 << std::endl;
		if (scorep1>=1000)
		{
			std::cout << scorep2 * pocitadlo;
			win = 0;
		}
		
		p = 0;
		for (size_t i = 0; i < 3; i++)
		{
			dice += 1;
			if (dice <= 100)
			{
				p += dice;
			}
			else
			{
				dice = 1;
				p += dice;
			}
		}
		pocitadlo += 3;
		p2 = p2 + p;
		if (p2 % 10 == 0)
		{
			scorep2 += 10;
			p2 = 10;
		}
		else
		{
			scorep2 += p2 % 10;
			p2 = p2 % 10;
		}
		//std::cout << "PLAYER 2: " << scorep2 << std::endl;
		if (scorep2 >= 1000)
		{
			std::cout << scorep1 * pocitadlo;
			win = 0;
		}
	}
}




#include <iostream>

unsigned long long p1win = 1, p2win=1; 
void misery(int p1, int score1, int p2, int scorep2, int tah,unsigned long long v) {

		if (tah == 1)
		{
			for (size_t i = 1; i < 4; i++)
			{
				if ((p1 + i) % 10 == 0) {
					if (score1 + 10<100)
					{
						misery(10, score1 + 10, p2, scorep2, 2, v + 1);
					}
					else
					{
						p1win += v + 1;
					}
					
				}
				else
				{
					if (score1 + ((p1 + i) % 10) < 100)
					{
						misery((p1 + i) % 10, score1 + ((p1 + i) % 10), p2, scorep2, 2, v + 1);
					}
					else
					{
						p1win += v + 1;
					}
					
				}
			}
		}
		else
		{
			for (size_t i = 1; i < 4; i++)
			{
				if ((p2 + i) % 10 == 0) {
					if (scorep2 + 10 < 100)
					{
						misery(p1, score1, 10, scorep2 + 10, 1, v + 1);
					}
					else
					{
						p2win += v + 1;
					}
					
				}
				else
				{
					if (scorep2 + ((p2 + i) % 10) < 100)
					{
						misery(p1, score1, (p2 + i) % 10, scorep2 + ((p2 + i) % 10), 1,v+1);
					}
					else
					{
						p2win += v + 1;
					}
					
				}
			}
		}
}
int main()
{
	misery(4, 0, 8, 0, 1,1);
	std::cout << p1win << std::endl;
	std::cout << p2win << std::endl;
}


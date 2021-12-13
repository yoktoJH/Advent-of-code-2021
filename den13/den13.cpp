

#include <iostream>
int papier[895][1311];
int main()
{	int s = 1310,d = 894;
    
	for (size_t i = 0; i < 895; i++)
	{
		for (size_t j = 0; j < 1311; j++)
		{
			papier[i][j] = 0;
		}
	}
	for (size_t i = 0; i < 982; i++)
	{
		int x,y;
		std::cin >> x;
		std::cin >> y;
		papier[y][x] = 1;
	}
	for (size_t k = 0; k < 12; k++)
	{
		char os;
		std::cin >> os;
		int linka;
		if (os == 'x')
		{
			std::cin>>linka;
			
			for (int i = 0; i < d+1; i++)
			{
				int p = s;
				for (int j = 0; j < linka; j++)
				{
					if (papier[i][j+p]==1)
					{	
						papier[i][j+p] = 0;
						papier[i][j] = 1;
					}
					p -= 2;
				}
				
			}
			s /= 2;
			s -= 1;
		}
		else
		{
			std::cin >> linka;
			int p = d;
			for (int i = 0; i < linka; i++)
			{
				for (int j = 0; j < s+1; j++)
				{
					if (papier[i+p][j] == 1)
					{
						papier[i+p][j] = 0;
						papier[i][j] = 1;
					}
				}
				p -= 2;
			}
			d /= 2;
			d -= 1;
		}
		
	}
	
	for (size_t i = 0; i < d+1; i++)
	{
		for (size_t j = 0; j < s; j++)
		{
			if (papier[i][j]==1)
			{
				std::cout << "#";
			}
			else
			{
				std::cout << ".";
			}

		}
		std::cout << std::endl;
	}
	
}

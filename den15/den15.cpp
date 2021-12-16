#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<int> h;
std::vector<std::string> jaskyna;

void pohyb(int x, int y, int s) {
	//std::cout << x << y << z << std::endl;
	s += jaskyna[y][x] - 48;
	if ((x == 99) && (y == 99))
	{
		h.push_back(s);
	}
	else
	{


		if ((x < 99))
		{


			pohyb(x + 1, y, s);


		}
		if ((y < 99))
		{


			pohyb(x, y + 1, s);


		}

	}
}

int main()
{

	std::string riadok;
	for (size_t i = 0; i < 100; i++)
	{

		std::getline(std::cin, riadok);
		jaskyna.push_back(riadok);

		
	}
	int x = 0, y = 0, sucet = 0;
	pohyb(x, y, sucet);

	int mn;
	mn = *min_element(h.begin(), h.end());

	std::cout << mn;
	std::cin >> mn;
}

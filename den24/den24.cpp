

#include <iostream>
#include <vector>
#include <string>
int main()
{
	

	
	for (size_t i = 1; i < 10; i++)
	{
		unsigned long long x = 0, y = 0, z = 447812, w = 0;
		w = i;
		x *= 0;
		x += z;
		x = x % 26;
		z /= 26;
		x += -12;
		x = x == w;
		x = x == 0;
		y *= 0;
		y += 25;
		y *= x;
		y += 1;
		z *= y;
		y *= 0;
		y += w;
		y += 6;
		y *= x;
		z += y;

		std::cout << z << std::endl;
	}

}


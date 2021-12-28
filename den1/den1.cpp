

#include <iostream>
#include <vector>
int main()
{
	std::vector<int> hlbka;
	for (size_t i = 0; i < 2000; i++)
	{
		int x;
		std::cin >> x;
		hlbka.push_back(x);
	}
	//part 1
	int p =0;
	for (int i = 1; i < 2000; i++)
	{
		if (hlbka[i-1]<hlbka[i])
		{
			p++;
		}
	}
    std::cout << "\n" << p<<"\n";
	//part 2
	int h1, h2,p2=0;
	h1 = hlbka[0] + hlbka[1] + hlbka[2];
	for (size_t i = 1; i < 1998; i++)
	{
		h2 = hlbka[i] + hlbka[i + 1] + hlbka[i + 2];
		if (h1<h2)
		{
			p2++;
		}
		h1 = h2;
	}
	std::cout << p2 << "\n";
}




#include <iostream>
#include <vector>
#include <string>
int main()
{
	std::vector<std::vector<std::string>> prikazy;
	for (size_t i = 0; i < 252; i++)
	{
		std::string s;
		std::vector<std::string> x;
		std::cin >> s; x.push_back(s); std::cin >> s; x.push_back(s); std::cin >> s; x.push_back(s);
		prikazy.push_back(x);
	}
	int beh = 1;
	unsigned long long cislo = 99999999999999;
	while (beh==1)
	{
		int xyz[4] = { 0,0,0,0 };
		int cifra = 0;
		std::string c = std::to_string(cislo);
		for (std::vector<std::string> x : prikazy) {
			if (x[0]=="inp")
			{
				xyz[(x[1][0] - 119)] = c[cifra] - 48;
				cifra++;
			}
			else if (x[0] == "add")
			{
				if (((x[2] == "w") || (x[2] == "x")) ||((x[2] == "y")|| (x[2] == "z")))
				{
					xyz[(x[1][0] - 119)] += xyz[(x[2][0] - 119)];
				}
				else
				{
					xyz[(x[1][0] - 119)] += stoi(x[2]);
				}
				
			}
			else if (x[0] == "mul")
			{
				if (((x[2] == "w") || (x[2] == "x")) || ((x[2] == "y") || (x[2] == "z")))
				{
					xyz[(x[1][0] - 119)] *= xyz[(x[2][0] - 119)];
				}
				else
				{
					xyz[(x[1][0] - 119)] *= stoi(x[2]);
				}
			}
			else if (x[0] == "div")
			{
				if (((x[2] == "w") || (x[2] == "x")) || ((x[2] == "y") || (x[2] == "z")))
				{
					xyz[(x[1][0] - 119)] /= xyz[(x[2][0] - 119)];
				}
				else
				{
					xyz[(x[1][0] - 119)] /= stoi(x[2]);
				}
			}
			else if (x[0] == "mod")
			{
				if (((x[2] == "w") || (x[2] == "x")) || ((x[2] == "y") || (x[2] == "z")))
				{
					xyz[(x[1][0] - 119)] = xyz[(x[1][0] - 119)]% xyz[(x[2][0] - 119)];
				}
				else
				{
					xyz[(x[1][0] - 119)] = xyz[(x[1][0] - 119)]%stoi(x[2]);
				}
			}
			else if (x[0] == "eql")
			{
				if (((x[2] == "w") || (x[2] == "x")) || ((x[2] == "y") || (x[2] == "z")))
				{
					xyz[(x[1][0] - 119)] = xyz[(x[1][0] - 119)] == xyz[(x[2][0] - 119)];
				}
				else
				{
					xyz[(x[1][0] - 119)] = xyz[(x[1][0] - 119)] == stoi(x[2]);
				}
			}
			if (xyz[3]==0)
			{
				beh = 0;
				std::cout << cislo;
			}
		}
		
			
			
			
		cislo--;
	}
}


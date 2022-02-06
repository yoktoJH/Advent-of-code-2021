
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

struct Node
{
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0,z1=0,z2=0;
	std::string typ;
};
Node* newNode(int x1, int x2, int y1, int y2, int z1, int z2, std::string typ) {
	Node* temp = new Node;
	temp->x1 = x1;
	temp->x2 = x2;
	temp->y1 = y1;
	temp->y2 = y2;
	temp->z1 = z1;
	temp->z2 = z2;
	temp->typ = typ;
	return temp;
}

int main()
{
	unsigned long long sucet = 0;
	using namespace std;
	std::string t;
	int x1, x2, y1, y2, z1, z2;
	vector<Node*> ulohy, prepocitane;
	for (size_t i = 0; i < 420; i++)
	{
		std::cin >> t;
		std::cin >> x1; std::cin >> x2; std::cin >> y1; std::cin >> y2; std::cin >> z1; std::cin >> z2;
		ulohy.push_back(newNode(x1, x2, y1, y2, z1, z2, t));
	}

	for (auto vstup : ulohy) {
		if (vstup->typ=="on")
		{	
			unsigned long long zapnute = 0;
			vector<Node*> overhang, antioverhang;
			for (auto predosly:prepocitane)
			{
				if ((()())(()()))
				{

				}
			}


		}
		else
		{

		}
	}
	
}


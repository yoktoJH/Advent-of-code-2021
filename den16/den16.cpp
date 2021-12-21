
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string binarne;
int sucet_v = 0;
std::string preklad(std::string v) {
	std::string vy ="";
	for (char x:v)
	{
		if (x=='0')
		{
			vy += "0000";
		}
		else if (x == '1')
		{
			vy += "0001";
		}
		else if (x == '2')
		{
			vy += "0010";
		}
		else if (x == '3')
		{
			vy += "0011";
		}
		else if (x == '4')
		{
			vy += "0100";
		}
		else if (x == '5')
		{
			vy += "0101";
		}
		else if (x == '6')
		{
			vy += "0110";
		}
		else if (x == '7')
		{
			vy += "0111";
		}
		else if (x == '8')
		{
			vy += "1000";
		}
		else if (x == '9')
		{
			vy += "1001";
		}
		else if (x == 'A')
		{
			vy += "1010";
		}
		else if (x == 'B')
		{
			vy += "1011";
		}
		else if (x == 'C')
		{
			vy += "1100";
		}
		else if (x == 'D')
		{
			vy += "1101";
		}
		else if (x == 'E')
		{
			vy += "1110";
		}
		else if (x == 'F')
		{
			vy += "1111";
		}
	
	}
	return vy;
}
int do_dec(std::string c) {
	if (c == "000")
	{
		return 0;
	}
	else if (c == "001")
	{
		return 1;
	}
	else if (c == "010")
	{
		return 2;
	}
	else if (c == "011")
	{
		return 3;
	}
	else if (c == "100")
	{
		return 4;
	}
	else if (c == "101")
	{
		return 5;
	}
	else if (c == "110")
	{
		return 6;
	}
	else if (c == "111")
	{
		return 7;
	}
}


void rozoberanie(std::string paket) {
	if (paket.size()>6)
	{


		std::string verzia, t_ID;
		int poz_np;
		verzia = paket.substr(0, 3);
		sucet_v += do_dec(verzia);
		t_ID = paket.substr(3, 3);
		if (t_ID == "100")
		{
			int i = 6, pokracuj = 1;
			while (pokracuj == 1)
			{
				pokracuj = paket[i] - 48;
				i += 5;
			}
			if (i < paket.size())
			{
				rozoberanie(paket.substr(i));
			}
			else
			{
				std::cout << paket;
			}
		}
		else
		{
			if (paket[6] == '0')
			{
				//int p;
				//p = stoi(paket.substr(7, 15), 0, 2);
				if (paket.size()>22)
				{
					rozoberanie(paket.substr(22));
				}
				else
				{
					std::cout << paket << std::endl;
				}
				
			}
			else
			{ 
				if (paket.size()>17)
				{
					rozoberanie(paket.substr(18));
				}
				else
				{
					std::cout << paket<<std::endl;
				}
			}
		}
	}
}

struct Node
{
	int version = 0, tID = 0, lID = 0, length = 0;
    unsigned long long literal_value = 0;
	std::string data = "";
	std::vector<Node*>child;
};
Node *newNode(){
	Node *temp = new Node;
	return temp;
}
int tvorba_struktury(Node *rodic){
	
	if (rodic->tID==4)
	{
		std::string cislo="";//celkom ironia xd
		int i = 0, pokrac = 1;
		while (pokrac==1)
		{
			pokrac = (rodic->data[i])-48;
			cislo += (rodic->data).substr(i + 1, 4);
			i += 5;

		}
		rodic->literal_value = stoull(cislo, 0, 2);
		return i;
	}
	else if(rodic->lID==1)
	{
		int s_o =0;
		for (size_t i = 0; i < rodic->length; i++)
		{
			int o;
			(rodic->child).push_back(newNode());
			rodic->child[i]->version = stoi((rodic->data).substr(0, 3), 0, 2);
			rodic->child[i]->tID = stoi((rodic->data).substr(3, 3), 0, 2);

			if (rodic->child[i]->tID == 4) {
				rodic->child[i]->data = (rodic->data).substr(6);
				o = tvorba_struktury(rodic->child[i]);
				o += 6;
			}
			else 
			{
				rodic->child[i]->lID = rodic->data[6] - 48;
				if (rodic->child[i]->lID == 1) {
					rodic->child[i]->length = stoi((rodic->data).substr(7, 11), 0, 2);
					rodic->child[i]->data = (rodic->data).substr(18);
					o = tvorba_struktury(rodic->child[i]);
					o += 18;
				}
			
				else
				{
					rodic->child[i]->length = stoi((rodic->data).substr(7, 15), 0, 2);
					rodic->child[i]->data = (rodic->data).substr(22);
					o = tvorba_struktury(rodic->child[i]);
					o += 22;
				}
			}
			rodic->data = (rodic->data).substr(o);
			s_o += o;
		}
		return s_o;
	}
	else
	{
		int s_o=0,i=0,dieta =0;
		while (i<rodic->length)
		{
			int o;
			(rodic->child).push_back(newNode());
			rodic->child[dieta]->version = stoi((rodic->data).substr(0, 3), 0, 2);
			rodic->child[dieta]->tID = stoi((rodic->data).substr(3, 3), 0, 2);

			if (rodic->child[dieta]->tID == 4) {
				rodic->child[dieta]->data = (rodic->data).substr(6);
				o = tvorba_struktury(rodic->child[dieta]);
				o += 6;
			}
			else
			{
				rodic->child[dieta]->lID = rodic->data[6] - 48;
				if (rodic->child[dieta]->lID == 1) {
					rodic->child[dieta]->length = stoi((rodic->data).substr(7, 11), 0, 2);
					rodic->child[dieta]->data = (rodic->data).substr(18);
					o = tvorba_struktury(rodic->child[dieta]);
					o += +18;
				}

				else
				{
					rodic->child[dieta]->length = stoi((rodic->data).substr(7, 15), 0, 2);
					rodic->child[dieta]->data = (rodic->data).substr(22);
					o = tvorba_struktury(rodic->child[dieta]);
					o += 22;
				}
			}
			rodic->data = (rodic->data).substr(o);
			dieta++;
			i += o;
			s_o += o;
		}
		return s_o;
	}
}
unsigned long long vypocet(Node* paket) {
	if (paket->tID==4)
	{
		return paket->literal_value;
	}
	else if (paket->tID==0)
	{
		unsigned long long sum =0;
		for (Node *x:paket->child )
		{
			sum += vypocet(x);
		}
		return sum;
	}
	else if (paket->tID == 1)
	{
		unsigned long long sum = 1;
		for (Node* x : paket->child)
		{
			sum *= vypocet(x);
		}
		return sum;
	}
	else if (paket->tID == 2)
	{
		std::vector<unsigned long long> sum;
		for (Node* x : paket->child)
		{
			sum.push_back(vypocet(x));
		}
		unsigned long long mn = 0;
		mn = *min_element(sum.begin(), sum.end());
		return mn;
	}
	else if (paket->tID == 3)
	{
		std::vector<unsigned long long> sum;
		for (Node* x : paket->child)
		{
			sum.push_back(vypocet(x));
		}
		unsigned long long mx = 0;
		mx = *max_element(sum.begin(), sum.end());
		return mx;
	}
	else if (paket->tID == 5)
	{
		unsigned long long v1 = vypocet(paket->child[0]), v2 = vypocet(paket->child[1]);
		if (v1>v2)
		{
			return 1;
		}
		return 0;
	}
	else if (paket->tID == 6)
	{
		unsigned long long v1 = vypocet(paket->child[0]), v2 = vypocet(paket->child[1]);
		if (v1 < v2)
		{
			return 1;
		}
		return 0;
	}
	else if (paket->tID == 7)
	{
		unsigned long long v1 = vypocet(paket->child[0]), v2 = vypocet(paket->child[1]);
		if (v1 == v2)
		{
			return 1;
		}
		return 0;
	}

}
int main()
{

	std::string vstup;
	std::cin >> vstup;
	binarne = preklad(vstup);
	//std::cout << binarne;
	Node* root = newNode();
	root->version = stoi(binarne.substr(0, 3), 0, 2);
	root->tID = stoi(binarne.substr(3, 3), 0, 2);
	root->lID = binarne[6] - 48;
	if (root->lID==1)
	{
		root->length = stoi(binarne.substr(7, 11), 0, 2);
		root->data = binarne.substr(18);
	}
	else
	{
		root->length = stoi(binarne.substr(7, 15), 0, 2);
		root->data = binarne.substr(22);
	}
	tvorba_struktury(root);
	unsigned long long pipip = vypocet(root);
	std::cout << pipip;
	//rozoberanie(binarne);
	//std::cout << sucet_v;
}
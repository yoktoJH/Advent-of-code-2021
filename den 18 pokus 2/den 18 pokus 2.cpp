#include <iostream>
#include <string>
#include <vector>
std::vector<char> znaky;
std::vector<int> cisla;
std::vector<int> polohy_ciarok;
void scitanie() {
    std::string scitanec;
    std::cin >> scitanec;
    polohy_ciarok.push_back(znaky.size());
    znaky.emplace(znaky.begin(),'[');
    znaky.push_back(',');
    for (size_t i = 0; i < polohy_ciarok.size(); i++)
    {
        polohy_ciarok[i] += 1;
    }
    for (char x : scitanec) {
        if ((x == 93) || (x == 91))
        {
            znaky.push_back(x);
        }
        else if ((x == 44))
        {
            polohy_ciarok.push_back(znaky.size());
            znaky.push_back(x);
        }
        else
        {
            cisla.push_back(x - 48);
        }
    }
    znaky.push_back(']');
}
int explooosion() {
    int vnorenia =0,ciarky =0;
    for (size_t i = 0; i < znaky.size(); i++)
    {
        if (znaky[i]==91)
        {
            vnorenia++;
        }
        else if (znaky[i]==93)
        {
            vnorenia--;
        }
        else
        {
            ciarky++;
        }
        if (vnorenia >=5)
        {
            if ((znaky[i]==44)&&((znaky[i-1]==91)&&(znaky[i+1]==93)))
            {
                int prvecislo = cisla[ciarky - 1], druhecislo = cisla[ciarky];
                if (ciarky-1!=0)
                {
                    cisla[ciarky - 2] += prvecislo;
                }
                if (ciarky+1!=cisla.size())
                {
                    cisla[ciarky + 1] += druhecislo;
                }
                cisla.erase(cisla.begin() + ciarky - 1);
                cisla[ciarky - 1] = 0;
                for (size_t j = ciarky; j < polohy_ciarok.size(); j++)
                {
                    polohy_ciarok[j] -= 3;
                }
                polohy_ciarok.erase(polohy_ciarok.begin() + ciarky - 1);
                znaky.erase(znaky.begin() + i - 1, znaky.begin() + i + 2);
                return 1;
            }
        }
    }
    return 0;
}
int split() {
    for (size_t i = 0; i < cisla.size(); i++)
    {
        if (cisla[i]>9)
        {
            int poz;
            if (i+1!=cisla.size())
            {
                poz = polohy_ciarok[i];
                if (znaky[poz-1]=='[')
                {
                    //pridanie znakov
                    znaky.emplace(znaky.begin() + poz, ']');
                    znaky.emplace(znaky.begin() + poz, ',');
                    znaky.emplace(znaky.begin() + poz, '[');
                    //uprava cisel
                    cisla.emplace(cisla.begin() + i, (cisla[i] / 2));
                    int p = (cisla[i + 1] / 2) + (cisla[i + 1] % 2);
                    cisla[i + 1] = p;
                    //polohy ciarok
                    for (size_t j = i; j < polohy_ciarok.size(); j++)
                    {
                        polohy_ciarok[j] += 3;
                    }
                    polohy_ciarok.emplace(polohy_ciarok.begin()+i, poz + 1);
                }
                else
                {
                    poz = polohy_ciarok[i - 1];
                    //pridanie znakov
                    znaky.emplace(znaky.begin() + poz+1, ']');
                    znaky.emplace(znaky.begin() + poz+1, ',');
                    znaky.emplace(znaky.begin() + poz+1, '[');
                    //uprava cisel
                    cisla.emplace(cisla.begin() + i, (cisla[i] / 2));
                    int p = (cisla[i + 1] / 2) + (cisla[i + 1] % 2);
                    cisla[i + 1] = p;
                    //polohy ciarok
                    for (size_t j = i; j < polohy_ciarok.size(); j++)
                    {
                        polohy_ciarok[j] += 3;
                    }
                    polohy_ciarok.emplace(polohy_ciarok.begin()+i, poz + 2);
                }
            }
            else
            {
                poz = polohy_ciarok[i - 1];
                //pridanie znakov
                znaky.emplace(znaky.begin() + poz + 1, ']');
                znaky.emplace(znaky.begin() + poz + 1, ',');
                znaky.emplace(znaky.begin() + poz + 1, '[');
                //uprava cisel
                cisla.emplace(cisla.begin() + i, (cisla[i] / 2));
                int p = (cisla[i + 1] / 2) + (cisla[i + 1] % 2);
                cisla[i + 1] = p;
                //polohy ciarok
                for (size_t j = i; j < polohy_ciarok.size(); j++)
                {
                    polohy_ciarok[j] += 3;
                }
                polohy_ciarok.emplace(polohy_ciarok.begin() + i, poz + 2);
            }
            return 1;
        }

    }
    return 0;
}
int main()
{
    std::string riadok;
    std::cin >> riadok;
    for (char x : riadok) {
        if ((x==93)|| (x == 91))
        {
            znaky.push_back(x);
        }
        else if ((x == 44))
        {
            polohy_ciarok.push_back(znaky.size());
            znaky.push_back(x);
        }
        else
        {
            cisla.push_back(x - 48);
        }
    }
    //odtialto
    
    //vypocxet hodnoty
    while (cisla.size()!=1)
    {
        for (int i = 0; i+1 < polohy_ciarok.size(); i++)
        {
            if (znaky[polohy_ciarok[i]-1]!= znaky[polohy_ciarok[i] + 1])
            {
                int prvecislo = cisla[i], druhecislo = cisla[i + 1];
                cisla.erase(cisla.begin() + i);
                cisla[i] = 3 * prvecislo + 2 * druhecislo;
                znaky.erase(znaky.begin() + polohy_ciarok[i] - 1, znaky.begin() + polohy_ciarok[i] + 2);
                for (size_t j = i; j < polohy_ciarok.size(); j++)
                {
                    polohy_ciarok[j] -= 3;
                }
                polohy_ciarok.erase(polohy_ciarok.begin() + i);
            }
        }
    }
    std::cout << cisla[0];
}
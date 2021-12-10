

#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
std::vector<std::string> vstup;
std::string x;
std::vector<int> vysledok;
int medzisucet;
int kontrola[100][100];
void jamy(int i, int j) {
    medzisucet += 1;
    kontrola[i][j] = 1;
    int overenie[] = { 0,0,0,0 };
    if (i == 0)
    {
        overenie[0] = 1;
        overenie[1] = 1;
    }
    else if (i == 99)
    {
        overenie[0] = -1;
        overenie[1] = -1;

    }
    else
    {
        overenie[0] = -1;
        overenie[1] = 1;
    }
    if (j == 0)
    {
        overenie[2] = 1;
        overenie[3] = 1;
    }
    else if (j == 99)
    {
        overenie[2] = -1;
        overenie[3] = -1;

    }
    else
    {
        overenie[2] = -1;
        overenie[3] = 1;
    }

    for (size_t k = 0; k < 2; k++)
    {
        if (vstup[i + overenie[k]][j] != '9') {
            if ((kontrola[i + overenie[k]][j] == 0))
            {
                jamy(i + overenie[k], j);
            }


        }
    }
    for (size_t k = 2; k < 4; k++)
    {
        if (vstup[i][j + overenie[k]] != '9') {
            if (kontrola[i][j + overenie[k]] == 0)
            {
                jamy(i, j + overenie[k]);
            }


        }
    }
}
int main()
{
    int vyska = 100,sirka = 100;
    
    for (size_t i = 0; i < vyska; i++)
    {
        std::cin >> x;
        vstup.push_back(x);
    }
    
    for (size_t i = 0; i < vyska; i++)
    {
        for (size_t j = 0; j < sirka; j++)
        { 
            medzisucet = 0;
            if (kontrola[i][j] == 0 || (vstup[i][j] != '9')) jamy(i, j);
            vysledok.push_back(medzisucet);
        }


    }
    std::sort(vysledok.begin(), vysledok.end(), std::greater<int>());
    int m=1;
    for (size_t i = 0; i < 3; i++)
    {
        m = m * (vysledok[i]-1);
    }
    std::cout << m;
}
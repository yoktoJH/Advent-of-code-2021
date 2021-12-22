
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::string> obrazok;
std::vector<std::string> obrazok2;
int main()
{   
    int pocet_opakovani = 1000;
    std::string vzor = "#####.##....##....##.#.....##....##..########.#.##.#.#.##.#..##.#.####.######.#####.######.##..#######.#.#...#..#.####..####...#.####..#......#...#...##.#.....#....#..###.#..##....#.#....#...##.###.#.#..##.......####.........#.#.###.#.#.....#..##..##.#.##..###.##.###.#....#.#..##.#.......###..#.#.#.#.#.....#..#.###.##..##...#....##...##.##...##.#..####.#...#.####...####..#####.#####.#.##...#.###.#######.###..#..##.#.#..#.#.#######.#####.#.##.#.#...##.######.#...##.##.#.........##...##.....#.###.#.##.#.####.";
    std::string vypln = "",pad = "";
    for (size_t i = 0; i < 102+(pocet_opakovani*2); i++)
    {
        vypln += ".";
    }
    for (size_t i = 0; i < pocet_opakovani+1; i++)
    {
        pad += ".";
    }
    for (size_t i = 0; i < pocet_opakovani + 1; i++)
    {
        obrazok.push_back(vypln);
    }
    
    std::string vstup;
    for (size_t i = 0; i < 100; i++)
    {
        std::cin >> vstup;
        vstup =pad + vstup + pad;
        obrazok.push_back(vstup);
    }
    for (size_t i = 0; i < pocet_opakovani + 1; i++)
    {
        obrazok.push_back(vypln);
    }
    char c;
    for (size_t o = 0; o < pocet_opakovani; o++)
    {
        if (o%2==0)
        {
            c = '#';
        }
        else
        {
            c = '.';
        }
        for (size_t i = 0; i < 102 + (pocet_opakovani * 2); i++)
        {
            std::string riadok = "";
            for (size_t j = 0; j < 102 + (pocet_opakovani * 2); j++)
            {
                std::string bod;
                if (((i == 0) || (i == 101 + (pocet_opakovani * 2))) || ((j == 0) || (j == 101 + (pocet_opakovani * 2)))) {
                    riadok += c;
                }
                else
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        for (int k = -1; k <= 1; k++)
                        {
                            if (obrazok[i + l][j + k] == '#')
                            {
                                bod += "1";
                            }
                            else
                            {
                                bod += "0";
                            }

                        }
                    }
                    int b;
                    b = stoi(bod, 0, 2);
                    riadok += vzor[b];
                }
            }
            obrazok2.push_back(riadok);
        }
        obrazok = obrazok2;
        obrazok2.clear();
       
    }
    int p=0;
    for (size_t i = 0; i < 102 + (pocet_opakovani * 2); i++)
    {

        for (size_t j = 0; j < 102 + (pocet_opakovani * 2); j++)
        {
            if (obrazok[i][j] == '#')
            {
                p += 1;
            }
        }
    }

    std::cout << p;
    std::cin >> p;
}



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::string> obrazok;
std::vector<std::string> obrazok2;
int main()
{   
    std::string vzor = "#####.##....##....##.#.....##....##..########.#.##.#.#.##.#..##.#.####.######.#####.######.##..#######.#.#...#..#.####..####...#.####..#......#...#...##.#.....#....#..###.#..##....#.#....#...##.###.#.#..##.......####.........#.#.###.#.#.....#..##..##.#.##..###.##.###.#....#.#..##.#.......###..#.#.#.#.#.....#..#.###.##..##...#....##...##.##...##.#..####.#...#.####...####..#####.#####.#.##...#.###.#######.###..#..##.#.#..#.#.#######.#####.#.##.#.#...##.######.#...##.##.#.........##...##.....#.###.#.##.#.####.";
    std::string vypln = "";
    for (size_t i = 0; i < 106; i++)
    {
        vypln += ".";
    }
    obrazok.push_back(vypln); obrazok.push_back(vypln); obrazok.push_back(vypln);
    std::string vstup;
    for (size_t i = 0; i < 100; i++)
    {
        std::cin >> vstup;
        vstup = "..." + vstup + "...";
        obrazok.push_back(vstup);
    }
    obrazok.push_back(vypln); obrazok.push_back(vypln); obrazok.push_back(vypln);
    
    for (size_t i = 0; i < 106; i++)
    {   
        std::string riadok = "";
        for (size_t j = 0; j < 106; j++)
        {
            std::string bod;
            if (((i == 0) || (i == 105)) || ((j == 0)||(j == 105))) {
                riadok += "#";
            }
            else
            {
                for (int l = -1; l <=1; l++)
                {
                    for (int k = -1; k <=1; k++)
                    {   
                        if (obrazok[i + l][j + k] == '#')
                        {
                            bod+="1";
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
    for (size_t i = 0; i < 106; i++)
    {
        std::string riadok = "";
        for (size_t j = 0; j < 106; j++)
        {
            std::string bod;
            if (((i == 0) || (i == 105)) || ((j == 0) || (j == 105))) {
                riadok += ".";
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
    int p=0;
    for (size_t i = 0; i < 106; i++)
    {

        for (size_t j = 0; j < 106; j++)
        {
            if (obrazok2[i][j] == '#')
            {
                p += 1;
            }
        }
    }

    std::cout << p;
}


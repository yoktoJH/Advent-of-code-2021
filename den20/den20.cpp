
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::string> obrazok;
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
    
    
    
    for (int i = 0; i <106; i++)
    {
        std::cout << obrazok[i]<<std::endl;
    }
    std::cout << vypln;
}


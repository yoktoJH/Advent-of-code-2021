#include <iostream>

int main()
{   
    int bliknutia = 0;
    int chobotnicky[10][10] = { {3,1,7,2,5,3,7,6,8,8},
{4,5,6,6,4,8,3,1,2,5},
{6,3,7,4,5,1,2,6,5,3},
{8,3,2,1,1,4,8,8,8,5},
{4,3,4,2,7,4,7,7,5,8},
{1,3,6,2,1,8,8,5,8,2},
{7,5,8,2,2,1,3,1,3,2},
{6,8,8,7,8,7,5,2,6,8},
{7,6,3,5,1,1,2,7,8,7},
{7,2,4,2,7,8,7,2,7,3} };
    for (size_t step = 0; step < 1000; step++)
    {   
        int uz_ready[10][10] = { {0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0} };
        int deviatky = 1;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                chobotnicky[i][j]++;
            }
        }
        while (deviatky==1)
        {
            deviatky = 0;

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {   
                    
                  
                    if ((chobotnicky[i][j] > 9)&&(uz_ready[i][j]==0)) {
                        deviatky = 1;
                        uz_ready[i][j] = 1;
                        for (int k = (i - 1); k <= (i + 1); k++)
                        {
                            for (int l = (j - 1); l <= (j + 1); l++)
                            {
                                if (((k >= 0) && (k <= 9)) && ((l >= 0) && (l <= 9)))
                                {
                                    chobotnicky[k][l]++;
                                }
                            }
                        }
                    }

                }
            }
        }
        int pocet=0;
        for (size_t i = 0; i < 10; i++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                int x;
                if (chobotnicky[i][j] > 9) {
                    bliknutia++;
                    chobotnicky[i][j] =0;
                    pocet++;
                }

            }
        }
        if (pocet==100)
        {
            std::cout << step<<std::endl;
        }
        
    }
    std::cout << bliknutia<<std::endl;
}


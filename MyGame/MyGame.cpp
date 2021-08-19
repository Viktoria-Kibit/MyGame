#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define spaceX 20
#define spaceY 40

const int X = spaceX + 2;
const int Y = spaceY + 2;

class Life
{
    int background[X][Y];

public:
    Life()
    {
        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                background[i][j] = 0;
            }
        }
    }
    

    void generateLife()
    {
        for (int i = 1; i < X-1; i++)
        {
            for (int j = 1; j < Y-1; j++)
            {
                background[i][j] = rand() % 2;
            }
        }
    }
    void printBackground()
    {
        for (int i = 1; i < X - 1; i++)
        {
            for (int j = 1; j < Y - 1; j++)
            {
                if (background[i][j] == 1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }

};

int main()
{
    Life life;
    life.generateLife();
    life.printBackground();

    return 0;
}

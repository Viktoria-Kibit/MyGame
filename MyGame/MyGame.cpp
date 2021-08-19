#include <iostream>

using namespace std;

#define spaceX 20
#define spaceY 20

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
    ~Life();

};

int main()
{
    

    return 0;
}

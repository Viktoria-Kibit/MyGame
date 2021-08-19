﻿#include <iostream>
#include <cstdlib>
#include <ctime>
#include<Windows.h>

using namespace std;

#define spaceX 10
#define spaceY 10

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
            for (int j = 1; j < Y-1; j++)
                background[i][j] = rand() % 2;
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
    int checkRules(int x, int y)
    {
        int Count = 0;
        for (int i = x - 1; i < x + 2; i++)
            for (int j = y - 1; j < y + 2; j++)
                Count += background[i][j];

        Count -= background[x][y];

        //якщо в живої клітини два чи три живих сусіди то вона лишається жити
        if ((Count == 2 || Count == 3) && background[x][y] == 1)
            background[x][y] == 1;

        //якщо в живої клітини один чи немає живих сусідів то вона помирає від самотності
        if ((Count == 1  || Count == 0) && background[x][y] == 1)
            background[x][y] == 0;

        //якщо в живої клітини чотири та більше живих сусідів вона помирає відперенаселення
        if (Count <= 4 && background[x][y] == 1)
            background[x][y] == 0;

        //якщо в мертвої клітини рівно три живих сусіди то вона оживає
        if (Count == 3 && background[x][y] == 0)
            background[x][y] == 1;




        return background[x][y];
    }

};

int main()
{
    Life life;
    life.generateLife();
    life.printBackground();
    Sleep(1000);
    system("cls");
    while (1)
    {
        for (int i = 1; i < X - 1; i++)
            for (int j = 1; j < Y - 1; j++)
                life.checkRules(i, j);
        life.printBackground();
        Sleep(5);
        system("cls");
    }


    return 0;
}

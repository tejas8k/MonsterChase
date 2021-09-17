// MonsterChase.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>

#include<stdio.h>

#include<conio.h>

#include<string.h>

#include "Initialization.h"

#include "Math/Point2D.h"

#include "Test.cpp"


int myPositionX;
int myPositionY;

int MonsterPositionX[10];
int MonsterPositionY[10];

int monsterNumber = 0;

int monsterIndex;
int counter;

char monsterGroup[10][10] = {
         "mojo",
         "jojo",
         "deacon",
         "john",
         "drax",
         "dexter",
         "jax",
         "tom",
         "dick",
         "harry"
};


    int main() {

        char myName[100];

       
        void InitializePlayer();

        void InitializeMonster(int monsterCount);

        void SpawnMoveMonsters();

        Engine::Initialize();
        Engine::Point2DUnitTest();

        std::cout << "\nEnter your name :\n";
        gets_s(myName);
        std::cout << "You entered : " << myName;

        std::cout << "\n Enter the number of Monsters to spawn \n";
        std::cin >> monsterNumber;

        if (std::cin.fail())
        {
            //not an integer
            std::cout << "Not an int \nRun the program again.";

            return 0;
        }

        InitializePlayer();
        SpawnMoveMonsters();

        char keyPressed = 0;

        while (keyPressed != 'q')
        {
            std::cout << "Select 'W S A D' to move or Q to quit \n";
            std::cin >> keyPressed;

            if (keyPressed == 'W' || keyPressed == 'w')
            {
                std::cout << "My position is: \n";
                std::cout << myPositionX << "\t";
                std::cout << ++myPositionY << std::endl;
                SpawnMoveMonsters();
            }

            else if (keyPressed == 'S' || keyPressed == 's')
            {
                std::cout << "My position is: \n";
                std::cout << myPositionX << "\t";
                std::cout << --myPositionY << std::endl;
                SpawnMoveMonsters();
            }

            else if (keyPressed == 'A' || keyPressed == 'a')
            {
                std::cout << "My position is: \n";
                std::cout << --myPositionX << "\t";
                std::cout << myPositionY << std::endl;
                SpawnMoveMonsters();
            }

            else if (keyPressed == 'D' || keyPressed == 'd')
            {
                std::cout << "My position is: \n";
                std::cout << ++myPositionX << "\t";
                std::cout << myPositionY << std::endl;
                SpawnMoveMonsters();
            }
            else if (keyPressed == 'Q' || keyPressed == 'q')
            {
                return 0;
            }
            else
            {
                std::cout << "Invalid Entry ! \n";
            }
        }
    }
    int randomeGeneratorVertical()
    {
        int vertical;
        vertical = rand() % 110;
        return vertical;
    }

    int randomeGeneratorHorizontal()
    {
        int horizontal;
        horizontal = rand() % 110;
        return horizontal;
    }

    void InitializePlayer() {
        myPositionX = randomeGeneratorHorizontal();
        myPositionY = randomeGeneratorVertical();
        std::cout << "I am starting at postion : \n" <<
            myPositionX << "\t" << myPositionY << "\n";
    }

    void InitializeMonster(int monsternumber) {
        MonsterPositionX[monsterIndex] = randomeGeneratorHorizontal();
        MonsterPositionY[monsterIndex] = randomeGeneratorVertical();
        std::cout << "Monster " << monsterGroup[monsterIndex - 1] << " is at:" << "\n" <<
            MonsterPositionX[monsterIndex] << "\t" << MonsterPositionX[monsterIndex] << "\n";
    }

    void SpawnMoveMonsters() {
        for (monsterIndex = 1; monsterIndex <= monsterNumber; monsterIndex++) {
            if (myPositionX == MonsterPositionX[monsterIndex] && myPositionY == MonsterPositionY[monsterIndex]) {
                break;
            }
            else {
                InitializeMonster(monsterIndex);
                int randomint = rand();
                if (randomint % 100 <= 10) {
                    monsterNumber--;
                    std::cout << "A monster was killed\n";
                }
                else if (randomint % 100 >= 90) {
                    if (monsterNumber < 10) {
                        monsterNumber++;
                        std::cout << "A monster was added\n";
                    }
                }
            }
        }
    }

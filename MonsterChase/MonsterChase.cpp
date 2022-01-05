// MonsterChase.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>

#include<stdio.h>

#include<conio.h>

#include<string.h>

#include "Initialization.h"

#include "Math/Point2D.h"

#include "MonsterChase.h"

#include "Test.cpp"

#include "DynamicArray.h"


    int main() {

        Engine::Initialize();
        Engine::Point2DUnitTest();

        std::cout << "\nEnter your name :\n";
        gets_s(myName);
        std::cout << "You entered : " << myName;

        std::cout << "\n Enter the number of Monsters to spawn \n";       
        std::cin >> monsterNumber;
        std::cin.ignore();
        monsterCount = monsterNumber;
        if (std::cin.fail())
        {
            //not an integer
            std::cout << "Not an int \nRun the program again.";

            return 0;
        }
        RunMonsterChase();
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

        for (int i = 0; i <= monsterNumber; i++)
        {
            delete[] wordsArray[i];
        }

#if defined(_DEBUG)
        _CrtDumpMemoryLeaks();
#endif // _DEBUG
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
        std::cout << myName << " starting at postion : \n" <<
            myPositionX << "\t" << myPositionY << "\n";
    }

    void InitializeMonster(int monsternumber)
    {
        MonsterPositionX[monsterIndex] = randomeGeneratorHorizontal();
        MonsterPositionY[monsterIndex] = randomeGeneratorVertical();
        std::cout << "Monster " << monsterNames[monsterIndex - 1] << " is at:" << "\n" <<
            MonsterPositionX[monsterIndex] << "\t" << MonsterPositionX[monsterIndex] << "\n";
    }

    void SpawnMoveMonsters()
    {
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

    char* readPlayerNameFromInput() {
        char x[20];
        size_t length = 0;
        while (length <= 20) {
            char c;         
            c = std::getchar();       
            if (c != '\n' && c != '\0') {
                x[length++] = c;
            }
            else break;
        }

        if (length == 0)
            return nullptr;

        length++;
        char* _str = new char[length];
        memcpy(_str, x, length - 1);
        _str[length - 1] = '\0';
        return _str;
    }

    void RunMonsterChase() {    

        char* thisWord;
        do {
            //std::cout << "Enter a word, pass empty string to finish : ";
            std::cout << "Enter monster names : ";
            thisWord = readPlayerNameFromInput();
            monsterNames.push_back(thisWord);
            monsterCount--;
        } while (monsterCount != 0); //while (thisWord != nullptr);

        wordsArray = new char* [monsterNames.Size()];
        for (size_t i = 0; i < monsterNames.Size(); i++) {
            //wordsArray[i] = monsterNames[i];
        }
        std::cout << std::endl;
       // char* pSentence = MakeSentence(wordsArray);
        //printf("Your Sentence is: %s\n", pSentence);

    }
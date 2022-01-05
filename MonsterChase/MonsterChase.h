#pragma once
#include "DynamicArray.h"

int monsterNumber = 0;
int monsterCount = 0;

int monsterIndex;
int counter;

int MonsterPositionX[10];
int MonsterPositionY[10];

int myPositionX;
int myPositionY;

char myName[100];

DynamicArray<char*> monsterNames;
char** wordsArray;

void RunMonsterChase();

void InitializePlayer();

void InitializeMonster(int monsterCount);

void SpawnMoveMonsters();

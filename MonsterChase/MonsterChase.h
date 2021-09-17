#pragma once
int monsterNumber = 0;

int monsterIndex;
int counter;

int MonsterPositionX[10];
int MonsterPositionY[10];

int myPositionX;
int myPositionY;

char myName[100];

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

void InitializePlayer();

void InitializeMonster(int monsterCount);

void SpawnMoveMonsters();

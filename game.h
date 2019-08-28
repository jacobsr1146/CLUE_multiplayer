#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "player.h"
#include "cpu.h"
#include "anwser.h"
using namespace std;

class Game
{
public:
   
   Game();
   
   void printLocations(int turn);
   
   void printItems(int turn);
   
   void printPeople(int turn);
   
   void setup(int numPlayers, int numCPU);
   
   void printAllPossabilities();
   
   string getLocation(int index);
   
   string getItem(int index);
   
   string getPeople(int index);
   
   int Guess(int numPlayers, int numCPU, int playerIndex);
   
   int guessGame(int index, int numPlayers, string guessLoc, string guessItem, string guessPers);
   
   void makeMap(string mapFile);
    
   string getPosition(int x, int y);
    
   void setPosition(int x, int y, int Index);
    
   int rollDice(int x);
   
   void printMap();
   
   void Move(int playerIndex, int moves);
   
   void displayMoveMenu(int moves);
   
   string getName(int index);

    
private:
    int totalPlayers = 0;
    int totalCPU = 0;
    Player players[4];
    CPU cpus[4];
    Anwser anwser[1];
    string locations[8] = {"Kitchen", "Media Room", "Living Room", "Bedroom", "Office", "Garage", "Closet", "Restroom"};
    string items[6] = {"Knife", "Baseball Bat", "Axe", "Handgun", "Shovel", "Poison"};
    string people[6] = {"Dr. Black", "Miss Scarlet", "Colonel Mustard", "Mrs. White", "Mrs. Peacock", "Proffesor Plum"};
    int locIndex;
    int itemIndex;
    int persIndex;
    string map[19][26];
};

#endif
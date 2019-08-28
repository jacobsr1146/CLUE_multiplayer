#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Player
{
public:
    
   Player();
   
   Player(string name1, int totalPlayers, string place);
   
   void setName(string name1);
   
   string getName();
   
   void setIndex(int x);
   
   int getIndex();
   
   string getLocations(string location);
   
   string getItems(string item);
   
   string getPeople(string person);
   
   void printLocations();
   
   void printItems();
   
   void printPeople();
   
   bool addLocation(string location);
   
   bool addItem(string Item);
   
   bool addPerson(string person);
   
   void setPosition(string place);
   
   string getPosition();
   

    
private:
    string locations[8]={" ", " ", " ", " ", " ", " ", " ", " "};
    string items[6]={" ", " ", " ", " ", " ", " ",};
    string people[6]={" ", " ", " ", " ", " ", " ",};
    int numLocations = 0;
    int numItems = 0;
    int numPeople = 0;
    string name = "";
    int playerIndex = 0;
    string temp = "";
};

#endif
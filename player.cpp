#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "player.h"
using namespace std;

   Player::Player(){
      name = "";
      locations[8];
       items[6];
       people[6];
       playerIndex = 0;
       temp = "";
   }
   
   Player::Player(string name1, int totalPlayers, string place){      //creates a new player
       name = name1;
       locations[8];
       items[6];
       people[6];
       playerIndex = totalPlayers;
       temp = " ";
   }
   
   void Player::setName(string name1){
      name = name1;
   }
   
   string Player::getName(){
      return name;
   }
   
   void Player::setIndex(int x){
      playerIndex = x;      
   }
   
   int Player::getIndex(){
      return playerIndex;
   }
   
   string Player::getLocations(string location){       //compares the guessed location with CPUs location array
       for(int x=0; x<8; x++){
           if(locations[x] == location){
               return location;
           }
       }
       return " ";
   }
   
   string Player::getItems(string item){       //compares the guessed item with CPUs item array
        for(int x=0; x<6; x++){
           if(items[x] == item){
               return item;
           }
       }
       return " ";
   }
   
   string Player::getPeople(string person){       //compares the guessed person with CPUs people array
        for(int x=0; x<6; x++){
           if(people[x] == person){
               return person;
           }
       }
       return " ";
   }
   
   bool Player::addLocation(string location){      //adds a new location to the players location array
      for(int x=0; x<8; x++){
         if(locations[x]==" "){
            locations[x] = location;
            return true;
         }
      }
   return false;   
   }
   
   bool Player::addItem(string item){      //adds a new item to the players item array
       for(int x=0; x<6; x++){
         if(items[x]==" "){
            items[x] = item;
            return true;
         }
      }
   return false;
   }
   
   bool Player::addPerson(string person){      //adds a new person to the players people array
    for(int x=0; x<6; x++){
         if(people[x]==" "){
            people[x] = person;
            return true;
         }
      }
   return false;
   
   }
    void Player::printLocations(){     //prints the players location cards
       for(int x=0; x<8; x++){
          cout << locations[x];
          if(locations[x] != " "){
             cout << endl;
          }
       }
       cout << endl;
   }
   
   void Player::printItems(){     //prints the players item cards
       for(int x=0; x<6; x++){
          cout << items[x];
          if(items[x] != " "){
             cout << endl;
          }
       }
       cout << endl;
   }
   
   void Player::printPeople(){     //prints the players people cards
       for(int x=0; x<6; x++){
          cout << people[x];
          if(people[x] != " "){
             cout << endl;
          }
       }
       cout << endl;
   }
   void Player::setPosition(string place){
      temp = place;
   }
   
   string Player::getPosition(){      //returns the current location of a specific player
      return temp;
   }
   
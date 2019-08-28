#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "game.h"
#include "player.h"
#include "cpu.h"
#include "anwser.h"

using namespace std;

    Game::Game(){
        int totalPlayers = 0;
        int totalCPU = 0;
    }
    
    void Game::printLocations(int turn){
        players[turn].printLocations();
    }
    
    void Game::printItems(int turn){
        players[turn].printItems();
    }
    
    void Game::printPeople(int turn){
        players[turn].printPeople();
    }

    void Game::setup(int numPlayers, int numCPU){       //randomizes the cards between all of the players and cpus
        Anwser anwser1;
        anwser[0] = anwser1;
        locIndex = random() % 8;
        anwser[0].setLocation(locations[locIndex]);
        itemIndex = random() % 6;
        anwser[0].setItem(items[itemIndex]);
        persIndex = random() % 6;
        anwser[0].setPerson(people[persIndex]);
        
        string map;
        int z = 0;
        while(z == 0){
            cout << "Enter a map file (map.txt):" << endl;
            getline(cin,map);
            cout << endl;
            ifstream file;
            file.open(map);
            if(file.fail()){
                cout << "Invalid Map File" << endl;
            }
            else{
                z++;
            }
        }
        makeMap(map);
        
        string name;
        string temp;
        for(int x=0; x<numPlayers; x++){
            cout << "Player " << x+1 << ": What is your name?" << endl;
            getline(cin,name);
            int posX = random() % 23 + 1;
            int posY = random() % 17 + 1;
            temp = getPosition(posX, posY);
            setPosition(posX, posY, x+1);
            Player player1;
            players[x] = player1;
            players[x].setName(name);
            players[x].setPosition(temp);
            players[x].setIndex(x);
            totalPlayers++;
        }
        totalCPU = numCPU;
        for(int x=0; x<numCPU;x++){
            CPU cpu1;
            cpus[x] = cpu1;
            totalCPU++;
        }
        
        string All[17];
        int count1 = 0;
        for(int x=0; x<8; x++){
            if(x!=locIndex){
                All[count1] = locations[x];
                count1 ++;
            }
        }
        for(int x=0; x<6; x++){
            if(x!=itemIndex){
                All[count1] = items[x];
                count1 ++;
            }
        }
        for(int x=0; x<6; x++){
            if(x!=persIndex){
                All[count1] = people[x];
                count1 ++;
            }
        }
        int count = 0;
        while(count<17){
            for(int x=0; x<totalCPU; x++){
                if(count<7){
                    cpus[x].addLocationCPU(All[count]);
                    count ++;
                }
                if(count>=7 && count<12){
                    cpus[x].addItemCPU(All[count]);
                    count ++;
                }
                if(count>=12){
                    cpus[x].addPersonCPU(All[count]);
                    count ++;
                }
            }
            for(int x=0; x<totalPlayers; x++){
                if(count<7){
                    players[x].addLocation(All[count]);
                    count ++;
                }
                if(count>=7 && count<12){
                    players[x].addItem(All[count]);
                    count ++;
                }
                if(count>=12){
                    players[x].addPerson(All[count]);
                    count ++;
                }
            }
        }
    }
   
   void Game::printAllPossabilities(){      //print every card in the game.
       cout << "=============ALL POSSABILITIES=============" << endl;
       cout << "Locations:        Items:        People:" << endl;
       cout << "Kitchen           Knife         Dr. Black" << endl;
       cout << "Media Room        Baseball Bat  Miss Scarlet" << endl;
       cout << "Living Room       Axe           Colonel Mustard" << endl;
       cout << "Bedroom           Handgun       Mrs. White" << endl;
       cout << "Office            Shovel        Mrs. Peacock" << endl;
       cout << "Garage            Poison        Professor Plum" << endl;
       cout << "Closet" << endl;
       cout << "Restroom" << endl;
       cout << endl;
   }
   
   string Game::getLocation(int index){
       return locations[index];
   }
   
   string Game::getItem(int index){
       return items[index];
   }
   
   string Game::getPeople(int index){
       return people[index];
   }
   
   int Game::Guess(int numPlayers, int numCPU, int playerIndex){       //compares the players guess with the cards of the next player
       string temp = players[playerIndex].getPosition();
       int game = 0;
       string guessLoc = " ";
       if(temp == "K"){
          guessLoc = "Kitchen";
       }
       if(temp == "M"){
          guessLoc = "Media Room";
       }
       if(temp == "L"){
          guessLoc = "Living Room";
       }
       if(temp == "B"){
          guessLoc = "Bedroom";
       }
       if(temp == "O"){
          guessLoc = "Office";
       }
       if(temp == "G"){
          guessLoc = "Garage";
       }
       if(temp == "C"){
          guessLoc = "Closet";
       }
       if(temp == "R"){
          guessLoc = "Restroom";
       }
       if(temp == "F"){
          guessLoc = "Front Door";
       }
       if(temp == " "){
          guessLoc = " ";
       }
      string guessItem = " ";
      string guessPers = " ";
      string temp1 = " ";
       cout << endl;
      if(guessLoc != " "){
           printAllPossabilities();
           cout << "===" << players[playerIndex].getName() << "'s Cards===" << endl;
           cout << "Locations: " << endl; players[playerIndex].printLocations();
           cout << "Items: " << endl; players[playerIndex].printItems();
           cout << "People: " << endl; players[playerIndex].printPeople();
         if(temp == "F"){
             cout << "========FINAL GUESS=======" << endl;
            while(guessLoc == "Front Door"){
               cout << "Where do you think the murder happened?" << endl;
               getline(cin,temp1);
               for(int x=0; x<8; x++){
                  if(temp1 == locations[x]){
                     guessLoc = temp1;
                  }
               }
                if(guessLoc == "Front Door"){
                 cout << "Invalid Location" << endl;
                 cout << "Please try again" << endl;
              }
            }
         }
         while(guessItem == " "){
            cout << "What Item do you think was used?" << endl;
            getline(cin,temp1);
            for(int x=0; x<6; x++){
               if(temp1 == items[x]){
                  guessItem = temp1;
               }
            }
             if(guessItem == " "){
              cout << "Invalid Item" << endl;
              cout << "Please try again" << endl;
           }
         }
         string temp2;
         while(guessPers == " "){
            cout << "Who do you think did the crime?" << endl;
            getline(cin,temp2);
            for(int x=0; x<6; x++){
               if(temp2 == people[x]){
                  guessPers = temp2;
               }
            }
            if(guessPers == " "){
              cout << "Invalid Person" << endl;
              cout << "Please try again" << endl;
           }
         }
         int anwser1 = 0;
         if(temp == "F"){
            if(anwser[0].getAnwserLocation() == guessLoc && anwser[0].getAnwserItem() == guessItem && anwser[0].getAnwserPerson() == guessPers){
               cout << "==========" << players[playerIndex].getName() << " WON=========" << endl;
               cout << "Killer: " << guessPers << endl;
               cout << "Weapon: " << guessItem << endl;
               cout << "Location: " << guessLoc << endl;
               game = 1;
            }
            else{
                cout << endl;
               cout << "======SORRY======" << endl;
               cout << "===WRONG ANWSER===" << endl;
               cout << "Player " << playerIndex +1 << " has been removed from the game." << endl << endl;
               game = 2;
            }
         }
         else{
            if(numPlayers>1){
               anwser1 = guessGame(playerIndex, numPlayers, guessLoc, guessItem, guessPers);
            }
            for(int x=0; x<numCPU; x++){
               while(anwser1 == 0){
                  if(cpus[x].CPUPeople(guessPers) == guessPers){
                        if(players[playerIndex].getPeople(guessPers) == " "){
                           players[playerIndex].addPerson(guessPers);
                           cout << "CPU " << x+1 << " told you that the murder was not done by " << guessPers << "." << endl;
                           cout << guessPers << " has been added to your People list." << endl;
                           anwser1 ++;
                        }
                     }
                  if(cpus[x].CPUItems(guessItem) == guessItem){
                        if(players[playerIndex].getItems(guessItem) == " "){
                           players[playerIndex].addItem(guessItem);
                           cout << "CPU " << x+1 << " told you that the murder was not done with a " << guessItem << "." << endl;
                           cout << guessItem << " has been added to your Items list." << endl;
                           anwser1 ++;
                        }
                     }
                  if(cpus[x].CPULocations(guessLoc) == guessLoc){
                        if(players[playerIndex].getLocations(guessLoc) == " "){
                           players[playerIndex].addLocation(guessLoc);
                           cout << "CPU " << x+1 << " told you that the murder was not in the " << guessLoc << "." << endl;
                           cout << guessLoc << " has been added to your Locations list." << endl;
                           anwser1 ++;
                        }
                     }
                  }
               }
            }
        }
      else{
         cout << "You cannot guess if you are in the hallway" << endl;
         game = -1;
      }
      if(anwser == 0 && game == 0){
          cout << "No one could prove you wrong" << endl;
      }
      return game;
   }
   
   int Game::guessGame(int index, int numPlayers, string guessLoc, string guessItem, string guessPers){
       int anwser = 0;
       int person = 0;
        int item = 0;
         int loc = 0;
       for(int x=0; x<totalPlayers; x++){
            while(anwser == 0 && x != index){
               if(players[x].getPeople(guessPers) == guessPers){
                  for(int y=0; y<6; y++){
                     if(people[y] == guessPers){
                        person = 1;
                     }
                  }
                  if(person != 1){
                     if(players[index].addPerson(guessPers) == true){
                        players[index].addPerson(guessPers);
                        cout << players[x].getName() <<" told you that the murder was not done by " << guessPers << "." << endl;
                        cout << guessPers << " has been added to your People list." << endl;
                        anwser ++;
                    }
                  }
               }
               if(players[x].getItems(guessItem) == guessItem){
                  for(int y=0; y<6; y++){
                     if(items[y] == guessItem){
                        item = 1;
                     }
                  }
                  if(item != 1){
                     if(players[index].addItem(guessItem) == true){
                        players[index].addItem(guessItem);
                        cout << players[x].getName() <<" told you that the murder was not done with a " << guessItem << "." << endl;
                        cout << guessItem << " has been added to your Items list." << endl;
                        anwser++;
                     }
                  }
               }
               if(players[x].getLocations(guessLoc) == guessLoc){
                  for(int y=0; y<8; y++){
                     if(locations[y] == guessLoc){
                        loc = 1;
                     }
                  }
                  if(loc != 1){
                     if(players[index].addLocation(guessLoc) == true){
                        players[index].addLocation(guessLoc);
                        cout << players[x].getName() << " told you that the murder was not in the " << guessLoc << "." << endl;
                        cout << guessLoc << " has been added to your Locations list." << endl;
                        anwser ++;
                     }
                  }
               }
            }
         }
        return anwser;
   }
   
   void Game::makeMap(string mapFile){        //reads the map file and turns it into a 2D array
      int y = 0;
      string line = "";
      ifstream file;
      file.open(mapFile);
      while(getline(file,line)){
          for(int x=0; x<line.length(); x++){
              map[y][x]=line.substr(x,1);
              cout << map[y][x];
          }
          cout << endl;
          y++;
      }
  }
  
  void Game::printMap(){        //prints out the map with every players current location
       for(int y=0; y<19; y++){
           for(int x=0; x<26; x++){
               cout << map[y][x];
           }
           cout << endl;
       }
       cout << "=======Key=======" << endl;
       cout << "K = Kitchen" << endl;
       cout << "M = Media Room" << endl;
       cout << "L = Living Room" << endl;
       cout << "B = Bedroom" << endl;
       cout << "O = Office" << endl;
       cout << "G = Garage" << endl;
       cout << "C = Closet" << endl;
       cout << "R = Restroom" << endl;
       cout << "F = Front Door (Final Guess Location)" << endl;
       cout << "- or | = Wall" << endl << endl;
   }
  
  string Game::getPosition(int x, int y){
    return map[y][x];
  }
  
  void Game::setPosition(int x, int y, int Index){
      string place = to_string(Index);
        map[y][x] = place;
  }
    
   int Game::rollDice(int x){     //rolls a randomized dice
    return random() % x + 1;                //returning a random number between 1 and x
   }
   
   void Game::displayMoveMenu(int moves){
       cout << "You have " << moves << " moves left" << endl;
      cout << "Select a numerical option:" << endl;
      cout << "======Move Menu=====" << endl;
      cout << "1. Move Up" << endl;
      cout << "2. Move Down" << endl;
      cout << "3. Move Left" << endl;
      cout << "4. Move Right" << endl;
      cout << "5. Print Map" << endl;
      cout << "6. Done Moving" << endl;
   }
   
   void Game::Move(int playerIndex, int moves){       //allows a player to move on the map
    string index = to_string(playerIndex+1);
    string direction;
    string temp1;
      while(moves>0){
          direction = " ";
         cout << "Which direction would you like to move?" << endl;
         while(direction == " "){
             displayMoveMenu(moves);
             getline(cin,temp1);
             if(temp1 == "1" || temp1 == "2" || temp1 == "3" || temp1 == "4" || temp1 == "5" || temp1 == "6"){
                    direction = temp1;
            }
            else{
                cout << "Invalid Input" << endl;
            }
         }
         int repeat = 0;
         switch(stoi(direction)){
            case 1:
               for(int y=0; y<19; y++){
                  for(int x=0; x<26;x++){
                     if(map[y][x] == index && repeat == 0){
                        if(map[y-1][x] != "-" && map[y-1][x] != "|"){
                            repeat++;
                           map[y][x] = players[playerIndex].getPosition();
                           players[playerIndex].setPosition(map[y-1][x]);
                           map[y-1][x] = index;
                           moves --;
                        }
                        else{
                           cout << "A Wall is in the way" << endl << endl;
                           repeat++;
                        }
                     }
                  }
               }
               break;
            case 2:
               for(int y=0; y<19; y++){
                  for(int x=0; x<26;x++){
                     if(map[y][x] == index && repeat == 0){
                        if(map[y+1][x] != "-" && map[y+1][x] != "|"){
                            repeat++;
                           map[y][x] = players[playerIndex].getPosition();
                           players[playerIndex].setPosition(map[y+1][x]);
                           map[y+1][x] = index;
                           moves --;
                        }
                        else{
                           cout << "A Wall is in the way" << endl << endl;
                           repeat++;
                        }
                     }
                  }
               }
               break;
            case 3:
               for(int y=0; y<19; y++){
                  for(int x=0; x<26;x++){
                     if(map[y][x] == index && repeat == 0){
                        if(map[y][x-1] != "-" && map[y][x-1] != "|"){
                            repeat++;
                           map[y][x] = players[playerIndex].getPosition();
                           players[playerIndex].setPosition(map[y][x-1]);
                           map[y][x-1] = index;
                           moves --;
                        }
                        else{
                           cout << "A Wall is in the way" << endl << endl;
                           repeat++;
                        }
                     }
                  }
               }
               break;
            case 4:
               for(int y=0; y<19; y++){
                  for(int x=0; x<26;x++){
                     if(map[y][x] == index && repeat == 0){
                        if(map[y][x+1] != "-" && map[y][x+1] != "|"){
                            repeat++;
                           map[y][x] = players[playerIndex].getPosition();
                           players[playerIndex].setPosition(map[y][x+1]);
                           map[y][x+1] = index;
                           moves --;
                        }
                        else{
                           cout << "A Wall is in the way" << endl << endl;
                           repeat++;
                        }
                     }
                  }
               }
               break;
            case 5:
               printMap();
               break;
            case 6:
               moves = -1;
               break;
            default:
               cout << "invalid input" << endl;
               break;
         }
      }
      if(moves == 0){
          cout << "You have 0 moves left" << endl;
      }
   }
   
   string Game::getName(int index){
       return players[index].getName();
   }
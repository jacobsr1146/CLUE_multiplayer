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


void displayStart(){
    cout << "Select a numerical option:" << endl;
    cout << "======Start Menu=====" << endl;
    cout << "1. Yes, start game" << endl;
    cout << "2. No, this looks boring" << endl;
}

void displayMenu(string name){     //menu screen/display
  cout << endl;
  cout << "It is " << name << "'s turn:" << endl << endl;
  cout << "Select a numerical option:" << endl;
  cout << "======Turn Menu=====" << endl;
  cout << "1. Roll Dice" << endl;
  cout << "2. Guess" << endl;
  cout << "3. What Do I Have?" << endl;
  cout << "4. Print All Possabilities" << endl;
  cout << "5. End Turn" << endl;
  cout << "6. END GAME" << endl;
}


int main(int argc, char const *argv[]) {
    Game game[1];
    int begin = 0;
    string temp1;
    string start = " ";
    while(start == " "){
        cout << "Would you like to play Clue?" << endl;
        displayStart();
        getline(cin,temp1);
        if(temp1 == "1" || temp1 == "2"){
                    start = temp1;
        }
        else{
            cout << "invalid input" << endl;
        }
    }
    
    int numPlayers = 0;
    int numCPU = 0;
    string num;
    
    while(numPlayers > 4 || numPlayers < 1){
        cout << "How many players? (1-4)" << endl;
        cout << "*2 or more is reccomended" << endl;
        getline(cin,temp1);
        if(temp1 == "1" || temp1 == "2" || temp1 == "3" || temp1 == "4"){
            num = temp1;
            switch(stoi(num)){
            case 1: numPlayers = 1; break;
            case 2: numPlayers = 2; break;
            case 3: numPlayers = 3; break;
            case 4: numPlayers = 4; break;
            default: cout << "invalid input" << endl;
            }
        }
        else{
            cout << "invalid input" << endl;
        }
    }
    while(numCPU > 4 || numCPU < 1){
        cout << "How many CPUs? (1-4)" << endl;
        cout << "*You will not be actually playing against the CPUs" << endl;
        getline(cin,temp1);
        if(temp1 == "1" || temp1 == "2" || temp1 == "3" || temp1 == "4"){
            num = temp1;
            switch(stoi(num)){
            case 1: numCPU = 1; break;
            case 2: numCPU = 2; break;
            case 3: numCPU = 3; break;
            case 4: numCPU = 4; break;
            default: cout << "invalid input" << endl;
            }
        }
        else{
            cout << "invalid input" << endl;
        }
    }
    game[0].setup(numPlayers,numCPU);
    
    string choice;
    int game1 = 0;
    int turn = 1;
    int noMoves = 0;
    int noGuess = 0;
    int out;
    int Out[4] = {0, 0, 0, 0};
    while (choice != "6") {
        choice = " ";
        for(int x=0; x<4; x++){
            if(Out[x] == 0){
                out++;
            }
        }
        if(out == (4-numPlayers)){
            cout << "Sorry! You Lose!" << endl;
            game1 = 1;
        }
        if(game1 == 1){
                choice = "6";
            }
        else{
            while(choice == " "){
                displayMenu(game[0].getName(turn-1));
                getline(cin,temp1);
                if(temp1 == "1" || temp1 == "2" || temp1 == "3" || temp1 == "4" || temp1 == "5" || temp1 == "6"){
                    choice = temp1;
                }
            }
        }
            int dice = 0;
            int dice2 = 0;
            int diceTotal = 0;
            
            switch (stoi(choice)) {     //coorsponding options based off of the display screen. along with each options actions.
                case 1:
                    if(noMoves == 0 && noGuess == 0){
                        dice = game[0].rollDice(6);
                        dice2 = game[0].rollDice(6);
                        diceTotal = dice + dice2;
                        cout << "You rolled a " << dice << " and a " << dice2 << endl;
                        cout << "Total = " << diceTotal << endl << endl;
                        game[0].Move(turn-1, diceTotal);
                    }
                    if(noMoves != 0){
                        cout << "You have already moved" << endl;
                    }
                    if(noGuess != 0){
                        cout << "You have already guessed" << endl;
                    }
                    noMoves = 1;
                    break;

                case 2:
                    if(noGuess == 0){
                        game1 = game[0].Guess(numPlayers, numCPU, turn-1);
                        if(game1 != -1){
                            noGuess = 1;
                        }
                    }
                    else{
                        cout << "You have already guessed" << endl;
                    }
                    if(game1 == 2){
                        for(int x=0; x<4; x++){
                            if(Out[x] == 0){
                                Out[x] = turn;
                            }
                        }
                    }
                    break;

                case 3:
                    cout << "===" << game[0].getName(turn-1) << "'s Cards===" << endl;
                   cout << "Locations: " << endl; game[0].printLocations(turn-1);
                   cout << "Items: " << endl; game[0].printItems(turn-1);
                   cout << "People: " << endl; game[0].printPeople(turn-1);
                    break;

                case 4:
                    game[0].printAllPossabilities();
                    break;

                case 5:
                    noMoves = 0;
                    noGuess = 0;
                    turn ++;
                    if(turn > numPlayers){
                        turn = 1;
                    }
                    for(int x=0; x<4; x++){
                        if(Out[x] == turn){
                            turn++;
                        }
                    }
                    break;
                
                case 6:
                    break;
                default:
                    cout << "invalid input" << endl;
                    cout << endl;
            }
        }
        cout << "Thanks for Playing!!!" << endl;
    }
    

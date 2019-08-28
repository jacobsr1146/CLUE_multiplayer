#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "cpu.h"
using namespace std;

    CPU::CPU(){     //default function
      locations[8];
      items[6];
      people[6];
    }
   
   string CPU::CPULocations(string location){       //compares the guessed location with CPUs location array
       for(int x=0; x<8; x++){
           if(locations[x] == location){
               return location;
           }
       }
       return " ";
   }
   
   string CPU::CPUItems(string item){       //compares the guessed item with CPUs item array
        for(int x=0; x<6; x++){
           if(items[x] == item){
               return item;
           }
       }
       return " ";
   }
   
   string CPU::CPUPeople(string person){       //compares the guessed person with CPUs people array
        for(int x=0; x<6; x++){
           if(people[x] == person){
               return person;
           }
       }
       return " ";
   }
   
   bool CPU::addLocationCPU(string location){      //adds a new location to the players location array
      for(int x=0; x<8; x++){
         if(locations[x]==" "){
            locations[x] = location;
            return true;
         }
      }
   return false;   
   }
   
   bool CPU::addItemCPU(string item){      //adds a new item to the players item array
       for(int x=0; x<6; x++){
         if(items[x]==" "){
            items[x] = item;
            return true;
         }
      }
   return false;
   }
   
   bool CPU::addPersonCPU(string person){      //adds a new person to the players people array
    for(int x=0; x<6; x++){
         if(people[x]==" "){
            people[x] = person;
            return true;
         }
      }
   return false;
   
   }
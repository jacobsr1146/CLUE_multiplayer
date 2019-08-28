#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class CPU
{
public:

    CPU();
    
    string CPULocations(string location);
    
    string CPUItems(string item);
    
    string CPUPeople(string person);
    
    bool addLocationCPU(string location);
   
    bool addItemCPU(string Item);
   
    bool addPersonCPU(string person);

    
private:
    string locations[8]={" ", " ", " ", " ", " ", " ", " ", " "};
    string items[6]={" ", " ", " ", " ", " ", " ",};
    string people[6]={" ", " ", " ", " ", " ", " ",};
    int numLocations = 0;
    int numItems = 0;
    int numPeople = 0;
};

#endif
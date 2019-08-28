#ifndef ANWSER_H
#define ANWSER_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Anwser
{
public:
    
    Anwser();
    
   void setLocation(string location1);
   
   void setItem(string item1);
   
   void setPerson(string person1);
   
   string getAnwserLocation();
   
   string getAnwserItem();
   
   string getAnwserPerson();

    
private:
    string location = "";
    string item = "";
    string person = "";
};

#endif
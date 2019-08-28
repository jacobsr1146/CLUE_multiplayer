#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "anwser.h"
using namespace std;

    Anwser::Anwser(){
        location = "";
        item = "";
        person = "";
    }
    
    void Anwser::setLocation(string location1){       //sets the correct location
        location = location1;
    }
   
   void Anwser::setItem(string item1){        //sets the correct item
       item = item1;
   }
   
   void Anwser::setPerson(string person1){        //sets the correct person
       person = person1;
   }

    string Anwser::getAnwserLocation(){     //returns the correct location
        return location;
    }
   
   string Anwser::getAnwserItem(){     //returns the correct item
       return item;
   }
   
   string Anwser::getAnwserPerson(){     //returns the correct person
       return person;
   }
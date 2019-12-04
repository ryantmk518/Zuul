 #include <iostream>
#include <cstring>

//Stores name of item
using namespace std;

class Item {
public:
  Item();
  char* getName();
private:
  char name[99];
};

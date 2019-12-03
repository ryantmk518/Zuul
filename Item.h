#include <iostream>
#include <cstring>

using namespace std;

class Item {
public:
  Item();
  char* getName();
private:
  char name[99];
};

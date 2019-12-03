#include <iostream>
#include <cstring>
#include <map>
#include "Item.h"
#include <vector>

using namespace std;

class Room {  
 public:
  Room();
  char* getName();
  char* getDescription();
  map<const char*, Room*>* getMap();
  vector<Item*>* addItems(Item* item);
  bool getCurrent(bool current);
  void printMap();
  void printItems();
  Item* takeItem(char* item);
 private:
  char description[999];
  map<const char*, Room*> exitMap;
  vector<Item*> itemList;
  char name[99];
  bool current;
};
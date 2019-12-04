#include <iostream>
#include <cstring>
#include <map>
#include "Item.h"
#include <vector>

//Room header. 

using namespace std;

class Room {  
 public:
  //Various functions seen in room.cpp
  Room();
  char* getName();
  char* getDescription();
  map<const char*, Room*>* getMap();
  vector<Item*>* addItems(Item* item);
  bool getCurrent(bool current);
  void printMap();
  void printItems();
  Item* takeItem(char* item);
  Room* getExitRoom(char* direction);
 private:
  //Private info
  char description[9999];
  map<const char*, Room*> exitMap;
  vector<Item*> itemList;
  char name[99];
  bool current;
};

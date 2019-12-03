#include <iostream>
#include <cstring>
#include "Room.h"


using namespace std;

Room::Room() {

}

char* Room::getDescription(){
  return description;
}

map<const char*,Room*>* Room::getMap(){
  return &exitMap;
}

vector<Item*>* Room::addItems(Item* item){
  itemList.push_back(item);
}

char* Room::getName(){
  return name;
}


bool Room::getCurrent(bool current){
  return current;
}

void Room::printMap() {
  map<const char*, Room*>::iterator it;
  for (it = this->exitMap.begin(); it!=this->exitMap.end(); ++it) {
    cout << it-> first << " ";
  }
  cout << "\n";
}


void Room::printItems(){
  vector<Item*>::iterator it;
  for (it = itemList.begin(); it!= itemList.end(); ++it) {
    cout << (*it)->getName() << " ";
  }
  cout << endl;
}

Item* Room::takeItem(char* item){
  vector<Item*>::iterator it;
  for (it = itemList.begin(); it!=itemList.end(); ++it) {
    if (strcmp((*it)->getName(), item) == 0) {
      Item* i = (*it);
    it:itemList.erase(it);
      return(i);
    }
  }
  return NULL;
}

#include <iostream>
#include <cstring>
#include "Room.h"


//Room class. Contains various functions for room.
using namespace std;

Room::Room() {

}


//Description
char* Room::getDescription(){
  return description;
}

//Map
map<const char*,Room*>* Room::getMap(){
  return &exitMap;
}

//Add item to vector
vector<Item*>* Room::addItems(Item* item){
  itemList.push_back(item);
}

//Add name
char* Room::getName(){
  return name;
}

//Unused
bool Room::getCurrent(bool current){
  return current;
}

//Prints the map
void Room::printMap() {
  map<const char*, Room*>::iterator it;
  for (it = this->exitMap.begin(); it!=this->exitMap.end(); ++it) {
    cout << it-> first << " ";
  }
  cout << "\n";
}

//Prints items
void Room::printItems(){
  vector<Item*>::iterator it;
  for (it = itemList.begin(); it!= itemList.end(); ++it) {
    cout << (*it)->getName() << " ";
  }
  cout << endl;
}

//Remove item from room
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

//Get room corresponding to exit direction
Room* Room::getExitRoom(char* direction) {
  map<const char*, Room*>::iterator it;
  for(it = this-> exitMap.begin(); it != this->exitMap.end(); ++it) {
    if(strcmp(it->first, direction) == 0) {
      return it->second;
    }
  }
  return 0;
}

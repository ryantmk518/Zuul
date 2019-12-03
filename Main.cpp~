#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Room.h"
#include <string.h>

using namespace std;


int main(){
  vector<Room*> rList;
  vector<Room*>* roomList = &rList;
  vector<char*> inventory;
  vector<char*>* inv;
  //Distant Woods
  Room* DW = new Room();
  Room* BM = new Room();
  Room* BL = new Room();
  Room* MT = new Room();
  Room* FT = new Room();
  strcpy(DW->getName(),"Distant Woods");
  strcpy(DW->getDescription(), "You begin your hunt in the distant woods. Oddly enough, all the trees are black."); 
  strcpy(BM->getName(), "Black Market");
  strcpy(BM->getDescription(), "You walk east, but it doesn't seem like anything's here.");
  strcpy(BL->getName(), "Blorax");
  strcpy(BL->getDescription(), "A black creature sits on a black stump in front of you. \nI AM THE BLOARX AND I SPEAK FOR THE TREES. LITTER AGAIN AND I'LL CHOP OFF YOUR KNEES. \nDoesn't sound like you want to approach him any time soon.");
  strcpy(MT->getName(), "Monka Tree");
  strcpy(MT->getDescription(), "The Monkas on the Monka Tree taunt you with their extreme Monkaness.");
  strcpy(FT->getName(), "Throw Hands");
  strcpy(FT->getDescription(), "You attempt throw hands at the Blorax, but what good is it.");
  

  
  DW->getMap()->insert(pair<const char*, Room*>("East" , BM));
  DW->getMap()->insert(pair<const char*, Room*>("North" , BL));
  DW->getMap()->insert(pair<const char*, Room*>("South" , MT));
  BM->getMap()->insert(pair<const char*, Room*>("West" , DW));
  MT->getMap()->insert(pair<const char*, Room*>("North" , DW));


  Item* BananaPeel = new Item();
  strcpy(BananaPeel->getName(), "Banana Peel");
  MT->addItems(BananaPeel);

  Item* Test = new Item();
  strcpy(Test->getName(), "Test");
  DW->addItems(Test);
  
  roomList->push_back(DW);
  roomList->push_back(BM);
  roomList->push_back(BL);
  roomList->push_back(MT);

  
  //Game
  cout << "The Council of Loathing wishes to speak to you. \nHELLO, ADVENTURER. THE COUNCIL\'S MOST WANTED CRIMINAL PETER JIN HAS BEEN LOCATED IN THE DISTANT WOODS. THERE IS A 20,000 SCHEMCKLE BOUNTY ON HIS HEAD. WE MUST HAVE HIS JIN AND OUT FORMULA. RECOVER THE FORUMULA AND BRING IT BACK TO US. \nType go (North, South, West or East) to go in a certain direction. Type pick up (item) to pick up an item." << endl;

  char current[99] = "Distant Woods";
  bool game = true;
  while (game == true) {
    vector<Room*>::iterator it;
    for (it = roomList->begin(); it !=roomList -> end(); ++it) {
      if (strcmp(current, (*it) ->getName()) == 0) {
	cout << (*it)->getDescription() << endl;
	cout << "There are exits to your: ";
	(*it)->printMap();
	cout << "Items in the room: " << endl;
	(*it)->printItems();
	if (inv->empty() == true) {
	  cout << "You have no items" << endl;
	}
	else {
	  cout << "Bruh" << endl;
	  vector<char*>::iterator i;
	  for (i = inv->begin(); i != inv->end(); ++i) {
	    cout << *i << endl;
	  }
	}
	char input[99];
	cin.get(input, 99);
	if (strncmp(input, "go ", 3) == 0) {
	  char direction[strlen(input)-3];
	  for (int a = 3; a < strlen(input); a++) {
	    direction[a-3] = input[a];
	  }
	  cout<< direction << endl;
	}
	else if (strncmp(input, "pick up ", 8) == 0) {
	  char thing[strlen(input)-3];
	  for (int a = 3; a < strlen(input); a++) {
	    thing[a-3] = input[a];
	  }
	  (*it)->takeItem(thing);
	  inv->push_back(thing);
	}
      }	  
    }
  }
}



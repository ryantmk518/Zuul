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
  vector<Item*> iList;
  vector<Item*>* itemList = &iList;
  //Distant Woods
  Room* DW = new Room();
  Room* BM = new Room();
  Room* BL = new Room();
  Room* MT = new Room();
  Room* FT = new Room();
  Room* inShack = new Room();
  Room* ABlorax = new Room();
  Room* inventory = new Room();
  Room* a = new Room();
  Room* b = new Room();
  Room* c = new Room();
  Room* d = new Room();
  Room* e = new Room();
  Room* f = new Room();
  Room* g = new Room();
  Room* h = new Room();
  strcpy(DW->getName(),"Distant Woods");
  strcpy(DW->getDescription(), "You begin your hunt in the distant woods. Oddly enough, all the trees are black."); 
  strcpy(BM->getName(), "Black Market");
  strcpy(BM->getDescription(), "You walk east and find a dark shack.");
  strcpy(BL->getName(), "Blorax");
  strcpy(BL->getDescription(), "A black creature sits on a black stump in front of you. \nI AM THE BLORAX AND I SPEAK FOR THE TREES. LITTER AGAIN AND I'LL CHOP OFF YOUR KNEES. \nDoesn't sound like you want to approach him any time soon.");
  strcpy(MT->getName(), "Monka Tree");
  strcpy(MT->getDescription(), "The Monkas on the Monka Tree taunt you with their extreme Monkaness.");
  strcpy(FT->getName(), "Throw Banana");
  strcpy(FT->getDescription(), "You throw a banana peel at the Blorax enraging him. As he charges towards you, he stubs his toe and dies. Now that's epic.");
  strcpy(ABlorax->getName(), "Approach Blorax");
  strcpy(ABlorax->getDescription(), "You attempt to approach the Blorax but he knocks you back");
  strcpy(inShack->getName(), "Inside Shack");
  strcpy(inShack->getDescription(), "Lying on the floor is the Jin and out formula! Peter Jin may have escaped but at least you have the formula!");
  strcpy(a->getName(), "A");
  strcpy(b->getName(), "B");
  strcpy(c->getName(), "C");
  strcpy(d->getName(), "D");
  strcpy(e->getName(), "E");
  strcpy(f->getName(), "F");
  strcpy(g->getName(), "G");
  strcpy(a->getDescription(), "You find a pair of foot prints headed this way!");
  strcpy(d->getDescription(), "You find a pair of foot prints headed this way!");
  strcpy(f->getDescription(), "You find a pair of foot prints headed this way!");
  strcpy(b->getDescription(), "Hmmmm.... A dead end.");
  strcpy(c->getDescription(), "Hmmmm.... A dead end.");
  strcpy(e->getDescription(), "Hmmmm.... A dead end.");
  strcpy(g->getDescription(), "Hmmmm.... A dead end.");

  
  DW->getMap()->insert(pair<const char*, Room*>("North" , BL));
  DW->getMap()->insert(pair<const char*, Room*>("South" , MT));
  BM->getMap()->insert(pair<const char*, Room*>("East" , DW));
  MT->getMap()->insert(pair<const char*, Room*>("North" , DW));
  MT->getMap()->insert(pair<const char*, Room*>("East" , a));
  MT->getMap()->insert(pair<const char*, Room*>("West" , b));
  a->getMap()->insert(pair<const char*, Room*>("East" , c));
  a->getMap()->insert(pair<const char*, Room*>("West" , d));
  d->getMap()->insert(pair<const char*, Room*>("East" , e));
  d->getMap()->insert(pair<const char*, Room*>("West" , f));
  f->getMap()->insert(pair<const char*, Room*>("East" , g));
  f->getMap()->insert(pair<const char*, Room*>("West" , BM));
  BL->getMap()->insert(pair<const char*, Room*>("South" , DW));
  BL->getMap()->insert(pair<const char*, Room*>("West" , ABlorax));
  ABlorax->getMap()->insert(pair<const char*, Room*>("East", BL));
  FT->getMap()->insert(pair<const char*, Room*>("South" , DW));
  

  
  Item* BananaPeel = new Item();
  strcpy(BananaPeel->getName(), "Banana Peel");
  MT->addItems(BananaPeel);
  itemList->push_back(BananaPeel);
  
  Item* Test = new Item();
  strcpy(Test->getName(), "Test");
  DW->addItems(Test);
  itemList->push_back(Test);

  Item* ShackKey = new Item();
  strcpy(ShackKey->getName(), "Shack Key");
  FT->addItems(ShackKey);
  itemList->push_back(ShackKey);

  
  roomList->push_back(DW);
  roomList->push_back(BM);
  roomList->push_back(BL);
  roomList->push_back(MT);
  roomList->push_back(a);
  roomList->push_back(b);
  roomList->push_back(c);
  roomList->push_back(d);
  roomList->push_back(e);
  roomList->push_back(f);
  roomList->push_back(g);
  roomList->push_back(FT);
  roomList->push_back(ABlorax);
  //Game
  cout << "The Council of Loathing wishes to speak to you. \nHELLO, ADVENTURER. THE COUNCIL\'S MOST WANTED CRIMINAL PETER JIN HAS BEEN LOCATED IN THE DISTANT WOODS. THERE IS A 20,000 SCHEMCKLE BOUNTY ON HIS HEAD. WE MUST HAVE HIS JIN AND OUT FORMULA. RECOVER THE FORMULA AND BRING IT BACK TO US. \nType go (North, South, West or East) to go in a certain direction. Type pick up (item) to pick up an item." << endl;

  char current[] = "Distant Woods";
  bool game = true;
  char input[99];
  while (game == true) {
    vector<Room*>::iterator it;
    for (it = roomList->begin(); it !=roomList -> end(); ++it) {
      if (strcmp(current, (*it) ->getName()) == 0) {
	cout << (*it)->getDescription() << endl;
	cout << "There are exits to your: ";
	(*it)->printMap();
	cout << "Items in the room: ";
	(*it)->printItems();
	cout << "Your inventory: ";
	inventory->printItems();
	cin.get(input, 99);
	cin.clear();
	cin.ignore(1000, '\n');
	if (strncmp(input, "go ", 3) == 0) {
	  char direction[strlen(input)-3];
	  for (int a = 3; a < strlen(input); a++) {
	    direction[a-3] = input[a];
	  }
	  strcpy(current, (*it)->getExitRoom(direction)->getName());
	  cout << current << endl;
	}
	else if (strncmp(input, "pick up ", 8) == 0) {
	  char thing[strlen(input)-8];
	  for (int a = 8; a < strlen(input); a++) {
	    thing[a-8] = input[a];
	  }
	  if (thing == "Banana Peel"){
	    BL->getMap()->insert(pair<const char*, Room*> ("Fight", FT));
	  }
	  else if (thing == "Shack Key") {
	    BM->getMap()->insert(pair<const char*, Room*> ("Enter", inShack));
	  }
	  vector<Item*>::iterator a;
	  for (a = itemList->begin(); a != itemList->end(); ++a) {
	    if (strcmp(thing, (*a)->getName()) == 0) {
	      inventory->addItems(*a);
	    }
	  (*it)->takeItem(thing);
	  }
	}
      }	  
    }
  }
}



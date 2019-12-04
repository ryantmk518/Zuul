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

  char North[] = "North"; 
  char East[] = "East";
  char South[] = "South";
  char West[] = "West";
  
  Room* r1 = new Room();
  Room* r2 = new Room();
  Room* r3 = new Room();
  Room* r4 = new Room();
  Room* r5 = new Room();
  Room* r6 = new Room();
  Room* r7 = new Room();
  Room* inventory = new Room();
  Room* r8 = new Room();
  Room* r9 = new Room();
  Room* r10 = new Room();
  Room* r11 = new Room();
  Room* r12 = new Room();
  Room* r13 = new Room();
  Room* r14 = new Room();
  Room* r15 = new Room();
  strcpy(r1->getName(),"Distant Woods");
  strcpy(r1->getDescription(), "You begin your hunt in the distant woods. Oddly enough, all the trees are black."); 
  strcpy(r2->getName(), "Black Market");
  strcpy(r2->getDescription(), "You walk east and find a dark shack.");
  strcpy(r3->getName(), "Blorax");
  strcpy(r3->getDescription(), "A black creature sits on a black stump in front of you. \nI AM THE BLORAX AND I SPEAK FOR THE TREES. LITTER AGAIN AND I'LL CHOP OFF YOUR KNEES. \nDoesn't sound like you want to approach him any time soon.");
  strcpy(r4->getName(), "Monka Tree");
  strcpy(r4->getDescription(), "The Monkas on the Monka Tree taunt you with their extreme Monkaness.");
  strcpy(r5->getName(), "Throw Banana");
  strcpy(r5->getDescription(), "You throw a banana peel at the Blorax enraging him. As he charges towards you, he stubs his toe and dies. Now that's epic.");
  strcpy(r6->getName(), "Approach Blorax");
  strcpy(r6->getDescription(), "You attempt to approach the Blorax but he knocks you back");
  strcpy(r7->getName(), "Inside Shack");
  strcpy(r7->getDescription(), "Lying on the floor is the Jin and out formula! Peter Jin may have escaped but at least you have the formula! Quick, exit the building before you get caught!");
  strcpy(r8->getName(), "Swamp");
  strcpy(r9->getName(), "Plains");
  strcpy(r10->getName(), "Mountain");
  strcpy(r11->getName(), "Hills");
  strcpy(r12->getName(), "Lake");
  strcpy(r13->getName(), "Temple");
  strcpy(r14->getName(), "Statue");
  strcpy(r15->getName(), "Win");
  strcpy(r8->getDescription(), "You find a pair of foot prints headed this way!");
  strcpy(r11->getDescription(), "You find a pair of foot prints headed this way!");
  strcpy(r13->getDescription(), "You find a pair of foot prints headed this way!");
  strcpy(r9->getDescription(), "Hmmmm.... A dead end.");
  strcpy(r10->getDescription(), "Hmmmm.... A dead end.");
  strcpy(r12->getDescription(), "Hmmmm.... A dead end.");
  strcpy(r14->getDescription(), "Hmmmm.... A dead end.");
  strcpy(r15->getDescription(), "You run towards the opening in the trees until you arrive at the council.");

  
  r1->getMap()->insert(pair<const char*, Room*>("North" , r3));
  r1->getMap()->insert(pair<const char*, Room*>("South" , r4));
  r2->getMap()->insert(pair<const char*, Room*>("East" , r1));
  r4->getMap()->insert(pair<const char*, Room*>("North" , r1));
  r4->getMap()->insert(pair<const char*, Room*>("East" , r8));
  r4->getMap()->insert(pair<const char*, Room*>("West" , r9));
  r8->getMap()->insert(pair<const char*, Room*>("South" , r10));
  r8->getMap()->insert(pair<const char*, Room*>("East" , r11));
  r8->getMap()->insert(pair<const char*, Room*>("West" , r4));
  r11->getMap()->insert(pair<const char*, Room*>("East" , r12));
  r11->getMap()->insert(pair<const char*, Room*>("North" , r13));
  r11->getMap()->insert(pair<const char*, Room*>("West" , r8));
  r13->getMap()->insert(pair<const char*, Room*>("East" , r14));
  r13->getMap()->insert(pair<const char*, Room*>("West" , r2));
  r13->getMap()->insert(pair<const char*, Room*>("South" , r11));
  r10->getMap()->insert(pair<const char*, Room*>("East" , r8));
  r12->getMap()->insert(pair<const char*, Room*>("West" , r11));
  r14->getMap()->insert(pair<const char*, Room*>("West" , r13));
  r3->getMap()->insert(pair<const char*, Room*>("South" , r1));
  r3->getMap()->insert(pair<const char*, Room*>("West" , r6));
  r6->getMap()->insert(pair<const char*, Room*>("East", r3));
  r5->getMap()->insert(pair<const char*, Room*>("South" , r1));
  r7->getMap()->insert(pair<const char*, Room*>("West" , r15));

  
  Item* Banana = new Item();
  strcpy(Banana->getName(), "Banana");
  r4->addItems(Banana);
  itemList->push_back(Banana);
  
      
  
  Item* ShackKey = new Item();
  strcpy(ShackKey->getName(), "Shack Key");
  r5->addItems(ShackKey);
  itemList->push_back(ShackKey);

  roomList->push_back(r1);
  roomList->push_back(r2);
  roomList->push_back(r3);
  roomList->push_back(r4);
  roomList->push_back(r5);
  roomList->push_back(r6);
  roomList->push_back(r7);
  roomList->push_back(r8);
  roomList->push_back(r9);
  roomList->push_back(r10);
  roomList->push_back(r11);
  roomList->push_back(r12);
  roomList->push_back(r13);
  roomList->push_back(r14);
  roomList->push_back(r15);
  
  
  
  
  
  
  
 
  
  
  
  
  //Game
  cout << "The Council of Loathing wishes to speak to you. \nHELLO, ADVENTURER. THE COUNCIL\'S MOST WANTED CRIMINAL PETER JIN HAS BEEN LOCATED IN THE DISTANT WOODS. THERE IS A 20,000 SCHEMCKLE BOUNTY ON HIS HEAD. WE MUST HAVE HIS JIN AND OUT FORMULA. RECOVER THE FORMULA AND BRING IT BACK TO US. \nType go (North, South, West or East) to go in a certain direction. Type pick up (item) to pick up an item. Type quit to quit. Type drop (item) to drop an item." << endl;

  char current[999] = "Distant Woods";
  bool game = true;
  char input[99];
  while (game == true) {
    vector<Room*>::iterator it;
    for (it = roomList->begin(); it !=roomList -> end(); ++it) {
      if (strcmp(current, (*it) ->getName()) == 0) {
	if (strcmp(current, "Win") == 0) {
	  cout<< "Congratulations, you've found the formula!" << endl;
	  game = false;
	}
	cout << "Room: " << (*it)->getName() << endl;
	cout << (*it)->getDescription() << endl;
	cout << "There are exits to your: ";
	(*it)->printMap();
	cout << "Items in the room: ";
	(*it)->printItems();
	cout << "Your inventory: ";
	inventory->printItems();
	cout << '\n' << endl;
	cin.get(input, 99);
	cin.clear();
	cin.ignore(1000, '\n');
	if (strcmp(input, "go North") == 0) {
	  strcpy(current, (*it)->getExitRoom(North)->getName());
	}
	else if (strcmp(input, "go East") == 0) {
	  strcpy(current, (*it)->getExitRoom(East)->getName());
	}
	else if (strcmp(input, "go West") == 0) {
	  strcpy(current, (*it)->getExitRoom(West)->getName());
	}
	else if (strcmp(input, "go South") == 0) {
	  strcpy(current, (*it)->getExitRoom(South)->getName());
	}
	else if (strncmp(input, "pick up ", 8) == 0) {
	  char thing[strlen(input)-8];
	  for (int a = 8; a < strlen(input); a++) {
	    thing[a-8] = input[a];
	  }
	  if (strcmp(thing, "Banana") == 0) {
	    cout << "You use this banana to throw at the Blorax" << endl;
	    r3->getMap()->insert(pair<const char*, Room*>("North" , r5));
	  }
	  if (strcmp(thing, "Shack Key") == 0) {
	    cout << "Looks like a key to a shack" << endl;
	    r2->getMap()->insert(pair<const char*, Room*>("North" , r7));
	  }
	  vector<Item*>::iterator a;
	  for (a = itemList->begin(); a != itemList->end(); ++a) {
	    if (strcmp(thing, (*a)->getName()) == 0) {
	      inventory->addItems(*a);
	    }
	  }
	  (*it)->takeItem(thing);
	}
	else if (strncmp(input, "drop ", 5) == 0) {
	  char drop[strlen(input)-5];
	  for (int b = 5; b< strlen(input); b++) {
	    drop[b-5] = input[b];
	  }
	  vector<Item*>::iterator b;
	  for (b = itemList->begin(); b != itemList->end(); ++b) {
	    if (strcmp(drop, (*b)->getName()) == 0) {
	      (*it)->addItems(*b);
	    }
	  }
	  inventory->takeItem(drop);
	}
	else if (strcmp(input, "quit") == 0) {
	  game = false;
	}
      }	  
    }
    cout << '\n' << endl;
  }







  
  
  
}



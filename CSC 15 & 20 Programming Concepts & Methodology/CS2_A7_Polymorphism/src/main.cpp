#include "Room.h"
#include "Thing.h"
#include "Item.h"
#include "Food.h"
#include "Utility.h"
#include <iostream>
using namespace std;

void ProcessInput(string text, string& cmd, string& obj);
void OneRoomGame(Room* theRoom);

int main()
{
  Thing painting("painting", "A colorful painting, depicting a vast landscape with snow-covered mountains in the distance.");
  Thing table("table", "A large wooden table, which looks very sturdy.");
  Item umbrella("umbrella", "A plain black umbrella.");
  Item notebook("notebook", "A large blue notebook, filled with notes in almost unreadable handwriting.");
  Food pie("pie", "A large apple pie, still warm from the oven.", "sweet and appley", true);
  Food cheese("cheese", "A block of super stinky cheese, with dark patches of mold throughout.", "salty and rotten", false);

  Room kitchen("Small Kitchen", "You are standing in a small kitchen. The aroma of apples and cinnamon fill the air. The room is cluttered, with numerous pots, pans, dishes and tools taking up most of the available counter space.");

  kitchen.AddThing(&painting);
  kitchen.AddThing(&umbrella);
  kitchen.AddThing(&table);
  kitchen.AddThing(&pie);
  kitchen.AddThing(&notebook);
  kitchen.AddThing(&cheese);

  OneRoomGame(&kitchen);
}

void OneRoomGame(Room* theRoom)
{
  cout << "\nWelcome to this one room game!\n";
  cout << "Commands:\n";
  cout << "L Look      T Take\n";
  cout << "X Examine   D Drop\n";
  cout << "E Eat       Q Quit\n\n";
  string input, action, target;
  theRoom->Describe();
  while (true)
    {
      cout << "\n";
      cout << "> ";
      getline(cin, input);
      ProcessInput(Utility::Lowercase(input), action, target);
      cout << "\n";
      if (action == "*UNKNOWN")
	cout << "I'm sorry, I didn't understand that.\n";
      else if (action == "quit")
	break;
      else if (action != "look" && target == "")
	{
	  cout << "I'm sorry, that doesn't make sense by itself. ";
	  cout << Utility::Capitalized(action) << " *what*?\n";
	}
      else if (action == "look")
	{
	  theRoom->Describe();
	}
      else
	{
	  if (action == "examine")
	    theRoom->ExamineThing(target);
	  else if (action == "take")
	    theRoom->TakeThing(target);
	  else if (action == "drop")
	    theRoom->DropThing(target);
	  else if (action == "eat")
	    theRoom->EatThing(target);
	}
    }
}

void ProcessInput(string text, string& cmd, string& obj)
{
  static string commands[12] = { "l", "look", "x", "examine", "t", "take", "d", "drop", "e", "eat", "q", "quit" };
  size_t space = text.find(" ");
  if (space == string::npos)
    {
      cmd = text;
      obj = "";
    }
  else
    {
      cmd = text.substr(0, space);
      obj = text.substr(space+1);
    }
  for (int i = 0; i < 12; i++)
    {
      if (cmd == commands[i])
	{
	  if (i%2 == 0)
	    cmd = commands[i+1];
	  return;
	}
    }
  cmd = "*UNKNOWN";
}

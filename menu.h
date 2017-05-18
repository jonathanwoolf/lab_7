#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"
#include <typeinfo>

using namespace std;

class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		//Base constructor to set up all necessary members
		Menu() : history_index(0) {}

		void execute() {
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			if(history.empty()) {
				cout << "0";
			}
			else {
				cout << history.at(history_index)->get_root();
			}
		};
		bool initialized() {
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
			if(typeid(history.at(0)->execute()) == typeid(double))
			{
				return true;
			}
			return false;
		};
		void add_command(Command* cmd) {
			//Adds a command to history in the appropriate posiiton (based on history_index)
			cout << "Error 1" << endl << flush;
			if(history.empty() || history_index >= int (history.size()))
			{
				history_index++;
				cout << "Error 2" << endl << flush;
				history.push_back(cmd);
			}
			else
			{
				cout << "Error 3" << endl << flush;
				history.at(history_index) = cmd;
				history_index++;
			}
		};
		Command* get_command() {
			//Returns the command in history we are currently referring to (based on history_index)
			return history.at(history_index - 1);
		};
		void undo() {
			//Moves to the last command in history (if possible)
			if(history_index > 0)
			{
				history_index--;
			}
		};
		void redo() {
			//Moves to the next command in history (if possible)
			if(history_index < int (history.size()) - 1)
			{
				history_index++;
			}
		};
};

#endif //__MENU_CLASS__

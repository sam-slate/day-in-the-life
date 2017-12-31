#ifndef OPTION_H
#define OPTION_H

#include <string>
#include <iostream>
using namespace std;

class Option {

public:

	void set_all(string name, string description, int change_pain,
			int change_spoons, int change_money, bool random,
			int random_percentage, int next_id);
	string get_name();
	string get_description();
	int get_change_pain();
	int get_change_spoons();
	int get_change_money();
	bool get_random();
	int get_random_percentage();
	int get_next_id();



private:
	string name, description;
	int change_pain, change_spoons, change_money;
	
	// If the option is random, then random is true and random_percentage
	// holds the percentage that the option will happen
	bool random;
	int random_percentage;

	//the integer id of the next Event (-1 if the end)
	int next_id;
};

#endif
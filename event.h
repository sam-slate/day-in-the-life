#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
#include "scores.h"
#include "option.h"
using namespace std;

const int MAX_OPTIONS = 10;
const int EVENTS_OVER = -1;
const int LOST = -2;

class Event {

public:
	Event();
	Event(int id, bool random, string name, 
			string message);

	void initialize_event(int id, bool random, string name, 
			string message);

	void add_option(string name, string description,
							int change_pain, int change_spoons,
							int change_money, bool random,
							int random_percentage, int next_id);

	int run_event(Scores &s);
	int get_id();



private:
	void print_message();
	void print_options();
	int get_choice();

	// Returns the integer ID of the next event (-1 if over
	// -2 if they lost)
	int process_choice(int choice, Scores &s);
	int process_random(Scores &s);

	// The number of options
	int total_num_options;

	// Unique id number for the event
	int id;
	// Whether or not the choice is random
	bool random;
	
	string name, message;

	//dynamic array of pointers to options
	Option options[MAX_OPTIONS];
};


#endif
#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <iostream>
#include "event.h"
using namespace std;

class Events {
public:
	Events();
	void read_in(ifstream &infile);
	// Returns true if game is not over, false if game is over
	bool run_events(Scores &s);

private:
	string my_getline(ifstream &infile);
	string name;
	int num_events;
	Event *events;
};

#endif
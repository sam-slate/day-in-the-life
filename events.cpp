#include <iostream>
using namespace std;

#include <string>
#include <fstream>
#include "events.h"

Events :: Events(){

}

void Events :: read_in(ifstream &infile){
	string trash;
	infile >> trash >> name >> trash >> num_events;

	//initialize array to num_events
	events = new Event[num_events];
	

	//loop through events
	for (int e_i = 0; e_i < num_events; e_i++){
		int id, num_options;
		bool random;
		string name;
		string message = "";

		infile >> trash >> id;
		infile >> trash >> random ;
		infile >> trash >> name;
		infile >> trash;
		getline(infile, message);
		getline(infile, message);

		events[e_i].initialize_event(id, random, name, message);
		infile >> trash >> num_options;

		//loop through options
		for (int o_i = 0; o_i < num_options; o_i++){
			string name, description;
			int change_pain, change_spoons, change_money, random_percentage, next_id;
			bool random;

			infile >> trash;
			getline(infile, name);
			getline(infile, name);
			infile >> trash;
			getline(infile, description);
			getline(infile, description);
			infile >> trash >> change_pain; 
			infile >> trash >> change_spoons;
			infile >> trash >> change_money;
			infile >> trash >> random;
			infile >> trash >> random_percentage;
			infile >> trash >> next_id;

			events[e_i].add_option(name, description, change_pain, change_spoons,
								change_money, random, random_percentage, next_id);
		}
	}

}

string Events :: my_getline(ifstream &infile){
	string to_return;
	char c;
	infile >> c;
	while (c != '/' and c != '*' and c != '#'){
		to_return += string(1, c);
		infile >> noskipws >> c;
	}
	return to_return;
}

bool Events :: run_events(Scores &s){
	int current_index = 0, next_id = -1;
	bool done = false;

	while(!done){
		next_id = events[current_index].run_event(s);
		if (next_id == EVENTS_OVER or next_id == LOST){
			done = true;
		} else {
			for (int i = 0; i < num_events; i++){
				if (events[i].get_id() == next_id){
					current_index = i;
					break;
				}
			}
		}
	}

	return (next_id == EVENTS_OVER);
}
#include <iostream>
using namespace std;

#include <string>
#include <stdlib.h> 
#include <time.h> 

#include "event.h"
#include "game.h"
#include <unistd.h>


Event :: Event(){

}

Event :: Event(int id, bool random, string name, 
				string message){
	this->id = id;
	this->random = random;
	this->name = name;
	this->message = message;
	this->total_num_options = 0;
}

void Event :: initialize_event(int id, bool random, string name, 
				string message){
	this->id = id;
	this->random = random;
	this->name = name;
	this->message = message;
	this->total_num_options = 0;
}

void Event :: add_option(string name, string description,
							int change_pain, int change_spoons,
							int change_money, bool random,
							int random_percentage, int next_id){

	options[total_num_options].set_all(name, 
			description, change_pain,
			change_spoons, change_money, random,
			random_percentage, next_id);
	total_num_options++;
}


int Event :: run_event(Scores &s){
	int choice = -1;
	int next_event = -1;

	if (SLEEP){sleep(2);}



	print_message();

	if (SLEEP){sleep(2);}


	if (random){
		next_event = process_random(s);
	} else {
		print_options();
		choice = get_choice();
		next_event = process_choice(choice, s);
	}


	return next_event;
}

void Event :: print_message(){
	if (message != "" and message != " "){
		cout << message << endl;
	}
}

void Event :: print_options(){
	cout << "Your options: " << endl;
	for (int i = 0; i < total_num_options; i++){
		cout << i + 1 << ") " << options[i].get_name() << endl;
	}
}

int Event :: get_choice(){
	int choice = -1;
	cout << "Type the number of your choice: ";
	cin >> choice;
	return choice - 1;
}

int Event :: process_choice(int choice, Scores &s){
	cout << options[choice].get_description() << endl << endl;
	if (SLEEP){sleep(2);}


	int change_pain = options[choice].get_change_pain();
	int change_spoons = options[choice].get_change_spoons();
	int change_money = options[choice].get_change_money();

	if (change_pain != 0){
		cout << "The change in pain tolerance is: " << change_pain << endl;
	}
	if (change_spoons != 0){
		cout << "The change in spoons is: " << change_spoons << endl;
	}
	if (change_money != 0){
		cout << "The change in money is: " << change_money << endl;
	}

	cout << endl;

	s.add_pain(change_pain);
	s.add_spoons(change_spoons);
	s.add_money(change_money);
	if (SLEEP){sleep(2);}
	s.print_scores();

	cout << endl;

	if (s.check_lost()){
		return LOST;
	}

	return options[choice].get_next_id();
}

int Event :: process_random(Scores &s){
	string trash;

	cout << "Type anything: ";
	cin >> trash;
	if (SLEEP){sleep(2);}

	srand(time(NULL));
	int rand_num = rand() % 100;

	int range = 0;
	for (int i = 0; i < total_num_options; i++){
		if (rand_num >= range and 
			rand_num <= range + options[i].get_random_percentage()){
			cout << options[i].get_name() << endl;
			return process_choice(i, s);
		} else {
			range += options[i].get_random_percentage();
		}
	}

	cout << rand_num << endl;
	return 0;
}

int Event :: get_id(){
	return id;
}







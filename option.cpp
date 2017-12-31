#include <iostream>
using namespace std;

#include <string>

#include "option.h"

void Option :: set_all(string name, string description, int change_pain,
			int change_spoons, int change_money, bool random,
			int random_percentage, int next_id){
	this->name = name;
	this->description = description;
	this->change_pain = change_pain;
	this->change_spoons = change_spoons;
	this->change_money = change_money;
	this->random = random;
	this->random_percentage = random_percentage;
	this->next_id = next_id;
}

string Option :: get_name(){
	return name;
}

string Option :: get_description(){
	return description;
}

int Option :: get_change_pain(){
	return change_pain;
}

int Option :: get_change_spoons(){
	return change_spoons;
}
int Option :: get_change_money(){
	return change_money;
}

bool Option :: get_random(){
	return random;
}

int Option :: get_random_percentage(){
	return random_percentage;
}

int Option :: get_next_id(){
	return next_id;
}










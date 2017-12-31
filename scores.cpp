#include <iostream>
using namespace std;

#include <string>

#include "scores.h"

Scores :: Scores(){

}

Scores :: Scores(int pain, int spoons, int money, bool homework){
	this->pain = pain;
	this->spoons = spoons;
	this->money = money;
	this->homework = homework;
}

void Scores :: initialize_scores(int pain, int spoons, int money, bool homework){
	this->pain = pain;
	this->spoons = spoons;
	this->money = money;
	this->homework = homework;
}

int Scores :: get_pain(){
	return pain;
}

int Scores :: get_spoons(){
	return spoons;
}

int Scores :: get_money(){
	return money;
}

bool Scores :: get_homework(){
	return homework;
}

void Scores :: print_scores(){
	cout << "Here are your scores:" << endl;
	cout << "Pain Tolerance: " << pain << endl;
	cout << "Spoons: " << spoons << endl;
	cout << "Money: " << money << endl;
}

void Scores :: add_pain(int c){
	pain += c;
}

void Scores :: add_spoons(int c){
	spoons += c;
}

void Scores :: add_money(int c){
	money += c;
}

bool Scores :: check_lost(){
	return (pain <= 0 or spoons <= 0 or money <= 0);
}




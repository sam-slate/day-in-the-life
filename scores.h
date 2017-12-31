#ifndef SCORES_H
#define SCORES_H

#include <string>
#include <iostream>
using namespace std;

class Scores {

public:
	Scores();
	Scores(int pain, int spoons, int money, bool homework);
	void initialize_scores(int pain, int spoons, int money, bool homework);
	int get_pain();
	void add_pain(int c);
	int get_spoons();
	void add_spoons(int c);
	int get_money();
	void add_money(int c);
	bool get_homework();
	void print_scores();
	bool check_lost();


private:
	int pain, spoons, money;
	bool homework;

};

#endif
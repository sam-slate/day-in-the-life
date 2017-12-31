#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include "scores.h"
#include "events.h"
using namespace std;

const int START_PAIN = 70;
const int START_SPOONS = 70;
const int START_MONEY = 70;

const int NUM_CLUSTERS = 8;

const bool SLEEP = true;

const string CLUSTERS[NUM_CLUSTERS] = {"morning_routine", "free_time", "work", "meal", "class", "moment_free_time", "small_chore", "doctor"};

class Game {
public:
	Game();
	void run_game();

private:
	void read_in();
	void print_initial_message();
	void start();
	void won();
	void lost();
	void learn_more();

	Scores scores;
	Events clusters[NUM_CLUSTERS];

};

#endif
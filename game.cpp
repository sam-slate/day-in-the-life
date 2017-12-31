#include <string>
#include <iostream>
#include <fstream>
#include <time.h> 
#include <unistd.h>
#include "game.h"
using namespace std;

Game :: Game(){
	scores.initialize_scores(START_PAIN, START_SPOONS, START_MONEY, false);
}

void Game :: run_game(){
	read_in();
	print_initial_message();
	start();

}

void Game :: read_in(){
	string filename = "";

	for (int i = 0; i < NUM_CLUSTERS; i++){
		filename = CLUSTERS[i] + ".txt";
		ifstream infile;
		infile.open(filename.c_str());

		clusters[i].read_in(infile);
	}
}

void Game :: print_initial_message(){
	cout << "Hello! Welcome to this little text-based, choose-your-own-adventure game! Playing this game will hopefully give you a sense of what it is like to live a day in the life of someone with an invisible physical disability at Tufts University, based on my (Sam Slate’s) own experiences.";
	cout << endl << endl;
	if (SLEEP){sleep(8);}
	cout << "The goal is easy: make it through the day. You will be given a series of events and options as to how to proceed. Each decision influences your next option, so choose wisely!";
	cout << endl << endl;
	if (SLEEP){sleep(8);}
	cout << "Here’s the tricky part. At the start of the day, you are given points in three areas: pain tolerance, spoons, and money (explained below). Each decision you make will either add or detract from any of these three areas. If you get to 0 or below on any of the areas, you lose!";
	cout << endl << endl;
	if (SLEEP){sleep(8);}
	cout << "Pain tolerance: " << scores.get_pain() << endl;
	cout << "    This is the measure of your ability to tolerate pain. The more pain you experience, the lower your pain tolerance.";
	cout << endl;
	if (SLEEP){sleep(8);}
	cout << "Spoons: " << scores.get_spoons() << endl;
	cout << "    This is the measure of your energy and motivation. You only have so much in a day!";
	cout << endl;
	if (SLEEP){sleep(8);}
	cout << "Money: " << scores.get_money() << endl;
	cout << "    This is how much money you have for the day. Spend it wisely :)";
	cout << endl << endl;
	if (SLEEP){sleep(8);}

	cout << "Ready to begin? (y/n)" << endl;

	char response = ' ';
	cin >> response;
	if (response == 'y' or response == 'Y'){
		cout << "Let's go!!" << endl;
	} else {
		cout << "Then why are you here . . ." << endl;
	}
}

void Game :: start(){

	int order[11] = {0, 4, 1, 3, 2, 5, 7, 4, 3, 4, 6};

	for (int i = 0; i < 11; i++){
		if (!clusters[order[i]].run_events(scores)){
			lost();
			return;
		}
	}
	won();
	return;

}

void Game :: won(){
	cout << "Congratulations, you made it through the day! I bet it wasn't easy!" << endl;
	learn_more();
}

void Game :: learn_more(){
	char response = ' ';

	if (SLEEP){sleep(2);}
	cout << "Thank you so very much for playing. I hope you have learned something!\n\n";
	if (SLEEP){sleep(2);}
	cout << "Would you like to play the game again? (g) Or, would you like to learn more about the inspiration for this game? (y/n)" << endl;
	cout << "Input: ";
	cin >> response;
	if (response == 'y' or response == 'Y'){
		cout << "Great!" << endl;
		if (SLEEP){sleep(2);}
		cout << "As mentioned earlier, this game simulates what it is like to live a day in the life of someone with an invisible physical disability at Tufts University. All of the situations presented are pulled from my lived experiences as a disabled student, and the tradeoffs and decisions and balancing acts you had to deal with are the same that I deal with every moment of every day.\n\n";
		if (SLEEP){sleep(12);}
		cout << "Some days are easier and some days are harder. Some days I make it through, some days I don’t. Most day I have moments of giving up and moments of strength and nearly every day I am thankful to be living and breathing at the very least.\n\n";
		if (SLEEP){sleep(12);}
		cout << "The tricky part is that disability does not exist in a vacuum. Other things go wrong, there are other pains in your life, you get sick, tired, upset, angry, and everything in between. Disability is just there making all the little things harder.\n\n";
		if (SLEEP){sleep(12);}
		cout << "If you feel like all these little decision I showed you are hard, in reality there are five times as many that I wasn’t able to put down. When my pain is bad, which is most days, I can never not think about the things I can and cannot do. I am my pain. I am these decisions.\n\n";
		if (SLEEP){sleep(12);}
 		cout << "And I know, in the back of my mind, that all those folks I see around me who get through the day with ease, who never have to think about the things that I think about, I know that someday something will give.\n\n";
 		if (SLEEP){sleep(10);}
 		cout << "We are all temporarily able.\n\n";
 		if (SLEEP){sleep(5);}
 		cout << "You will have to fight this fight.\n\n";
 		if (SLEEP){sleep(5);}
 		cout << "You will have to live my life.\n\n";
 		if (SLEEP){sleep(5);}
 		cout << "And you will know, then, the strength it takes to carry on.\n";
 		if (SLEEP){sleep(5);}

	} else if (response == 'g' or response == 'G'){
		cout << "Alright, have fun!";
		scores.initialize_scores(START_PAIN, START_SPOONS, START_MONEY, false);
		run_game();
	}
}

void Game :: lost(){
	//check what made you lose
	if (scores.get_pain() <= 0){
		cout << "Looks like you felt too much pain :( You'll need to space out how you use your body next time around. The key is to save pain tolerance for the more demanding actions later in the day.\n\n";
	} else if (scores.get_money() <= 0){
		cout << "Uh-oh, you ran out of money! You can't spend like crazy to protect your body, even if you'd like to.\n\n";
	} else {
		cout << "Your spoons seem to be compeletely gone :( You've exhausted yourself trying to compensate for your body through taking on mental and emotional labor.\n\n";
	}

	learn_more();
}


# Day in the Life
A text-based, choose-your-own-adventure game describing a day in in the life of someone with a physical disability.

## About

This game was created for a class on disability studies to demonstrate the difficulties of having an invisible physical disablity at Tufts University. 

I chose to use basic C++ classes with few added libraries in order to better help the students I was TAing with their assignments. This limits the code in terms of how dynamic it can be but makes the classes simpler and easy to understand.

I started from scratch in building the framework of a choose-your-own-adventure game. Since I wanted to be able to change the gameplay easily, I built out an abstract framework that can read in from information files the events and choices central the game. These information files are the .txt files.

## Setup

To set up on your computer, first download the ZIP of all of the files by clicking the green "Clone or download" button on the top right and selecting "Download ZIP"

Once downloaded, navigate to the downloaded file in terminal and run the following commands:

`clang++ driver.cpp events.cpp event.cpp game.cpp option.cpp scores.cpp`

`./a.out`

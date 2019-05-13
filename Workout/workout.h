#pragma once

#include <fstream>
#include <random>
#include <ctime>
#include <string>
#include <iostream>

/*
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;
*/

struct Workout
{
private:
	//int p0 = 0;
	int s0 = 0;
	int c0 = 0;
	int a0 = 0;
	int ca0 = 0;
	std::string primary[3] = {"Deadlift", "Squats", "Press"};
	std::string secondary[5] = {"Bent Over Rows", "Curls & Triceps", "Cleans", "Kettle Bell Swings", "Bench"};
	std::string core[12] = { "Situps", "Toes to Bar", "Russian Twists", "Wall Throws", "Crunches", "Mtn Climbers", "Leg Lifts" , "Planks" , "GHD Sit Ups", "Back Extentions", "Horizontal WoodChop", "Spiderman Climb"};
	std::string auxilary[10] = { "Pull Ups", "Push Ups", "Dips", "Row Ups", "Flies", "Step Ups", "Box Jump", "Hand Stand Push Up", "Muscle Up", "Wall Balls"};
	std::string cardio[5] = {"Sprints", "Mile", "Bike", "Row", "Nothing"};
	std::string workout[7];
	int reps[7];
	int plen = sizeof(primary) / sizeof(*primary);
	int slen = sizeof(secondary) / sizeof(*secondary);
	int clen = sizeof(core) / sizeof(*core);
	int alen = sizeof(auxilary) / sizeof(*auxilary);
	int calen = sizeof(cardio) / sizeof(*cardio);

	std::random_device re;
	std::random_device rd;
	int s;

	void gen(); 
	void gen2(int i);
	void publish(int);

public:
	Workout();
};
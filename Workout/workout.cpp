#include "workout.h"

Workout::Workout()
{
	
	srand(time(NULL));
	for (int i = 1; i <= 6; i++)
	{
		if (i % 3 == 0)
			workout[0] = primary[0];
		if (i % 3 == 1)
			workout[0] = primary[1];
		if (i % 3 == 2)
			workout[0] = primary[2];
		gen();
		gen2(i);
		publish(i);
	}
}

void Workout::gen()
{

	srand(time(NULL));
	//int p = rand() % 3;
	int s = rand() % (slen - 1);
	int c = 0;
	//int c = rand() % (clen - 1);
	int a = rand() % (alen - 1);
	int ca = rand() % (calen - 1);
check_s:
	if (s0 == s)
	{
		s = rand() % (slen - 1);
		goto check_s;
	}
check_c:
	if (c == c0)
	{
		c = rand() % (clen - 1);
		goto check_c;
	}
check_a:
	if (a == a0)
	{
		a = rand() % (alen - 1);
		goto check_a;
	}
check_ca:
	if (ca == ca0)
	{
		ca = rand() % (calen - 1);
		goto check_ca;
	}

	s0 = s;
	c0 = c;
	a0 = a;
	ca0 = ca;
	//workout[0] = primary[p];
	workout[1] = secondary[s];
	workout[2] = core[c];
	workout[3] = auxilary[a];
	workout[4] = cardio[ca];
}

void Workout::gen2(int i) {
	std::uniform_int_distribution <int> numReps(2,5);
//	std::uniform_int_distribution <int> dist(1, 7);
	std::uniform_int_distribution <int> coreDist(1, 16);

	if (i % 3 == 0 || i % 3 == 1) { // Deadlift & Squats
//		s = dist(re);
		// SECONDARY
		// Deadlift & Squats 
		/*
		switch (s) {
		case 1: // Bent Over Rows
			workout[1] = secondary[0];
		case 2: // Curls & Triceps
			workout[1] = secondary[1];
		case 3: // KB Swings
			workout[1] = secondary[3];
		case 4: // Bench
			workout[1] = secondary[4];
		case 5: // Curls & Triceps
			workout[1] = secondary[1];
		case 6: // Bent Over Rows
			workout[1] = secondary[0];
		case 7: // Bench
			workout[1] = secondary[4];
		default: // Bent Over Rows
			workout[1] = secondary[0];
		} */
		reps[1] = numReps(rd);
		s = coreDist(re);
		// AUXILARY
		// Deadlift & Squats
		switch (s) {
		case 1: // Pull Ups
			workout[5] = auxilary[0];
		case 2: // P5sh Ups
			workout[5] = auxilary[1];
		case 3:// Di5s
			workout[5] = auxilary[2];
		case 4: // R5w Ups
			workout[5] = auxilary[3];
		case 5: // F5ies
			workout[5] = auxilary[4];
		case 6: // P5ll Ups
			workout[5] = auxilary[0];
		case 7: // R5w Ups
			workout[5] = auxilary[3];
		case 8: // M5scle Ups
			workout[5] = auxilary[8];
		case 9: // H5nd Stand Push Ups
			workout[5] = auxilary[7];
		case 10:// W5ll Balls
			workout[5] = auxilary[9];
		case 11: // 5all Balls
			workout[5] = auxilary[9];
		case 12: // 5lies
			workout[5] = auxilary[4];
		case 13: // 5ull Ups
			workout[5] = auxilary[0];
		case 14: // 5ow Ups
			workout[5] = auxilary[3];
		case 15: // 5ush Ups
			workout[5] = auxilary[1];
		case 16: // 5ips
			workout[5] = auxilary[2];
		default: // 5ow Ups
			workout[5] = auxilary[3];
		}
		reps[3] = numReps(rd);
		s = coreDist(re);
		// CORE
		switch (s) {
		case 1: // Situps
			workout[6] = core[0];
		case 2: // R6ssian Twists
			workout[6] = core[2];
		case 3: // P6anks
			workout[6] = core[7];
		case 4: // T6es To Bar
			workout[6] = core[1];
		case 5: // W6ll Throws
			workout[6] = core[3];
		case 6: // C6unches
			workout[6] = core[4];
		case 7: // M6n Climbers
			workout[6] = core[5];
		case 8: // L6g Lifts
			workout[6] = core[6];
		case 9: // G6D Situps
			workout[6] = core[8];
		case 10:// B6ck Extentions
			workout[6] = core[9];
		case 11: // 6ack Extnetions
			workout[6] = core[9];
		case 12: // 6HD Situps
			workout[6] = core[8];
		case 13: // 6oes To Bar
			workout[6] = core[1];
		case 14: // 6lanks
			workout[6] = core[7];
		case 15: // 6ussian Twists
			workout[6] = core[2];
		case 16: // 6itups
			workout[6] = core[0];
		default: // Planks
			workout[6] = core[7];
		}
		reps[2] = numReps(rd);
	//	s = dist(re);
		// CARDIO
		/*s
		witch (s) {
		case 1: // Nothing
			workout[4] = cardio[4];
		case 2: // Nothing
			workout[4] = cardio[4];
		case 3:// Nothing
			workout[4] = cardio[4];
		case 4: // Sprints
			workout[4] = cardio[0];
		case 5: // Mile
			workout[4] = cardio[1];
		case 6: // Row
			workout[4] = cardio[2];
		case 7: // Bike
			workout[4] = cardio[3];
		default: // Nothing
			workout[4] = cardio[4];
		} */
	}
	else if (i % 3 == 2) { // Press
	//	s = dist(re);
		// SECONDARY
		// Press
		/*
		switch (s) {
		case 1: // Bent Over Rows
			workout[1] = secondary[0];
		case 2: // Curls & Triceps
			workout[1] = secondary[1];
		case 3: // KB Swings
			workout[1] = secondary[3];
		case 4: // Cleans
			workout[1] = secondary[2];
		case 5: // Curls & Triceps
			workout[1] = secondary[1];
		case 6: // Bent Over Rows
			workout[1] = secondary[0];
		case 7: // Cleans
			workout[1] = secondary[2];
		} */
		reps[1] = numReps(rd);
		s = coreDist(re);
		// AUXILARY
		// Press
		switch (s) {
		case 1: // Step Ups
			workout[5] = auxilary[5];
		case 2: // B5x Jumps
			workout[5] = auxilary[6];
		case 3: // W5ll Balls
			workout[5] = auxilary[9];
		case 4: // P5ll Ups
			workout[5] = auxilary[0];
		case 5: // D5ps
			workout[5] = auxilary[2];
		case 6: // S5ep Ups
			workout[5] = auxilary[5];
		case 7: // B5x Jumps 
			workout[5] = auxilary[6];
		case 8: // W5ll Balls
			workout[5] = auxilary[9];
		case 9: // P5sh Ups
			workout[5] = auxilary[1];
		case 10: // 5tep Ups
			workout[5] = auxilary[5];
		case 11: // 5ox Jumps
			workout[5] = auxilary[6];
		case 12: // 5all Balls
			workout[5] = auxilary[9];
		case 13: // 5lies
			workout[5] = auxilary[4];
		case 14: // 5ush Ups
			workout[5] = auxilary[1];
		case 15: // 5ull Ups
			workout[5] = auxilary[0];
		case 16: // 5tep Ups
			workout[5] = auxilary[5];
		}
		reps[3] = numReps(rd);
		s = coreDist(re);
		// CORE
		switch (s) {
		case 1: // Situps
			workout[6] = core[0];
		case 2: // R6ssian Twists
			workout[6] = core[2];
		case 3: // P6anks
			workout[6] = core[7];
		case 4: // T6es To Bar
			workout[6] = core[1];
		case 5: // W6ll Throws
			workout[6] = core[3];
		case 6: // C6unches
			workout[6] = core[4];
		case 7: // M6n Climbers
			workout[6] = core[5];
		case 8: // L6g Lifts
			workout[6] = core[6];
		case 9: // G6D Situps
			workout[6] = core[8];
		case 10:// B6ck Extentions
			workout[6] = core[9];
		case 11: // 6ack Extnetions
			workout[6] = core[9];
		case 12: // 6HD Situps
			workout[6] = core[8];
		case 13: // 6oes To Bar
			workout[6] = core[1];
		case 14: // 6lanks
			workout[6] = core[7];
		case 15: // 6ussian Twists
			workout[6] = core[2];
		case 16: // 6itups
			workout[6] = core[0];
		default: // 6lanks
			workout[6] = core[7];
		}
//		s = dist(re);
		// CARDIO
		/*
		switch (s) {
		case 1: // Nothing
			workout[4] = cardio[4];
		case 2: // Nothing
			workout[4] = cardio[4];
		case 3:// Nothing
			workout[4] = cardio[4];
		case 4: // Sprints
			workout[4] = cardio[0];
		case 5: // Mile
			workout[4] = cardio[1];
		case 6: // Row
			workout[4] = cardio[2];
		case 7: // Bike
			workout[4] = cardio[3];
		default: // Nothing
			workout[4] = cardio[4];
		} */
	}
	else {
		std::cout << "Failed" << std::endl;
		workout[1] = secondary[0];
		workout[2] = core[7];
		workout[3] = auxilary[5];
		workout[4] = cardio[4];
	}

}

void Workout::publish(int num)
{
	std::ofstream f;
	std::string file = "C:\\Users\\Josh Chica\\Desktop\\Workout.txt";
	f.open(file, std::ios::app);
	if (f.is_open())
	{
		if (num != 1)
			f << "\n";
		f << "Day ";
		f << num;
		f << ":\n";
		f << "Primary Lift: ";
		f << workout[0];
		f << " |";
		f << "\t";
		f << "Secondary Lift: ";
		f << workout[1];
		f << " for ";
		f << reps[1] * 5;
		f << " reps |";
		f << "\t";
		f << "Core: ";
		f << workout[2];
		f << " & ";
		f << workout[6];
		f << " for ";
		f << reps[2] * 5;
		f << " reps |";
		f << "\t";
		f << "Auxilary Lifts: ";
		f << workout[3];
		f << " & ";
		f << workout[5];
		f << " for ";
		f << reps[3] * 5;
		f << " reps |";
		f << "\t";
		f << "Cardio: ";
		f << workout[4];
		f << "\n\n";
		f.close();
	}
}

/*
s = dist(re);
// SECONDARY
// Deadlift & Squats
switch (s) {
case 1: // Bent Over Rows
	workout[1] = secondary[0];
case 2: // Curls & Triceps
	workout[1] = secondary[1];
case 3: // KB Swings
	workout[1] = secondary[3];
case 4: // Bench
	workout[1] = secondary[4];
case 5: // Curls & Triceps
	workout[1] = secondary[1];
case 6: // Bent Over Rows
	workout[1] = secondary[0];
case 7: // Bench
	workout[1] = secondary[4];
}
// Press
switch (s) {
case 1: // Bent Over Rows
	workout[1] = secondary[0];
case 2: // Curls & Triceps
	workout[1] = secondary[1];
case 3: // KB Swings
	workout[1] = secondary[3];
case 4: // Cleans
	workout[1] = secondary[2];
case 5: // Curls & Triceps
	workout[1] = secondary[1];
case 6: // Bent Over Rows
	workout[1] = secondary[0];
case 7: // Cleans
	workout[1] = secondary[2];
}

s = coreDist(re);
// AUXILARY
// Deadlift & Squats
switch (s) {
case 1: // Pull Ups
	workout[3] = auxilary[0];
case 2: // Push Ups
	workout[3] = auxilary[1];
case 3:// Dips
	workout[3] = auxilary[2];
case 4: // Row Ups
	workout[3] = auxilary[3];
case 5: // Flies
	workout[3] = auxilary[4];
case 6: // Pull Ups
	workout[3] = auxilary[0];
case 7: // Row Ups
	workout[3] = auxilary[3];
case 8: // Muscle Ups
	workout[3] = auxilary[8];
case 9: // Hand Stand Push Ups
	workout[3] = auxilary[7];
case 10:// Wall Balls
	workout[3] = auxilary[9];
case 11: // Wall Balls
	workout[3] = auxilary[9];
case 12: // Flies
	workout[3] = auxilary[4];
case 13: // Pull Ups
	workout[3] = auxilary[0];
case 14: // Row Ups
	workout[3] = auxilary[3];
case 15: // Push Ups
	workout[3] = auxilary[1];
case 16: // Dips
	workout[3] = auxilary[2];
}
// Press
switch (s) {
case 1: // Step Ups
	workout[3] = auxilary[5];
case 2: // Box Jumps
	workout[3] = auxilary[6];
case 3: // Wall Balls
	workout[3] = auxilary[9];
case 4: // Pull Ups
	workout[3] = auxilary[0];
case 5: // Dips
	workout[3] = auxilary[2];
case 6: // Step Ups
	workout[3] = auxilary[5];
case 7: // Box Jumps 
	workout[3] = auxilary[6];
case 8: // Wall Balls
	workout[3] = auxilary[9];
case 9: // Push Ups
	workout[3] = auxilary[1];
case 10: // Step Ups
	workout[3] = auxilary[5];
case 11: // Box Jumps
	workout[3] = auxilary[6];
case 12: // Wall Balls
	workout[3] = auxilary[9];
case 13: // Flies
	workout[3] = auxilary[4];
case 14: // Push Ups
	workout[3] = auxilary[1];
case 15: // Pull Ups
	workout[3] = auxilary[0];
case 16: // Step Ups
	workout[3] = auxilary[5];
}

s = coreDist(re);
// CORE
switch (s) {
case 1: // Situps
	workout[2] = core[0];
case 2: // Russian Twists
	workout[2] = core[2];
case 3:// Planks
	workout[2] = core[7];
case 4: // Toes To Bar
	workout[2] = core[1];
case 5: // Wall Throws
	workout[2] = core[3];
case 6: // Crunches
	workout[2] = core[4];
case 7: // Mtn Climbers
	workout[2] = core[5];
case 8: // Leg Lifts
	workout[2] = core[6];
case 9: // GHD Situps
	workout[2] = core[8];
case 10:// Back Extentions
	workout[2] = core[9];
case 11: // Back Extnetions
	workout[2] = core[9];
case 12: // GHD Situps
	workout[2] = core[8];
case 13: // Toes To Bar
	workout[2] = core[1];
case 14: // Planks
	workout[2] = core[7];
case 15: // Russian Twists
	workout[2] = core[2];
case 16: // Situps
	workout[2] = core[0];
}

s = dist(re);
// CARDIO
switch (s) {
case 1: // Nothing
	workout[3] = cardio[4];
case 2: // Nothing
	workout[3] = cardio[4];
case 3:// Nothing
	workout[3] = cardio[4];
case 4: // Sprints
	workout[3] = cardio[0];
case 5: // Mile
	workout[3] = cardio[1];
case 6: // Row
	workout[3] = cardio[2];
case 7: // Bike
	workout[3] = cardio[3];
} */
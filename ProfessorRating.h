//This is a class specification file for ProfessorRating.h
//Version 1

#ifndef PROFESSORRATING_H
#define PROFESSORRATING_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//global variable
const int NUM_PROFESSORS = 5;

//ProfessorRating class declaration
class ProfessorRating
{
public:
	string profName;	// holds professor name
	int easiness;		// easiness rating
	int helpfulness;	// helpfulness rating
	int friendliness;	// friendliness rating
	int clarity;		// clarity rating

public:
	// constructor (default)
	ProfessorRating()
	{};

	// constructor #2
	ProfessorRating(string name, int easy, int help, int friendly, int clear):
		profName(name), easiness(easy), helpfulness(help), friendliness(friendly), clarity(clear)
	{
	}


//************************************************************
// accessor(getter) function that returns the average rating *
//************************************************************
	double calcRating()
	{
		double average;
		average = ((easiness + helpfulness + friendliness + clarity) / 4.0);
		return average;
	}


//*******************************************************************************
// mutator(setter) function that displays the professor name and his/her rating *
// includes output formatting                                                   *
//*******************************************************************************
	void print()
	{
		cout << "Professor Individual Ratings" << endl;
		cout << "Name" << setw(25)
			<< "Easiness" << setw(16)
			<< "Helpfulness" << setw(17)
			<< "Friendliness" << setw(13)
			<< "Clarity" << setw(20)
			<< "Average Rating" << endl;
	}


//************************************************************************************
// mutator(setter) function that assigns parameter value to each private data member *
//************************************************************************************
	void setData(string name, int easy, int help, int friendly, int clear)
	{
		profName = name;
		easiness = easy;
		helpfulness = help;
		friendliness = friendly;
		clarity = clear;
	}

};
#endif

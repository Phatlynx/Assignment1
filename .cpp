// *****************************************************************************************
// Author: Cheng Chun Hsieh
//
// Program Assignment 1: Professor Rating - This program evaluates 5 professors to 
// see which professor has the highest rating according to student input. These ratings 
// are used to evaluate Easiness, Helpfulness, Friendliness, and Clarity. It also displays 
// the average ratings for each professor by highest and lowest.
// Version: 1
//
// *****************************************************************************************

#include <iostream>
#include <vector>
#include "ProfessorRating.h"
using namespace std;


// function prototypes
void fillProfList(vector<ProfessorRating>);
int getRating(string);
void displayHighestandLowestRating(vector<ProfessorRating>);
void displayAverageRating(vector<ProfessorRating>);


ProfessorRating profRatings; // ProfessorRatings object

int main()
{
	vector<ProfessorRating>csProfs(NUM_PROFESSORS);

// INPUT SECTION
	fillProfList(csProfs);

// PROCESSING SECTION

// OUTPUT SECTION
	
	displayHighestandLowestRating(csProfs);
	profRatings.print();
	displayAverageRating(csProfs);

}

//**********************************************************************************
// function definition - prompts user to populate professor names in the vector *
//**********************************************************************************
void fillProfList(vector<ProfessorRating>profList)
{
	string name;
	int easy, help, friendly, clarity;

	for (int count = 0; count < NUM_PROFESSORS; count++)
	{
		cout << "Enter the name of the Professor: ";
		getline(cin, name);
		easy = getRating("Easiness");
		help = getRating("Helpfulness");
		friendly = getRating("Friendliness");
		clarity = getRating("Clarity");
		cin.ignore();
	}
}
//***************************************************************************************
// function definition - prompts user for each professor rating based on rating type *
//***************************************************************************************
int getRating(string ratingType)
{
	int rating;

	cout << "Enter the " << ratingType << " between 1 to 5, with 1 being the lowest and 5 being the highest: ";
		cin >> rating;

		// input validation
		while (rating <= 0 || rating >= 6)
		{
			cout << "Invalid rating, please enter a number between 1 to 5: ";
			cin >> rating;
		}

		return rating;
}
//*****************************************************************************************************
// function definition - displays the highest and lowest average rated professor and their ratings *
//*****************************************************************************************************
void displayHighestandLowestRating(vector<ProfessorRating>profList)
{
	double highestAvg = 0;
	double lowestAvg = 0;

	double highestProf = profList.at(0).calcRating();
	double lowestProf = profList.at(0).calcRating();

	for (int index = 0; index < NUM_PROFESSORS; index++)
	{

		if (highestAvg < profList.at(index).calcRating())
		{
			highestProf = profList.at(index).calcRating();
			highestAvg = index;
		}

		if (lowestAvg > profList.at(index).calcRating())
		{
			lowestProf = profList.at(index).calcRating();
			lowestAvg = index;
		}
	}


		cout << "\n\nProfessor with highest average rating: " << endl;
		cout << "Name: " << profList.at(0).profName << endl;
		cout << "Easiness: " << profList.at(1).easiness << endl;
		cout << "Helpfulness: " << profList.at(2).helpfulness << endl;
		cout << "Friendliness: " << profList.at(3).friendliness << endl;
		cout << "Clarity: " << profList.at(4).clarity << endl;
		cout << "Average Rating: " << highestProf << endl;

		cout << "\n------------------------------------------------------------" << endl;

		cout << "Professor with lowest average rating: " << endl;
		cout << "Name: " << profList.at(0).profName << endl;
		cout << "Easiness: " << profList.at(1).easiness << endl;
		cout << "Helpfulness: " << profList.at(2).helpfulness << endl;
		cout << "Friendliness: " << profList.at(3).friendliness << endl;
		cout << "Clarity: " << profList.at(4).clarity << endl;
		cout << "Average Rating: " << lowestProf <<endl;

		cout << "\n------------------------------------------------------------" << endl;
	
}
//************************************************************************************************************
// function definition - displays the average of ALL ratings of the professors using the calcRating function *
//************************************************************************************************************
	void displayAverageRating(vector<ProfessorRating>profList)
	{
		
		for (int index = 0; index < NUM_PROFESSORS; index++)
		{
			cout << profList.at(index).calcRating() << endl;
		}
		for (int count = 0; count < NUM_PROFESSORS; count++)
		{
			cout << profList.at(count).profName << setw(25)
				<< profList.at(count).easiness << setw(16)
				<< profList.at(count).helpfulness << setw(17)
				<< profList.at(count).friendliness << setw(13)
				<< profList.at(count).clarity << setw(20)
				<< fixed << showpoint << setprecision(2) << profList.at(count).calcRating() << endl;
		}

		cout << "------------------------------------------------------------" << endl;
	}


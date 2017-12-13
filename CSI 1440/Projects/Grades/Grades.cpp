/*************************************************************
 File name:			Grades.cpp
 Author:			Glen Newell
 Discription:		Used to open a file that contains 
 				names and grades. Caculates class 
 				average,Highest, &lowest class score, and
 				student average.
 
 File Modifide:	20060927
 		-File Created
 		-opens student.dat *string file name*
 		-opens first sutdents data

 File Modifide: 20060928
		-Created loop for high test scores, low test score,
		 and to find average of student!!!
		-Created a loop to open student files over and over
		 and read in new data!!!!
		-Create eqautions to caculate sum, avg, avgsum, and
		 class average!!
		-Program completed
 
***************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
 
int main()
{
	//defins double to use in program
	double number, sum, avg, high, low, loopCount, studentCount, 
	avgsum, classavg, tests;
	
	//defines strings to use in program
	string inputF, lastName, firstName, middleInitial, 
		fileName, scores;
	
	//defines high,low, sum,loopCount, studentCount, avg, avgsum
	high = 0;
	low = 100;
	studentCount = 0;
	loopCount = 0;
	sum = 0;
	avg = 0;
	avgsum = 0;

	//ask for string name to define file
	cout << "Input name of file:";
		cin >> inputF;

	//open's file 	
	ifstream inFile;
	inFile.open(inputF.c_str());

	//checks to see if file opens
		if (!inFile)
		{ cout << "No File Found!";
 			return 0;
		}
 	else
	
	//Inputs string as students filename
	while(inFile >> lastName >> firstName >> middleInitial)
	{
		fileName = firstName+lastName+".dat";
 		inFile.clear();

 	//opens student file
 	ifstream nameFile;
 	nameFile.open(fileName.c_str());
 		
	//checks to see if student file opens
 	if (!nameFile)
 		{ 
			cout << "Error opening file.\n";
		}	
 	
	//outputs students name
	 else
		cout << endl << "Student: " << firstName << " " 
			<< middleInitial << " "<< lastName << endl 
			<< "Test Scores: ";

	//defines loopCount and tests
	 loopCount = 0;
	 tests = 0;

	//this loop finds the high & low test scores
	 while(nameFile >> number)
		{	//caculates sum
			sum += number;
			cout << fixed << setprecision(2) << number 
				<< " ";

	//checks for high
	if(number >= high)
		{
			high = number;
		}
	//checks for low	
	else if(number <= low)
		{
			low = number;
		}
	//else for loop count and test count	
	else
		loopCount ++;
		tests ++;
	 }
	
	//Caculates average
	avg = sum/tests;

	//Adds averages together
	avgsum += avg;

	//Resets sum and loopCount
	sum =0;
	loopCount=0;

	//Displays students average
	cout << endl <<"Average: " << avg << endl;
		studentCount ++;
		}
	
	//Eqaution to find class average
	classavg = avgsum/studentCount;

	//Displays class average
	cout << endl << "The class average is: " << classavg << endl;

	//Changes precision for high and low score and Displays scores
	cout << fixed << setprecision(0);
	cout <<"The Highest score is: " << high << endl;
	cout << "The Lowest score is: " << low << endl;
	return 0;
}

 


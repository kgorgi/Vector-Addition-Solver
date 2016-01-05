//***********************************************************
//* VectorAddition.cpp Created By Kian Gorgichuk			*
//* Copyright (c) 2015 Kian Gorgichuk. All rights reserved. *
//***********************************************************

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Vector.cpp"

using namespace std;

bool validValue(string str);

int main()
{
	//Set Command Prompt Size
	system("mode 100,40"); 
	
	//Loop back program in order to do multiple calculations
	bool exitProgram = false;
	do 
	{
		//Initialize 
		int i = 0;
		int j = 0;
		
		system("CLS");
		cout << "************************************************************" << endl;
		cout << "*           Welcome to the Vector Addition Solver          *" << endl;
		cout << "*                 Created By Kian Gorgichuk                *" << endl;
		cout << "*                      Version 1.2.0                       *" << endl;
		cout << "************************************************************" << endl;
		
		//User Enters Amount of Vectors To Add
		cout << "\nPlease enter the amount of vectors you would like to add: ";
		cin >> i;
		cout << endl;
		
		//Create Vectors
		Vector** VectorArray = new Vector*[i];
		
		while(i != Vector::getTotalVectors())
		{
			string tempMag;
			string tempDir;
			cout << "Please enter the magnitude for Vector " << j + 1<< ": ";
			cin >> tempMag;
			cout << "Please enter the direction for Vector "<< j + 1 << " in degrees: ";
			cin >> tempDir;
			cout << endl;
			
			double mag = strtod(tempMag.c_str(), NULL);
			double dir = strtod(tempDir.c_str(), NULL);
			
			VectorArray[j] = new Vector(mag, dir);
			
			delete &tempMag;
			delete &tempDir;
			mag = 0;
			dir = 0;
			j++;
		}	
		
		//Add Vectors
		j = 0;
		Vector *answerVector = new Vector();
		while(i != j)
		{
			*answerVector = *answerVector + *VectorArray[j];
			j++;
		}
			
		
		cout << "The Answer is: "<< *answerVector << endl;
		
		//Clean Up
		for(int k = 0; k < i; k++)
		{
			delete VectorArray[k];
		}
		
		delete[] VectorArray;
		delete answerVector;
		i = 0;
		j = 0;
		
		string c;
		//Ask If User Would Like To Do Another Calculation 
		cout << "\nWould You Like To Do Another Calculation (Y/N): ";
		cin >> c;
		while(!validValue(c))
		{
			cout << "Would You Like To Do Another Calculation (Y/N): ";
			cin >> c;
		}
		if(c.compare("Y") == 0)
			exitProgram = false;
		else if(c.compare("y") == 0)
			exitProgram = false;
		else
			exitProgram = true;
		
		delete &c;
	} while (exitProgram == false);
		
	return EXIT_SUCCESS;
}

//Determines if user enters valid value in a yes or no question
bool validValue(string str)
{
	if(str.compare("Y") == 0)
		return true;
	else if(str.compare("y") == 0)
		return true;
	else if(str.compare("N") == 0)
		return true;
	else if(str.compare("n") == 0)
		return true;
	return false;
}

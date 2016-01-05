//***********************************************************
//* Vector.cpp Created By Kian Gorgichuk                    *
//* Copyright (c) 2014 Kian Gorgichuk. All rights reserved. *
//***********************************************************

#ifndef VECTOR_CLASS
#define VECTOR_CLASS

#include <math.h>
#include <stdlib.h>
#include "Vector.h"

//Constructors & Destructor

Vector :: Vector()
{
	_totalVectors++;
}

Vector :: Vector(double magnitude, double direction)
{
	setMagnitude(magnitude);
	setDirection(direction);
	_totalVectors++;
}

Vector :: ~Vector()
{
	_totalVectors--;
	_magnitude = 0; 
	_directionRad = 0;
	_directionDeg = 0;
}

//Setters
void Vector :: setMagnitude(double magnitude)
{
	_magnitude = magnitude;
}

void Vector :: setDirection(double direction)
{
	_directionDeg = direction;
	_directionRad = direction * M_PI / 180;
}

//Getters
double Vector :: getMagnitude()
{
	return _magnitude;
}

double Vector :: getDirectionRad()
{
	return _directionRad;
}
double Vector :: getDirectionDeg()
{
	return _directionDeg;
}

double Vector :: getXComponent()
{
	if((_directionDeg == 90) || (_directionDeg == 270))
		return 0;
	else if(_directionDeg == 0)
		return _magnitude;
	else if(_directionDeg == 180)
		return _magnitude * -1;
	else
		return _magnitude * cos(_directionRad);
}

double Vector :: getYComponent()
{
	if((_directionDeg == 0) || (_directionDeg == 180 ))
		return 0;
	else if(_directionDeg == 90)
		return _magnitude;
	else if(_directionDeg == 270)
		return _magnitude * -1;
	else
		return _magnitude * sin(_directionRad);
}

//Return Total Amount of Vectors
unsigned long Vector :: getTotalVectors()
{
	return _totalVectors;
}

//Operator Overloads
//Stream Operation
std::ostream &operator<<(std::ostream& stream, Vector& param)
{
	stream << param.getMagnitude() << "[" << param.getDirectionDeg() << "]";
	return stream;
}

//Addition Operation
Vector Vector :: operator+(Vector& param)
{
	
	double x;
	double y;
	double tempMag;
	double tempRefDir;
	double tempDir;
	
	//Add Vector Components Together
	x = getXComponent() + param.getXComponent();
	y = getYComponent() + param.getYComponent();
	

	//Exception Handling - Magnitude is Zero
	if( x == 0 && y == 0)
	{
		tempDir = 0;
		tempMag = 0;
	}
	
	//Determine Which Quadrant if X or Y Equals Zero
	else if( x > 0 && y == 0)
	{
		tempDir = 0;
		tempMag = x;
	}
	else if( x == 0 && y > 0)
	{
		tempDir = M_PI / 2;
		tempMag = y;
	}
	else if( x < 0 && y == 0)
	{
		tempDir = M_PI;
		tempMag = x;
	}
	else if( x == 0 && y < 0)
	{
		tempDir = (3 * M_PI) / 2;
		tempMag = y;
	}
	
	//Calculate X & Y of new Vector
	else
	{	
		tempMag = sqrt( (x * x) + (y * y) );
		tempRefDir = fabs(atan(y / x));
		
		//Determine Actual Angle using the Reference Angle
		if(x > 0 && y > 0)
			tempDir = tempRefDir;
		else if(x < 0 && y > 0)
			tempDir = M_PI - tempRefDir;	
		else if(x < 0 && y < 0)
			tempDir = tempRefDir + M_PI;
		else if(x >	0 && y < 0)
			tempDir = (2 * M_PI) - tempRefDir;
	}
	
	//Exception Handling - Zero Vector
	if( (x < 1.0e-12) && (x > -1.0e-12) &&
		(y < 1.0e-12) && (y > -1.0e-12) )
	{
		tempMag = 0;
		tempDir = 0;
	}
			
	
	//Create New Vector
	Vector v (fabs(tempMag), tempDir * (180 / M_PI) );
	return v;
	
}

unsigned long Vector :: _totalVectors = 0;

#endif
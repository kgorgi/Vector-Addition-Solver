//***********************************************************
//* Vector.h Created By Kian Gorgichuk                      *
//* Copyright (c) 2014 Kian Gorgichuk. All rights reserved. *
//***********************************************************

class Vector
{
	private:
		double _magnitude; 
		double _directionRad;
		double _directionDeg;
		static unsigned long _totalVectors;
	
	public:
		//Constructors & Destructor
		Vector();
		Vector(double, double);
		~Vector();
		
		//Setters
		void setMagnitude(double);
		void setDirection(double);
		
		//Getters
		
		double getMagnitude();
		double getDirectionRad();
		double getDirectionDeg();
		double getXComponent();
		double getYComponent();
		
		static unsigned long getTotalVectors();
		
		//Operator Overload
		Vector operator+(Vector&);
		friend std::ostream &operator<<(std::ostream&, Vector&);
		
};
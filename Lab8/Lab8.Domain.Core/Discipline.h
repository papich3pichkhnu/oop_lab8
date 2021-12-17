#pragma once
#include "Department.h"
using namespace System;
namespace Lab8DomainCore {
	ref class Department;
	public ref class Discipline
	{
	public:
		int credits;
		int numberOfHours;
		int numberOfControlWorks;
		
	public:
		int id;
		static int cnt = 0;
		String^ name;
		int departmentId;
		Department^ department;
		String^ typeOfControl;
		Discipline(String^ _n, Department^ _d, String^ _t, int _cr, int _nh, int _ncw);
		Discipline();
		~Discipline();
		String^ getName();
		Department^ getDepartment();
		String^ getTypeOfControl();
		int getCredits();
		int getNumberOfHours();
		int getNumberOfControlWorks();		
		void readFromFile(StreamReader^);
		void writeToFile(StreamWriter^);
	};

}
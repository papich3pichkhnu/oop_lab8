#pragma once
#include "Student.h"
#include "Discipline.h"
#include "Department.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
namespace Lab8DomainCore {
	ref class Student;
	ref class Discipline;
	ref class Department;
	public ref class Faculty
	{
	public:		
		int yearOfCreating;
		int numOfSpecs;
		String^ telephoneNumber;
		String^ email;	
	public:
		static int cnt=0;
		String^ facultyName;
		String^ abbreviature;
		List<Student^>^ students;
		List<Department^>^ departments;
		String^ decane;
		int id;
		Faculty();
		~Faculty();
		Faculty(String^ _fName, String^ _a, String^ _d, int _yc, int _ns, String^ _tn, String^ _e);
		void setFaculty(String^ _facultyName);
		void setFaculty(String^ _facultyName, String^ _abbreviature);
		void setNumericData(int _numOfSpecs);
		void setInfo(String^ _decane, int _yearOfCreating, String^ _telephoneNumber, String^ _email);
		int getNumOfDepartments();		
		bool enrollStudent(Student^ s);
		bool deductStudent(Student^ s);
		bool addDepartment(Department^ s);
		bool deleteDepartment(Department^ s);
		void readFromFile(StreamReader^);
		void writeToFile(StreamWriter^);
	};
}



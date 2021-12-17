#pragma once
using namespace System;
#include "Department.h"
#include "Discipline.h"
#include "Person.h"

namespace Lab8DomainCore {	
	ref class Department;
	ref class Discipline;
	ref class Student;
	ref class Person;
	public ref class Lecturer : public Person
	{
	protected:
				
	protected:
		int departmentId;
		Lab8DomainCore::Department^ d;
	public:
		void setDepartment(Department^ d);
		static int cnt = 0;
		virtual String^ getDescryptor();
		Department^ getDepartment();
		int getDepartmentId();
		Lecturer();
		int id;
		virtual ~Lecturer();
		Lecturer(String^ _lName, String^ _fName, String^ _mName);
		Lecturer(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh);		
		void selfDescribe() override;
		bool equals(Lecturer^ a);
		void readFromFile(StreamReader^);
		void writeToFile(StreamWriter^);
	};
}

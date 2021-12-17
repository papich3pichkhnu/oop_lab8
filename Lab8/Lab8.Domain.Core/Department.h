#pragma once
#include "Lecturer.h"
#include "Faculty.h"
#include "Lecturer.h"
#include "AssociateProfessor.h"
namespace Lab8DomainCore {
	ref class Lecturer;
	ref class Faculty;
	ref class Discipline;
	ref class Discipline;
	ref class AssociateProfessor;
	using namespace System;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	public ref class Department
	{
	private:
		int facultyId;
		Faculty^ f;
		
	public:		
		int id;
		static int cnt = 0;
		String^ name;
		List<Lecturer^>^ lecturers;
		int lecturerId;
		AssociateProfessor^ headOfDepartment;
		Department(String^ _n);
		~Department();
		Department();
		bool enrollLecturer(Lecturer^ l);
		bool deductLecturer(Lecturer^ l);
		void setHeadOfDepartment(AssociateProfessor^ l);
		void setFaculty(Faculty^ f);
		Faculty^ getFaculty();		
		bool equals(Department^ a);
		void readFromFile(StreamReader^);
		void writeToFile(StreamWriter^);
		int getFacultyId();
	};
	
}
#pragma once
using namespace System::IO;
#include "Person.h"
#include "Faculty.h"
#include "IEntity.h"

	using namespace System;
	namespace Lab8DomainCore {
		ref class Faculty;
		ref class AssociateProfessor;
		public ref class Student : public Person
		{
		private:
			int facultyId;
			Faculty^ sFaculty;
			
			int mentorId;
			AssociateProfessor^ mentor;
		public:
			static Student^ createInstance();
			Student();
			int id;
			static int cnt = 0;
			virtual ~Student();
			Student(String^ _lName, String^ _fName, String^ _mName);
			Student(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh);
			void setFaculty(Faculty^ _sFaculty);
			Faculty^ getFaculty();
			void readFromFile(StreamReader^);
			void writeToFile(StreamWriter^);
			void selfDescribe() override;
			bool equals(Student^ s);
			void setMentor(AssociateProfessor^ p);
			int getFacultyId();
			int getMentorId();
			AssociateProfessor^ getMentor();
		};
	}





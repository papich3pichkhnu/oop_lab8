#pragma once
using namespace System::IO;
#include "Person.h"
	using namespace System;
	namespace Lab8DomainCore {
		public ref class Student : Person
		{
		private:
			int facultyId;
			Student^ sFaculty;
			static int cnt = 0;
		public:
			Student();
			int id;
			virtual ~Student();
			Student(String^ _lName, String^ _fName, String^ _mName);
			Student(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh);
			//void setFaculty(Faculty^ _sFaculty);
			//Faculty^ getFaculty();
			static Student^ readFromFile(StreamReader^);
			void printToFile();
			void selfDescribe() override;
		};
	}





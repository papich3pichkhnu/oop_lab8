#pragma once
#include "Faculty.h"
#include "Department.h"
#include "Student.h"
#include "Lecturer.h"
#include "SeniorLecturer.h"
#include "Discipline.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
namespace Lab8DomainCore {
	public ref class Exam
	{
	public:
		static int cnt = 0;
		int id;
		int studentId;
		Student^ student;
		int lecturerId;
		SeniorLecturer^ lecturer;
		int disciplineId;
		Discipline^ discipline;
		int mark;
		String^ date;
		bool issigned;
		~Exam();
		Exam(Student^, SeniorLecturer^, Discipline^);
		Exam();
		int takeExam(String^);
		void readFromFile(StreamReader^);
		void writeToFile(StreamWriter^);
	};
}



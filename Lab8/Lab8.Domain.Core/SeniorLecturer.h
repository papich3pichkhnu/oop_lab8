#pragma once
#include "Lecturer.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
namespace Lab8DomainCore {
	ref class Lecturer;
	ref class Exam;
	public ref class SeniorLecturer : public Lecturer
	{
	
	public:
		static int seniorcnt = 0;
		int seniorid = 0;
		SeniorLecturer();
		virtual ~SeniorLecturer();
		SeniorLecturer(String^ _lName, String^ _fName, String^ _mName);
		SeniorLecturer(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh);
		void setExamSign(Exam^);
		void selfDescribe() override;
		String^ getDescryptor() override;
	};

}
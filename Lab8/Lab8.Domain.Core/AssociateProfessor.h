#pragma once
#include "SeniorLecturer.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
namespace Lab8DomainCore {
	public ref class AssociateProfessor : public SeniorLecturer
	{
    protected:
        
    public:        
        String^ descryptor = "AssociateProfessor";
        static int assoccnt = 0;
        int associd = 0;
        AssociateProfessor();
        virtual ~AssociateProfessor();
        AssociateProfessor(String^ _lName, String^ _fName, String^ _mName);
        AssociateProfessor(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh);
        void mentorCourseProject(Student^ s);
        void selfDescribe() override;
        String^ getDescryptor() override;
	};

}
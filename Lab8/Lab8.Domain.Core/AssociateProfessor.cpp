#include "pch.h"
#include "AssociateProfessor.h"
using namespace System;
using namespace Lab8DomainCore;
AssociateProfessor::AssociateProfessor() :AssociateProfessor("Last name", "First name", "Middle name") {}
AssociateProfessor::~AssociateProfessor()
{
	this->d = nullptr;
}
AssociateProfessor::AssociateProfessor(String^ _lName, String^ _fName, String^ _mName) : AssociateProfessor(_lName, _fName, _mName, 30, 180, "Green", "Black") {}

AssociateProfessor::AssociateProfessor(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh) :
	SeniorLecturer(_ln, _fn, _mn, _a, _h, _coe, _coh), associd(assoccnt++) {
	
}
void AssociateProfessor::mentorCourseProject(Student^ s)
{
	s->setMentor(this);
}
void AssociateProfessor::selfDescribe()
{
	Console::WriteLine("I am associate professor " + this->getFullName());
}

String^ Lab8DomainCore::AssociateProfessor::getDescryptor()
{
	return "AssociateProfessor";
}

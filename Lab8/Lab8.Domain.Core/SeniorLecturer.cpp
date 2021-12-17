#include "pch.h"
#include "SeniorLecturer.h"
using namespace System;
using namespace Lab8DomainCore;
SeniorLecturer::SeniorLecturer() :SeniorLecturer("Last name", "First name", "Middle name") { }
SeniorLecturer::~SeniorLecturer()
{
	this->d = nullptr;
}
SeniorLecturer::SeniorLecturer(String^ _lName, String^ _fName, String^ _mName) : SeniorLecturer(_lName, _fName, _mName, 30, 180, "Green", "Black") { }

SeniorLecturer::SeniorLecturer(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh) :
	Lecturer(_ln, _fn, _mn, _a, _h, _coe, _coh), seniorid(seniorcnt++)
{
	
}
void SeniorLecturer::setExamSign(Exam^ e)
{
	e->issigned = true;
}
void SeniorLecturer::selfDescribe()
{
	Console::WriteLine("I am senior lecturer " + this->getFullName());
}

String^ Lab8DomainCore::SeniorLecturer::getDescryptor()
{
	return "SeniorLecturer";
}

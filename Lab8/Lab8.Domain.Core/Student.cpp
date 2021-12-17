#include "pch.h"
#include "Student.h"

using namespace System;
using namespace System::IO;
using namespace Lab8DomainCore;
Student::~Student()
{
	Console::WriteLine("Student " + this->getFullName() + " was destroyed");
	this->sFaculty = nullptr;

}
Student::Student(String^ _lName, String^ _fName, String^ _mName) : Student(_lName, _fName, _mName, 30, 180, "Green", "Black") {}

Student::Student(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh) :
	Person(_ln, _fn, _mn, _a, _h, _coe, _coh), sFaculty(nullptr),id(Student::cnt++),facultyId(-1),mentorId(-1) {
	Console::WriteLine("Student " + this->getFullName() + " was created");
}
Student^ Lab8DomainCore::Student::createInstance()
{
	return gcnew Student();
}
Student::Student() :Student("Last name", "First name", "Middle name",
	18, 170, "Brown", "Black")
{
}

void Student::setFaculty(Faculty^ _sFaculty) { this->sFaculty = _sFaculty; this->facultyId=_sFaculty == nullptr ? -1 :_sFaculty->id; }


Faculty^ Student::getFaculty()
{
	return this->sFaculty;
}

void Student::writeToFile(StreamWriter^ sw)
{	
	sw->WriteLine(this->lastName);
	sw->WriteLine(this->firstName);
	sw->WriteLine(this->middleName);
	sw->WriteLine(this->age);
	sw->WriteLine(this->height);
	sw->WriteLine(this->colorOfEyes);
	sw->WriteLine(this->colorOfHair);
	sw->WriteLine(this->facultyId);
	sw->WriteLine(this->mentorId);
}


void Student::readFromFile(StreamReader^ sr)
{
	this->setName(sr->ReadLine(), sr->ReadLine(), sr->ReadLine());
	this->setData(int::Parse(sr->ReadLine()), int::Parse(sr->ReadLine()));
	this->setEyesHair(sr->ReadLine(), sr->ReadLine());
	this->facultyId = int::Parse(sr->ReadLine());
	this->mentorId= int::Parse(sr->ReadLine());
}
void Student::selfDescribe()
{
	Console::WriteLine("I am student " + this->getFullName());
}

bool Lab8DomainCore::Student::equals(Student^ a)
{
	return a->id == this->id;
}

void Lab8DomainCore::Student::setMentor(AssociateProfessor^ p)
{
	this->mentor = p;
	this->mentorId = p == nullptr ? -1 : p->id;
}

int Lab8DomainCore::Student::getFacultyId()
{
	return this->facultyId;
}

int Lab8DomainCore::Student::getMentorId()
{
	return this->mentorId;
}

AssociateProfessor^ Lab8DomainCore::Student::getMentor()
{
	return this->mentor;
}


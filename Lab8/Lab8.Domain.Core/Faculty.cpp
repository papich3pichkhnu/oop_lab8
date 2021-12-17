#include "pch.h"
#include "Faculty.h"
using namespace System;
using namespace Lab8DomainCore;
Faculty::Faculty() :Faculty("Faculty", "F", "Decane",
	2021, 10, "3802123456", "faculty@khnu.km.ua") {
}
Faculty::~Faculty()
{
	this->students->Clear();
	this->departments->Clear();
	//cout << "Faculty \"" << this->facultyName << "\" was destroyed" << endl;
}
Faculty::Faculty(String^ _fName, String^ _a, String^ _d, int _yc, int _ns, String^ _tn, String^ _e) :
	facultyName(_fName), abbreviature(_a), decane(_d), yearOfCreating(_yc),
	numOfSpecs(_ns), telephoneNumber(_tn), email(_e), id(cnt++), departments(gcnew List<Department^>()),students(gcnew List<Student^>())
{
	Console::WriteLine("Faculty " + this->facultyName + " was created");
}
void Faculty::setFaculty(String^ _facultyName) { this->facultyName = _facultyName; }
void Faculty::setFaculty(String^ _facultyName, String^ _abbreviature) { this->facultyName = _facultyName; this->abbreviature = _abbreviature; }
void Faculty::setNumericData(int _numOfSpecs) { this->numOfSpecs = _numOfSpecs; }
void Faculty::setInfo(String^ _decane, int _yearOfCreating, String^ _telephoneNumber, String^ _email) {
	this->decane = _decane; this->yearOfCreating = _yearOfCreating; this->telephoneNumber = _telephoneNumber;
	this->email = _email;
}
int Faculty::getNumOfDepartments() {
	return this->departments->Count;
}
bool Faculty::enrollStudent(Student^ s)
{
	if (s->getFaculty() != nullptr)
	{
		Console::WriteLine("Student " + s->getFullName() + " is already enroled on the faculty " + s->getFaculty()->abbreviature);
		return false;
	}
	this->students->Add(s);
	s->setFaculty(this);
	return true;
Console::WriteLine("Student " +s->getFullName() + " was enroled on the faculty " + this->abbreviature);
}
bool Faculty::deductStudent(Student^ s)
{
	Student^ f = this->students->Find(gcnew Predicate<Student^>(s, &Student::equals));
	if (f == nullptr)
	{		
		return false;
	}
	else
	{
		this->students->Remove(f);
		s->setFaculty(nullptr);
		return true;
	}
}

bool Faculty::addDepartment(Department^ s)
{
	if (s->getFaculty() != nullptr)
	{
		return false;
	}
	this->departments->Add(s);
	s->setFaculty(this);
	return true;
}

bool Faculty::deleteDepartment(Department^ s)
{
	Department^ f = this->departments->Find(gcnew Predicate<Department^>(s, &Department::equals));
	if (f == nullptr)
	{
		return false;
	}
	else
	{
		this->departments->Remove(f);
		s->setFaculty(nullptr);
		return true;
	}
}
void Faculty::writeToFile(StreamWriter^ sw)
{
	sw->WriteLine(this->abbreviature);
	sw->WriteLine(this->decane);
	sw->WriteLine(this->email);
	sw->WriteLine(this->facultyName);
	sw->WriteLine(this->numOfSpecs);
	sw->WriteLine(this->telephoneNumber);
	sw->WriteLine(this->yearOfCreating);
	
}


void Faculty::readFromFile(StreamReader^ sr)
{
	this->abbreviature = sr->ReadLine();
	this->decane = sr->ReadLine();
	this->email = sr->ReadLine();
	this->facultyName = sr->ReadLine();
	this->numOfSpecs = int::Parse(sr->ReadLine());
	this->telephoneNumber = sr->ReadLine();
	this->yearOfCreating = int::Parse(sr->ReadLine());	
}


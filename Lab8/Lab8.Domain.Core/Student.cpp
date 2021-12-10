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
	Person(_ln, _fn, _mn, _a, _h, _coe, _coh), sFaculty(nullptr),id(++Student::cnt) {
	Console::WriteLine("Student " + this->getFullName() + " was created");
}
Student::Student() :Student("Last name", "First name", "Middle name",
	18, 170, "Brown", "Black")
{
}

//void Student::setFaculty(Faculty^ _sFaculty) { this->sFaculty = _sFaculty; }
//void Student::setFaculty(Faculty^ _sFaculty) { this->sFaculty = _sFaculty; }

/*Faculty^ Student::getFaculty()
{
	return this->sFaculty;
}
*/
void Student::printToFile()
{
	System::IO::StreamWriter^ sw = gcnew StreamWriter("students.txt", true);
	sw->WriteLine(this->id);
	sw->WriteLine(this->lastName);
	sw->WriteLine(this->firstName);
	sw->WriteLine(this->middleName);
	sw->WriteLine(this->age);
	sw->WriteLine(this->height);
	sw->WriteLine(this->colorOfEyes);
	sw->WriteLine(this->colorOfHair);
	sw->WriteLine(this->facultyId);
	sw->Close();	
}

Student^ Student::readFromFile(StreamReader^ sw)
{
	Student^ obj=gcnew Student();
	obj->id=int::Parse(sw->ReadLine());	
	obj->lastName=sw->ReadLine();
	obj->firstName= sw->ReadLine();
	obj->middleName= sw->ReadLine();
	obj->age=int::Parse(sw->ReadLine());
	obj->height=int::Parse(sw->ReadLine());
	obj->colorOfEyes= sw->ReadLine();
	obj->colorOfHair = sw->ReadLine();	
	obj->facultyId = int::Parse(sw->ReadLine());
	return obj;
}

void Student::selfDescribe()
{
	Console::WriteLine("I am student " + this->getFullName());
}
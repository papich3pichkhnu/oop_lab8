#include "pch.h"
#include "Lecturer.h"

using namespace System;
using namespace Lab8DomainCore;
Lecturer::Lecturer() :Lecturer("Last name", "First name", "Middle name") { }
Lecturer::~Lecturer()
{
	this->d = nullptr;
	System::Console::WriteLine("Lecturer " + this->getFullName() + " was destroyed");
}
Lecturer::Lecturer(String^ _lName, String^ _fName, String^ _mName) : Lecturer(_lName, _fName, _mName, 30, 180, "Green", "Black") {}

Lecturer::Lecturer(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh) :
	Person(_ln, _fn, _mn, _a, _h, _coe, _coh), d(nullptr), id(Lecturer::cnt++), departmentId(-1)
{
	System::Console::WriteLine("Lecturer " + this->getFullName() + " was created");
}
void Lecturer::setDepartment(Department^ d)
{
	this->d = d;
	if(this->d!=nullptr)this->departmentId = d->id;
}
String^ Lab8DomainCore::Lecturer::getDescryptor()
{
	return "Lecturer";
}
Department^ Lecturer::getDepartment()
{
	return this->d;
}

int Lab8DomainCore::Lecturer::getDepartmentId()
{
	return this->departmentId;
}

void Lecturer::selfDescribe()
{
	Console::WriteLine("I am lecturer" + this->getFullName());
}

bool Lab8DomainCore::Lecturer::equals(Lecturer^ a)
{
	return a->id==this->id;
}

void Lecturer::writeToFile(StreamWriter^ sw)
{
	sw->WriteLine(this->lastName);
	sw->WriteLine(this->firstName);
	sw->WriteLine(this->middleName);
	sw->WriteLine(this->age);
	sw->WriteLine(this->height);
	sw->WriteLine(this->colorOfEyes);
	sw->WriteLine(this->colorOfHair);
	sw->WriteLine(this->departmentId);
}


void Lecturer::readFromFile(StreamReader^ sr)
{
	this->lastName = sr->ReadLine();
	this->firstName = sr->ReadLine();
	this->middleName = sr->ReadLine();
	this->age = int::Parse(sr->ReadLine());
	this->height = int::Parse(sr->ReadLine());
	this->colorOfEyes = sr->ReadLine();
	this->colorOfHair = sr->ReadLine();
	this->departmentId = int::Parse(sr->ReadLine());
}


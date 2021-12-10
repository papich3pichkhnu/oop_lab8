#include "pch.h"
#include "Person.h"

	using namespace System;
	using namespace Lab8DomainCore;
	Person::Person() : Person(gcnew String("Last name"), gcnew String("First name"), gcnew String("Middle name")) {

	}
	Person::~Person()
	{
		System::Console::WriteLine("Person " + this->getFullName() + " was destroyed");
	}
	Person::Person(String^ _lName, String^ _fName, String^ _mName) : Person(_lName, _fName, _mName, 18, 170, "Brown", "Black")
	{

	}
	Person::Person(String^ _ln, String^ _fn, String^ _mn, int _a, int _h, String^ _coe, String^ _coh)
	{
		setName(_ln, _fn, _mn);
		setData(_a, _h); setEyesHair(_coe, _coh);
		System::Console::WriteLine("Person " + this->getFullName() + " was created");

	}
	String^ Person::getFullName() {
		return this->lastName + " " + this->firstName + " " + this->middleName;
	}
	void Person::setName(String^ _name) { this->firstName = _name; }
	void Person::setName(String^ _lName, String^ _fName, String^ _mName) { this->lastName = _lName; this->firstName = _fName; this->middleName = _mName; }
	void Person::setData(int _age) { this->age = _age; }
	void Person::setData(int _age, int _height) { this->age = _age; this->height = _height; }
	void Person::setEyesHair(String^ _colorOfEyes, String^ _colorOfHair) { this->colorOfEyes = _colorOfEyes; this->colorOfHair = _colorOfHair; }
	int Person::getAge() { return this->age; }
	int Person::getHeight() { return this->height; }
	String^ Person::getColorOfEyes() { return this->colorOfEyes; }
	String^ Person::getColorOfHair() { return this->colorOfHair; }



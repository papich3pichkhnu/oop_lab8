#include "pch.h"
#include "Discipline.h"
using namespace System;
using namespace Lab8DomainCore;
Discipline::Discipline(String^ _n, Department^ _d, String^ _t, int _cr, int _nh, int _ncw) :
	name(_n), department(_d), typeOfControl(_t), credits(_cr), numberOfHours(_nh), numberOfControlWorks(_ncw), id(cnt++)
{
	if (this->department != nullptr)this->departmentId = _d->id; else this->departmentId = -1;
}
Discipline::Discipline() : Discipline("Discipline", gcnew Department("Department"), "Exam", 60, 20, 5)
{

}
Discipline::~Discipline()
{
}

String^ Discipline::getName() {
	return this->name;
}
Department^ Discipline::getDepartment() {
	return this->department;
}
String^ Discipline::getTypeOfControl() {
	return this->typeOfControl;
}
int Discipline::getCredits() {
	return this->credits;
}
int Discipline::getNumberOfControlWorks() {
	return this->numberOfControlWorks;
}
int Discipline::getNumberOfHours() {
	return this->numberOfHours;
}
void Discipline::writeToFile(StreamWriter^ sw)
{
	sw->WriteLine(this->name);
	sw->WriteLine(this->typeOfControl);
	sw->WriteLine(this->credits);
	sw->WriteLine(this->departmentId);
	sw->WriteLine(this->numberOfHours);
	sw->WriteLine(this->numberOfControlWorks);	
}


void Discipline::readFromFile(StreamReader^ sr)
{
	this->name = sr->ReadLine();
	this->typeOfControl = sr->ReadLine();
	this->credits = int::Parse(sr->ReadLine());
	this->departmentId = int::Parse(sr->ReadLine());
	this->numberOfHours = int::Parse(sr->ReadLine());
	this->numberOfControlWorks = int::Parse(sr->ReadLine());
}
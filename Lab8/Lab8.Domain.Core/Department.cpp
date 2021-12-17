#include "pch.h"
#include "Department.h"

using namespace System;
using namespace Lab8DomainCore;
Department::Department(String^ _n) :name(_n), f(nullptr), headOfDepartment(nullptr), id(cnt++), facultyId(-1),lecturerId(-1),
lecturers(gcnew List<Lecturer^>())
{
	Console::WriteLine("Department " + this->name + " was created");
}

Department::~Department()
{	
	Console::WriteLine("Department " + this->name + " was destroyed");
}

Department::Department() :Department("Department")
{	

}

void Department::setHeadOfDepartment(AssociateProfessor^ l)
{
	this->headOfDepartment = l;
	if(this->headOfDepartment!=nullptr)this->lecturerId = l->id;
}

void Department::setFaculty(Faculty^ f)
{
	this->f = f;
	if (this->f != nullptr)this->facultyId = f->id;
}
Faculty^ Department::getFaculty()
{
	return this->f;
}
bool Lab8DomainCore::Department::equals(Department^ a)
{
	return this->id == a->id;
}
bool Department::enrollLecturer(Lecturer^ s)
{
	if (s->getDepartment() == nullptr)
	{
		this->lecturers->Add(s);
		s->setDepartment(this);
		return true;
	}
	else return false;
	//Console::WriteLine("Lecturer " + s->getFullName() + " was enrolled on the department " + this->name);

}
bool Department::deductLecturer(Lecturer^ s)
{
	Lecturer^ f = this->lecturers->Find(gcnew Predicate<Lecturer^>(s, &Lecturer::equals));
	if (f == nullptr)
	{
		Console::WriteLine("Lecturer " + s->getFullName() + " doesn't teach on this department ");
		return false;
	}
	else
	{
		this->lecturers->Remove(f);
		s->setDepartment(nullptr);
		return true;
		Console::WriteLine("Lecturer " + s->getFullName() + " was deducted from the department " + this->name);
	}	
}

void Department::writeToFile(StreamWriter^ sw)
{
	sw->WriteLine(this->name);
	sw->WriteLine(this->facultyId);
	sw->WriteLine(this->lecturerId);
}


void Department::readFromFile(StreamReader^ sr)
{
	this->name = sr->ReadLine();
	this->facultyId= int::Parse(sr->ReadLine());
	this->lecturerId= int::Parse(sr->ReadLine());
}

int Department::getFacultyId()
{
	return this->facultyId;
}
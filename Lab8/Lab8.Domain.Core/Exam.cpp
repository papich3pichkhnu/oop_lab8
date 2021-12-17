#include "pch.h"
#include "Exam.h"
using namespace System;
using namespace Lab8DomainCore;
Exam::~Exam()
{
}

Exam::Exam(Student^ s, SeniorLecturer^ l, Discipline^ di) :
	student(s), lecturer(l), discipline(di), mark(0), issigned(false), id(cnt++)
{
	if (this->student != nullptr)this->studentId = s->id;
	if (this->lecturer != nullptr)this->lecturerId = l->id;
	if (this->discipline != nullptr)this->disciplineId = di->id;
}
Exam::Exam() :Exam(nullptr, nullptr, nullptr) {

}
int Exam::takeExam(String^ date)
{
	Random^ rnd = gcnew Random();
	int score = rnd->Next(1,5);
	this->lecturer->setExamSign(this);	
	if (score < 3)this->student->getFaculty()->deductStudent(this->student);
	this->mark = score;
	this->date = date;
	return score;
	
}
void Exam::writeToFile(StreamWriter^ sw)
{
	sw->WriteLine(this->date);
	sw->WriteLine(this->disciplineId);
	sw->WriteLine(this->issigned);
	sw->WriteLine(this->lecturerId);
	sw->WriteLine(this->mark);
	sw->WriteLine(this->studentId);	
}


void Exam::readFromFile(StreamReader^ sr)
{
	this->date = sr->ReadLine();
	this->disciplineId = int::Parse(sr->ReadLine());
	this->issigned = bool::Parse(sr->ReadLine());
	this->lecturerId = int::Parse(sr->ReadLine());
	this->mark = int::Parse(sr->ReadLine());
	this->studentId = int::Parse(sr->ReadLine());
}
#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace Lab8DomainCore;
namespace Lab8 {
	public ref class DBContext
	{
	public:
		List<AssociateProfessor^>^ associateprofessors;
		List<Department^>^ departments;
		List<Discipline^>^ disciplines;
		List<Exam^>^ exams;
		List<Faculty^>^ faculties;
		List<Lecturer^>^ lecturers;
		List<Lecturer^>^ alllecturers;
		List<SeniorLecturer^>^ seniorlecturers;
		List<Student^>^ students;
		DBContext()
		{
			associateprofessors = gcnew List<AssociateProfessor^>();
			departments = gcnew List<Department^>();
			disciplines = gcnew List<Discipline^>();
			exams = gcnew List<Exam^>();
			faculties = gcnew List<Faculty^>();
			lecturers = gcnew List<Lecturer^>();
			alllecturers = gcnew List<Lecturer^>();
			seniorlecturers = gcnew List<SeniorLecturer^>();
			students = gcnew List<Student^>();

			getData();

		}
		void getData()
		{
			Department::cnt = 0;
			Discipline::cnt = 0;
			Exam::cnt = 0;
			Faculty::cnt = 0;
			Student::cnt = 0;
			Lecturer::cnt = 0;
			SeniorLecturer::seniorcnt = 0;
			AssociateProfessor::assoccnt = 0;
			StreamReader^ sr;
			try
			{
				sr = gcnew StreamReader("students.txt");
				while (!sr->EndOfStream)
				{
					Student^ s = gcnew Student();
					s->readFromFile(sr);
					this->students->Add(s);
				}
				sr->Close();
			}
			catch (System::IO::FileNotFoundException^ e) { File::Create("students.txt")->Close(); }
			finally { delete sr; }

			try
			{
				sr = gcnew StreamReader("departments.txt");
				while (!sr->EndOfStream)
				{
					Department^ s = gcnew Department();
					s->readFromFile(sr);
					this->departments->Add(s);
				}
				sr->Close();
			}
			catch (System::IO::FileNotFoundException^ e) { File::Create("departments.txt")->Close(); }
			finally { delete sr; }

			try
			{
				sr = gcnew StreamReader("disciplines.txt");
				while (!sr->EndOfStream)
				{
					Discipline^ s = gcnew Discipline();
					s->readFromFile(sr);
					this->disciplines->Add(s);
				}
				sr->Close();
			}
			catch (System::IO::FileNotFoundException^ e) { File::Create("disciplines.txt")->Close(); }
			finally { delete sr; }

			try
			{
				sr = gcnew StreamReader("exams.txt");
				while (!sr->EndOfStream)
				{
					Exam^ s = gcnew Exam();
					s->readFromFile(sr);
					this->exams->Add(s);
				}
				sr->Close();
			}
			catch (System::IO::FileNotFoundException^ e) { File::Create("exams.txt")->Close(); }
			finally { delete sr; }

			try
			{
				sr = gcnew StreamReader("faculties.txt");
				while (!sr->EndOfStream)
				{
					Faculty^ s = gcnew Faculty();
					s->readFromFile(sr);
					this->faculties->Add(s);
				}
				sr->Close();
			}
			catch (System::IO::FileNotFoundException^ e) { File::Create("faculties.txt")->Close(); }
			finally { delete sr; }

			try
			{
				sr = gcnew StreamReader("lecturers.txt");
				while (!sr->EndOfStream)
				{
					String^ descr = sr->ReadLine();
					Lecturer^ s;
					if (descr == "Lecturer")s = gcnew Lecturer();
					else if (descr == "SeniorLecturer")s = gcnew SeniorLecturer();
					else s = gcnew AssociateProfessor();
					s->readFromFile(sr);
					this->alllecturers->Add(s);
					if (descr == "Lecturer")this->lecturers->Add(s);
					else if (descr == "SeniorLecturer")this->seniorlecturers->Add(dynamic_cast<SeniorLecturer^>(s)), this->lecturers->Add(s);
					else this->associateprofessors->Add(dynamic_cast<AssociateProfessor^>(s)), this->seniorlecturers->Add(dynamic_cast<SeniorLecturer^>(s)), this->lecturers->Add(s); ;
				}
				sr->Close();
			}
			catch (System::IO::FileNotFoundException^ e) { File::Create("lecturers.txt")->Close(); }
			finally { delete sr; }
			for each (Student ^ s in this->students)
			{
				if (s->getFacultyId() != -1) {
					this->faculties[s->getFacultyId()]->enrollStudent(s);							
				}
				if (s->getMentorId() != -1)
					s->setMentor(dynamic_cast<AssociateProfessor^>(this->alllecturers[s->getMentorId()]));
			}
			for each (Department ^ s in this->departments)
			{
				if (s->getFacultyId() != -1) {
					this->faculties[s->getFacultyId()]->addDepartment(s);					
				}
				if (s->lecturerId != -1)
				{
					s->setHeadOfDepartment(dynamic_cast<AssociateProfessor^>(alllecturers[s->lecturerId]));
				}
			}
			for each (Discipline ^ s in this->disciplines)
			{
				if(s->departmentId!=-1)
				s->department = this->departments[s->departmentId];
			}
			for each (Exam ^ s in this->exams)
			{

				if (s->disciplineId != -1)s->discipline = this->disciplines[s->disciplineId];
				if (s->lecturerId != -1)s->lecturer = dynamic_cast<SeniorLecturer^>(this->alllecturers[s->lecturerId]);
				if (s->studentId != -1)s->student = this->students[s->studentId];
			}
			for each (Lecturer ^ s in this->alllecturers)
			{
				if (s->getDepartmentId() != -1) {
					departments[s->getDepartmentId()]->enrollLecturer(s);
				}
			}

		}
		void saveChanges()
		{
			StreamWriter^ sw = gcnew StreamWriter("students.txt");
			for each (Student ^ s in this->students)
			{
				s->writeToFile(sw);
			}
			sw->Close();
			sw = gcnew StreamWriter("lecturers.txt");
			for each (Lecturer ^ s in this->alllecturers)
			{
				sw->WriteLine(s->getDescryptor());
				s->writeToFile(sw);
			}
			sw->Close();
			sw = gcnew StreamWriter("departments.txt");
			for each (Department ^ s in this->departments)
			{
				s->writeToFile(sw);
			}
			sw->Close();
			sw = gcnew StreamWriter("disciplines.txt");
			for each (Discipline ^ s in this->disciplines)
			{
				s->writeToFile(sw);
			}
			sw->Close();
			sw = gcnew StreamWriter("exams.txt");
			for each (Exam ^ s in this->exams)
			{
				s->writeToFile(sw);
			}
			sw->Close();
			sw = gcnew StreamWriter("faculties.txt");
			for each (Faculty ^ s in this->faculties)
			{
				s->writeToFile(sw);
			}
			sw->Close();

		}

		void clear()
		{
			this->alllecturers->Clear();
			this->associateprofessors->Clear();
			this->departments->Clear();
			this->disciplines->Clear();
			this->exams->Clear();
			this->faculties->Clear();
			this->lecturers->Clear();
			this->seniorlecturers->Clear();
			this->students->Clear();			
		}
		void clearAndDelete()
		{
			clear();
			(File::Create("lecturers.txt"))->Close();
			(File::Create("departments.txt"))->Close();
			(File::Create("disciplines.txt"))->Close();
			(File::Create("exams.txt"))->Close();
			(File::Create("faculties.txt"))->Close();
			(File::Create("students.txt"))->Close();
		}
	};

}
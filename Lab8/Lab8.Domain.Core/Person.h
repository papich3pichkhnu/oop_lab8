#pragma once

	using namespace System;
	namespace Lab8DomainCore {
		public ref class Person abstract
		{
		protected:
			int age;
			int height;
			String^ colorOfEyes;
			String^ colorOfHair;
		public:
			Person(String^, String^, String^);
			Person();
			Person(String^, String^, String^, int, int, String^, String^);
			virtual ~Person();
			String^ lastName;
			String^ firstName;
			String^ middleName;
			void setName(String^ _lName);
			void setName(String^ _lName, String^ _fName, String^ _mName);
			String^ getFullName();
			void setData(int _age);
			void setData(int _age, int _height);
			void setEyesHair(String^ _colorOfEyes, String^ _colorOfHair);
			int getAge();
			int getHeight();
			String^ getColorOfEyes();
			String^ getColorOfHair();
			virtual void selfDescribe() = 0;

		};
	}
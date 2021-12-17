#pragma once
using namespace System;
using namespace System::IO;
namespace Lab8DomainCore {
	public interface class IEntity
	{
	    void readFromFile(StreamReader^);
		void writeToFile(StreamWriter^);		
		template<class T>
		static T createInstance()
		{
			return gcnew T();
		}
	};

	

}
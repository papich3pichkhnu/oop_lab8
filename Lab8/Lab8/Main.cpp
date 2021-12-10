#include "Main.h"


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace Lab8DomainCore;
	[STAThread]
	void main(array<String^>^ args)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Lab8::Main form;
		Application::Run(% form);		
		
	}

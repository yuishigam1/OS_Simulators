#include "Index.h"

using namespace System;
using namespace System::Windows::Forms;


int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OSSimulators::Index main_form;
	Application::Run(% main_form);
	return 0;
}
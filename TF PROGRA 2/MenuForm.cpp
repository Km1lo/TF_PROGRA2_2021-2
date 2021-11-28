#include "MenuForm.h"

using namespace System;
using namespace Windows::Forms;
using namespace EndOfVirusBeta;

void main() {
	//Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew EndOfVirusBeta::MenuForm);
}

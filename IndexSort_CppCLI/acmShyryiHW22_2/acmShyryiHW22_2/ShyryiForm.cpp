#include "ShyryiForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	acmShyryiHW22_2::ShyryiForm form;
	Application::Run(% form);
}


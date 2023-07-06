#include "ShyryiForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	acmShyryiHW24_1::ShyryiForm form;
	Application::Run(% form);
}
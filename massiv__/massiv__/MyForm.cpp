#include "MyForm.h"
#include <iostream>
#include <ctime>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	massiv::MyForm form;
	Application::Run(% form);

}
int a;
int b;
int** random = 0;
	System::Void massiv::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
	{ 
			a = Convert::ToInt32(textBox1->Text);
			b = Convert::ToInt32(textBox2->Text);
			int const q = a;
			int const w = b;
			srand(time(0));
			random = new int* [q];
			for (int i = 0; i < q; i++)
			{
				random[i] = new int[w];
			}
		
		
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				random[i][j] = rand();
			}
		}

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				textBox3->Text += random[i][j];
				textBox3->Text += "\t\n";
			}
			textBox3->Text += "\r\n";
		}
		textBox3->Text += "\r\n";
	}
	System::Void massiv::MyForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		
		if (random) {
			
			for (int i = 0; i < a; ++i)
			delete[] random[i];
		delete[] random;
		
		textBox3->Text = "";
		random = NULL;
			
		}
		
	}

	System::Void massiv::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (random) {
			int i, j;
			using namespace std;
			ofstream file("массив.txt");
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < b; j++)
				{
					file << random[i][j] << "\t";
				}
				file << "\n";
			}
			file.close();
		}

	}

	
	 






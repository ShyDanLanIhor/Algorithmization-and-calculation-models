#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>
#include <fstream>

void sort_word_indices(std::vector<size_t>& words, const std::string& input, char starting_letter) {
    std::ofstream myfile;
    std::sort(words.begin(), words.end(), [&input](size_t a, size_t b) {
        return std::tolower(input[a]) < std::tolower(input[b]);  // порівнюємо у порядку спадання
        });

    myfile.open("NotSelectedWords.txt"); // записую результат у файл
    for (size_t i = 0; i < words.size(); i++) {
        std::string word = input.substr(words[i], input.find(' ', words[i]) - words[i]);
        if (std::tolower(word[0]) != std::tolower(starting_letter)) {
            myfile << word << "[" << words[i] << "]" << " ";
        }
    }
    myfile.close();
}

struct GetSecond {
    const std::string& operator()(const std::pair<size_t, std::string>& p) const {
        return p.second;
    }
};

namespace acmShyryiHW19 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::IO;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

    private: System::Windows::Forms::TextBox^ inputTextBox;
    private: System::Windows::Forms::Label^ inputInfoLabel;
    private: System::Windows::Forms::Label^ inputLetterInfoLabel;
    private: System::Windows::Forms::TextBox^ inputLetterTextBox;
    private: System::Windows::Forms::TextBox^ outputSelectedWordsTextBox;
    private: System::Windows::Forms::TextBox^ outputNotSelectedWordsTextBox;
    private: System::Windows::Forms::Label^ outputSelectedWordsInfoLabel;
    private: System::Windows::Forms::Label^ outputNotSelectedWordsInfoLabel;
    private: System::Windows::Forms::TextBox^ outputOtherTextBox;
    private: System::Windows::Forms::Button^ sortTextButton;
    private: System::Windows::Forms::Label^ outputOtherInfoInfoLabel;
    protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
            this->inputInfoLabel = (gcnew System::Windows::Forms::Label());
            this->inputLetterInfoLabel = (gcnew System::Windows::Forms::Label());
            this->inputLetterTextBox = (gcnew System::Windows::Forms::TextBox());
            this->outputSelectedWordsTextBox = (gcnew System::Windows::Forms::TextBox());
            this->outputNotSelectedWordsTextBox = (gcnew System::Windows::Forms::TextBox());
            this->outputSelectedWordsInfoLabel = (gcnew System::Windows::Forms::Label());
            this->outputNotSelectedWordsInfoLabel = (gcnew System::Windows::Forms::Label());
            this->sortTextButton = (gcnew System::Windows::Forms::Button());
            this->outputOtherTextBox = (gcnew System::Windows::Forms::TextBox());
            this->outputOtherInfoInfoLabel = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // inputTextBox
            // 
            this->inputTextBox->Location = System::Drawing::Point(12, 47);
            this->inputTextBox->Multiline = true;
            this->inputTextBox->Name = L"inputTextBox";
            this->inputTextBox->Size = System::Drawing::Size(406, 185);
            this->inputTextBox->TabIndex = 0;
            // 
            // inputInfoLabel
            // 
            this->inputInfoLabel->AutoSize = true;
            this->inputInfoLabel->Location = System::Drawing::Point(12, 9);
            this->inputInfoLabel->Name = L"inputInfoLabel";
            this->inputInfoLabel->Size = System::Drawing::Size(366, 26);
            this->inputInfoLabel->TabIndex = 1;
            this->inputInfoLabel->Text = L"Введіть текст, що буде оброблятися:";
            // 
            // inputLetterInfoLabel
            // 
            this->inputLetterInfoLabel->AutoSize = true;
            this->inputLetterInfoLabel->Location = System::Drawing::Point(12, 247);
            this->inputLetterInfoLabel->Name = L"inputLetterInfoLabel";
            this->inputLetterInfoLabel->Size = System::Drawing::Size(405, 104);
            this->inputLetterInfoLabel->TabIndex = 2;
            this->inputLetterInfoLabel->Text = L"Введіть букву, за якою буде відбуватися\nпошук та сортування:\nІндекси слів будуть виведені праворуч\nвід кожного слова у квадартних дужках.";
            // 
            // inputLetterTextBox
            // 
            this->inputLetterTextBox->Location = System::Drawing::Point(196, 268);
            this->inputLetterTextBox->Multiline = true;
            this->inputLetterTextBox->Name = L"inputLetterTextBox";
            this->inputLetterTextBox->Size = System::Drawing::Size(18, 22);
            this->inputLetterTextBox->TabIndex = 3;
            // 
            // outputSelectedWordsTextBox
            // 
            this->outputSelectedWordsTextBox->Location = System::Drawing::Point(452, 30);
            this->outputSelectedWordsTextBox->Multiline = true;
            this->outputSelectedWordsTextBox->Name = L"outputSelectedWordsTextBox";
            this->outputSelectedWordsTextBox->Size = System::Drawing::Size(407, 70);
            this->outputSelectedWordsTextBox->TabIndex = 4;
            // 
            // outputNotSelectedWordsTextBox
            // 
            this->outputNotSelectedWordsTextBox->Location = System::Drawing::Point(452, 130);
            this->outputNotSelectedWordsTextBox->Multiline = true;
            this->outputNotSelectedWordsTextBox->Name = L"outputNotSelectedWordsTextBox";
            this->outputNotSelectedWordsTextBox->Size = System::Drawing::Size(406, 270);
            this->outputNotSelectedWordsTextBox->TabIndex = 5;
            // 
            // outputSelectedWordsInfoLabel
            // 
            this->outputSelectedWordsInfoLabel->AutoSize = true;
            this->outputSelectedWordsInfoLabel->Location = System::Drawing::Point(447, 9);
            this->outputSelectedWordsInfoLabel->Name = L"outputSelectedWordsInfoLabel";
            this->outputSelectedWordsInfoLabel->Size = System::Drawing::Size(410, 26);
            this->outputSelectedWordsInfoLabel->TabIndex = 6;
            this->outputSelectedWordsInfoLabel->Text = L"Слова, що починаються на задану букву:";
            // 
            // outputNotSelectedWordsInfoLabel
            // 
            this->outputNotSelectedWordsInfoLabel->AutoSize = true;
            this->outputNotSelectedWordsInfoLabel->Location = System::Drawing::Point(448, 105);
            this->outputNotSelectedWordsInfoLabel->Name = L"outputNotSelectedWordsInfoLabel";
            this->outputNotSelectedWordsInfoLabel->Size = System::Drawing::Size(418, 26);
            this->outputNotSelectedWordsInfoLabel->TabIndex = 7;
            this->outputNotSelectedWordsInfoLabel->Text = L"Вивід решти слів у алфавітному порядку:";
            // 
            // sortTextButton
            // 
            this->sortTextButton->Location = System::Drawing::Point(106, 350);
            this->sortTextButton->Name = L"sortTextButton";
            this->sortTextButton->Size = System::Drawing::Size(175, 36);
            this->sortTextButton->TabIndex = 8;
            this->sortTextButton->Text = L"Посортувати";
            this->sortTextButton->UseVisualStyleBackColor = true;
            this->sortTextButton->Click += gcnew System::EventHandler(this, &MainForm::sortTextButton_Click);
            // 
            // outputOtherTextBox
            // 
            this->outputOtherTextBox->Location = System::Drawing::Point(12, 435);
            this->outputOtherTextBox->Multiline = true;
            this->outputOtherTextBox->Name = L"outputOtherTextBox";
            this->outputOtherTextBox->Size = System::Drawing::Size(846,50);
            this->outputOtherTextBox->TabIndex = 4;
            // 
            // outputOtherInfoInfoLabel
            // 
            this->outputOtherInfoInfoLabel->AutoSize = true;
            this->outputOtherInfoInfoLabel->Location = System::Drawing::Point(12, 410);
            this->outputOtherInfoInfoLabel->Name = L"outputOtherInfoInfoLabel";
            this->outputOtherInfoInfoLabel->Size = System::Drawing::Size(410, 26);
            this->outputOtherInfoInfoLabel->TabIndex = 6;
            this->outputOtherInfoInfoLabel->Text = L"Вивід правильних слів, який організовується за допомогою std::copy та std::transform:";
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(13, 26);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(870, 500);
            this->Controls->Add(this->outputOtherInfoInfoLabel);
            this->Controls->Add(this->outputOtherTextBox);
            this->Controls->Add(this->sortTextButton);
            this->Controls->Add(this->outputNotSelectedWordsInfoLabel);
            this->Controls->Add(this->outputSelectedWordsInfoLabel);
            this->Controls->Add(this->outputNotSelectedWordsTextBox);
            this->Controls->Add(this->outputSelectedWordsTextBox);
            this->Controls->Add(this->inputLetterTextBox);
            this->Controls->Add(this->inputLetterInfoLabel);
            this->Controls->Add(this->inputInfoLabel);
            this->Controls->Add(this->inputTextBox);
            this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->Margin = System::Windows::Forms::Padding(5);
            this->Name = L"MainForm";
            this->Text = L"Ширий Богдан. АМО Домашнє завдання №19, варіант №24";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void sortTextButton_Click(System::Object^ sender, System::EventArgs^ e) {
        std::ofstream myfile;
        // Переводимо типи даних з System в std
        std::string input(inputTextBox->Text->Length, ' ');
        for (int i = 0; i < inputTextBox->Text->Length ; i++)
        {
            input[i] = static_cast<char>(inputTextBox->Text[i]);
        }
        input = std::regex_replace(input, std::regex("[^a-zA-Z0-9\\s]"), "");

        char starting_letter = inputLetterTextBox->Text[0];

        // Робота самої програми
        std::vector<size_t> word_indices;
        for (size_t i = 0; i < input.length(); i++) {
            if (i == 0 || input[i - 1] == ' ') {
                word_indices.push_back(i);
            }
        }

        myfile.open("SelectedWords.txt"); // записую результат у файл
        for (const auto& i : word_indices) {
            std::string word = input.substr(i, input.find(' ', i) - i);
            if (std::tolower(word[0]) == std::tolower(starting_letter)) {
                myfile << word << "[" << i << "]" << " ";
            }
        }
        myfile.close();

        // Використовую функцію, яка сортує зі std::sort, оскільки у цьому блоці не
        sort_word_indices(word_indices, input, starting_letter); // можна використовувати лямбда вирази

        // Робота самої програми
        word_indices.clear();
        for (size_t i = 0; i < input.length(); i++) {
            if ((i == 0 || input[i - 1] == ' ') && std::tolower(input[i]) == std::tolower(starting_letter)) {
                word_indices.push_back(i);
            }
        }

        //створення std::map
        std::map<size_t, std::string> word_map;
        for (const auto& i : word_indices) {
            std::string word = input.substr(i, input.find(' ', i) - i);
            if (std::tolower(word[0]) == std::tolower(starting_letter)) {
                word_map[i] = word;
            }
        }

        // Виведення слів та індексів на екран
        myfile.open("Another.txt"); // записую результат у файл
        std::copy(word_indices.begin(), word_indices.end(), std::ostream_iterator<size_t>(myfile, " "));
        myfile << std::endl;
        std::transform(word_map.begin(), word_map.end(), std::ostream_iterator<std::string>(myfile, " "), GetSecond());
        myfile.close();

        //Запис результатів з файлу у TextBox
        StreamReader^ reader = gcnew StreamReader("SelectedWords.txt");
        outputSelectedWordsTextBox->Text = reader->ReadToEnd();
        reader = gcnew StreamReader("NotSelectedWords.txt");
        outputNotSelectedWordsTextBox->Text = reader->ReadToEnd();
        reader = gcnew StreamReader("Another.txt");
        outputOtherTextBox->Text = reader->ReadToEnd();
    }

};
}
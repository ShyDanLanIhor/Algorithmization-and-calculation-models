#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

namespace acmShyryiHW24_1 {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for ShyryiForm
	/// </summary>
	public ref class ShyryiForm : public System::Windows::Forms::Form
	{
		String^ imagePath;
		bool IsInputImage = true, first = true, isChanged = false;



		// ��������� ���� �� �������� ���� � PictureBox
		void LoadAndDisplayImage(String^ imagePath)
		{
			try
			{
				// ����������� ���� � �����
				pictureBox->Image = Image::FromFile(imagePath);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("������� ������������ ����: " + ex->Message);
			}
		}

		// �������� ��䳿 ������������� ����� �� �����
		void ShyryiForm_DragEnter(Object^ sender, DragEventArgs^ e)
		{
			// ��������, �� � ����������� ����� ����������
			if (e->Data->GetDataPresent(DataFormats::FileDrop))
			{
				array<String^>^ files = (array<String^>^)e->Data
					->GetData(DataFormats::FileDrop);
				if (files != nullptr && files->Length > 0)
				{
					String^ fileExtension = Path::GetExtension(files[0]);
					if (fileExtension->Equals(".jpg", 
						StringComparison::InvariantCultureIgnoreCase) ||
						fileExtension->Equals(".jpeg", 
							StringComparison::InvariantCultureIgnoreCase) ||
						fileExtension->Equals(".png", 
							StringComparison::InvariantCultureIgnoreCase))
					{
						e->Effect = DragDropEffects::Copy;
					}
				}
			}
		}

		// �������� ��䳿 ������������� �� ���������� ����� �� �����
		void ShyryiForm_DragDrop(Object^ sender, DragEventArgs^ e)
		{
			// ��������� ������� ������������� �����
			array<String^>^ files = (array<String^>^)e->Data
				->GetData(DataFormats::FileDrop);

			// ������������ �� ����������� ������� ���������� � ������ �����
			if (files != nullptr && files->Length > 0)
			{
				String^ fileExtension = Path::GetExtension(files[0]);
				if (fileExtension->Equals(".jpg", 
					StringComparison::InvariantCultureIgnoreCase) ||
					fileExtension->Equals(".jpeg", 
						StringComparison::InvariantCultureIgnoreCase) ||
					fileExtension->Equals(".png", 
						StringComparison::InvariantCultureIgnoreCase))
				{
					imagePath = files[0];
					File::Delete("inputImage.jpg");
					File::Copy(imagePath, "inputImage.jpg");
					LoadAndDisplayImage(imagePath);

					IsInputImage = true; isChanged = true;
					this->FindFacesButton->Text = L"������ �������";
					this->changeViewButton->Text = 
						L"������ ������� 9 �����";
					this->changeViewButton->Enabled = false;
					this->FindFacesButton->Enabled = true;
				}
			}
		}

	public:
		ShyryiForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			pictureBox->SizeMode = PictureBoxSizeMode::Zoom;

			// ϳ�������� ��������� ���� ������������� ����� �� �����
			AllowDrop = true;
			DragEnter += gcnew DragEventHandler(this, 
				&ShyryiForm::ShyryiForm_DragEnter);
			DragDrop += gcnew DragEventHandler(this, 
				&ShyryiForm::ShyryiForm_DragDrop);

			this->changeViewButton->Enabled = false;
			this->FindFacesButton->Enabled = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShyryiForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Label^ InfoLabel;
	private: System::Windows::Forms::Button^ FindFacesButton;
	private: System::Windows::Forms::Button^ changeViewButton;

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
			this->pictureBox = 
				(gcnew System::Windows::Forms::PictureBox());
			this->InfoLabel = 
				(gcnew System::Windows::Forms::Label());
			this->FindFacesButton = 
				(gcnew System::Windows::Forms::Button());
			this->changeViewButton = 
				(gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel
				::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(8, 38);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(680, 395);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// 
			// InfoLabel
			// 
			this->InfoLabel->AutoSize = true;
			this->InfoLabel->Font = (gcnew System::Drawing
				::Font(L"Times New Roman", 13.8F, System::Drawing
					::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InfoLabel->Location = System::Drawing::Point(12, 9);
			this->InfoLabel->Name = L"InfoLabel";
			this->InfoLabel->Size = System::Drawing::Size(578, 26);
			this->InfoLabel->TabIndex = 1;
			this->InfoLabel->Text = 
				L"���������� ���������� �� ����� �� �������� �� ������.";
			// 
			// FindFacesButton
			// 
			this->FindFacesButton->Font = (gcnew 
				System::Drawing::Font(L"Times New Roman", 13.8F, 
					System::Drawing::FontStyle::Regular, System::Drawing
					::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->FindFacesButton->Location = System::Drawing::Point(367, 439);
			this->FindFacesButton->Name = L"FindFacesButton";
			this->FindFacesButton->Size = System::Drawing::Size(321, 36);
			this->FindFacesButton->TabIndex = 2;
			this->FindFacesButton->Text = L"���������� ����";
			this->FindFacesButton->UseVisualStyleBackColor = true;
			this->FindFacesButton->Click += gcnew System
				::EventHandler(this, &ShyryiForm::FindFacesButton_Click);
			// 
			// changeViewButton
			// 
			this->changeViewButton->Font = (gcnew System::Drawing
				::Font(L"Times New Roman", 13.8F, System::Drawing
					::FontStyle::Regular, System::Drawing
					::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->changeViewButton->Location = System::Drawing::Point(12, 439);
			this->changeViewButton->Name = L"changeViewButton";
			this->changeViewButton->Size = System::Drawing::Size(349, 36);
			this->changeViewButton->TabIndex = 3;
			this->changeViewButton->Text = L"���� ���� ��� �������";
			this->changeViewButton->UseVisualStyleBackColor = true;
			this->changeViewButton->Click += gcnew System
				::EventHandler(this, &ShyryiForm::changeViewButton_Click);
			// 
			// ShyryiForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->changeViewButton);
			this->Controls->Add(this->FindFacesButton);
			this->Controls->Add(this->InfoLabel);
			this->Controls->Add(this->pictureBox);
			this->Name = L"ShyryiForm";
			this->Text = L"����� ������. ��� ������ �������� �24.1, ������ �24";
			(cli::safe_cast<System::ComponentModel
				::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FindFacesButton_Click
		   (System::Object^ sender, System::EventArgs^ e) {

		// ������������ ����
		cv::Mat image = cv::imread("inputImage.jpg");

		// ����������� � ������ ����� (��� ���������� ������ ���������)
		cv::Mat gray;
		cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

		// ������������ ���������� ������������� �������
		cv::CascadeClassifier faceCascade;
		// ���������� ���� �� ������ ����� XML ���������� ������������� �������
		faceCascade.load("haarcascade_frontalface_alt.xml"); 

		// ��������� �������
		std::vector<cv::Rect> faces;
		faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0, cv::Size(30, 30));

		// ��� �������� �������
		int maxFaces = 9; // ����������� ������� �����, ��� �� ������ �������
		int numFaces = std::min(static_cast<int>(faces.size()), maxFaces);

		// ���������� ����� ������ ��� �������
		for (int i = 0; i < numFaces; ++i)
		{
			cv::Point center(faces[i].x + faces[i].width / 2, 
				faces[i].y + faces[i].height / 2);
			cv::Size axes(faces[i].width / 2, faces[i].height / 2);
			cv::ellipse(image, center, axes, 0, 0, 360, 
				cv::Scalar(0, 255, 0), 2);
		}

		// ���������� ���������� � ���� .jpg
		cv::imwrite("outputImage.jpg", image);
		cv::imwrite("outputImage2.jpg", image);

		// ���� ����������
		first ? 
			LoadAndDisplayImage("outputImage.jpg") : 
			LoadAndDisplayImage("outputImage2.jpg");
		first = isChanged ? !first : first; 
		IsInputImage = false; isChanged = false;
		this->changeViewButton->Text = L"�������� ��������� ����";
		this->changeViewButton->Enabled = true;
		this->FindFacesButton->Text = L"���������� ������ ����";
		this->FindFacesButton->Enabled = false;
	}
private: System::Void changeViewButton_Click
	   (System::Object^ sender, System::EventArgs^ e) {
	if (IsInputImage)
	{
		IsInputImage = false;
		!first ? 
			LoadAndDisplayImage("outputImage.jpg") : 
			LoadAndDisplayImage("outputImage2.jpg");
		this->changeViewButton->Text = L"�������� ��������� ����";
	}
	else
	{
		IsInputImage = true;
		LoadAndDisplayImage(imagePath);
		this->changeViewButton->Text = L"�������� ��������� ����";
	}
}
};
}

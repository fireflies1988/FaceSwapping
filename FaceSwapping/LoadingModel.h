#pragma once
#include "MyForm.h"

namespace FaceSwapping {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoadingModel
	/// </summary>
	public ref class LoadingModel : public System::Windows::Forms::Form
	{
	public:
		LoadingModel(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			faceDetector.load("haarcascade_frontalface_alt2.xml");
			if (faceDetector.empty()) {
				cout << "Could not load face detector!" << endl;
				Application::Exit();
				return;
			}
			cout << "Face detector loaded." << endl;
			progressBar1->Value = 30;

			// Create an instance of Facemark and load model for face landmark detector
			facemark = createFacemarkLBF();
			facemark->loadModel("lbfmodel.yaml");
			if (facemark.empty()) {
				cout << "Could not load landmark detector!" << endl;
				Application::Exit();
				return;
			}
			cout << "Model for face landmark detection loaded." << endl;
			progressBar1->Value = 100;
			FaceSwapping::MyForm form;
			Application::Run(% form);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoadingModel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label1;
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
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(82, 163);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(453, 41);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(79, 131);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Loading...Please wait...";
			// 
			// LoadingModel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 233);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->Name = L"LoadingModel";
			this->Text = L"LoadingModel";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

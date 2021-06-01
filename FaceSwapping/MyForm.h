#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <msclr\marshal_cppstd.h>
#include <iostream>

namespace FaceSwapping {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace cv;
	using namespace std;
	using namespace cv::face;

	Mat src, dst, dstWarped, result, img;
	CascadeClassifier faceDetector;
	Ptr<Facemark> facemark;
	vector<Point2f> landmarks1, landmarks2, landmarks3, frameLandmarks;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ buttonProcess;
	private: System::Windows::Forms::Button^ buttonLoadDst;
	private: System::Windows::Forms::Button^ buttonLoadSrc;
	private: System::Windows::Forms::PictureBox^ pictureBoxRes;
	private: System::Windows::Forms::PictureBox^ pictureBoxDst;
	private: System::Windows::Forms::PictureBox^ pictureBoxSrc;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::GroupBox^ groupBox5;


	private: System::Windows::Forms::Button^ buttonStart;

	private: System::Windows::Forms::Button^ buttonLoadImg;

	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::PictureBox^ pictureBoxImg;
	private: System::Windows::Forms::PictureBox^ pictureBoxCam;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::Label^ labelStatus2;
	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::Label^ labelStatus1a;
	private: System::Windows::Forms::Label^ labelStatus1b;













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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->labelStatus1b = (gcnew System::Windows::Forms::Label());
			this->labelStatus1a = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonProcess = (gcnew System::Windows::Forms::Button());
			this->buttonLoadDst = (gcnew System::Windows::Forms::Button());
			this->buttonLoadSrc = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxRes = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxDst = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxSrc = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->labelStatus2 = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->buttonLoadImg = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxCam = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxImg = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxRes))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDst))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSrc))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCam))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxImg))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1201, 754);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox9);
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 31);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1193, 719);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Img";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->labelStatus1b);
			this->groupBox9->Controls->Add(this->labelStatus1a);
			this->groupBox9->Location = System::Drawing::Point(22, 616);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(1150, 95);
			this->groupBox9->TabIndex = 3;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Status bar";
			// 
			// labelStatus1b
			// 
			this->labelStatus1b->AutoSize = true;
			this->labelStatus1b->ForeColor = System::Drawing::Color::Red;
			this->labelStatus1b->Location = System::Drawing::Point(21, 57);
			this->labelStatus1b->Name = L"labelStatus1b";
			this->labelStatus1b->Size = System::Drawing::Size(566, 24);
			this->labelStatus1b->TabIndex = 1;
			this->labelStatus1b->Text = L"Dst image: No image found. Click \"Load dst image\" to choose one.";
			// 
			// labelStatus1a
			// 
			this->labelStatus1a->AutoSize = true;
			this->labelStatus1a->ForeColor = System::Drawing::Color::Red;
			this->labelStatus1a->Location = System::Drawing::Point(21, 33);
			this->labelStatus1a->Name = L"labelStatus1a";
			this->labelStatus1a->Size = System::Drawing::Size(569, 24);
			this->labelStatus1a->TabIndex = 0;
			this->labelStatus1a->Text = L"Src image: No image found. Click \"Load src image\" to choose one.";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->buttonSave);
			this->groupBox4->Controls->Add(this->buttonProcess);
			this->groupBox4->Controls->Add(this->buttonLoadDst);
			this->groupBox4->Controls->Add(this->buttonLoadSrc);
			this->groupBox4->Location = System::Drawing::Point(958, 16);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(214, 591);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Control";
			// 
			// buttonSave
			// 
			this->buttonSave->Enabled = false;
			this->buttonSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSave->Location = System::Drawing::Point(25, 185);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(164, 38);
			this->buttonSave->TabIndex = 3;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &MyForm::buttonSave_Click);
			// 
			// buttonProcess
			// 
			this->buttonProcess->Enabled = false;
			this->buttonProcess->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonProcess->Location = System::Drawing::Point(25, 135);
			this->buttonProcess->Name = L"buttonProcess";
			this->buttonProcess->Size = System::Drawing::Size(164, 38);
			this->buttonProcess->TabIndex = 2;
			this->buttonProcess->Text = L"Process";
			this->buttonProcess->UseVisualStyleBackColor = true;
			this->buttonProcess->Click += gcnew System::EventHandler(this, &MyForm::buttonProcess_Click);
			// 
			// buttonLoadDst
			// 
			this->buttonLoadDst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLoadDst->Location = System::Drawing::Point(25, 86);
			this->buttonLoadDst->Name = L"buttonLoadDst";
			this->buttonLoadDst->Size = System::Drawing::Size(164, 38);
			this->buttonLoadDst->TabIndex = 1;
			this->buttonLoadDst->Text = L"Load dst image";
			this->buttonLoadDst->UseVisualStyleBackColor = true;
			this->buttonLoadDst->Click += gcnew System::EventHandler(this, &MyForm::buttonLoadDst_Click);
			// 
			// buttonLoadSrc
			// 
			this->buttonLoadSrc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLoadSrc->Location = System::Drawing::Point(25, 37);
			this->buttonLoadSrc->Name = L"buttonLoadSrc";
			this->buttonLoadSrc->Size = System::Drawing::Size(164, 38);
			this->buttonLoadSrc->TabIndex = 0;
			this->buttonLoadSrc->Text = L"Load src image";
			this->buttonLoadSrc->UseVisualStyleBackColor = true;
			this->buttonLoadSrc->Click += gcnew System::EventHandler(this, &MyForm::buttonLoadSrc_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->pictureBoxRes);
			this->groupBox3->Location = System::Drawing::Point(385, 16);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(551, 591);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Result";
			// 
			// pictureBoxRes
			// 
			this->pictureBoxRes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxRes->Location = System::Drawing::Point(3, 24);
			this->pictureBoxRes->Name = L"pictureBoxRes";
			this->pictureBoxRes->Size = System::Drawing::Size(545, 564);
			this->pictureBoxRes->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxRes->TabIndex = 0;
			this->pictureBoxRes->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->pictureBoxDst);
			this->groupBox2->Location = System::Drawing::Point(19, 320);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(345, 287);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Destination image";
			// 
			// pictureBoxDst
			// 
			this->pictureBoxDst->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxDst->Location = System::Drawing::Point(3, 24);
			this->pictureBoxDst->Name = L"pictureBoxDst";
			this->pictureBoxDst->Size = System::Drawing::Size(339, 260);
			this->pictureBoxDst->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxDst->TabIndex = 1;
			this->pictureBoxDst->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->pictureBoxSrc);
			this->groupBox1->Location = System::Drawing::Point(19, 16);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(345, 287);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Source image";
			// 
			// pictureBoxSrc
			// 
			this->pictureBoxSrc->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxSrc->Location = System::Drawing::Point(3, 24);
			this->pictureBoxSrc->Name = L"pictureBoxSrc";
			this->pictureBoxSrc->Size = System::Drawing::Size(339, 260);
			this->pictureBoxSrc->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxSrc->TabIndex = 0;
			this->pictureBoxSrc->TabStop = false;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox8);
			this->tabPage2->Controls->Add(this->groupBox7);
			this->tabPage2->Controls->Add(this->groupBox6);
			this->tabPage2->Controls->Add(this->groupBox5);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1193, 725);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Cam";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->labelStatus2);
			this->groupBox8->Location = System::Drawing::Point(17, 641);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(1148, 70);
			this->groupBox8->TabIndex = 4;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Status bar";
			// 
			// labelStatus2
			// 
			this->labelStatus2->AutoSize = true;
			this->labelStatus2->ForeColor = System::Drawing::Color::Red;
			this->labelStatus2->Location = System::Drawing::Point(16, 33);
			this->labelStatus2->Name = L"labelStatus2";
			this->labelStatus2->Size = System::Drawing::Size(444, 24);
			this->labelStatus2->TabIndex = 0;
			this->labelStatus2->Text = L"No image found. Click \"Load image\" to choose one.";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->buttonStop);
			this->groupBox7->Controls->Add(this->buttonStart);
			this->groupBox7->Controls->Add(this->buttonLoadImg);
			this->groupBox7->Location = System::Drawing::Point(17, 439);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(371, 196);
			this->groupBox7->TabIndex = 5;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Control";
			// 
			// buttonStop
			// 
			this->buttonStop->Enabled = false;
			this->buttonStop->Location = System::Drawing::Point(207, 103);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(144, 43);
			this->buttonStop->TabIndex = 4;
			this->buttonStop->Text = L"Stop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm::buttonStop_Click);
			// 
			// buttonStart
			// 
			this->buttonStart->Enabled = false;
			this->buttonStart->Location = System::Drawing::Point(207, 43);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(144, 43);
			this->buttonStart->TabIndex = 3;
			this->buttonStart->Text = L"Run";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &MyForm::buttonStart_Click);
			// 
			// buttonLoadImg
			// 
			this->buttonLoadImg->Location = System::Drawing::Point(20, 43);
			this->buttonLoadImg->Name = L"buttonLoadImg";
			this->buttonLoadImg->Size = System::Drawing::Size(144, 43);
			this->buttonLoadImg->TabIndex = 2;
			this->buttonLoadImg->Text = L"Load image";
			this->buttonLoadImg->UseVisualStyleBackColor = true;
			this->buttonLoadImg->Click += gcnew System::EventHandler(this, &MyForm::buttonLoadImg_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->pictureBoxCam);
			this->groupBox6->Location = System::Drawing::Point(412, 15);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(756, 620);
			this->groupBox6->TabIndex = 1;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Cam";
			// 
			// pictureBoxCam
			// 
			this->pictureBoxCam->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxCam->Location = System::Drawing::Point(3, 24);
			this->pictureBoxCam->Name = L"pictureBoxCam";
			this->pictureBoxCam->Size = System::Drawing::Size(750, 593);
			this->pictureBoxCam->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxCam->TabIndex = 0;
			this->pictureBoxCam->TabStop = false;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->pictureBoxImg);
			this->groupBox5->Location = System::Drawing::Point(17, 15);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(371, 409);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Image";
			// 
			// pictureBoxImg
			// 
			this->pictureBoxImg->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxImg->Location = System::Drawing::Point(3, 24);
			this->pictureBoxImg->Name = L"pictureBoxImg";
			this->pictureBoxImg->Size = System::Drawing::Size(365, 382);
			this->pictureBoxImg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxImg->TabIndex = 0;
			this->pictureBoxImg->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"JPEG (*.jpg)|*.jpg|PNG (*.png)|*.png|All files (*.*)|(*.*)";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1201, 754);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Face Swapping";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxRes))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDst))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSrc))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCam))->EndInit();
			this->groupBox5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxImg))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
bool bFacialLandmarksDetected(CascadeClassifier faceDetector, Ptr<Facemark> facemark, Mat img, vector<Point2f>& res) {
	// Detect possible face regions and store it in a vector<Rect> faces
	vector<Rect> faces;
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	equalizeHist(gray, gray);
	faceDetector.detectMultiScale(gray, faces, 1.1, 3, 0, cv::Size(30, 30));
	if (faces.empty()) {
		return false;
	}

	// Detect facial landmarks of all detected faces in the image
	// Save the facial landmarks of the first face detected to res
	vector<vector<Point2f>> landmarks;
	facemark->fit(img, faces, landmarks);
	for (int j = 0; j < landmarks[0].size(); j++) {
		res.push_back(landmarks[0][j]);
	}
	return true;
}
// Calculate Delaunay triangles for set of points
// Returns the vector of indices of 3 points for each triangle
void calculateDelaunayTriangles(Rect rect, vector<Point2f> points, vector<vector<int>>& delaunayTri) {
	// Create an instance of Subdiv2D (empty Delaunay subdivision)
	Subdiv2D subdiv(rect);

	// Insert points into subdiv
	for (vector<Point2f>::iterator it = points.begin(); it != points.end(); it++) {
		if (rect.contains(*it)) {
			subdiv.insert(*it);
		}
	}

	vector<Vec6f> triangleList;
	subdiv.getTriangleList(triangleList);
	vector<Point2f> pt(3);
	vector<int> ind(3);

	for (size_t i = 0; i < triangleList.size(); i++)
	{
		Vec6f t = triangleList[i];
		pt[0] = Point2f(t[0], t[1]);
		pt[1] = Point2f(t[2], t[3]);
		pt[2] = Point2f(t[4], t[5]);
		for (int j = 0; j < 3; j++) {
			for (size_t k = 0; k < points.size(); k++) {
				/*if (abs(pt[j].x - points[k].x) < 1.0 && abs(pt[j].y - points[k].y) < 1.0)
					ind[j] = k;*/
				if (pt[j].x == points[k].x && pt[j].y == points[k].y) {
					ind[j] = k;
					break;
				}
			}
		}
		delaunayTri.push_back(ind);
	}
}
// Warps and alpha blends triangular regions from img1 and img2 to img
void warpTriangle(Mat img1, Mat& img2, vector<Point2f> triangle1, vector<Point2f> triangle2)
{
	// Find bounding rectangle for each triangle
	Rect r1 = boundingRect(triangle1);
	Rect r2 = boundingRect(triangle2);

	// Offset points by left top corner of the respective rectangles
	vector<Point2f> tri1Cropped, tri2Cropped;
	vector<cv::Point> tri2CroppedInt;
	for (int i = 0; i < 3; i++)
	{
		tri1Cropped.push_back(Point2f(triangle1[i].x - r1.x, triangle1[i].y - r1.y));
		tri2Cropped.push_back(Point2f(triangle2[i].x - r2.x, triangle2[i].y - r2.y));
		// fillConvexPoly needs a vector of Point and not Point2f
		tri2CroppedInt.push_back(cv::Point(triangle2[i].x - r2.x, triangle2[i].y - r2.y));

	}
	// Apply warpImage to small rectangular patches
	Mat img1Cropped;
	img1(r1).copyTo(img1Cropped);
	Mat img2Cropped = Mat::zeros(r2.height, r2.width, img1Cropped.type());

	// Given a pair of triangles, find the affine transform
	Mat warpMat = getAffineTransform(tri1Cropped, tri2Cropped);

	// Apply the Affine Transform just found to the src image
	warpAffine(img1Cropped, img2Cropped, warpMat, img2Cropped.size(), INTER_LINEAR, BORDER_REFLECT_101);

	// Get mask by filling triangle
	Mat mask = Mat::zeros(r2.height, r2.width, CV_32FC3);
	fillConvexPoly(mask, tri2CroppedInt, Scalar(1.0, 1.0, 1.0), 16, 0);

	// Copy triangular region of the rectangular patch to the output image
	multiply(img2Cropped, mask, img2Cropped);
	multiply(img2(r2), Scalar(1.0, 1.0, 1.0) - mask, img2(r2));
	img2(r2) = img2(r2) + img2Cropped;
}
private: char* convertStringToChar(System::String^ str) {
	char* temp = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
	return temp;
}
Bitmap^ convertMatToBitmap(Mat matToConvert) {
	//return gcnew Bitmap(matToConvert.cols, matToConvert.rows, 4 * matToConvert.rows, System::Drawing::Imaging::PixelFormat::Format4bppIndexed, IntPtr(matToConvert.data));
	cvtColor(matToConvert, matToConvert, COLOR_BGR2BGRA);
	HBITMAP hBit = CreateBitmap(matToConvert.cols, matToConvert.rows, 1, 32, matToConvert.data);
	Bitmap^ bmp = Bitmap::FromHbitmap((IntPtr)hBit);
	DeleteObject(hBit);
	return bmp;
}
std::string convertSysStringToStdString(System::String^ str) {
	msclr::interop::marshal_context context;
	return context.marshal_as<std::string>(str);
}




bool srcFlag = false, dstFlag = false, flag = true; // flag for stopping capturing
bool isRunning = false; // cam is running if isRunning == true;
private: System::Void buttonLoadSrc_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		pictureBoxSrc->ImageLocation = openFileDialog1->FileName;
		src = imread(convertSysStringToStdString(pictureBoxSrc->ImageLocation));

		// Resize the images for better performance
		resize(src, src, cv::Size(), 0.7, 0.7, INTER_LINEAR_EXACT);

		// Get facial landmarks of the src image
		landmarks1.clear();
		if (!bFacialLandmarksDetected(faceDetector, facemark, src, landmarks1)) {
			labelStatus1a->ForeColor = Color::Red;
			labelStatus1a->Text = "Src image: No face detected in the src image. Please choose another image.";
			srcFlag = false;
			buttonProcess->Enabled = srcFlag && dstFlag;
		}
		else {
			labelStatus1a->ForeColor = Color::Green;
			labelStatus1a->Text = "Src image: Valid.";

			// Enable buttonProcess when srcFlag and dstFlag are true
			srcFlag = true;
			buttonProcess->Enabled = srcFlag && dstFlag;

			// Convert Mat to float data type
			src.convertTo(src, CV_32F);
		}
	}
}
private: System::Void buttonLoadDst_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		pictureBoxDst->ImageLocation = openFileDialog1->FileName;
		dst = imread(convertStringToChar(pictureBoxDst->ImageLocation));

		// Resize the images for better performance
		resize(dst, dst, cv::Size(), 0.7, 0.7, INTER_LINEAR_EXACT);

		// Get facial landmarks of the dst image
		landmarks2.clear();
		if (!bFacialLandmarksDetected(faceDetector, facemark, dst, landmarks2)) {
			labelStatus1b->ForeColor = Color::Red;
			labelStatus1b->Text = "Dst image: No face detected in the dst image. Please choose another image.";
			dstFlag = false;
			buttonProcess->Enabled = srcFlag && dstFlag;
		}
		else {
			labelStatus1b->ForeColor = Color::Green;
			labelStatus1b->Text = "Dst image: Valid.";

			// Enable buttonProcess when srcFlag and dstFlag are true
			dstFlag = true;
			buttonProcess->Enabled = srcFlag && dstFlag;
		}

	}
}
private: System::Void buttonProcess_Click(System::Object^ sender, System::EventArgs^ e) {
	// Convert Mat to float data type
	dstWarped = dst.clone();
	dstWarped.convertTo(dstWarped, CV_32F);

	// Find convex hull of one or the other
	vector<Point2f> hull1;
	vector<Point2f> hull2;
	vector<int> hullIndex;
	convexHull(landmarks2, hullIndex, false, false);
	for (int i = 0; i < hullIndex.size(); i++)
	{
		hull1.push_back(landmarks1[hullIndex[i]]);
		hull2.push_back(landmarks2[hullIndex[i]]);
	}

	// Find Delaunay Triangulation for points on the convex hull
	vector<vector<int>> triangles;
	Rect rect(0, 0, dstWarped.cols, dstWarped.rows);
	calculateDelaunayTriangles(rect, hull2, triangles);

	// Apply affine transformation to Delaunay triangles
	for (size_t i = 0; i < triangles.size(); i++)
	{
		vector<Point2f> triangle1, triangle2;
		// Get points for img1, img2 corresponding to the triangles
		for (size_t j = 0; j < 3; j++)
		{
			triangle1.push_back(hull1[triangles[i][j]]);
			triangle2.push_back(hull2[triangles[i][j]]);
		}
		warpTriangle(src, dstWarped, triangle1, triangle2);
	}

	// Calculate mask
	// fillConvexPoly needs a vector of Point and not Point2f
	vector<cv::Point> hull8U;
	for (int i = 0; i < hull2.size(); i++)
	{
		hull8U.push_back(cv::Point(hull2[i].x, hull2[i].y));
	}
	Mat mask = Mat::zeros(dst.rows, dst.cols, dst.depth());
	fillConvexPoly(mask, hull8U, Scalar(255, 255, 255));

	// Clone seamlessly.
	Rect r = boundingRect(hull2);
	cv::Point center = (r.tl() + r.br()) / 2;
	dstWarped.convertTo(dstWarped, CV_8UC3);
	seamlessClone(dstWarped, dst, mask, center, result, NORMAL_CLONE);
	pictureBoxRes->Image = convertMatToBitmap(result);

	// Enable buttonSave when the images have been processed
	buttonSave->Enabled = true;
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	// Load face detector
	faceDetector.load("haarcascade_frontalface_alt2.xml");
	if (faceDetector.empty()) {
		cout << "Could not load face detector!" << endl;
		Application::Exit();
		return;
	}
	cout << "Face detector loaded." << endl;

	// Create an instance of Facemark and load model for face landmark detector
	facemark = createFacemarkLBF();
	facemark->loadModel("lbfmodel.yaml");
	if (facemark.empty()) {
		cout << "Could not load landmark detector!" << endl;
		Application::Exit();
		return;
	}
	cout << "Model for face landmark detection loaded." << endl;
}
private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		imwrite(convertSysStringToStdString(saveFileDialog1->FileName), result);
		MessageBox::Show("Successfully saved.", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void buttonLoadImg_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		pictureBoxImg->ImageLocation = openFileDialog1->FileName;
		img = imread(convertSysStringToStdString(pictureBoxImg->ImageLocation));

		// Resize the images for better performance
		resize(img, img, cv::Size(), 0.7, 0.7, INTER_LINEAR_EXACT);

		// Get facial landmarks of the image
		landmarks3.clear();
		if (!bFacialLandmarksDetected(faceDetector, facemark, img, landmarks3)) {
			labelStatus2->ForeColor = Color::Red;
			labelStatus2->Text = "No face detected in the image. Please choose another image.";
			flag = false;
			buttonStop->Enabled = false;
			buttonStart->Enabled = false;
		}
		else {
			labelStatus2->ForeColor = Color::Green;
			labelStatus2->Text = "Face swap camera is ready. Click \"Run\" to start capturing.";
			// Enable buttonStart when the image is loaded
			if (!isRunning) {
				buttonStart->Enabled = true;
			}

			// Convert Mat to float data type
			img.convertTo(img, CV_32F);
		}

	}
}
private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonStart->Enabled = false;
	buttonStop->Enabled = true;
	labelStatus2->ForeColor = Color::Green;
	labelStatus2->Text = "Face swap camera is running (Click \"Stop\" to stop capturing).";

	// Open the fault video camera
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "Can't open the video camera!" << endl;
	}

	// read frames
	Mat frame;
	//cap.set(CAP_PROP_FRAME_HEIGHT, cap.get(CAP_PROP_FRAME_HEIGHT) * 0.5f);
	//cap.set(CAP_PROP_FRAME_WIDTH, cap.get(CAP_PROP_FRAME_WIDTH) * 0.5f);
	while (cap.read(frame) && flag) {
		isRunning = true;
		Mat frameWarped = frame.clone();

		frameLandmarks.clear();
		if (!bFacialLandmarksDetected(faceDetector, facemark, frame, frameLandmarks)) {
			continue;
		}

		frameWarped.convertTo(frameWarped, CV_32F);

		// Find convex hull of one or the other
		vector<Point2f> hull1;
		vector<Point2f> hull2;
		vector<int> hullIndex;
		convexHull(frameLandmarks, hullIndex, false, false);
		for (int i = 0; i < hullIndex.size(); i++)
		{
			hull1.push_back(landmarks3[hullIndex[i]]);
			hull2.push_back(frameLandmarks[hullIndex[i]]);
		}

		// Find Delaunay Triangulation for points on the convex hull
		vector<vector<int>> triangles;
		Rect rect(0, 0, frameWarped.cols, frameWarped.rows);
		calculateDelaunayTriangles(rect, hull2, triangles);

		// Apply affine transformation to Delaunay triangles
		for (size_t i = 0; i < triangles.size(); i++)
		{
			vector<Point2f> triangle1, triangle2;
			// Get points for img1, img2 corresponding to the triangles
			for (size_t j = 0; j < 3; j++)
			{
				triangle1.push_back(hull1[triangles[i][j]]);
				triangle2.push_back(hull2[triangles[i][j]]);
			}
			warpTriangle(img, frameWarped, triangle1, triangle2);
		}

		// Calculate mask
		// fillConvexPoly needs a vector of Point and not Point2f
		vector<cv::Point> hull8U;
		for (int i = 0; i < hull2.size(); i++)
		{
			hull8U.push_back(cv::Point(hull2[i].x, hull2[i].y));
		}
		Mat mask = Mat::zeros(frame.rows - 10, frame.cols - 10, frame.depth());
		fillConvexPoly(mask, hull8U, Scalar(255, 255, 255));

		// Clone seamlessly.
		Rect r = boundingRect(hull2);
		cv::Point center = (r.tl() + r.br()) / 2;
		Mat output;
		frameWarped.convertTo(frameWarped, CV_8UC3);
		try {
			seamlessClone(frameWarped, frame, mask, center, output, NORMAL_CLONE);
		}
		catch (exception ex) {
			labelStatus2->ForeColor = Color::Red;
			labelStatus2->Text = "Error running: Please click “Run” to start again.";
			buttonStart->Enabled = true;
			buttonStop->Enabled = false;
			break;
		}
		pictureBoxCam->Image = convertMatToBitmap(output);

		waitKey(1);
	}
	pictureBoxCam->Image = nullptr;
	flag = true;
	isRunning = false;
}
private: System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) {
	flag = false;
	buttonStart->Enabled = true;
	buttonStop->Enabled = false;
	labelStatus2->ForeColor = Color::Green;
	labelStatus2->Text = "Face swap camera is ready. Click \"Run\" to start capturing.";
}
};
}

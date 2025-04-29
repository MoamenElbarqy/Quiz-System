#pragma once
#include <iomanip>
#include "Input.h"
#include "HeaderScreen.h"
#include "CreateNewQuiz.h"
#include "EditDraftQuiz.h"
#include "PublishQuiz.h"
#include "ViewQuizReports.h"
#include "DeleteQuiz.h"

class TeacherMainMenu : private HeaderScreen
{
private:
	enum TeacherOptions {
		CreateQuiz = 1,
		EditDraftQuiz = 2,
		PublishQuiz = 3,
		ViewReports = 4,
		DeleteQuiz = 5,
		Exit = 6
	};

	
	static void BackToTeacherMainMenu()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Teacher Main Menu...\n";
		system("pause>0");
		TeacherMainMenu::Show();
	}

	static void PerformTeacherMenuOptions(TeacherOptions option)
	{
		switch (option)
		{
		case TeacherOptions::CreateQuiz:
			CreateNewQuiz::Show();
			BackToTeacherMainMenu();
			break;
		case TeacherOptions::EditDraftQuiz:
			EditDraftQuiz::Show();
			BackToTeacherMainMenu();
			break;
		case TeacherOptions::PublishQuiz:
			PublishQuiz::Show();
			BackToTeacherMainMenu();
			break;
		case TeacherOptions::ViewReports:
			ViewQuizReports::Show();
			BackToTeacherMainMenu();
			break;
		case TeacherOptions::DeleteQuiz:
			DeleteQuiz::Show();
			BackToTeacherMainMenu();
			break;
		case TeacherOptions::Exit:
			break;
		}
	}

public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\tTeacher Main Menu Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTeacher Menu Options\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Create New Quiz.\n";
		cout << setw(37) << left << "" << "\t[2] Edit Drafted Quiz.\n";
		cout << setw(37) << left << "" << "\t[3] Publish Quiz.\n";
		cout << setw(37) << left << "" << "\t[4] View Quiz Reports.\n";
		cout << setw(37) << left << "" << "\t[5] Delete Quiz.\n";
		cout << setw(37) << left << "" << "\t[6] Exit.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "Choose What Do you Want to Do: ";
		PerformTeacherMenuOptions(TeacherOptions(Input::ReadNumberBetween(1, 6)));
	}
};

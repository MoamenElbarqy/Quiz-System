#pragma once
#include "HeaderScreen.h"
#include "ViewQuizzes.h"
class DeletedQuizzes : private ViewQuizzes
{
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\t Deleted Exams");

		vector<Quiz> deletedQuizzes = Quiz::LoadDeletedQuizzes();
		if (deletedQuizzes.empty())
		{
			cout << "\nNo deleted exams found.\n";
			return;
		}

		ShowQuizTable(deletedQuizzes);
	}
};
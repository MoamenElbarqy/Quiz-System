#pragma once
#pragma once
#include "HeaderScreen.h"
#include "ViewQuizzes.h"
class DraftedQuizzes : private ViewQuizzes
{

public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\t Drafted Exams");

		vector<Quiz> draftedQuizzes = Quiz::LoadDraftedQuizzes();
		if (draftedQuizzes.empty())
		{
			cout << "\nNo drafted exams found.\n";
			return;
		}

		ShowQuizTable(draftedQuizzes);
	}
};
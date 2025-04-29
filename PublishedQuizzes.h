#pragma once
#include "HeaderScreen.h"
#include "ViewQuizzes.h"
class PublishedQuizzes : private ViewQuizzes
{
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\t Published Exams");

		vector<Quiz> publishedQuizzes = Quiz::LoadPublishedQuizzes();
		if (publishedQuizzes.empty())
		{
			cout << "\nNo published exams found.\n";
			return;
		}

		ShowQuizTable(publishedQuizzes);
	}
};
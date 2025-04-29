#pragma once
#include "HeaderScreen.h"
#include "Quiz.h" 
#include <iostream>
#include <vector>


class ViewQuizReports : private HeaderScreen
{
private:

	static void ShowTableHeader()
	{
		cout << "\t-------------------------------------------------------------------------------------------------\n";
		cout << "\t|    ID    |          Title            |  No. of Qs. | Qs. Degree | Total Quiz Degrees |  Status\n";
		cout << "\t-------------------------------------------------------------------------------------------------\n";
	}
	static void ShowTableRows(vector<Quiz> &vec,string status)
	{
		for (Quiz quiz : vec)
		{
			cout << "\t|" << setw(10) << left << quiz.getID();
			cout << "|" << setw(27) << left << quiz.getTitle();
			cout << "|" << setw(13) << left << quiz.getNumberOfQs();
			cout << "|" << setw(12) << left << quiz.getQsDegree();
			cout << "|" << setw(20) << left << quiz.getTotalDegrees();
			cout << "|" << setw(9) << left << status;
			cout << endl;
		}
	}
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\t View Quizzes Reports Screen ");

		vector<Quiz> publishedQuizzes = Quiz::LoadPublishedQuizzes();
		vector<Quiz> draftedQuizzes = Quiz::LoadDeletedQuizzes();
		vector<Quiz> deletedQuizzes = Quiz::LoadDeletedQuizzes();

		ShowTableHeader();
		ShowTableRows(publishedQuizzes, "Published");
		ShowTableRows(draftedQuizzes, "Drafted");
		ShowTableRows(deletedQuizzes, "Deleted");
		
		cout << "\t------------------------------------------------------------------------------------------------------------------------\n";

	}

};

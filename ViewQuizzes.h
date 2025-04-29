#pragma once
#include "Quiz.h"
#include "Util.h"
#include "HeaderScreen.h"
#include <iomanip>
#include <vector>

class ViewQuizzes : protected HeaderScreen
{
protected:
	static void ShowTableHeader()
	{
		cout << "\t-------------------------------------------------------------------------------------------------\n";
		cout << "\t|  Quiz ID  |   Title                    |  Questions |  Points/Q  |  Time (min)  |  Created By  \n";
		cout << "\t-------------------------------------------------------------------------------------------------\n";
	}

	static void ShowTableRows(vector<Quiz>& quizzes)
	{
		for (Quiz& quiz : quizzes)
		{
			cout << "\t|" << setw(11) << left << quiz.getID();
			cout << "|" << setw(28) << left << quiz.getTitle();
			cout << "|" << setw(12) << left << quiz.getNumberOfQs();
			cout << "|" << setw(11) << left << quiz.getQsDegree();
			cout << "|" << setw(13) << left << quiz.getTimeLimit();
			cout << "|" << setw(13) << left << quiz.getCreatedBy();
			cout << endl;
		}
	}

	static void ShowTableFooter()
	{
		cout << "\t-----------------------------------------------------------------------------------------------\n";
	}

	static void ShowQuizTable(vector<Quiz>& quizzes)
	{
		ShowTableHeader();
		ShowTableRows(quizzes);
		ShowTableFooter();
	}
};
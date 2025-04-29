#pragma once
#include "HeaderScreen.h"
class EditDraftQuiz : private HeaderScreen
{
private:
public:
	static void Show()
	{
		DrawScreenHeader("\t Edit Drafted Quiz Screen ");

		cout << "Please Enter Quiz Id You Want To Edit : ";
		string quizID = Input::ReadString();

		vector<Quiz> draftedQuizzes = Quiz::LoadDraftedQuizzes();

		for (Quiz& cur_quiz : draftedQuizzes)
		{
			if (cur_quiz.getID() == quizID && SystemUser->getFullName() == cur_quiz.getCreatedBy())
			{
				cur_quiz.ReadQuizInfo();
				Quiz::LoadDataToDrafted(draftedQuizzes);
				cout << "\n========================================\n";
				cout << " Quiz Edited Successfuly :-) \n";
				cout << "========================================\n";
				return;
			}
		}
		cout << "\n==========================\n";
		cout << " Quiz is not found  :-) \n";
		cout << "===========================\n";
	}
};
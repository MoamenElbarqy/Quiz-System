#pragma once
#include "HeaderScreen.h"
#include "Student.h"
#include "Input.h"
#include "Util.h"

class DeleteStudent : private HeaderScreen
{
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\t Remove Student Screen");

		vector<Student> allStudents = Student::LoadStudentDataFromFile();

		if (allStudents.empty())
		{
			cout << "\nNo students found.\n";
			return;
		}

		cout << "\nEnter Student Phone Number to Remove: ";
		string phoneNumber = Input::ReadString();

		cout << "\nEnter Student Password to Remove: ";
		string password = Input::ReadString();

		Student studentToRemove = Student::Find(phoneNumber, password);

		if (studentToRemove.isEmpty())
		{
			cout << "\n========================================\n";
			cout << " We Don't Have This Student in our System :-) \n";
			cout << "========================================\n";
			return;
		}

		// Remove student from vector
		for (auto it = allStudents.begin(); it != allStudents.end(); it++)
		{
			if (it->getPhoneNumber() == phoneNumber && it->getPassword() == password)
			{
				allStudents.erase(it);
				break;
			}
		}

		Student::SaveStudentsToFile(allStudents);

		cout << "\n========================================\n";
		cout << " Student removed successfully! \n";
		cout << "========================================\n";
	}
};

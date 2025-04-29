#pragma once
#include "HeaderScreen.h"
#include "Teacher.h"
class ViewTeachers : private HeaderScreen
{
private:
	static void ShowTableHeader()
	{
		cout << "\t-----------------------------------------------------------------------------------------------\n";
		cout << "\t|  First Name  |   Last Name |  Phone Number |    Email           |   Password      |   Gender  \n";
		cout << "\t-----------------------------------------------------------------------------------------------\n";
	}
	static void ShowTableRows(vector<Teacher>& allTeachers)
	{
		for (Teacher &myTeacer : allTeachers)
		{
			cout << "\t|" << setw(14) << left << myTeacer.getFirstName();
			cout << "|" << setw(13) << left << myTeacer.getLastName();
			cout << "|" << setw(15) << left << myTeacer.getPhoneNumber();
			cout << "|" << setw(20) << left << myTeacer.getEmail();
			cout << "|" << setw(17) << left << myTeacer.getPassword();
			cout << "|" << setw(10) << left << myTeacer.getGender();
			cout << endl;
		}
	}
	static void ShowTableFooter()
	{
		cout << "\t-----------------------------------------------------------------------------------------------\n";
	}
	static void ShowTeacherTable(vector<Teacher> &allTeachers)
	{
		ShowTableHeader();
		ShowTableRows(allTeachers);
		ShowTableFooter();
	}
public:
	static void Show()
	{
		system("cls");

		DrawScreenHeader("\t All Teachers ");

		vector<Teacher> allTeachers = Teacher::LoadAllTeachersInSystem();

		if (allTeachers.empty())
        {
            cout << "\nNo Teachers found.\n";
            return;
        }
		ShowTeacherTable(allTeachers);
	}
};


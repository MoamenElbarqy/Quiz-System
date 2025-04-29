#pragma once
#include "HeaderScreen.h"
#include "Teacher.h"
#include "Input.h"
#include "Util.h"

class DeleteTeacher : private HeaderScreen
{
public:
    static void Show()
    {
        system("cls");
        DrawScreenHeader("\t Remove Teacher");

        vector<Teacher> allTeachers = Teacher::LoadAllTeachersInSystem();

        if (allTeachers.empty())
        {
            cout << "\nNo teachers found.\n";
            return;
        }

        cout << "\nEnter Teacher Phone Number to Remove: ";
        string phoneNumber = Input::ReadString();

        cout << "\nEnter Teacher Password to Remove: ";
        string password = Input::ReadString();

        Teacher teacherToRemove = Teacher::Find(phoneNumber, password);

        if (teacherToRemove.isEmpty())
        {
            cout << "\n========================================\n";
            cout << " We Don't Have This Teacher in our System :-) \n";
            cout << "========================================\n";
            return;
        }

        // Remove teacher from vector
        for (auto it = allTeachers.begin(); it != allTeachers.end(); it++)
        {
            if (it->getPhoneNumber() == phoneNumber && it->getPassword() == password)
            {
                allTeachers.erase(it);
                break;
            }
        }

        Teacher::SaveTeacherToFile(allTeachers);
        

        cout << "\n========================================\n";
        cout << " Teacher removed successfully! \n";
        cout << "========================================\n";

    }
};

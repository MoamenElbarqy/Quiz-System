#pragma once
#include "HeaderScreen.h"
class ViewStudents : private HeaderScreen
{
private:
    static void ShowTableHeader()
    {
        cout << "\t-----------------------------------------------------------------------------------------------\n";
        cout << "\t|  First Name  |   Last Name |  Phone Number |    Email                     |   Gender  \n";
        cout << "\t-----------------------------------------------------------------------------------------------\n";
    }

    static void ShowTableRows(vector<Student>& allStudents)
    {
        for (Student& myStudent : allStudents)
        {
            cout << "\t|" << setw(14) << left << myStudent.getFirstName();
            cout << "|" << setw(13) << left << myStudent.getLastName();
            cout << "|" << setw(15) << left << myStudent.getPhoneNumber();
            cout << "|" << setw(30) << left << myStudent.getEmail();
            cout << "|" << setw(10) << left << myStudent.getGender();
            cout << endl;
        }
    }
    static void ShowTableFooter()
    {
        cout << "\t-----------------------------------------------------------------------------------------------\n";
    }
    static void ShowStudentTable(vector<Student>& allStudents)
    {
        ShowTableHeader();
        ShowTableRows(allStudents);
        ShowTableFooter();
    }

public:
    static void Show()
    {
        system("cls");

        DrawScreenHeader("\t All Students ");

        
        vector<Student> allStudents = Student::LoadStudentDataFromFile();

        if (allStudents.empty())
        {
            cout << "\nNo Students found.\n";
            return;
        }
        ShowStudentTable(allStudents);
    }
};

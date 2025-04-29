#pragma once
#include <iomanip>
#include "Input.h"
#include "HeaderScreen.h"
#include "ViewAllTeachers.h"
#include "ViewAllStudents.h"
#include "ViewQuizzes.h"
#include "AddAdmin.h"
#include "DeleteAdmin.h"
#include "UpdateAdminInfo.h"
#include "DeleteTeacher.h"
#include "DeleteStudent.h"
#include "DraftedQuizzes.h"
#include "DeletedQuizzes.h"
#include "PublishedQuizzes.h"

class AdminMainMenu : private HeaderScreen
{
private:
    enum AdminOptions
    {
        ViewTeachers = 1,
        ViewStudents = 2,
        ViewDraftQuizzes = 3,
        ViewPublishedQuizzes = 4,
        ViewDeletedQuizzes = 5,
        AddAdmin = 6,
        DeleteAdmin = 7,
        UpdateAdminInfo = 8,
        DeleteTeacher = 9,
        DeleteStudent = 10,
        Exit = 11
    };

   
    static void BackToAdminMainMenu()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Admin Main Menu...\n";
        system("pause>0");
        AdminMainMenu::Show();
    }

    static void PerformAdminMenuOptions(AdminOptions option)
    {
        switch (option)
        {
        case AdminOptions::ViewTeachers:
            ViewTeachers::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::ViewStudents:
            ViewStudents::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::ViewDraftQuizzes:
            DraftedQuizzes::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::ViewPublishedQuizzes:
            PublishedQuizzes::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::ViewDeletedQuizzes:
            DeletedQuizzes::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::AddAdmin:
            AddAdmin::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::DeleteAdmin:
            DeleteAdmin::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::UpdateAdminInfo:
            UpdateAdminInfo::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::DeleteTeacher:
            DeleteTeacher::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::DeleteStudent:
            DeleteStudent::Show();
            BackToAdminMainMenu();
            break;
        case AdminOptions::Exit:
            break;
        }
    }

public:
 
    static void Show()
    {
        system("cls");
        DrawScreenHeader("\tAdmin Main Menu Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tAdmin Menu Options\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] View Teachers.\n";
        cout << setw(37) << left << "" << "\t[2] View Students.\n";
        cout << setw(37) << left << "" << "\t[3] View Draft Exams.\n";
        cout << setw(37) << left << "" << "\t[4] View Published Exams.\n";
        cout << setw(37) << left << "" << "\t[5] View Deleted Exams.\n";
        cout << setw(37) << left << "" << "\t[6] Add Admin.\n";
        cout << setw(37) << left << "" << "\t[7] Delete Admin.\n";
        cout << setw(37) << left << "" << "\t[8] Update Admin Info.\n";
        cout << setw(37) << left << "" << "\t[9] Delete Teacher.\n";
        cout << setw(37) << left << "" << "\t[10] Delete Student.\n";
        cout << setw(37) << left << "" << "\t[11] Exit.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Choose What Do you Want to Do: ";
        PerformAdminMenuOptions(AdminOptions(Input::ReadNumberBetween(1, 11)));
    }
};
#pragma once
#include "HeaderScreen.h"
#include "Admin.h"
#include "Input.h"
#include "Util.h"

class UpdateAdminInfo : private HeaderScreen
{
public:
    static void Show()
    {
        system("cls");
        DrawScreenHeader("\t Update Admin Information");

        vector<Admin> allAdmins = Admin::LoadAdminsDataFromFile();

        if (allAdmins.empty())
        {
            cout << "\nNo admins found.\n";
            return;
        }

        cout << "\nEnter Admin Phone Number to Update: ";
        string phoneNumber = Input::ReadString();

        cout << "\nEnter Admin Password to Update: ";
        string password = Input::ReadString();

        Admin adminToUpdate = Admin::Find(phoneNumber, password);

        if (adminToUpdate.isEmpty())
        {
            cout << "\n========================================\n";
            cout << " We Don't Have This Admin in our System :-) \n";
            cout << "========================================\n";
            return;
        }

        cout << "\nEnter Updated Information:\n";
        cout << "-------------------------\n";

        cout << "First Name: ";
        string firstName = Input::ReadString();

        cout << "Last Name: ";
        string lastName = Input::ReadString();

        cout << "Phone Number: ";
        string newPhoneNumber = Input::ReadString();

        cout << "Email: ";
        string email = Input::ReadString();

        cout << "Password: ";
        string newPassword = Input::ReadString();

        cout << "Gender (M/F): ";
        string gender = Input::ReadString();

        // Update admin in the vector
        for (auto &admin : allAdmins)
        {
            if (admin.getPhoneNumber() == phoneNumber && admin.getPassword() == password)
            {
                admin = Admin(Admin::Mode::UpdateMode, firstName, lastName, newPhoneNumber, email, newPassword, gender);
                break;
            }
        }

        Admin::SaveAdminsDataToFile(allAdmins);

        cout << "\n=====================================\n";
		cout << " Admin information updated successfully!\n";
		cout << "=====================================\n";
       
    }
};

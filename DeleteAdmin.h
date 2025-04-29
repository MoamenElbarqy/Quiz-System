#pragma once
#include "HeaderScreen.h"
#include "Admin.h"
#include "Input.h"
#include "Util.h"
#include <algorithm>
class DeleteAdmin : private HeaderScreen
{
private:
public:
    static void Show()
    {
        system("cls");
        DrawScreenHeader("\t Delete Admin");

        vector<Admin> allAdmins = Admin::LoadAdminsDataFromFile();

        if (allAdmins.empty())
        {
            cout << "\nNo admins found.\n";
            return;
        }

        cout << "\nEnter Admin Phone Number to Delete: ";
        string phoneNumber = Input::ReadString();

         cout << "\nEnter Admin Admin Password to Delete: ";
        string password = Input::ReadString();

        Admin adminToDelete = Admin::Find(phoneNumber , password);

        if(adminToDelete.isEmpty())
        {
            cout << "\n========================================\n";
			cout << " We Don't Have This Admin in our System :-) \n";
			cout << "========================================\n";
            return;
        }
        for(auto it = allAdmins.begin(); it != allAdmins.end(); it++)
        {
            if(it->getPhoneNumber() == phoneNumber && it->getPassword() == password)
            {
                allAdmins.erase(it);
                break;
            }
        }

        Admin::SaveAdminsDataToFile(allAdmins);

        cout << "\n========================================\n";
		cout << " Admin deleted successfully! \n";
		cout << "========================================\n";
        
    }
};

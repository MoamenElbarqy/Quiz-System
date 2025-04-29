#pragma once
#include "HeaderScreen.h"
#include "Admin.h"
#include "Input.h"
#include "Util.h"

class AddAdmin : private HeaderScreen
{
private:
    static vector<string> ReadAdminInfo()
    {
        vector<string> adminInfo;

        cout << "\nEnter Admin Information:\n";
        cout << "------------------------\n";

        cout << "First Name: ";
        adminInfo.push_back(Input::ReadString());

        cout << "Last Name: ";
        adminInfo.push_back(Input::ReadString());

        cout << "Phone Number: ";
        adminInfo.push_back(Input::ReadPhoneNumber());

        cout << "Email: ";
        adminInfo.push_back(Input::ReadEmail());

        cout << "Password: ";
        adminInfo.push_back(Input::ReadString());

        cout << "Gender (M/F): ";
        adminInfo.push_back(Input::ReadString());

        return adminInfo;
    }

public:
    static void Show()
    {
        system("cls");
        DrawScreenHeader("\t Add New Admin");

        vector<string> adminInfo = ReadAdminInfo();

        // Create new admin object
        Admin newAdmin(Admin::Mode::AddNewMode,
                       adminInfo[0], adminInfo[1], adminInfo[2],
                       adminInfo[3], adminInfo[4], adminInfo[5]);

        // Save to file
        fstream myFile;

        myFile.open(ADMINS_FILE, ios::app);

        if (!myFile.is_open())
            throw runtime_error("Can't open " + ADMINS_FILE);

        string newRecord = Util::ConvertVectorDataToLine(adminInfo);

        myFile << newRecord << "\n";
        myFile.close();

        cout << "\nAdmin added successfully!\n";
    }
};
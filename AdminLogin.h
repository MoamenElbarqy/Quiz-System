#pragma once
#include "Global.h"
#include "HeaderScreen.h"
#include "Input.h"
#include "Admin.h"
#include "AdminMainMenu.h"

class AdminLogin : private HeaderScreen
{
private:
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\tAdmin Login Screen");

		cout << "Please Enter Your Phone Number : ";
		string adminPhone = Input::ReadString();

		cout << "Please Enter Your Password : ";
		string adminPassword = Input::ReadString();

		Admin myAdmin = Admin::Find(adminPhone, adminPassword);

		if (myAdmin.isEmpty())
		{
			cout << "\n=====================================\n";
			cout << " Your Phone or Password is Wrong :-(\n";
			cout << "=====================================\n";
			return;
		}
		SystemUser = &myAdmin;
		AdminMainMenu::Show(); // go to admin options after login
		SystemUser = nullptr; // Make The User Empty Because The Admin has Logout
	}
};

#pragma once

#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include "Util.h"
#include "Person.h"
#include "Global.h"

class Admin : public Person
{
private:
	string ConvertObjectToLine() override
	{
		string delimiter = "#//#";
		string line;
		line += getFirstName() + delimiter;
		line += getLastName() + delimiter;
		line += getPhoneNumber() + delimiter;
		line += getEmail() + delimiter;
		line += getPassword() + delimiter;
		line += getGender();
		return line;
	}
public:
	Admin(Mode mode, string firstName, string lastName, string phoneNumber, string email, string password, string gender)
		: Person(mode, firstName, lastName, phoneNumber, email, password, gender)
	{
	}

	static Admin Find(string phoneNumber, string password)
	{
		fstream myFile;
		myFile.open(ADMINS_FILE, ios::in);

		if (!myFile.is_open())
			throw std::runtime_error("Error: Could not open " + ADMINS_FILE);

		string line;
		while (getline(myFile, line))
		{
			if (line.empty()) // Saving Program From Crashing Because the Last \n int the file
				continue;

			vector<string> adminInfo = Util::SplitRecord(line); // phone number and password located in index 2 and 4
			if (adminInfo[2] == phoneNumber && adminInfo[4] == password)
			{
				myFile.close();
				return Admin(Mode::ExsistedMode, adminInfo[0], adminInfo[1], adminInfo[2], adminInfo[3], adminInfo[4], adminInfo[5]);
			}
		}
		myFile.close();

		return Admin(Mode::EmptyMode, "", "", "", "", "", "");
	}

	static vector<Admin> LoadAdminsDataFromFile()
	{
		vector<Admin> allAdmins;
		fstream myFile;
		myFile.open(ADMINS_FILE, ios::in);

		if (!myFile.is_open())
			throw runtime_error("Can't open " + ADMINS_FILE);

		string line;
		while (getline(myFile, line))
		{
			if (line.empty()) // Saving Program From Crashing Because the Last \n int the file
				continue;

			vector<string> adminInfo = Util::SplitRecord(line);

			if (adminInfo.size() < 6)
				throw runtime_error("Wrong Data In " + ADMINS_FILE + " file");

			allAdmins.push_back(Admin(Mode::ExsistedMode,
									  adminInfo[0], adminInfo[1],
									  adminInfo[2], adminInfo[3],
									  adminInfo[4], adminInfo[5]));
		}
		myFile.close();

		return allAdmins;
	}

	static void SaveAdminsDataToFile(vector<Admin> &allAdmins)
	{
		fstream myFile;
		myFile.open(ADMINS_FILE, ios::out);

		if (!myFile.is_open())
			throw runtime_error("Can't open " + ADMINS_FILE);

		for (Admin &admin : allAdmins)
		{
			string record = admin.ConvertObjectToLine();
			myFile << record << "\n";
		}
		myFile.close();
	}
};

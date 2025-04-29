#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "Util.h"
#include "Global.h"
using namespace std;

class Person
{
public:
	enum Mode
	{
		ExsistedMode = 1,
		EmptyMode = 2,
		AddNewMode = 3,
		UpdateMode = 4
	};

private:
	string firstName;
	string lastName;
	string phoneNumber;
	string email;
	string password;
	string gender;
	Mode mode;

public:
	Person(Mode mode, string firstName, string lastName, string phoneNumber, string email, string password, string gender)
		: mode(mode), firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), email(email), password(password), gender(gender)
	{
	}

	bool isEmpty()
	{
		return mode == Mode::EmptyMode;
	}

	// Setters
	void setFirstName(const string &str) { firstName = str; }
	void setLastName(const string &str) { lastName = str; }
	void setPhoneNumber(const string &str) { phoneNumber = str; }
	void setEmail(const string &str) { email = str; }
	void setPassword(const string &str) { password = str; }
	void setGender(string str) { gender = str; }

	// Getters
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getPhoneNumber() { return phoneNumber; }
	string getEmail() { return email; }
	string getPassword() { return password; }
	string getFullName() { return firstName + " " + lastName; }
	string getGender() { return gender; }
	Mode getMode() { return mode; }


protected:
	virtual string ConvertObjectToLine()
	{
		string delimiter = "#//#";
		string line;
		line += firstName + delimiter;
		line += lastName + delimiter;
		line += phoneNumber + delimiter;
		line += email + delimiter;
		line += password + delimiter;
		line += gender;
		return line;
	}

	static vector<Person> LoadDataFromFile(string filename)
	{
		vector<Person> allData;
		fstream myFile;
		myFile.open(filename, ios::in);

		if (!myFile.is_open())
			throw runtime_error("Can't open " + filename);

		string line;
		while (getline(myFile, line))
		{
			if (line.empty())
				continue;

			vector<string> data = Util::SplitRecord(line);
			if (data.size() < 6)
				throw runtime_error("Wrong Data In " + filename + " file");

			allData.push_back(Person(Mode::ExsistedMode,
									 data[0], data[1],
									 data[2], data[3],
									 data[4], data[5]));
		}
		myFile.close();
		return allData;
	}

	static void SaveDataToFile(string filename, vector<Person> &allData)
	{
		fstream myFile;
		myFile.open(filename, ios::out);

		if (!myFile.is_open())
			throw runtime_error("Can't open " + filename);

		for (Person &person : allData)
		{
			string record = person.ConvertObjectToLine();
			myFile << record << "\n";
		}
		myFile.close();
	}

	static void SaveNewToFile(string filename, vector<string> newInfo)
	{
		fstream myFile;
		myFile.open(filename, ios::app);

		if (!myFile.is_open())
			throw runtime_error("Can't Open " + filename + " File");

		string newRecord = Util::ConvertVectorDataToLine(newInfo);
		myFile << newRecord << "\n";
		myFile.close();
	}

	static Person Find(const string &filename, string phoneNumber, string password)
	{
		fstream myFile;
		myFile.open(filename, ios::in);

		if (!myFile.is_open())
			throw runtime_error("Error: Could not open " + filename);

		string line;
		while (getline(myFile, line))
		{
			if (line.empty())
				continue;

			vector<string> info = Util::SplitRecord(line);
			if (info.size() < 6)
				throw runtime_error("Wrong Data In " + filename + " file");

			if (info[2] == phoneNumber && info[4] == password)
			{
				myFile.close();
				return Person(Mode::ExsistedMode, info[0], info[1], info[2], info[3], info[4], info[5]);
			}
		}
		myFile.close();
		return Person(Mode::EmptyMode, "", "", "", "", "", "");
	}
};

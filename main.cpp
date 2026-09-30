#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void display_codes(const map<string, string>& countries)
{
	cout << "Country Codes: ";
	for_each(countries.begin(), countries.end(), 
		[](const pair<string, string>& p){
			cout << p.first << " ";
		}
	);
	cout << "\n\n";
}

int main()
{
	cout << "Welcome to the Country Info Program!\n\n";

	cout << "COMMAND MENU\n"
		<< "show - Show All Codes\n"
		<< "search - Search by country name\n"
		<< "count - Count codes with a given first letter\n"
		<< "exit - Exit\n\n";
	
	map<string, string> countries {
		{"CA", "Canada"},
		{"US", "United States"},
		{"MX", "Mexico"},
		{"UAE", "United Arab Emirates"},
		{"UG", "Uganda"},
		{"FR", "France"},
		{"JP", "Japan"}
	};

	string command;

	while (command != "exit")
	{
		cout << "Enter a command: ";
		cin >> command;

		if (command == "show")
		{
			display_codes(countries);
		}
		else if (command == "count")
		{
			char letter;
			cout << "Enter the first letter of code: ";
			cin >> letter;

			int c = count_if(countries.begin(), countries.end(),
				[&](const pair<string, string>& p) {
					return p.first[0] == toupper(letter);
				}
			);
			
			cout << "Number of codes starting with " << letter << ": " << c << "\n\n";
		}
		else if (command == "exit")
		{
			cout << "Bye!!\n";
		}
		else if (command == "search")
		{
			string name;
			cout << "Enter a country name: ";
			cin.ignore();
			getline(cin, name);

			string lowerName = "";
			for (char c : name){
				lowerName += tolower(c);
			}

			// search through the map values (convert values to lowercase while doing it)
			auto iter = find_if(countries.begin(), countries.end(),
				[&](const pair<string, string>& p){
					string lowerCountry = "";
					for (char c : p.second){
						lowerCountry += tolower(c);
					}
					return lowerCountry == lowerName;
				}
			);

			if (iter != countries.end())
			{
				cout << "Found: " << iter->first << " = " << iter->second  << "\n\n";
			}
			else {
				cout << "Not Found\n\n";
			}
		}
		else
		{
			cout << "Invalid command, try again!\n";
		}

	}

	return 0;
}

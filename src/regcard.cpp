#include "../headers/regcard.hpp"


void mainMenu(void) {
	cout << "Enter one from next numbers" << endl
		<< "1 Registration" << endl
		<< "2 Entry" << endl
		<< "3 out is programm" << endl
		<< "4 Administrator" << endl;
	cout << "Your choose:";
}

bool checkLenghtName(const User& user) {
	return (user.name.size() >= 5 && user.name.size() <= 20) ? true : false;
}

bool checkLenghtFamily(const User& user) {
	return (user.family.size() >= 5 && user.family.size() <= 20) ? true : false;
}

bool checkAddress(const User& user) {
	return (user.address.size() <= 11 && user.address.size() >= 20) ? true : true;
}

bool checkYear(const User& user) {
	return (user.year > 100 || user.year < 18) ? false : true;
}

bool autifToServer(User& current)
{
	return (current.userConnect == true) ? true : false;
}


bool checkSpace(string& current)
{
	for (size_t k = 0; k < current.size(); k++)
	{
		if (current[k] == ' ') return false;
	}
	return true;
}

bool checkCode(const User& user) {
	if (user.pinCode.size() < 4 || user.pinCode.size() > 4)
	{
		return false;
	}
	else
	{
		for (int k = 0; k < user.pinCode.size(); k++)
		{
			if (user.pinCode[k] < '0' || user.pinCode[k] > '9')
			{
				return false;
			}
		}
	}
	return true;
}

string codeCardGeneration(User& current) {
	/*varibles*/
	int64_t first{ 0 };
	int64_t second{ 0 };
	random_device rd;
	std::mt19937_64 gen(rd());
	/*generation*/
	first = rd();
	second = rd();
	/*record into temp varibles*/
	string tmp1 = std::to_string(first);
	string tmp2 = std::to_string(second);
	/*add to main string*/
	current.cardCode.append(tmp1);
	current.cardCode.append(tmp2);

	for (int i = 0; i < MAGIC_VALUE; i++)
	{
		current.cardCode.erase(current.cardCode.end() - i);
	}

	return current.cardCode;
}

int registerUser(User& user) {
	cout << "Input your name: ";
	cin.ignore();
	getline(cin, user.name);
	if (!checkLenghtName(user) || !checkSpace(user.name)) return 1;
	

	cout << "Input your family: ";
	getline(cin, user.family);
	if (!checkLenghtFamily(user) || !checkSpace(user.family)) return 2;


	cout << "Input your address: ";
	getline(cin, user.address);
	if (!checkAddress(user) || !checkSpace(user.address)) return 3;

	cout << "To think your pin-code: ";
	cin >> user.pinCode;
	if (!checkCode(user)) return 4;

	cout << "How many your year: ";
	cin >> user.year;
	if (!checkYear(user)) return 5;
	

	return 0;
}

void codeShuffle(User& current) {
	for (int i = 0, len = current.cardCode.size() - 1; i <= len; i++, len--)
	{
		char tmp = current.cardCode[i];
		current.cardCode[i] = current.cardCode[len];
		current.cardCode[len] = tmp;
	}
}

User loginByCode(map<string,User>& mapUsers)
{
	cout << "Enter your pin-code: ";
	string pinCode;
	cin >> pinCode;
	User empty;
	empty.userConnect = false;
	for (map<string, User>::iterator it = mapUsers.begin(); it != mapUsers.end(); ++it)
	{
		if ((*it).first == pinCode)
		{
			(*it).second.userConnect = true;
			return (*it).second;
		}
		else
		{
			return User(empty);
		}
	}
	return User(empty);
}

void ShowInfo(const User& current)
{
	cout << current.name << endl;
	cout << current.family << endl;
	cout << current.address << endl;
	cout << current.year << endl;
	cout << current.cardCode << endl;
	cout << "****" << endl;

}

string currentTime()
{
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	string current_date = std::ctime(&end_time);

	return current_date;
}

void showUsers(map<string, User>& mapUsers)
{
	if (mapUsers.size() > 0)
	{
		for (const auto& [key, value] : mapUsers)
		{
			cout << "General information" << endl;
			cout << "Primary key: " << key << endl
				<< "Name: " << value.name << endl
				<< "Family" << value.family << endl
				<< "Address: " << value.address << endl
				<< "Year: " << value.year << endl;
			cout << "Secure information" << endl;
			cout << "Number card: " << value.cardCode << endl;
			cout << "Pin-Code: " << value.pinCode << endl << endl;
		}
	}
	else
	{
		cout << "users missing" << endl;
	}
	
}
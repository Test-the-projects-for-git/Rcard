#include<iostream>
#include<fstream>
#include<string>
#include<random>
#include<chrono>
#include<map>
#include<chrono>
#include<fstream>

using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::string;
using std::getline;
using std::random_device;
using std::normal_distribution;
using std::map;
using std::fstream;


/*general variblies and constands*/
const size_t MAGIC_VALUE = 5;
static bool connect;
static int successRegister;
static int16_t countLogin;
static bool blockProgramm;

struct User {
	/*data about an user*/
	string name;
	string family;
	string address;
	int16_t year;
	/*secret data*/
	string cardCode;
	string pinCode;
	bool userConnect;

	friend bool operator > (const User& lhs, const User& rhs)
	{
		return (lhs.name > rhs.name) ? true : false;
	}

	friend bool operator < (const User& lhs, const User& rhs)
	{
		return (lhs.name > rhs.name) ? true : false;
	}

	friend bool operator == (const User& lhs, const User& rhs)
	{
		return (lhs.name == rhs.name) ? true : false;
	}

	friend bool operator != (const User& lhs, const User& rhs)
	{
		return !(lhs.name == rhs.name) ? true : false;
	}
};


void showUsers(map<string, User>& mapUsers);

/*information functions for users*/
void mainMenu(void);

/*Check data for users*/
bool checkLenghtName(const User& user);

bool checkLenghtFamily(const User& user);

bool checkAddress(const User& user);

bool checkYear(const User& user);

bool checkCode(const User& user);


/*Function for emulation connect user to server*/
bool autifToServer(User& current);

/*Card code generation*/
string codeCardGeneration(User& current);

/*Regitstration for users*/
int registerUser(User& user);

/*Shuffle card code*/
void codeShuffle(User& current);

/*Longin for users*/
User loginByCode(map<string,User>& mapUser);

/*Sow info for users*/
void ShowInfo(const User& current);

/*functions for of time*/

string currentTime();

//void showAllUsers(map<string, User>& mapUser);
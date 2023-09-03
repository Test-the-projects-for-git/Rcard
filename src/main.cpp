#include "../headers/regcard.hpp"


int main()
{

	map<string, User> users;
	char choose = 'y';
	char act = '0';
	User current;
	User tmp;

	successRegister = false;
	connect = false;
	countLogin = 0;
	blockProgramm = false;

	while (choose == 'y')
	{
		if (blockProgramm == true)
		{
			cout << "Server not avaliable" << endl;
			break;
		}
		else
		{
			mainMenu();
			cin >> act;
			switch (act)
			{
			case '1':
				successRegister = registerUser(current);
				if (successRegister != 0)
				{
					cout << "Code Error equal: " << successRegister << endl;
					cout << "data entry error" << endl
						<< "data not should contain not less 5 symbols and not more 10 symbols." << endl
						<< "Also name not should contain the spaces." << endl;
					break;
				}
				else
				{
					codeCardGeneration(current);
					codeShuffle(current);
					users.emplace(current.pinCode, current);
					break;
				}
			case '2':
				tmp = loginByCode(users);
				connect = autifToServer(tmp);
				if (connect == true)
				{
					cout << "Choose act" << endl
						<< "1 Show my data " << endl
						<< "2 exit into main menu " << endl;
					cin >> act;
					if (act == '1')
					{
						ShowInfo(tmp);
					}
					else if (act == '2')
					{
						main();
					}
					else
					{
						cout << "Unknow operation: " << endl;
						break;
					}
				}
				else if (countLogin >= 3)
				{
					blockProgramm = true;
					string now = currentTime();
					ofstream outfile("report.txt", std::ios::app);

					if (outfile.is_open())
					{
						outfile << now << endl;
					}
					else
					{
						cout << "Error opening file" << endl;
					}

					outfile.close();
					break;
				}
				countLogin++;
				cout << "Not try connect to server" << endl;
				break;
			case '3':
				return EXIT_SUCCESS;
				break;
			case '4':
				cout << "Choose action: " << endl
					<< "1 show all users" << endl;
				cin >> act;
				if (act == '1')
				{
					showUsers(users);
				}
				else
				{
					cout << "Unknow operation" << endl;
				}
			default:
				cout << "Unknow operation" << endl;
				break;
			}
			cout << "Repeat the program y/n: ";
			cin >> choose;
		}
		
	}
		
	return EXIT_SUCCESS;
}
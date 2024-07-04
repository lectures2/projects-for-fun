#include <iostream>
#include <fstream>//Class for read and write data.
#include <string>//Class for string variable.
#include <cmath>
#include <cstdio>//Class for random number generator.
#include <time.h>//Class for variable random number.
using namespace std;
int record_w, record_l, record_d; //variable for win and loose count.
//Function for flush the screen
void refresh()
{
	system("cls");
}
//Function for avoiding auto enter on the comand lind.
void wait()
{
	cout << "Press ENTER to continue...";
		while (getchar() != '\n'); // option to clean stdin
	getchar();
}
/*This function check the record of total play.Also the number of win,
lose ans draw.*/
void check_record(string name)
{
	string line;
	ifstream myfile(name);
	record_l = 0;
	record_w = 0;
	record_w = 0;
	if (myfile.is_open())
	{
		cout << "Welcome Back: " << name << endl;
		if (getline(myfile, line))   record_w = stoi(line);
		if (getline(myfile, line))  record_l = stoi(line);
		if (getline(myfile, line))  record_d = stoi(line);
		//while ( getline (myfile,line) )
		//{
		//    cout << line << '\n';
		//}

		cout << "Total Played: " << record_l + record_w + record_d << endl;
		cout << "Win   : " << record_w << endl;
		cout << "Loose : " << record_l << endl;
		cout << "Draw  : " << record_d << endl;
		myfile.close();
	}
	else
	{
		cout << "Welcome New Player: " << name << endl;
		ofstream myfile;
		myfile.open(name);
		myfile << record_w << endl << record_l << endl << record_d;
		myfile.close();
	}
	wait();
	refresh();
}

//This function create a file for user.
void store_record(string name)
{
	ofstream myfile;
	myfile.open(name, ofstream::out | ofstream::trunc);
	myfile << record_w << endl << record_l << endl << record_d;
	myfile.close();
}
//This function convert string name to int number
string val_name(int i)
{
	if (i == 1) return "Rock";
	else if (i == 2) return "Scissor";
	else if (i == 3) return "Paper";
	else if (i == 0) return "Exit";
	else return "Invalid input";
}
//This function allow the user to play the game creating varible number by computer.
void play(string name)
{
	int usr;
	refresh();
	while (1)
	{
		srand(time(NULL));
		cout << "Win: " << record_w << "  Loose: " << record_l << "   Draw: " << record_d << endl;
		cout << "1. Rock  2. Scissor  3. Paper    0. Exit" << endl;
		cout << "Select any: ";
		cin >> usr;

		int computer = rand() % 3 + 1;

		cout << "User selected		: " << val_name(usr) << endl;
		cout << "Computer selected	: " << val_name(computer) << endl;

		if (usr == 0)
		{
			store_record(name);
			break;
		}
		else if (usr == computer)
		{
			cout << "Its a draw" << endl;
			record_d++;
		}
		else if ((usr == 1 && computer == 3) || (usr == 2 && computer == 1) || (usr == 3 && computer == 2))
		{
			cout << name << " looses" << endl;
			record_l++;
		}
		else if ((usr == 3 && computer == 1) || (usr == 1 && computer == 2) || (usr == 2 && computer == 3))
		{
			cout << name << " wins" << endl;
			record_w++;
		}
		else cout << "Invalid input" << endl;

		wait();
		refresh();
	}
	refresh();
	cout << "Thanks for playing..." << endl;
	wait();
	refresh();
}

int main() {
	while(1)
	{
		string name;
		cout << "Please Enter Your Name: ";
		cin >> name;
		refresh();
		check_record(name);
		play(name);
		char sel;
		cout << "Do you want to play again? (y/n): ";
		cin >> sel;
		if (sel == 'n') break;
	}
	return 0;
}


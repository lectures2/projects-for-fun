#include <iostream>     //standard library.
#include <iomanip>      //Library containing manipulators to control format of output.
#include <windows.h>    //Windows-specific header file.
#include <conio.h>      //A C header file used mostly by MS-DOS compilers to provide console input/output.
#include <stdlib.h>     //srand, rand.
#include <time.h>       //time.
#include <cmath>        //declares a set of functions to compute common mathematical operations and transformations, for mathematics equations.
#include <cstdlib>      //This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <process.h>    //A C header file which contains function declarations and macros used in working with threads and processes.

using namespace std;

#define reward 1000
int multiplier=0;
struct player_details{
	string player_name;
	int player_ID;
	long points;
}player[2];

//My Knowns that'll use to make this program works later on.
int Logic( int, int);
void Result_decoder(int);
void Points_checker();
void Element_displayer();

int main()
{
	system ("color 0e");
	int choice, choiceby1, choiceby2, winner;
	bool x, locker;
	//register the user
	player[1].player_name="computer";
	cout<<endl;
	cout<<"Welcome to the 5 Elements Game";
	cout<<"\n\n";
	cout<<"Please register below\nPLAYER 1 NAME:\t";
	cin>>player[0].player_name;
	cout<<"\nPLAYER 2 NAME:\t"<<player[1].player_name<<"\n";
	Sleep(1);
	player[0].points=10000;
	player[1].points=10000;

	do{
		Points_checker(); 	// this is just to check if all the players got points for them to play if one of them doesn't have
		//enough points then it will show who dont have enough points and will ask to exit..

		do{
			//this is to take the choice entered by player and check if it's a correct choice or not
			do{
				Element_displayer();
				cout<<"Player1, "<<player[0].player_name <<", enter your choice: ";
				cin>>choiceby1;
			}while(!(choiceby1>=1 && choiceby1<=5) );
			//this is to take the choice entered by player and check if it's a correct choice or not

			/* initialize random seed: */
			srand (time(0));

			/* generate secret number between 1 and 10: */
			choiceby2 = rand() % 5 + 1;

			//call the logic to perform the decision of who won
			winner=Logic(choiceby1,choiceby2);
            cout<<"\n\nplayer 1 entered no "<< choiceby1;
            cout<<"\nplayer 2 entered no "<< choiceby2<<"\n";
			//check if there is a winner or not
			if(winner==0||winner==2) {
				Result_decoder(winner);
				multiplier=0;
			}else if(winner==11){
				cout<< "\n\tTie!,No winner\n";
				cout<< "\nBoth players chose the same Element,\n";
				cout<< "Please try again\n";
				Sleep(1);
			}else{
				multiplier++;
				cout<<endl;
				cout<<"Generating Interaction!"<<endl;
				cout<<"Proceeding to Round "<<1+multiplier<<"!, \nPoints in here are more than the previous round\n";
				cout<< endl;
				cout<<"This round winner will get "<<(reward+(reward*multiplier))<<" added to his original points,\n";
				cout<<"while the loser will lose "<<(reward+(reward*multiplier))<<" which is added to the winner.\n";
				getch();
				}//means generating interaction therefore play again but now for more additional points.

		}while(winner==10);


		do{
			locker=false;
			cout<<"\nDo you want to play another round?\n1: Yes\n2: No\n";
			cin>>choice;
			if (choice==1){x=true;		}
			else if (choice==2){x=false; cout <<"Thank you for playing!"<<endl;		}
			else {cout<<"\nPlease re enter your choice correctly:"; locker=true;		}
		}while(locker==true);
	}while(x==true);

}

//elements list.
void Element_displayer(){
	system("CLS");
	cout<<"Pick an element from the list below:\n";
	cout<<"1: Water\n";
	cout<<"2: Wood\n";
	cout<<"3: Fire\n";
	cout<<"4: Earth\n";
	cout<<"5: Metal\n";
}
//points check and the start of the game.
	void Points_checker(){
		for(int i=0; i<2; i++){
			cout<<"\nPlayer "<<i+1;
			cout<<"\t"<< player[i].player_name;
			cout<<"\tpoints: "<< player[i].points;
		}
		if (player[0].points<1000){
			cout<<"\nplayer 1 has no enough points\n";
			cout<<"****game is exiting in ....";
			for(int sec=3;sec>0;sec--){
			cout<<"\t"<<sec<<" seconds\n";
			Sleep(1);
			}
			exit (0);
		}else 	if (player[1].points<1000){
			cout<<"\nplayer 2 has no enough points\n";
			cout<<"****game is exiting in ....";
			for(int sec=3;sec>0;sec--){
			cout<<"\t"<<sec<<" seconds\n";
			Sleep(1);
			}
			exit (0);
		}else{
			cout<<"\n both players have enough points to play\n";
		}
		Sleep(1);
}

// 5 Elements Game starts here, The switch with If..else inside Plays the game depends on my inputs.
int Logic( int pl1, int pl2){
	int champion;
	if (pl1==pl2){
		champion=11;
		return champion;
	}
	switch(pl1){
		case 1:
			if(pl2==3){
				champion=0;
			}else if(pl2==4) {
				champion=2;
			} else{
			champion=10;
			}
			break;

		case 2:
			if(pl2==4){
				champion=0;
			}else if(pl2==5) {
				champion=2;
			} else{
			champion=10;
			}
			break;

		case 3:
			if(pl2==5){
				champion=0;
			}else if(pl2==1) {
				champion=2;
			} else{
			champion=10;
			}
			break;

		case 4:
			if(pl2==1){
				champion=0;
			}else if(pl2==2) {
				champion=2;
			} else{
			champion=10;
			}
			break;

		case 5:
			if(pl2==2){
				champion=0;
			}else if(pl2==3) {
				champion=2;
			} else{
			champion=10;
			}
			break;
	}
	return champion;
}

// My function for points calculation and reult.
void Result_decoder(int winr){
	cout<<"\n\tcongratulations player ";
	if (winr==0){
		cout<<"1\t"<<player[0].player_name;
		player[0].points+=(reward+(reward*multiplier));
		player[1].points-=(reward+(reward*multiplier));
	}else{
		cout<<"2\t"<<player[1].player_name;
		player[0].points-=(reward+(reward*multiplier));
		player[1].points+=(reward+(reward*multiplier));
	}
	cout<<"\n\nPlayer 1\t"<<player[0].player_name<<"\tpoints: "<<player[0].points;
	cout<<"\nPlayer 2\t"<<player[1].player_name<<"\tpoints: "<<player[1].points<<"\n";
}

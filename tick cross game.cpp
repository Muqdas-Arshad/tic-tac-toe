//Name: Muqadas arshad
//Roll No: Bitf20m023
//Section: BSiT-Morning
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
char a[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }, option = 'X', again;
int choice, row, col;
bool draw = false;
string name1, name2;
void board();
void turn();
void reset();
bool gameOver();
int main()
{
	do
	{
		//ofstream fout is used to save the data in the file
		ofstream fout;
		fout.open("players name.txt", ios::app);
		if (fout.fail())   //it is used to check weither the file is created or not
		{
			cout << "The file is not connected.";
		}
		else
		{
			cout << "\n\n\n\t\t\t\t\t\t\t\t L E T ' S  S T A R T  T H E  G A M E\n";
			cout << "\t\t\t\t\t\t\t\t ____________________________________\n\n\n\n";
			cout << "\t\t\t-This game is just for two players.\n";
			cout << "\n\t\t\tPlease enter the name of Player 1:  ";
			getline(cin, name1);
			fout << "  Player 1 name is: " << " " << name1 << endl;
			cout << "\t\t\tPlease enter the name of Player 2:  ";
			getline(cin, name2);
			fout << "  Player 2 name is: " << " " << name2 << endl;
			reset();
			while (gameOver())
			{
				board();
				turn();
				board();
				gameOver();
			}
			//this is the portion about the announcement of winner or DRAW the game
			if (option == 'X' && draw == false)
			{
				cout << "\n\n\t\t\t\t\t Congratulation!!" << name2 << ", you are the winner.\n";
				fout << name2 << "  is the winner of the game.\n";

			}
			else if (option == 'O' && draw == false)
			{
				cout << "\n\n\t\t\t\t\t Congratulation!!" << name1 << ", you are the winner.\n";
				fout << name1 << " is the winner of the game.\n";
			}
			else
				cout << "\n\n\t\t\t\t\t GAME DRAW!!!\n";
			fout <<  "\tGAME DRAW";
			fout << endl;
			fout.close();
		}
		cout << "\n\n\t\t\t\t Do you want to play the game again.\n";
		cout << "\t\t\t\t Enter 'y' or 'Y' for yes and 'n' for no: " << " ";
		cin >> again;
		cin.ignore();
		system("cls");
	} while (again == 'y' || again == 'Y');

}
void board()              //this function is used to display the table
{
	system("cls");       //this system is used to clear the previous screen
	cout << "\n\n\t\t\t\t\t\t\t\t T I C  T A C  T O E  G A M E\n";
	cout << "\t\t\t\t\t\t\t\t_____________________________\n\n\n\n";
	cout << "\t\t\t- " << name1 << " should use the sign[X]\n\n";
	cout << "\t\t\t- " << name2 << " should use the sign[O]\n";
	cout << "\n\n\t\t\t\t\t\t     |     |     \n";
	cout << "\t\t\t\t\t\t   " << a[0][0] << " |  " << a[0][1] << "  |  " << a[0][2] << "  \n";
	cout << "\t\t\t\t\t\t_____|_____|_____\n";
	cout << "\t\t\t\t\t\t     |     |     \n";
	cout << "\t\t\t\t\t\t   " << a[1][0] << " |  " << a[1][1] << "  |  " << a[1][2] << "  \n";
	cout << "\t\t\t\t\t\t_____|_____|_____\n";
	cout << "\t\t\t\t\t\t     |     |     \n";
	cout << "\t\t\t\t\t\t   " << a[2][0] << " |  " << a[2][1] << "  |  " << a[2][2] << "  \n";
	cout << "\t\t\t\t\t\t     |     |     \n";
}
void turn()            //This function is used for the players turns
{

	if (option == 'X')
	{
		cout << "\n\t\t\t\t\t " << name1 << " [X], its your turn: ";
	}
	if (option == 'O')
	{
		cout << "\n\t\t\t\t\t " << name2 << " [O], its your turn: ";
	}
	cin >> choice;
	while (choice < 1 || choice > 9)
	{
		cout << "\t\t\t\t\t ERROR! Its range is from 1 to 9.\n";
		cout << "\t\t\t\t\t Plesae enter again.\n";
		if (option == 'X')
		{

			cout << "\n\t\t\t\t\t " << name1 << " [X], its your turn: ";
		}
		if (option == 'O')
		{

			cout << "\n\t\t\t\t\t " << name2 << " [O], its your turn: ";
		}
		cin >> choice;
	}

	switch (choice)      // this is used to replace the position numbers with 'X' or 'O'
	{
	case 1:
		row = 0; col = 0; break;
	case 2:
		row = 0; col = 1; break;
	case 3:
		row = 0; col = 2; break;
	case 4:
		row = 1; col = 0; break;
	case 5:
		row = 1; col = 1; break;
	case 6:
		row = 1; col = 2; break;;
	case 7:
		row = 2; col = 0; break;
	case 8:
		row = 2; col = 1; break;
	case 9:
		row = 2; col = 2; break;
	default:"Invlid Input";
		break;
	}
	//these conditions are about the turns of players
	if (option == 'X'  && a[row][col] != 'X' && a[row][col] != 'O')
	{
		a[row][col] = 'X';
		option = 'O';
	}
	else if (option == 'O'&& a[row][col] != 'X' && a[row][col] != 'O')
	{
		a[row][col] = 'O';
		option = 'X';
	}
	else
	{
		cout << "\t\t\t\t\t ERROR! Box already filled.\n  ";
		cout << "\t\t\t\t\t Please Enter another number.\n\n";
		turn();
	}
}
bool gameOver()  //it is about to end the game program
{
	//when someone wins the game.
	for (int i = 0; i < 3; i++)        //it is the condition about the rows and columns
		if (a[i][0] == a[i][1] && a[i][0] == a[i][2] || a[0][i] == a[1][i] && a[0][i] == a[2][i])
		{
			return false;
		}
	if (a[0][0] == a[1][1] && a[0][0] == a[2][2] || a[0][2] == a[1][1] && a[0][2] == a[2][0])   // this condition is about the both diagonals
	{
		return false;
	}
	//when there is any unfilled box is avilable.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != 'X' && a[i][j] != 'O')
			{
				return true;
			}
		}
	}
	//Checking the if game already draw
	draw = true;
	return false;
}
void reset()      //to reset the game
{
	a[0][0] = '1';
	a[0][1] = '2';
	a[0][2] = '3';
	a[1][0] = '4';
	a[1][1] = '5';
	a[1][2] = '6';
	a[2][0] = '7';
	a[2][1] = '8';
	a[2][2] = '9';
}
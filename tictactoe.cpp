/*tic tac toe game with a choice to a first player,box validity,diplayed table,game result,and can be restarted*/

#include <iostream>

using namespace std;

		

		void table(char box[10]);
		int win(char c1, char box[10]);
		bool validity(int valid[11]);

	int main(void)
	{
		int restart = 0;
		do
		{
			int num = 0, x = 0, o = 0;
			
			char player, player1, player2;
			int player1_box[5] = { 0,0,0,0,0 }, player2_box[4] = { 0,0,0,0 };
			int valid[11] = { 101,102,103,104,105,106,107,108,109,110,111 };

			char box[10] = { '0','1','2','3','4','5','6','7','8','9' };

			cout << endl << "Welcome to tic tac toe !!!" << endl << "========================================" << endl << endl << endl;

			table(box);

			do
			{
				cout << "which starts ? (X or O) : ";
				cin >> player;
				cout << endl;
				if (player != 'o' && player != 'O' && player != '0' && player != 'x' && player != 'X' && player != '1' && player != '2')
					cout << endl << " kindly enter a valid value " << endl << endl;
			} while (player != 'o' && player != 'O' && player != '0' && player != 'x' && player != 'X' && player != '1' && player != '2');

			switch (player)
			{
			case '1':
			case 'x':
			case 'X':
			{
				player1 = 'X';
				player2 = 'O';
				break;
			}

			case '0':
			case 'o':
			case 'O':
			case '2':
			{
				player1 = 'O';
				player2 = 'X';
			}
			break;

			default:
				cout << "kindly enter a valid value";	//program should never arrive here
				break;
			}

			for (int i = 1; i < 10; i++)
			{

				table(box);
				cout << endl;
				do
				{
					do
					{
						if (i % 2 != 0)
							cout << player1 << " Choose case num : ";
						else
							cout << player2 << " Choose case num : ";

						cin >> num;

						if (num < 0 || num>9)
							cout << "kindly enter a valid value \n";
					} while (num < 0 || num>9);
					valid[i] = num;
					if (validity(valid) == false)
						cout << "\n \n BOX OCCUPIED \n \n";
				} while (validity(valid) == false);

				cout << endl;

				if (i % 2 != 0)
					box[num] = player1;
				else
					box[num] = player2;

				cout << endl;

				if (i % 2 != 0)
				{
					player1_box[x] = num;
					x++;
				}
				else
				{
					player2_box[o] = num;
					o++;
				}
				if (win(player1, box) == 1 || win(player1, box) == 2)
					break;
				cout << endl << endl;
			}
			table(box);
			cout << endl << endl;

			cout << "Player " << player1 << " chose : \n";
			for (int i = 0; i < 5; i++)
				cout << "- Case " << player1_box[i] << endl;

			cout << "Player " << player2 << " chose : \n";
			for (int i = 0; i < 4; i++)
				cout << "- Case " << player2_box[i] << endl;
			cout << endl << endl;

			if (win(player1, box) == 1)
			{
				cout << endl << endl << player1 << "  wins !!!  congrats!! \n";
			}
			else if (win(player1, box) == 2)
			{
				cout << endl << endl << player2 << "  wins !!!  congrats!! \n";
			}
			else
				cout << endl << endl << "match ended as a draw" << endl << endl;
			;
			cout << endl << "restart ? (0 for yes) : ";
			cin >> restart;
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		}while (restart == 0);
		return 0;
	}

	void table(char box[10])
	{

		for (int i = 1; i <= 9; i++)
		{
			cout << box[i];
			if (i % 3 == 0)
			{
				cout << endl;
				if (i != 9)
					cout << "---------------" << endl;
			}
			else
			{
				cout << "  |  ";
			}
		}
		cout << endl << endl << endl;


	}

	int win(char c1, char box[10])
	{
		if (box[1] == box[2] && box[2] == box[3])
		{
			if (box[1] == c1)
				return 1;
			else
				return 2;
		}
		else if (box[1] == box[4] && box[4] == box[7])
		{
			if (box[1] == c1)
				return 1;
			else
				return 2;
		}
		else if (box[1] == box[5] && box[5] == box[9])
		{
			if (box[1] == c1)
				return 1;
			else
				return 2;
		}
		else if (box[2] == box[5] && box[5] == box[8])
		{
			if (box[2] == c1)
				return 1;
			else
				return 2;
		}
		else if (box[3] == box[6] && box[6] == box[9])
		{
			if (box[3] == c1)
				return 1;
			else
				return 2;
		}
		else if (box[3] == box[5] && box[5] == box[7])
		{
			if (box[3] == c1)
				return 1;
			else
				return 2;
		}
		else if (box[4] == box[5] && box[5] == box[6])
		{
			if (box[4] == c1)
				return 1;
			else
				return 2;
		}
		else if (box[8] == box[7] && box[7] == box[9])
		{
			if (box[8] == c1)
				return 1;
			else
				return 2;
		}
		else
			return 0;
	}

	bool validity(int valid[11])
	{
			if (valid[1] == valid[2] || valid[1] == valid[3] || valid[1] == valid[4] || valid[1] == valid[5] || valid[1] == valid[6] || valid[1] == valid[7] || valid[1] == valid[8] || valid[1] == valid[9] || valid[2] == valid[3] || valid[2] == valid[4] || valid[2] == valid[5] || valid[2] == valid[6] || valid[2] == valid[7] || valid[2] == valid[8] || valid[2] == valid[9] || valid[3] == valid[4] || valid[3] == valid[5] || valid[3] == valid[6] || valid[3] == valid[7] || valid[3] == valid[8] || valid[3] == valid[9] || valid[4] == valid[5] || valid[4] == valid[6] || valid[4] == valid[7] || valid[4] == valid[8] || valid[4] == valid[9] || valid[5] == valid[6] || valid[5] == valid[7] || valid[5] == valid[8] || valid[5] == valid[9] || valid[6] == valid[7] || valid[6] == valid[8] || valid[6] == valid[9] || valid[7] == valid[8] || valid[7] == valid[9] || valid[8] == valid[9])
				return false;
			else
				return true;
	}
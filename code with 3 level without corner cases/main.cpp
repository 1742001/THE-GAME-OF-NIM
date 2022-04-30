#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <stack>
using namespace std;
int main()
{
    stack<int> stacks;
	char mode;
	char playAgain;
	int numStones = 0;
	int playerNum = 0;
	int computerNum = 0;
	int firstPlayer = 0;

	do																					// This do-while loop is for being able to play the game again.
	{
		cout << "**THE GAME OF NIM**\n\n";
		cout << "Rules of the game:\n";
		cout << "* Each player can remove 1, 2, or 3 stones from the pile.\n";
		cout << "* The player who makes the last move loses.\n\n";
		cout << "Choose mode:\n";
		cout << "Easy Mode (e) or Hard Mode (h) or Professional Mode (p) : ";
		cin >> mode;

		while ((mode != 'e') && (mode != 'h')&& (mode!='p'))	// This while loop is to ensure the player chooses either easy mode or hard mode.
		{
			cout << "Error! Must enter e or h.\n";
			cout << "Choose mode:\n";
			cout << "Easy Mode (e) or Hard Mode (h): ";
			cin >> mode;
		}

		if (mode == 'e')	// This if statement is just for what needs to be said in the beginning
		{					// (what mode was chosen, initial number of stones, who goes first) but
			cout << "You chose the easy mode.\n\n";		// doesn't need to be repeated every turn.
			numStones = ((rand() % 12) + 10);
			for(int i=1;i<=numStones;i++)
            {
                stacks.push(i);
            }
			cout << "The initial number of stones is " << numStones << endl;
			cout << "Now let's roll the dice to see who goes first..." << endl;

			firstPlayer = (rand() % 2);
			if (firstPlayer == 0)
			{
				cout << "You go first!\n\n";
			}
			else
			{
				cout << "The computer goes first.\n\n";
			}
			do																				// This do-while loop is for the game itself.
			{
				if (firstPlayer == 0)			// This if statement is what will happen when it's the player's turn.
				{
					cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					if(stacks.empty())
                        break;
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 1;		// When firstPlayer is 1, it's the computer's turn.
				}
				else if (firstPlayer == 1)		// This else statement is what will happen when it's the computer's turn.
				{
					cout << "The computer is choosing a move...\n";

					if (stacks.top() > 3)
					{
						computerNum = ((rand() % 3) + 1);
					}
					else if (stacks.top() == 2)
					{
						computerNum = 2;
					}
					else
					{
						computerNum = 1;
					}

					for(int i=1;i<=computerNum;i++)
                    {
                        stacks.pop();

                    }
					cout << "The computer removed " << computerNum << " stone(s) from the pile.\n";
					if(stacks.empty())
                        break;
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;		// When firstPlayer is 0, it's the player's turn.
				}
			} while (!stacks.empty());
		}

		else if (mode == 'h')					// This if statement is just for what needs to be said in the beginning
		{							// (what mode was chosen, initial number of stones, who goes first) but
			cout << "You chose the hard mode.\n\n";		// doesn't need to be repeated every turn.
			numStones = ((rand() % 12) + 10);
			for(int i=1;i<=numStones;i++)
            {
                stacks.push(i);
            }
			cout << "The initial number of stones is " << numStones << endl;
			cout << "Now let's roll the dice to see who goes first..." << endl;

			firstPlayer = (rand() % 2);
			if (firstPlayer == 0)
			{
				cout << "You go first!\n\n";
			}
			else
			{
				cout << "The computer goes first.\n\n";
			}
			do
			{
				if (firstPlayer == 0)			// This if statement is what will happen when it's the player's turn.
				{
					cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}
					for(int i=1;i<=playerNum;i++){
                        stacks.pop();

					}

					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					if(stacks.empty())
                        break;
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 1;
				}

				else if (firstPlayer == 1)		// This else statement is what will happen when it's the computer's turn.
				{
					cout << "The computer is choosing a move...\n";

					if ((stacks.top() % 4 == 1) || (stacks.top() % 4 == 2))
					{					// If the number of stones is a multiple of four plus 1 the computer has no winning
						computerNum = 1;		// strategy so it will only remove 1 stone. When the remainder of the number of stones
					}					// divided by 4 is either 1 or 2, then the number is a multiple of 4 + 1.
					else if (stacks.top() % 4 == 3)
					{					// If the remainder of the number of stones divided by 4 is 3 then taking away 2
						computerNum = 2;		// stones will leave a multiple of four plus 1 stones.
					}
					else if (stacks.top() % 4 == 0)
					{					// If the remainder of the number of stones divided by 4 is 0 then taking away 3
						computerNum = 3;		// stones will leave a multiple of four plus 1 stones.
					}
					for (int i=1;i<=computerNum;i++){
                        stacks.pop();

					}

					cout << "The computer removed " << computerNum << " stone(s) from the pile.\n";
					if(stacks.empty())
                    break;
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
				}
			} while (!stacks.empty());
		}


		    else if(mode=='p')
          {
              cout << "You chose the professional mode.\n\n";		// doesn't need to be repeated every turn.
			numStones = ((rand() % 12) + 10);
			for(int i=1;i<=numStones;i++)
            {
                stacks.push(i);
            }
			cout << "The initial number of stones is " << numStones << endl;
			cout << "Now let's roll the dice to see who goes first..." << endl;

			firstPlayer = (rand() % 2);
			if (firstPlayer == 0)
			{
				cout << "You go first!\n\n";
			}
			else
			{
				cout << "The computer goes first.\n\n";
			}
			do																				// This do-while loop is for the game itself.
			{
				if (firstPlayer == 0)			// This if statement is what will happen when it's the player's turn.
				{
					cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
                    if(stacks.empty())
                    break;
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 1;		// When firstPlayer is 1, it's the computer's turn.
				}
				else if (firstPlayer == 1)		// This else statement is what will happen when it's the computer's turn.
				{
					cout << "The computer is choosing a move...\n";

					if ((stacks.top() % 4 == 1) || (stacks.top() % 4 == 2))
					{					// If the number of stones is a multiple of four plus 1 the computer has no winning
						computerNum = 1;		// strategy so it will only remove 1 stone. When the remainder of the number of stones
					}					// divided by 4 is either 1 or 2, then the number is a multiple of 4 + 1.
					else if (stacks.top() % 4 == 3)
					{					// If the remainder of the number of stones divided by 4 is 3 then taking away 2
						computerNum = 2;		// stones will leave a multiple of four plus 1 stones.
					}
					else if (stacks.top() % 4 == 0)
					{					// If the remainder of the number of stones divided by 4 is 0 then taking away 3
						computerNum = 3;		// stones will leave a multiple of four plus 1 stones.
					}
					for (int i=1;i<=computerNum;i++){
                        stacks.pop();

					}

					cout << "The computer removed " << computerNum << " stone(s) from the pile.\n";
					if(stacks.empty())
                    break;
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
				}
                  else if(numStones==10)
                  {
                      cout << "The computer is choosing a move...\n";

                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					//9
					cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					if(playerNum==3) //6
                    {
                    cout << "The computer is choosing a move...\n";

                        stacks.pop();
                        numStones--;

                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    //5
                    cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)//4
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                       numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)//3
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)//2
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    }
                    else if(playerNum==2) //7
                        {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                       numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
                      cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                     cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                  }


                  else if(playerNum==1) //8
                  {
                      cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
                      cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                     cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                  }
				}

				else if(numStones==11)
				{
				    cout << "The computer is choosing a move...\n";
                      for (int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					//9
					cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					if(playerNum==3) //6
                    {
                    cout << "The computer is choosing a move...\n";

                        stacks.pop();
                        numStones--;

                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    //5
                    cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)//4
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)//3
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)//2
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                      firstPlayer = 0;
                    }
                    }




                    else if(playerNum==2) //7
                        {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
                      cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                     cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                  }


                  else if(playerNum==1) //8
                  {
                      cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
                      cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                     cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                  }
				}

				else if (numStones==12)
                {
                    cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					//9
					cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					if(playerNum==3) //6
                    {
                    cout << "The computer is choosing a move...\n";

                        stacks.pop();
                        numStones--;

                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    //5
                    cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)//4
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)//the remaining is 3
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)//the remaining is 2
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    }
                    else if(playerNum==2) //the remaining is 7
                        {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }

                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
                      cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                      //5
                     cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                  }


                  else if(playerNum==1) //8
                  {
                      cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
                      cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                     cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}

					for(int i=1;i<=playerNum;i++)
                    {
                        stacks.pop();
                        numStones--;
                    }
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    if(playerNum==1)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=2;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "3" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==2)
                    {
                        cout << "The computer is choosing a move...\n";
                      for(int i=0;i<=1;i++){
                        stacks.pop();
                        numStones--;
                      }
                      cout << "The computer removed " << "2" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                    else if(playerNum==3)
                    {
                        cout << "The computer is choosing a move...\n";
                        stacks.pop();
                        numStones--;
                      cout << "The computer removed " << "1" << " stone(s) from the pile.\n";
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
                    }
                  }
                }

			} while (!stacks.empty());
          }

		if (firstPlayer == 1)
		{
			cout <<"\n              You win!\n\n";				// If the game ends on the players turn it mean the computer took the last stone
		}							// so the player wins.

		else							// If the game ends on the players turn it mean the player took the last stone
		{	label:						// so the computer wins.
			cout << "\n             You lose...\n\n";
		}

		cout << "Would you like to play again? (y or n): ";
		cin >> playAgain;
		cout << endl << endl;

	} while (playAgain == 'y');
	cout << "Thanks for playing!\n\n";

	return 0;
}

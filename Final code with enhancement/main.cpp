#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <chrono>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    auto start = chrono::steady_clock::now();
    stack<int> stacks; //the game is made by stacks only
    string mode;         //to know the mode --> easy,medium,hard
    string playAgain;    //if user want to play again
    int numStones = 0; //to store the initial random number of stones
    float playerNum = 0;  //it is the number the user has chosen to remove the bricks in his turn
    int computerNum = 0; //it is the number the computer has chosen to remove the bricks in his turn
    int firstPlayer = 0; //to know who plays first
int  timemode=0,timeeasy=0,timemeduim=0,timehard=0,timetotal=0,timetotalreal=0;
    do				// This do-while loop is for being able to play the game again.
    {
        cout << "THE GAME OF NIM\n\n";
        cout << "Rules of the game:\n";
        cout << "* Each player can remove 1, 2, or 3 stones from the pile.\n";
        cout << "* The player who makes the last move loses.\n\n";
        cout << "Choose mode:\n";
        cout << "Easy Mode (e) or Medium Mode (m) or hard Mode (h) : ";
        auto start = chrono::steady_clock::now();
        cin >> mode;
        while ((mode != "e") && (mode != "m") && (mode != "h"))	// This while loop is to ensure the player chooses either easy mode or hard mode.
        {
            cout << "Error! Must enter e or m or h.\n";
            cout << "Choose mode:\n";
            cout << "Easy Mode (e) or Medium Mode (m) or Hard Mode (h): ";
            auto start = chrono::steady_clock::now();
            cin >> mode;
            auto end = chrono::steady_clock::now();
            timemode=chrono::duration_cast<chrono::seconds>(end - start).count();

        }

        if (mode == "e")	// This if statement is just for what needs to be said in the beginning
        {					// (what mode was chosen, initial number of stones, who goes first) but
            cout << "You chose the easy mode.\n\n";		// doesn't need to be repeated every turn.
            numStones = ((rand() % 12) + 10);
            //push the stones in the stack till it reaches to numStones
            for (int i = -2; i <= numStones; i++)
            {
                stacks.push(i);
            }
            cout << "The initial number of stones is " << numStones << endl;
            cout << "Now let's roll the dice to see who goes first..." << endl;

            firstPlayer = (rand() % 2);  //so that we know who starts first
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
                    auto start = chrono::steady_clock::now();
                    cin >> playerNum;
                     auto end = chrono::steady_clock::now();
                     timeeasy=chrono::duration_cast<chrono::seconds>(end - start).count();
                                while (cin.fail())  //if user enters a charachter which is forbidden
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> playerNum;
    }
                    while ((playerNum > 3) || (playerNum < 1))
                    {
                        cout << "Error! Must enter a number between 1 and 3: ";
                        cin >> playerNum;
                                                  while (cin.fail())  //if user enters a charachter which is forbidden
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> playerNum;
    }
                    }

                    for (int i = 1; i <= playerNum; i++)
                    {
                        stacks.pop();        //pop the bricks out the stack
                    }
                    cout << "You removed " << floor(playerNum) << " stone(s) from the pile.\n";
                    if (stacks.top() <= 0)
                        break;
                    cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    firstPlayer = 1;		// When firstPlayer is 1, it's the computer's turn.
                }
                else if (firstPlayer == 1)		// This else statement is what will happen when it's the computer's turn.
                {
                    cout << "The computer is choosing a move...\n";

                    if (stacks.top() > 3)
                    {
                        computerNum = ((rand() % 3) + 1);  //any random play
                    }
                    else if (stacks.top() == 2)
                    {
                        computerNum = 2;     //so the computer can lose easilly
                    }
                    else
                    {
                        computerNum = 1;    //so the computer can lose easilly
                    }

                    for (int i = 1; i <= computerNum; i++)
                    {
                        stacks.pop();     //pop the bricks out of the stack

                    }
                    cout << "The computer removed " << computerNum << " stone(s) from the pile.\n";
                    if (stacks.top() <= 0)
                        break;
                    cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    firstPlayer = 0;		// When firstPlayer is 0, it's the player's turn.
                }
            } while (!stacks.empty());
        }

        else if (mode == "m")					// This if statement is just for what needs to be said in the beginning
        {							// (what mode was chosen, initial number of stones, who goes first) but
            cout << "You chose the hard mode.\n\n";		// doesn't need to be repeated every turn.
            numStones = ((rand() % 12) + 10);    //initial random number of stones
            for (int i = -2; i <= numStones; i++)
            {
                stacks.push(i);   //push the bricks into the stack
            }
            cout << "The initial number of stones is " << numStones << endl;
            cout << "Now let's roll the dice to see who goes first..." << endl;

            firstPlayer = (rand() % 2);   //to know who starts first
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
                                                    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> playerNum;          //take a new input from the user
    }

                    while ((playerNum > 3) || (playerNum < 1))
                    {
                        cout << "Error! Must enter a number between 1 and 3: ";
                        auto start = chrono::steady_clock::now();
                        cin >> playerNum;
                        auto end = chrono::steady_clock::now();
                     timemeduim=chrono::duration_cast<chrono::seconds>(end - start).count();

                                    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> playerNum;          //take a new input from the user
    }
                    }
                    for (int i = 1; i <= playerNum; i++) {
                        stacks.pop();    // pop the bricks from the stack
                        numStones--;

                    }

                    cout << "You removed " << floor(playerNum) << " stone(s) from the pile.\n";
                    if (stacks.top() <= 0)  //is user enters number more than the remaining bricks he loses
                        break;
                    cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    firstPlayer = 1;          //it is the computer turn
                }

                else if (firstPlayer == 1)		// This else statement is what will happen when it's the computer's turn.
                {
                    cout << "The computer is choosing a move...\n";
                    computerNum = 1;
                    if ((stacks.top() % 4 == 1) || (stacks.top() % 4 == 2))
                    {					// If the number of stones is a multiple of four plus 1 the computer has no winning
                        computerNum = 1;		// strategy so it will only remove 1 stone. When the remainder of the number of stones
                    }					// divided by 4 is either 1 or 2, then the number is a multiple of 4 + 1.

                    else if (stacks.top() % 4 == 0)
                    {					// If the remainder of the number of stones divided by 4 is 0 then taking away 3
                        computerNum = 3;		// stones will leave a multiple of four plus 1 stones.
                    }
                    for (int i = 1; i <= computerNum; i++) {
                        stacks.pop();
                        numStones--;

                    }

                    cout << "The computer removed " << computerNum << " stone(s) from the pile.\n";
                    if (stacks.top() <= 0)    //if computer enters number more than the remaining bricks computer loses
                        break;

                    cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
                    firstPlayer = 0;
                }
            } while (!stacks.empty());
        }


        else if (mode == "h")
        {
            cout << "You chose the professional mode.\n\n";		// doesn't need to be repeated every turn.
            numStones = ((rand() % 12) + 10) + 7;  //random initial number of stones
            for (int i = -2; i <= numStones; i++)
            {
                stacks.push(i);    //push the stones in the stack
            }
            cout << "The initial number of stones is " << numStones << endl;
            cout << "Now let's roll the dice to see who goes first..." << endl;

            firstPlayer = (rand() % 2);         //to know who starts first
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
                    auto start = chrono::steady_clock::now();
                    cin >> playerNum;
                    auto end = chrono::steady_clock::now();
                     timehard=chrono::duration_cast<chrono::seconds>(end - start).count();

                     while (cin.fail())        //if user enters a charchter
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> playerNum;    //enter a new number
    }
                    while ((playerNum > 3) || (playerNum < 1))
                    {
                        cout << "Error! Must enter a number between 1 and 3: ";
                        cin >> playerNum;
                                                        while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> playerNum;          //take a new input from the user
    }
                    }

                    for (int i = 1; i <= playerNum; i++)
                    {
                        stacks.pop();           //pop the bricks out the stack
                        numStones--;
                    }
                    cout << "You removed " << floor(playerNum )<< " stone(s) from the pile.\n";
                    if (stacks.top() <= 0)    //this if is made in last bricks so that if user enters number more than the remaining breaks so he loses
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
					 if (stacks.top() <= 0)    //if computer enters number more than the remaining bricks computer loses
                        break;
					cout << "There are " << stacks.top() << " stone(s) remaining.\n\n";
					firstPlayer = 0;
				}
			} while (!stacks.empty());
		}

		if (firstPlayer == 1)
        {
            cout << "\n              You win!\n\n";				// If the game ends on the players turn it mean the computer took the last stone
        }							// so the player wins.

        else							// If the game ends on the players turn it mean the player took the last stone
        {
            // so the computer wins.
            cout << "\n             You lose...\n\n";
        }
        cout << "Would you like to play again? (y or n): ";
     cin >> playAgain;
        while (playAgain != "y" && playAgain != "n") {
            cout << "Would you like to play again? (y or n): ";
                     auto start = chrono::steady_clock::now();
            cin >> playAgain;
             cout << endl << endl;
        }
    }
            while (playAgain == "y");
            auto end = chrono::steady_clock::now();
             timetotal=chrono::duration_cast<chrono::seconds>(end - start).count();
              timetotalreal=timetotal-timemode-timeeasy-timehard-timemeduim;
              cout << "Real excution time in seconds: "<< timetotalreal<< " sec";

    return 0;
}

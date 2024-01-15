//Purpose: Mario Party spin off Summative
//Kirby
//Gavin Macnabb and Michael Han
//Started:01-08-18 Finished: 1/22/2018, 11:05 PM
//C++ 5.11
//

//adding library
#include<iostream>
#include<ctype.h>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
using namespace std;

//calling functions
void menu(string &Pone,string &Ptwo);
void game(string &Pone,string &Ptwo);
void gameBoardVisual(int playerOneBoard[2][7],int playerTwoBoard[2][7]);
void gameBoardScore(int oneCoin, int twoCoin, int turns, string Pone, string Ptwo);
int challengePicker();
int versusPicker(string Pone, string Ptwo);
int hangman();
int tictactoe(string Pone, string Ptwo);
int cardGame(string Pone, string Ptwo);
int turnAction(int position,string Pone, string Ptwo);
void endGameScreen(string Pone, string Ptwo, int oneCoin, int twoCoin);
int main()
{
	//setting variables
	string Pa,Pb;
	//calling function menu
	menu(Pa,Pb);
	//calling function to start game
	game(Pa,Pb);
	
}

void menu(string &Pone,string &Ptwo)
{

	//outputting info to user
	cout<<"Welcome to Jason's Party House\n\n";
	cout<<"RULES:\nTwo players compete to collect the most coins on the map in 15 turns.\n\nMap Pieces:\n#1-14:\t+1 Coin\nO:\t+2\nX:\t+0\n!:\t+3 (selects mini game for a chance to win 3 coins).\nVS:\t+3 (Players compete against each other for a chance to win 3 coins.\n\n";
	system("pause");
	system("CLS");
	cout<<"PLAYER 1: What is your name? ->";
	cin>>Pone;
	system("CLS");
	cout<<"PLAYER 2: What is your name? ->";
	cin>>Ptwo;
	system("CLS");
	cout<<"Welcome "<<Pone<<" and "<<Ptwo<<" to Jason's Party House' >:)\n";
	system("pause");
	system("CLS");
}

void game(string &Pone,string &Ptwo)
{
	//setting position for player 1 on the board
	int playerOneBoard[2][7] =
	{
	{1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}
	};
	int indexOne = 0;
	//setting position for player 2 on the board
	int playerTwoBoard[2][7] =
	{
	{1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}
	};
	int indexTwo = 0;
	//setting variables
	int turns, roll, oneCoin=0, twoCoin=0, turnTotal;
	int playerOneCounter, playerTwoCounter;
	
	//looping game 
	for (turns=0;turns<15;turns++)
	{
		srand(time(0));
		playerOneCounter=0;
		//player one's turn
		while (playerOneCounter!=3)
		{
		system ("CLS");
		cout<<Pone<<", it is your turn.\n\n";
		//output scoreboard
		gameBoardScore(oneCoin,twoCoin,turns,Pone,Ptwo);
		//outputting game board
		gameBoardVisual(playerOneBoard,playerTwoBoard);
		//telling player they are rolling a random number
		if (playerOneCounter==0)
		{
			cout<<"Rolling random number...\n";
			system("pause");
			playerOneCounter++;
		}
		//generating roll
		else if (playerOneCounter==1)
		{
			roll = (rand() %6)+1;
			cout<<"You rolled a "<<roll<<"!\n";
			indexOne=indexOne+roll;
		if (indexOne>14)
		{
			indexOne=indexOne-14;
		}
		for (int a=0;a<2;a++)
		{
			for (int b=0;b<7;b++)
			{
				playerOneBoard[a][b]=0;
			}
		}
			//resetting counter
			if (indexOne>=14)
			{
				indexOne=indexOne-14;
			}
			//determining position on the map
			if (indexOne<7)
			{
				int x;
				x=indexOne;
				playerOneBoard[0][x]=1;
			}
			else if (indexOne>=7)
			{
				int x,z;

				if (indexOne==7)
				{
					playerOneBoard[1][6]=1;
				}
				else
				{
				x=indexOne-7;
				x=6-x;
				playerOneBoard[1][x]=1;
				}
			}
			system("pause");
			playerOneCounter++;
		}
		else if (playerOneCounter==2)
		{
			turnTotal=turnAction(indexOne,Pone,Ptwo);
			if (turnTotal==4)
			{
				twoCoin=3+twoCoin;
				oneCoin=3+oneCoin;
			}
			else if (turnTotal==6)
			{
				twoCoin=3+twoCoin;
			}
			else if (turnTotal==5)
			{
				oneCoin=3+oneCoin;
			}
			else
			{
			oneCoin=turnTotal+oneCoin;	
			};
			system("pause");
			playerOneCounter++;
			cout<<indexOne<<"\n";
		}
		}

		playerTwoCounter=0;
		//Player two's turn
		while (playerTwoCounter!=3)
		{
		system ("CLS");
		cout<<Ptwo<<", it is your turn.\n\n";
		gameBoardScore(oneCoin,twoCoin,turns,Pone,Ptwo);
		//outputting game board
		gameBoardVisual(playerOneBoard,playerTwoBoard);
		//telling player they are rolling a random number
		if (playerTwoCounter==0)
		{
			cout<<"Rolling random number...\n";
			system("pause");
			playerTwoCounter++;
		}
		//generating roll
		else if (playerTwoCounter==1)
		{
			roll = (rand() %6)+1;
			cout<<"You rolled a "<<roll<<"!\n";
			indexTwo=indexTwo+roll;
		if (indexTwo>14)
		{
			indexTwo=indexTwo-14;
		}
		for (int a=0;a<2;a++)
		{
			for (int b=0;b<7;b++)
			{
				playerTwoBoard[a][b]=0;
			}
		}
			//resetting counter
			if (indexTwo>=14)
			{
				indexTwo=indexTwo-14;
			}
			//determining position on the map
			if (indexTwo<7)
			{
				int x;
				x=indexTwo;
				playerTwoBoard[0][x]=1;
			}
			else if (indexTwo>=7)
			{
				int x,z;

				if (indexTwo==7)
				{
					playerTwoBoard[1][6]=1;
				}
				else
				{
				x=indexTwo-7;
				x=6-x;
				playerTwoBoard[1][x]=1;
				}
			}
			system("pause");
			playerTwoCounter++;
		}
		else if (playerTwoCounter==2)
		{
			turnTotal=turnAction(indexTwo,Pone,Ptwo);
			if (turnTotal==4)
			{
				twoCoin=3+twoCoin;
				oneCoin=3+oneCoin;
			}
			else if (turnTotal==6)
			{
				twoCoin=3+twoCoin;
			}
			else if (turnTotal==5)
			{
				oneCoin=3+oneCoin;
			}
			else
			{
			twoCoin=turnTotal+twoCoin;	
			}
			system("pause");
			playerTwoCounter++;
			cout<<indexTwo<<"\n";
		}
		}
	}

}

void gameBoardVisual(int playerOneBoard[2][7],int playerTwoBoard[2][7])
{
	//setting game board
	int gameBoard[2][7] =
	{
	{1,2,3,4,5,6,7},
	{14,13,12,11,10,9,8}
	};
	
for (int a=0;a<2;a++)
	{
		for (int b=0;b<7;b++)
		{
			cout<<"\t";
			if (gameBoard[a][b]==1)
			{
				cout<<"|START|";
			}
			//setting Bonus Positions
			else if ((gameBoard[a][b]==3)||(gameBoard[a][b]==9))
			{
				cout<<"|O|";
			}
			//setting Setback Positions
			else if ((gameBoard[a][b]==5)||(gameBoard[a][b]==11))
			{
				cout<<"|X|";
			}
			//setting Challenge Positions
			else if ((gameBoard[a][b]==4)||(gameBoard[a][b]==12))
			{
				cout<<"|!|";
			}
			//setting VS Position
			else if (gameBoard[a][b]==7)
			{
				cout<<"|VS|";
			}
			else 
			{
				cout<<"|"<<gameBoard[a][b]<<"|";
			}
			cout<<"\t";
		}
		cout<<"\n";
			//setting position for two players on the board
		for (int b=0;b<7;b++)
		{
			cout<<"\t|";
			//Setting position for player 1 on the board
			if (playerOneBoard[a][b]==1)
			{
				cout<<"P1";
			}
			else if (playerOneBoard[a][b]==0)
			{
				cout<<"__";
			}
			cout<<"|";
			//setting position for player 2 on the board
			if (playerTwoBoard[a][b]==1)
			{
				cout<<"P2";
			}
			else if (playerTwoBoard[a][b]==0)
			{
				cout<<"__";
			}
			cout<<"|\t";
		}
		cout<<"\n\n";
	}	
}

void gameBoardScore(int oneCoin, int twoCoin, int turns, string Pone, string Ptwo)
{
	cout<<"Turn: "<<turns+1<<"\n";
	cout<<Pone<<"'s Coins: "<<oneCoin<<"\t|"<<Ptwo<<"'s Coins: "<<twoCoin<<"\n\n";
}

int turnAction(int position, string Pone, string Ptwo)
{
	//determining actions to be taken
	if ((position==2)||(position==8))
	{
		cout<<"Bonus!\n";
		cout<<"Coins earned: +2!\n";
		return (2);
	}
	else if ((position==4)||(position==10))
	{
		cout<<"Red Zone :(\n";
		cout<<"Coin earned: +0\n";
		return (0);
	}
	else if ((position==3)||(position==11))
	{
		int x;
		cout<<"Challenge Round!\n";
		x=challengePicker();
		return (x);
	}
	else if (position==6)
	{
		int y;
		cout<<"VERSUS MATCH\n\n";
		y=versusPicker(Pone,Ptwo);
		return (y);
	}
	else
	{
		cout<<"Coins earned: +1!\n";
		return (1);
	}
}

int versusPicker(string Pone, string Ptwo)
{
	int gamePicker, x;
	srand(time(0));
	gamePicker = (rand() %2);
	if (gamePicker==0)
	{
		cout<<"Game Chosen: Card Game!\n";
		return(cardGame(Pone,Ptwo));
	}
	else if (gamePicker==1)
	{
		cout<<"Game 2\n";
		return (0);
	}
}

int challengePicker()
{
	int game;
	srand(time(0));
	game=rand() %2;
	if (game==0)
	{
		cout<<"Game Chosen: Hangman!\n";
		system("pause");
		system("CLS");
		int x=hangman();
		if (x==1)
		{
			return (3);
		}
		else if (x==2)
		{
			return (0);
		}
	}
	else if (game==1)
	{
		cout<<"Game 2\n";
		return (3);
	}
}

int hangman()
{
//Adding Variables
	int lives, i, j, num, counter[10]{0,0,0,0,0,0,0,0,0,0},len,pos,lenPic,pickpos; 
	string word[10],name,display,picked;
	char let, playAgain='y';
	srand (time(NULL));
		
	//Setting Values for Words
	word[0]="apples";
	word[1]="eyeball";
	word[2]="butter";
	word[3]="potato";
	word[4]="horse";
	word[5]="juice";
	word[6]="pepper";
	word[7]="pizza";
	word[8]="cheerios";
	word[9]="bacon";
	
	//Displaying Information to User
	cout<<"Welcome to Hangman\nYou have 9 guesses to find all the letters of the grocery item.\n";
	
	//Getting Info to Start Game	
	system("Pause");
	system("CLS");
	
	//Choosing a Word to Star
		picked="";										//restarting picked value for new round
		lives=9;										//setting value for lives
		
		//Picking Random Number
		num=rand()%10;
		
		//setting name to selected word
		name=word[num];
		
		//assigning output for display
		len=name.size();
		display.assign(len,'#');
		
		//looping until word is solved
			do
			{
				//outputting art based on lives left
				if(lives==1)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"  ____\n";
					cout<<" /    |\n";
					cout<<" |    O\n";
					cout<<" |   /I\\\n";
					cout<<" |   / \\\n";
					cout<<" |\n";
				}
				else if (lives==2)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"  ____\n";
					cout<<" /    |\n";
					cout<<" |    O\n";
					cout<<" |   /I\\\n";
					cout<<" |   / \n";
					cout<<" |\n";
				}
				else if (lives==3)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"  ____\n";
					cout<<" /    |\n";
					cout<<" |    O\n";
					cout<<" |   /I\\\n";
					cout<<" |\n";
					cout<<" |\n";
				}
				else if (lives ==4)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"  ____\n";
					cout<<" /    |\n";
					cout<<" |    O\n";
					cout<<" |   /I\n";
					cout<<" |\n";
					cout<<" |\n";
				}
				else if (lives==5)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"  ____\n";
					cout<<" /    |\n";
					cout<<" |    O\n";
					cout<<" |   /\n";
					cout<<" |\n";
					cout<<" |\n";
				}
				else if (lives==6)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"  ____\n";
					cout<<" /    |\n";
					cout<<" |    O\n";
					cout<<" |\n";
					cout<<" |\n";
					cout<<" |\n";
				}
				else if (lives==7)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"  ____\n";
					cout<<" /    |\n";
					cout<<" |    \n";
					cout<<" |\n";
					cout<<" |\n";
					cout<<" |\n";
				}
				else if (lives==8)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"\n";
					cout<<"\n";
					cout<<" |\n";
					cout<<" |\n";
					cout<<" |\n";
					cout<<" |\n";
				}
				else if (lives==9)
				{
					cout<<"Lives: "<<lives<<"\n\n";
					cout<<"\n";
					cout<<"\n";
					cout<<"\n";
					cout<<"\n";
					cout<<"\n";
					cout<<"\n";
				}
			cout<<display<<"\n\n";
			cout<<picked<<"\n";
			
			//getting info from user
			cin>>let;
			
			//finding if letter has already been picked
			lenPic=picked.size();
			pickpos=picked.find(let);
			
			//adding letter to database
			picked=picked+let+",";
			
			//outputting info if letter was already picked
			if ((pickpos>=0)&&(pickpos<lenPic))			
			{
				cout<<"Sorry, letter has been picked\n";
				picked=picked.substr(0,lenPic);
				system("pause");
				system("CLS");
			}
			else										
			{
			//looping to find letter
			for (int j=0;j<len;j++)						
			{
				//changing display to letter found
				if (name[j]==let)						
				{
					display[j]=let;
				}
			}	
			pos=word[num].find(let);
			
			//removing life if picked letter is not in word
			if (pos<0)									
			{
				lives--;
			}
			
			//clearing screen
			system("CLS");
			}								 
			}while ((lives!=0)&&(display!=word[num]));
	
	//outputting info if player did not find the word		
	if (lives==0)
	{
		cout<<"You lost all of your lives.\n ";
		return(2);
				
	}
	//outputting info if player did find the word
	else 
	{
		cout<<"Congratulations, you win!\n";
		return (1);
	}
	
	//letter player read info before clearing screen
	system("pause");
	system("CLS");
}

int cardGame(string Pone,string Ptwo)
{
	
	int ponewins, ptwowins, onearray[5], twoarray[5], i, j, card, totalone, totaltwo, temp, typeone, typetwo;
	char ans, swit;
	//telling player about game
	cout<<"Welcome to the Card Game!\n\n\n";
	cout<<"Rules are: You get 5 cards, possible numbers between 1-6.\n\n\nYour goal is to get 5 of a kind or as close as you can to 5 of a kind\n\n\n";
	cout<<"If you don't get the cards you want, you have one switch to try to get the card you want\n\n\n";
	cout<<"";
	system("PAUSE");
	system("CLS");
	//player 1's turn
	cout<<"Player 1's turn\n";
	srand(time(0));
	//getting 5 cards
	for(i=0; i<5; i++)
	{
		
		card = (rand() %6) +1;
		onearray[i] = card;
	}
	//showing cards to player
	for (i=0; i < 5; i++)
	{
	
          cout << "\nCard: " << i+1 <<": " << onearray[i];
    cout <<"\n";
	}
  	
  	//askiing players if they want to switch cards
	for (i=0;i < 5; i++)
	{
		
		cout<<"\nWould you like to switch card "<<i+1<<", y or n?\n";
		//getting player's answer
		cin>>swit;
		if (swit=='y')
		{
			system("CLS");
			//getting new random card
			srand(time(0));
			onearray[i] = (rand() %6) +1;
			//telling player their new card
			cout<<"Your new card "<<i+1<<" is now "<<onearray[i]<<"\n";
			//showing player all their cards
			for (j=0; j < 5; j++)
				{
	
         			cout << "\nCard: " << j+1 <<": " << onearray[j];
    				cout <<"\n";
				}
			}
			else if (swit=='n')
		{
			system("CLS");
			cout<<"Card "<<i+1<<" has not been switched\n";
			for (j=0; j < 5; j++)
				{
				
         			cout << "\nCard: " << j+1 <<": " << onearray[j];
    				cout <<"\n";
				}
		}	
		
	}
	system("CLS");
	
	
	//bubble sorting the array to make it easier for if statements
	for(i = 1; i <= 5; i++)
     	{
          
        for (j=0; j < (5 -1); j++)
         	{
               if (onearray[j+1] > onearray[j])      						//<------bubble sorting
              		{ 
                    temp = onearray[j];             
                    onearray[j] = onearray[j+1];
                    onearray[j+1] = temp;
          	}
       				}
   		}	
   	
	//showing user cards after sorting
   	cout<<"Your five cards, from greatest to least, are: \n";
	for (j=0; j < 5; j++)
				{
	
         			cout << "\nCard: " << j+1 <<": " << onearray[j];
    				cout <<"\n";
				}
	
	//all combinations for five of a kind
	
	if(onearray[0]==onearray[1]&&onearray[0]==onearray[2]&&onearray[0]==onearray[3]&&onearray[0]==onearray[4])
		{
			cout<<"\nYou got five of a kind";
			totalone=onearray[0]+onearray[1]+onearray[2]+onearray[3]+onearray[4];
		
			typeone=7;
		}
		
	
	//all possible combinations for four of a kind
	
	else if(onearray[0]==onearray[1]&&onearray[0]==onearray[2]&&onearray[0]==onearray[3])
		{
			cout<<"\nYou got four of a kind";
			totalone=onearray[0]+onearray[1]+onearray[2]+onearray[3];
		
			typeone=6;
		}
		
	else if(onearray[1]==onearray[2]&&onearray[1]==onearray[3]&&onearray[1]==onearray[4])
		{
			cout<<"\nYou got four of a kind";
			totalone=onearray[1]+onearray[2]+onearray[3]+onearray[4];
			
			typeone=6;
		}
		
	//all possible combinatiions for full house
	else if (onearray[0]==onearray[1]&&onearray[0]==onearray[2]&&onearray[3]==onearray[4])
		{
			cout<<"You got a full house";
			totalone=onearray[0]+onearray[1]+onearray[2];
			
			typeone=5;
		}
			
	else if (onearray[0]==onearray[1]&&onearray[2]==onearray[3]&&onearray[2]==onearray[4])
		{
			cout<<"You got a full house";
			totalone=onearray[2]+onearray[3]+onearray[4];
		
			typeone=5;
		}
		
	//all possible combinations for three of a kind
	else if(onearray[0]==onearray[1]&&onearray[0]==onearray[2])
		{
			cout<<"\nYou got three of a kind";
			totalone=onearray[0]+onearray[1]+onearray[2];
			
			typeone=4;
		}
	
	else if(onearray[1]==onearray[2]&&onearray[1]==onearray[3])
		{
			cout<<"\nYou got three of a kind";
			totalone=onearray[1]+onearray[2]+onearray[3];
			
			typeone=4;
		}
		
	else if(onearray[2]==onearray[3]&&onearray[2]==onearray[4])
		{
			cout<<"\nYou got three of a kind";
			totalone=onearray[2]+onearray[3]+onearray[4];
			
			typeone=4;
		}
	//all possible combinations for two pairs (two of a kind 2x)
	else if(onearray[0]==onearray[1]&&onearray[2]==onearray[3])
		{
			cout<<"You got two pairs";
			totalone=onearray[0]+onearray[1];
			typeone=3;
		}
		
	else if (onearray[1]==onearray[2]&&onearray[3]==onearray[4])
		{
			cout<<"You got two pairs";
			totalone=onearray[0]+onearray[1];
			typeone=3;
		}
	else if (onearray[0]==onearray[1]&&onearray[3]==onearray[4])
		{
			cout<<"You got two pairs";
			totalone=onearray[0]+onearray[1];
			typeone=3;
		}
		//all possible combinations for two of a kind
	else if(onearray[0]==onearray[1])
		{
			cout<<"\nYou got two of a kind";
			totalone=onearray[0]+onearray[1];
		
			typeone=2;
		}
		
	else if(onearray[1]==onearray[2])
		{
			cout<<"\nYou got two of a kind";
			totalone=onearray[1]+onearray[2];
		
			typeone=2;
		}
		
	else if(onearray[2]==onearray[3])
		{
			cout<<"\nYou got two of a kind";
			totalone=onearray[2]+onearray[3];
		
			typeone=2;
		}
		
	else if(onearray[3]==onearray[4])
		{
			cout<<"\nYou got two of a kind";
			totalone=onearray[3]+onearray[4];
		
			typeone=2;
		}
	//if you have a trash hand
	else
		{
			cout<<"Trash lol";
			typeone=1;
		}
	
	
	
	system("pause");
	//clearing screen
	system("CLS");
	
	
	//player 2's turn
	cout<<"Player 2's turn\n";
	srand(time(0));
	//getting 5 cards
	for(i=0; i<5; i++)
	{
		
		card = (rand() %6) +1;
		twoarray[i] = card;
	}
	//showing cards to player
	for (i=0; i < 5; i++)
	{
	
          cout << "\nCard: " << i+1 <<": " << twoarray[i];
    cout <<"\n";
	}
  	
  	//askiing players if they want to switch cards
	for (i=0;i < 5; i++)
	{
		
		cout<<"\nWould you like to switch card "<<i+1<<", y or n?\n";
		//getting player's answer
		cin>>swit;
		if (swit=='y')
		{
			system("CLS");
			//getting new random card
			srand(time(0));
			twoarray[i] = (rand() %6) +1;
			//telling player their new card
			cout<<"Your new card "<<i+1<<" is now "<<twoarray[i]<<"\n";
			//showing player all their cards
			for (j=0; j < 5; j++)
				{
	
         			cout << "\nCard: " << j+1 <<": " << twoarray[j];
    				cout <<"\n";
				}
			
		}
		else if (swit=='n')
		{
			system("CLS");
			cout<<"Card "<<i+1<<" has not been switched\n";
			for (j=0; j < 5; j++)
				{
	
         			cout << "\nCard: " << j+1 <<": " << twoarray[j];
    				cout <<"\n";
				}
		}
	}
	system("CLS");
	//showing player their final 5 cards after switching
	cout<<"Your five cards are: \n";
	for (j=0; j < 5; j++)
				{
	
         			cout << "\nCard: " << j+1 <<": " << twoarray[j];
    				cout <<"\n";
				}
	system("CLS");
	
		//bubble sorting the array to make it easier for if statements
	for(i = 1; i <= 5; i++)
     	{
          
        for (j=0; j < (5 -1); j++)
         	{
               if (twoarray[j+1] > twoarray[j])      						//<------bubble sorting
              		{ 
                    temp = twoarray[j];             
                    twoarray[j] = twoarray[j+1];
                    twoarray[j+1] = temp;
          	}
       				}
   		}	
   	
	//showing user cards after sorting
   	cout<<"Your five cards are: \n";
	for (j=0; j < 5; j++)
				{
	
         			cout << "\nCard: " << j+1 <<": " << twoarray[j];
    				cout <<"\n";
				}
	
	//all combinations for five of a kind
	
	if(twoarray[0]==twoarray[1]&&twoarray[0]==twoarray[2]&&twoarray[0]==twoarray[3]&&twoarray[0]==twoarray[4])
		{
			cout<<"\nYou got five of a kind\n";
			totaltwo=twoarray[0]+twoarray[1]+twoarray[2]+twoarray[3]+twoarray[4];
		
			typetwo=7;
		}
		
	
	//all possible combinations for four of a kind
	
	else if(twoarray[0]==twoarray[1]&&twoarray[0]==twoarray[2]&&twoarray[0]==twoarray[3])
		{
			cout<<"\nYou got four of a kind\n";
			totaltwo=twoarray[0]+twoarray[1]+twoarray[2]+twoarray[3];
	
			typetwo=6;
		}
		
	else if(twoarray[1]==twoarray[2]&&twoarray[1]==twoarray[3]&&twoarray[1]==twoarray[4])
		{
			cout<<"\nYou got four of a kind\n";
			totaltwo=twoarray[1]+twoarray[2]+twoarray[3]+twoarray[4];
		
			typetwo=6;
		}
		
	//all possible combinatiions for full house
	else if (twoarray[0]==twoarray[1]&&twoarray[0]==twoarray[2]&&twoarray[3]==twoarray[4])
		{
			cout<<"You got a full house\n";
			totaltwo=twoarray[0]+twoarray[1]+twoarray[2];
		
			typetwo=5;
		}
			
	else if (twoarray[0]==twoarray[1]&&twoarray[2]==twoarray[3]&&twoarray[2]==twoarray[4])
		{
			cout<<"You got a full house\n";
			totaltwo=twoarray[2]+twoarray[3]+twoarray[4];
		
			typetwo=5;
		}
		
	//all possible combinations for three of a kind
	else if(twoarray[0]==twoarray[1]&&twoarray[0]==twoarray[2])
		{
			cout<<"\nYou got three of a kind\n";
			totaltwo=twoarray[0]+twoarray[1]+twoarray[2];
		
			typetwo=4;
		}
	
	else if(twoarray[1]==twoarray[2]&&twoarray[1]==twoarray[3])
		{
			cout<<"\nYou got three of a kind\n";
			totaltwo=twoarray[1]+twoarray[2]+twoarray[3];
		
			typetwo=4;
		}
		
	else if(twoarray[2]==twoarray[3]&&twoarray[2]==twoarray[4])
		{
			cout<<"\nYou got three of a kind\n";
			totaltwo=twoarray[2]+twoarray[3]+twoarray[4];
		
			typetwo=4;
		}
		
			
		//all possible combinations for two pairs (two of a kind 2x)
	else if(twoarray[0]==twoarray[1]&&twoarray[2]==twoarray[3])
		{
			cout<<"You got two pairs\n";
			totaltwo=twoarray[0]+twoarray[1];
			typetwo=3;
		}
		
	else if (twoarray[1]==twoarray[2]&&twoarray[3]==twoarray[4])
		{
			cout<<"You got two pairs\n";
			totaltwo=twoarray[0]+twoarray[1];
			typetwo=3;
		}
	else if (twoarray[0]==twoarray[1]&&twoarray[3]==twoarray[4])
		{
			cout<<"You got two pairs\n";
			totaltwo=twoarray[0]+twoarray[1];
			typetwo=3;
		}
		
		//all possible combinations for two of a kind
	else if(twoarray[0]==twoarray[1])
		{
			cout<<"\nYou got two of a kind\n";
			totaltwo=twoarray[0]+twoarray[1];
		
			typetwo=2;
		}
		
	else if(twoarray[1]==twoarray[2])
		{
			cout<<"\nYou got two of a kind\n";
			totaltwo=twoarray[1]+twoarray[2];
		
			typetwo=2;
		}
		
	else if(twoarray[2]==twoarray[3])
		{
			cout<<"\nYou got two of a kind\n";
			totaltwo=twoarray[2]+twoarray[3];
		
			typetwo=2;
		}
		
	else if(twoarray[3]==twoarray[4])
		{
			cout<<"\nYou got two of a kind\n";
			totaltwo=twoarray[3]+twoarray[4];
		
			typetwo=2;
		}
	//if you have a trash hand
	else
		{
			cout<<"Trash lol\n";
			typetwo=1;
		}
	
	system("PAUSE");
	system("CLS");
	//final scores
	cout<<"Player 1\t\t\tPlayer 2\n__________________________________________";
	for (j=0; j < 5; j++)
				{
	
         			cout << "\n\nCard " << j+1 <<": " << onearray[j]<<"\t\t\t";
         			
					cout<<"Card "<<j+1<<": "<<twoarray[j];
    			
				}
	
	system("PAUSE");
	system("CLS");	
	
	//determining winner
	if(typeone>typetwo)
		{
			cout<<"\n"<<Pone<<" is the winner!\n";
			ponewins=ponewins+1;
			return (5);
		}
	else if(typeone<typetwo)
		{
			cout<<"\n"<<Ptwo<<" is the winner\n";
			ptwowins=ptwowins+1;
			return (6);
		}
	else if(typeone==typetwo)
		{
			cout<<"\nBoth players got same type of hand but...\n";
			if(totalone>totaltwo)
			{
				cout<<Pone<<" has the better hand, player 1 wins!\n";
				ponewins=ponewins+1;
				return(5);
			}
			else if(totalone<totaltwo)
			{
				cout<<Ptwo<<" has the better hand, player 2 wins!\n";
				ptwowins=ptwowins+1;
				return (6);
			}
			else
			{
				cout<<"Tie Game!\n";
				return(4);
			}
		}
	
}

int tictactoe(string Pone, string Ptwo)
{
		int newSpot=2, i, j, t, n, pOnewins,pTwowins, choice, compChoice, displayboard[3][3];
	char gameboard[3][3];
	n=0;

	pOnewins=0;
	pTwowins=0;
	
	cout<<"Welcome to Tic Tac Toe, do you kno de wae?\n\n";
	
	//presetting gameboard
		for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			gameboard[i][j]=' ';
			
		}
	}
	
	//filling in table for user to see
	for(i=0; i<3; i++)
	{
		//filling across
		for(j=0; j<3; j++)
		{
			displayboard[i][j]=n+1;
			n=n+1;
		}
	}
	
	
	
	//outputting table fo user to see which spot is which
	for(i=0; i<3; i++)
	{
		cout<<" | ";
		for(j=0; j<3; j++)
		{
			cout<<displayboard[i][j]<<" | ";

		}
		
		cout<<"\n\n";
	}

	
	
	cout<<"These are the number of the spots you can mark\n";
	cout<<"You will be playing against a computer\n";
	
	

	do{
		
	cout<<"Player 1's turn\n";
	
	
	
	do{
		newSpot=2;
	cout<<"Which spot would you like to mark\n";
	cin>>choice;
	
	//spot 1
	if (choice==1)
	{
		if (gameboard[0][0]==' ')
			{	
				gameboard[0][0]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}

	//spot 2
	else if (choice==2)
	{
		if (gameboard[0][1]==' ')
			{	
				gameboard[0][1]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 3
	else if (choice==3)
	{
		if (gameboard[0][2]==' ')
			{	
				gameboard[0][2]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 4
	else if (choice==4)
	{
		if (gameboard[1][0]==' ')
			{	
				gameboard[1][0]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 5
	else if (choice==5)
	{
		if (gameboard[1][1]==' ')
			{	
				gameboard[1][1]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 6
	else if (choice==6)
	{
		if (gameboard[1][2]==' ')
			{	
				gameboard[1][2]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}	
	
	//spot 7
	else if (choice==7)
	{
		if (gameboard[2][0]==' ')
			{	
				gameboard[2][0]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 8
	else if (choice==8)
	{
		if (gameboard[2][1]==' ')
			{	
				gameboard[2][1]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 9
	else if (choice==9)
	{
		if (gameboard[2][2]==' ')
			{	
				gameboard[2][2]='X';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	}while(newSpot == 1);
		
	
	
		t=t+1;
		//outputting updated gameboard
		for(i=0; i<3; i++)
	{
		cout<<" | ";
		for(j=0; j<3; j++)
		{
			cout<<gameboard[i][j]<<" | ";

		}
		
		cout<<"\n\n";
	}
	
	//all possible win combinations
	//horizontal lines
	if(gameboard[0][0]==gameboard[0][1]&&gameboard[0][1]==gameboard[0][2]&&gameboard[0][2]=='X')
	{
		cout<<Pone<<" wins!";
		cout<<" | ";
		
		pOnewins=pOnewins+1;
	}
	
	else if(gameboard[1][0]==gameboard[1][1]&&gameboard[1][1]==gameboard[1][2]&&gameboard[1][2]=='X')
	{
		cout<<Pone<<" wins!";
		cout<<" | ";
	
		pOnewins=pOnewins+1;
	}
	
	else if(gameboard[2][0]==gameboard[2][1]&&gameboard[2][1]==gameboard[2][2]&&gameboard[2][2]=='X')
	{
		cout<<Pone<<" wins!";
		cout<<" | ";
	
		pOnewins=pOnewins+1;
	}
	
	//vertical lines
	else if(gameboard[0][0]==gameboard[1][0]&&gameboard[1][0]==gameboard[2][0]&&gameboard[2][0]=='X')
	{
		cout<<Pone<<" wins!";
		cout<<" | ";
	
		pOnewins=pOnewins+1;
	}
	
		else if(gameboard[0][1]==gameboard[1][1]&&gameboard[1][1]==gameboard[2][1]&&gameboard[2][1]=='X')
	{
		cout<<Pone<<" wins!";
		cout<<" | ";
	
		pOnewins=pOnewins+1;
	}
		
		else if(gameboard[0][2]==gameboard[1][2]&&gameboard[1][2]==gameboard[2][2]&&gameboard[2][2]=='X')
	{
		cout<<Pone<<" wins!";
		cout<<" | ";
	
		pOnewins=pOnewins+1;
	}
	
	//diagonal lines
	else if(gameboard[0][0]==gameboard[1][1]&&gameboard[1][1]==gameboard[2][2]&&gameboard[2][2]=='X')
	{
		cout<<Pone<<" wins!";
		cout<<" | ";
	
		pOnewins=pOnewins+1;
	}
	
		else if(gameboard[0][2]==gameboard[1][1]&&gameboard[1][1]==gameboard[2][0]&&gameboard[2][0]=='X')
	{
		cout<<Pone<<" wins!";
		cout<<" | ";
	
		pOnewins=pOnewins+1;
	}



	system("PAUSE");
	system("CLS");
	
	//player 2's turn
	
	cout<<"Player 2's turn\n";
	
	do{
		newSpot=2;
	cout<<"Which spot would you like to mark\n";
	cin>>choice;
	
	//spot 1
	if (choice==1)
	{
		if (gameboard[0][0]==' ')
			{	
				gameboard[0][0]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}

	//spot 2
	else if (choice==2)
	{
		if (gameboard[0][1]==' ')
			{	
				gameboard[0][1]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 3
	else if (choice==3)
	{
		if (gameboard[0][2]==' ')
			{	
				gameboard[0][2]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 4
	else if (choice==4)
	{
		if (gameboard[1][0]==' ')
			{	
				gameboard[1][0]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 5
	else if (choice==5)
	{
		if (gameboard[1][1]==' ')
			{	
				gameboard[1][1]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 6
	else if (choice==6)
	{
		if (gameboard[1][2]==' ')
			{	
				gameboard[1][2]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}	
	
	//spot 7
	else if (choice==7)
	{
		if (gameboard[2][0]==' ')
			{	
				gameboard[2][0]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 8
	else if (choice==8)
	{
		if (gameboard[2][1]==' ')
			{	
				gameboard[2][1]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	
	//spot 9
	else if (choice==9)
	{
		if (gameboard[2][2]==' ')
			{	
				gameboard[2][2]='O';
				newSpot=2;
			}
		else
		{
			newSpot=1;
			cout<<"Spot already taken\n";
		}
	}
	}while(newSpot == 1);
	
		t=t+1;
		//outputting updated gameboard
		for(i=0; i<3; i++)
	{
		cout<<" | ";
		for(j=0; j<3; j++)
		{
			cout<<gameboard[i][j]<<" | ";

		}
		
		cout<<"\n\n";
	}
	
	//all possible win combinations
	//horizontal lines
	if(gameboard[0][0]==gameboard[0][1]&&gameboard[0][1]==gameboard[0][2]&&gameboard[0][2]=='O')
	{
		cout<<Ptwo<<" wins!";
		
		
		pTwowins=pTwowins+1;
	}
	
	else if(gameboard[1][0]==gameboard[1][1]&&gameboard[1][1]==gameboard[1][2]&&gameboard[1][2]=='O')
	{
		cout<<Ptwo<<" wins!";
		
	
		pTwowins=pTwowins+1;
	}
	
	else if(gameboard[2][0]==gameboard[2][1]&&gameboard[2][1]==gameboard[2][2]&&gameboard[2][2]=='O')
	{
		cout<<Ptwo<<" wins!";
		
	
		pTwowins=pTwowins+1;
	}
	
	//vertical lines
	else if(gameboard[0][0]==gameboard[1][0]&&gameboard[1][0]==gameboard[2][0]&&gameboard[2][0]=='O')
	{
		cout<<Ptwo<<" wins!";
		
	
		pTwowins=pTwowins+1;
	}
	
		else if(gameboard[0][1]==gameboard[1][1]&&gameboard[1][1]==gameboard[2][1]&&gameboard[2][1]=='O')
	{
		cout<<Ptwo<<" wins!";
		
	
		pTwowins=pTwowins+1;
	}
		
		else if(gameboard[0][2]==gameboard[1][2]&&gameboard[1][2]==gameboard[2][2]&&gameboard[2][2]=='O')
	{
		cout<<Ptwo<<" wins!";
		
	
		pTwowins=pTwowins+1;
	}
	
	//diagonal lines
	else if(gameboard[0][0]==gameboard[1][1]&&gameboard[1][1]==gameboard[2][2]&&gameboard[2][2]=='O')
	{
		cout<<Ptwo<<" wins!";
		
	
		pTwowins=pTwowins+1;
	}
	
		else if(gameboard[0][2]==gameboard[1][1]&&gameboard[1][1]==gameboard[2][0]&&gameboard[2][0]=='O')
	{
		cout<<Ptwo<<" wins!";
		
	
		pTwowins=pTwowins+1;
		
	}
t=t+1;

//do while turns are less than 9, if player one and player two wins are less than 1	
}while((t<9)||(pOnewins<1)||(pTwowins<1));

//if player 1 wins
if (pOnewins<pTwowins)
{
	return(5);
}
//if player 2 wins
else if (pOnewins>pTwowins)
{
	return(6);
}
//if no one wins
else
{
	return(4);
}

}

int RPS(string Pone, string Ptwo)
{
	int i, len, typeone, typetwo, ptwowins, ponewins;
	string choiceone, choicetwo;
	cout<<"Welcome to Rock, Paper, Scissors!\n";
	cout<<"Player 1 will enter their choice, then player 2 will enter their choice!\n";
	cout<<"Screen will clear after each player has made their choice, no peaking!\n\n";
while((ponewins<3)||(ptwowins<3))
	{
	
	//player 1's turn
	cout<<"Player 1's turn\n";
	cout<<"Rock, paper or scissors?";
	cin>>choiceone;
	
	//string manipulation
	for(i=0; i<choiceone.length();i++)
	{
		choiceone[i]=tolower(choiceone[i]);
		
	}
	
	//turning player choice into numbers
	if (choiceone=="rock")
	{
		typeone=1;
	}
	else if(choiceone=="paper")
	{
		typeone=2;
	}
	else if(choiceone=="scissors")
	{
		typeone=3;
	}
	else
	{
		cout<<"Please select rock, paper, or scissors, or check your spelling";
	}
	system("CLS");
	
	//player 2's turn
	cout<<"Player 2's turn";
	cout<<"Rock, paper or scissors?";
	cin>>choicetwo;
	
	//string manipulation
	for(i=0; i<choicetwo.length();i++)
	{
		choicetwo[i]=tolower(choicetwo[i]);
		
	}
	
	//turning player choice into numbers
	if (choicetwo=="rock")
	{
		typetwo=1;
	}
	else if(choicetwo=="paper")
	{
		typetwo=2;
	}
	else if(choicetwo=="scissors")
	{
		typetwo=3;
	}
	else
	{
		cout<<"Please select rock, paper, or scissors, or check your spelling";
	}
	system("CLS");
	
	cout<<"Player 1 picked "<<choiceone<<" and Player 2 picked "<<choicetwo<<"!\n";
	 
	
	//if statements for all possible outcomes	
		if((typeone==2)&&(typetwo==2))
	{
		cout<<"Tie";
		
	}
		else if((typeone==1)&&(typetwo==1))
	{
		cout<<"Tie";
		
	}	else if((typeone==3)&&(typetwo==3))
	{
		cout<<"Tie";
		
	}
	else if((typeone==1)&&(typetwo==2))
	 	{
	 		cout<<"Paper covers rock, "<<Ptwo<<" wins!\n";
	 		ptwowins=ptwowins+1;
	 	}
	
	else if((typeone==1)&&(typetwo=3))
	{
		cout<<"Rock smashes scissors, "<<Pone<<" wins!\n";
		ponewins=ponewins+1;
	}
	else if((typeone==2)&&(typetwo=3))
	{
		cout<<"Paper gets cut by scissors, "<<Ptwo<<" wins!\n";
		ptwowins=ptwowins+1;
	}
	
	else if((typeone==2)&&(typetwo=1))
	{
		cout<<"Paper covers rock, "<<Pone<<" wins!\n";
		ponewins=ponewins+1;
	}
	else if((typeone==3)&&(typetwo=1))
	{
		cout<<"Rock smashes scissors, "<<Ptwo<<" wins!\n";
		ptwowins=ptwowins+1;
	}
	else if((typeone==3)&&(typetwo=2))
	{
		cout<<"Scissors cuts paper, "<<Pone<<" wins!\n";
		ponewins=ponewins+1;
	}
}
return 0;
}


void endGameScreen(string Pone, string Ptwo, int oneCoin, int twoCoin)
{
	system ("CLS");
	cout<<"After 15 turns, here are the results:\n";
	system ("pause");
	system ("CLS");
	cout<<"After 15 turns, here are the results:\n\n";
	cout<<Pone<<"-\t# of coins collected: "<<oneCoin;
	cout<<"/n"<<Ptwo<<"-\t# of coins collected: "<<twoCoin;
	system("pause");
	system("CLS");
	if (oneCoin>twoCoin)
	{
		cout<<Pone<<" is the winner!";
	}
	else if (twoCoin>oneCoin)
	{
		cout<<Ptwo<<" is the winner!";
	}
	else 
	{
		cout<<"TIE GAME...";
	}
}

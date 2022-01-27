/* Name: Ubaidullah
   Roll.no:20i0541
   Sec: T
   
   Project: Chess
*/

#include<iostream>
#include<iomanip>


using namespace std;

//globally declaring array and row and coloumn number for King, Bishop1 and Bishop2 

 char array [8][8];
 
 int row_K;
 int col_K;
 
 int row_B1;
 int col_B1;
 
 int row_B2;
 int col_B2;

//declaring functions 
 void start();
 void yournextmove();
 void intialposval(char (&board)[8][8], int&, int&, int&, int&, int&, int&);
 void posval(char (&board)[8][8], int&, int&, int&, int&, int&, int&);
 void chess(char (&board)[8][8], int&, int&, int&, int&, int&, int&);
 void chessboard(char (&board)[8][8]);
 void intial_position_king(char (&board)[8][8]);
 void intial_position_bishop(char (&board)[8][8]);
 void bishop1_move(char (&board)[8][8], int&, int&);
 void bishop2_move(char (&board)[8][8], int&, int&);
 void king_move(char (&board)[8][8], int&, int&);
 
 //----------------main function-----------------------
 int main()
 {
 	start();
 	
 	return 0;
 }
 
 //-------------defination of start function---------------
 void start()
 {
 	char option;

 	cout<<"Chess: "<<endl;
 	cout<<"Program for King and 2 bishops"<<endl;
 	cout<<"\nPress 'N' to start a Newgame "<<endl;
 	cout<<"Press 'E' to Exit game "<<endl;
 	cin>>option;	
 		
	//input validation
	while(!(option=='e'||option=='E'||option=='N'||option=='n'))
	{
		cout<<"Invalid input Please enter the value again"<<endl;
		cin>>option;
	}

	//--------------using effective multiselector switch statement--------------
	switch(option)
	{
		case 'N':
		case 'n':
				{
					
					char suboption;
					intial_position_king(array);//takes intial position of king as input
					intial_position_bishop(array);//takes intila position of both bishops as input
					chess(array, row_K, col_K, row_B1, col_B1,row_B2,col_B2);//prints the chess board
					
					
					while(suboption!='E'||'e')
					{
					cout<<"\n\nTo continue enter  'C'\nTo exit game enter 'E' : ";
					cin>>suboption;
					
					//--------------using effective multiselector switch statement--------------
					switch(suboption)
					{
						//if the user continues playing the game
						case 'C':
						case 'c':
							{
								yournextmove();
								cout<<endl;
								break;	
							}
						
						//if the user exits the program will then terminate	
						case 'E':
						case 'e':
							{
								exit(0);
								break;	
							}		
							
					}
					}
					
					break;
				}	
		//--------------terminates the program-----------------	
		case 'e':
		case 'E':
			{
				cout<<"Better luck next time";
				exit(0);
				break;
			}
	}
 }
 
 //-----------------------function defination for the next moves------------------
 void yournextmove()
 {
 					cout<<endl;
 					
 					//asks the user to select the piece he wants t move
					int choice;
					
					cout<<"Please select the piece you want to move: "<<endl;
					cout<<"1-King"<<endl;
					cout<<"2-Bishop 1"<<endl;
					cout<<"3-Bishop 2"<<endl;
					cin>>choice;
					
					//input validation
					while(!(choice==1||choice==2 || choice==3))
					{
						cout<<"Invalid input Please enter the value again"<<endl;
						cin>>choice;
					}
					
					
					//--------------using effective multiselector switch statement--------------
					switch(choice)
					{
					case 1:
						{
					    	king_move(array, row_K, col_K);//shows the next possible move for the king
					    	chess(array, row_K, col_K, row_B1, col_B1,row_B2,col_B2);//prints the chess board
							break;
							
						}
					case 2:
						{
							bishop1_move(array, row_B1, col_B1);//shows the next possible move for the bishop1
							chess(array, row_K, col_K, row_B1, col_B1,row_B2,col_B2);//prints the chess board
							break;
						}
					case 3:
						{
							bishop2_move(array, row_B2, col_B2);//shows the next possible moves for the bishop2
							chess(array, row_K, col_K, row_B1, col_B1,row_B2,col_B2);//prints the chess board
							break;
						}	
					}
 }
  
  //function for the validation of intial position of the pieces
  void intialposval(char (&board)[8][8], int& row_K, int& col_K, int& row_B1, int& col_B1, int& row_B2, int& col_B2)
  {
  	while(row_B1==row_B2 && col_B1==col_B2)
	{
			cout<<"Error"<<endl;
			cout<<"Please again enter row number(0-7) for Bishop 2: ";
			cin>>row_B2;
			
			//input validation
			while(!(row_B2>=0 && row_B2<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>row_B2;
			}
			
			cout<<"Please again enter coloumn number(0-7) for Bishop 2: ";
			cin>>col_B2;
			//input validation
			while(!(col_B2>=0 && col_B2<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>col_B2;
			}
	}
	
	while(row_B1==row_K && col_B1==col_K)
	{
			cout<<"Error"<<endl;
			cout<<"Please again enter row number(0-7) for Bishop 1: ";
			cin>>row_B1;
			
			//input validation
			while(!(row_B1>=0 && row_B1<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>row_B1;
			}
			
			cout<<"Please again enter coloumn number(0-7) for Bishop 1: ";
			cin>>col_B1;
			
			//input validation
			while(!(col_B1>=0 && col_B1<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>col_B1;
			}
	}
	
	while(row_B2==row_K && col_B2==col_K)
	{
		cout<<"Error"<<endl;
		cout<<"Please again enter row number(0-7) for Bishop 2: ";
		cin>>row_B2;
		
		//input validation	
		while(!(row_B2>=0 && row_B2<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>row_B2;
		}
			
		cout<<"Please again enter coloumn number(0-7) for Bishop 2: ";
		cin>>col_B2;
		//input validation	
		while(!(col_B2>=0 && col_B2<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>col_B2;
		}
		
	}
	
	if((row_K>=0 || row_K<=7) && (col_K>=0 || col_K<=7))
	{
	
	while((row_B1==row_K && col_B1==col_K-1) || (row_B1==row_K+1 && col_B1==col_K-1) || (row_B1==row_K+1 && col_B1== col_K) || (row_B1==row_K+1 && col_B1==col_K+1) || (row_B1==row_K && col_B1==col_K+1) || (row_B1==row_K-1 && col_B1==col_K+1) || (row_B1==row_K-1&& col_B1==col_K) || (row_B1==row_K-1 && col_B1==col_K-1))
		{
			cout<<"\nYou are in range of the king"<<endl;
			cout<<"Please again enter row number(0-7) for Bishop 1: ";
			cin>>row_B1;
			
			//input validation
			while(!(row_B1>=0 && row_B1<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>row_B1;
			}
			
			cout<<"Please again enter coloumn number(0-7) for Bishop 1: ";
			cin>>col_B1;
			
			//input validation
			while(!(col_B1>=0 && col_B1<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>col_B1;
			}
			
		}
	
		while((row_B2==row_K && col_B2==col_K-1) || (row_B2==row_K+1 && col_B2==col_K-1) || (row_B2==row_K+1 && col_B2== col_K) || (row_B2==row_K+1 && col_B2==col_K+1) || (row_B2==row_K && col_B2==col_K+1) || (row_B2==row_K-1 && col_B2==col_K+1) || (row_B2==row_K-1&& col_B2==col_K) || (row_B2==row_K-1 && col_B2==col_K-1))
		{
			cout<<"\nYou are in range of the king"<<endl;
			cout<<"Please again enter row number(0-7) for Bishop 2: ";
			cin>>row_B2;
			
			//input validation
			while(!(row_B2>=0 && row_B2<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>row_B2;
			}
			
			cout<<"Please again enter coloumn number(0-7) for Bishop 2: ";
			cin>>col_B2;
			
			//input validation
			while(!(col_B2>=0 && col_B2<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>col_B2;
			}
			
		}
	}
	
	
		board[row_B1][col_B1] = 'B';
		board[row_B2][col_B2] = 'B';
  	
  }
 
 //functions for the validation of overlapping or wrong moves
 void posval(char (&board)[8][8],int& row_K,int& col_K,int& row_B1,int& col_B1,int& row_B2,int& col_B2)
 {
 	while(row_B1==row_B2 && col_B1==col_B2)
	{
			cout<<"Error"<<endl;
			cout<<"Please again enter row number(0-7) for Bishop 2: ";
			cin>>row_B2;
			
			//input validation
			while(!(row_B2>=0 && row_B2<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>row_B2;
			}
			
			cout<<"Please again enter coloumn number(0-7) for Bishop 2: ";
			cin>>col_B2;
			
			//input validation
			while(!(col_B2>=0 && col_B2<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>col_B2;
			}
	}
	
	while(row_B1==row_K && col_B1==col_K)
	{
			cout<<"Error"<<endl;
			cout<<"Please again enter row number(0-7) for Bishop 1: ";
			cin>>row_B1;
			
			//input validation
			while(!(row_B1>=0 && row_B1<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>row_B1;
			}
			
			cout<<"Please again enter coloumn number(0-7) for Bishop 1: ";
			cin>>col_B1;
			
			//input validation
			while(!(col_B1>=0 && col_B1<=7))
			{
				cout<<"Invalid input Please enter value again: ";
				cin>>col_B1;
			}
	}
	
	while(row_B2==row_K && col_B2==col_K)
	{
		cout<<"Error"<<endl;
		cout<<"Please again enter row number(0-7) for Bishop 2: ";
		cin>>row_B2;
		
		//input validation	
		while(!(row_B2>=0 && row_B2<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>row_B2;
		}
			
		cout<<"Please again enter coloumn number(0-7) for Bishop 2: ";
		cin>>col_B2;
		
		//input validation	
		while(!(col_B2>=0 && col_B2<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>col_B2;
		}
		
	}	
 } 
 
 //function that takes intial position of the king as input
 void intial_position_king(char (&board)[8][8])
 {
 	for(int i=0; i<=7 ;i++)
 	{
 		for(int j=0; j<=7 ;j++)
 		{
 			board[i][j] = ' ';
		}
	}
	
	cout<<endl;
	cout<<"Please enter row number(0-7) for King: ";
	cin>>row_K;
	
	//input validation
	while(!(row_K>=0 && row_K<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>row_K;
	}
	
	cout<<"Please enter coloumn number(0-7) for King: ";
	cin>>col_K;
	
	//input validation
	while(!(col_K>=0 && col_K<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>col_K;
	}
	
	board[row_K][col_K] ='K';
}

//shows the possible moves for the king
void king_move(char (&board)[8][8], int& row_K, int& col_K)
  {
  	int king_row[8];
  	int king_col[8];
  	
  	for(int i=1;i<=8;i++)
  	{
  		king_row[i]=0;
  		king_col[i]=0;
	}
  	
	king_row[1]=row_K-1;;
	king_col[1]=col_K-1;
	
	king_row[2]=row_K+1;
	king_col[2]=col_K-1;
	
	king_row[3]=row_K+1;
	king_col[3]=col_K;
	
	king_row[4]=row_K+1;
	king_col[4]=col_K+1;
	
	king_row[5]=row_K;
	king_col[5]=col_K+1;
	
	king_row[6]=row_K-1;
	king_col[6]=col_K+1;
	
	king_row[7]=row_K-1;
	king_col[7]=col_K;
	
	king_row[8]=row_K;
	king_col[8]=col_K-1;
	
	
	cout<<"Possible moves for the king are: "<<endl;
	for(int i=1;i<=8;i++)
	{
		
		if((king_row[i]>=0 && king_row[i]<=7) && (king_col[i]>=0 && king_col[i]<=7))
		{
			cout<<" "<<"("<<king_row[i]<<","<<king_col[i]<<")";
		}
		
	}

	cout<<endl;
	cout<<"Please enter row number(0-7) for King: ";
	cin>>row_K;
	
	while(!(row_K>=0 && row_K<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>row_K;
	}
	
	cout<<"Please enter coloumn number(0-7) for King: ";
	cin>>col_K;
	
	//input validation
	while(!(col_K>=0 && col_K<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>col_K;
	}
	
	//input validation
	while(!((row_K==king_row[1] && col_K==king_col[1])||(row_K==king_row[2] && col_K==king_col[2])||( row_K==king_row[3] && col_K==king_col[3])||(row_K==king_row[4] && col_K==king_col[4])||(row_K==king_row[5] && col_K==king_col[5])||(row_K==king_row[6] && col_K==king_col[6])||(row_K==king_row[7] && col_K==king_col[7])||(row_K==king_row[8] && col_K==king_col[8])))
	{
		cout<<endl;
		cout<<"Invalid move. Again enter the value for row: ";
		cin>>row_K;
		//input validation
		while(!(row_K>=0 && row_K<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>row_K;
		}
		cout<<"Invalid move. Again enter the value for col: ";
		cin>>col_K;
		//input validation
		while(!(col_K>=0 && col_K<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>col_K;
		}
		
	}
	
		
	for(int i=0; i<=7 ;i++)
 	{
 		for(int j=0; j<=7 ;j++)
 		{
 			board[i][j] = ' ';
		}
	}
	
	
	posval(board,row_K,col_K,row_B1,col_B1,row_B2,col_B2);//calling the position validation function
	
	board[row_K][col_K] ='K';
	
	board[row_B1][col_B1]='B';
	
	board[row_B2][col_B2]='B';
	
	
  }

//takes intial position of bishop as input	
void intial_position_bishop(char (&board)[8][8])
{	
	cout<<endl;
	cout<<"Please enter row number(0-7) for Bishop 1: ";
	cin>>row_B1;
	
	//input validation
	while(!(row_B1>=0 && row_B1<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>row_B1;
	}
	
	cout<<"Please enter coloumn number(0-7) for Bishop 1: ";
	cin>>col_B1;
	
	//input validation
	while(!(col_B1>=0 && col_B1<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>col_B1;
	}
	//bishop 2
	cout<<endl;
	cout<<"Please enter row number(0-7) for Bishop 2: ";
	cin>>row_B2;
	
	//input validation
	while(!(row_B2>=0 && row_B2<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>row_B2;
	}
	
	cout<<"Please enter coloumn number(0-7) for Bishop 2: ";
	cin>>col_B2;
	
	//input validation
	while(!(col_B2>=0 && col_B2<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>col_B2;
	}
	
	intialposval(board,row_K,col_K,row_B1,col_B1,row_B2,col_B2);
	
  } 
  
 
 //shows the possible moves for bishop1 
 void bishop1_move(char (&board)[8][8], int& row_B1, int& col_B1)
 {	
	int row1_B1[28];
	int col1_B1[28];
	
	int* ap=0;
	int* bp=0;
		
		ap = row1_B1;
		bp = col1_B1;
	
	for(int i=1;i<=28;i++)
	{
		ap=0;
		bp=0;
		
		ap = ap+1;
		bp = bp+1;
	}
	
	row1_B1[1]=row_B1-1;
	col1_B1[1]=col_B1-1;
	row1_B1[2]=row_B1-2; 
	col1_B1[2]=col_B1-2;
	row1_B1[3]=row_B1-3;
	col1_B1[3]=col_B1-3;
	row1_B1[4]=row_B1-4 ;
	col1_B1[4]=col_B1-4;
	row1_B1[5]=row_B1-5 ;
	col1_B1[5]=col_B1-5;
	row1_B1[6]=row_B1-6 ;
	col1_B1[6]=col_B1-6;
	row1_B1[7]=row_B1-7 ;
	col1_B1[7]=col_B1-7;
	
	row1_B1[8]=row_B1-1;
	col1_B1[8]=col_B1+1;
	row1_B1[9]=row_B1-2;
	col1_B1[9]=col_B1+2;
	row1_B1[10]=row_B1-3;
	col1_B1[10]=col_B1+3;
	row1_B1[11]=row_B1-4;
	col1_B1[11]=col_B1+4;
	row1_B1[12]=row_B1-5;
	col1_B1[12]=col_B1+5;
	row1_B1[13]=row_B1-6;
	col1_B1[13]=col_B1+6;
	row1_B1[14]=row_B1-7;
	col1_B1[14]=col_B1+7;
	
	row1_B1[15]=row_B1+1;
	col1_B1[15]=col_B1-1;
	row1_B1[16]=row_B1+2;
	col1_B1[16]=col_B1-2;
	row1_B1[17]=row_B1+3;
	col1_B1[17]=col_B1-3;
	row1_B1[18]=row_B1+4;
	col1_B1[18]=col_B1-4;
	row1_B1[19]=row_B1+5;
	col1_B1[19]=col_B1-5;
	row1_B1[20]=row_B1+6;
	col1_B1[20]=col_B1-6;
	row1_B1[21]=row_B1+7;
	col1_B1[21]=col_B1-7;

	row1_B1[22]=row_B1+1;	
	col1_B1[22]=col_B1+1;
	row1_B1[23]=row_B1+2;
	col1_B1[23]=col_B1+2;
	row1_B1[24]=row_B1+3;
	col1_B1[24]=col_B1+3;
	row1_B1[25]=row_B1+4;
	col1_B1[25]=col_B1+4;
	row1_B1[26]=row_B1+5;
	col1_B1[26]=col_B1+5;
	row1_B1[27]=row_B1+6;
	col1_B1[27]=col_B1+6;
	row1_B1[28]=row_B1+7;
	col1_B1[28]=col_B1+7;
	
	
	
	cout<<"Possible moves for the Bishop1 are: "<<endl;
	for(int i=1;i<=28;i++)
	{
		
		if((row1_B1[i]>=0 && row1_B1[i]<=7) && (col1_B1[i]>=0 && col1_B1[i]<=7))
		{
			cout<<" "<<"("<<row1_B1[i]<<","<<col1_B1[i]<<")";
		}
		
	}
	
	
	for(int i=0; i<=7 ;i++)
 	{
 		for(int j=0; j<=7 ;j++)
 		{
 			board[i][j] = ' ';
		}
	}
	
	cout<<endl;
	cout<<"Please enter row number(0-7) for Bishop 1: ";
	cin>>row_B1;
	
	//input validation
	while(!(row_B1>=0 && row_B1<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>row_B1;
	}
	
	cout<<"Please enter coloumn number(0-7) for Bishop 1: ";
	cin>>col_B1;
	
	//input validation
	while(!(col_B1>=0 && col_B1<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>col_B1;
	}
	//input validation
	while(!((row_B1==row1_B1[1] && col_B1==col1_B1[1])||(row_B1==row1_B1[2] && col_B1==col1_B1[2])||(row_B1==row1_B1[3] && col_B1==col1_B1[3])||(row_B1==row1_B1[4] && col_B1==col1_B1[4])||(row_B1==row1_B1[5] && col_B1==col1_B1[5])||(row_B1==row1_B1[6] && col_B1==col1_B1[6])||(row_B1==row1_B1[7] && col_B1==col1_B1[7])||(row_B1==row1_B1[8] && col_B1==col1_B1[8])||(row_B1==row1_B1[9] && col_B1==col1_B1[9])||(row_B1==row1_B1[10]  && col_B1==col1_B1[10])||(row_B1==row1_B1[11] && col_B1==col1_B1[11])||(row_B1==row1_B1[12] && col_B1==col1_B1[12])||(row_B1==row1_B1[13] && col_B1==col1_B1[13])||(row_B1==row1_B1[14] && col_B1==col1_B1[14])||(row_B1==row1_B1[15] && col_B1==col1_B1[15])||(row_B1==row1_B1[16] && col_B1==col1_B1[16])||(row_B1==row1_B1[17] && col_B1==col1_B1[17])||(row_B1==row1_B1[18] && col_B1==col1_B1[18])||(row_B1==row1_B1[19] && col_B1==col1_B1[19])||(row_B1==row1_B1[20] && col_B1==col1_B1[20])||(row_B1==row1_B1[21] && col_B1==col1_B1[21])||(row_B1==row1_B1[22] && col_B1==col1_B1[22])||(row_B1==row1_B1[23] && col_B1==col1_B1[23])||(row_B1==row1_B1[25] && col_B1==col1_B1[25])||(row_B1==row1_B1[24] && col_B1==col1_B1[24])||(row_B1==row1_B1[26] && col_B1==col1_B1[26])||(row_B1==row1_B1[27] && col_B1==col1_B1[27])||(row_B1==row1_B1[28] && col_B1==col1_B1[28])))
	{
		cout<<endl;
		cout<<"Invalid input Please again enter value for row: ";
		cin>>row_B1;
		
		//input validation
		while(!(row_B1>=0 && row_B1<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>row_B1;
		}
		
		cout<<"Invalid input Please again enter value for col: ";
		cin>>col_B1;
			//input validation
		while(!(col_B1>=0 && col_B1<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>col_B1;
		}
		
	}
	posval(board,row_K,col_K,row_B1,col_B1,row_B2,col_B2);
	
 	board[row_K][col_K] ='K';
	
	board[row_B1][col_B1]='B';
	
	board[row_B2][col_B2]='B';
 	
 } 
 
 //shows the possible moves for the bishop 2
 void bishop2_move(char (&board)[8][8], int& row_B2, int& col_B2)
 {
	int row2_B2[28];
	int col2_B2[28];
	
	int* ip=0;
	int* up=0;
		
		ip = row2_B2;
		up = col2_B2;
	
	for(int i=1;i<=28;i++)
	{
		ip=0;
		up=0;
		
		ip=ip+1;
		up=up+1;
	}
	
	row2_B2[1]=row_B2-1;
	col2_B2[1]=col_B2-1;
	row2_B2[2]=row_B2-2; 
	col2_B2[2]=col_B2-2;
	row2_B2[3]=row_B2-3;
	col2_B2[3]=col_B2-3;
	row2_B2[4]=row_B2-4 ;
	col2_B2[4]=col_B2-4;
	row2_B2[5]=row_B2-5 ;
	col2_B2[5]=col_B2-5;
	row2_B2[6]=row_B2-6 ;
	col2_B2[6]=col_B2-6;
	row2_B2[7]=row_B2-7 ;
	col2_B2[7]=col_B2-7;

	row2_B2[8]=row_B2-1;
	col2_B2[8]=col_B2+1;
	row2_B2[9]=row_B2-2;
	col2_B2[9]=col_B2+2;
	row2_B2[10]=row_B2-3;
	col2_B2[10]=col_B2+3;
	row2_B2[11]=row_B2-4;
	col2_B2[11]=col_B2+4;
	row2_B2[12]=row_B2-5;
	col2_B2[12]=col_B2+5;
	row2_B2[13]=row_B2-6;
	col2_B2[13]=col_B2+6;
	row2_B2[14]=row_B2-7;
	col2_B2[14]=col_B2+7;
	
	row2_B2[15]=row_B2+1;
	col2_B2[15]=col_B2-1;
	row2_B2[16]=row_B2+2;
	col2_B2[16]=col_B2-2;
	row2_B2[17]=row_B2+3;
	col2_B2[17]=col_B2-3;
	row2_B2[18]=row_B2+4;
	col2_B2[18]=col_B2-4;
	row2_B2[19]=row_B2+5;
	col2_B2[19]=col_B2-5;
	row2_B2[20]=row_B2+6;
	col2_B2[20]=col_B2-6;
	row2_B2[21]=row_B2+7;
	col2_B2[21]=col_B2-7;
	
	row2_B2[22]=row_B2+1;	
	col2_B2[22]=col_B2+1;
	row2_B2[23]=row_B2+2;
	col2_B2[23]=col_B2+2;
	row2_B2[24]=row_B2+3;
	col2_B2[24]=col_B2+3;
	row2_B2[25]=row_B2+4;
	col2_B2[25]=col_B2+4;
	row2_B2[26]=row_B2+5;
	col2_B2[26]=col_B2+5;
	row2_B2[27]=row_B2+6;
	col2_B2[27]=col_B2+6;
	row2_B2[28]=row_B2+7;
	col2_B2[28]=col_B2+7;
	
	cout<<"Possible moves for the Bishop2 are: "<<endl;
	for(int i=1;i<=28;i++)
	{
		
		if((row2_B2[i]>=0 && row2_B2[i]<=7) && (col2_B2[i]>=0 && col2_B2[i]<=7))
		{
			cout<<" "<<"("<<row2_B2[i]<<","<<col2_B2[i]<<")";
		}
		
	}

	
	for(int i=0; i<=7 ;i++)
 	{
 		for(int j=0; j<=7 ;j++)
 		{
 			board[i][j] = ' ';
		}
	}
	
	cout<<endl;
	cout<<"Please enter row number(0-7) for Bishop 2: ";
	cin>>row_B2;
	
	//input validation
	while(!(row_B2>=0 && row_B2<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>row_B2;
	}
	
	cout<<"Please enter coloumn number(0-7) for Bishop 2: ";
	cin>>col_B2;
	
	//input validation
	while(!(col_B2>=0 && col_B2<=7))
	{
		cout<<"Invalid input Please enter value again: ";
		cin>>col_B2;
	}
	
	//input validation
	while(!((row_B2==row2_B2[1] && col_B2==col2_B2[1])||(row_B2==row2_B2[2] && col_B2==col2_B2[2])||(row_B2==row2_B2[3] && col_B2==col2_B2[3])||(row_B2==row2_B2[4] && col_B2==col2_B2[4])||(row_B2==row2_B2[5] && col_B2==col2_B2[5])||(row_B2==row2_B2[6] && col_B2==col2_B2[6])||(row_B2==row2_B2[7] && col_B2==col2_B2[7])||(row_B2==row2_B2[8] && col_B2==col2_B2[8])||(row_B2==row2_B2[9] && col_B2==col2_B2[9])||(row_B2==row2_B2[10]  && col_B2==col2_B2[10])||(row_B2==row2_B2[11] && col_B2==col2_B2[11])||(row_B2==row2_B2[12] && col_B2==col2_B2[12])||(row_B2==row2_B2[13] && col_B2==col2_B2[13])||(row_B2==row2_B2[14] && col_B2==col2_B2[14])||(row_B2==row2_B2[15] && col_B2==col2_B2[15])||(row_B2==row2_B2[16] && col_B2==col2_B2[16])||(row_B2==row2_B2[17] && col_B2==col2_B2[17])||(row_B2==row2_B2[18] && col_B2==col2_B2[18])||(row_B2==row2_B2[19] && col_B2==col2_B2[19])||(row_B2==row2_B2[20] && col_B2==col2_B2[20])||(row_B2==row2_B2[21] && col_B2==col2_B2[21])||(row_B2==row2_B2[22] && col_B2==col2_B2[22])||(row_B2==row2_B2[23] && col_B2==col2_B2[23])||(row_B2==row2_B2[25] && col_B2==col2_B2[25])||(row_B2==row2_B2[24] && col_B2==col2_B2[24])||(row_B2==row2_B2[26] && col_B2==col2_B2[26])||(row_B2==row2_B2[27] && col_B2==col2_B2[27])||(row_B2==row2_B2[28] && col_B2==col2_B2[28])))
	{
		cout<<endl;
		cout<<"Invalid input Please again enter value for row: ";
		cin>>row_B2;
		//input validation
		while(!(row_B2>=0 && row_B2<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>row_B2;
		}
		
		cout<<"Invalid input Please again enter value for col: ";
		cin>>col_B2;
		//input validation
		while(!(col_B2>=0 && col_B2<=7))
		{
			cout<<"Invalid input Please enter value again: ";
			cin>>col_B2;
		}
		
	}
	
	posval(board,row_K,col_K,row_B1,col_B1,row_B2,col_B2);
	
 	board[row_K][col_K] ='K';
	
	board[row_B1][col_B1]='B';
	
	board[row_B2][col_B2]='B';
 }
  
 //function that prints the grid/board 
 void chess(char (&board)[8][8], int& row_K, int& col_K, int& row_B1, int& col_B1, int& row_B2, int& col_B2)
 {
 	char(*pointer1)[8]=board;
 	
 	cout<<endl;
	cout<<setw(7)<<0<<setw(6)<<1<<setw(6)<<2<<setw(6)<<3<<setw(6)<<4<<setw(6)<<5<<setw(6)<<6<<setw(6)<<7<<endl<<endl;
	for (int i=0 ; i<8 ; i++)
	{
		cout<<i;
		for (int j=0;j<=7;j++)
		{
			cout<<setw(6)<<pointer1[i][j];
		}
		cout<<endl;
		cout<<endl;
		cout<<endl;
	}
	
	cout<<"\nPosition of king: ("<<row_K<<","<<col_K<<")";
	cout<<"\nPosition of Bishop 1: ("<<row_B1<<","<<col_B1<<")";
	cout<<"\nPosition of Bishop 2: ("<<row_B2<<","<<col_B2<<")";

 }
 
 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );
void moveHare( int * const );

int main()
{
    int tortoise=1;
    int hare = 1;
    clock_t Start, End;
    
    srand( time( 0 ) );

    Start = clock();
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 100 );
      system("cls");
	      
      moveTortoise( &tortoise );
      moveHare(&hare);
      printCurrentPositions( &tortoise, &hare );
      
   }
   End = clock();
   cout << (End-Start)/1000 <<"s";
}

/*印出烏龜與兔子位置*/
void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
	for(int i=1;i<=7;i++){
		for(int j=1;j<=9;j++)
			cout << '-';
		cout << '|';
	}
	cout << endl;
	cout << setw(*bunnyPtr) << 'H' << endl;
	cout << setw(*snapperPtr) << 'T' << endl;
}

/*移動烏龜*/
void moveTortoise( int * const turtlePtr )
{
	int x= (rand()%10)+1;
	if(x<=5){
		*turtlePtr += 3;
	}else if(x<=7){
		*turtlePtr -= 6;
	}else if(x<=10){
		*turtlePtr += 1;
	}
	(*turtlePtr>70)?*turtlePtr=70:(*turtlePtr<1)?*turtlePtr=1:0;;
}

/*移動兔子*/
void moveHare( int * const rabbitPtr )
{
	int x= (rand()%10)+1;
	if(x<=2){
		*rabbitPtr -= 0;
	}else if(x<=4){
		*rabbitPtr += 9;
	}else if(x<=5){
		*rabbitPtr -= 12;
	}else if(x<=8){
		*rabbitPtr += 1;
	}else if(x<=10){
		*rabbitPtr -= 2;
	}
	(*rabbitPtr>70)?*rabbitPtr=70:(*rabbitPtr<1)?*rabbitPtr=1:0;;
}

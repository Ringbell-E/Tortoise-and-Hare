#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );


int main()
{
    int tortoise=1;
    int hare = 1;
    
    srand( time( 0 ) );
    
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 500 );
      system("cls");    
      moveTortoise( &tortoise );
      printCurrentPositions( &tortoise, &hare );
   }
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
	(x>70)?x=70:(x<1)?x=1:0;
}

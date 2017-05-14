#include <ncurses.h>
//#include <iostream>
#include <thread>
#include <queue>
#include <string>
#include <ctime>
using namespace std;

void AddToQueue(queue<int> & queue1,queue<int>  & queue2,int rangeQueue1, int rangeQueue2){

	queue1.push(rand()%rangeQueue1);
	queue2.push(rand()%rangeQueue2);

}

void AddToMatrix(int * & A,queue<int> & queue1,queue<int>  & queue2,int numberOfRows,int numberOfColumns){
	A[queue1.back(),queue2.back()]=1;
	for(int row=0;row<numberOfRows;row++){
		for(int column=0;column<numberOfColumns;column++){
			if(column!=(numberOfColumns-1) && A[row,column]==1){
				A[row,column]=0;
				A[row,column+1]=1;
			}
			column+=1;
		}
		row+=1;
	}

}
int main()
{
	srand( time(NULL));
	int n,m,a,number;
	n=10;
	m=10;
	a = n * m;
	int *A = new int[a]; //Macierz dynamiczna
	A[0,0]=1;
	queue<int> queue1;
	queue<int> queue2;
	AddToQueue(queue1,queue2,10,20);
	initscr();
	printw("HelloWord \n");
	printw("%d",queue1.back());
	printw("\n");
	printw("%d",A[0,0]);
	refresh();
	getch();
	endwin();
	return 0;
}

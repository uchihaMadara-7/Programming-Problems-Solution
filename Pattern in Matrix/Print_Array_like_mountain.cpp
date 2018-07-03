/*
	Given an array and a number n, print the array like a mountain
	Example: array = [R A M A N C L A S S E S]  n = 3
	output:
			R       N       S
			  A   A   C   A   S   S
			    M       L       E
*/

#include <iostream>

using namespace std;

void printLine(char array[], int inter, int start, int mid, int size)
{
    int i = 0;
    int copi = i;
    while(i < copi+start && i < size)
    {
        cout << " ";
        i ++;
    }

    if(i < size)
        cout << array[i ++];

    while(i < size)
    {
        copi = i;
        while(i < copi+inter && i < size)
        {
            cout << "#";
            i ++;
        }

        if(i < size && mid != 0)
            cout <<array[i ++];

        copi = i;
        while(i < copi+mid && i < size)
        {
            cout << "*";
            i ++;
        }

        if(i < size)
            cout << array[i ++];
    }
    cout << endl;
}

void PrintMountain(char array[], int n, int size)
{
	int inter = (2 * n) - 3;
	int start = 0;
    int mid = 0;

    printLine(array, inter, start, mid, size);
    start ++;
    inter -= 2;
    mid ++;

	while(inter > 0)
    {
        printLine(array, inter, start, mid,  size);
        inter -= 2;
        start ++;
        mid += 2;
    }

    printLine(array, (2*n)-3, start, mid, size);
}

int main()
{
	int n = 3;
	int size = 12;
	char array[] = {'R','A','M','A','N','C','L','A','S','S','E','S','\0'};

	PrintMountain(array, n, size);
	return 0;
}

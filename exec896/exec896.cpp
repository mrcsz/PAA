#include <bits/stdc++.h>

#define SIZE 11

using namespace std;

int ratioCalculator(int a0, int an, int n);
int termoN(int a0, int r, int n);
void searchElement(int elements[SIZE], int begin, int end, int r);

int main()
{

	int elements[SIZE];
	int tests, n;


	cin >> tests;

	for(int z = 0; z < tests; z++)
	{
		cin >> n;
		
		for(int i = 0; i < n; i++)
		{
			cin >> elements[i];
		}

		int r = ratioCalculator(elements[0], elements[n - 1], n);

		searchElement(elements, 0, n, r);
	}

	return 0;
}

int ratioCalculator(int a0, int an, int n)
{
	return (an - a0)/n;
}

int termoN(int a0, int r, int n)
{
	return a0 + n * r;
}

void searchElement(int elements[SIZE], int begin, int end, int r)
{
	int middle = (begin + end)/2;
	int t = termoN(elements[0], r, middle);

	//cout << "t = "<< t << endl;

	if(begin >= end)
	{
		if(elements[middle] > t)
		{
			cout << elements[middle] - r << endl;
		} else
		{
			cout << elements[middle] + r << endl;
		}
		return;
	}

	if(t == elements[middle])
	{
		searchElement(elements, middle + 1, end, r);
	} 
	else
	{
		searchElement(elements, begin, middle - 1, r);
	}
}










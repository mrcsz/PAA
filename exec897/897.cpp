#include <bits/stdc++.h>

#define SIZE 31

using namespace std;

int searchDiv(int elements[SIZE], int begin, int end);

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

		if(elements[0] == elements[n-1])
		{
			if(elements[0] == 1)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << n << endl;
			}
		} else cout << n - searchDiv(elements, 0, n - 1) << endl;

		
	}

	return 0;
}

int searchDiv(int elements[SIZE], int begin, int end)
{
	int middle = (begin + end) / 2;

	if(begin >= end)
	{
		return middle;
	}


	if(elements[middle] == 1)
	{
		searchDiv(elements, middle + 1, end);
	} 
	else
	{
		if(middle - 1 != 0)
		{
			if(elements[middle - 1] == 1)
			{
				return middle;
			}
		}else
		{
			return 1;
		}

		searchDiv(elements, begin, middle - 1);
	}
	
}
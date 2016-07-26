#include <bits/stdc++.h>

using namespace std;

#define SIZE 1003

void searchElement(int elements[SIZE], int begin, int end);
int main()
{
	int elements[SIZE];
	int tests, n;


	cin >> tests;

	for(int z = 0; z < tests; z++)
	{
		cin >> n;
		//margens
		n += 2;

		//margem inferior
		elements[0] = -1;

		for(int i = 1; i < n - 1; i++)
		{
			cin >> elements[i];
		}
		//margem superior
		elements[n - 1] = -1;

		//um sobrando em cada margem
		searchElement(elements, 1, n - 2);
		//cout << "--------------" << endl;
	}


	return 0;
}

void searchElement(int elements[SIZE], int begin, int end)
{
	int middle = (begin + end) / 2;
	//cout << "el[mid] = "<<elements[middle] << endl;

	if(begin >= end)
	{
		cout << elements[middle] << endl;
		return;
	}


	if(middle % 2 == 0)
	{
		if(elements[middle] == elements[middle + 1])
		{
			searchElement(elements, begin, middle - 1);
		}
		else if(elements[middle] == elements[middle - 1])
		{
			searchElement(elements, middle + 1, end);
		} else
		{
			cout << elements[middle] << endl;
			return;
		}	
	} 
	else
	{
		if(elements[middle] == elements[middle - 1])
		{
			searchElement(elements, begin, middle - 1);
		}
		else if(elements[middle] == elements[middle + 1])
		{
			searchElement(elements, middle + 1, end);
		} else
		{
			cout << elements[middle] << endl;
			return;
		}
	}
	
	

}
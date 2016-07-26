#include <stdio.h>
#include <stdlib.h>

#define SIZE 1001

void searchMin( int elem[SIZE], int begin, int end);
int main()
{
    int elements[SIZE];
    int t, n, z, i;
	int begin = 0;
	int end;

    scanf("%d %d",&t, &n);
	end = n-1;
    for(z = 0; z < t; z++){
        for(i = 0; i < n; i++){
            scanf("%d", &elements[i]);
        }

		searchMin(elements, 0, n - 1);
		scanf("%d", &n);
	}
    return 0;
}

void searchMin( int elem[SIZE], int begin, int end){
    int middle = (begin + end) / 2;

   //printf("begin = %d, middle = %d, end = %d, elem[midle] = %d\n", begin, middle, end, elem[middle]);

    if(elem[middle - 1] > elem[middle] || begin >= end)
    {
        printf("%d\n", elem[middle]);
        return;
    }
 	 else if(elem[begin] > elem[end] && elem[middle] > elem[end])
    {
     searchMin(elem, middle + 1, end);
    }
    else
    {
        searchMin(elem, begin, middle - 1);
    }
    return;
}

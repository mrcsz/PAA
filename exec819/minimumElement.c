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

//quantidade de testes
    scanf("%d",&t);
	end = n-1; //elemento final do vetor

  //carregando elementos
    for(z = 0; z < t; z++){
      scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", &elements[i]);
        }

//funcao que procura o inicio do vetor circular (o menor valor)
		searchMin(elements, 0, n - 1);
	}
    return 0;
}

void searchMin( int elem[SIZE], int begin, int end){
    int middle = (begin + end) / 2;

   //printf("begin = %d, middle = %d, end = %d, elem[midle] = %d\n", begin, middle, end, elem[middle]);

   //caso do menor acontecer na primeira posicao
   if(middle > 0) //se for maior que zero verifique o elemento em middle - 1
   {
     if(elem[middle - 1] > elem[middle])
     {
       printf("%d\n", elem[middle]); //é o primeiro
       return;
     }
   }

    if(begin >= end) //no final da recursao so resta o menor elemento
    {
        printf("%d\n", elem[middle]);
        return;
    } //chamada recursiva T(n/2)
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

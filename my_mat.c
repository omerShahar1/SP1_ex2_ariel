#include <stdio.h>
#include <math.h>
#include "my_mat.h"
#define SIZE 10

int min(int num1, int num2, int num3) //accept 3 numbers, and return the smallest combination (num1 or num2+num3)
{
    //0 represent no connection so if num1==0 we will return the other option
    if(num1 == 0)
    {
        return (num2 + num3);
    }
    //0 represent no connection so if num2==0 and num3==0 we will return the other option
    if(num2 == 0 && num3 == 0)
    {
        return num1;
    }
    //check smallest number combination (we know both combinations are bigger then 0)
    if (num1 < (num2 + num3))
    {
        return num1;
    }
    return (num2 + num3);
}

void f1(int mat[SIZE][SIZE]) //accept matrix pointer. scan elements from user and insert to metrix. operate Floyd–Warshall_algorithm.
{
    int i, j, k;
    for(i = 0; i < SIZE; i++) //insert numbers 
    {
        for(j = 0; j < SIZE; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    for(k = 0; k < SIZE; k++) //operate Floyd–Warshall_algorithm.
    {
        for(i = 0; i < SIZE; i++)
        {
            for(j = 0; j < SIZE; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k], mat[k][j]);
            }
        }
    }
}

void f2(int mat[SIZE][SIZE])
{
    int i,j;
    scanf("%d%d", &i, &j);
    if(mat[i][j] == 0)
    {
        printf("False\n");
    }
    else
    {
        printf("True\n");
    }
}

void f3(int mat[SIZE][SIZE])
{
    int i,j;
    scanf("%d%d", &i, &j);
    if(mat[i][j] == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",mat[i][j]);
    }
}
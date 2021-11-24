#include <stdio.h>
#include <math.h>
#include "my_mat.h"
#define SIZE 10

int sum(int mat[SIZE][SIZE])
{
    int i, j, answer=0;
    for(i = 0; i < SIZE; i++) 
    {
        for(j = 0; j < SIZE; j++)
        {
            answer += mat[i][j];
        }
    }
    return answer;
}

void f1(int mat[SIZE][SIZE]) //accept matrix pointer. scan elements from user and insert to metrix. operate Floyd–Warshall_algorithm.
{
    int i, j, k, max;
    for(i = 0; i < SIZE; i++) //insert numbers 
    {
        for(j = 0; j < SIZE; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    max = sum(mat) + 1;
    for(i = 0; i < SIZE; i++) //swich cells with 0 exept diagnle to the max vlaue. 
    {
        for(j = 0; j < SIZE; j++)
        {
            if(i!=j && mat[i][j]==0)
            {
                mat[i][j] = max;
            }
        }
    }
    for(k = 0; k < SIZE; k++) //operate Floyd–Warshall_algorithm.
    {
        for (i = 0; i < SIZE; i++) 
        {
            for (j = 0; j < SIZE; j++) 
            {
                if (mat[i][k] + mat[k][j] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
    for(i = 0; i < SIZE; i++) //swich bad cells back to 0.
    {
        for(j = 0; j < SIZE; j++)
        {
            if(i!=j && mat[i][j]==max)
            {
                mat[i][j] = 0;
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
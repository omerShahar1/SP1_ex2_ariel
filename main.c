#include <stdio.h>
#include "my_mat.h"
#define SIZE 10

int main()
{
    int mat[SIZE][SIZE];  //build matrix 10x10 (10 is the requred value)
    char ch;

    do {
        scanf("%c", &ch);
        if(ch == 'A')
        {
            f1(mat);
            continue;
        }
        if(ch == 'B')
        {
            f2(mat);
            continue;
        }
        if(ch == 'C')
        {
            f3(mat);
            continue;
        }
        
    } while(ch != 'D');

    return 0;
}

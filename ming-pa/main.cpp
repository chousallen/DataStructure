#include <iostream>
#include "matrix.h"

using namespace std;

#define DIM 2

Matrix readMat()
{
    unsigned long lt, rt, lb, rb;
    scanf("%lu,%lu,%lu,%lu", &lt, &rt, &lb, &rb);
    char tmp = 0;
    cin >> tmp;
    if (tmp != ']')
    {
        printf("Read Mat Err: right bracket expected\n");
    }
    Matrix r = Matrix(lt, rt, lb, rb);
    //printf("read mat: ");
    //r.print();
    return r;
}

Matrix process()
{
    if(cin.eof())
    {
        printf("Warning: meet end of cin\n");
        return Matrix(1, 0, 0, 1);
    }
    char tmp = 0;
    cin >> tmp;
    if(tmp == '(')
    {
        Matrix left = process();
        cin >> tmp;
        if(tmp != '*')
        {
            printf("process: read left error\n");
        }
        Matrix right = process();
        cin >> tmp;
        if(tmp != ')')
        {
            printf("process: read right error\n");
        }
        return left*right;
    }
    if(tmp == '[')
    {
        return readMat();
    }
    printf("process: left parenthesis or bracket expected, but '%c' got\n", tmp);
    return Matrix(1, 0, 0, 1);
}

int main()
{
    Matrix result = process();
    result.print();

    return EXIT_SUCCESS;
}


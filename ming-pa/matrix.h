//matrix.h

#include <cstring>

#define MAT_DIM 2

class Matrix
{
    public:
        Matrix(); 
        Matrix(int lt, int rt, int lb, int rb);
        const int* operator[](int ind1) const;
        Matrix operator*(Matrix mul) const;
        void print() const;
        ~Matrix(); 

    private:
        int mat[MAT_DIM][MAT_DIM];

};

Matrix::Matrix()
{
    memset(mat, 0, MAT_DIM*MAT_DIM);
}

Matrix::Matrix(int lt, int rt, int lb, int rb)
{
    mat[0][0] = lt;
    mat[0][1] = rt;
    mat[1][0] = lb;
    mat[1][1] = rb;
}

const int* Matrix::operator[](int ind1) const
{
    if(ind1 >= MAT_DIM)
    {
        printf("matrix index out of range\n");
        return 0;
    }
    return mat[ind1];
}

Matrix Matrix::operator*(Matrix mul) const
{
    return Matrix(mat[0][0]*mul[0][0]+mat[0][1]*mul[1][0], mat[0][0]*mul[0][1]+mat[0][1]*mul[1][1], 
            mat[1][0]*mul[0][0]+mat[1][1]*mul[1][0], mat[1][0]*mul[0][1]+mat[1][1]*mul[1][1]);
}

void Matrix::print() const
{
    printf("[%d,%d,%d,%d]\n", mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
}

Matrix::~Matrix()
{}

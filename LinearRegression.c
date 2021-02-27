#include "LinearRegression.h"


vec LeastSquare_fit(vec x, vec y, int m){
    matrixtype res_x, res_y;
    matrix A = zeros_matrix(m+1, m+1);
    matrix B = zeros_matrix(m+1, 1);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            res_x = 0;
            for(int k=0;k<x.N;k++)
                res_x += pow(get(x, k, 0),i+j);
            put(&A, res_x, i, j);
        }
    }

    for(int i=0;i<=m;i++){
        res_y=0;
        for(int k=0;k<x.N;k++)
            res_y += get(y, k, 0)*pow(get(x, k, 0), i);
        put(&B, res_y, i, 0);
    }
    print_matrix(x);
    print_matrix(A);
    print_matrix(B);

    vec a = CGmethod(A, B);
    return a;
} 

vec RegularLeastSquare_fit(vec x, vec y, int m, matrixtype lambda){
    matrixtype res_x, res_y;
    matrix A = zeros_matrix(m+1, m+1);
    matrix B = zeros_matrix(m+1, 1);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            res_x = 0;
            for(int k=0;k<x.N;k++)
                res_x += pow(get(x, k, 0),i+j);
            if(i==j)
                res_x += lambda;
            put(&A, res_x, i, j);
        }
    }
    for(int i=0;i<=m;i++){
        res_y=0;
        for(int k=0;k<x.N;k++)
            res_y += get(y, k, 0)*pow(get(x, k, 0), i);
        put(&B, res_y, i, 0);
    }

    vec a = CGmethod(A, B);
    return a;
}

vec vec_polynomial(vec a, vec x, int m){
    matrixtype res;
    vec y = zeros_matrix(x.N, 1);
    for(int i=0;i<x.N;i++){
        res = 0;
        for(int j=0;j<m;j++){
            res += get(a, j, 0)*pow(get(x, i, 0), j);
        }
        put(&y, res, i, 0);
    }
    return y;
}


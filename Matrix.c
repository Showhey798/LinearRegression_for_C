#include "Matrix.h"

Matrix init_matrix(int n, int m){
    Matrix A = (Matrix)malloc(sizeof(matrix));
    A->N = n;
    A->M = m;
    A->mat = (matrixtype*)malloc(sizeof(matrixtype)*n*m);
    return A;
}

matrixtype get(matrix A, int i, int j){
    if(A.N<=i || A.M<=j){
        printf("get (%d, %d) from Shape(%d, %d) but Index Error\n", i, j, A.N, A.M);
        exit(-1);
    }
    return A.mat[i*A.M + j];
}

void put(Matrix A, matrixtype val,int i, int j){
    if(A->N<=i || A->M<=j){
        printf("put %f at (%d, %d) from Shape(%d, %d) but Index Error\n", val, i, j, A->N, A->M);
        exit(-1);
    }
    A->mat[i*A->M+j] = val;
}


matrix insert(matrix A, matrix B, int axis){

    Matrix C;
    if(axis==0){
        if(A.M != B.M){
            printf("Shape Error\n");
            exit(-1);
        }
        C = init_matrix(A.N+B.N, A.M);
        for(int i=0;i<A.N;i++)
            for(int j=0;j<A.M;j++)
                put(C, get(A, i, j), i, j);
        for(int i=0;i<B.N;i++)
            for(int j=0;j<B.M;j++)
                put(C, get(B, i, j), i+A.N, j);  

    }else if(axis==1){
        if(A.N != B.N){
            printf("Shape Error\n");
            exit(-1);
        }
        C = init_matrix(A.N, A.M+B.M);

        for(int i=0;i<C->N;i++){
            for(int j=0;j<C->M;j++){
                if(j >= A.M)
                    put(C, get(B, i, j-A.M), i, j);
                else
                    put(C, get(A, i, j), i, j);
            }
        }
    }else{
        printf("You must indicate axis=0 or axis=1.\n");
        exit(-1);
    }
    return *C;
}

matrixtype max(matrix A){
    matrixtype max = get(A, 0, 0);
    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.M;j++){
            if(max < get(A, i, j))
                max = get(A, i, j);
        }
    }
    return max;
}

matrixtype min(matrix A){
    matrixtype min = get(A, 0, 0);
    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.M;j++){
            if(min < get(A, i, j))
                min = get(A, i, j);
        }
    }
    return min;
}

void print_matrix(matrix A){
    for(int i=0;i< A.N;i++){
        for(int j=0;j< A.M;j++)
            printf("%f ", get(A, i, j));
        printf("\n");
    }
    printf("\n");
}


matrix zeros_matrix(int n, int m){
    Matrix C = init_matrix(n, m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            C->mat[i*C->M+j] = 0;
    return *C;
}

matrix ones_matrix(int n, int m){
    Matrix C = init_matrix(n, m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            C->mat[i*C->M+j] = 1;
    return *C;
}


matrix add_matrix(matrix A, matrix B){
    // A + B

    if(A.N!=B.N || A.M!=B.M){
        printf("Shape Error\n");
        exit(-1);
    }
    
    Matrix C = init_matrix(A.N, A.M);
    for(int i=0;i<A.N;i++)
        for(int j=0;j<A.M;j++)
            put(C, get(A, i, j) + get(B, i, j), i, j);
    return *C;
}

matrix sub_matrix(matrix A, matrix B){
    // A - B
    if(A.N!=B.N || A.M!=B.M){
        printf("Shape Error\n");
        exit(-1);
    }
    Matrix C = init_matrix(A.N, A.M);
    for(int i=0;i<A.N;i++)
        for(int j=0;j<A.M;j++)
            put(C, get(A, i, j) - get(B, i, j), i, j);
    return *C;
}

matrix pow_matrix(matrix A, int n){
    Matrix C = init_matrix(A.N, A.M);
    for(int i=0;i<A.N;i++)
        for(int j=0;j<A.M;j++)
            put(C, pow(get(A, i, j), n), i, j);
    return *C;
}

matrix add_scalar(matrix A,matrixtype a){
    Matrix C = init_matrix(A.N, A.M);
    for(int i=0;i<A.N;i++)
        for(int j=0;j<A.M;j++)
            put(C, a + get(A, i, j), i, j);
    return *C;
}

matrix sub_scalar(matrix A,matrixtype a){
    Matrix C = init_matrix(A.N, A.M);
    for(int i=0;i<A.N;i++)
        for(int j=0;j<A.M;j++)
            put(C, a-get(A, i, j), i, j);
    return *C;
}

matrix mul_scalar(matrix A,matrixtype a){
    Matrix C = init_matrix(A.N, A.M);
    for(int i=0;i<A.N;i++)
        for(int j=0;j<A.M;j++)
            put(C, get(A, i, j)*a, i, j);
    return *C;
}

matrix div_scalar(matrix A,matrixtype a){
    Matrix C = init_matrix(A.N, A.M);
    for(int i=0;i<A.N;i++)
        for(int j=0;j<A.M;j++)
            put(C, get(A, i, j)/a, i, j);
    return *C;
}

matrix dot(matrix A, matrix B){
    if(A.M != B.N){
        printf("Shape Error\n");
        exit(-1);
    }
    matrix C = zeros_matrix(A.N, B.M);
    for(int i=0;i<A.N;i++)
        for(int j=0;j<B.M;j++)
            for(int k=0;k<A.M;k++)
                C.mat[i*C.M + j] +=  get(A, i, k)*get(B, k, j);
    return C;
}

matrix transpose(matrix A){
    Matrix A_T = init_matrix(A.M, A.N);
    for(int i=0;i<A_T->N;i++)
        for(int j=0;j<A_T->M;j++)
            put(A_T, get(A, j, i), i, j);
    return *A_T;
}

matrixtype trace(matrix A){
    if(A.N != A.M){
        printf("This is not Regular.\n");
        exit(-1);
    }
    matrixtype t = 0;
    for(int i=0;i<A.N;i++)
        t += get(A, i, i);
    return t;
}

matrixtype dist(matrix A, matrix B){
    matrix C, D;
    C = sub_matrix(A, B);
    D = dot(C, transpose(C));
    return trace(D);
}

matrixtype inner_product(matrix A, matrix B){

    if(A.N != B.N || A.M != B.M){
        printf("Shape Error\n");
        exit(-1);
    }
    return trace(dot(transpose(A), B));
}

matrixtype norm(matrix A){return inner_product(A, A);}


vec read_vec(int n, matrixtype a[n]){
    Vec v = init_matrix(n, 1);
    for(int i=0;i<n;i++)
        put(v, a[i], i, 0);
    return *v;
}

vec CGmethod(matrix A, vec b){
    int max_iter=10000, iter=0;
    // Initialize
    matrix x = zeros_matrix(b.N,1);
    matrixtype alpha, beta;
    vec Ap;

    vec p = sub_matrix(b, dot(A, x));
    vec r = p; 
    while(iter < max_iter){
        iter++;
        alpha = inner_product(p, r)/inner_product(p, dot(A, p));
        x = add_matrix(x, mul_scalar(p, alpha));
        Ap = dot(A, p);
        r = sub_matrix(r, mul_scalar(Ap, alpha));
        if(norm(r) < Epsilon)break;
        beta = -(inner_product(r, Ap)/inner_product(p, Ap));
        p = add_matrix(r, mul_scalar(p, beta));
    }
    return x;
}
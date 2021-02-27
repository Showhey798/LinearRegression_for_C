#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define Epsilon (1e-8) // error value

typedef double matrixtype;


typedef struct {
    int N, M;
    matrixtype *mat;
} matrix; 

typedef matrix* Matrix;

/* 
    行列の初期化 
    n×m分の配列を確保して返す
*/
Matrix init_matrix(int n, int m); 

/* 
    行列内の(i, j)要素を取得
*/
matrixtype get(matrix A, int i, int j);

/*
    行列内の(i, j)要素に値を代入
*/
void put(Matrix A, matrixtype val,int i, int j); 

/* AにBを挿入 */
matrix insert(matrix A, matrix B, int axis); 

 /* 最大要素を返す */
matrixtype max(matrix A); 

/* 最小要素を返す */
matrixtype min(matrix A); 

/* 行列を標準出力する */
void print_matrix(matrix A); 

/* 行列を0で初期化する */
matrix zeros_matrix(int n, int m); 

/* 行列を1で初期化 */
matrix ones_matrix(int n, int m); 

/* 行列同士の足し算 */
matrix add_matrix(matrix A, matrix B); 

/* 行列同士の引き算 */
matrix sub_matrix(matrix A, matrix B); 

/* Aのn乗 */
matrix pow_matrix(matrix A, int n); 

/* 行列にスカラーを足す */
matrix add_scalar(matrix A,matrixtype a); 

/* スカラーから行列を引く */
matrix sub_scalar(matrix A,matrixtype a); 

/* 行列にスカラーをかける */
matrix mul_scalar(matrix A,matrixtype a); 

/* 行列からスカラーを割る */
matrix div_scalar(matrix A,matrixtype a); 

/* 行列同士の積 */
matrix dot(matrix A, matrix B); 

/* 転置行列を返す */
matrix transpose(matrix A); 

/* トレースを返す */
matrixtype trace(matrix A); 

/* AとBの距離を算出 */
matrixtype dist(matrix A, matrix B); 

/* 内積 */
matrixtype inner_product(matrix A, matrix B); 

/* 行列の大きさを返す */
matrixtype norm(matrix A); 

/*----------------ベクトルの関数----------------*/
typedef matrix vec;
typedef vec* Vec;

vec read_vec(int n, matrixtype a[n]); // 配列をベクトルに変換
vec CGmethod(matrix A, vec b); // Ax = bを共役勾配法で解く




#endif // _MATRIX_H_
#ifndef _RANDOM_FUNC_H_
#define _RANDOM_FUNC_H_

#include "Matrix.h"

vec linspace(int min, int max, int size);

vec vec_sin(vec x);

matrixtype normal_dist(matrixtype x, matrixtype mu, matrixtype sigma);

vec vec_normal_dist(vec x, matrixtype mu, matrixtype sigma);

// random data in probability distribution

matrixtype uniform_rand(void);

matrixtype normal_dist_rand(matrixtype mu, matrixtype sigma);

vec normal_rand(matrixtype mu, matrixtype sigma, int size);

#endif // _RANDOM_FUNC_H_
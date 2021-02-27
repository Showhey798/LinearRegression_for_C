#include "random_func.h"

vec linspace(int min, int max, int size){
    Vec x = init_matrix(size, 1);
    matrixtype interval = (matrixtype)(max-min)/(matrixtype)(size-1);
    for(int i=0;i<size;i++)
        put(x, min+ i*interval, i, 0);
    return *x;
}
vec vec_sin(vec x){
    Vec y = init_matrix(x.N, 1);
    for(int i=0;i<x.N;i++)
        put(y, sin(2*M_PI*get(x, i, 0)), i, 0);
    return *y;
}

matrixtype normal_dist(matrixtype x, matrixtype mu, matrixtype sigma){
    return (1/(sqrt(2*M_PI*sigma)))*exp(-(x-mu)*(x-mu)/(2*sigma));
}

vec vec_normal_dist(vec x, matrixtype mu, matrixtype sigma){
    Vec y = init_matrix(x.N, 1);
    for(int i=0;i<x.N;i++)
        put(y, normal_dist(get(x, i, 0), mu, sigma), i, 0);
    return *y;
}

matrixtype uniform_rand(void){
    return ((matrixtype)rand()+1.0)/((matrixtype)RAND_MAX+2.0);
}

matrixtype normal_dist_rand(matrixtype mu, matrixtype sigma){
	matrixtype z=sqrt(-2.0*log(uniform_rand())) * sin(2.0*M_PI*uniform_rand());
	return mu + sigma*z;
}

vec normal_rand(matrixtype mu, matrixtype sigma, int size){
    if(size <= 0){
        printf("size error: size<=0\n");
        exit(-1);
    }
    Vec x;
    x = init_matrix(size, 1);

    for(int i=0;i<size;i++)
        put(x, normal_dist_rand(mu, sigma), i, 0);
    return *x;
}

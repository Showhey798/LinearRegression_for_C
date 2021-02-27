#ifndef _LINEARREGRESSION_H_
#define _LINEARREGRESSION_H_

#include "Matrix.h"

/*
最小二乗法 係数を返す
*/
vec LeastSquare_fit(vec x, vec y, int m);

/*
  正則化項込みの最小二乗法(Ridge回帰) 係数を返す 
*/
vec RegularLeastSquare_fit(vec x, vec y, int m, matrixtype lambda); 

/*
  m次多項式関数を返す 
*/
vec vec_polynomial(vec a, vec x, int m); 


#endif
#ifndef _CSV_H_
#define _CSV_H_

#include "Matrix.h"
#include <string.h>

#define MAXLENGTH 1024
/*
    csvファイルを読み込み、その行列を返す
*/
matrix read_csv(char *filename);

/*
    行列Aの要素をcsvファイルとして出力する

*/

void to_csv(matrix A, char* filename);




#endif //_CSV_H_
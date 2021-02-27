#include "LinearRegression.h"
#include "csv.h"


int main(void){
    //データの取得
    char *input_name = "./csv_files/toy_data.csv";
    char *output_name = "./csv_files/regular_least_coef.csv";

    matrix A = read_csv(input_name);

    Vec x, y;
    x = init_matrix(A.N, 1);y = init_matrix(A.N, 1);
    for(int i=0;i<A.N;i++){
        put(x, get(A, i, 0), i, 0);
        put(y, get(A, i, 1), i, 0);
    }

    matrix W = RegularLeastSquare_fit(*x, *y, 9, 1e-3);

    to_csv(W, output_name);

    return 0;
}
#include "csv.h"


matrix read_csv(char *filename){
    FILE *fp;
    char str[MAXLENGTH], *ptr;

    matrixtype *tmp, *start;
    matrix ret_matrix, tmp_matrix;
    int row=0, col;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("%s doesn't exist.\n", filename);
        exit(-1);
    }
    printf("start reading!\n");

    while(fgets(str, MAXLENGTH, fp)!=NULL){
        col = 0;
        ptr = strtok(str, ",");
        while(ptr != NULL){
            tmp = (matrixtype*)malloc(sizeof(matrixtype));
            if(col==0)start = tmp;
            start[col] = atof(ptr);
            col++;tmp++;
            ptr = strtok(NULL, ",");
        }
    if(row == 0)
        ret_matrix = transpose(read_vec(col, start));
    else{
        tmp_matrix = transpose(read_vec(col, start));
        ret_matrix = insert(ret_matrix, tmp_matrix, 0);
    }
    row++;
    }
    free(start);
    fclose(fp);
    printf("completed!\n");
    return ret_matrix;
}

void to_csv(matrix A, char* filename){
    FILE *fp;
    
    fp = fopen(filename, "w");
    if(A.N <= 0 || A.M <=0){
        printf("This matrix doesn't have data.\n");
        exit(-1);
    }
    printf("start writing!\n");

    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.M;j++){
            if(j!=A.M-1)
                fprintf(fp, "%f,", get(A, i, j));
            else
                fprintf(fp, "%f\n", get(A, i, j));
        }
    }
    fclose(fp);
    printf("completed!\n");
}
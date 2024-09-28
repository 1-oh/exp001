#include <stdio.h>
//written by wsq 2024 all rights reserved

#define num 4
int sig(int n1, int n2, int n3, int n4);
int alge(int i,int j,int det[4][4]);
int cal(int caldet[4][4]);

int main(){ 
    int i, j;
    int det[num][num];
    //
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("input det[%d][%d]\n", i, j);                  // 输入4X4行列式A
            scanf("%d", &det[i][j]);
        }
    }
    //
    printf("A=\n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%d\t", det[i][j]);                               // 可视化该4X4行列式A
        }
        printf("\n");
    }
    //
    
    int result = 0;
    result=cal(det);                                            //计算det(A)
    printf("det= %d\n", result);
    //
    if(result==0){                                              //判断A-1是否存在
        printf("no A-1\n");
    }
    else{
    float det_[num][num];
     for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            det_[j][i]=1.0*alge(i,j,det)/result;                        // 得到逆矩阵A-1
        }
    }
    // 
    printf("A-1=\n");
     for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%.2f\t",det_[i][j]);                       // 可视化逆矩阵A-1
        }
        printf("\n");
    }
    }
    return 0;
}

//符号函数
int sig(int n1, int n2, int n3, int n4){
    int sign = 1;
    if (n1 > n2)
    {
        sign *= -1;
    }
    if (n1 > n3)
    {
        sign *= -1;
    }                                                                    // 计算4个数的逆序数
    if (n1 > n4)
    {
        sign *= -1;
    }
    if (n2 > n3)
    {
        sign *= -1;
    }
    if (n2 > n4)
    {
        sign *= -1;
    }
    if (n3 > n4)
    {
        sign *= -1;
    }
    return sign;
}

//代数余子式函数
int alge(int m,int n,int det[4][4]){
    int ret;
    int det3[num][num];
    int i,j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            det3[i][j]=det[i][j];   
        }
    }
    for(i=m,j=0;j<num;j++){
        det3[i][j]=0;
    }
    
    det3[m][n]=1;
    ret=cal(det3);
    return ret;
}

//行列式计算函数
int cal(int caldet[4][4]){
    int calret=0;
    
    int multi = 1, n1, n2, n3, n4, k;
    int sign ;  
                     
    for (n1 = 0; n1 < num; n1++)
    {
        for (n2 = 0; n2 < num; n2++)
        {
            for (n3 = 0; n3 < num; n3++)
            {
                for (n4 = 0; n4 < num; n4++)
                {
                    if (n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4)        // 按定义计算caldet  
                    {

                        multi = caldet[0][n1] * caldet[1][n2] * caldet[2][n3] * caldet[3][n4];
                        sign=sig(n1,n2,n3,n4);
    
                        calret += multi * sign;
                    }
                }
            }
        }
    }
    return calret;
}
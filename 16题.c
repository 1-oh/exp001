#include<stdio.h>
int main(){
	float q1,q2,q3;
	float num1=0,num2=0;
	float m,n;/*m,n is defined by the question*/
	int i;
	printf("i=?\n");
	scanf("%d",&i);
	for(q1=1;q1<=i;q1++){
		for(q2=1;q2<=i;q2++){
			if(q2!=q1){
				for(q3=1;q3<=i;q3++){
					if (q3!=q1&&q3!=q2){
						num1++;
						m=0.5*(q1+q2);
						n=(q1+q2+q3)/3;
						if(m-n<=0.5&&m-n>=-0.5){
							 num2++;
							 printf("q1=%0.1f,q2=%0.1f,q3=%0.1f\n",q1,q2,q3);
						}	 
					}
				}
			}
		}
	}
	float answer;
	answer=(num2/num1);
	printf("num1=%0.1f,num2=%0.1f,the answer is %f",num1,num2,answer);
	return 0;
}

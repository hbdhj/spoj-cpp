#include <stdio>
int main() 
{
int i,j=0;char in[10][20];
for(i= 0; i<10; i++)scanf("%s",in[i]);
for(i= 0; i<10; i++){int r=1;while(in[i][j]!='\0'){char c=in[i][j];if ((c=='T')||(c=='D')||(c=='F')||(c=='F'))r*=2;j++;}printf("%d\n",r);}
return 0;
}

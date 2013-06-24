/*
TASK: ROMAN NUMERALS
Input:
LX XV +
X V *

Output:
LXXV
L
*/
#include <iostream>
using namespace std;
string itom(int n)
{
string ret="";
while(n>=1000){ret+="M";n-=1000;}
if(n>=900){ret+="CM";n-=900;}
if(n>=500){ret+="D";n-=500;}
if(n>=400){ret+="CD";n-=400;}
while(n>=100){ret+="C";n-=100;}
if(n>=90){ret+="XC";n-=90;}
if(n>=50){ret+="L";n-=50;}
if(n>=40){ret+="XL";n-=40;}
while(n>=10){ret+="X";n-=10;}
if(n>=9){ret+="IX";n-=9;}
if(n>=5){ret+="V";n-=5;}
if(n>=4){ret+="IV";n-=4;}
while(n){ret+="I";n--;}
return ret;
}

int mtoi(string str)
{
int ret=0;
for(int i=0;i<str.length();i++)
{
if(str[i]=='M')ret+=1000;
else if(str[i]=='D')ret+=500;
else if(str[i]=='C')
{
if(i<str.length()-1)
{
if(str[i+1]=='M'){ret+=900;i++;}else if(str[i+1]=='D'){ret+=400;i++;}else ret+=100;
}
else
ret+=100;
}
else if(str[i]=='L')ret+=50;
else if(str[i]=='X')
{
if(i<str.length()-1)
{
if(str[i+1]=='C'){ret+=90;i++;}else if(str[i+1]=='L'){ret+=40;i++;}else ret+=10;
}
else
ret+=10;
}
else if(str[i]=='V')ret+=5;
else if(str[i]=='I')
{
if(i<str.length()-1)
{
if(str[i+1]=='X'){ret+=9;i++;}else if(str[i+1]=='V'){ret+=4;i++;}else ret+=1;
}
else
ret+=1;
}
}
return ret;
}

int main()
{
int i,l,r,out[5];
for(i=0;i<5;i++)
{
char left[20], right[20], ac;
scanf("%s %s %c", left, right, &ac);
l=mtoi(left);
r=mtoi(right);
switch(ac)
{
case '+':
out[i]=r+l;
break;
case '-':
out[i]=l-r;
break;
case '*':
out[i]=l*r;
break;
case '/':
out[i]=l/r;
break;
case '%':
out[i]=l%r;
break;
}
}
for(i=0;i<5;i++)
printf("%s\n", itom(out[i]).c_str());
return 0;
}

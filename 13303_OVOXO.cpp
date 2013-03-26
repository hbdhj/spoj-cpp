#include <iostream>
#include <vector>
using namespace std;
#define f(i, n) for(int i=0;i<n;i++)
#define s(l) scanf("%s", l);
#define pf printf
#define rt return
#define el else
#define ef else if
#define sr string
int nc(sr m, char c)
{
int r=0;
f(i,m.length())if(m[i]==c)r++;
rt r;
}
int ch(char a, char b, char c, char d)
{
int r=int(a)+int(b)+int(c);
if(d=='X')if(r==271)rt 1;el rt 0;
ef(r==253) rt 1; el rt 0;
}
int ts(sr m, char c)
{
f(i,3)if(ch(m[i*3],m[i*3+1],m[i*3+2],c))rt i+1;
f(i,3)if(ch(m[i],m[i+3],m[i+6],c))rt i+4;
if(ch(m[0],m[4],m[8],c))rt 7;        
if(ch(m[2],m[4],m[6],c))rt 8;        
rt 0;
}
void fs(sr& m,char c,int i)
{
i--;
if(i<3)m[i*3]=m[i*3+1]=m[i*3+2]=c;
ef(i<6)m[i]=m[i+3]=m[i+6]=c;
ef(i==6)m[0]=m[4]=m[8]=c;
ef(i==7)m[2]=m[4]=m[6]=c;
}
void ps(sr m)
{
f(i,3){f(j,3)pf("%c", m[i*3+j]);pf("\n");}
}
void hd(sr m)
{
int nO=nc(m,'O');
int nX=nc(m,'X');
int c;
if(nO==nX)
{c=ts(m,'X');if(c){pf("WON\n",c);fs(m,'X',c);ps(m);}el pf("CONT\n");}
el
{c=ts(m,'O');if(c){pf("WON\n",c);fs(m,'O',c);ps(m);}el pf("CONT\n");}
}
int main()
{
int i, t;
scanf("%d", &t);
vector<sr> ip(t);
f(i,t)f(j,3){char l[3];s(l);ip[i]+=l;}
f(i,t)hd(ip[i]);
rt 0;
}
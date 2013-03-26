#include <stdio.h>
#include <iostream>
     
#define pc parr[plen++]
typedef unsigned long long ULONG;
ULONG parr[100]={2};
int plen =1;
     
int jacobi(ULONG a, ULONG b)
{
  if ((b<=0) || (b % 2)==0) return 0;
  int j=1;
  if (a<0)
    {
      a=-a;
      if ((b % 4)==3) j=-j;
    }
  while ( a!=0 )
    {
      while ((a % 2)==0)
	{
	  /* Process factors of 2: Jacobi(2,b)=-1 if b=3,5 (mod 8) */
	  a = a/2;
	  if (((b % 8)==3) || ((b % 8)==5))
	    {
	      j=-j;
	    }
	}
      /* Quadratic reciprocity: Jacobi(a,b)=-Jacobi(b,a) if a=3,b=3 (mod 4) */
      //interchange(a,b);
      ULONG temp = a;a=b;b=temp;
      if (((a % 4)==3) && ((b % 4)==3)) {j=-j;}
      a = a % b;
    }
  if (b==1) {return j;}
  else return 0;
}
     
     
ULONG modulePower(ULONG a,
		  ULONG n,
		  ULONG p) // a^n mod p
{
  if(n == 0) return 1;
  if(n == 1) return (a % p);
  if(n & 1)
    {
      return ((a % p) * modulePower(a,n-1,p)) % p;
    }
  else
    {
      ULONG c = modulePower(a,n/2,p);
      return ((c * c) % p);
    }
};
     
bool IsPrimeS(ULONG a, ULONG n)
{
  ULONG pow = modulePower(a,(n-1)/2,n);
  int jac = jacobi(a,n);
  long long jacobian = (n+jac)%n;
  if (!jacobian || (pow != jacobian))
    {
      return false;
    }
  return true;
};
     
bool IsPrime(ULONG n)
{
  if(n == 1) return false;
  if((n & 1) == 0)
    {
      return false;
    }
  for(int i=1;i<plen;i++)
    {
      if ((n % parr[i]) == 0 )
	{
	  return false;
	}
    }
  if(IsPrimeS(2,n) == false) return false;
  if(IsPrimeS(617,n) == false) return false;
  if(IsPrimeS(98621,n) == false) return false;
  if(IsPrimeS(2521176419,n) == false) return false;
  if(IsPrimeS(1660891231,n) == false) return false;
  if(IsPrimeS(1982543363,n) == false) return false;
     
  return true;
};
     
int main()
{
  for(int i =3;i<300;i++)
    {
      int j=0;
      for(;j<plen;j++)
	{
	  if((i % parr[j]) == 0) break;
	}
      if(j<plen)
	{
	  continue;
	}
      else
	{
	  pc = i;
	}
    }
  pc=307;pc=311;pc=331;pc=337;pc=367;pc=373;pc=379;pc=401;pc=421;pc=433;pc=461;pc=613;pc=617;
     
  ULONG init =1UL;
  char arr[5501];
  int i=0;
  for (;i<5500;i++)
    {
      if(IsPrime(init))
	{
	  arr[i]='1';
	}
      else
	{
	  arr[i]='0';
	}
      init = (init + 1234567890) % (1L << 31);
    }
  arr[i]='\0';
  printf("%s",arr);
  return 0;
}

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class complex
{
public:
	float x,y;
	complex()
	{
		x = 0.0;
		y = 0.0;
	}
	complex(const complex &b)
	{
		x = b.x;
		y = b.y;
	}
	complex(float b)
	{
		x = b;
		y = 0;
	}
	complex(float a, float b)
	{
		x = a;
		y = b;
	}
	float abs()
	{
		return sqrt(x*x+y*y);
	}
	complex plus(const complex &b)
	{
		complex ret;
		ret.x = x + b.x;
		ret.y = y + b.y;	
		return ret;
	}
	complex minus(const complex &b)
	{
		complex ret;
		ret.x = x-b.x;
		ret.y = y-b.y;
		return ret;
	}
	complex times(const complex &b)
	{
		complex ret;
		ret.x = x*b.x - y*b.y;
		ret.y = x*b.y + y*b.x;
		return ret;
	}
	complex div(const complex &b)
	{
		complex ret;
		ret.x = (x*b.x + y*b.y)/(b.x*b.x+b.y*b.y);
		ret.y = (y*b.x - x*b.y)/(b.x*b.x+b.y*b.y);
		return ret;
	}
	complex divby(const complex &b)
	{
		complex ret;
		ret.x = (x*b.x + y*b.y)/(x*x + y*y);
		ret.y = (x*b.y - y*b.x)/(x*x + y*y);
		return ret;
	}
	void print()
	{
		if(y>0)
			cout<<x<<"+"<<y<<"j"<<endl;
		else
			cout<<x<<y<<"j"<<endl;
	}
	complex times(const float n)
	{
		complex ret;
		ret.x = x*n;
		ret.y = y*n;
		return ret;
	}
	complex pow(const unsigned short n)
	{
		unsigned short m = n;
		complex ret(1);
		while(m)
		{
			ret = times(ret);
			m--;	
		}
		return ret;
	}
	
};

int compute(string str)
{
	int a,b,c,d;
	sscanf(str.c_str(), "%d %d %d %d", &a, &b, &c, &d);
	complex x(a, b);
	x.print();
	complex y(c, d);
	y.print();
	int stage = 0;
	complex w = x;
	while (w.abs()>y.abs())
	{
		stage ++;
		w=w.div(y);
	}
	cout<<"stage = "<<stage<<endl;
	complex z = x.div(y.pow(stage-1));
	z.print();
	vector<int> an;
	int a1 = z.x;
	cout<<"a1 = "<<a1<<endl;
	complex v = y.times(a1);
	v.print();
	complex u = x.minus((y.pow(stage-1)).times(a1));
	u.print();
}

int main()
{
	/*cout<<"hello"<<endl;
	complex a(1,2);
	complex b(4,5);
        a.print();
        b.print();
	cout<<"(1+2j)+(4+5j)=";
	complex c = b.plus(a);
	c.print();
	cout<<"(4+5j)-(1+2j)=";
	complex d = b.minus(a);
	d.print();
	cout<<"(4+5j)*(1+2j)=";
	complex e = b.times(a);
	e.print();
	cout<<"(1+2j)*(4+5j)=";
	complex f = a.times(b);
	f.print();
	cout<<"(-6+13j)/(1+2j)=";
	complex g = f.div(a);
	g.print();
	cout<<"(-6+13j)/(4+5j) = ";
	complex h = b.divby(f);
	h.print();
	cout<<"abs(1+2j)="<<a.abs()<<endl;
	cout<<"abs(4+5j)="<<b.abs()<<endl;
	cout<<"(4+5j)*3 = ";
	complex i = b.times(3);
	i.print();
	cout<<"(1+2j)$2 = ";
	complex j = a.pow(2);
	j.print();
	cout<<"(4+5j)$3 = ";
	complex k = b.pow(3);
	k.print();*/
	vector<string> inputs;
	inputs.push_back("191 -192 11 -12");
	for (int i = 0; i<inputs.size(); i++)
	{
		compute(inputs[i]);
	}
	
	return 0;
}


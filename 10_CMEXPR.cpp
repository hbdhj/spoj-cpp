/*
 * 2012/11/28
 TASK: Complicated Expressions
 ALGO: expression tree
 */
#include <stack>

using namespace std;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAXLEN = 256;

struct Node 
{
	int left, right;
	char token;
};

char infix[MAXLEN], result[MAXLEN], postfix[MAXLEN];
Node Tree[MAXLEN];
int pidx;

inline bool isoper(char ch)
{
	return (ch=='+'||ch=='-'||ch=='*'||ch=='/');
}

inline bool isvar(char ch) 
{
	return (ch>='a' && ch<='z');
}

inline int precd(char ch) 
{
	switch(ch) 
    {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		default : return 3;
	}
}

void getPostfix(char *post, int &plen, char *inp, int len) 
{
	plen = 0;
	stack< char > S;
	for(int i = 0; i < len; i++) 
    {
		if(isvar(inp[i])) 
            post[plen++] = inp[i];
		else if(inp[i]=='(') 
            S.push('(');
		else if(inp[i]==')') {
			while(!S.empty() && S.top()!='(') 
            {
				post[plen++] = S.top();
				S.pop();
			}
			if(!S.empty()) S.pop();
		}
		else 
        {
			while(!S.empty() && S.top() != '(' && precd(S.top()) >= precd(inp[i])) 
            {
				post[plen++] = S.top();
				S.pop();
			}
			S.push(inp[i]);
		}
	}
	while(!S.empty())
    {
		post[plen++] = S.top();
		S.pop();
	}
}

int buildTree(char *post, int len) 
{
	stack< int > S;
	int idL, idR, nodes = 0;
	for(int i = 0; i < len; i++) 
    {
		if(islower(post[i])) 
        {
			Tree[nodes].left = Tree[nodes].right = -1;
			Tree[nodes].token = post[i];
			S.push(nodes++);
		}
		else 
        {
			idR = S.top(); S.pop();
			idL = S.top(); S.pop();
			Tree[nodes].left = idL;
			Tree[nodes].right = idR;
			Tree[nodes].token = post[i];
			S.push(nodes++);
		}
	}
	return S.top();
}

void print(int root) 
{
	bool br;
	char ch;
	switch(Tree[root].token) 
    {
		case '+':
			print(Tree[root].left);
			result[pidx++] = '+';
			print(Tree[root].right);
		break;
		case '-':
			print(Tree[root].left);
			result[pidx++] = '-';
			ch = Tree[Tree[root].right].token;
			br = (ch=='+') | (ch=='-');
			if(br) result[pidx++] = '(';
			print(Tree[root].right);
			if(br) result[pidx++] = ')';
		break;
		case '*':
			ch = Tree[Tree[root].left].token;
			br = (ch=='+') | (ch=='-');
			if(br) result[pidx++] = '(';
			print(Tree[root].left);
			if(br) result[pidx++] = ')';
			result[pidx++] = '*';
			ch = Tree[Tree[root].right].token;
			br = (ch=='+') | (ch=='-');
			if(br) result[pidx++] = '(';
			print(Tree[root].right);
			if(br) result[pidx++] = ')';
		break;
		case '/':
			ch = Tree[Tree[root].left].token;
			br = (ch=='+') | (ch=='-');
			if(br) result[pidx++] = '(';
			print(Tree[root].left);
			if(br) result[pidx++] = ')';
			result[pidx++] = '/';
			ch = Tree[Tree[root].right].token;
			br = !islower(ch);
			if(br) result[pidx++] = '(';
			print(Tree[root].right);
			if(br) result[pidx++] = ')';
		break;
		default : result[pidx++] = Tree[root].token;
	}
}

int main() 
{
	int t = atoi(fgets(infix, MAXLEN, stdin));
	int ilen, plen, root;
	while(t--) 
    {
		fgets(infix, MAXLEN, stdin);
		for(ilen = 0; infix[ilen] > ' '; ilen++);
		getPostfix(postfix, plen, infix, ilen);
		root = buildTree(postfix, plen);
		pidx = 0; print(root); result[pidx] = 0;
		puts(result);
	}
	return 0;
}

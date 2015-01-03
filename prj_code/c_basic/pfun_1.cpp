nclude <iostream> 

using namespace std; 

typedef int (*PF(int))(int,int); 

int f(int,int) 
{ 
	return 1 ; 
} 
int (*(ff(int)))(int,int) 
{ 
	return f ; 
} 
void main() 
{ 
	PF *pf1; 
	pf1 = ff; 
	cout << (*pf1(10))(1,2) << endl; 
} 

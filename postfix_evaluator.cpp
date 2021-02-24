// by Gabriel Pawlak

#include<iostream>
#include<cstdlib>
#include<string>
#include<stack>
#include<math.h>

using namespace std;

int main()
{
	string input;
	
	cout <<"Enter the expression in a postfix notation, separating consecutive elements with commas (for floating point numbers use . )\n";
	cin >> input;
	
	cout << endl;
		
    stack < float > stos;
	string tempint;
	bool itwasint = false;
	float k;
	
	int length = input.length();

	for(int i=0;i<length;i++)
	{
		if((input[i] == ',')&&(itwasint))
		{
		     k = stof(tempint);
		     stos.push(k);
		     tempint = "";
		     itwasint = false;
		}
		else if(((input[i] >= 48)&&(input[i] <= 57))||(input[i] == '.')||((input[i] == '-')&&((input[i+1] >= 48)&&(input[i+1] <= 57))))//chary od 48 do 57 to cyfry
	     {
	     	tempint += input[i];
	     	itwasint = true;
	     }
	     else if(input[i] == '~')
	     {
	     	stos.top() -= 2*stos.top();
	     }
	      else if((input[i] == 's')&&(input[i+1] == 'q'))
	     {
	     	i += 3;
	     	stos.top() = sqrt(stos.top());
	     }
	      else if(input[i] == '+')
	     {
	     	k = stos.top();
	     	stos.pop();
	     	stos.top() += k;	
	     }
	       else if(input[i] == '-')
	     {
	     	k = stos.top();
	     	stos.pop();
	     	stos.top() -= k;	
	     }
	     else if(input[i] == '*')
	     {
	     	k = stos.top();
	     	stos.pop();
	     	stos.top() *= k;	
	     }
	     else if(input[i] == '/')
	     {
	     	k = stos.top();
	     	stos.pop();
	     	stos.top() /= k;	
	     }
	     else if(input[i] == '^')
	     {
	     	k = stos.top();
	     	stos.pop();
	     	stos.top() = pow(stos.top(),k);
	     }
	     else if(input[i] == 's')
	     {
	     	i = i+2;
	     	stos.top() = sin(stos.top());	
	     }
	         else if(input[i] == 'c')
	     {
	     	i =i+2;
	     	stos.top() = cos(stos.top());	
	     }		   	     
	}
	
	cout << "Result: "<< stos.top();
	
	return 0;	
}

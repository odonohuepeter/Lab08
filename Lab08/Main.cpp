/*
Author: Peter O'Donohue
Creation Date: 08/09/17
Modification Date: 08/10/17
Description: This program is a postfix calculator. When promted, key in an arithmetic
expression in postfix form. The program will then compute and print the result. When you
want to finish using the calculator, key in the word "stop" and the program will stop.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>

using namespace std;

// function prototypes
void computeResult(char operation, stack<double>& tempStack);


int main()
{
	char ch = ' ';
	char prevCh = ' ';
	double operandOne = 0;
	double operandTwo = 0;
	string expression = "";
	string operand = "";
	double result = 0;
	double operandNum = 0;
	stack<double> expressionStack;

	cout << "Key in an expression in postfix form and press enter: ";
	getline (cin, expression);

	while (expression != "stop")
	{
		for (int i = 0; i < expression.length(); ++i)
		{
			ch = expression.at(i);
			if (i > 0)
				prevCh = expression.at(i - 1);
				if (ch == '+')
				{
					computeResult('+', expressionStack);
				}

				else if (ch == '-')
				{
					computeResult('-', expressionStack);
				}

				else if (ch == '*')
				{
					computeResult('*', expressionStack);
				}
				

				else if (ch == '/')
				{
					computeResult('/', expressionStack);
				}
				

				else if (ch == '=')
				{
					computeResult('=', expressionStack);
				}
				
				else if (ch == ' ' && (prevCh != '+' && prevCh != '-' && prevCh != '*' && prevCh != '/' && prevCh != '='))
				{
					operandNum = atof(operand.c_str());
					expressionStack.push(operandNum);
					operand = "";
					operandNum = 0;
				}

				else
				{
					operand += expression.at(i);
				}

		}
		cout << "Key in another expression or 'stop' to quit: ";
		cin >> expression;
	}
	system("pause");
	return 0;
}

// function definitions
void computeResult(char operation, stack<double>& tempStack)
{
	double tempResult = 0.0;
	double operandOne = 0.0;
	double operandTwo = 0.0;

	switch (operation)
	{
	case '+':
	{
		operandTwo = tempStack.top();
		tempStack.pop();
		operandOne = tempStack.top();
		tempStack.pop();
		tempResult = operandOne + operandTwo;
		tempStack.push(tempResult);
	}
	break;

	case '-':
	{
		operandTwo = tempStack.top();
		tempStack.pop();
		operandOne = tempStack.top();
		tempStack.pop();
		tempResult = operandOne - operandTwo;
		tempStack.push(tempResult);
	}
	break;

	case '*':
	{
		operandTwo = tempStack.top();
		tempStack.pop();
		operandOne = tempStack.top();
		tempStack.pop();
		tempResult = operandOne * operandTwo;
		tempStack.push(tempResult);
	}
	break;

	case '/' :
	{
		operandTwo = tempStack.top();
		tempStack.pop();
		operandOne = tempStack.top();
		tempStack.pop();
		tempResult = operandOne / operandTwo;
		tempStack.push(tempResult);
	}
	break;

	case '=' :
	{
		cout << fixed << showpoint << setprecision(5) << tempStack.top() << endl;
		tempStack.pop();
	}
	break;
	}
}
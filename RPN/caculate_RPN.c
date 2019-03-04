#include <stdio.h>

//convert string to int
int str_to_int(char* str, int len)
{
	int result = 0;
	int offset = len - 1;
	if(str[len-1] == '\0') offset--;
	int temp = 1;
	while(offset >= 0)
	{
		//printf(" %c",str[offset]); 
		result += (str[offset] - 48) * temp;
		temp*=10;
		offset--; 
	}
	return result;
}


//define stack
int stack[100];
int top = -1;
void push(int val) { ++top; stack[top] = val; }
int pop() {return stack[top--];}
void print_stack()
{
	printf("Stack: ");
	for(int i = 0; i < 10; i++)
		printf("%d ", stack[i]);
	printf("\n");
}

int caculate_RPN(char* exp, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(exp[i] == ' '){ printf("_rong_\n"); continue;}
		else if(exp[i] >= 48 && exp[i] <= 57)
		{
			int len = 1;
			int j = i + 1;
			while(exp[j] >= 48 && exp[j] <= 57)
			{
				j++;
				len++;
			}
			printf("%d ", str_to_int(&exp[i], len));
			push(str_to_int(&exp[i], len));
			i = j-1;
		}
		else
		{
			printf("%c", exp[i]);
			int y = pop(), x = pop();
			switch(exp[i])
			{
				case '+': push(x + y); break;
				case '-': push(x - y); break;
				case '*': push(x * y); break;
				case '/': push(x / y); break;
			}
		}
		print_stack();
	}
	print_stack();
	return pop();
}

int len(const char* str)
{
	int i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}

void main()
{
	char* str = "10 2/3+7 4-*";
	int res = caculate_RPN(str,len(str));
	printf("%d", res);
}

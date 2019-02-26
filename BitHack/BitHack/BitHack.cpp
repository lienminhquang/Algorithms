// BitHack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <functional>

int v = -123, sign;

void compute_the_sign_of_an_integer_1()
{
	sign = -(v < 0);
}

void compute_the_sign_of_an_integer_2()
{
	sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
}

void compute_the_sign_of_an_integer_3()
{
	sign = v >> (sizeof(int) * CHAR_BIT - 1);
}

void time_counting(std::function<void()> fn)
{
	int times, timed;
	times = clock();	

	for (int i = 0; i < 10000000; ++i)
	{
		fn();
	}

	timed = clock();
	times = timed - times;
	std::cout << "\ntime: " << times;
}

//detect if two integers have opposite signs
int x = 10, y = -2342;
bool f;
void opposite_sign_1()
{
	f = x * y;
}

void opposite_sign_2()
{
	f = (x ^ y) < 0;
}

//compute abs of integer


void abs_1()
{
	int v = -100;
	int mask = v >> 31;
	int r = (v + mask) ^ mask;
}

void abs_2()
{
	int v = -100;
	int r = v > 0 ? v : -v;
}

//compute the min max of two integer
void min_2()
{
	bool f = y ^ ((x ^ y) & -(x < y)); // min(x, y)
}

void min_1()
{
	bool f = x < y ? x : y;
}


//determinate if an integer is power of 2
void isPowerOf2_1()
{
	int x = 32768;

	while (x > 1)
	{
		if ((x % 2) == 1) 
		{
			bool rs = false;
			return;
		}
		x /= 2;
	}

	bool rs = true;
}

void isPowerOf2_2()
{
	int x = 32768;

	bool f = x && !(x & (x - 1));
}

int main()
{
	
	
	
	/*time_counting(compute_the_sign_of_an_integer_1);
	time_counting(compute_the_sign_of_an_integer_2);
	time_counting(compute_the_sign_of_an_integer_3);*/

	//time_counting(opposite_sign_1); // debug: 2417 rl: 33
	//time_counting(opposite_sign_2); // debug: 2417 rl: 28

	//time_counting(abs_1); // debug: 2637 rl: 35 ???
	//time_counting(abs_2); // debug: 2417 rl: 38

	for (int i = 0; i < 10; ++i) {
		//time_counting(min_1); // debug: 2637 rl: 35 ???
		//time_counting(min_2); // debug: 2417 rl: 38

		time_counting(isPowerOf2_1); // debug: 2637 rl: 35 ???
		time_counting(isPowerOf2_2); // debug: 2417 rl: 38

		std::cout << "\n -----------------------------------------------";
	}

	system("pause");
    return 0;
}


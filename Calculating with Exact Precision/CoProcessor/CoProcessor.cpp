#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	int Program;
	while (cout << "Please,enter the number of program to be launched : "&&cin >> Program) {
		cout << endl;
		switch (Program) {
		case 1: 
		{
			long double result_temp = 0;
			long double result_accum = 0;
			long double result = 0;
			long double k = 1;
			k = k - 1;
			long double four = 4;
			long double one = 1;
			long double two = 2;
			long double buf;
			long double precision = 1.0;
			int number;

			cout << "ln2 = " << setprecision(18) << log(2) << endl;
			cout << endl;

			for (long double n = 1; n < 100000; n++) {
				k = n;
				k = k - 1;
				result_temp = 0;
				_asm {
				_begin_:
					finit
						fld one
						fadd k
						fst k

						fld k
						fld k
						fmul st(0), st(1)
						fld four
						fmul st(0), st(1)
						fsub one
						fld k
						fmul st(0), st(1)
						fst buf
						fld one
						fdiv buf

						fadd result_temp
						fst result_temp
						fld n
						fld k
						fcompp
						fstsw ax
						sahf
						jne _begin_

						_end_ :

					fld result_accum
						fadd result_temp
						fst result_accum

						fadd one
						fdiv two
						fst result

				}


				long long int num1 = 0;
				long long int num2 = 0;
				num1 = log(2) * pow(10.0, precision);
				num2 = result * pow(10.0, precision);
				if (num1 == num2) {
					cout << "Precision = " << precision << "; " << "Iterations to achieve = " << n << "; " << "Value = " << setprecision(18) << result << ";" << endl;
					precision++;
				}
			}
			cout << endl;
			break;
		}
		case 2:
		{
			long double n = 10000;
			long double k = 1;
			long double left_range = 0;
			long double right_range = 2 * M_PI;
			long double step = (right_range - left_range) / n;
			long double buf=0;
			long double result_accum = 0;
			long double result=0;
			long double one = 1;
			long double two = 2;
			n = n - 1;
			k = k - 1;
			_asm
			{
				finit
				_beg_:
				fld k
				fadd one
				fstp k
				fld step
				fmul k
				fadd left_range
				fst result
					
				fsin
				fstp buf
				fld result
				fmul result
				fadd buf 
				fstp buf
				fld result_accum
				fadd buf
				fstp result_accum
				fld k
				fld n

				fcompp
				fstsw ax
				sahf
				jne _beg_

				fld result_accum
				fmul two
				fst buf
				fld left_range

				fsin
				fst result
				fld left_range
				fmul left_range
				fadd result
				fst result
				fld right_range
				fsin
				fadd result
				fst result
				fld right_range

				

				fmul right_range
				fadd result
				fadd buf
				fmul step
				fdiv two
				fst result
			}
			cout << "Lets calculate the definite integral F(x)= I( x^2 + sin(x) )" << endl;
			cout << "Our range is [" << left_range << ";" << right_range << "]" << endl;
			cout << "For n = " << n+1 << endl;
			cout << "F(x) = f(x_0) + SUM <k=1;n-1> (f(x_k)) + f(x_n) = "<<setprecision(18) << result << endl;
			cout << endl;

			break;
		}
		case 3:
		{
			long double buf = 1;
			long double temp = 0;
			long double result=0;
			long double k = 0;
			long double one = 1;

			long double n = 25;

			long double x;
			long double a;

			cout << "Lets calculate a^x " << endl;
			cout << "Please,enter number <a> and its power <x> :" << endl;
			cout << "a = "; cin >> a;
			cout << "x = "; cin >> x;
			long double ln_a = log(a);
			_asm

			{
				finit
				fld result
				fadd one
				fstp result
				_start_:
				fld k
				fadd one
				fstp k

				fld buf
				fmul ln_a
				fmul x
				fdiv k
				fstp buf
				fld result
				fadd buf
				fstp result

				fld n
				fld k

				fcompp
				fstsw ax
				sahf
				jne _start_
			}
			cout <<a<<"^"<<x<<" = "<< setprecision(18) << result << endl;
			cout << endl;
			break;
		}
		
		}
		

	}
	system("pause");
	return 0;
}
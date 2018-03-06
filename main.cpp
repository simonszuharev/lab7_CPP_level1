#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <strstream>

/*Write a function that converts a decimal number to its Roman numeral equivalent.  The function takes an integer argument and returns a string. The function prototype is:

string DecimalToRoman(int);

The decimal number to convert must be in the range 1 - 4999,  An algorithm for conversion uses the following table:

Decimal Value (v)	1	4	5	9	10	40	50	90	100	400	500	900	1000
Roman Numeral (n)	I	IV	V	IX	X	XL	L	XC	C	CD	D	CM	M
Perform the following steps to find the Roman numeral equivalent of the decimal number 2012.

From the above table find the highest decimal value (v) that is less than or equal to the decimal number (x) and its corresponding Roman numeral (n).
Write the roman numeral (n) that you found and subtract its value (v) from (x).
Repeat steps 1 and 2 until the value of (x) is zero.
The following is an example of converting the number 2012 to its Roman numeral equivalent:

Iteration	Decimal(x)	Highest Decimal(v)	Highest Roman(n)	Temporary Result
1	2012	1000	M	M
2	1012	1000	M	MM
3	12	10	X	MMX
4	2	1	I	MMXI
5	1	1	I	MMXII
Write a program that utilizes the DecimalToRoman function.  The program should contain a loop that prompts the user to enter a decimal number. An entry of zero should terminate the loop and end the program.  If the number is in the range 1 - 4999, call the DecimalToRoman function and display the result of the conversion.

Submit your solution (main.cpp) as the file lab7_annnnnnn.cpp where annnnnnn is your ACC student identification number.*/

using namespace std;

//prototypes
string DecimalToRoman(int value);


int main()
{   int year;


    cout << "Lab 7 Convert decimal Number to Roman Numeral\n";
    cout << "---------------------------------------------" << endl;

    do{
        cout << "\nDecimal Value to Convert to Roman Numeral? ";
        cin.clear(); cin.sync();
		cin >> year;
        if(year >0 && year < 5000){
        cout << "'" << DecimalToRoman(year) << "'" << " is the Roman equivalent of " << year << endl;
        continue;
            }
            else{
			if(year == 0){
                break;
            }
            cout << "Number must be 1 - 4999 or 0 to end." << endl;
			continue;

            }
    }while(year!=0);
    return 0;
}

string DecimalToRoman(int value)
{
  struct RomanNumbersStruct { int value; char const* numeral; };
  struct RomanNumbersStruct const romanNumber[] =
     { 1000, "M", 900, "CM", 500, "D", 400, "CD",
        100, "C", 90, "XC", 50, "L", 40, "XL",
         10, "X", 9, "IX", 5, "V", 4, "IV", 1, "I",
          0, NULL };

  string result;
  for (RomanNumbersStruct const* current = romanNumber; current->value > 0; ++current)
  {
    while (value >= current->value)
    {
      result += current->numeral;
      value  -= current->value;
    }
  }
  return result;
}

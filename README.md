#bigdecimal.h Header File for C++

This header file if for C++ for mingw complier.
The purpose of this header file is to calculate results with greater accuracy.
It can handle numbers of any length.
It can add, subtract, multiply, divide and compare numbers of any length and give results accurately without the limitation of standard datatypes.

Characterstics and Behavior :

It has 1 class with 7 public methods.
Class BigNumbers stores all the data values and perform the operation accordingly.
Instantiate BigNumbers class object and use the below mentioned functions.

Methods :
1. int comparison(string a,string b) 
	This method compares the numbers and return result.
	It takes two string variables(represent two numbers) as arguements and returns an integer.
	if a > b return > 0
	if a < b return < 0
	if a = b return 0

2. string calculator(string a,string b) 
	This method calculate results according to the operator provided.
	It takes three string variables(represent two numbers and one operator) as arguements and returns a string.
	Opeator List : {"+","-","*","/",">","<",">=","<=","=","!="}
	if + return a + b
	if * return a * b
	if - return a - b
	if / return a / b
	if > return if a > b -> True
		    if a <= b -> False
	if < return if a < b -> True
		    if a >= b -> False 	 
	if = return if a = b -> True
		    if a != b -> False
	if >= return if a >= b -> True
		    if a < b -> False
	if <= return if a <= b -> True
		    if a > b -> False
	if != return if a != b -> True
		    if a = b -> False
3. string multiplication(string a,string b)
	This method multiply two numbers.
	It takes two string variables(represenr two numbers) as arguements and returns a string.
	return a * b

4. string addition(string a,string b)
	This method add two numbers.
	It takes two string variables(represenr two numbers) as arguements and returns a string.
	return a + b

5. string subtraction(string a,string b)
	This method subtract two numbers.
	It takes two string variables(represenr two numbers) as arguements and returns a string.
	return a - b

6. string division(string a,string b)
	This method divide two numbers.
	It takes two string variables(represenr two numbers) as arguements and returns a string.
	return a / b

7. string absolute(string a)
	This method returns the absolute value.
	It takes single arguement as arguement and returns a string.
	if a < 0 return -a
	if a >= 0 return a 

Note :

This class BigNumbers can handle numbers of any length with floating point support also.
It is also compatible for handling floating point numbers.
Also it can handle sign convention in numbers like positive and negative numbers.
By default the division method support only 10 decimal digits, to increase further just provide that integer during the object instatiation of BigNumbers class constructor.
All illegal numbers are checked inside these functions so only provide valid numbers otherwise "Invalid Input !" is returned.
If provided operator does not match with the operator list provided in calculator method, "Invalid Operator !" is returned.    
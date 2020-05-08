#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std ; 
class BigNumbers
{
		string a, b, ch ;
		bool sign ;
		int limit ;
		bool numberValidator(string) ;
		int compare(string,string) ;
		string add(string,string,int) ;
		string multiply(string,string) ;
		string subtract(string,string) ;
		string divide(string,string) ;
		int sizeCheck(string,string) ;
		string equalResize(string,string,int) ;
		string normalAddition(string,string,int = 0) ;
		string pointAddition(string,string) ;
		string normalMultiplication(string,string) ;
		string pointMultiplication(string,string) ;
		string normalSubtraction(string,string) ;
		string pointSubtraction(string,string) ;
		string normalDivision(string,string) ;
		string pointDivision(string,string) ;   
		string multiplyBy10Power(string,int) ;    
		string divideBy10Power(string,int) ;
		string abs(string) ;
		int getPointLoc(string) ;
		bool pointPresent(string) ;
		bool checkForZero(string) ;
		bool checkForOne(string) ;
		string resultOptimiser(string) ;
		string removePoint(string) ;
		string trimZeros(string) ;
		bool divisibleBy10(string) ;
		int countZeros(string) ;
		string addManager(string,string) ;   
		string subManager(string,string) ;
		bool mulManager(string,string) ;   
		bool signCheck(string,string) ;                   
	public :
		int comparison(string,string) ;
		string calculator(string,string,string) ;
		string multiplication(string,string) ;
		string addition(string,string) ;
		string subtraction(string,string) ;
		string division(string,string) ;		
		string absolute(string) ;
		BigNumbers(int l = 10)
		{
			sign = true ;
			a = "None" ;
			b = "None" ;
			ch = "None" ;
			limit = l ;
		}
} ;
string BigNumbers :: calculator(string a,string b,string ch)
{
	this->ch = ch ;
	if(ch == "+")
		return addition(a,b) ;
	else if(ch == "*")
		return multiplication(a,b) ;
	else if(ch == "-")
		return subtraction(a,b) ;
	else if(ch == "/")
		return division(a,b) ;
	else if(ch == ">")
		if(comparison(a,b) > 0)
			return "True" ;
		else
			return "False" ;
	else if(ch == "<")
		if(comparison(a,b) < 0)
			return "True" ;
		else
			return "False" ;
	else if(ch == "=")
		if(comparison(a,b) == 0)
			return "True" ;
		else
			return "False" ;
	else if(ch == ">=")
		if(comparison(a,b) >= 0)
			return "True" ;
		else
			return "False" ;
	else if(ch == "<=")	
		if(comparison(a,b) <= 0)
			return "True" ;
		else
			return "False" ;
	else if(ch == "!=")
		if(comparison(a,b) == 0)
			return "False" ;
		else
			return "True" ;
	else	
		return "Invalid Operator !" ;	
}
string BigNumbers :: subtraction(string a,string b)
{
	if(numberValidator(a) && numberValidator(b))
	{
		if(signCheck(a,b))
			return resultOptimiser(subManager(a,b)) ;
		if(compare(a,b) < 0)
		{
			this->sign = false ;
			this->a = trimZeros(abs(b)) ;
		    this->b = trimZeros(abs(a)) ;
		}
		else
		{    
			this->a = trimZeros(abs(a)) ;
			this->b = trimZeros(abs(b)) ;
		}
		if(pointPresent(this->a) || pointPresent(this->b))
			return resultOptimiser(pointSubtraction(this->a,this->b)) ;
		else
			return resultOptimiser(normalSubtraction(this->a,this->b)) ;
	}
	return "Invalid Inputs !" ;	
}
string BigNumbers :: multiplication(string a,string b)
{
	if(numberValidator(a) && numberValidator(b))
	{
		this->sign = mulManager(a,b) ;
		this->a = trimZeros(abs(a)) ;
		this->b = trimZeros(abs(b)) ;
		if(pointPresent(this->a) || pointPresent(this->b))
			return resultOptimiser(pointMultiplication(this->a,this->b)) ;
		else
			return resultOptimiser(normalMultiplication(this->a,this->b)) ;
	}
	return "Invalid Inputs !" ;	
}
string BigNumbers :: addition(string a,string b)
{
	if(numberValidator(a) && numberValidator(b))
	{   
		if(signCheck(a,b))
			return resultOptimiser(addManager(a,b)) ;
		this->a = trimZeros(abs(a)) ;
		this->b = trimZeros(abs(b)) ;
		if(pointPresent(this->a) || pointPresent(this->b))
			return resultOptimiser(pointAddition(this->a,this->b)) ;
		else
			return resultOptimiser(normalAddition(this->a,this->b)) ;
	}
	return "Invalid Inputs !" ;	
}
string BigNumbers :: division(string a,string b)
{
	if(numberValidator(a) && numberValidator(b))
	{
		this->sign = mulManager(a,b) ;
		this->a = trimZeros(abs(a)) ;
		this->b = trimZeros(abs(b)) ;
		if(pointPresent(this->a) || pointPresent(this->b))
			return resultOptimiser(pointDivision(this->a,this->b)) ;
		else
			return resultOptimiser(normalDivision(this->a,this->b)) ;
	}
	return "Invalid Inputs !" ;	
}
int BigNumbers :: comparison(string a,string b)
{
	if(numberValidator(a) && numberValidator(b))
	{	
		this->a = trimZeros(a) ;
		this->b = trimZeros(b) ;
		int signA = 0, signB = 0 ;
		if(a[0] == '-')
			signA = -1 ;
		if(b[0] == '-')
			signB = -1 ;
		if(signA == 0 && signB == 0)
			return compare(a,b) ;
		else if(signA == 0 && signB == -1)
			return 1 ;
		else if(signA == -1 && signB == 0)
			return -1 ;
		else
			return -compare(abs(a),abs(b)) ;
	}
	cout <<"Invalid Inputs !" ;
	return 0 ;
}
bool BigNumbers :: signCheck(string a,string b)
{
	if(a[0] == '-' || a[0] == '+' || b[0] == '-' || b[0] == '+')
		return true ;
	return false ;
}
string BigNumbers :: addManager(string a,string b)
{
	int signA = 0, signB = 0 ;
	if(a[0] == '-')
		signA = -1 ;
	if(b[0] == '-')
		signB = -1 ;
	if(signA == -1 && signB == -1)
	{
		this->sign = false ;
		return addition(abs(a),abs(b)) ; 
	}	
	else if(signA == -1 && signB == 0) 
	{
		int res = compare(abs(a),abs(b)) ;
		if(res > 0)
		{	
			this->sign = false ;
			return subtraction(abs(a),abs(b)) ;
 		}
		else
		{	
			this->sign = true ;
			return subtraction(abs(b),abs(a)) ;
		}
	}
	else if(signA == 0 && signB == -1) 
	{
		int res = compare(abs(a),abs(b)) ;
		if(res >= 0)
		{	
			this->sign = true ;
			return subtraction(abs(a),abs(b)) ;
		}
		else
		{	
			this->sign = false ;
			return subtraction(abs(b),abs(a)) ;
		}
	}
	else
	{
		this->sign = true ;
		return addition(abs(a),abs(b)) ;
	}
}
string BigNumbers :: subManager(string a,string b)
{
	int signA = 0, signB = 0 ;
	if(a[0] == '-')
		signA = -1 ;
	if(b[0] == '-')
		signB = -1 ;
	if(signA == -1 && signB == -1)
	{
		int res = compare(abs(a),abs(b)) ;
		if(res > 0)
		{	
			this->sign = false ;
			return subtraction(abs(a),abs(b)) ;
		}
		else
		{	
			this->sign = true ;
			return subtraction(abs(b),abs(a)) ;
		}
	}	
	else if(signA == -1 && signB == 0) 
	{
		this->sign = false ;
		return addition(abs(a),abs(b)) ;
	}
	else if(signA == 0 && signB == -1) 
	{
		this->sign = true ;
		return addition(abs(a),abs(b)) ;
	}
	else
	{
		int res = compare(abs(a),abs(b)) ;
		if(res >= 0)
		{	
			this->sign = true ;
			return subtraction(abs(a),abs(b)) ;
		}
		else
		{	
			this->sign = false ;
			return subtraction(abs(b),abs(a)) ;
		}
	}
}
bool BigNumbers :: mulManager(string a,string b)
{
	int signA = 0, signB = 0 ;
	if(a[0] == '-')
		signA = -1 ;
	if(b[0] == '-')
		signB = -1 ;
	if(signA == -1 ^ signB == -1)
		return false ;
	return true ;
}
bool BigNumbers :: numberValidator(string a)
{
	int pointCount = 0 ;
	for(int i = 0 ; i < a.length() ; i++)
		if(a[i] == '.')
			++pointCount ;
		else if(!isdigit(a[i]) && ((a[i] != '+' || a[i] != '-') && i != 0))
			return false ;
	if(pointCount > 1)
		return false ;
	if((a[0] == '-' || a[0] == '+') && (a[1] == '-' || a[1] == '+'))
		return false ;
	return true ;
}
int BigNumbers :: countZeros(string a)
{
	int count = 0 ;
	int loc = getPointLoc(a) ;
	if(loc < 0)
		loc = a.length() ;
	for(int i = loc-1 ; i >= 0 ; i--)
	{
		if(a[i] != '0')
			break ;
		++count ;
	}
	return count ;
}
bool BigNumbers :: divisibleBy10(string a)
{
	string newA = trimZeros(a) ;
	int loc = getPointLoc(newA) ;
	if(loc >= 0)
	{
		string pointSide = newA.substr(loc+1,newA.length()-loc-1) ;
		if(!checkForZero(pointSide))
			return false ;
	}
	string otherSide = newA.substr(0,loc) ;
	if(otherSide[otherSide.length()-1] == '0')
		return true ;
	return false ;
}
string BigNumbers :: trimZeros(string a)
{
	if(checkForZero(a))
		return "0" ;
	int n = a.length() ;
	int i = 0 ;
	while(a[i] != '.' && i < n)
	{
		if(a[i] != '0')
			break ;
		++i ;
	}
	string newStr = a.substr(i,a.length()-i) ;
	int j = getPointLoc(newStr) ;
	i = newStr.length() - 1 ;
	if(j >= 0)
		while(newStr[i] == '0' && i > j)
			--i ;
	newStr = newStr.substr(0,i+1) ;
	if(newStr[0] == '.')
		newStr = "0" + newStr ;
	if(newStr[newStr.length()-1] == '.')
		newStr = newStr.substr(0,newStr.length()-1) ;
	return newStr ;
}
string BigNumbers :: removePoint(string a)
{
	string newStr ;
	for(char ch : a)
		if(ch != '.')
			newStr += ch ;
	return newStr ;
}
string BigNumbers :: resultOptimiser(string a)
{
	string newA = trimZeros(a) ;
	if(checkForZero(newA))
		return "0" ;
	if(checkForOne(newA))
		newA = "1" ;
	if(!this->sign && newA[0] != '-' && newA[0] != '+')
		return ("-" + newA) ;
	return newA ;
}
bool BigNumbers :: checkForZero(string a)
{
	for(char ch : a)
		if(ch == '0' || ch == '.')
			continue ;
		else 
			return false ;
	return true ;
}
bool BigNumbers :: checkForOne(string a)
{
	int pointLoc = getPointLoc(a) ;
	string pointSide = a, otherSide = a ;
	if(pointLoc >= 0)
	{
		pointSide = a.substr(pointLoc+1,a.length()-pointLoc-1) ;
		otherSide = a.substr(0,pointLoc) ;
	}
	else
	{
		stringstream os(otherSide) ;
		int o ;
		os >>o ;
		if(o == 1)
			return true ;
		return false ;
	}
	stringstream os1(pointSide) ;
	stringstream os2(otherSide) ;
	int p, o ;
	os1 >>p ;
	os2 >>o ;
	if(p == 0 && o == 1)
		return true ;
	return false ;
}
bool BigNumbers :: pointPresent(string a)
{
	for(char ch : a)
		if(ch == '.')
			return true ;
	return false ;
}
int BigNumbers :: getPointLoc(string a)
{
	for(int i = 0 ; i < a.length() ; i++)
		if(a[i] == '.')
			return i ;
	return -1 ; 
}
string BigNumbers :: multiplyBy10Power(string a,int p)
{
	string newStr = a ;
	int pl = getPointLoc(newStr) ;
	if(pl >= 0)
	{
		newStr = removePoint(newStr) ;
		string tmp = newStr ;
		int loc = pl + p ;
		if(loc < tmp.length())
		{
			newStr = tmp.substr(0,loc) + "." + tmp.substr(loc,tmp.length()-loc) ;
		}
		else 
		{
			loc -= tmp.length() ;
			for(int i = 0 ; i < loc ; i++)
				tmp += "0" ;
			newStr = tmp ;
		}
	}
	else
		for(int i = 0 ; i < p ; i++)
			newStr += "0" ;
	return newStr ;
}
string BigNumbers :: divideBy10Power(string a,int p)
{
	int pointLoc = getPointLoc(a) ;
	string newA = a ;
	int newPointLoc ;
	if(pointLoc < 0)
		pointLoc = newA.length() ;
	else
		newA = removePoint(a) ;
	newPointLoc = pointLoc - p ;
	if(newPointLoc > 0)
	{
		string tmp ;
		for(int i = 0 ; i < newPointLoc ; i++)
			tmp += newA[i] ;
		tmp += '.' ;
		for(int i = newPointLoc ; i < newA.length() ; i++)
			tmp += newA[i] ;
		return tmp ;
	}
	for(int i = newPointLoc ; i < 0 ; i++)
		newA = "0" + newA ;
	return ("." + newA) ;
}
string BigNumbers :: abs(string a)
{
	if(a[0] == '-' || a[0] == '+')
		return(a.substr(1,a.length()-1)) ;
	return a ;
}
string BigNumbers :: normalAddition(string a,string b,int carry) 
{
	if(checkForZero(a))
		return b ;
	if(checkForZero(b))
		return a ;
	if(sizeCheck(a,b) == 1)
		b = equalResize(a,b,1) ;
	else if(sizeCheck(a,b) == -1)
		a = equalResize(a,b,-1) ;
	return add(a,b,carry) ;
}
string BigNumbers :: pointAddition(string a,string b)
{
	if(checkForZero(a))
		return b ;
	if(checkForZero(b))
		return a ;
	int pA = getPointLoc(a) ;
	int pB = getPointLoc(b) ;
	int nA = a.length() ;
	int nB = b.length() ;
	string nAs, pAs, nBs, pBs ;
	if(pA >= 0)
	{
		nAs = a.substr(0,pA) ;
		pAs = a.substr(pA+1,nA-pA-1) ;
	}
	else
		nAs = a ;
	if(pB >= 0)
	{	
		nBs = b.substr(0,pB) ;
		pBs = b.substr(pB+1,nB-pB-1) ;
	}
	else
		nBs = b ;
	int NpAs = pAs.length() ;
	int NpBs = pBs.length() ;
	if(NpAs > NpBs)
		pBs = multiplyBy10Power(pBs,NpAs-NpBs) ;
	else
		pAs = multiplyBy10Power(pAs,NpBs-NpAs) ;
	NpAs = pAs.length() ;
	NpBs = pBs.length() ;
	string pointSide ;
	if(NpAs > 0 || NpBs > 0)
		pointSide = add(pAs,pBs,0) ;
	string otherSide ;
	if(NpAs < pointSide.length())
	{
		int p ;
		string tmp(1,pointSide[0]) ;
		stringstream os(tmp) ;
		os >>p ;
		pointSide = pointSide.substr(1,pointSide.length()-1) ;
		otherSide = normalAddition(nAs,nBs,p) ;
	}
	else
		otherSide = normalAddition(nAs,nBs) ;
	return (otherSide + "." + pointSide) ;
}
string BigNumbers :: normalMultiplication(string a,string b)
{
	string newA = a, newB = b ;
	if(checkForZero(newA))
		return newA ;
	else if(checkForZero(newB))
		return newB ;
	else if(checkForOne(newA))
		return newB ;
	else if(checkForOne(newB))
		return newA ;
	else if(divisibleBy10(a))
	{	
		int z = countZeros(a) ;
		newA = trimZeros(divideBy10Power(a,z)) ;
		newB = multiplyBy10Power(b,z) ;
	}
	else if(divisibleBy10(b))
	{	
		int z = countZeros(b) ;
		newA = trimZeros(divideBy10Power(b,z)) ;
		newB = multiplyBy10Power(a,z) ;
	}
	if(newA.length() >= newB.length())
		return multiply(newA,newB) ;
	return multiply(newB,newA) ;
}
string BigNumbers :: pointMultiplication(string a,string b)
{
	if(checkForZero(a))
		return a ;
	if(checkForZero(b))
		return b ;
	if(checkForOne(a))
		return b ;
	if(checkForOne(b))
		return a ;
	if(divisibleBy10(a))
	{	
		int z = countZeros(a) ;
		string newA = divideBy10Power(a,z) ;
		string newB = multiplyBy10Power(b,z) ;
		if(newA.length() >= newB.length())
			return multiply(newA,newB) ;
	 	return multiply(newB,newA) ;
	}
	if(divisibleBy10(b))
	{	
		int z = countZeros(b) ;
		string newA = divideBy10Power(b,z) ;
		string newB = multiplyBy10Power(a,z) ;
		if(newA.length() >= newB.length())
			return multiply(newA,newB) ;
	 	return multiply(newB,newA) ;
	}
	int pointIndexOfA = getPointLoc(a) ;
	int pointIndexOfB = getPointLoc(b) ;
	int p ;
	if(pointIndexOfA < 0)
		p = b.length() - pointIndexOfB - 1 ;
	else if(pointIndexOfB < 0)
		p = a.length() - pointIndexOfA - 1 ;
	else
		p = (a.length() + b.length()) - (pointIndexOfA + pointIndexOfB) - 2 ;
	string newA = removePoint(a) ;
	string newB = removePoint(b) ;
	newA = trimZeros(newA) ;
	newB = trimZeros(newB) ;
	string result ;
	if(newA.length() >= newB.length())
		result = multiply(newA,newB) ;
	result = multiply(newB,newA) ;
	result = divideBy10Power(result,p) ;
	return result ;
}
string BigNumbers :: pointSubtraction(string a,string b)
{
	if(checkForZero(a))
	{	
		this->sign = false;
		return b ;
	}
	if(checkForZero(b))
		return a ;
	if(compare(a,b) == 0)
		return "0" ;
	int pA = getPointLoc(a) ;
	int pB = getPointLoc(b) ;
	int nA = a.length() ;
	int nB = b.length() ;
	string nAs, pAs, nBs, pBs ;
	if(pA >= 0)
	{
		nAs = a.substr(0,pA) ;
		pAs = a.substr(pA+1,nA-pA-1) ;
	}
	else
		nAs = a ;
	if(pB >= 0)
	{	
		nBs = b.substr(0,pB) ;
		pBs = b.substr(pB+1,nB-pB-1) ;
	}
	else
		nBs = b ;
	string otherSide ;
	bool otherSign = true ;
	if(compare(nAs,nBs) < 0)
	{	
		otherSide = normalSubtraction(nBs,nAs) ;
		otherSign = false ;
	}
	else
		otherSide = normalSubtraction(nAs,nBs) ;
	int NpAs = pAs.length() ;
	int NpBs = pBs.length() ;
	if(NpAs > NpBs)
		pBs = multiplyBy10Power(pBs,NpAs-NpBs) ;
	else
		pAs = multiplyBy10Power(pAs,NpBs-NpAs) ;
	NpAs = pAs.length() ;
	NpBs = pBs.length() ;
	string pointSide ;
	bool pointSign = true ;
	if(NpAs > 0 || NpBs > 0)
		if(compare(pAs,pBs) == -1)
		{	
			pointSide = normalSubtraction(pBs,pAs) ;
			pointSign = false ;
		}
		else
			pointSide = normalSubtraction(pAs,pBs) ;
	if((otherSign ^ pointSign) && compare(otherSide,"0") != 0)
	{
		pointSide = normalSubtraction(multiplyBy10Power("1",NpAs),pointSide) ;
		otherSide = normalSubtraction(otherSide,"1") ;
	}
	pointSide = divideBy10Power(pointSide,NpAs) ;
	return pointAddition(otherSide,pointSide) ;
}
string BigNumbers :: normalDivision(string a,string b)
{
	if(checkForZero(a) && checkForZero(b))
		return "Not Defined" ;
	if(checkForZero(b))
		return "Not Defined" ;
	if(checkForZero(a))
		return "0" ;
	if(checkForOne(b))
		return a ;
	return divide(a,b) ;
}
string BigNumbers :: pointDivision(string a,string b)
{
	if(checkForZero(a) && checkForZero(b))
		return "Not Defined" ;
	if(checkForZero(b))
		return "Not Defined" ;
	if(checkForZero(a))
		return "0" ;
	if(checkForOne(b))
		return a ;
	int nza = getPointLoc(a) ;
	string newA = removePoint(a) ;
	if(nza < 0)
		nza = 0 ;
	else
		nza = newA.length() - nza ;
	int nzb = getPointLoc(b) ;
	string newB = removePoint(b) ;
	if(nzb < 0)
		nzb = 0 ;
	else
		nzb = newB.length() - nzb ;
	int z = nza - nzb ;
	this->limit -= z ;
	if(z > 0)
		return divideBy10Power(trimZeros(divide(newA,newB)),z) ;
	return multiplyBy10Power(trimZeros(divide(newA,newB)),-z) ;
}
string BigNumbers :: equalResize(string a,string b,int flag)
{
	int d = labs(a.length() - b.length()) ;
	string newStr = "" ;
	for(int i = 1 ; i <= d ; i++)
			newStr.resize(newStr.length()+1,'0') ;
	if(flag == 1)
		return newStr + b ;
	else
		return newStr + a ;
}
int BigNumbers :: sizeCheck(string a,string b)
{
	if(a.length() == b.length())
		return 0 ;
	else if(a.length() > b.length())
		return 1 ;
	else
		return -1;
}
string BigNumbers :: add(string a,string b,int carry)
{
	int n = a.length() ;
	short int A[n] = {0} ;
	short int B[n] = {0} ;
	short int C[n+1] = {0} ;
	for(int i = 0 ; i < n ; i++)
	{
		string t1 = string(1,a[i]) ;
		string t2 = string(1,b[i]) ;
		stringstream toInt1(t1) ;
		stringstream toInt2(t2) ;
		toInt1 >>A[i] ;
		toInt2 >>B[i] ;
	}
	for(int i = n-1 ; i >= 0 ; i--)
	{
		C[i+1] = A[i] + B[i] + carry ;
		carry = 0 ;
		if(C[i+1] > 9)
		{
			carry = C[i+1] / 10 ;
			C[i+1] = C[i+1] % 10 ; 
		}
		if(i == 0)
			C[i] = carry ;
	}
	stringstream toString ;
	n = sizeof(C)/sizeof(C[0]) ;
	int i ;
	for(i = 0 ; i < n ; i++)
		if(C[i] != 0)
			break ;
	for(int j = i ; j < n ; j++)
		toString <<C[j] ;
	string result(toString.str()) ;
	return result ;
}
string BigNumbers :: multiply(string a,string b)
{
	int nA = a.length() ;
	int nB = b.length() ;
	short int A[nA] = {0} ;
	short int B[nB] = {0} ;
	for(int i = 0 ; i < nA ; i++)
	{
		string t1 = string(1,a[i]) ;
		stringstream toInt1(t1) ;
		toInt1 >>A[i] ;
	}
	for(int i = 0 ; i < nB ; i++)
	{
		string t2 = string(1,b[i]) ;
		stringstream toInt2(t2) ;
		toInt2 >>B[i] ;
	}
	int index = 0 ;
	string ip[nB] ;
	for(int i = nB-1 ; i >= 0 ; i--)
	{
		short int D[nA+1] ;
		int k = nA-1 ;
		int carry = 0 ;
		for(int j = nA-1 ; j >= 0 ; j--,k--)
		{
			D[k+1] = (B[i] * A[j]) + carry ;
		    carry = 0 ;
			if(D[k+1] > 9)
			{
				carry = D[k+1] / 10 ;
				D[k+1] = D[k+1] % 10 ; 
			}
			if(j == 0)
				D[k] = carry ;
		}
	    stringstream toString ;
		int n = sizeof(D)/sizeof(D[0]) ;
		int m ;
		for(m = 0 ; m < n ; m++)
			if(D[m] != 0)
				break ;
		for(int l = m ; l < n ; l++)
			toString <<D[l] ;
		string tmp(toString.str()) ;
		tmp = multiplyBy10Power(tmp,index) ;
		ip[index++] = tmp ;
	}
	int i ;
	for(i = 0 ; i < nB-1 ; i++)
	{	
		string c = ip[i] ;
		string d = ip[i+1] ;
		ip[i+1] = normalAddition(c,d) ;
	}
	return ip[i] ;
}
string BigNumbers :: normalSubtraction(string a,string b)
{
	if(checkForZero(a))
		return b ;
	if(checkForZero(b))
		return a ;
	if(compare(a,b) == 0)
		return "0" ;
	string newA = a, newB = b ;
	if(compare(a,b) < 0)
	{
		newA = b ;
		newB = a ;
	}	
	if(sizeCheck(newA,newB) == 1)
		newB = equalResize(newA,newB,1) ;
	else if(sizeCheck(newA,newB) == -1)
		newA = equalResize(newA,newB,-1) ;
	return subtract(newA,newB) ;
}
string BigNumbers :: absolute(string a)
{
	if(numberValidator(a))
		return abs(a) ;
	return "Invalid Input !" ;
}
string BigNumbers :: subtract(string a,string b)
{
	int n = a.length() ;
	short int A[n] = {0} ;
	short int B[n] = {0} ;
	short int C[n] = {0} ;
	for(int i = 0 ; i < n ; i++)
	{
		string t1 = string(1,a[i]) ;
		string t2 = string(1,b[i]) ;
		stringstream toInt1(t1) ;
		stringstream toInt2(t2) ;
		toInt1 >>A[i] ;
		toInt2 >>B[i] ;
	}
	for(int i = n-1 ; i >= 0 ; i--)
	{
		C[i] = A[i] - B[i] ;
		if(C[i] < 0)
		{
			--A[i-1] ;
			C[i] += 10 ;
		}
	}
	stringstream toString ;
	n = sizeof(C)/sizeof(C[0]) ;
	int i ;
	for(i = 0 ; i < n ; i++)
		if(C[i] != 0)
			break ;
	for(int j = i ; j < n ; j++)
		toString <<C[j] ;
	string result(toString.str()) ;
	return result ;
}
string BigNumbers :: divide(string a,string b)
{
	string newA = a ;
	int nz = countZeros(newA) ;
	newA = trimZeros(divideBy10Power(newA,nz)) ;
	int actualLengthOfA = newA.length() ;
	int my = this->limit + nz ;
	string quiotent = "" , remainder = newA, dividend ;
	int counter = 0 ;
	remainder = dividend = newA.substr(counter,b.length()) ;
	counter = b.length() - 1 ;
	while(counter < newA.length() && my >= 0)
	{
		if(compare(dividend,b) >= 0)
		{
			string pn = "1" ;
			string pm = b ;
			for(int i = 1 ; i <= 10 ; i++)
			{
				stringstream toString ;
				toString <<i ;
				string n(toString.str()) ;
				string m = normalMultiplication(b,n) ;
				if(compare(dividend,m) < 0)
				{	
					quiotent += pn ;
					remainder = normalSubtraction(dividend,pm) ;
					break ;
				}
				pn = n ;
				pm = m ;
			}
		}
		counter++ ;
		if(!checkForZero(remainder) && counter >= actualLengthOfA)
		{
			if(getPointLoc(quiotent) < 0)
				quiotent += "." ;
			newA += "0" ;
			bool firstCheck = false ;
			while(compare(remainder,b) < 0)
			{
				if(firstCheck)
					quiotent += "0" ;
				firstCheck = true ;
				newA += "0" ;
				--my ;
				remainder = trimZeros(remainder + "0") ;
			}
			dividend = remainder ;
			continue ;
		}
		if(checkForZero(dividend))
			if(counter >= newA.length())
				break ;
		if(compare(dividend,b) < 0)
		{
			 quiotent += "0" ;
			 remainder = dividend ;
		}
		dividend = trimZeros(remainder + newA[counter])  ;
	}
	return multiplyBy10Power(quiotent,nz) ;
}
int BigNumbers :: compare(string a,string b)
{
	string newA = a, newB = b ;
	if(checkForZero(newA))
		newA = "0" ;
	if(checkForZero(newB))
		newB = "0" ;
	int pALoc = getPointLoc(newA) ;
	int pBLoc = getPointLoc(newB) ;
	if(pALoc >= 0)
		newA = newA.substr(0,pALoc) ;
	if(pBLoc >= 0)
		newB = newB.substr(0,pBLoc) ;
	if(sizeCheck(newA,newB) == 1)
		newB = equalResize(newA,newB,1) ;
	else if(sizeCheck(newA,newB) == -1)
		newA = equalResize(newA,newB,-1) ;
	if(pALoc < 0 && pBLoc < 0)
		return newA.compare(newB) ;
	else if (pALoc < 0 && pBLoc >= 0)
	{
		int res = newA.compare(newB) ;
		if(res == 0)
			return -1 ;
		return 1 ;
	}
	else if(pALoc >= 0 && pBLoc < 0)
	{
		int res = newA.compare(newB) ;
		if(res == 0)
			return 1 ;
		return -1 ;
	}
	else
	{
		int res = newA.compare(newB) ;
		if(res == 0)
		{
			newA = a.substr(pALoc+1,a.length()-pALoc-1) ;
			newB = b.substr(pBLoc+1,b.length()-pBLoc-1) ;
			return newA.compare(newB) ;
		}	
		return res ;
	}
}
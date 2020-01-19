#include "Monomial.h"
#include "Polynomial.h"
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	// Check Mono
	Monomial M1, M2(1), M3(-1), M4(2,3), M5(250,0), M6(-15,86), M7(-2,3), M8(4,18), M9(539,539), M10(0,2), M11(0,200), M12(-199,166), M13(1,4), M14, M15, M16(-4,18), M17(-111,1), M18(15, 1), M19(-399), M20(1,1);
	// M1(0,0), M2(1,0), M3(-1,0), M4(2,3), M5(250,0), M6(-15,86), M7(-2,3), M8(4,18), M9(539,539), M10(0,2), M11(0,200), M12(-199,166), M13(1,4), M14(0,0), M15(0,0), M16(-4,18), M17(-111,1), M18(15,1), M19(-399,0), M20(1,1)
	int coeff1 = M1.getCoeff(), exp1 = M1.getExp(), coeff3 = M3.getCoeff(), exp9 = M9.getExp();
	// coeff1 = 0, exp1 = 0, coeff3 = -1, exp9 = 539;
	
	// Operator += can be used only on sane exp monos!! -> a x^ n * b x^ n = (a*b) x^ n
	M1 += M2; // (1,0)M1
	M1 += M3; // (0,0)M1
	M4 += M4; // (4,3)M4

	// Operator * && *= -> a x^ n * b x^ m = (a*b) x^ (n+m)
	M14 = M3 * M4; // (-1,0)*(4,3) = (-4,3)M14
	M15 = M4 * M7; // (4,3)*(-2,3) = (-8,6)M15
	M15 *= M7; // (-8,6)*(-2,3) = (16,9)M15
	M4 *= M8; // (4,3)*(4,18) = (16,21)M4

	// Operator == returns bool
	M4 == M4; // True
	M2 == M3; // False
	M16 == M8; // False

	// Operator - (negate) (a,b) -> (-a,b)
	M1.negate(); // (0,0) -> (0,0)M1
	M10.negate(); // (0,2) -> (0,2)M10
	M12.negate(); // (-199,166) -> (199,166)M12

	// Operand << prints representation:
	/*
		-/+ num					coeff = -/+ num, exp = 0
		-/+ numx				coeff = -/+ num, exp = 1
		-/+ numx^num			coeff = -/+ num, exp = num
		-/+ x					coeff = -/+ 1, exp = 1 ??????
		-/+ x^num				coeff = -/+ 1, exp = num
	*/
	std::cout << M2 << endl;	// 1
	std::cout << M3 << endl;	// -1
	std::cout << M5 << endl;	// 250
	std::cout << M19 << endl;	// -399

	std::cout << M18 << endl;	// 15x
	std::cout << M17 << endl;	// -111x

	std::cout << M9 << endl;	// 539x^539
	std::cout << M16 << endl;	// -4x^18

	std::cout << M20 << endl;	// x
	std::cout << M20.negate() << endl;	// -x

	std::cout << M13 << endl;	// x^4
	std::cout << M13.negate() << endl;	// -x^4


	// Check Poly
	Polynomial P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, P20;

	// Check x, -x + big and small x (x,X - did not define specific input)
	P1 >> "x"; // (1,1)
	P2 >> "-x"; // (-1,1)
	P3 >> "X";  // (1,1)
	P4 >> "-X"; // (-1,1)

	// Check num, -num diff sizes

	P5 >> "2"; // (2,0)
	P6 >> "193"; // (193,0)
	P7 >> "-6"; // (-6,0)
	P8 >> "-250"; // (-250,0)

	// Check numx, -numx diff sizes

	P9 >> "16x"; // (16,1)
	P10 >> "-330X"; // (-330,1)

	// Check +-numx^num

	P11 >> "22x^3"; // (22,3)
	P12 >> "-8x^24"; // (-8,24)

	// Check +- x^num

	P13 >> "x^84"; // (1,84)
	P14 >> "-x^2"; // (-1,2)

	// bigger poly, beginning + & -, after + and -

	P15 >> "12x^3+8x^2-16"; // (12,3)(8,2)(-16,0)
	P16 >> "-3x^61-4x^2+48x"; //(-3,61)(-4,2)(48,1)
	
	P17 >> "5x^2"; // (5,2)
	// Copy and assignment constructor
	Polynomial PP = P16; // pp = (-3,61)(-4,2)(48,1), size 3, see different addresses!!
	P5 = P16; //P5 = (-3,61)(-4,2)(48,1) size = 3, see different addresses!!
	P15 = P11; // p15 = (22,3) size = 1, see different addresses!!

	// Check Operator += Poly and Poly (Assuming Poly+=mono was used in implementatoin!!!)
	P16 += P14; // p16 = (-3,61)(-5,2)(48,1)
	P17 += P16; // p17 = (-3,61)(48,1)

	// Check Operator -= Poly and Poly (Assuming Poly-=mono was used in implementatoin!!!)
	
	P13 -= P14; //(1,84)(1,2)
	P1 -= P3; // p1 = NULL , size = 0

	// Check Operator *= Poly and Poly (Assuming Poly*=mono was used in implementatoin!!!)
	
	P20 >> "4"; // (4,0)

	P20 *= P20; // (16,0), size 1

	Polynomial P23, P24, P25, P26, P27;
	P23 >> "4x";
	P20 *= P23;//(64,1) size 1
	P24 >> "5x^8"; 
	P24 *= P20;// (320,9) size 1
	P25 >> "-x^2+x+2"; //(-1,2),(1,1),(2,0)
	P26 >> "-x+2";


	P25 *= P26; //(1,3)(-3,2)(4,0) size = 3
	
	// -------------------------------New-Tests--------------------------------//

	// More tests with Poly and Poly/Mono, (+,-,*)= and =(+,-,*)- global function 
	Monomial M104(2, 1), M106(5,2), m(5); // "2x", "5x^2", "5"
	Polynomial P100, P101, P102, P103, P104, P105, P106, P107, P108, P109, P110, P111, P112, P113, P114, P115;
	P100 >> ""; // NULL, size 0
	P101 >> "x^2+2x+5"; // (1,2)(2,1)(5,0), size 3
	P102 >> "2"; // (2,0), size 1
	P103 >> "2x^3+x-2"; // (2,3)(1,1)(-2,0), size 3
	P104 >> "2X"; // (2,1), size 1
	P105 >> "X+4"; // (1,1)(4,0), size 2
	P106 >> "5x^2"; // (5,2), size 1
	P107 >> "5x^2-15000000"; // (5,2)(-15000000,0), size 2
	P108 >> "3x^3+2x^2+x+1"; // (3,3)(2,2)(1,1)(1,0), size 4
	P109 >> "5x^4+3x^2+300"; // (5,4)(3,2)(300,0), size 3
	P111 >> "-2x^2+1"; // (-2,2)(1,0), size 2

	// Use P110 for all global options (not to ruin original value)
	/*
		Notice: you should have 15 options:
		Poly +/-/* Poly
		Poly +/-/* Mono
		Poly +/-/* int		// int -> Mono(x,0)
		Mono +/-/* Poly
		int  +/-/* Poly		// int -> Mono(x,0)
	*/
	// return null, same size as original, check "if this->_size<1")
	P110 = P101 - P101; // P110 = NULL, size 0
	// return bigger size as original, check "if this->_size<1")
	P110 = P101 * P102; // P110 = (2,2)(-4,1)(10,0), size 3
	// return bigger size then original poly, "normal" route
	P110 = P103 * P111; // P110 = (-4,5)(4,2)(1,1)(-2,0), size 4
	
	// All simple options for +

	P110 = P104 + P105; // P110 = (3,1)(4,0), size 2, Poly+ Poly
	P110 = M104 + P105; // P110 = (3,1)(4,0), size 2, Mono + Poly
	P110 = P105 + M104; // P110 = (3,1)(4,0), size 2, Poly + Mono

	P110 = m + P105; // P110 = (1,1)(9,0), size 2, Mono + Poly
	//P110 = 5 + P105; // P110 = (1,1)(9,0), size 2, int + Poly
	//P110 = P105 + m; // P110 = (1,1)(9,0), size 2, Poly + Mono
	//P110 = P105 + 5; // P110 = (1,1)(9,0), size 2, Poly + int

	// All simple options for -

	P110 = P106 - P107; // P110 = (15000000), size 1, Poly+ Poly
	P110 = M106 - P107; // P110 = (15000000), size 1, Mono + Poly
	P110 = P107 - M106; // P110 = (15000000), size 1, Poly + Mono

	P110 = m - P105; // P110 = (1,1)(-1,0), size 2, Mono + Poly
	///P110 = 5 - P105; // P110 = (1,1)(-1,0), size 2, int + Poly
	P110 = P105 - m; // P110 = (1,1)(-1,0), size 2, Poly + Mono
	//P110 = P105 - 5; // P110 = (1,1)(-1,0), size 2, Poly + int
	
	// All simple options for *

	P110 = m * P105; // P110 = (5,1)(20,0), size 2, Mono + Poly
	//P110 = 5 * P105; // P110 = (5,1)(20,0), size 2, int + Poly
	P110 = P105 * m; // P110 = (5,1)(20,0), size 2, Poly + Mono
	//P110 = P105 * 5; // P110 = (5,1)(20,0), size 2, Poly + int

	P110 = P108 * P109; // P110 = (15,7)(10,6)(14,5)(11,4)(903,3)(602,2)(300,1)(300,0), size 8

	P112 = P101;
	P113 = P114 = P115 = P112; // See in all same data : (1,2)(2,1)(5,0), size 3, but diffrent addreses! 

	// Same tests with operands, run over original poly
	// return null, same size as original, check "if this->_size<1")
	P101 -= P101; // P101 = NULL, size 0
	// return bigger size as original, check "if this->_size<1")
	P112 *= P102; // P112 = (2,2)(-4,1)(10,0), size 3
	// return bigger size then original poly, "normal" route
	P103 *= P111; // P103 = (-4,5)(4,2)(1,1)(-2,0), size 4
	
	// Same result poly and poly/mono

	P104 += P105; // P104 = (3,1)(4,0), size 2
	P105 += M104; // P105 = (3,1)(4,0), size 2
	
	P106 -= P107; // P106 = (15000000), size 1
	P107 -= M106.negate(); // P107 = (15000000), size 1
	
	P108 *= P109; // P108 = (15,7)(10,6)(14,5)(11,4)(903,3)(602,2)(300,1)(300,0), size 8

	// Check print and return values

	// Print "15x^7+10x^6+14x^5+11x^4+903x^3+602x^2+300x+300, all + sign
	std::cout << P108 << endl;
	std::cout << P108.getStringRepresentation() << endl;
	
	// Print "-4x^5+4x^2+x-2", start with - sign and - sign in the middle
	std::cout << P103 << endl;
	std::cout << P103.getStringRepresentation() << endl;
	
	// --------------Not-sure-if-legal-tests--------------//
	
	// x-x = 0, 0*y = 0 (NULL*y)
	P110 = P110 - P110; // P110 = NULL, size 0
	P110 = P110 * P103; // P110 = NULL, size 0
	P110 *= P103; // P110 = NULL, size 0

	// More than one action at the same command ( from the same action)
	// No math priority was defined so did not mix diff signs
	// Assuming more complicated scenarios tested earlier on each action

	Polynomial P200, P201, P202, P203, P204, P205, P206;
	P200 >> "2x^2"; // (2,2), size 1
	P201 >> "15x"; // (15,1), size 1
	P202 >> "-599"; // (-599,0), size 1
	P203 = P200 + P201 + P202; // P203 = (2,2)(15,1)(-599,0), size 3, "2x^2+15x-599", P200-P202 should not change!!
	P203 = P200 - P201 - P202; // P203 = (2,2)(-15,1)(599,0), size 3, "2x^2-15x+599", P200-P202 should not change!!
	P205 >> "1"; // (1,0), size 1
	P206 = P200 * P201 * P202 * P205; // "2x^2 * 15x * (-599) * 1" => (2*15*(-599)*1) x^ (2+1+0+0) => (-17970, 3), size 1, P200-P205 should not change!!

		
	return 0;
}

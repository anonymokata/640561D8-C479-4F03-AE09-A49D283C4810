#include <string.h>
#include <math.h>

typedef enum { false, true } bool;

#define ROW 4
#define COL 10
char *romanSymbols[ROW][COL] = {
	{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
	{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
	{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
	{ "", "M", "MM", "MMM", "*", "*", "*", "*", "*", "*"}
};
int romanSymbolLength[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
int symbolSearchOrder[] = {0, 9, 8, 7, 6, 4, 5, 3, 2, 1};

int romanToArabic(char *roman) {
	char *foundRomanPointer;
	char *shiftingRomanPointer;
	int arabic = 0;
	int i;
	bool symbolWasFound;

	shiftingRomanPointer = roman;

	for(int place = 3; place >= 0; --place) {
		symbolWasFound = false;
		for(i=1; i<=9 && !symbolWasFound; ++i) {
			foundRomanPointer = strstr(shiftingRomanPointer, romanSymbols[place][symbolSearchOrder[i]]);
			if(foundRomanPointer != NULL) {
				symbolWasFound = true;
				if(shiftingRomanPointer == foundRomanPointer) {
					arabic += symbolSearchOrder[i]*pow(10,place);
					shiftingRomanPointer = foundRomanPointer + romanSymbolLength[symbolSearchOrder[i]];
				}
			}
		}
	}

	return arabic;
}

size_t arabicToRoman(int arabic, char *roman, size_t romanBufferLength) {
	size_t romanLength = 0;
	int thousandsDigit = arabic/1000;
	int hundredsDigit = (arabic - thousandsDigit*1000)/100;
	int tensDigit = (arabic - hundredsDigit*100 - thousandsDigit*1000)/10;
	int onesDigit = arabic - tensDigit*10 - hundredsDigit*100 - thousandsDigit*1000;

	int digits[4] = {onesDigit, tensDigit, hundredsDigit, thousandsDigit};

	for(int place = 3; place >= 0; --place) {
		if((romanSymbolLength[digits[place]] + romanLength) <= romanBufferLength){
			strcat(roman, romanSymbols[place][digits[place]]);
			romanLength += romanSymbolLength[digits[place]];
		}
	}

	return romanLength;
}

size_t addRomanNumerals(char *summand1Roman, char *summand2Roman, char *sumRoman, size_t sumRomanBufferLength) {
	int summand1Arabic = romanToArabic(summand1Roman);
	int summand2Arabic = romanToArabic(summand2Roman);
	int sumArabic = summand1Arabic + summand2Arabic;

	size_t usedSumBufferLength = arabicToRoman(sumArabic, sumRoman, sumRomanBufferLength);

	return usedSumBufferLength;
}

size_t subtractRomanNumerals(char *minuendRoman, char *subtrahendRoman, char *differenceRoman, size_t differenceRomanBufferLength) {
	int minuendArabic = romanToArabic(minuendRoman);
	int subtrahendArabic = romanToArabic(subtrahendRoman);
	int differenceArabic = minuendArabic - subtrahendArabic;

	size_t usedBufferLength = arabicToRoman(differenceArabic, differenceRoman, differenceRomanBufferLength);

	return usedBufferLength;
}

#include <string.h>

typedef enum { false, true } bool;

char *onesRomanSymbols[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char *tensRomanSymbols[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char *hundredsRomanSymbols[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char *thousandsRomanSymbols[] = { "", "M", "MM", "MMM", "*", "*", "*", "*", "*", "*"};
int romanSymbolLength[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
int symbolSearchOrder[] = {0, 9, 8, 7, 6, 4, 5, 3, 2, 1};

int romanToArabic(char *roman) {
	char *foundRomanPointer;
	char *shiftingRomanPointer;
	int arabic = 0;
	int i;
	bool symbolWasFound;

	shiftingRomanPointer = roman;

	symbolWasFound = false;
	for(i=1; i<=9 && !symbolWasFound; ++i) {
		foundRomanPointer = strstr(shiftingRomanPointer, thousandsRomanSymbols[symbolSearchOrder[i]]);
		if(foundRomanPointer != NULL) {
			symbolWasFound = true;
			if(shiftingRomanPointer == foundRomanPointer) {
				arabic += symbolSearchOrder[i]*1000;
				shiftingRomanPointer = foundRomanPointer + romanSymbolLength[symbolSearchOrder[i]];
			}
		}
	}

	symbolWasFound = false;
	for(i=1; i<=9 && !symbolWasFound; ++i) {
		foundRomanPointer = strstr(shiftingRomanPointer, hundredsRomanSymbols[symbolSearchOrder[i]]);
		if(foundRomanPointer != NULL) {
			symbolWasFound = true;
			if(shiftingRomanPointer == foundRomanPointer) {
				arabic += symbolSearchOrder[i]*100;
				shiftingRomanPointer = foundRomanPointer + romanSymbolLength[symbolSearchOrder[i]];
			}
		}
	}

	symbolWasFound = false;
	for(i=1; i<=9 && !symbolWasFound; ++i) {
		foundRomanPointer = strstr(shiftingRomanPointer, tensRomanSymbols[symbolSearchOrder[i]]);
		if(foundRomanPointer != NULL) {
			symbolWasFound = true;
			if(shiftingRomanPointer == foundRomanPointer) {
				arabic += symbolSearchOrder[i]*10;
				shiftingRomanPointer = foundRomanPointer + romanSymbolLength[symbolSearchOrder[i]];
			}
		}
	}

	symbolWasFound = false;
	for(i=1; i<=9 && !symbolWasFound; ++i) {
		foundRomanPointer = strstr(shiftingRomanPointer, onesRomanSymbols[symbolSearchOrder[i]]);
		if(foundRomanPointer != NULL) {
			symbolWasFound = true;
			arabic += symbolSearchOrder[i];
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

	if((romanSymbolLength[thousandsDigit] + romanLength) <= romanBufferLength){
		strncpy(roman, thousandsRomanSymbols[thousandsDigit], romanBufferLength);
		romanLength += romanSymbolLength[thousandsDigit];
	}
	if((romanSymbolLength[hundredsDigit] + romanLength) <= romanBufferLength){
		strcat(roman, hundredsRomanSymbols[hundredsDigit]);
		romanLength += romanSymbolLength[hundredsDigit];
	}
	if((romanSymbolLength[tensDigit] + romanLength) <= romanBufferLength){
		strcat(roman, tensRomanSymbols[tensDigit]);
		romanLength += romanSymbolLength[tensDigit];
	}
	if((romanSymbolLength[onesDigit] + romanLength) <= romanBufferLength){
		strcat(roman, onesRomanSymbols[onesDigit]);
		romanLength += romanSymbolLength[onesDigit];
	}

	return romanLength;
}

size_t addRomanNumerals(char *term1Roman, char *term2Roman, char *sumRoman, size_t sumRomanBufferLength) {
	int term1Arabic = romanToArabic(term1Roman);
	int term2Arabic = romanToArabic(term2Roman);
	int sumArabic = term1Arabic + term2Arabic;

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

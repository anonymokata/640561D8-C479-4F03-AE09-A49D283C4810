#include <string.h>

typedef enum { false, true } bool;

char *onesRomanSymbols[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char *tensRomanSymbols[] = { "", "X"};
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
	for(i=1; i<=1 && !symbolWasFound; ++i) {
		foundRomanPointer = strstr(shiftingRomanPointer, tensRomanSymbols[i]);
		if(foundRomanPointer != NULL) {
			symbolWasFound = true;
			if(shiftingRomanPointer == foundRomanPointer) {
				arabic += i*10;
				shiftingRomanPointer = foundRomanPointer + 1;
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

size_t arabicToRoman(int arabic, char *arabicBuffer, size_t arabicBufferLength) {
	size_t romanLength = 0;
	int tensDigit = arabic/10;
	int onesDigit = arabic - tensDigit*10;

	if((romanSymbolLength[tensDigit] + romanLength) <= arabicBufferLength){
		strncpy(arabicBuffer, tensRomanSymbols[tensDigit], arabicBufferLength);
		romanLength += romanSymbolLength[tensDigit];
	}
	if((romanSymbolLength[onesDigit] + romanLength) <= arabicBufferLength){
		strcat(arabicBuffer, onesRomanSymbols[onesDigit]);
		romanLength += romanSymbolLength[onesDigit];
	}

	return romanLength;
}

size_t addRomanNumerals(char *term1Roman, char *term2Roman, char *sumBuffer, size_t sumBufferLength) {
	int term1Arabic = romanToArabic(term1Roman);
	int term2Arabic = romanToArabic(term2Roman);
	int sumArabic = term1Arabic + term2Arabic;

	size_t usedSumBufferLength = arabicToRoman(sumArabic, sumBuffer, sumBufferLength);

	return usedSumBufferLength;
}

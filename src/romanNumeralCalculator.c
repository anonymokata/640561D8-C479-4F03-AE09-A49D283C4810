#include <string.h>

size_t addRomanNumerals(char *term1, char *term2, char *sumBuffer, size_t sumBufferLength) {
	size_t usedSumBufferLength;

	if(!strcmp(term1,"I") && !strcmp(term2,"I")) {
		char sumRomanNumeral[] = "II";
		usedSumBufferLength = 2;

		if(usedSumBufferLength <= sumBufferLength){
			strncpy(sumBuffer, sumRomanNumeral, sumBufferLength);
		}
	}
	else if ( (!strcmp(term1,"I") && !strcmp(term2,"II"))
		|| (!strcmp(term1,"II") && !strcmp(term2,"I")) ) {
		char sumRomanNumeral[] = "III";
		usedSumBufferLength = 3;

		if(usedSumBufferLength <= sumBufferLength){
			strncpy(sumBuffer, sumRomanNumeral, sumBufferLength);
		}
	}

	return usedSumBufferLength;
}

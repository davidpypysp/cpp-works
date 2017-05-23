/*
	Write code to reverse a C-Style String
	(C-String means that “abcd” is represented as five characters, including the null character )
*/



/*
    we do it in-place, reverse from the start with the end character.
	time: o(n) space: o(1);

*/

void ReverseString(char *str) {
	char *end = str;
	while (*end != '\0') end++;
	end--;
	while (str < end) {
		char temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}

}

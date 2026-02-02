#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/**
 * Determine if the string s starts with the string prefix.
 * @param s - the string to see if it starts with prefix
 * @param prefix - the prefix to test
 * @returns true if the strings begins with the prefix.
 */
int startsWith(const char s[], const char prefix[]) // BUG #1 - No check for NULL parameters
{
	char buf[20]; // BUG #2 - A prefix longer than 20 will overflow this buffer
	int i;

	int sz = strlen(prefix);
	for (i = 0; i < sz; i++) // BUG #4 - if the prefix is longer than s, this will overflow s
	{
		buf[i] = s[i];
	}
	buf[sz] = '\0';

	return 0 == strcmp(buf, prefix);
}
/**
 * Determine if the string s ends with the string suffix.
 * @param s - the string to see if it ends with suffix
 * @param suffix - the suffix to test
 * @returns true if the strings ends with the suffix.
 */
int endsWith(const char s[], const char suffix[]) // BUG #1 - No check for NULL parameters
{
	int sz = strlen(suffix);
	int slen = strlen(s);

	return 0 == strcmp(s + slen - sz, suffix); // BUG #4 - if suffix is longer than s buffer underflow
}

int main(void)
{
	char s1[] = {"Hi"};
	char prefix[] = {"Hello"};
	char suffix[] = {"Hi"};

	printf("%s does %s start with %s\n",
				 s1, startsWith(s1, prefix) ? "" : " not", prefix);

	printf("%s does %s end with %s\n",
				 s1, endsWith(s1, suffix) ? "" : " not", suffix);

	printf("%s does %s end with %s\n",
				 s1, endsWith(s1, "upended") ? "" : " not", "upended");

	printf("%s does %s start with %s\n",
				 s1, startsWith(s1, prefix) ? "" : " not", "upendedup");

	printf("%s does %s start with %s\n",
				 s1, startsWith(s1, prefix) ? "" : " not", "upendedup_buffer_overflow");

	return 0;
}

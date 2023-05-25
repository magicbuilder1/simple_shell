#include "shell_main.h"

/**
 * _itoa - converts an integer into a null-terminated string
 *
 * @num: the number to be converted to a string
 * @buffer: Space in memory where to store the resulting
 * null-terminated string
 *
 * Return: pointer to the resulting null-terminated string
 */
char *_itoa(int num, char *buffer)
{
	int digit, temp = num;
	size_t count = 0;

	if (num == 0)
	{
		buffer[count++] = '0';
		buffer[count] = '\0';
		return (buffer);
	}

	while (temp != 0)
	{
		digit = temp % 10;

		if (digit < 0)
			digit *= -1;

		buffer[count++] = digit + '0';

		temp /= 10;
	}

	if (num < 0)
		buffer[count++] = '-';

	buffer[count] = '\0';

	_rev_string(buffer);

	return (buffer);
}

/**
 * _get_digit_count - counts the number of digits of
 * a numeric value
 *
 * @num: the number to be measured
 *
 * Return: number of digits
 */
size_t _get_digit_count(int num)
{
	size_t digit_count = 0;

	if (num == 0)
		return (digit_count);

	/* Increment digit_count due to the sign */
	if (num < 0)
		digit_count++;

	for (; num != 0; digit_count++)
		num /= 10;

	return (digit_count);
}

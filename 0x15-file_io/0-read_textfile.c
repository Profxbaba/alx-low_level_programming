#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int gh;
	ssize_t nrd, nwr;
	char *puf;

	if (!filename)
		return (0);

	gh = open(filename, O_RDONLY);

	if (gh == -1)
		return (0);

	puf = malloc(sizeof(char) * (letters));
	if (!puf)
		return (0);

	nrd = read(gh, puf, letters);
	nwr = write(STDOUT_FILENO, puf, nrd);

	close(gh);

	free(puf);

	return (nwr);
}

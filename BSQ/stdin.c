#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	unsigned long long int		buffer_size;
	unsigned long long int		length;
	char						*buffer;
	char						*new_buffer;
	char						c;
	unsigned long long int		i;

	buffer_size = 1;
	length = 0;
	buffer = malloc(buffer_size * sizeof(char));
	if (buffer == NULL)
	{
		printf("Erreur d'allocation de mémoire");
		return (1);
	}
	//while (read(STDIN_FILENO, &c, 1) > 0 && c != '\n')
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		new_buffer = malloc((length + 1 + 1) * sizeof(char));
		if (new_buffer == NULL)
		{
			free(buffer);
			printf("Erreur d'allocation de mémoire");
			return (1);
		}
		i = 0;
		while (i < length)
		{
			new_buffer[i] = buffer[i];
			i++;
		}
		new_buffer[length] = c;
		new_buffer[length + 1] = '\0';
		free(buffer);
		buffer = new_buffer;
		length++;
	}
	if (length == 0)
		buffer[0] = '\0';
	printf("Vous avez entré : %s\n", buffer);
	free(buffer);
	return (0);
}

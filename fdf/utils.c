#include "fdf.h"

unsigned int	getcol(char **columns)
{
	unsigned int	n;
	int				i;

	n = 0;
	i = 0;
	while (columns[i++])
		n++;
	return (n);
}

void	checkoverflow(char *content)
{
	if (ft_atol(content) < INT_MIN || ft_atol(content) > INT_MAX)
		write(2, "Warning: int overflow, may cause unpredictable behavior\n", 57);
	else if (ft_atol(content) != ft_atoi(content))
	{
		write(2, "Fatal Error: Input wrong or corrupted, terminating\n", 52);
		exit(EXIT_FAILURE);
	}
}



#include "cub3d.h"

void	side_error(void)
{
	write(2, "SIDE ERROR\n", 11);
	exit(0);
}

char *checkside(char **texture, char *side)
{
	if (ft_strlen(texture[0]) == 2)
		return (side = ft_strdup(texture[1]));
	else
		side_error();
	return (0);
}


void	makeside(t_file *file)
{
	char **textures;
	int i;

	i = 0;
	textures = ft_split(file->line, ' ');
	while (textures[i])
		i++;
	if (i != 2)
		side_error();
	if (ft_strnstr(textures[0], "S", 2) != NULL)
	{
		if (ft_strlen(textures[0]) == 1)
			file->sprite = ft_strdup(textures[1]);
		if (ft_strlen(textures[0]) == 2 && textures[0][1] != 'O')
			side_error();
	}
	if (ft_strnstr(textures[0], "NO", 2) != NULL)
		 file->sides.north = checkside(textures, file->sides.north);
	if (ft_strnstr(textures[0], "WE", 2) != NULL)
		file->sides.west = checkside(textures, file->sides.west);
	if (ft_strnstr(textures[0], "EA", 2) != NULL)
		file->sides.east = checkside(textures, file->sides.east);
	if (ft_strnstr(textures[0], "SO", 2) != NULL)
		file->sides.south = checkside(textures, file->sides.south);
	free(textures);
}
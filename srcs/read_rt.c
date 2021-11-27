/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:24:03 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/27 12:36:44 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char		*read_everything(int fd)
{
	char	*resultat;
	char	*buffer;
	int		i_read;

	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	if (!(resultat = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	resultat[0] = '\0';
	while ((i_read = read(fd, buffer, BUFFER_SIZE)))
	{
		resultat = concat_here(resultat, buffer, i_read);
	}
	free(buffer);
	if (i_read < 0)
		return (NULL); // ERROR READING = 2
	return (resultat);
}

int			process_element(rt_scene *sc, char *begin)
{
	if (begin[0] == 'A')
	{
		if (sc->a_lum >= 0)
			return ((sc->a_lum = -444));
		else
			return (process_ambiance(sc, begin));
	}
	if (begin[0] == 'C')
		return (process_camera(sc, begin));
	if (begin[0] == 'L')
		return (process_light(sc, begin));
	return (process_object(sc, begin));
}

int			process_everything(char *all, rt_scene *this_scene)
{
	int		i;
	char	**all_elements;

	all_elements = ft_split(all, '\n');
	i = 0;
	while (all_elements[i])
	{
		printf("%s\n", all_elements[i]);
		if (all_elements[i][0])
			if (process_element(this_scene, all_elements[i]) < 0)
				exit_program("INCORRECT ELEMENT FORMATTING\n");
		free(all_elements[i]);
		i++;
	}
	free(all_elements[i]);
	free(all_elements);
	return (0);
}

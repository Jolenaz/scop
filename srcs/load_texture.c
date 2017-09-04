/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:13:32 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/01 14:13:35 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	load_texture(void)
{
	unsigned char	header[138];
	t_text_info		info;
	char			*data;
	FILE			*file;

	file = fopen("./scenes/materials/licorne.bmp", "rb");
	if (file == NULL)
		print_error1("impossible d'ouvrir la texture.");
	fread(header, 1, 138, file);
	info.data_pos = *(int*)&(header[0x0A]);
	info.width = *(int*)&(header[0x12]);
	info.height = *(int*)&(header[0x16]);
	info.image_size = info.width * info.height * 3;
	data = (char*)malloc(info.image_size * sizeof(char));
	fread(data, 1, info.image_size, file);
	fclose(file);
	glGenTextures(1, &(info.im_id));
	glBindTexture(GL_TEXTURE_2D, info.im_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, info.width, info.height,
	0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

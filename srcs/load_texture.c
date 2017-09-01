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

void load_texture()
{
	unsigned char	header[138]; 
	unsigned int	dataPos;
	unsigned int	width, height;
	unsigned int	imageSize;
	unsigned int	im_id;
	char			*data;

	FILE * file = fopen("./scenes/materials/licorne.bmp","rb");
	if (file == NULL)
		print_error1("impossible d'ouvrir la texture.");
	if ( fread(header, 1, 138, file)!=138 ){ 
    	printf("Not a correct BMP file\n");
    	return;
	}
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x02]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);
	printf("data pose = %d\nimagesize = %d\nwidth = %d\nheight = %d\n",
		dataPos,
		imageSize,
		width,
		height
		);
	imageSize = width * height * 3;
	data = (char*)malloc(imageSize * sizeof(char));
	fread(data,1,imageSize,file);
	fclose(file);
	glGenTextures(1, &im_id);
	glBindTexture(GL_TEXTURE_2D, im_id);
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

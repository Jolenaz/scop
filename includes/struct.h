/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:06:16 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/18 15:06:20 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_text_info{
	unsigned int	data_pos;
	unsigned int	width;
	unsigned int	height;
	unsigned int	image_size;
	unsigned int	im_id;
}				t_text_info;

typedef struct	s_trigo{
	float	cos_x;
	float	sin_x;
	float	cos_y;
	float	sin_y;
	float	cos_z;
	float	sin_z;
}				t_trigo;

typedef struct	s_vec2{
	GLfloat x;
	GLfloat y;
}				t_vec2;

typedef struct	s_mat2{
	GLfloat m00;
	GLfloat m01;
	GLfloat m10;
	GLfloat m11;
}				t_mat2;

typedef struct	s_mat3{
	GLfloat m00;
	GLfloat m01;
	GLfloat m02;
	GLfloat m10;
	GLfloat m11;
	GLfloat m12;
	GLfloat m20;
	GLfloat m21;
	GLfloat m22;
}				t_mat3;

typedef struct	s_mat4{
	GLfloat m00;
	GLfloat m10;
	GLfloat m20;
	GLfloat m30;
	GLfloat m01;
	GLfloat m11;
	GLfloat m21;
	GLfloat m31;
	GLfloat m02;
	GLfloat m12;
	GLfloat m22;
	GLfloat m32;
	GLfloat m03;
	GLfloat m13;
	GLfloat m23;
	GLfloat m33;
}				t_mat4;

typedef struct	s_vec3{
	GLfloat x;
	GLfloat y;
	GLfloat z;
}				t_vec3;

typedef struct	s_vec4{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
}				t_vec4;

typedef struct	s_color{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
}				t_color;

typedef struct	s_cam{
	t_vec3	pos;
	t_vec3	rot;
	GLfloat	width;
	GLfloat	height;
	GLfloat	ratio;
	GLfloat	near;
	GLfloat	far;
	GLfloat	fov;
	t_mat4	view_matrice;
}				t_cam;

typedef struct	s_vertex{
	t_vec3	pos;
	t_color	kd;
	t_vec2	text;
}				t_vertex;

enum	e_vao_ids{
	Triangles,
	NumVAOs
};

enum	e_buffer_ids{
	ArrayBuffer,
	NumBuffers
};

enum	e_attrib_ids{
	vPosition = 0,
	vColor = 1
};

typedef struct	s_shader_info{
	GLenum	flag;
	GLchar	*addr;
}				t_shader_info;

typedef enum	e_face_type{
	face_undefine,
	face_v,
	face_v_n,
	face_v_t,
	face_v_t_n
}				t_face_type;

typedef struct	s_face{
	int				vertex[3];
	struct s_face	*next;
	struct s_face	*prev;
}				t_face;

typedef	enum	e_text_type{
	grey_scale,
	texture
}				t_texture_type;

typedef struct	s_obj{
	t_face			*first_face;
	t_face			*last_face;
	t_vec3			pos;
	t_vec3			rot;
	GLuint			nb_faces;
	GLfloat			xmin;
	GLfloat			ymin;
	GLfloat			zmin;
	GLfloat			xmax;
	GLfloat			ymax;
	GLfloat			zmax;
	t_texture_type	texture_type;
}				t_obj;

typedef struct	s_env{
	t_cam			*camera;
	SDL_Window		*main_window;
	SDL_GLContext	main_context;
	SDL_Event		evenements;
	GLuint			program;
	GLuint			vaos[NumVAOs];
	GLuint			buffers[NumBuffers];
	float			delta;
	int				nb_vertex;
	int				nb_faces;
	t_vec3			*vertex_tab;
	t_obj			*obj;
}				t_env;

typedef struct	s_key_input{
	int		keycode;
	void	(*f)(t_env *env);
}				t_key_input;

#endif

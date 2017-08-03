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

typedef struct s_vec2{
    GLfloat x;
    GLfloat y;
}               t_vec2;

typedef struct s_mat2{
    GLfloat _00;
    GLfloat _01;
    GLfloat _10;
    GLfloat _11;
}               t_mat2;

typedef struct s_mat3{
    GLfloat _00;
    GLfloat _01;
    GLfloat _02;
    GLfloat _10;
    GLfloat _11;
    GLfloat _12;
    GLfloat _20;
    GLfloat _21;
    GLfloat _22;
}               t_mat3;

typedef struct s_mat4{
    GLfloat _00;
    GLfloat _10;
    GLfloat _20;
    GLfloat _30;
	GLfloat _01;
    GLfloat _11;
    GLfloat _21;
    GLfloat _31;
	GLfloat _02;
    GLfloat _12;
    GLfloat _22;
    GLfloat _32;
	GLfloat _03;
    GLfloat _13;
    GLfloat _23;
    GLfloat _33;

}               t_mat4;

typedef struct  s_vec3{
    GLfloat x;
    GLfloat y;
    GLfloat z;
}               t_vec3;

typedef struct	s_vec4{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
}				t_vec4;

typedef struct  s_color{
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
}               t_color;

typedef struct s_cam{
    t_vec3  	pos;
    t_vec3  	rot;
    GLfloat		width;
    GLfloat		height;
	GLfloat		ratio;
    GLfloat		near;
    GLfloat		far;
    GLfloat		fov;
	t_mat4		view_matrice;
}               t_cam;

typedef struct	s_vertex{
    t_vec3  pos;
    t_color col; 
	}			t_vertex;

typedef struct	s_textured_vertex{
    t_vec3 		pos;
    GLfloat		text[2]; 
	}			t_textured_vertex;

enum e_vao_ids {
	Triangles,
	NumVAOs 
	};

enum e_buffer_ids {
	ArrayBuffer,
	NumBuffers
	};

enum e_attrib_ids {
	vPosition = 0,
	vColor = 1
	};

typedef struct s_shader_info{
	GLenum	flag;
	GLchar*	addr;
}				t_shader_info;

typedef enum	e_face_type{
	face_undefine,
	face_v,
	face_v_n,
	face_v_t,
	face_v_t_n
}				t_face_type;

typedef struct	s_material
{
	char	*name;
	char 	*map_Kd;
	t_color	Kd;
	t_color	Ks;
	t_color	Ka;
	GLfloat	Ns;
}				t_material;

typedef struct	s_face{
	int				vertex[3];
	int				normal[3];
	int				texture[3];
	struct	s_face	*next;
	struct	s_face	*prev;
	
}				t_face;

typedef struct s_obj{
    t_face			*first_face;
    t_face			*last_face;
    t_vec3  		pos;
    t_vec3  		rot;
	GLuint			nb_faces;
	t_face_type		f_type;
	t_material		*material;
	struct s_obj	*next;
	struct s_obj	*prev;
}           t_obj;

typedef struct  s_env{
    t_cam           *camera;
    SDL_Window      *mainWindow;
    SDL_GLContext   mainContext;
    SDL_Event       evenements;
	GLuint			program;
	GLuint			vaos[NumVAOs];
	GLuint 			buffers[NumBuffers];
	int				nb_vertex;
	int				nb_texture;
	int				nb_normal;
	int				nb_faces;
	t_vec3			*vertex_tab;
	t_vec3			*normal_tab;
	t_vec2			*texture_tab;
	t_obj			*first_obj;
	t_obj			*last_obj;
	int				nb_material;
	t_material		*mat_list;
	t_material		current_mat;
}               t_env;

typedef struct s_key_input{
	int		keycode;
	void	(*f)(t_env *env);
}				t_key_input;

#endif

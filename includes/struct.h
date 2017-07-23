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
}               t_cam;

typedef struct	s_vertex{
    t_vec3  pos;
    t_color col; 
	}			t_vertex;

typedef struct s_obj{
    int         vert_nb;
    t_vertex    *vertexes;
    t_vec3      pos;
    t_vec3      rot;
}           t_obj;

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

typedef struct  s_env{
    t_cam           *camera;
    SDL_Window      *mainWindow;
    SDL_GLContext   mainContext;
    SDL_Event       evenements;
	GLuint			program;
	GLuint			vaos[NumVAOs];
	GLuint 			buffers[NumBuffers];
    t_obj           *objets;
}               t_env;

typedef struct t_VertexData {
		GLfloat position[4];
		GLubyte color[4];
	}VertexData;

#endif

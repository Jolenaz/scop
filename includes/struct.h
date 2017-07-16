#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vec2{
    float x;
    float y;
}               t_vec2;

typedef struct s_mat2{
    float _00;
    float _01;
    float _10;
    float _11;
}               t_mat2;

typedef struct s_mat3{
    float _00;
    float _01;
    float _02;
    float _10;
    float _11;
    float _12;
    float _20;
    float _21;
    float _22;
}               t_mat3;

typedef struct s_mat4{
    float _00;
    float _01;
    float _02;
    float _03;
    float _10;
    float _11;
    float _12;
    float _13;
    float _20;
    float _21;
    float _22;
    float _23;
    float _30;
    float _31;
    float _32;
    float _33;
}               t_mat4;

typedef struct  s_vec3{
    float x;
    float y;
    float z;
}               t_vec3;

typedef struct  s_color{
    float r;
    float g;
    float b;
    float a;
}               t_color;

typedef struct s_cam{
    t_vec3  pos;
    t_vec3  rot;
    float   fov;
    float   near;
    float   far;
}               t_cam;

typedef struct s_vertex{
    t_vec3  pos;
    t_vec3  norm;
    t_color col;
}               t_vertex;

typedef struct s_obj{
    int         vert_nb;
    t_vertex    *vertexes;
    t_vec3      pos;
    t_vec3      rot;
}           t_obj;

typedef struct  s_env{
    t_cam           camera;
    SDL_Window      *mainWindow;
    SDL_GLContext   mainContext;
    SDL_Event       evenements;
}               t_env;

#endif
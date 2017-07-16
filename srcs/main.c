/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:10:23 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/11 16:10:26 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
  
int main(){

t_env   *env;

env = init_world();

int terminer = 0;
if (SDL_Init(SDL_INIT_VIDEO) == -1)
{
    fprintf(stderr,"Error: chargement de SDL");
    return (0);
}

float vertices[] = {-0.5, -0.5,   0.0, 0.5,   0.5, -0.5};

env->mainWindow = SDL_CreateWindow("une fenetre",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    640,
    480,
    SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

env->mainContext = SDL_GL_CreateContext(env->mainWindow);

SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // use new opengl
SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);



while(!terminer)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLE_FAN, 0, 3);

    glDisableVertexAttribArray(0);

    
    SDL_GL_SwapWindow(env->mainWindow);

    SDL_WaitEvent(&(env->evenements));
    if((env->evenements).key.keysym.sym == SDLK_c)
        terminer = 1;
}

SDL_Quit();
return (0);
}
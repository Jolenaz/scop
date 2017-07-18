#include "scop.h"

const GLchar *load_shader_source(char *filename) {
  if (FILE *file = fopen(filename, "r") == -1)
    return NULL;
  fseek(file, 0L, SEEK_END);
  size_t size = ftell(file);
  GLchar *shaderSource = (GLchar*)malloc(sizeof(GLchar) * size);
  rewind(file);
  fread(shaderSource, size, sizeof(char), file);
  fclose(file);
  return shaderSource;
}

void init_shader(t_env *e)
{
  GLchar *tmpString;

	e->shaders = (GLuint*)malloc(sizeof(GLuint) * NB_SHADER);
    
    e->shaders[EMPTY_FRAG] = glCreateShader(GL_FRAGMENT_SHADER);
    e->shaders[EMPTY_VERT] = glCreateShader(GL_VERTEX_SHADER);

    tmpString = load_shader_source(EMPTY_FRAG_FILE);
    glShaderSource(e->shaders[EMPTY_FRAG], 1, tmpString, NULL);

    tmpString = load_shader_source(EMPTY_VERT_FILE);
    glShaderSource(e->shaders[EMPTY_VERT], 1, tmpString, NULL);

    glCompileShader(e->shaders[EMPTY_FRAG]);
    glCompileShader(e->shaders[EMPTY_VERT]);

}
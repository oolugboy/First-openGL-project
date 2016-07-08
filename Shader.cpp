/*
 * Shader.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: olujimi
 */

#include "Shader.h"
#include <iostream>
#include <fstream>
using namespace std;

/** Helper method to create the shader **/
static GLuint CreateShader(const string & text, GLenum shaderType);
void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

Shader::Shader(const string & fileName)
{
	/** Create the program on the GPU **/
	program = glCreateProgram();
	/** Now to create the vertex shader **/
	shaders[0] = CreateShader(LoadShader(fileName + ".vs"),GL_VERTEX_SHADER);
	shaders[1] = CreateShader(LoadShader(fileName + ".fs"),GL_FRAGMENT_SHADER);

	/** The we attached the shaders to the program **/
	for(unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(program, shaders[i]);

	glBindAttribLocation(program,0,"position");
	/** Now to link all the programs that gave been attached **/
	glLinkProgram(program);
	/** Now to check for linking errors **/
	CheckShaderError(program,GL_LINK_STATUS,true," Error: Program linking failure: ");

	/** Now to validate the program **/
	glValidateProgram(program);
	CheckShaderError(program,GL_VALIDATE_STATUS,true," Error: Program validation error: ");
}

Shader::~Shader() {
	/**we initially delete the shader **/
	for(unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(program, shaders[i]);
		glDeleteShader(shaders[i]);
	}
	/** Delete the program on the GPU **/
	glDeleteProgram(program);
}
/** Now to implement bind **/
void Shader::Bind()
{
	/** To install this program as part of the current rendering state **/
	glUseProgram(program);
}
/** Helper method to create the shader **/
static GLuint CreateShader(const string & text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	if(shader == 0)
		cerr << " Failed to create the empty shader object " << endl;

	/** Now to compile the shader **/
	const GLchar * shaderSrcStrings[1];
	const GLint shaderSrcStringsLength[1] = {text.length()};

	shaderSrcStrings[0] = text.c_str();

	/** Now to copy the source code into the shader object **/
	glShaderSource(shader, 1, shaderSrcStrings, shaderSrcStringsLength);
	/** Now to compile the shader source code **/
	glCompileShader(shader);
	CheckShaderError(shader,GL_COMPILE_STATUS,false,"Error: Shader compilation failed: ");
	return shader;
}

std::string Shader::LoadShader(const std::string& fileName)
{
    ifstream file;
    file.open((fileName).c_str());

    string output;
    string line;

    /** Getting all the text from the file **/
    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}


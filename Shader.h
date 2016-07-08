/*
 * Shader.h
 *
 *  Created on: Jul 4, 2016
 *      Author: olujimi
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <GL/glew.h>
using namespace std;

class Shader {
	public:
		Shader(const string & fileName);

		/** This to make sure that the GPU is using the vertex
		 * and fragment shader implemented in this class
		 */
		void Bind();
		virtual ~Shader();
	protected:
	private:
		string LoadShader(const std::string& fileName);
		static const unsigned int NUM_SHADERS = 2;
	/** keep track of where the program is **/
		GLuint program;
	/** Now to store the 2 shaders **/
		GLuint shaders[NUM_SHADERS];


};

#endif /* SHADER_H_ */

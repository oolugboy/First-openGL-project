/*
 * mesh.h
 *
 *  Created on: Jun 29, 2016
 *      Author: olujimi
 */
#ifndef MESH_H
#define MESH_H

/** openGL math library to represent the vertices **/
#include <glm/glm.hpp>
/** for the openGL functions **/
#include <GL/glew.h>

/** To make our data a little nicer for openGL to work with **/
class Vertex
{
    public:
        Vertex(const glm::vec3& pos)
        {
            this->pos = pos;
        }
    protected:
    private:
        glm::vec3 pos;
};

class Mesh
{
    public:
        Mesh(Vertex * vertices, unsigned int numVertices);

        /** This is supposed to take out mesh and draw it ?? **/
        void draw();

        virtual ~Mesh();
    protected:
    private:

        enum
        {
            POSITION_VB,
            NUM_BUFFERS
        };

        /** Data on the GPU?? **/
        GLuint vertexArrayObject;
        GLuint vertexArrayBuffers[NUM_BUFFERS];

        unsigned int drawCount;
};

#endif // MESH_H




/*
 * mesh.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: olujimi
 */
#include "mesh.h"
#include <iostream>
using namespace std;

Mesh::Mesh(Vertex * vertices, unsigned int numVertices)
{
	/** Set the drawCount **/
	drawCount = numVertices;

	/** Generate the VAO to store the state of the buffers and the attribute **/
	glGenVertexArrays(1,&vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	/** The generate the vertex buffer **/
	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

	cerr << " The amount of buffers " << NUM_BUFFERS << endl;

	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER,numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	/** This would be a sequence of positions **/
	glEnableVertexAttribArray(0);
	/** Now to specify how openGL should get all the position attributes **/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	/** Unbind the vertex array */
	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}
/** The method that is supposed to draw up our mesh **/
void Mesh::draw()
{
	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glBindVertexArray(0);
}




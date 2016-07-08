#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "Shader.h"


using namespace std;

int main()
{
    Display disp = Display(800, 600, "Jimi's window");
    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
    						Vertex(glm::vec3(0,0.5, 0)),
    						Vertex(glm::vec3(0.5 ,-0.5, 0))};
    Mesh test = Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
   // cout << " something got printed " << endl;
    Shader shader("./res/basicShader");
    /** Now to test the display **/
    while(!(disp.getClosed()))
    {
        glClearColor(0.5f,0.5f,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.Bind();
        test.draw();
        disp.update();
    }
    return 0;
}



#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

/* Vertex Shader Source Code */
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main()
{
	/* Initializing GLFW */
	glfwInit();
	
	/* Giving GLFW information about version being used  */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Making a Window pointer object 
		Arguements -> Width, Height, Name, Monitor, Share*/
	GLFWwindow *window = glfwCreateWindow(800, 800, "My First Window", NULL, NULL);

	/*To be safe side*/
	if (window == NULL)
	{
		std::cout << "Failed to Compile Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	/* If No error found */
	glfwMakeContextCurrent(window);

	/*Loading GLAD */
	gladLoadGL();

	/*passing in viewport size */
	glViewport(0, 0, 800, 800);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	/* Swapping buffers as only front buffer content is displayed */
	glfwSwapBuffers(window);

	/* Adding delay : kind of */
	while (!glfwWindowShouldClose(window)) 
	{
		glfwPollEvents();
	}

	/* Terminate Context window */
	glfwDestroyWindow(window);

	/* Terminate glfw call */
	glfwTerminate();
	return 0;
}
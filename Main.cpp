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

	GLfloat vertices[] =
	{
		-0.5f ,-0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
	};

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

	/* Setting Up vertex shader*/
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	/* Setting Up fragment Shader */
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// --- --- --- ---
	/* Creating Shader Program */
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	/* Delete shaders as thier compiled form is now linked*/
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// --- --- --- ---

	/* VBO objects for display */
	GLuint VAO, VBO;

	/*Ordering is Important*/
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Specify Color of the background 
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean back buffer and assign new color to it
	glClear(GL_COLOR_BUFFER_BIT);

	/* Swapping buffers as only front buffer content is displayed */
	glfwSwapBuffers(window);

	/* Adding delay : kind of */
	while (!glfwWindowShouldClose(window)) 
	{
		// Specify Color of the background 
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean back buffer and assign new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	/* Terminate Context window */
	glfwDestroyWindow(window);

	/* Terminate glfw call */
	glfwTerminate();
	return 0;
}
/*
	All openGL sources are referenced by refereences
*/
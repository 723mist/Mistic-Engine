#include "../window/window.h"

void Window::Update() {
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
    }
}


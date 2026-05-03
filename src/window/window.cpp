#include "window.h"

static void glfw_error_callback() {

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Window::Init(const char* title, int width, int height, bool fullscreen) {
    this->title = title;
    this->width = width;
    this->height = height;
    this->fullscreen = fullscreen;

    if (!glfwInit()) return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, fullscreen ? GLFW_TRUE : GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window) return;

    glfwMakeContextCurrent(window);

    int version = gladLoadGL(glfwGetProcAddress);
    if (!version) return;

    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSwapInterval(1);

    return;
}

void Window::Close() {
    glfwDestroyWindow(window);
    glfwTerminate();
    return;
}
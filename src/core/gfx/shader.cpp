#include "shader.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <print>

std::string loadTextFromFile(std::string path)
{
    std::string str;
    std::ifstream file;
    file.open(path);

    if (!file.is_open())
    {
        std::println("Failed to open file {}", path);
        return " ";
    }

    std::string line;

    while (std::getline(file, line))
    {
        str += line + '\n';
    }

    return str;
}

void checkShaderComp(unsigned int shader)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Shader Compilation Error!: \n" << infoLog << '\n';
    }
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    std::ifstream vertexShaderFile(vertexShaderPath);
    std::ifstream fragShaderFile(fragmentShaderPath);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexSource = loadTextFromFile(vertexShaderPath);

    const char* vSource = vertexSource.c_str();
    glShaderSource(vertexShader, 1, &vSource, NULL);
    glCompileShader(vertexShader);
    
    checkShaderComp(vertexShader);

    std::string fragmentShaderSource = loadTextFromFile(fragmentShaderPath);
    const char* fsource = fragmentShaderSource.c_str();
    glShaderSource(fragmentShader, 1, &fsource, NULL);
    glCompileShader(fragmentShader);

    checkShaderComp(fragmentShader);

    this->programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use()
{
    glUseProgram(this->programID);
}

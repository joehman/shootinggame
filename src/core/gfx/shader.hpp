#pragma once
#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <string>

class Shader
{
public:
    Shader() {}
    Shader(std::string vertexShaderPath, std::string fragmentShaderPath);

    void use();

    unsigned int getProgramID() {return programID;}

private:
    unsigned int programID;

};

#endif
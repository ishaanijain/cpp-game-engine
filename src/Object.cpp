#include "../include/Object.h"

Object::Object(std::string name) : name(name) {}

const std::string& Object::getName() const {
    return name;
}
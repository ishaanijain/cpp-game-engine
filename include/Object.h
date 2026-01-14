#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object{
    private:
    std::string name;

    public:
    Object(std::string name);
    virtual ~Object() = default;
    const std::string& getName() const;
    virtual std::string describe() const = 0;
};

#endif  

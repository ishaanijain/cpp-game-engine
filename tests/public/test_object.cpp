#include <catch_amalgamated.hpp>
#include "../../include/Object.h"

class ObjectProb : public Object{
    public:
    ObjectProb(std::string name):Object(name){}
    std::string describe() const{
        return  "";
    }
};

namespace {
  TEST_CASE("HW 5 Object Test 2", "[nameTest]") {
   ObjectProb object("Mystery Box");
   std::string name = "Mystery Box";
   CHECK(object.getName() == name);
  }
}
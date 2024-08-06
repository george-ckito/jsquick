//
// Created by georgeckito on 8/3/2024.
//

#ifndef API_H
#define API_H
#include <string>
#include <vector>
#include "Input/Input.h"
#include "json.hpp"
#include "Project.h"
#include "Utility/Utility.h"

namespace project {

class api : public Project {
private:
    std::string mongodb;
public:
    explicit api(const Input::api& input);
    std::string getMongodb();
    void setMongodb(const std::string& mongodb);
};

} // project

#endif //API_H

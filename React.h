//
// Created by georgeckito on 8/5/2024.
//

#ifndef REACT_H
#define REACT_H
#include "Project.h"
#include "Input/Input.h"

namespace project {

class React : public Project {
public:
    explicit React(const Input::react& input);
};

} // project

#endif //REACT_H

#include <string>

std::string catMouse(std::string field, unsigned int jump) {
    bool catPresent = false;
    bool dogPresent = false;
    bool mousePresent = false;
    int catIndex = -1;
    int mouseIndex = -1;

    for (int i = 0; i < field.size(); ++i) {
        if (field[i] == 'C') {
            catPresent = true;
            catIndex = i;
        } else if (field[i] == 'D') {
            dogPresent = true;
        } else if (field[i] == 'm') {
            mousePresent = true;
            mouseIndex = i;
        }
    }

    if (!catPresent || !dogPresent || !mousePresent) {
        return "boring without all three";
    }

    int distance = std::abs(catIndex - mouseIndex) - 1;

    if (distance <= jump && field.substr(std::min(catIndex, mouseIndex), distance + 1).find('D') == std::string::npos) {
        return "Caught!";
    } else if (distance <= jump) {
        return "Protected!";
    } else {
        return "Escaped!";
    }
}
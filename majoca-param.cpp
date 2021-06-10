#include "majoca-param.h"

const int32_t MajocaParam::getPosX()
{
    return _pos_x;
}

const int32_t MajocaParam::getPosY()
{
    return _pos_y;
}

void MajocaParam::setPosX(const int32_t x)
{
    _pos_x = x;
}

void MajocaParam::setPosY(const int32_t y)
{
    _pos_y = y;
}
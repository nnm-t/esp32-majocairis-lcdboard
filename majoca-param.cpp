#include "majoca-param.h"

const int32_t MajocaParam::getPosX()
{
    return _pos_x;
}

const int32_t MajocaParam::getPosY()
{
    return _pos_y;
}

const uint32_t MajocaParam::getBackground()
{
    return _background;
}

const uint32_t MajocaParam::getForeground()
{
    return _foreground;
}

void MajocaParam::setPosX(const int32_t x)
{
    _pos_x = x;
}

void MajocaParam::setPosY(const int32_t y)
{
    _pos_y = y;
}

void MajocaParam::setBackground(const uint32_t color)
{
    _background = color;
}

void MajocaParam::setForeground(const uint32_t color)
{
    _foreground = color;
}
#pragma once
#include "ChessPiece.h"
class bishop :
    public ChessPiece
{
public:
    bishop(char c);
    Vector2* getlegalmoves(Grid* gptr);
};


#pragma once
#include "ChessPiece.h"
class queen :
    public ChessPiece
{
public:
    queen(char c);
    Vector2* getlegalmoves(Grid* gptr);
};


#pragma once
#include "ChessPiece.h"
class king :
    public ChessPiece
{
public:
    king(char c);
    Vector2* getlegalmoves(Grid* gptr);
};


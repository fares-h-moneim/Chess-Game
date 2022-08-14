#pragma once
#include "ChessPiece.h"
class rook :
    public ChessPiece
{
public:
    rook(char c);
    Vector2* getlegalmoves(Grid* gptr);
};


#pragma once
#include "ChessPiece.h"
class pawn :
    public ChessPiece
{
    bool first = true;
public:
    pawn(char c);
    Vector2* getlegalmoves(Grid* gptr);
};


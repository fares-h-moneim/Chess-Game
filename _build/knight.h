#pragma once
#include "ChessPiece.h"
class knight :
    public ChessPiece
{
public:
   
     knight(char c);
     Vector2* getlegalmoves(Grid* gptr);
};


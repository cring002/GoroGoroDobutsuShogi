//
//  GiraffePiece.hpp
//  papTermTwoCourseWork
//
//  Created by Charles Ringer on 08/03/2016.
//
//

#ifndef GiraffePiece_hpp
#define GiraffePiece_hpp

#include <stdio.h>
#include "GamePiece.hpp"

class GiraffePiece: public GamePiece
{
public:
    GiraffePiece(int x, int y, Player* _owner, shared_ptr<ImageBank> imgBank = NULL);
    //No copy constructor because we want default behaviour as cannot redefine the implict copy constuctor. 
    virtual ~GiraffePiece();
    virtual bool canMove(int newX, int newY);
    virtual shared_ptr<GamePiece> clone();
};

#endif /* GiraffePiece_hpp */

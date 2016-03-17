//
//  Button.cpp
//  papTermTwoCourseWork
//
//  Created by Charles Ringer on 27/02/2016.
//
//

#include "Button.hpp"

Button::Button(int _x, int _y, int _w, int _h, string ident, string imgPath, shared_ptr<ImageBank>& imgBank): x(_x), y(_y), w(_w), h(_h), id(ident)
{
    dispImage = imgBank->loadImage(imgPath);
}

void Button::draw()
{
    dispImage->draw(x,y);
}

bool Button::clicked(int mX, int mY)
{
    return mX > x && mX < x+w && mY > y && mY < y+h;
}
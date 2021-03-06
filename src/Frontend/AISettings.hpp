//
//  AISettings.hpp
//  papTermTwoCourseWork
//
//  Created by Charles Ringer on 16/03/2016.
//
//

#ifndef AISettings_hpp
#define AISettings_hpp

#include <stdio.h>
#include "GameState.hpp"
#include "ImageBank.hpp"
#include "Button.hpp"

class AISettings: public GameState
{
private:
    ofImage* background;
    Button back;
    Button title;
    Button lArrowItt;
    Button rArrowItt;
    Button lArrowExp;
    Button rArrowExp;
    ofTrueTypeFont dispFont;
    
public:
    AISettings(shared_ptr<ImageBank> imgBank);
    AISettings(const AISettings& other);
    virtual ~AISettings();
    virtual void update(){};
    virtual void draw();
    virtual void handleClick(int x, int y);
    
};

#endif /* AISettings_hpp */

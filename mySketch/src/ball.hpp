//
//  ball.hpp
//  mySketch
//
//  Created by egusahiroaki on 2017/10/13.
//
//

#ifndef ball_hpp
#define ball_hpp

#include "ofMain.h"
#include <stdio.h>

class Ball {
public:
    void init(float _x, float _y, int _eSize, ofColor _color);

    void update();

    void grow();

    bool checkEdge();
    void stopGrow();
    
    void display();
    
    float xPos, yPos, eSize, speed;
    
    ofColor color;

    bool isGrowing;
    
private:
};


#endif /* ball_hpp */


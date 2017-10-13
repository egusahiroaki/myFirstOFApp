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
    void init(float _y, int _eSize, float _speed);
    
    void update();
    
    void display();
    
    float xPos, yPos, eSize, speed;
    
private:
};

#endif /* ball_hpp */


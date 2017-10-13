//
//  ball.cpp
//  mySketch
//
//  Created by egusahiroaki on 2017/10/13.
//
//

#include "ball.hpp"

void Ball::init (float _y, int _eSize, float _speed){

    xPos = 0.0;
    yPos = _y;
    eSize = _eSize;
    speed = _speed;
}

void Ball::update() {
    
    xPos += speed;
    if (xPos >  ofGetWidth()){
        xPos = 0;
    }
}

void Ball::display(){
    ofDrawCircle(xPos, yPos, eSize);
}

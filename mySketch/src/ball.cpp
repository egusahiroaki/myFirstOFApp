//
//  ball.cpp
//  mySketch
//
//  Created by egusahiroaki on 2017/10/13.
//
//

#include "ball.hpp"


void Ball::init (float _x, float _y, int _eSize){
    xPos = _x;
    yPos = _y;
    eSize = _eSize;
    speed = 1;
    isGrowing = true;
}

void Ball::grow() {
    
//    cout << "grow" << endl;
    if(isGrowing){
        eSize += 1;
    }
}

void Ball::stopGrow() {
    isGrowing = false;
}


bool Ball::checkEdge() {
    if(xPos + eSize > ofGetWidth() || xPos - eSize < 0){
        return true;
    }
    
    if(yPos + eSize > ofGetHeight() || yPos - eSize < 0){
        return true;
    }

    return false;
}

void Ball::update() {
    
    xPos += speed;
    if (xPos > ofGetWidth()){
        xPos = 0;
    }
}

void Ball::display(){
    ofDrawCircle(xPos, yPos, eSize);
}

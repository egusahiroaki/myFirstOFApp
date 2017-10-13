#include "ofApp.h"
#include <random>
#include <vector>

#define NUM_CIRCLES 10


//std::array<Ball, NUM_CIRCLES> circles;

std::vector<Ball> circles;


//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetFrameRate(60);

    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    
    for(Ball c:circles){
//        float x = ((float) rand() / (RAND_MAX));
//        float y = ((float) rand() / (RAND_MAX));
//        circles[i].init(ofGetWidth() * x, ofGetHeight() * y, 1.0);
    }

/*
    bkImage.load("images/The_Girl_With_The_Pearl_Earring.jpg");
    bkImage.grabScreen(0,0,ofGetWidth(),ofGetHeight()); // 0,0 からwindow width, heightのスクショを撮影
    
    for(int x = 0; x < bkImage.getWidth(); x++){
        for(int y = 0; y < bkImage.getHeight(); y++){
            int index = x + y * bkImage.getWidth();
            color
        }
    }

    float imageHeight = ofGetHeight();
    float imageWidth  = imageHeight * 800 /1145;
    float imageMarginWidth  = (ofGetWidth() - imageHeight * 800 /1145)/2;


    bkImage.draw(imageMarginWidth, 0, imageWidth, imageHeight); // 800 x 1145
*/

}

void ofApp::newCircle(){
    float x = ofGetWidth() * ((float) rand() / (RAND_MAX));
    float y = ofGetHeight() * ((float) rand() / (RAND_MAX));
    
    bool valid = true;
    for(Ball c:circles){
        float d = ofDist(x, y, c.xPos, c.yPos);
        if(d < c.eSize){
            valid = false;
            break;
        }
    }
    if(valid){
        Ball b;
        b.init(x, y, 1.0);
        circles.push_back(b);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    newCircle();
    
    for(int i=0; i<circles.size();i++){
        if(circles[i].checkEdge()){
            circles[i].stopGrow();
        }
        circles[i].grow();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<NUM_CIRCLES;i++){
        ofNoFill();
        ofSetColor(0,0,0);
        circles[i].display();
        ofFill();
        ofSetColor(255, 255, 255);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << "keyPressed " << (char)key << endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

#include "ofApp.h"
#define NUM_CIRCLES 1


std::array<Ball, NUM_CIRCLES> circles;

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetFrameRate(60);

    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);

    for(int i=0; i<NUM_CIRCLES;i++){
        circles[i].init(100, 100, 1.0);
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

//--------------------------------------------------------------
void ofApp::update(){
//    b1.update();
//    b2.update();

    for(int i=0; i<NUM_CIRCLES;i++){
        if(circles[i].checkEdge()){
            circles[i].stopGrow();
        }
        circles[i].grow();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0);
    for(int i=0; i<NUM_CIRCLES;i++){
        circles[i].display();
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

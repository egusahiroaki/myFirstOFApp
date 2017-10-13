#include "ofApp.h"
#define NUM_CIRCLES 500

//float circleX[NUM_CIRCLES];
//float circleY[NUM_CIRCLES];
//float circleRad[NUM_CIRCLES];

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetFrameRate(60);
//
//    for(int i=0; i<NUM_CIRCLES;i++){
//        circleX[i] = ofRandom(0, ofGetWidth());
//        circleY[i] = ofRandom(0, ofGetHeight());
//        circleRad[i] = ofRandom(10, 40);
//    }

    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);

    b1.init(100, 10, 1.0);
    b2.init(300, 40, 3.5);
}

//--------------------------------------------------------------
void ofApp::update(){
//    for(int i=0; i<NUM_CIRCLES;i++){
//        circleX[i] += ofRandom(-1,1);
//        circleY[i] += ofRandom(-1,1);
//    }
    
    b1.update();
    b2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    for(int i=0; i<NUM_CIRCLES;i++){
//        ofDrawCircle(circleX[i], circleY[i], circleRad[i]);
//    }
    ofSetColor(0, 0, 0);
    b1.display();
    b2.display();
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

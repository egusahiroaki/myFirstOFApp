#include "ofApp.h"
#include <random>
#include <vector>

#define NUM_CIRCLES 10


//std::array<Ball, NUM_CIRCLES> circles;

std::vector<Ball> circles;
std::vector<ofColor> colors;


//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetFrameRate(60);
    ofSetFrameRate(100);

    
    ofBackground(255, 255, 255);
//    ofSetCircleResolution(64);
    
    bkImage.load("images/The_Girl_With_The_Pearl_Earring.jpg");

    float imageHeight = ofGetHeight();
    float imageWidth  = imageHeight * 800 /1145;
    float imageMarginWidth  = (ofGetWidth() - imageHeight * 800 /1145)/2;

//    bkImage.draw(imageMarginWidth, 0, imageWidth, imageHeight); // 800 x 1145

//    bkImage.grabScreen(0,0,ofGetWidth(),ofGetHeight()); // 0,0 からwindow width, heightのスクショを撮影

//    ofPixels pixels = bkImage.getPixelsRef();
    
    //unsigned char * pixels = bkImage.getPixels().getData();
    ofPixels pixels = bkImage.getPixels();
    cout << pixels.size(); // 2748000
    int w = bkImage.getWidth();
    int h = bkImage.getHeight();
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            ofColor color;
            color.r = pixels[i*3 * w + j*3];
            color.g = pixels[i*3 * w + j*3 + 1];
            color.b = pixels[i*3 * w + j*3 + 2];
            colors.push_back(color);
        }
    }

    cout << "colors";
    cout << colors.size();

    
/*
    for(int x = 0; x < bkImage.getWidth(); x++){
        for(int y = 0; y < bkImage.getHeight(); y++){
            // int index = x + y * bkImage.getWidth();
            unsigned char * myPixels;
            int colorIndex =  y*(bkImage.getWidth()*3)+x*3;
            cout << myPixels[colorIndex] << endl;
            ofSetColor(myPixels[colorIndex],myPixels[colorIndex+1],myPixels[colorIndex+2]);
        }
    }
*/
 
//    bkImage.draw(imageMarginWidth, 0, imageWidth, imageHeight); // 800 x 1145


    
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
        int index = int(x) + int(y) * 800;
        b.init(x, y, 1.0, colors[index]);
        circles.push_back(b);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    newCircle();
    for(int i=0; i< circles.size(); i++){
        //cout << c.id << endl;
        if(circles[i].isGrowing){
            if(circles[i].checkEdge()){
                circles[i].stopGrow();
            }else{
                for(int j=0; j<circles.size(); j++){
                    if(!(circles[i].xPos == circles[j].xPos)&& !(circles[i].yPos == circles[j].yPos)) {
                        float d = ofDist(circles[i].xPos, circles[i].yPos, circles[j].xPos, circles[j].yPos);
                        if(d < circles[i].eSize + circles[j].eSize){ // 円同士が重なったら
                            circles[i].stopGrow();
                            break;
                        }
                    }
                }
            }
        }
        circles[i].grow();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    float imageHeight = ofGetHeight();
//    float imageWidth  = imageHeight * 800 /1145;
//    float imageMarginWidth  = (ofGetWidth() - imageHeight * 800 /1145)/2;
    
//    bkImage.draw(0, 0, 800, 1145); // 800 x 1145

    for(Ball c:circles){
//        ofNoFill();
//        ofSetColor(0,0,0);

        c.display();
        ofFill();

//        ofSetColor(255, 255, 255);
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

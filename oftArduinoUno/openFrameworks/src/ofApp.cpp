#include "ofApp.h"

constexpr const char *PROJECT_NAME = "Untitled";
constexpr const char *CREATOR = "Violet Graham";

void ofApp::setup() {
  serial.listDevices();
  serial.setup(0, 9600);
}

void ofApp::update() { title(); }

void ofApp::draw() {
  ofBackground(ledOn ? 255 : 0);
  ofSetColor(ledOn ? 0 : 255);
  ofDrawBitmapString(
      "click mouse to toggle ardunio's on board led labeled with an L", 100,
      ofGetHeight() / 2);
}

void ofApp::mousePressed(int x, int y, int button) {
  ledOn = !ledOn;
  serial.writeByte(ledOn ? 'A' : 'B');
}

void ofApp::title() {
  stringstream titleStream;
  titleStream << PROJECT_NAME << " - " << CREATOR
              << " - FPS: " << static_cast<int>(ofGetFrameRate());
  ofSetWindowTitle(titleStream.str());
}

#include "ofApp.h"

constexpr const char *PROJECT_NAME = "Untitled";
constexpr const char *CREATOR = "Creator Name";

void ofApp::setup() {}

void ofApp::update() { title(); }

void ofApp::draw() {}

void ofApp::title() {
  stringstream titleStream;
  titleStream << PROJECT_NAME << " - " << CREATOR
              << " - FPS: " << static_cast<int>(ofGetFrameRate());
  ofSetWindowTitle(titleStream.str());
}

#pragma once

#include "ofMain.h"

constexpr char* PROJECT_NAME = "untitled";
constexpr char* CREATOR = "creator";
constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;

class ofApp : public ofBaseApp {
 public:
  ofVideoGrabber camera;

  ofPixels pixelsBuffer;

  ofTexture frame;

  ofShader shader;
  ofPlanePrimitive plane;

  void setup();
  void update();
  void draw();

  void updateTitle();

  void beginCamera();
};

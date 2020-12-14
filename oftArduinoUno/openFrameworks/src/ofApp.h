#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
  bool ledOn;
  ofSerial serial;

  void setup();
  void update();
  void draw();

  void mousePressed(int, int, int);

  void title();
};

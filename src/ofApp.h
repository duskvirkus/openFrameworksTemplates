#pragma once

#include "ofMain.h"

constexpr const char *PROJECT_NAME = "Untitled";
constexpr const char *CREATOR = "Violet Graham";

class ofApp : public ofBaseApp {

public:
  void setup();
  void update();
  void draw();

  void title();
};

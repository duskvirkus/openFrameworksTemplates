#include "ofApp.h"

void ofApp::setup() {
#ifdef TARGET_OPENGLES
  cout << "Project unsupported on this system! Press enter to exit." << '\n';
  cin.get();
  exit(1);
#endif
  assert(ofIsGLProgrammableRenderer());

#ifdef _DEBUG
  ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);
  ofLogToFile("logfile.log", true);
#endif

  ofEnableAlphaBlending();

  beginCamera();

  plane.set(ofGetWidth(), ofGetHeight(), ofGetWidth() / 20, ofGetHeight() / 20,
            OF_PRIMITIVE_TRIANGLES);

  shader.load("shader");

  ofSetBackgroundColor(0);
}

void ofApp::update() {
  updateTitle();

  camera.update();

  if (camera.isFrameNew()) {
    pixelsBuffer = camera.getPixels();
    ofTexture texture;
    texture.allocate(pixelsBuffer);
    texture.loadData(pixelsBuffer);
    frame = texture;
  }

  ofSetFrameRate(30);
}

void ofApp::draw() {
  const glm::vec2 window(ofGetWidth(), ofGetHeight());

  if (frame.getWidth() > 0 && frame.getHeight() > 0) {
    plane.mapTexCoordsFromTexture(frame);
    frame.bind();

    shader.begin();
    {
      shader.setUniform2f("u_window", window);

      ofPushMatrix();
      ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
      float scale = 1.f;
      ofScale(glm::vec3(scale, -scale, scale));
      plane.draw();
      ofPopMatrix();
    }
    shader.end();

    frame.unbind();
  }
}

void ofApp::updateTitle() {
  stringstream titleStream;
  titleStream << PROJECT_NAME << " - " << CREATOR
              << " - FPS: " << static_cast<int>(ofGetFrameRate());
  ofSetWindowTitle(titleStream.str());
}

void ofApp::beginCamera() {
  auto devices = camera.listDevices();
  for (const auto& device : devices) {
    if (device.bAvailable) {
      ofLogNotice() << device.id << ':' << device.deviceName;
    } else {
      ofLogNotice() << device.id << ':' << device.deviceName
                    << " - UNAVAILABLE!";
    }
  }

  camera.setDeviceID(0);
  camera.setDesiredFrameRate(30);
  camera.setup(WIDTH, HEIGHT);
}

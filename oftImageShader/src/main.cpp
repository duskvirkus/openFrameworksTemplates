#include <optional>

#include "ofApp.h"
#include "ofAppGLFWWindow.h"
#include "ofMain.h"

int main() {
  ofGLFWWindowSettings settings;
  settings.setSize(WIDTH / 2, HEIGHT / 2);
  settings.setPosition(glm::vec2(0, 30));
  settings.resizable = false;
  settings.setGLVersion(3, 2);

  shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

  shared_ptr<ofApp> mainApp(new ofApp);

  ofRunApp(mainWindow, mainApp);
  ofRunMainLoop();
}

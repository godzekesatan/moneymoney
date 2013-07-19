#include "moneymoney.h"

void MoneyMoney::setup() {
  map = reader.ReadMap("data/map.json");
  for (auto sprite : map) {
    images[sprite.filename].loadImage(sprite.filename);
    images[sprite.filename].getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
  }
  mouse_position = ofVec2f(ofGetWidth(), ofGetHeight()) / 2.0;
}

void MoneyMoney::update() {
  ofVec2f d((mouse_position.x - ofGetWidth() / 2.0) / ofGetWidth(),
            (mouse_position.y - ofGetHeight() / 2.0) / ofGetHeight());
  ofVec2f e = 0.8 * 0.5 * d / max(abs(d.x), abs(d.y));
  if (mouse_position.x < 0.1 * ofGetWidth() ||
      mouse_position.x > 0.9 * ofGetWidth() ||
      mouse_position.y < 0.1 * ofGetHeight() ||
      mouse_position.y > 0.9 * ofGetHeight()) {
    position += 10.0 * (d - e);
  }
  scale = ofLerp(scale, scale_target, 0.02);
}

void MoneyMoney::draw() {
  ofPushMatrix();
  ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0);
  ofScale(scale, scale);
  ofTranslate(-ofGetWidth() / 2.0, -ofGetHeight() / 2.0);
  ofTranslate(-position.x, -position.y);
  ofBackground(ofColor::black);
  ofEnableAlphaBlending();
  for (auto sprite : map) {
    images[sprite.filename].draw(sprite.x, sprite.y);
  }
  ofPopMatrix();
}

void MoneyMoney::keyPressed(int key) {
  if (key == '=') {
    scale_target *= 2;
  }
  if (key == '-' && scale_target > 1) {
    scale_target /= 2;
  }
}

void MoneyMoney::keyReleased(int key) {

}

void MoneyMoney::mouseMoved(int x, int y) {
  mouse_position = ofVec2f(x, y);
}

void MoneyMoney::mouseDragged(int x, int y, int button) {

}

void MoneyMoney::mousePressed(int x, int y, int button) {

}

void MoneyMoney::mouseReleased(int x, int y, int button) {

}

void MoneyMoney::windowResized(int w, int h) {

}

void MoneyMoney::gotMessage(ofMessage msg) {

}

void MoneyMoney::dragEvent(ofDragInfo dragInfo) {

}

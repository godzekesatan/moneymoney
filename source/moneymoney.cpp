#include "moneymoney.h"

void MoneyMoney::setup() {
  map = reader.ReadMap("data/map.json");
  for (auto sprite : map) {
    images[sprite.filename].loadImage(sprite.filename);
    images[sprite.filename].getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
  }
}

void MoneyMoney::update() {
  if (ofGetKeyPressed(OF_KEY_LEFT)) {
    position.x -= 1;
  }
  if (ofGetKeyPressed(OF_KEY_RIGHT)) {
    position.x += 1;
  }
  if (ofGetKeyPressed(OF_KEY_UP)) {
    position.y -= 1;
  }
  if (ofGetKeyPressed(OF_KEY_DOWN)) {
    position.y += 1;
  }
  if (ofGetKeyPressed('=')) {
    scale *= 1.01;
  }
  if (ofGetKeyPressed('-')) {
    scale /= 1.01;
  }
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

}

void MoneyMoney::keyReleased(int key) {

}

void MoneyMoney::mouseMoved(int x, int y) {

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

#include "moneymoney.h"

void MoneyMoney::setup() {
  ofSetVerticalSync(true);
  // Read map and character data before OpenFrameworks switches the working directory to 'data'.
  map = reader.ReadMap("data/map.json");
  characters = characterReader.ReadCharacters("data/characters.json");

  for (auto sprite : map) {
    images[sprite.filename].loadImage(sprite.filename);
    images[sprite.filename].getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
  }
  
  editMode = false;
  currentTime = 0;
  endTime = 20;
  pause = false;
  mouse_position = ofVec2f(ofGetWidth(), ofGetHeight()) / 2.0;
}

void MoneyMoney::update() {
  
  if (!pause) {
    currentTime += 1.0/60.0;
    if (currentTime > endTime) {
      currentTime = endTime;
    }
  }
  
  ofVec2f d((mouse_position.x - ofGetWidth() / 2.0) / ofGetWidth(),
            (mouse_position.y - ofGetHeight() / 2.0) / ofGetHeight());
  ofVec2f e = 0.8 * 0.5 * d / max(abs(d.x), abs(d.y));
  if (mouse_position.x < 0.1 * ofGetWidth() ||
      mouse_position.x > 0.9 * ofGetWidth() ||
      mouse_position.y < 0.1 * ofGetHeight() ||
      mouse_position.y > 0.9 * ofGetHeight()) {
    position += 50.0 * (d - e);
  }
  scale = ofLerp(scale, scale_target, 0.1);
  
  for (auto &character : characters){
    character.update(currentTime);
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
  ofSetColor(ofColor::white);
  for (auto sprite : map) {
    images[sprite.filename].draw(sprite.x, sprite.y);
  }
  for (auto &character : characters){
    character.draw();
  }
  ofPopMatrix();
  
  if (editMode) {
    double timeline_start = ofGetWidth() * .1;
    double timeline_end = ofGetWidth() * .9;
    double timeline_height = ofGetHeight() *.9;
    double timeline_pos = ofLerp(timeline_start, timeline_end, currentTime/endTime);
    if (drag_timeline) {
      ofSetColor(255, 0, 0);
    } else {
      ofSetColor(255, 255, 255);
    }
    ofLine(timeline_start, timeline_height, timeline_end, timeline_height);
    ofRect(timeline_pos - 5, timeline_height - 5,10,10);
    ofDrawBitmapString(ofToString(currentTime), timeline_pos, timeline_height - 10);
  }
  
}

void MoneyMoney::keyPressed(int key) {
  if (key == '=') {
    scale_target *= 2;
  }
  if (key == '-' && scale_target > 0.125) {
    scale_target /= 2;
  }
  
  if (key == ' ') {
    if (pause) {
      drag_timeline = false;
    }
    pause = !pause;
    editMode = !editMode;
  }
  
  if (key == OF_KEY_LEFT){
    currentTime -= 5;
    if (currentTime < 0){
      currentTime = 0;
    }
  }
  
  if (key == OF_KEY_RIGHT){
    currentTime += 5;
    if (currentTime > endTime) {
      currentTime = endTime;
    }
  }
  
  if (key == 's') {
    CharacterWriter writer;
    writer.WriteCharacters("characters_test.json", characters);
    
  }
}

void MoneyMoney::keyReleased(int key) {

}

void MoneyMoney::mouseMoved(int x, int y) {
  mouse_position = ofVec2f(x, y);
}

void MoneyMoney::mouseDragged(int x, int y, int button) {
  if (drag_timeline) {
    double timeline_start = ofGetWidth() * .1;
    double timeline_end = ofGetWidth() * .9;
    float new_timeline_pos = drag_offset + x;
    currentTime = ofClamp((new_timeline_pos - timeline_start) / (timeline_end - timeline_start), 0.0, 1.0) * endTime;
  }
}

void MoneyMoney::mousePressed(int x, int y, int button) {
  if (editMode) {
    double timeline_start = ofGetWidth() * .1;
    double timeline_end = ofGetWidth() * .9;
    double timeline_height = ofGetHeight() *.9;
    double timeline_pos = ofLerp(timeline_start, timeline_end, currentTime/endTime);
    if (x > timeline_pos - 5 && x < timeline_pos + 5 &&
        y > timeline_height - 5 && y < timeline_height + 5) {
      drag_timeline = true;
      drag_offset = timeline_pos - x;
    }
  }
}

void MoneyMoney::mouseReleased(int x, int y, int button) {
  drag_timeline = false;
}

void MoneyMoney::windowResized(int w, int h) {

}

void MoneyMoney::gotMessage(ofMessage msg) {

}

void MoneyMoney::dragEvent(ofDragInfo dragInfo) {

}

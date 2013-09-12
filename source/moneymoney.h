#ifndef __moneymoney__moneymoney__
#define __moneymoney__moneymoney__

#include <map>

#include "map.h"
#include "mapreader.h"
#include "Character.h"
#include "CharacterReader.h"
#include "ofMain.h"
#include "CharacterWriter.h"

/**
 * The OpenFrameworks application for Money Money.
 */
class MoneyMoney : public ofBaseApp {
public:
  MoneyMoney() = default;
  virtual ~MoneyMoney() = default;

  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

private:
  MapReader reader;
  Map map;
  CharacterReader characterReader;
  vector<Character> characters;
  double currentTime;
  double endTime;
  bool editMode;
  bool pause;
  bool drag_timeline;
  float drag_offset;
  
  double timeline_start;
  double timeline_end;
  double timeline_height;
  
  
  
  std::map<std::string, ofImage> images;
  ofVec2f position, mouse_position;
  float scale = 1.0, scale_target = 1.0;
};

#endif /* defined(__moneymoney__moneymoney__) */

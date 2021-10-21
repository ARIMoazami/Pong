
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  bool in_menu = true;
  bool in_instr_menu = false;
  bool in_pause_menu = false;
  bool collisionCheck(sf::Vector2i, sf::Sprite sprite);

  sf::Text menu_text;
  sf::Text play_option;
  sf::Text instr_option;
  sf::Text score_pl1_text;
  sf::Text score_pl2_text;
  sf::Text force_quit;
  sf::Text pause_menu_text;
  sf::Text pause_yes;
  sf::Text pause_menu;
  sf::Text pause_resume;
  sf::Text instr_text_p1;
  sf::Text instr_text_p2;
  sf::Text instr_pause_text;
  sf::Text menu_return;
  sf::Text instr_menu;



  sf::Font font;


  sf::RenderWindow& window;

  sf::Sprite ball;
  sf::Sprite paddle_pl1;
  sf::Sprite paddle_pl2;
  sf::Sprite menu_background;
  sf::Sprite goal_left;
  sf::Sprite goal_right;


  sf::Texture menu_background_texture;
  sf::Texture ball_texture;
  sf::Texture paddle1_texture;
  sf::Texture paddle2_texture;
  sf::Texture goal_left_texture;
  sf::Texture goal_right_texture;


  bool instr_selected = false;
  bool play_selected = true;
  bool yes_selected = true;
  bool menu_selected = true;
  bool reverse_xaxis = false;
  bool reverse_yaxis = false;


  float speed = 210;

  int score_pl1 = 0;
  int score_pl2 = 0;

};

#endif // PONG_GAME_H

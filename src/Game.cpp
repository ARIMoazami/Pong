
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  //setting background image
  menu_background_texture.loadFromFile("Data/Images/field.jpg");
  menu_background.setTexture(menu_background_texture);


  font.loadFromFile("Data/Fonts/StarcruiserExpanded-0Z14.ttf");

  //creating the text, setting sizes,colour and position
  menu_text.setString("PONG:\n  FOOTBALL");
  menu_text.setFont(font);
  menu_text.setCharacterSize(60);
  menu_text.setFillColor(sf::Color(255,255,255));

  menu_text.setPosition(
    window.getSize().x/2.1 - menu_text.getGlobalBounds().width/2,
    window.getSize().y/10 - menu_text.getGlobalBounds().height/2);

  play_option.setString("ENTER PONG");
  play_option.setFont(font);
  play_option.setCharacterSize(50);
  play_option.setFillColor(sf::Color(255,255,255));

  play_option.setPosition(
    window.getSize().x/5 - play_option.getGlobalBounds().width/2,
    window.getSize().y/3 - play_option.getGlobalBounds().height/2);

  instr_menu.setString("INSTRUCTIONS MENU");
  instr_menu.setFont(font);
  instr_menu.setCharacterSize(50);
  instr_menu.setFillColor(sf::Color(255,255,255));

  instr_menu.setPosition(
    window.getSize().x/2.1 - instr_menu.getGlobalBounds().width/2,
    window.getSize().y/10 - instr_menu.getGlobalBounds().height/2);

  instr_option.setString("INSTRUCTIONS");
  instr_option.setFont(font);
  instr_option.setCharacterSize(50);
  instr_option.setFillColor(sf::Color(255,255,255));

  instr_option.setPosition(
    window.getSize().x/4.1 - instr_option.getGlobalBounds().width/2,
    window.getSize().y/2 - instr_option.getGlobalBounds().height/2);

  instr_text_p1.setString("PLAYER 1 CONTROLS:\n UP - W\nDOWN - S");
  instr_text_p1.setFont(font);
  instr_text_p1.setCharacterSize(22);
  instr_text_p1.setFillColor(sf::Color(255,255,255));

  instr_text_p1.setPosition(
    window.getSize().x/4.1 - instr_text_p1.getGlobalBounds().width/2,
    window.getSize().y/3.6 - instr_text_p1.getGlobalBounds().height/2);

  instr_text_p2.setString("PLAYER 2 CONTROLS:\n UP - I\nDOWN - K");
  instr_text_p2.setFont(font);
  instr_text_p2.setCharacterSize(22);
  instr_text_p2.setFillColor(sf::Color(255,255,255));

  instr_text_p2.setPosition(
    window.getSize().x/1.5 - instr_text_p2.getGlobalBounds().width/2,
    window.getSize().y/3.6 - instr_text_p2.getGlobalBounds().height/2);

  instr_pause_text.setString("PAUSE GAME - P\nWHEN IN THE PAUSE MENU USE"
  "\nTHE KEY 'N' TO SELECT OPTIONS");
  instr_pause_text.setFont(font);
  instr_pause_text.setCharacterSize(22);
  instr_pause_text.setFillColor(sf::Color(255,255,255));

  instr_pause_text.setPosition(
    window.getSize().x/2.1 - instr_pause_text.getGlobalBounds().width/2,
    window.getSize().y/1.7 - instr_pause_text.getGlobalBounds().height/2);

  menu_return.setString("RETURN TO MENU - TAB");
  menu_return.setFont(font);
  menu_return.setCharacterSize(22);
  menu_return.setFillColor(sf::Color(255,255,255));

  menu_return.setPosition(
    window.getSize().x/2 - menu_return.getGlobalBounds().width/2,
    window.getSize().y/2.3 - menu_return.getGlobalBounds().height/2);

  force_quit.setString("Esc key to quit\nat anytime");
  force_quit.setFont(font);
  force_quit.setCharacterSize(35);
  force_quit.setFillColor(sf::Color(255,255,255));

  force_quit.setPosition(
    window.getSize().x/2 - force_quit.getGlobalBounds().width/2,
    window.getSize().y/1.2 - force_quit.getGlobalBounds().height/2);

  score_pl1_text.setFont(font);
  score_pl1_text.setCharacterSize(50);
  score_pl1_text.setFillColor(sf::Color(255,255,255));

  score_pl1_text.setPosition(
    window.getSize().x/1.4 - score_pl1_text.getGlobalBounds().width/2,
    window.getSize().y/7 - score_pl1_text.getGlobalBounds().height/2);

  score_pl2_text.setFont(font);
  score_pl2_text.setCharacterSize(50);
  score_pl2_text.setFillColor(sf::Color(255,255,255));

  score_pl2_text.setPosition(
    window.getSize().x/5 - score_pl2_text.getGlobalBounds().width/2,
    window.getSize().y/7 - score_pl2_text.getGlobalBounds().height/2);

  pause_menu_text.setString("MATCH PAUSED");
  pause_menu_text.setFont(font);
  pause_menu_text.setCharacterSize(60);
  pause_menu_text.setFillColor(sf::Color(255,255,255));

  pause_menu_text.setPosition(
    window.getSize().x/2.1 - pause_menu_text.getGlobalBounds().width/2,
    window.getSize().y/10 - pause_menu_text.getGlobalBounds().height/2);

  pause_yes.setString("YES");
  pause_yes.setFont(font);
  pause_yes.setCharacterSize(40);
  pause_yes.setFillColor(sf::Color(255,255,255));

  pause_yes.setPosition(
    window.getSize().x/2.1 - pause_yes.getGlobalBounds().width/2,
    window.getSize().y/4 - pause_yes.getGlobalBounds().height/10);

  pause_menu.setString("RETURN TO MENU");
  pause_menu.setFont(font);
  pause_menu.setCharacterSize(40);
  pause_menu.setFillColor(sf::Color(255,255,255));

  pause_menu.setPosition(
    window.getSize().x/2.1 - pause_menu.getGlobalBounds().width/2,
    window.getSize().y/3 - pause_menu.getGlobalBounds().height/5);

  pause_resume.setString("RESUME GAME?");
  pause_resume.setFont(font);
  pause_resume.setCharacterSize(50);
  pause_resume.setFillColor(sf::Color(255,255,255));

  pause_resume.setPosition(
    window.getSize().x/2.1 - pause_resume.getGlobalBounds().width/2,
    window.getSize().y/6 - pause_resume.getGlobalBounds().height/10);

  //setting the ball,paddle and goal images, position, rotation and scale
  if(!paddle1_texture.loadFromFile("Data/Images/boot.png"))
  {
    std::cout << "boot pl1 did not load\n";
  }
  paddle_pl1.setTexture(paddle1_texture);
  paddle_pl1.setPosition(150,300);
  paddle_pl1.setScale(0.17,0.17);
  paddle_pl1.rotate(90);

  if(!paddle2_texture.loadFromFile("Data/Images/boot p2.png"))
  {
    std::cout << "boot pl2 did not load\n";
  }
  paddle_pl2.setTexture(paddle2_texture);
  paddle_pl2.setPosition(925,300);
  paddle_pl2.setScale(-0.17,0.17);
  paddle_pl2.rotate(270);

  if(!ball_texture.loadFromFile("Data/Images/football.png"))
  {
    std::cout << "ball did not load\n";
  }

  ball.setTexture(ball_texture);
  ball.setPosition(500,300);
  ball.setScale(0.1,0.1);

  if(!goal_right_texture.loadFromFile("Data/Images/Right.jpg"))
  {
    std::cout << "Collision_right did not load\n";
  }

  goal_right.setTexture(goal_right_texture);
  goal_right.setPosition(1280,0);
  goal_right.setScale(10,10);
  goal_right.rotate(90);

  if(!goal_left_texture.loadFromFile("Data/Images/Left.jpg"))
  {
    std::cout << "Collision left did not load\n";
  }

  goal_left.setTexture(goal_left_texture);
  goal_left.setPosition(45,0);
  goal_left.setScale(10,10);
  goal_left.rotate(90);
  return true;
}

void Game::update(float dt)
{
  if(in_menu or in_pause_menu or in_instr_menu)
  {
    speed = 0;
  }
  else
  {
    // The pong ball movement on different axis
    if (
      (ball.getPosition().x >=
       (window.getSize().x - ball.getGlobalBounds().width)) ||
      (ball.getPosition().x <= 0))
    {
      reverse_xaxis = !reverse_xaxis;
    }
    else if (
      (ball.getPosition().y >=
       (window.getSize().y - ball.getGlobalBounds().width)) ||
      (ball.getPosition().y <= 0))
    {
      reverse_yaxis = !reverse_yaxis;
    }


    // movement changes depending on ball collision
    if (reverse_xaxis)
    {
      ball.move(sf::Vector2f(1.0f * speed * dt, 0));
    }
    else if (!reverse_xaxis)
    {
      ball.move(sf::Vector2f(-1.0f * speed * dt, 0));
    }

    if (reverse_yaxis)
    {
      ball.move(sf::Vector2f(0, 1.0f * speed * dt));
    }
    else if (!reverse_yaxis)
    {
      ball.move(sf::Vector2f(0, -1.0f * speed * dt));
    }

    // collision with the player 1 paddle will reverse the balls movement
    if (ball.getGlobalBounds().intersects(paddle_pl1.getGlobalBounds()))
    {
      reverse_xaxis = !reverse_xaxis;
    }
    else if (ball.getGlobalBounds().intersects(
    paddle_pl1.getGlobalBounds()))
    {
      reverse_yaxis = !reverse_yaxis;
    }
    


    // collision with the player 2 paddle will reverse the balls movement
    if (ball.getGlobalBounds().intersects(paddle_pl2.getGlobalBounds()))
    {
      reverse_xaxis = !reverse_xaxis;
    }
    else if (ball.getGlobalBounds().intersects(paddle_pl2.getGlobalBounds()))
    {
      reverse_yaxis = !reverse_yaxis;
    }

    // collision with goal will add score to player 1 and reset ball position
    if (ball.getGlobalBounds().intersects(goal_left.getGlobalBounds()))
    {
      score_pl1 += 1;
      score_pl1_text.setString(std::to_string(score_pl1));
      ball.setPosition(500, 300);
      speed = 200;
    }

    // collision with goal will add score to player 2 and reset ball position
    if (ball.getGlobalBounds().intersects(goal_right.getGlobalBounds()))
    {
      score_pl2 += 1;
      score_pl2_text.setString(std::to_string(score_pl2));
      ball.setPosition(500, 300);
      speed = 200;
    }

    //Ball speed will increase each time it collides with paddles
    if(ball.getGlobalBounds().intersects(paddle_pl1.getGlobalBounds()))
    {
      speed += 25;
    }

    if(ball.getGlobalBounds().intersects(paddle_pl2.getGlobalBounds()))
    {
      speed += 25;
    }

    // game movement with each key moving the paddles on the Y-axis
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
      paddle_pl1.move(sf::Vector2f(0.f, -10.f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
      paddle_pl1.move(sf::Vector2f(0.f, 10.f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I))
    {
      paddle_pl2.move(sf::Vector2f(0.f, -10.f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
    {
      paddle_pl2.move(sf::Vector2f(0.f, 10.f));
    }

    // stop the both paddles from going out of bounds
    if (
      paddle_pl1.getPosition().y >=
      window.getSize().y - paddle_pl1.getGlobalBounds().height)
    {
      paddle_pl1.move(sf::Vector2f(0.f, -10.f));
    }
    else if (paddle_pl1.getPosition().y <= 0)
    {
      paddle_pl1.move(sf::Vector2f(0.f, 10.f));
    }

    if (
      paddle_pl2.getPosition().y >=
      window.getSize().y - paddle_pl2.getGlobalBounds().height)
    {
      paddle_pl2.move(sf::Vector2f(0.f, -10.f));
    }
    else if (paddle_pl2.getPosition().y <= 0)
    {
      paddle_pl2.move(sf::Vector2f(0.f, 10.f));
    }
  }

}



void Game::render()
{
  //render the menu if the in_menu is set to true
  if (in_menu == true){
    window.draw(menu_background);
    window.draw(menu_text);
    window.draw(play_option);
    window.draw(instr_option);
    window.draw(force_quit);
  }
  else
  {
    in_menu = false;
    window.draw(menu_background);
    window.draw(paddle_pl1);
    window.draw(paddle_pl2);
    window.draw(ball);
    window.draw(goal_left);
    window.draw(goal_right);
    window.draw(score_pl1_text);
    window.draw(score_pl2_text);

  }
  //render the pause menu if in_pause_menu set to true
  if(in_pause_menu == true)
  {
    window.draw(menu_background);
    window.draw(pause_menu_text);
    window.draw(pause_yes);
    window.draw(pause_resume);
    window.draw(pause_menu);
    window.draw(force_quit);
  }
  //render the instructions menu if in_instr_menu set to true
  if(in_instr_menu == true)
  {
    window.draw(menu_background);
    window.draw(force_quit);
    window.draw(instr_menu);
    window.draw(instr_text_p1);
    window.draw(instr_text_p2);
    window.draw(instr_pause_text);
    window.draw(menu_return);
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}


void Game::keyPressed(sf::Event event)
{
  //mapping the keys for the controls on the menu
  if ((event.key.code == sf::Keyboard::A) ||
  (event.key.code == sf::Keyboard::D))

  //menu text will change depending on if certain options are selected
  {
    play_selected = !play_selected;
    instr_selected= !instr_selected;
    if (play_selected)
    {
      play_option.setString("ENTER PONG<<<");
      instr_option.setString("INSTRUCTIONS");
    }
    else
    {
      play_option.setString("ENTER PONG");
      instr_option.setString("INSTRUCTIONS<<<");
    }
  }
  //enter is selected on either option it will take the player to those menus
  else if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected)
    {
      in_menu = false;
      ball.setPosition(500,300);
      speed = 200;
    }
    else if (instr_selected)
    {
      in_instr_menu = true;
    }
  }

  //same controls as above but for the pause menu system
  if ((event.key.code == sf::Keyboard::A) ||
  (event.key.code == sf::Keyboard::D))

  {
    yes_selected = !yes_selected;
    if (yes_selected)
    {
      pause_yes.setString(">YES<");
      pause_menu.setString("RETURN TO MENU");
    }
    else
    {
      pause_yes.setString("YES");
      pause_menu.setString(">RETURN TO MENU<");
    }
  }
  //new key used to select options in the pause menu
  else if (event.key.code == sf::Keyboard::N)
  {
    if (yes_selected)
    {
      in_pause_menu = false;
      speed = 200;
    }
    else if (menu_selected)
    {
      in_menu = true;
      in_pause_menu = false;
      in_instr_menu = false;
    }
  }

  //escape key will close the entire game
  if ((event.key.code == sf::Keyboard::Escape))
  {
    window.close();
  }

//key used to activate the pause menu and stop the ball movement when paused
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
  {
    in_pause_menu = true;
    ball.move(0,0);
    speed = 0;
  }

  //Key used to return to menu when in the instruction menu
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
  {
    in_pause_menu = false;
    in_instr_menu = false;
    in_menu = true;
  }
  
}



/*
** EPITECH PROJECT, 2022
** B-CPP-500-COT-5-1-rtype-prunella.dousso
** File description:
** Intermediate
*/

#ifndef INTERMEDIATE_HPP_
#define INTERMEDIATE_HPP_

#include <cstdio>
#include <memory>
#include <iostream>
#include <string>
#include <iterator>
#include <filesystem>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <enet/enet.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <map>
#include <SFML/Audio.hpp>
#include <condition_variable>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace glob
{
    inline std::map<int, sf::Vector2f> ShipPos = {
        {1, (sf::Vector2f){30.0f, 30.0f}},
        {2, (sf::Vector2f){30.0f, 70.0f}},
        {3, (sf::Vector2f){30.0f, 110.0f}},
        {4, (sf::Vector2f){30.0f, 150.0f}},
    };

    inline std::map<int, std::string> ShipFiles = {
        {1, "assets/graphics/players_enemies/player1.png"},
        {2, "assets/graphics/players_enemies/player2.png"},
        {3, "assets/graphics/players_enemies/player3.png"},
        {4, "assets/graphics/players_enemies/player3.png"},
    };
};

namespace MyComponents
{
    struct Position
    {
        Position(float x, float y) {
            _position = std::make_pair(x, y);
        };
        std::pair<float, float> _position;
    };

    struct Velocity
    {
        float _vx;
        float _vy;
        Velocity(float vx, float vy) : _vx(vx), _vy(vy) {}
        ~Velocity(){};
    };

    struct Drawable
    {
        std::shared_ptr<sf::Texture> texture;
        std::shared_ptr<sf::Sprite> me;
        int state;
        int life;
        int touchable = 1;
        int tcounter = 0;
    };

    struct Controllable
    {
        sf::Keyboard::Key left;
        sf::Keyboard::Key right;
        sf::Keyboard::Key up;
        sf::Keyboard::Key down;
    };

    struct MyId
    {
        size_t myId;
    };

    struct PlayerId
    {
        size_t playerId;
    };
};

#endif /* !INTERMEDIATE_HPP_ */

/*
** EPITECH PROJECT, 2022
** Components types
** File description:
** create different types of components
*/

#ifndef STEP3_HPP_
#define STEP3_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../Component/Registry.hpp"
#include "Client/Display/MyLib.hpp"
#include "Client/includes/Client.hpp"
#include "Client/include/System/Components.hpp"


namespace MyComponents
{
    class DrawSystem
    {
        public:

            /**
             * @brief Construct a new Draw System object
             *
             * @param window
             * @param lib
             */
            DrawSystem(sf::RenderWindow &window, MyLib &lib) : _win(window), _lib(lib){
                texture.loadFromFile("assets/ParallaxAssets/life.png");
                text.loadFromFile("assets/ParallaxAssets/shield.png");
                text1.loadFromFile("assets/ParallaxAssets/back1.png");
                //sf::IntRect rect1(0, 0, 171, 36.4);
                rect = sf::IntRect(0, 0, 171, 36.4);
                sprite = sf::Sprite(texture, rect);
                spr = sf::Sprite(text);
                spr1 = sf::Sprite(text1);
                //sprite = res;
            }

            /**
             * @brief Destroy the Draw System object
             *
             */
            ~DrawSystem(){};
            sf::RenderWindow &_win;
            MyLib &_lib;
            sf::Texture text;
            sf::Texture text1;
            sf::Texture texture;
            sf::IntRect rect;
            sf::Sprite sprite;
            sf::Sprite spr;
            sf::Sprite spr1;
            /**
             * @brief Create a drawable object
             *
             * @param r
             */
            // void drawing_shape(Registry &r) {
            //     auto &drawable = r.get_components<Drawable>();
            //     auto &positions = r.get_components<Position>();
            //     auto &drawable_x = r.get_components<DrawableSprite_x>();
            //     auto &bullet = r.get_components<Bullet_x>();

            //     std::cout << "size = " << bullet.size() << std::endl;
            //     for (size_t i = 0; i < drawable.size() && i < positions.size(); ++ i) {
            //         auto &draw = drawable[i];
            //         auto &pos = positions[i];
            //         if (draw && pos) {
            //             std::cout << "i = " << i << std::endl;
            //             auto shape(draw.value().me);
            //             sf::FloatRect rect1 = (*draw.value().me).getGlobalBounds();
            //             sf::FloatRect rect2;
            //             for (size_t i = 0; i < drawable_x.size() && i < bullet.size(); ++ i) {
            //                 auto &bull = bullet[i];
            //                 auto &enemy = drawable_x[i];
            //                 if (bull && enemy) {
            //                     rect2 = (*bull.value().back).getGlobalBounds();
            //                 }
            //             }
            //             //sf::FloatRect rect2 = (*bull.value().back).getGlobalBounds();
            //             if (rect1.intersects(rect2))
            //             {
            //                 if (draw.value().state == 0)
            //                     draw.value().state = 1;
            //             }
            //             else
            //             {
            //                 if (draw.value().state == 2)
            //                     draw.value().state = 0;
            //             }
            //             if (draw.value().state == 1/* && draw.value().touchable == 1*/)
            //             {
            //                 draw.value().life -= 1;
            //                 if (draw.value().life < 4)
            //                     rect.top += 36.4;
            //                 draw.value().state = 2;
            //             }
            //             float one = positions[i].value()._position.first;
            //             float two = positions[i].value()._position.second;
            //             auto shape_x(sprite);
            //             _lib.setPosition(shape, (sf::Vector2f){one, two});
            //             sprite.setPosition((sf::Vector2f){0, 0});
            //             sprite.setTextureRect(rect);
            //             _win.draw(sprite);
            //             if (draw.value().life >= 0)
            //                 _lib.draw_sprites(_win, shape);
            //             std::cout << "state = " << draw.value().state << std::endl;
            //         }
            //     }
            // }

            void drawing_shape(Registry &r) {
                auto &drawable = r.get_components<Drawable>();
                auto &positions = r.get_components<Position>();

                for (size_t i = 0; i < drawable.size() && i < positions.size(); ++ i) {
                    auto &draw = drawable[i];
                    auto &pos = positions[i];
                    if (draw && pos) {
                        auto shape(draw.value().me);
                        float one = positions[i].value()._position.first;
                        float two = positions[i].value()._position.second;
                        _lib.setPosition(shape, (sf::Vector2f){one, two});
                        _lib.draw_sprites(_win, shape);
                    }
                }
            }

            // void drawing_shape_one(Registry &r) {
            //     auto &drawable = r.get_components<Drawable>();
            //     auto &positions = r.get_components<Position>();
            //     auto &drawable_x = r.get_components<DrawableSprite_x>();
            //     auto &bullet = r.get_components<Bullet_x>();

            //     std::cout << "size = " << bullet.size() << std::endl;
            //     // for (size_t i = 0; i < drawable.size() && i < positions.size(); ++ i) {
            //         auto &draw = drawable[0];
            //         auto &pos = positions[0];
            //         if (draw && pos) {
            //             // std::cout << "i = " << i << std::endl;
            //             auto shape(draw.value().me);
            //             sf::FloatRect rect1 = (*draw.value().me).getGlobalBounds();
            //             sf::FloatRect rect2;
            //             for (size_t i = 0; i < drawable_x.size() && i < bullet.size(); ++ i) {
            //                 auto &bull = bullet[i];
            //                 auto &enemy = drawable_x[i];
            //                 if (bull && enemy) {
            //                     rect2 = (*bull.value().back).getGlobalBounds();
            //                 }
            //             }
            //             //sf::FloatRect rect2 = (*bull.value().back).getGlobalBounds();
            //             if (rect1.intersects(rect2))
            //             {
            //                 if (draw.value().state == 0)
            //                     draw.value().state = 1;
            //             }
            //             else
            //             {
            //                 if (draw.value().state == 2)
            //                     draw.value().state = 0;
            //             }
            //             if (draw.value().state == 1/* && draw.value().touchable == 1*/)
            //             {
            //                 draw.value().life -= 1;
            //                 if (draw.value().life < 4)
            //                     rect.top += 36.4;
            //                 draw.value().state = 2;
            //             }
            //             float one = positions[0].value()._position.first;
            //             float two = positions[0].value()._position.second;
            //             auto shape_x(sprite);
            //             _lib.setPosition(shape, (sf::Vector2f){one, two});
            //             sprite.setPosition((sf::Vector2f){0, 0});
            //             sprite.setTextureRect(rect);
            //             _win.draw(sprite);
            //             if (draw.value().life >= -10)
            //                 _lib.draw_sprites(_win, shape);
            //             std::cout << "state = " << draw.value().state << std::endl;
            //         }
            //     // }
            // }

            void drawing_shape_one(Registry &r) {
                auto &drawable = r.get_components<Drawable>();
                auto &positions = r.get_components<Position>();
                auto &drawable_x = r.get_components<DrawableSprite_x>();
                auto &bullet = r.get_components<Bullet_x>();

                std::cout << "size = " << bullet.size() << std::endl;
                // for (size_t i = 0; i < drawable.size() && i < positions.size(); ++ i) {
                    auto &draw = drawable[0];
                    auto &pos = positions[0];
                    if (draw && pos) {
                        // std::cout << "i = " << i << std::endl;
                        auto shape(draw.value().me);
                        sf::FloatRect rect1 = (*draw.value().me).getGlobalBounds();
                        sf::FloatRect rect2;
                        for (size_t i = 0; i < drawable_x.size() && i < bullet.size(); ++ i) {
                            auto &bull = bullet[i];
                            auto &enemy = drawable_x[i];
                            if (bull && enemy) {
                                rect2 = (*bull.value().back).getGlobalBounds();
                            }
                        }
                        //sf::FloatRect rect2 = (*bull.value().back).getGlobalBounds();
                        if (rect1.intersects(rect2))
                        {
                            if (draw.value().state == 0)
                                draw.value().state = 1;
                        }
                        else
                        {
                            if (draw.value().state == 2)
                                draw.value().state = 0;
                        }
                        if (draw.value().state == 1/* && draw.value().touchable == 1*/)
                        {
                            if (draw.value().touchable == 1)
                                draw.value().life -= 1;
                            else {
                                if (draw.value().tcounter << 3) draw.value().tcounter++;
                                else
                                    draw.value().touchable = 1;
                            }
                            if (draw.value().life < 4 && draw.value().touchable == 1)
                                rect.top += 36.4;
                            draw.value().state = 2;
                        }
                        float one = positions[0].value()._position.first;
                        float two = positions[0].value()._position.second;
                        auto shape_x(sprite);
                        _lib.setPosition(shape, (sf::Vector2f){one, two});
                        spr.setPosition(one - 50, two - 40);
                        sprite.setPosition((sf::Vector2f){0, 0});
                        sprite.setTextureRect(rect);
                        spr1.setScale(4.5, 4);
                        _win.draw(sprite);
                        if (draw.value().touchable == 0)
                            _win.draw(spr);
                        if (draw.value().life >= -4)
                            _lib.draw_sprites(_win, shape);
                        else
                            _win.draw(spr1);
                        std::cout << "state = " << draw.value().state << std::endl;
                    }
                // }
            }

            /*******/

            // void drawing_shape(Registry &r) {
            //     auto &drawable = r.get_components<Drawable>();
            //     auto &positions = r.get_components<Position>();

            //     for (size_t i = 0; i < drawable.size() && i < positions.size(); ++ i) {
            //         auto &draw = drawable[i];
            //         auto &pos = positions[i];
            //         if (draw && pos) {
            //             auto shape(draw.value().me);
            //             float one = positions[i].value()._position.first;
            //             float two = positions[i].value()._position.second;
            //             _lib.setPosition(shape, (sf::Vector2f){one, two});
            //             _lib.draw_sprites(_win, shape);
            //         }
            //     }
            // }

            // void drawing_shape_one(Registry &r) {
            //     auto &drawable = r.get_components<Drawable>();
            //     auto &positions = r.get_components<Position>();

            //     auto &draw = drawable[0];
            //     auto &pos = positions[0];
            //     if (draw && pos) {
            //         auto shape(draw.value().me);
            //         float one = positions[0].value()._position.first;
            //         float two = positions[0].value()._position.second;
            //         _lib.setPosition(shape, (sf::Vector2f){one, two});
            //         _lib.draw_sprites(_win, shape);
            //     }
            // }
    };

    /**
     * @brief System of the other players System
     *
     * @param r
     */
    inline void PlayerPositionSystem(Registry &r) {
        auto &positions = r.get_components<Position>();
        auto const &ids = r.get_components<PlayerId>();

        for ( size_t i = 0; i < positions.size() && i < ids.size(); ++ i) {
            auto const &pos = positions[i];
            auto const &t_ids = ids[i];
            if (pos && t_ids) {
                auto r = t_ids.value().playerId;
                positions[i].value()._position.first = c_connect.OtherPlayers[r].x;
                positions[i].value()._position.second = c_connect.OtherPlayers[r].y;
            }
        }
    }


    class PosiSystem {
        public:
            PosiSystem(NetWorkClient *client) : _client(client){}
            ~PosiSystem() = default;

            /**
             * @brief Update the Position of the Components
             *
             * @param r
             */
            inline void PositionSystem(Registry &r) {
                auto &positions = r.get_components<Position>();
                auto const &velocities = r.get_components<Velocity>();

                for ( size_t i = 0; i < positions.size() && i < velocities.size(); ++ i) {
                    auto const &pos = positions[i];
                    auto const &vel = velocities[i];
                    if (pos && vel) {
                        positions[i].value()._position.first += vel.value()._vx;
                        positions[i].value()._position.second += vel.value()._vy;
                        std::string message_Send = "Position:__x=" + to_string(positions[i].value()._position.first) + "__y=" + to_string(positions[i].value()._position.second);
                        _client->Send_to_Client(message_Send.c_str());
                    }
                }
            }

            NetWorkClient *_client;
    };

    class MoveSystem {
        private:
            double _velo_unit;
        public:

            /**
             * @brief Construct a new Move System object
             *
             * @param events
             */
            MoveSystem(sf::Event &events) : _events(events) {
                _velo_unit = 3;
            };

            /**
             * @brief Destroy the Move System object
             *
             */
            ~MoveSystem(){
                _velo_unit = 3;
            };

            sf::Event &_events;

            /**
             * @brief Update the Position of the Components according to the keys entered
             *
             * @param r
             */
            void VelocitySystem(Registry &r) {
                auto &controllable = r.get_components<Controllable>();
                auto &velocities = r.get_components<Velocity>();

                for (size_t i = 0; i < controllable.size() && i < velocities.size(); ++ i) {
                    auto const &con = controllable[i];
                    auto &vel = velocities[i];
                    if (con && vel) {
                        vel.value()._vx = vel.value()._vy = 0;
                        if (_events.type == sf::Event::KeyPressed) {
                            if (_events.key.code == con.value().left)
                                vel.value()._vx = -_velo_unit;
                            if (_events.key.code == con.value().right)
                                vel.value()._vx = _velo_unit;
                            if (_events.key.code == con.value().up)
                                vel.value()._vy = -_velo_unit;
                            if (_events.key.code == con.value().down)
                                vel.value()._vy = _velo_unit;
                        }
                    }
                }
            }
    };
}

#endif /* !STEP3_HPP_ */

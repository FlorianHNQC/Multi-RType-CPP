/*
** EPITECH PROJECT, 2022
** B-CPP-500-COT-5-1-rtype-prunella.dousso
** File description:
** Main
*/

#include "../include/System/Systems.hpp"
#include "Client/include/CreateEntities.hpp"

extern struct all_connexions c_connect;

void create_component_power_up(Registry &r, MyLib &lib)
{
    const entity_t &pu = r.spawn_entity();
    struct MyComponents::Power_Up drawn = {lib.LoadTexture("assets/ParallaxAssets/shot_boost.png"), lib.create_sprite(drawn.texture), std::make_shared<sf::Clock>(), 0};
    struct MyComponents::Scrolling_x scroll = {5};
    r.add_component<MyComponents::Position>(pu, MyComponents::Position(1000.f, 110.f));
    r.add_component<MyComponents::Power_Up>(pu, drawn);
    r.add_component<MyComponents::Scrolling_x>(pu, scroll);
}

int main(int ac, char **av)
{
    if (ac != 3) {
        printf ("You must to use 2 arguments after binary to run server:\n");
        printf ("Usage:\n");
        printf ("First argument: Port (Number)\n");
        printf ("Second argument: address ip\n");
        return (84);
    }
    else {
        Registry bigBrowser;
        MyLib lib;
        NetWorkClient myClient(atoi(av[1]), av[2], bigBrowser, lib);
        registerComponentType(bigBrowser);
        sf::RenderWindow window(sf::VideoMode(1300, 731), "My window");
        sf::Event event;
        MyComponents::DrawSystem ball(window, lib);
        MyComponents::DrawSpriteSystem parallax(window, lib);
        MyComponents::ScrollingClass scr_class(lib);
        MyComponents::DrawEnemySystem enemy(window, lib);
        MyComponents::MoveEnemy move(lib);
        MyComponents::MoveSystem motion(event);
        MyComponents::PosiSystem _position(&myClient);
        MyComponents::c_connect.alert = false;

        MyComponents::MoveBullet bullet(window, lib);
        MyComponents::DrawPUSystem pow(window, lib);
        MyComponents::MovePU pu(lib);
        MyComponents::MoveEnemyBullet bull_x(window, lib);
        sf::IntRect rect(0, 0, 100, 100);
        sf::IntRect rect2(0, 0, 100, 26);
        sf::IntRect rect3(0, 0, 100, 26);
        sf::IntRect rect4(0, 0, 100, 26);
        sf::IntRect rect5(0, 0, 60, 30);
        sf::IntRect rect6(0, 0, 100, 38);
        MyComponents::Menu menu(window, lib, rect, rect2, rect3, rect4, rect5, rect6);

        myClient.Connection_and_initialize();
        std::unique_lock<std::mutex> lk(MyComponents::c_connect.myMutex);
        std::thread myThread_2(&NetWorkClient::MsgLoop, &myClient);
        MyComponents::c_connect.cv.wait(lk);
        create_component_me(bigBrowser, lib, glob::ShipFiles[MyComponents::c_connect.connected], glob::ShipPos[MyComponents::c_connect.connected]);
        initialize_parallax(bigBrowser, lib);
        create_component_enemy(bigBrowser, lib, "assets/graphics/players_enemies/e_alien.png");
        create_component_enemy2(bigBrowser, lib, "assets/graphics/players_enemies/e_alien.png");
        create_component_power_up(bigBrowser, lib);
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                motion.VelocitySystem(bigBrowser);
                if (event.type == sf::Event::Closed) {
                    window.close();
                    myClient.DeconnectionHost();
                    exit(0);
                }
            }
            window.clear(sf::Color::White);
            /*Systèmes pour faire bouger les entités*/
            if (menu.play != 19 && menu.play != 20) {
            //mode solo
                menu.drawMenu();
            }
            else if (menu.play == 19) {
                _position.PositionSystem(bigBrowser);
                MyComponents::PlayerPositionSystem(bigBrowser);
                scr_class.ScrollingSystem(bigBrowser);
                move.MoveEnemySystem(bigBrowser);
                parallax.drawing_shape(bigBrowser);
                pu.MovePUSystem(bigBrowser);
                enemy.drawing_shape(bigBrowser);
                bullet.drawing_shape(bigBrowser);
                pow.drawing_shape(bigBrowser);
                bull_x.drawing_shape(bigBrowser);
                ball.drawing_shape_one(bigBrowser);
            }
            else if (menu.play == 20) {
                _position.PositionSystem(bigBrowser);
                MyComponents::c_connect.OtherPlayers[myClient.id_others] = sf::Vector2f(myClient.posX_others, myClient.posY_others);
                MyComponents::PlayerPositionSystem(bigBrowser);
                scr_class.ScrollingSystem(bigBrowser);
                move.MoveEnemySystem(bigBrowser);
                parallax.drawing_shape(bigBrowser);
                ball.drawing_shape(bigBrowser);
                enemy.drawing_shape(bigBrowser);
                bullet.drawing_shape(bigBrowser);
                pow.drawing_shape(bigBrowser);
                bull_x.drawing_shape(bigBrowser);
            }
            window.display();
        }
        myThread_2.join();
    }
    return 0;
}

#include <SFML/Graphics.hpp>
#include <SFML/Audio.Hpp>
#include <iostream>
#include "FightSis.cpp"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

using namespace std;
using namespace sf;
int main()
{
   //VARIABLES///////////////////////////////////////////////////////////////////////////////////////////////////////////
    int x = 50;
    int pos = x;
    srand (time(NULL));
	//jugador
	int vida=100;
	int nivel = 0;
	int atk = 40;
	int dfs = 15;
	int spd = 3;
	int xpmax = 10;


	//enemigo
	int vidae=100;
	int atke= 35;
	int dfse = 20;
	int spde = 2;
	int seleccione=0;

	int counter=0;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	subirdenivel (nivel,atk,dfs,spd,xpmax,vida);

    sf::RenderWindow window(sf::VideoMode(600, 600), "THE FUTURE'S FUTURE FUTURE TOMORROW'S EARLIEST ACCESS!");
    //Sprites: inicio//////////////////////////////////////////////////////////////
    sf::Texture Ptexture;
    sf::Sprite PikachuImage;
    if(!Ptexture.loadFromFile("backP.png"))
        cout<<"GG";
    PikachuImage.setTexture(Ptexture);
    PikachuImage.setPosition(30,193);

    sf::Texture tTexture;
    if(!tTexture.loadFromFile("Tri.png"))
        cout<<"GGx3";
    sf::Sprite TriSprite;
    TriSprite.setTexture(tTexture);
    TriSprite.setPosition(360,30);
    TriSprite.setScale(sf::Vector2f(0.5,0.5));

    sf::Texture Bk;
    if(!Bk.loadFromFile("battleB.png"))
        cout<<"GGx2";
    sf::Sprite BkImage(Bk);

    RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(700, 100));
    rectangle.setPosition(0,400);

    CircleShape triangulito (10,3);
    triangulito.rotate(90);
    triangulito.setPosition(x,525);

    RectangleShape vidaR (sf::Vector2f(120,50));
    vidaR.setFillColor(Color::Green);
    vidaR.setPosition(200,200);
    vidaR.setSize(sf::Vector2f(vida,20));



    RectangleShape vidaeR (sf::Vector2f(120,50));
    vidaeR.setFillColor(Color::Green);
    vidaeR.setPosition(300,80);
    vidaeR.setSize(sf::Vector2f(vidae,20));

    //Sprites: Final////////////////////////////////////////////////////////////

    //Musica: Inicio///////////////////////////////////////////////////////////
    sf::Music BM;
    if (!BM.openFromFile("Bmusic.wav"))
        cout<<"gg_musica";
    BM.setLoop(true);
    BM.play();
    //Musica: FIN//////////////////////////////////////////////////////////////

    //Texto: Inicio////////////////////////////////////////////////////////////
    Font font;
    if (!font.loadFromFile("Pixel_font.ttf")){}

    sf::Text log;
    sf::Text Fight;
    sf::Text Defend;
    sf::Text RUN;

    Fight.setFont(font);
    Fight.setString("FIGHT");
    Fight.setCharacterSize(75);
    Fight.setFillColor(Color::White);
    Fight.setPosition(75,485);

    Defend.setFont(font);
    Defend.setString("DEFEND");
    Defend.setCharacterSize(75);
    Defend.setFillColor(Color::White);
    Defend.setPosition(275,485);

    RUN.setFont(font);
    RUN.setString("RUN");
    RUN.setCharacterSize(75);
    RUN.setFillColor(Color::White);
    RUN.setPosition(500,485);

    log.setFont(font);
    log.setString("Un illuminatti aparece!");
    log.setCharacterSize(60);
    log.setFillColor(Color::Black);
    log.setPosition(15,375);
    //TEXTO: FINAL /////////////////////////////////////////////////////////////////////

    while (window.isOpen())
    {
        sf::Event Event;
        {

        do{
                while (window.pollEvent(Event))
                {
                    switch(Event.type)
                   {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if(Event.key.code == sf::Keyboard::Right)
                          {
                              if(pos < 450){
                            pos += 200;
                            triangulito.move(200,0);
                            break;}
                          }
                        else if (Event.key.code == Keyboard::Left)
                        {
                            if (pos > 50){
                            pos -= 200;
                            triangulito.move(-200,0);
                            break;}
                        }
                        else if (Event.key.code == Keyboard::Z)
                        {
                            if (pos == 50){
                                ataque (atk,dfse,vidae);
                                vidaeR.setSize(sf::Vector2f(vidae,20));
                                ataque(atke,dfs,vida);
                                log.setString("Pikachu realizo un ataque!");
                                vidaR.setSize(sf::Vector2f(vida,20));
                                if (vidae>45)
                                   {
                                    vidaeR.setFillColor(Color::Blue);


                                    break;
                                    }
                                if (vidae<45 && vidae > 0)
                                    {
                                    vidaeR.setFillColor(Color::Red);

                                    break;
                                    }
                                if (vidae<=0)
                                    {vidaeR.setPosition(10000,100000);
                                    log.setString("Ganaste !!");
                                    break;}
                                break;}
                            else if(pos == 250){
                                log.setString("JAJA la defensa es DLC");
                                ataque(atke,dfs,vida);
                                 vidaeR.setSize(sf::Vector2f(vidae,20));
                                  vidaR.setSize(sf::Vector2f(vida,20));
                                if (vida>45)
                                   {
                                    vidaR.setFillColor(Color::Blue);


                                    break;
                                    }
                                if (vida<45 && vidae > 0)
                                    {
                                    vidaR.setFillColor(Color::Red);

                                    break;
                                    }
                                if (vida<=0)
                                    {vidaR.setPosition(10000,100000);
                                    log.setString("GG");
                                    break;}
                                break;}
                            else if (pos == 450){
                                window.close();
                                cout << "GAME OVER";
                                break;}
                            }

                            break;
                        }
                    }

        window.setSize(sf::Vector2u(700,600));
        window.clear();
        window.draw(BkImage);
        window.draw(rectangle);
        window.draw(TriSprite);
        window.draw(PikachuImage);
        window.draw(log);
        window.draw(Fight);
        window.draw(Defend);
        window.draw(RUN);
        window.draw(triangulito);
        window.draw(vidaR);
        window.draw(vidaeR);
        window.display();
        }while(vida > 0 && vidae>0);
    }
    }

    return 0;
}

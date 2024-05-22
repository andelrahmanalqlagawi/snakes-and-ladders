#include <SFML/Graphics.hpp>
#include<sfml\Audio.hpp>
#include <sfml\system.hpp>
#include<sfml\network.hpp>
#include<sfml\window.hpp>
#include <iostream>
#include<ctime>
#include<cmath>
#include <string>
#include"menu.h"
#include<sstream>
using namespace sf;
using namespace std;
void SnakeValues(int sizeladder, int sizesnake);
void locationsnake(int size);
void locationladder(int size);
void locationSprite(int n1, Sprite& back);
void locationplayer(int, int);
void hole2animation(Sprite& player_sprite, int& xpos);
void holeanimation(Sprite& player_sprite, int& xpos);
void Rightmove(Sprite& player_sprite, int& xpos, int& ypos);
void Leftmove(Sprite& player_sprite1, int& xpos, int& ypos);
void upmove(Sprite& player_sprite1, int& xpos, int& ypos);
void Drawanimation(RenderWindow&, int, int);
void Draw(RenderWindow&, int, int, Sprite, Sprite, Sprite,  Sprite , Text postion[], int maxplayer, int);
void ChangeTotal(int, RenderWindow&, int, int, Sprite, Sprite, Sprite, Sprite,Sprite, Text postion[], Sound, int, int);
void Refresh(int&, int maxplayer);
void Game(int  sizesnake, int sizeladder, int maxplayer, bool computer);
void levels(int& choose_hard, Sprite Background0);
void Name(int numberofplayer, Sprite Back, Sprite Background0);
void choosenumber_player(int& numberofplayer, RenderWindow& window, RenderWindow& window_play, Sprite Background0, menu menu1);
void Processingto_game(int numberofplayer, int choose_hard);
string fromKtoS(const sf::Keyboard::Key& k);
struct snakeAndLadder {
    int Values = { 0 };
    int ValuesBack = { 0 };
    Sprite  Holesnake_sprite;
    int  X_postion_stopsprite = { 0 };
}Snake[10], ladder[10];
struct  player12
{
    string Name;
    int Total = 1;
    
    Texture texture;
    Sprite  sprites;
    int X_stopanimation = 0;
    int Y_stopanimation = 0;
    bool ingame = { false };
}player[5];
struct  side
{
    Texture texture;
    Sprite sprite;
}Side[7];
int page_number;
int main()
{
    
    bool k = true;
    Music music;
    if (!music.openFromFile("Music4.wav"));
    music.play();
    music.setLoop(true);
    Texture image1, image2;
    if (!image1.loadFromFile("images1.JPG ")) {}
    if (!image2.loadFromFile("images.JPG ")) {}
    RectangleShape rect, rect1;
    rect.setPosition(900, 0);
    rect.setSize(Vector2f(100, 100));
    rect.setTexture(&image1);

    int choose_hard=0, numberofplayer=0;
    while (true)
    {
        for (int i = 1; i < 5; i++)
            player[i].Name = "";
        sf::RenderWindow window(VideoMode(1500, 1000), "SnakeAndLadder", sf::Style::Close);

        Texture background[2];
        background[0].loadFromFile("background00.JPG");
        background[1].loadFromFile("background1.JPG");
        Sprite Background[2];
        Background[0].setTexture((background[0]));
        Background[1].setTexture((background[1]));

        Texture players[3];
        players[0].loadFromFile("vs.png");
        players[1].loadFromFile("Vsss.png");
        players[2].loadFromFile("Human0.png");
        Sprite playerss[20];
        playerss[0].setTexture(players[0]);
        playerss[0].setPosition(Vector2f(320, 200));

        playerss[1].setTexture(players[2]);
        playerss[2].setTexture(players[1]);
        playerss[3].setTexture(players[2]);

        playerss[1].setPosition(Vector2f(690 + 300, 200));
        playerss[2].setPosition(Vector2f(760 + 300, 200));
        playerss[3].setPosition(Vector2f(820 + 300, 200));

        playerss[4].setTexture(players[2]);
        playerss[5].setTexture(players[1]);
        playerss[6].setTexture(players[2]);
        playerss[7].setTexture(players[1]);
        playerss[8].setTexture(players[2]);

        playerss[4].setPosition(Vector2f(200, 550));
        playerss[5].setPosition(Vector2f(270, 550));
        playerss[6].setPosition(Vector2f(330, 550));
        playerss[7].setPosition(Vector2f(400, 550));
        playerss[8].setPosition(Vector2f(470, 550));

        playerss[9].setTexture(players[2]);
        playerss[10].setTexture(players[1]);
        playerss[11].setTexture(players[2]);
        playerss[12].setTexture(players[1]);
        playerss[13].setTexture(players[2]);
        playerss[14].setTexture(players[1]);
        playerss[15].setTexture(players[2]);

        playerss[9].setPosition(Vector2f(690 + 170, 550));
        playerss[10].setPosition(Vector2f(760 + 170, 550));
        playerss[11].setPosition(Vector2f(820 + 170, 550));
        playerss[12].setPosition(Vector2f(890 + 170, 550));
        playerss[13].setPosition(Vector2f(950 + 170, 550));
        playerss[14].setPosition(Vector2f(1010 + 170, 550));
        playerss[15].setPosition(Vector2f(1070 + 170, 550));


        Font font1;
        font1.loadFromFile("font/arial.ttf");
        Text Choose[4];
        for (int i = 0; i < 4; i++)
        {
            Choose[i].setFillColor(sf::Color::Cyan);
            Choose[i].setFont(font1);
            Choose[i].setOutlineColor(Color::Blue);
            Choose[i].setOutlineThickness(9);
            Choose[i].setCharacterSize(40);
        }

        Choose[0].setString("play with computer");
        Choose[0].setPosition(sf::Vector2f(270, 300));
        Choose[01].setString("play with one player");
        Choose[01].setPosition(sf::Vector2f(670 + 300, 300));
        Choose[02].setString("play with Two player");
        Choose[02].setPosition(sf::Vector2f(240, 650));
        Choose[3].setString("play with Three player");
        Choose[03].setPosition(sf::Vector2f(670 + 210, 650));

        Texture back;
        back.loadFromFile("backwindow.png");
        Sprite Back(back);
        Back.setPosition(Vector2f(1250, 800));
        menu menu1(600, 600);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        menu1.moveUp();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        menu1.moveDown();
                        break;
                    }

                    //choose page
                    if (event.key.code == sf::Keyboard::Return) //enter
                    {

                        if (menu1.mainmenupressed() == 0)
                        {
                            window.close();
                            page_number = 0;
                        }
                        if (menu1.mainmenupressed() == 1)
                        {
                            window.close();
                            page_number = 1;
                        }
                        if (menu1.mainmenupressed() == 2)
                        {
                            window.close();
                            page_number = 2;
                        }
                    }


                }

            }
            
          
            window.clear();
            window.draw(Background[0]);
            menu1.draw(window);
            window.draw(rect);
            window.display();
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (k) {

                    music.stop();
                    k = false;
                    window.clear();
                    rect.setTexture(&image2);


                }
                else if (k == false) {
                    music.play();
                    k = true;
                    window.clear();
                    rect.setTexture(&image1);
                }

            }

        }
        if (page_number == 0)
        {
            window.close();
            sf::RenderWindow window_play(VideoMode(1500, 1000), "player", sf::Style::Close);
            while (window_play.isOpen())
            {
                sf::Event event;
                while (window_play.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window_play.close();
                        window.clear();
                        window.draw(Background[0]);
                        menu1.draw(window);
                        window.display();
                    }
                }
                window_play.draw(Background[1]);
                for (int i = 0; i < 16; i++)
                    window_play.draw(playerss[i]);
                for (int i = 0; i < 4; i++)
                    window_play.draw(Choose[i]);
                window_play.draw(Back);
                 choosenumber_player(numberofplayer, window, window_play, Background[0], menu1);
                window_play.display();
            }
        }
        if (page_number == 2)
        {
            window.close();
            break;
        }

        if (page_number == 3)///Easy || Medium || Hard::level///chose level
            levels(choose_hard, Background[0]);
        if (page_number == 4)//Enter Name
            Name(numberofplayer, Back, Background[0]);
        if (page_number == 5)////togame
           Processingto_game(numberofplayer,  choose_hard);
    }
}
void Game(int  sizesnake ,int sizeladder,int maxplayer,bool computer ) {
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "snake and ladder", sf::Style::Close | sf::Style::Resize);
    Texture back1;
    back1.loadFromFile("back11.png");
    Sprite Back1[2];
    Back1[0].setTexture(back1);
    Back1[1].setTexture(back1);
    Back1[0].setPosition(921, 734);

    Back1[1].setPosition(1300, 700);
    if (computer == true)
        player[2].Name = "Computer";
    player[1].texture.loadFromFile("playerplayer1.png");
    player[2].texture.loadFromFile("playerplayer2.png");
    player[3].texture.loadFromFile("playerplayer442.png");
    player[4].texture.loadFromFile("playerplayer4.png");
    for (int i = 1; i < 5; i++)
    {
        
        player[i].sprites.setTextureRect(IntRect(8, 0, 75, 125));
        player[i].sprites.setTexture(player[i].texture);
        player[i].sprites.setPosition(Vector2f(20.0f, 775.0f + 40));
    }
    Side[0].texture.loadFromFile("9.png");
    Side[1].texture.loadFromFile("1side.png");
    Side[2].texture.loadFromFile("2side.png");
    Side[3].texture.loadFromFile("3side.png");
    Side[4].texture.loadFromFile("4side.png");
    Side[5].texture.loadFromFile("5side.png");
    Side[6].texture.loadFromFile("6side.png");
    for (int i = 1; i < 7; i++)
    {
        Side[i].sprite.setTexture(Side[i].texture);
        Side[i].sprite.setPosition(Vector2f(1000.f, 600.f));
    }
    Side[0].sprite.setOrigin(Vector2f(292 / 2, 262 / 2));
    Side[0].sprite.setTexture(Side[0].texture);
    Side[0].sprite.setPosition(Vector2f(1100.f, 700.f));

    Texture hole[2];
    hole[1].loadFromFile("hole1.png");
    hole[0].loadFromFile("202222.png");
    for (int i = 0; i < 10; i++)
    {
        Snake[i].Holesnake_sprite.setTexture(hole[0]);
        ladder[i].Holesnake_sprite.setTexture(hole[1]);
    }

    SnakeValues(sizesnake, sizeladder);

    Texture Back;
    Back.loadFromFile("back.png");
    Sprite back(Back);
    back.setTextureRect(IntRect(80 * 0 + 24, 75 * 1, 65, 75));

    Texture ground[4];
    Sprite Ground[4];
    ground[1].loadFromFile("1.png");
    ground[0].loadFromFile("21.jpg");
    ground[2].loadFromFile("2.jpg");
  
    Ground[1].setTexture(ground[1]);
    Ground[0].setTexture(ground[0]);
    Ground[2].setTexture(ground[2]);
    ground[3].loadFromFile("Home.png");
    Ground[3].setTexture(ground[3]);
    Ground[2].setPosition(Vector2f(880.f, 0.f));
    Ground[1].setPosition(Vector2f(30.f, 90.f));
    Ground[3].setPosition(Vector2f(555.f, 733.f));
    Ground[0].setPosition(Vector2f(0.f, 0.f));

    Texture wins;
    wins.loadFromFile("wins12.png");
    Sprite Wins(wins);
    Wins.setPosition(350, 100);

    //////////////////////
    SoundBuffer Buffer1;
    Buffer1.loadFromFile("Black hole1.wav");
    Sound Black_hole;
    Black_hole.setBuffer(Buffer1);
    ////////////////////
    SoundBuffer Buffer2;
    Buffer2.loadFromFile("move.wav");
    Sound movesound;
    movesound.setBuffer(Buffer2);

    ///////////////
   // SoundBuffer Buffer3;
    Music dice;
    dice.openFromFile("dice1.wav");
    dice.setVolume(100);


    Music wins1;
    wins1.openFromFile("data1.wav");
    wins1.setVolume(100);
    srand(time(0));
    int result;
    Time time1 = milliseconds(30);
    int numberofplayer = 1, sideofdice = 0, time4, time5;
    srand(time(0));
    int x = 0;

    ostringstream s1;
    ostringstream s0;
    ostringstream s2;
    ostringstream s3;
    ostringstream s4;
    ostringstream s5;
    Font font1;
    font1.loadFromFile("font/arial.ttf");

    s0 << "Name: "  << "Score ";
    s1 << player[1].Name << ' '  << player[1].Total;
    s2 << player[2].Name << ' '<<player[2].Total;
    s3 << player[3].Name  <<' '<< player[3].Total;
    s4 << player[4].Name <<' '<< player[4].Total;

    
    Text postion[6];
    for (int i = 0; i < 6; i++)
    {
        postion[i].setFont(font1);
        postion[i].setCharacterSize(55);
        postion[i].setStyle(Text::Bold);
    }
    postion[0].setPosition(1100, 150);
    postion[0].setCharacterSize(65);
    postion[0].setString(s0.str());

    postion[1].setPosition(1100, 250);
    postion[1].setString(s1.str());
    postion[1].setFillColor(Color::Blue);
    postion[2].setPosition(1100, 320);
    postion[2].setString(s2.str());
    postion[2].setFillColor(Color::Red);

    postion[3].setPosition(1100, 400);
    postion[3].setString(s3.str());
    postion[3].setFillColor(Color::Yellow);

    postion[4].setPosition(1100, 460);
    postion[4].setString(s4.str());
   postion[4].setFillColor(Color::Magenta);

   postion[5].setFont(font1);
 postion[5].setFillColor(Color::Black);
 postion[5].setPosition(460, 652);
    while (window.isOpen())
    {
        time4 = time(0);
        time5 = time4;
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            }
        }
        if(computer==true&& numberofplayer==2)
        {
            result = rand() % 6 + 1;
            cout << result << endl;
            cout << player[numberofplayer].Total + result << endl;

            dice.play();
            while (time5 - time4 <= 2) {
                time5 = time(0);
                Side[0].sprite.rotate(100);

                Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1],postion, maxplayer, 0);

            }
            dice.stop();
            sideofdice = result;
            Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2],  Back1[1],postion, maxplayer, sideofdice);
            if (player[numberofplayer].Total + result <= 100)
                for (int i = 0; i < result; i++) {

                    if (player[numberofplayer].Total <= 100) {
                        player[numberofplayer].Total++; float xposition, yposition;
                        xposition = float(player[numberofplayer].sprites.getPosition().x);
                        yposition = float(player[numberofplayer].sprites.getPosition().y);
                       
                         if (numberofplayer == 2) {
                            s1.str("");
                            s1 << player[numberofplayer].Name << " " << player[numberofplayer].Total;
                            postion[2].setString(s1.str());
                        }
                        
                        if (player[numberofplayer].Total == 20 || player[numberofplayer].Total == 40 || player[numberofplayer].Total == 60 || player[numberofplayer].Total == 80 || player[numberofplayer].Total == 100)
                        {
                            while (player[numberofplayer].sprites.getPosition().x >= xposition - 84) {
                                Leftmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);
                                Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1],postion, maxplayer, sideofdice);
                                movesound.play();
                                sleep(time1);
                                movesound.pause();
                            }
                        }
                        else if (player[numberofplayer].Total == 30 || player[numberofplayer].Total == 50 || player[numberofplayer].Total == 70 || player[numberofplayer].Total == 90)
                        {
                            while (player[numberofplayer].sprites.getPosition().x <= xposition + 85) {
                                Rightmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);
                                Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1], postion,maxplayer, sideofdice);
                                movesound.play();
                                sleep(time1);
                                movesound.pause();
                            }

                        }
                        else if (((player[numberofplayer].Total / 10) % 2 == 0 || player[numberofplayer].Total <= 10) && (player[numberofplayer].Total % 10 != 1)) {

                            while (player[numberofplayer].sprites.getPosition().x <= xposition + 85) {
                                Rightmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);
                                Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1],postion, maxplayer, sideofdice);
                                movesound.play();
                                sleep(time1);
                                movesound.pause();
                            }

                        }
                        else if (((player[numberofplayer].Total / 10) % 2 == 1 && player[numberofplayer].Total % 10 != 1)) {
                            while (player[numberofplayer].sprites.getPosition().x >= xposition - 84) {
                                Leftmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);

                                Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1], postion,maxplayer, sideofdice);
                                movesound.play();
                                sleep(time1);
                                movesound.pause();
                            }
                        }
                        else if (player[numberofplayer].Total % 10 == 1) {
                            while (player[numberofplayer].sprites.getPosition().y >= yposition - 83) {
                                upmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);
                                window.clear();
                                Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1], postion,maxplayer, sideofdice);
                                movesound.play();
                                sleep(time1);
                                movesound.pause();
                            }
                        }
                    }

                }
            player[numberofplayer].ingame = true;
           // sleep(microseconds(1));
        }
        if (Mouse::isButtonPressed(Mouse::Left) && (Mouse::getPosition().x > 1219) && (Mouse::getPosition().x < 1472) && (Mouse::getPosition().y < 872) && (Mouse::getPosition().y > 624)) {

            result = rand() % 6 + 1;
            cout << result << endl;
            cout << player[numberofplayer].Total + result << endl;

            dice.play();
            while (time5 - time4 <= 2) {
                time5 = time(0);
                Side[0].sprite.rotate(100);

                Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1],postion, maxplayer, 0);

            }
            dice.stop();

            sideofdice = result;


            Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1], postion,maxplayer, sideofdice);

            if (player[numberofplayer].Total + result <= 100)
                for (int i = 0; i < result; i++) {

                    if (player[numberofplayer].Total <= 99) {
                        player[numberofplayer].Total++;float xposition, yposition;
    xposition = float(player[numberofplayer].sprites.getPosition().x);
    yposition = float(player[numberofplayer].sprites.getPosition().y);
    if (numberofplayer == 1) {
        s1.str("");
        s1 << player[1].Name << " " << player[1].Total;
        postion[1].setString(s1.str());

    }
    else if (numberofplayer == 2) {
        s1.str("");
        s1 << player[numberofplayer].Name << " " << player[numberofplayer].Total;
        postion[2].setString(s1.str());
    }
    else if (numberofplayer == 3) {
        s1.str("");
        s1 << player[numberofplayer].Name << " " << player[numberofplayer].Total;
        postion[3].setString(s1.str());
    }
    else {
        s1.str("");
        s1 << player[numberofplayer].Name << " " << player[numberofplayer].Total;
        postion[4].setString(s1.str());
    }
    if (player[numberofplayer].Total == 20 || player[numberofplayer].Total == 40 || player[numberofplayer].Total == 60 || player[numberofplayer].Total == 80 || player[numberofplayer].Total == 100)
    {
        while (player[numberofplayer].sprites.getPosition().x >= xposition - 84) {
            Leftmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);
            Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1],postion, maxplayer, sideofdice);
            movesound.play();
            sleep(time1);
            movesound.pause();
        }
    }
    else if (player[numberofplayer].Total == 30 || player[numberofplayer].Total == 50 || player[numberofplayer].Total == 70 || player[numberofplayer].Total == 90)
    {
        while (player[numberofplayer].sprites.getPosition().x <= xposition + 85) {
            Rightmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);
            Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1], postion,maxplayer, sideofdice);
            movesound.play();
            sleep(time1);
            movesound.pause();
        }

    }
    else if (((player[numberofplayer].Total / 10) % 2 == 0 || player[numberofplayer].Total <= 10) && (player[numberofplayer].Total % 10 != 1)) {

        while (player[numberofplayer].sprites.getPosition().x <= xposition + 85) {
            Rightmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);
            Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1],postion, maxplayer, sideofdice);
            movesound.play();
            sleep(time1);
            movesound.pause();
        }

    }
    else if (((player[numberofplayer].Total / 10) % 2 == 1 && player[numberofplayer].Total % 10 != 1)) {
        while (player[numberofplayer].sprites.getPosition().x >= xposition - 84) {
            Leftmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);

            Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1],postion, maxplayer, sideofdice);
            movesound.play();
            sleep(time1);
            movesound.pause();
        }
    }
    else if (player[numberofplayer].Total % 10 == 1) {
        while (player[numberofplayer].sprites.getPosition().y >= yposition - 89) {
            upmove(player[numberofplayer].sprites, player[numberofplayer].X_stopanimation, player[numberofplayer].Y_stopanimation);
            window.clear();
            Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1],postion, maxplayer, sideofdice);
            movesound.play();
            sleep(time1);
            movesound.pause();
        }
    }
                    }
                }
            player[numberofplayer].ingame = true;
            sleep(microseconds(100));
        }
        
        ChangeTotal(numberofplayer, window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], back,  Back1[1], postion,Black_hole, maxplayer, sideofdice);
       Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2],Back1[1],postion,maxplayer, sideofdice);
       
        if (numberofplayer == 1) {
            s1.str("");
            s1 << player[1].Name << " " << player[1].Total;
            postion[1].setString(s1.str());

        }
        else if (numberofplayer == 2) {
            s1.str("");
            s1 << player[numberofplayer].Name << " " << player[numberofplayer].Total;
            postion[2].setString(s1.str());
        }
        else if (numberofplayer == 3) {
            s1.str("");
            s1 << player[numberofplayer].Name << " " << player[numberofplayer].Total;
            postion[3].setString(s1.str());
        }
        else {
            s1.str("");
            s1 << player[numberofplayer].Name << " " << player[numberofplayer].Total;
            postion[4].setString(s1.str());
        }
        for (int i = 1; i < 5; ++i) {
            if (player[i].Total == 100) {

              
                Draw(window, sizesnake, sizeladder, Ground[0], Ground[1], Ground[2], Back1[1], postion, maxplayer, sideofdice);
                window.draw(Wins);
                s5.str("");
                s5 << player[i].Name << " is  winner";
                postion[5].setString(s5.str());
                window.draw(postion[5]);
                window.draw(Ground[3]);
                window.draw(Back1[0]);
                window.display();
                wins1.play();
                if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 775 && Mouse::getPosition().x < 870 && Mouse::getPosition().y>813 && Mouse::getPosition().y < 903)
                {
                    window.close();
                    window.clear();
                    page_number = 0;
                }
                if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1143 && Mouse::getPosition().x < 1231 && Mouse::getPosition().y>817 && Mouse::getPosition().y < 903)
                {

                    window.clear();
                    window.close();

                    page_number = 0;
                }

            }
        }
       
        if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1519 && Mouse::getPosition().x < 1609 && Mouse::getPosition().y>780 && Mouse::getPosition().y < 870)
        {

            window.clear();
            window.close();
            page_number = 0;
        }

        Refresh(numberofplayer, maxplayer);
        
    }
}
void Rightmove(Sprite& player_sprite1, int& xpos, int& ypos)
{
    ypos = 4;
    xpos++;
    player_sprite1.move(Vector2f(15.f/2, 0.f));
    xpos = xpos % 6;
    int   c = 100, b = 133;
    if (xpos == 1)
    {
        player_sprite1.setTextureRect(IntRect(22, c * ypos, 58, b));
    }
    else if (xpos == 2)
        player_sprite1.setTextureRect(IntRect(100, c * ypos, 58, b));

    else if (xpos == 4)
        player_sprite1.setTextureRect(IntRect(315, c * ypos, 58, b));
    else if (xpos == 5)
        player_sprite1.setTextureRect(IntRect(405, c * ypos, 58, b));

    else if (xpos == 3 || xpos == 6)

        player_sprite1.setTextureRect(IntRect(484, c * ypos, 58, b));

}
void upmove(Sprite& player_sprite1, int& xpos, int& ypos)
{
    ypos = 2;
    xpos++;
    player_sprite1.move(Vector2f(0.f, -15.f/2));
    xpos = xpos % 6;
    int   c = 70;
    if (xpos == 1)
    {
        player_sprite1.setTextureRect(IntRect(13, c * ypos, 70, 125));
    }
    else if (xpos == 3 || xpos == 2)
        player_sprite1.setTextureRect(IntRect(92, c * ypos, 70, 125));

    else if (xpos == 4)
        player_sprite1.setTextureRect(IntRect(306, c * ypos, 70, 125));
    else if (xpos == 5)
        player_sprite1.setTextureRect(IntRect(400, c * ypos, 70, 125));

    else if (xpos == 6)

        player_sprite1.setTextureRect(IntRect(476, c * ypos, 70, 125));
}
void Leftmove(Sprite& player_sprite1, int& xpos, int& ypos)
{


    ypos = 3;

    xpos++;

    player_sprite1.move(Vector2f(-15.f/2, 0.f));
    xpos = xpos % 6;
    int   c = 90, b = 129;
    if (xpos == 1)
    {
        player_sprite1.setTextureRect(IntRect(22, c * ypos, 58, b));
    }
    else if (xpos == 2)
        player_sprite1.setTextureRect(IntRect(100, c * ypos, 58, b));

    else if (xpos == 4)
        player_sprite1.setTextureRect(IntRect(315, c * ypos, 58, b));
    else if (xpos == 5)
        player_sprite1.setTextureRect(IntRect(405, c * ypos, 58, b));

    else if (xpos == 3 || xpos == 6)

        player_sprite1.setTextureRect(IntRect(484, c * ypos, 58, b));

}
void SnakeValues(int sizesnake, int sizeladder)
{
    for (int i = 0; i < sizesnake; i++)
    {
        switch (i)
        {
        case(0):
        {
            Snake[i].Values = rand() % 10 + 81;
            Snake[i].ValuesBack = rand() % 10 + 21;
            break;
        }
        case(1):
        {
            Snake[1].Values = rand() % 10 + 61;

            Snake[1].ValuesBack = rand() % 10 + 11;

        }
        case(2):
        {
            Snake[2].Values = rand() % 9 + 91;
            Snake[2].ValuesBack = rand() % 10 + 41;
            break;
        }
        case(3):
        {
            Snake[3].Values = rand() % 10 + 31;
            Snake[3].ValuesBack = rand() % 4 + 7;
            break;
        }
        case(4):
        {
            Snake[4].Values = rand() % 9 + 91;
            while (true)
            {
                if (Snake[2].Values == Snake[4].Values || Snake[2].Values % Snake[4].Values == 1 || Snake[4].Values % Snake[2].Values == 1)
                    Snake[2].Values = rand() % 9 + 91;

                else
                    break;
            }
            Snake[4].ValuesBack = rand() % 10 + 71;
            break;
        }
        case(5):
        {
            Snake[5].Values = rand() % 10 + 21;
            while (true)
            {
                if (Snake[5].Values == Snake[0].ValuesBack)
                    Snake[i].Values = rand() % 10 + 21;
                else
                    break;
            }
            Snake[5].ValuesBack = rand() % 4 + 3;
            break;
        }
        case(6):
        {
            Snake[6].Values = rand() % 9 + 91;
            while (true)
            {
                if (Snake[6].Values == Snake[2].Values || Snake[6].Values == Snake[4].Values ||
                    Snake[6].Values % Snake[2].Values == 1 || Snake[2].Values % Snake[6].Values == 1 ||
                    Snake[6].Values % Snake[4].Values == 1 || Snake[4].Values % Snake[6].Values == 1)
                    Snake[6].Values = rand() % 9 + 91;
                else
                    break;
            }
            Snake[6].ValuesBack = rand() % 10 + 61;

            while (true)
            {
                if (Snake[6].ValuesBack == Snake[1].Values)
                    Snake[6].ValuesBack = rand() % 10 + 61;
                else
                    break;
            }
            break;
        }
        case(7):
        {
            Snake[i].Values = rand() % 10 + 51;

            Snake[i].ValuesBack = rand() % 10 + 31;
            while (true)
            {
                if (Snake[7].ValuesBack == Snake[3].Values)
                    Snake[7].ValuesBack = rand() % 10 + 31;
                else
                    break;
            }
            break;
        }

        case(8):
        {
            Snake[i].Values = rand() % 10 + 71;
            while (true)
            {
                if (Snake[8].Values == Snake[4].ValuesBack)
                    Snake[8].Values = rand() % 10 + 71;
                else
                    break;
            }
            Snake[i].ValuesBack = rand() % 10 + 41;
            while (true)
            {
                if (Snake[8].ValuesBack == Snake[2].ValuesBack)
                    Snake[8].ValuesBack = rand() % 10 + 41;
                else
                    break;
            }
            break;
        }
        case(9):
        {
            Snake[i].Values = rand() % 10 + 81;
            while (true)
            {
                if (Snake[9].Values == Snake[0].Values)
                    Snake[9].Values = rand() % 10 + 81;
                else
                    break;
            }
            Snake[i].ValuesBack = rand() % 10 + 11;
            while (true)
            {
                if (Snake[9].ValuesBack == Snake[1].ValuesBack)
                    Snake[9].ValuesBack = rand() % 10 + 11;
                else
                    break;
            }
            break;
        }
        }
    }
    for (int i = 0; i < sizesnake; i++)
        cout << Snake[i].Values << ' ' << Snake[i].ValuesBack << endl;
    cout << "= ============" << endl;
    for (int i = 0; i < sizeladder; i++)
    {

        switch (i)
        {
        case(0):
        {
            ladder[i].Values = rand() % 4 + 7;
            while (true)
            {
                if (ladder[0].Values == Snake[3].ValuesBack)
                    ladder[i].Values = rand() % 4 + 7;
                else
                    break;

            }

            ladder[i].ValuesBack = rand() % 3 + 31;
            while (true)
            {
                if (Snake[3].Values == ladder[0].ValuesBack || Snake[7].ValuesBack == ladder[0].ValuesBack)
                    ladder[i].ValuesBack = rand() % 3 + 31;
                else
                    break;

            }
            break;
        }
        case(1):
        {
            ladder[i].Values = rand() % 4 + 51;
            while (true)
            {
                if (ladder[1].Values == Snake[7].Values)
                    ladder[1].Values = rand() % 4 + 51;
                else
                    break;

            }
            ladder[i].ValuesBack = rand() % 5 + 66;
            while (true)
            {
                if (ladder[i].ValuesBack == Snake[6].ValuesBack || ladder[i].ValuesBack == Snake[1].Values)
                    ladder[i].ValuesBack = rand() % 5 + 66;
                else
                    break;

            }
        }
        case(2):
        {
            ladder[2].Values = rand() % 5 + 24;
            while (true)
            {
                if (ladder[2].Values == Snake[0].ValuesBack || ladder[i].Values == Snake[5].Values)
                    ladder[2].Values = rand() % 5 + 24;
                else
                    break;

            }
            Snake[i].ValuesBack = rand() % 5 + 84;
            while (true)
            {
                if (ladder[2].ValuesBack == Snake[9].Values || ladder[i].ValuesBack == Snake[0].Values)
                    ladder[2].ValuesBack = rand() % 5 + 84;
                else
                    break;

            }
            break;
        }
        case(3):
        {
            if ((Snake[4].ValuesBack != 80) && Snake[8].Values != 80 && (Snake[4].ValuesBack != 79) && (Snake[8].Values != 79)
                && (Snake[4].ValuesBack != 87) && Snake[8].Values != 78)

            {
                ladder[i].Values = rand() % 3 + 78;
                ladder[i].ValuesBack = 100;
            }
            else
            {
                ladder[i].Values = rand() % 10 + 71;
                while (true)
                {
                    if (ladder[i].Values == Snake[8].Values || ladder[i].Values == Snake[4].ValuesBack)
                        ladder[i].ValuesBack = rand() % 10 + 71;
                    else
                        break;

                }
                ladder[i].ValuesBack = rand() % 4 + 91;

                while (true)
                {
                    if (ladder[i].ValuesBack == Snake[4].Values || ladder[i].ValuesBack == Snake[6].Values || ladder[i].ValuesBack == Snake[2].Values)
                    {
                        ladder[i].ValuesBack = rand() % 4 + 91;

                    }
                    else
                        break;

                }
            }

            break;
        }
        case(4):
        {
            ladder[i].Values = rand() % 10 + 11;
            while (true)
            {
                if (ladder[i].Values == 20||ladder[i].Values == Snake[1].ValuesBack || ladder[i].Values == Snake[9].ValuesBack)
                    ladder[i].ValuesBack = rand() % 10 + 11;
                else
                    break;

            }
            
            ladder[i].ValuesBack = rand() % 10 + 41;
            while (true)
            {
                if (ladder[i].ValuesBack == Snake[8].ValuesBack || ladder[i].ValuesBack == Snake[2].ValuesBack)
                    ladder[i].ValuesBack = rand() % 10 + 41;
                else
                    break;
            }
            break;
        }
        }
    }
    for (int i = 0; i < sizeladder; i++)
        cout << ladder[i].Values << ' ' << ladder[i].ValuesBack << endl;
    cout << "= ============" << endl;

    locationsnake(sizesnake);
    locationladder(sizeladder);
}
void locationladder(int size)
{
    for (int i = 0; i < size; i++)
    {
        float Xpostion = 0, Ypostion = 0;
        int Result;
        if (ladder[i].Values > 0 && ladder[i].Values < 11)
        {
            Ypostion = 85 * 10;
            Xpostion = float(50 + 85 * (ladder[i].Values - 1) - 14);
        }
        else if (ladder[i].Values % 90 <= 9 && ladder[i].Values % 90 > 0)
        {
            Result = ladder[i].Values % 90;
            Ypostion = 85;
            Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
        }
        else if (ladder[i].Values % 80 <= 10 && ladder[i].Values % 80 > 0)
        {
            Result = ladder[i].Values % 80;
            Ypostion = 85 * 2;
            Xpostion = float(50 + 85 * (Result - 1) - 14);
        }
        else if (ladder[i].Values % 70 <= 10 && ladder[i].Values % 70 > 0)
        {
            Result = ladder[i].Values % 70;
            Ypostion = 85 * 3;
            Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
        }
        else if (ladder[i].Values % 60 <= 10 && ladder[i].Values % 60 > 0)
        {
            Result = ladder[i].Values % 60;
            Ypostion = 85 * 4;
            Xpostion = float(50 + 85 * (Result - 1) - 14);
        }
        else if (ladder[i].Values % 50 <= 10 && ladder[i].Values % 50 > 0)
        {
            Result = ladder[i].Values % 50;
            Ypostion = 85 * 5;
            Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
        }
        else if (ladder[i].Values % 40 <= 10 && ladder[i].Values % 40 > 0)
        {
            Result = ladder[i].Values % 40;
            Ypostion = 85 * 6;
            Xpostion = float(50 + 85 * (Result - 1) - 14);
        }
        else if (ladder[i].Values % 30 <= 10 && ladder[i].Values % 30 > 0)
        {
            Result = ladder[i].Values % 30;
            Ypostion = 85 * 7;
            Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
        }
        else if (ladder[i].Values % 20 <= 10 && ladder[i].Values % 20 > 0)
        {
            Result = ladder[i].Values % 20;
            Ypostion = 85 * 8;
            Xpostion = float(50 + 85 * (Result - 1) - 14);
        }
        else if (ladder[i].Values % 10 <= 10 && ladder[i].Values % 10 > 0)
        {
            Result = ladder[i].Values % 10;
            if (ladder[i].Values == 20)
            {
                Ypostion = 85 * 9;
                Xpostion = float(50 - 14);
            }
            else
            {
                Ypostion = 85 * 9;
                Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
            }
        }
        ladder[i].Holesnake_sprite.setPosition(Xpostion - 13, Ypostion + 10);
    }
}
void locationsnake(int size)
{
    for (int i = 0; i < size; i++)
    {
        float Ypostion = 0, Xpostion = 0;
        int Result;
        if (Snake[i].Values > 0 && Snake[i].Values < 11)
        {
            Ypostion = 85 * 10;
            Xpostion = float(50 + 85 * (Snake[i].Values - 1) - 14);
        }
        else if (Snake[i].Values % 90 <= 9 && Snake[i].Values % 90 > 0)
        {
            Result = Snake[i].Values % 90;
            Ypostion = 85;
            Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
        }
        else if (Snake[i].Values % 80 <= 10 && Snake[i].Values % 80 > 0)
        {
            Result = Snake[i].Values % 80;
            Ypostion = 85 * 2;
            Xpostion = float(50 + 85 * (Result - 1) - 14);
        }
        else if (Snake[i].Values % 70 <= 10 && Snake[i].Values % 70 > 0)
        {
            Result = Snake[i].Values % 70;
            Ypostion = 85 * 3;
            Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
        }
        else if (Snake[i].Values % 60 <= 10 && Snake[i].Values % 60 > 0)
        {
            Result = Snake[i].Values % 60;
            Ypostion = 85 * 4;
            Xpostion = float(50 + 85 * (Result - 1) - 14);
        }
        else if (Snake[i].Values % 50 <= 10 && Snake[i].Values % 50 > 0)
        {
            Result = Snake[i].Values % 50;
            Ypostion = 85 * 5;
            Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
        }
        else if (Snake[i].Values % 40 <= 10 && Snake[i].Values % 40 > 0)
        {
            Result = Snake[i].Values % 40;
            Ypostion = 85 * 6;
            Xpostion = float(50 + 85 * (Result - 1) - 14);
        }
        else if (Snake[i].Values % 30 <= 10 && Snake[i].Values % 30 > 0)
        {
            Result = Snake[i].Values % 30;
            Ypostion = 85 * 7;
            Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
        }
        else if (Snake[i].Values % 20 <= 10 && Snake[i].Values % 20 > 0)
        {
            Result = Snake[i].Values % 20;
            Ypostion = 85 * 8;
            Xpostion = float(50 + 85 * (Result - 1) - 14);
        }
        else if (Snake[i].Values % 10 <= 10 && Snake[i].Values % 10 >= 0)
        {
            Result = Snake[i].Values % 10;
            if (Snake[i].Values == 20)
            {
                Ypostion = 85 * 9;
                Xpostion = float(50 - 14);
            }
            else
            {
                Ypostion = 85 * 9;
                Xpostion = float(50 + 85 * (abs(Result - 10)) - 14);
            }
        }
        Snake[i].Holesnake_sprite.setPosition(Xpostion, Ypostion);
    }
}
void locationplayer(int number, int k)
{
    int Result, c = 71;
    if (number > 0 && number < 11)

    {
        player[k].sprites.setPosition(Vector2f(float(50 + 85 * (number - 1) - 14), float(c * 10 + 60)));
    }
    else if (number % 90 <= 10 && number % 90 > 0)
    {
        Result = number % 90;
        if (number == 100)
            player[k].sprites.setPosition(Vector2f(float(50), float(c - 15)));
        else
            player[k].sprites.setPosition(Vector2f(float(50 + 85 * (abs(Result - 10)) - 14), float(c - 15)));
    }
    else if (number % 80 <= 10 && number % 80 > 0)
    {
        Result = number % 80;

        player[k].sprites.setPosition(Vector2f(float(50 + 85 * (Result - 1) - 14), float(c * 2 - 10)));
    }
    else if (number % 70 <= 10 && number % 70 > 0)
    {
        Result = number % 70;

        player[k].sprites.setPosition(Vector2f(float(50 + 85 * (abs(Result - 10)) - 14), float(c * 3 + 5)));
    }
    else if (number % 60 <= 10 && number % 60 > 0)
    {
        Result = number % 60;

        player[k].sprites.setPosition(Vector2f(float(50 + 85 * (Result - 1) - 14), float(c * 4 + 22)));
    }

    else if (number % 50 <= 10 && number % 50 > 0)
    {
        Result = number % 50;

        player[k].sprites.setPosition(Vector2f(float(50 + 85 * (abs(Result - 10)) - 14), float(c * 5 + 30)));
    }
    else if (number % 40 <= 10 && number % 40 > 0)
    {
        Result = number % 40;

        player[k].sprites.setPosition(Vector2f(float(50 + 85 * (Result - 1) - 14), float(c * 6 + 45)));
    }

    else if (number % 30 <= 10 && number % 30 > 0)
    {
        Result = number % 30;

        player[k].sprites.setPosition(Vector2f(float(50 + 85 * (abs(Result - 10)) - 14), float(c * 7 + 50)));
    }
    else if (number % 20 <= 10 && number % 20 > 0)
    {
        Result = number % 20;

        player[k].sprites.setPosition(Vector2f(float(50 + 85 * (Result - 1) - 14), float(c * 8 + 50)));
    }


    else if (number % 10 <= 10 && number % 10 > 0)
    {
        Result = number % 10;
        if (number == 20)
            player[k].sprites.setPosition(Vector2f(float(50 - 14), float(c * 9 + 50)));
        else
            player[k].sprites.setPosition(Vector2f(float(50 + 85 * (abs(Result - 10)) - 14), float(c * 9 + 50)));
    }


}
void locationSprite(int n1, Sprite& back)
{
    int Result, c = 80;
    if (n1 > 0 && n1 < 11)

    {
        back.setPosition(Vector2f(float(20 + 90 * (n1 - 1) - 14), float(c * 10 + 60)));
    }
    else if (n1 % 90 <= 10 && n1 % 90 > 0)
    {
        Result = n1 % 90;
        if (n1 == 100)
            back.setPosition(Vector2f(float(50), float(c - 15)));
        else
            back.setPosition(Vector2f(float(20 + 90 * (abs(Result - 10)) - 14), float(c + 10)));
    }
    else if (n1 % 80 <= 10 && n1 % 80 > 0)
    {
        Result = n1 % 80;

        back.setPosition(Vector2f(float(20 + 90 * (Result - 1) - 14), float(c * 2 + 10)));
    }
    else if (n1 % 70 <= 10 && n1 % 70 > 0)
    {
        Result = n1 % 70;

        back.setPosition(Vector2f(float(20 + 90 * (abs(Result - 10)) - 14), float(c * 3 + 5)));
    }
    else if (n1 % 60 <= 10 && n1 % 60 > 0)
    {
        Result = n1 % 60;

        back.setPosition(Vector2f(float(20 + 90 * (Result - 1) - 14), float(c * 4 + 22)));
    }
    else if (n1 % 50 <= 10 && n1 % 50 > 0)
    {
        Result = n1 % 50;

        back.setPosition(Vector2f(float(20 + 90 * (abs(Result - 10)) - 14), float(c * 5 + 30)));
    }
    else if (n1 % 40 <= 10 && n1 % 40 > 0)
    {
        Result = n1 % 40;

        back.setPosition(Vector2f(float(0 + 90 * (Result - 1) - 14), float(c * 6 + 45)));
    }
    else if (n1 % 30 <= 10 && n1 % 30 > 0)
    {
        Result = n1 % 30;

        back.setPosition(Vector2f(float(20 + 90 * (abs(Result - 10)) - 14), float(c * 7 + 50)));
    }
    else if (n1 % 20 <= 10 && n1 % 20 > 0)
    {
        Result = n1 % 20;

        back.setPosition(Vector2f(float(20 + 90 * (Result - 1) - 14), float(c * 8 + 50)));
    }
    else if (n1 % 10 <= 10 && n1 % 10 > 0)
    {
        Result = n1 % 10;
        if (n1 == 20)
            back.setPosition(Vector2f(float(20 - 14), float(c * 9 + 50)));
        else
            back.setPosition(Vector2f(float(20 + 90 * (abs(Result - 10)) - 14), float(c * 9 + 50)));
    }
}
void hole2animation(Sprite& player_sprite, int& xpos)
{
    xpos %= 7;
    player_sprite.setTextureRect(IntRect(float(xpos * 62.48f), 0, 65, 100));
    xpos++;
}
void holeanimation(Sprite& player_sprite, int& xpos)
{
    xpos %= 4;
    player_sprite.setTextureRect(IntRect(xpos * 100, 0, 97, 100));
    xpos++;
}
void Drawanimation(RenderWindow& window0, int sizesnake, int sizeladder) {
    for (int i = 0; i < sizesnake; i++)
    {
        hole2animation(Snake[i].Holesnake_sprite, Snake[i].X_postion_stopsprite);
        window0.draw(Snake[i].Holesnake_sprite);
    }
    for (int i = 0; i < sizeladder; i++)
    {
        holeanimation(ladder[i].Holesnake_sprite, ladder[i].X_postion_stopsprite);
        window0.draw(ladder[i].Holesnake_sprite);
    }

}
void Draw(RenderWindow& window0, int sizesnake, int sizeladder, Sprite ground0, Sprite ground, Sprite ground1,Sprite Back1,Text postion[], int maxplayer, int numberside)
{
    window0.clear();
    window0.draw(ground0);
    window0.draw(ground1);
    window0.draw(ground);
    Drawanimation(window0, sizesnake, sizeladder);
    for (int i = 0; i <= maxplayer; i++)
    {
        window0.draw(player[i].sprites);
        window0.draw(postion[i]);
    }
    window0.draw(Back1);
    window0.draw(Side[numberside].sprite);
    window0.display();
}
void ChangeTotal(int k, RenderWindow& window, int sizesnake, int sizeladder, Sprite ground0, Sprite ground, Sprite ground1, Sprite back, Sprite Back1,Text postion[], Sound sound, int maxplayer, int numberside)
{
    Time time2 = milliseconds(590);
    for (int l = 0; l < sizesnake; l++)
        if (player[k].Total == Snake[l].Values)
        {
            locationSprite(Snake[l].ValuesBack, back);
            swap(Snake[l].ValuesBack, Snake[l].Values);
            locationsnake(l + 1);
            for (int i = 1; i <= 2; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    sound.play();
                    back.setTextureRect(IntRect(80 * j + 24, 75 * i - 10, 65, 75));
                    window.clear();
                    window.draw(ground0);
                    window.draw(ground1);
                    window.draw(ground);
                    Drawanimation(window, sizesnake, sizeladder);
                    window.draw(back);
                    for (int i = 1; i <= maxplayer; i++)
                    {
                        if (k == i)
                            continue;
                        else
                            window.draw(player[i].sprites);
                    }
                    window.draw(Side[numberside].sprite);
                    window.display();
                    sleep(time2);
                    sound.pause();
                }
            }
            window.clear();
            swap(Snake[l].Values, Snake[l].ValuesBack);
            locationsnake(l + 1);
            locationplayer(Snake[l].ValuesBack, k);
            player[k].Total = Snake[l].ValuesBack;
            cout << player[k].Total << endl;
            Draw(window, sizesnake, sizeladder, ground0, ground, ground1, Back1,postion, maxplayer, numberside);
        }
    for (int l = 0; l < sizeladder; l++)
        if (player[k].Total == ladder[l].Values)
        {
            locationSprite(ladder[l].ValuesBack, back);
            swap(ladder[l].ValuesBack, ladder[l].Values);
            locationladder(l);
            for (int i = 1; i <= 2; i++)
                for (int j = 0; j < 4; j++)
                {
                    sound.play();
                    back.setTextureRect(IntRect(80 * j + 24, 75 * i - 10, 65, 75));
                    window.clear();
                    window.draw(ground0);
                    window.draw(ground1);
                    window.draw(ground);
                    Drawanimation(window, sizesnake, sizeladder);
                    window.draw(back);
                    for (int i = 1; i <= maxplayer; i++)
                    {
                        if (k == i)
                            continue;
                        else
                            window.draw(player[i].sprites);
                    }
                    window.draw(Side[numberside].sprite);
                    window.display();
                    sleep(time2);
                    sound.pause();
                }
            window.clear();
            swap(ladder[l].Values, ladder[l].ValuesBack);
            locationladder(l);
            locationplayer(ladder[l].ValuesBack, k);
            player[k].Total = ladder[l].ValuesBack;
            cout << player[k].Total << endl;
            for (int i = 1; i < 5; i++)
                player[i].sprites.setTextureRect(IntRect(8, 0, 75, 125));
            Draw(window, sizesnake, sizeladder, ground0, ground, ground1,Back1,postion, maxplayer, numberside);
        }
}
void Refresh(int& k, int maxplayer)
{
    if (player[k].ingame == true)
        k++;
    if (k == maxplayer + 1)
    {
        k = 1;
        for (int l = 1; l <= maxplayer; l++)
            player[l].ingame = false;
    }
}
string fromKtoS(const sf::Keyboard::Key& k) {
    string ret;
    switch (k) {

    case sf::Keyboard::A:

        ret = "A";
        break;
    case sf::Keyboard::B:

        ret = "B";
        break;
    case sf::Keyboard::C:

        ret = "C";
        break;
    case sf::Keyboard::D:

        ret = "D";
        break;
    case sf::Keyboard::E:

        ret = "E";
        break;
    case sf::Keyboard::F:

        ret = "F";
        break;
    case sf::Keyboard::G:

        ret = "G";
        break;
    case sf::Keyboard::H:

        ret = "H";
        break;
    case sf::Keyboard::I:

        ret = "I";
        break;
    case sf::Keyboard::J:

        ret = "J";
        break;
    case sf::Keyboard::K:

        ret = "K";
        break;
    case sf::Keyboard::L:

        ret = "L";
        break;
    case sf::Keyboard::M:

        ret = "M";
        break;
    case sf::Keyboard::N:

        ret = "N";
        break;
    case sf::Keyboard::O:

        ret = "O";
        break;
    case sf::Keyboard::P:

        ret = "P";
        break;
    case sf::Keyboard::Q:

        ret = "Q";
        break;
    case sf::Keyboard::R:

        ret = "R";
        break;
    case sf::Keyboard::S:

        ret = "S";
        break;
    case sf::Keyboard::T:

        ret = "T";
        break;
    case sf::Keyboard::U:

        ret = "U";
        break;
    case sf::Keyboard::V:

        ret = "V";
        break;
    case sf::Keyboard::W:

        ret = "W";
        break;
    case sf::Keyboard::X:

        ret = "X";
        break;
    case sf::Keyboard::Y:

        ret = "Y";
        break;
    case sf::Keyboard::Z:

        ret = "Z";
        break;
    case sf::Keyboard::Escape:

        ret = "";
        break;
  
    case sf::Keyboard::SemiColon:

        ret = ";";
        break;
    case sf::Keyboard::Comma:

        ret = ".";
        break;
    case sf::Keyboard::Space:

        ret = " ";
        break;
    case sf::Keyboard::Return:

        ret = "";
        break;
    case sf::Keyboard::BackSpace:

        ret = " ";
        break;
    case sf::Keyboard::End:

        ret = " ";
        break;
    case sf::Keyboard::Numpad0:

        ret = "0";
        break;
    case sf::Keyboard::Numpad1:

        ret = "1";
        break;
    case sf::Keyboard::Numpad2:

        ret = "2";
        break;
    case sf::Keyboard::Numpad3:

        ret = "3";
        break;
    case sf::Keyboard::Numpad4:

        ret = "4";
        break;
    case sf::Keyboard::Numpad5:

        ret = "5";
        break;
    case sf::Keyboard::Numpad6:

        ret = "6";
        break;
    case sf::Keyboard::Numpad7:

        ret = "7";
        break;
    case sf::Keyboard::Numpad8:

        ret = "8";
        break;
    case sf::Keyboard::Numpad9:

        ret = "9";
        break;
    default:
        break;
    }
    return ret;
}
void levels(int & choose_hard,Sprite Background0) {

    sf::RenderWindow window_play(VideoMode(1500, 1000), "Easy||Medium||Hard ::level", sf::Style::Close | sf::Style::Resize);

    Texture box;
    box.loadFromFile("box.png");
    Sprite Box[3];
    for (int i = 0; i < 3; i++)
        Box[i].setTexture(box);
    Box[0].setPosition(Vector2f(800, 300));
    Box[1].setPosition(Vector2f(800, 500));
    Box[2].setPosition(Vector2f(800, 700));
    Texture nice[3];
    nice[0].loadFromFile("blue_mark.png");
    nice[1].loadFromFile("green_mark.png");
    nice[2].loadFromFile("yellow_mark.png");
    Sprite Nice[3];
    for (int i = 0; i < 3; i++)
        Nice[i].setTexture(nice[i]);
    Nice[0].setPosition(Vector2f(800, 300));
    Nice[1].setPosition(Vector2f(800, 500));
    Nice[2].setPosition(Vector2f(800, 700));


    Font font2;
    font2.loadFromFile("font/arial.ttf");
    Text Chooses[5];
    for (int i = 0; i < 4; i++)
    {
        Chooses[i].setFont(font2);
        Chooses[i].setCharacterSize(50);
        Chooses[i].setOutlineThickness(9);
        Chooses[i].setOutlineColor(Color::Blue);
    }
    Chooses[3].setCharacterSize(80);
    Chooses[3].setPosition(Vector2f(50, 50));
    Chooses[3].setString(" Click the circle next to it that you want");
    Chooses[3].setOutlineColor(Color::Cyan);
    Chooses[3].setFillColor(Color::Magenta);
    Chooses[0].setPosition(Vector2f(270, 300));
    Chooses[1].setPosition(Vector2f(270, 500));
    Chooses[2].setPosition(Vector2f(270, 700));
    Chooses[0].setString(" EasY");
    Chooses[1].setString("Medium ");
    Chooses[2].setString("Hard ");
    Chooses[4].setPosition(Vector2f(270, 300));
    Chooses[4].setCharacterSize(80);
    Texture back;
    back.loadFromFile("backwindow.png");
    Sprite Back(back);
    Back.setPosition(Vector2f(1250, 800));
    while (window_play.isOpen())
    {
        sf::Event event;
        while (window_play.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_play.close();
                window_play.clear();
                window_play.display();
                page_number = 0;
            }
        }
        window_play.draw(Background0);
        for (int i = 0; i < 4; i++)
            window_play.draw(Chooses[i]);
        window_play.draw(Back);
        for (int i = 0; i < 3; i++)
            window_play.draw(Box[i]);

        window_play.display();

        if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1470 && Mouse::getPosition().x < 1550 && Mouse::getPosition().y>880 && Mouse::getPosition().y < 920)
        {
            window_play.close();
            page_number = 0;
        }
        if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1020 && Mouse::getPosition().x < 1097 && Mouse::getPosition().y>377 && Mouse::getPosition().y < 450)
        {
            window_play.draw(Background0);
            for (int i = 0; i < 4; i++)
                window_play.draw(Chooses[i]);
            window_play.draw(Back);
            for (int i = 0; i < 3; i++)
                window_play.draw(Box[i]);
            window_play.draw(Nice[0]);
            window_play.display();
            sleep(seconds(1.5));
            page_number = 4;
            choose_hard = 0;
            window_play.close();
        }
        if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1020 && Mouse::getPosition().x < 1097 && Mouse::getPosition().y>574 && Mouse::getPosition().y < 651)
        {

            window_play.draw(Background0);
            for (int i = 0; i < 4; i++)
                window_play.draw(Chooses[i]);
            window_play.draw(Back);
            for (int i = 0; i < 3; i++)
                window_play.draw(Box[i]);
            window_play.draw(Nice[1]);
            window_play.display();
            sleep(seconds(1.5));
            page_number = 4;
            choose_hard = 1;
            window_play.close();

        }
        if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1020 && Mouse::getPosition().x < 1097 && Mouse::getPosition().y < 850 && Mouse::getPosition().y > 651)
        {
            window_play.draw(Background0);
            for (int i = 0; i < 4; i++)
                window_play.draw(Chooses[i]);
            window_play.draw(Back);
            for (int i = 0; i < 3; i++)
                window_play.draw(Box[i]);
            window_play.draw(Nice[2]);
            window_play.display();
            sleep(seconds(1.5));
            page_number = 4;
            choose_hard = 2;
            window_play.close();

        }
    }
}
void Name(int numberofplayer, Sprite Back, Sprite Background0)
{
    Font font1;
    font1.loadFromFile("font/arial.ttf");
    Text Choose[2];
    for (int i = 0; i < 2; i++)
        Choose[i].setFont(font1);
    Choose[0].setString(" Click in  Rectangle to Enter Name ");
    Choose[1].setString("and Enter to End");
    Choose[0].setPosition(Vector2f(50, 50));
    Choose[1].setPosition(Vector2f(50, 150));
    Choose[0].setCharacterSize(50);
    Choose[1].setCharacterSize(50);
    Text writes[4], name[4];
    for (int i = 0; i < 4; i++)
    {
        writes[i].setFont(font1);
        name[i].setFont(font1);
        writes[i].setString("Max is 9 Characters");
    }
    name[0].setPosition(450, 290);
    name[1].setPosition(450, 430);
    name[2].setPosition(450, 560);
    name[3].setPosition(450, 720);
    writes[0].setPosition(450, 290);
    writes[1].setPosition(450, 430);
    writes[2].setPosition(450, 560);
    writes[3].setPosition(450, 720);
    Text player2[4];
    for (int i = 0; i < 4; i++)
        player2[i].setFont(font1);
    player2[0].setString("Player 1");
    player2[1].setString("Player 2");
    player2[2].setString("Player 3");
    player2[3].setString("Player 4");

    player2[0].setPosition(60, 290);
    player2[1].setPosition(60, 430);
    player2[2].setPosition(60, 560);
    player2[3].setPosition(60, 720);

    Texture write[4];
    write[0].loadFromFile("011.png");
    write[1].loadFromFile("01222.png");
    write[2].loadFromFile("013.png");
    write[3].loadFromFile("014.png");

    Sprite  player1[4];
    player1[0].setTexture(write[0]);
    player1[1].setTexture(write[1]);
    player1[2].setTexture(write[2]);
    player1[3].setTexture(write[3]);
    player1[0].setPosition(250, 200);
    player1[1].setPosition(270, 350);
    player1[2].setPosition(250, 500);
    player1[3].setPosition(270, 660);
    Texture start;
    start.loadFromFile("startgame.png");
    Sprite Start1(start);
    Start1.setPosition(1019, 200);
    sf::RenderWindow window_play(VideoMode(1500, 1000), "Name", sf::Style::Close);
    while (window_play.isOpen())
    {
        sf::Event event;
        while (window_play.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_play.close();
                window_play.clear();
                window_play.display();
                page_number = 3;
            }
        }
        window_play.draw(Background0);
        window_play.draw(Choose[0]);
        window_play.draw(Start1);
        for (int i = 0; i < numberofplayer; i++)
        {
            window_play.draw(player1[i]);
            window_play.draw(player2[i]);
            window_play.draw(writes[i]);
            window_play.draw(name[i]);
        }
        window_play.draw(Back);

        window_play.display();

        while (Mouse::getPosition().x > 631 && Mouse::getPosition().x < 943 && Mouse::getPosition().y>345 && Mouse::getPosition().y < 417)
        {
            window_play.clear();
            if (numberofplayer == 1)
            {
                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[1].Name += fromKtoS(event.key.code);
                                writes[0].setString(player[1].Name);
                                name[0].setString(player[1].Name);
                                window_play.clear();
                                window_play.draw(Background0);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(Back);
                                window_play.draw(writes[0]);
                                window_play.display();

                            }
                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                        case sf::Keyboard::Escape:
                        case sf::Keyboard::End:

                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }
            }
            else if (numberofplayer == 2)
            {

                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(writes[1]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[1].Name += fromKtoS(event.key.code);
                                writes[0].setString(player[1].Name);
                                name[0].setString(player[1].Name);
                                window_play.clear();
                                window_play.draw(Background0);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(player1[1]);
                                window_play.draw(player2[1]);
                                window_play.draw(writes[1]);
                                window_play.draw(Back);
                                window_play.draw(name[0]);
                                window_play.display();

                            }
                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                        case sf::Keyboard::Escape:
                        case sf::Keyboard::End:
                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }
            }
            else  if (numberofplayer == 3)
            {
                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(player1[2]);
                window_play.draw(player2[2]);
                window_play.draw(writes[1]);
                window_play.draw(writes[2]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[1].Name += fromKtoS(event.key.code);
                                writes[0].setString(player[1].Name);
                                name[0].setString(player[1].Name);
                                window_play.clear();
                                window_play.draw(Background0);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(player1[1]);
                                window_play.draw(player2[1]);
                                window_play.draw(player1[2]);
                                window_play.draw(player2[2]);
                                window_play.draw(writes[1]);
                                window_play.draw(writes[2]);
                                window_play.draw(Back);
                                window_play.draw(name[0]);
                                window_play.display();

                            }
                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                        case sf::Keyboard::Escape:
                        case sf::Keyboard::End:
                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }
            }

            else if (numberofplayer >= 4)
            {
                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(player1[2]);
                window_play.draw(player2[2]);
                window_play.draw(writes[1]);
                window_play.draw(player1[3]);
                window_play.draw(player2[3]);
                window_play.draw(writes[3]);
                window_play.draw(writes[2]);
                window_play.draw(name[0]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[1].Name += fromKtoS(event.key.code);
                                writes[0].setString(player[1].Name);
                                name[0].setString(player[1].Name);
                                window_play.clear();
                                window_play.draw(Background0);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(player1[1]);
                                window_play.draw(player2[1]);
                                window_play.draw(player1[2]);
                                window_play.draw(player2[2]);
                                window_play.draw(writes[1]);
                                window_play.draw(player1[3]);
                                window_play.draw(player2[3]);
                                window_play.draw(writes[3]);
                                window_play.draw(writes[2]);
                                window_play.draw(Back);
                                window_play.draw(name[0]);
                                window_play.display();

                            }
                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }
            }
        }
        while (Mouse::getPosition().x > 631 && Mouse::getPosition().x < 943 && Mouse::getPosition().y>500 && Mouse::getPosition().y < 575)

        {
            if (numberofplayer == 2)
            {

                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(writes[0]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[2].Name += fromKtoS(event.key.code);
                                writes[1].setString(player[2].Name);
                                name[1].setString(player[2].Name);
                                window_play.clear();
                                window_play.draw(Background0);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(player1[1]);
                                window_play.draw(player2[1]);
                                window_play.draw(writes[0]);
                                window_play.draw(Back);

                                window_play.draw(name[1]);
                                window_play.display();

                            }

                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }

            }
            else  if (numberofplayer == 3)
            {
                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(player1[2]);
                window_play.draw(player2[2]);
                window_play.draw(writes[0]);
                  window_play.draw(writes[2]);
                window_play.draw(name[1]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[2].Name += fromKtoS(event.key.code);
                                writes[1].setString(player[2].Name);
                                name[1].setString(player[2].Name);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(player1[1]);
                                window_play.draw(writes[1]);
                                window_play.draw(player2[1]);
                                window_play.draw(player1[2]);
                                window_play.draw(player2[2]);
                                window_play.draw(writes[0]);
                              window_play.draw(writes[2]);
                                window_play.draw(Back);
                                window_play.draw(name[1]);

                                window_play.display();

                            }
                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }
            }
            else if (numberofplayer >= 4)
            {
                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(player1[2]);
                window_play.draw(player2[2]);
                window_play.draw(writes[0]);
                window_play.draw(player1[3]);
                window_play.draw(player2[3]);
                window_play.draw(writes[3]);
                window_play.draw(writes[2]);
                window_play.draw(name[1]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[2].Name += fromKtoS(event.key.code);
                                writes[1].setString(player[2].Name);
                                name[1].setString(player[2].Name);
                                window_play.clear();
                                window_play.draw(Background0);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(player1[1]);
                                window_play.draw(writes[1]);
                                window_play.draw(player2[1]);
                                window_play.draw(player1[2]);
                                window_play.draw(player2[2]);
                                window_play.draw(writes[0]);
                                window_play.draw(player1[3]);
                                window_play.draw(player2[3]);
                                window_play.draw(writes[2]);
                               
                                window_play.draw(Back);
                                window_play.draw(name[1]);
                                window_play.display();

                            }
                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                        case sf::Keyboard::Escape:
                        case sf::Keyboard::End:
                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }
            }
        }
        while (Mouse::getPosition().x > 631 && Mouse::getPosition().x < 943 && Mouse::getPosition().y>631 && Mouse::getPosition().y < 702)
        {
            if (numberofplayer == 3)
            {
                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(player1[2]);
                window_play.draw(player2[2]);
                window_play.draw(writes[1]);
                window_play.draw(writes[0]);
                window_play.draw(name[1]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[3].Name += fromKtoS(event.key.code);
                                name[2].setString(player[3].Name);
                                writes[2].setString(player[3].Name);
                                window_play.clear();
                                window_play.draw(Background0);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(player1[1]);
                                window_play.draw(player2[1]);
                                window_play.draw(player1[2]);
                                window_play.draw(player2[2]);
                                window_play.draw(writes[0]);
                                window_play.draw(writes[1]);
                                window_play.draw(Back);
                                window_play.draw(name[2]);
                                window_play.display();
                            }
                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                        case sf::Keyboard::Escape:
                        case sf::Keyboard::End:
                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }
            }
            else if (numberofplayer >= 4)
            {
                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(player1[2]);
                window_play.draw(player2[2]);
                window_play.draw(writes[0]);
                window_play.draw(player1[3]);
                window_play.draw(player2[3]);
                window_play.draw(writes[3]);
                window_play.draw(writes[1]);
                window_play.draw(Back);
                window_play.display();
                if (Mouse::isButtonPressed(Mouse::Left))
                    while (true)
                    {
                        while (window_play.pollEvent(event))
                            if (event.type == sf::Event::KeyPressed)
                            {
                                player[3].Name += fromKtoS(event.key.code);
                                name[2].setString(player[3].Name);
                                writes[2].setString(player[3].Name);
                                window_play.clear();
                                window_play.draw(Background0);
                                window_play.draw(Choose[0]);
                                window_play.draw(player1[0]);
                                window_play.draw(player2[0]);
                                window_play.draw(player1[1]);
                                window_play.draw(player2[1]);
                                window_play.draw(player1[2]);
                                window_play.draw(player2[2]);
                                window_play.draw(writes[0]);
                                window_play.draw(player1[3]);
                                window_play.draw(player2[3]);
                                window_play.draw(writes[3]);
                                window_play.draw(writes[1]);
                                window_play.draw(Back);
                                window_play.draw(name[2]);
                                window_play.display();

                            }
                        bool h = false;
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Return:
                        case sf::Keyboard::Escape:
                        case sf::Keyboard::End:
                            h = true;
                            break;
                        }
                        if (h == true)
                            break;
                    }
            }
        }
        while (Mouse::getPosition().x > 631 && Mouse::getPosition().x < 943 && Mouse::getPosition().y>790 && Mouse::getPosition().y < 870)
        {

            if (numberofplayer >= 4)
            {
                window_play.clear();
                window_play.draw(Background0);
                window_play.draw(Choose[0]);
                window_play.draw(player1[0]);
                window_play.draw(player2[0]);
                window_play.draw(player1[1]);
                window_play.draw(player2[1]);
                window_play.draw(player1[2]);
                window_play.draw(player2[2]);
                window_play.draw(writes[0]);
                window_play.draw(writes[1]);
                window_play.draw(player1[3]);
                window_play.draw(player2[3]);
                window_play.draw(writes[2]);
                window_play.draw(name[1]);
                window_play.draw(Back);
                window_play.draw(writes[2]);
                window_play.draw(name[0]);
                window_play.draw(name[1]);
                window_play.draw(name[2]);
                window_play.draw(Back);
                window_play.draw(name[3]);
                window_play.display();
            }
            if (Mouse::isButtonPressed(Mouse::Left))
                while (true)
                {
                    while (window_play.pollEvent(event))
                        if (event.type == sf::Event::KeyPressed)
                        {
                            player[4].Name += fromKtoS(event.key.code);
                            name[3].setString(player[4].Name);
                            writes[3].setString(player[4].Name);
                            window_play.clear();
                            window_play.draw(Background0);
                            window_play.draw(Choose[0]);
                            window_play.draw(player1[0]);
                            window_play.draw(player2[0]);
                            window_play.draw(player1[1]);
                            window_play.draw(player2[1]);
                            window_play.draw(player1[2]);
                            window_play.draw(player2[2]);
                            window_play.draw(writes[0]);
                            window_play.draw(player1[3]);
                            window_play.draw(player2[3]);
                            window_play.draw(writes[2]);
                            window_play.draw(writes[1]);
                            window_play.draw(name[0]);
                            window_play.draw(name[1]);
                            window_play.draw(name[2]);
                            window_play.draw(Back);
                            window_play.draw(name[3]);
                            window_play.display();
                        }
                    bool h = false;
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Return:
                    case sf::Keyboard::Escape:
                    case sf::Keyboard::End:
                        h = true;
                        break;
                    }
                    if (h == true)
                        break;
                }
        }
        if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1470 && Mouse::getPosition().x < 1550 && Mouse::getPosition().y>880 && Mouse::getPosition().y < 920)
        {
            window_play.close();
            page_number = 3;
        }
        if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1231 && Mouse::getPosition().x < 1477 && Mouse::getPosition().y>333 && Mouse::getPosition().y < 430)
        {
            window_play.close();
            page_number = 5;
        }
    }
}
void choosenumber_player(int & numberofplayer,RenderWindow & window, RenderWindow & window_play,Sprite Background0, menu menu1)
{
    if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1470 && Mouse::getPosition().x < 1550 && Mouse::getPosition().y>880 && Mouse::getPosition().y < 920)
    {
        window_play.close();
        window.clear();
        window.draw(Background0);
        menu1.draw(window);
        window.display();

    }
    ///upleft

    if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 521 && Mouse::getPosition().x < 760 && Mouse::getPosition().y>280 && Mouse::getPosition().y < 432)
    {
        page_number = 3;
        numberofplayer = 1;
        window_play.clear();
        window_play.close();

    }
    //downleft
    if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 414 && Mouse::getPosition().x < 771 && Mouse::getPosition().y>633 && Mouse::getPosition().y < 784)
    {
        numberofplayer = 3;
        window_play.clear();
        window_play.close();
        page_number = 3;
    }
    //upright
    if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1205 && Mouse::getPosition().x < 1426 && Mouse::getPosition().y>290 && Mouse::getPosition().y < 422)
    {
        numberofplayer = 2;
        window_play.clear();
        window_play.close();
        page_number = 3;

    }
    //down left
    if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x > 1070 && Mouse::getPosition().x < 1552 && Mouse::getPosition().y>632 && Mouse::getPosition().y < 763)
    {
        numberofplayer = 4;
        window_play.clear();
        window_play.close();
        page_number = 3;
    }
}
void Processingto_game(int numberofplayer,int choose_hard)
{
    //bool is computer or no if computer >>true 
    if (numberofplayer == 1 && choose_hard == 0) //computer >>>easy
        Game(5, 5, 2, true);
    else if ((numberofplayer == 1) && choose_hard == 1) //computer >>>m
        Game(6, 4, 2, true);
    else if ((numberofplayer == 1) && choose_hard == 2) //computer >>>hard
        Game(8, 3, 2, true);
    else if ((numberofplayer == 2) && choose_hard == 0) //2player >>>easy
        Game(5, 5, 2, false);
    else if (numberofplayer == 2 && choose_hard == 1) //2player >>>m
        Game(6, 4, 2, false);
    else if ((numberofplayer == 2) && choose_hard == 2) //2player >>>hard
        Game(8, 3, 2, false);
    else if ((numberofplayer == 3) && choose_hard == 0) //3player >>>easy
        Game(5, 5, 3, false);
    else if ((numberofplayer == 3) && choose_hard == 1) //3player<<m
        Game(6, 4, 3, false);
    else if (numberofplayer == 3 && choose_hard == 2) //3player>>hard
        Game(8, 3, 3, false);
    else if ((numberofplayer == 4) && choose_hard == 0) //4player >>>easy
        Game(5, 5, 4, false);
    else if ((numberofplayer == 4) && choose_hard == 1) //4player >>>m
        Game(6, 4, 4, false);
    else if ((numberofplayer == 4) && choose_hard == 2) //4player >hard
        Game(8, 3, 4, false);
}

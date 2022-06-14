#include    "Game.h"
#include    "Background.h"
#include    "Player.h"
#include    "Shaun.h"
#include    "John.h"
#include    "GameBackground.h"
#include    "TitleBackground.h"
#include    "MenuBackground.h"
#include    "TitleButton.h"
#include    "OnePlayerButton.h"
#include    "TwoPlayerButton.h"
#include    "Enemy.h"
#include    "Dart.h"
#include    "Brick.h"
#include    "Sword.h"
#include    "PowerUp.h"
#include    "Pistol.h"
#include    "Coin.h"
#include    <string>
#include    "SpikeShoe.h"
#include    "BrokenWatch.h"
#include    "OldDrink.h"
#include    "ShaunGhost.h"
#include    "JohnGhost.h"
#include    "EndScreen.h"
#include    "Laser.h"
#include    "Block.h"
#include    "AnimatingObject.h"


Game::Game()
	:	window		        (sf::VideoMode::getDesktopMode(),"Dungeon Dash", sf::Style::Titlebar|sf::Style::Close)
	,	gameClock	        ()
    ,   backGround          ()
    ,   objectSprite        ()
    ,   backgroundVector    ()
    ,   playerVector        ()
    ,   GameMode            (0)
    ,   ghostVector         ()
    ,   whatScreen          ()
    ,   buttonVector        ()
    ,   enemyVector         ()
    ,   timeSinceEnemy      ()
    ,   randomStuff         (0)
    ,   player1Pos          ()
    ,   player2Pos          ()
    ,   spawnRateMultiplyer ()
    ,   enemySpawnRate      ()
    ,   powerUpVector       ()
    ,   timeSincePowerUp    ()
    ,   p1                  ()
    ,   p2                  ()
    ,   p1Score             ()
    ,   p2Score             ()
    ,   p1PowerUp           ()
    ,   p2PowerUp           ()
    ,   p1Time              ()
    ,   p2Time              ()
    ,   player1Time         ()
    ,   player2Time         ()
    ,   winner              ()
    ,   mainFont            ()
    ,   gameModeChosen      (false)
    ,   isPlayerOneGhost    (false)
    ,   isPlayerTwoGhost    (false)
    ,   ghostHaveBeenCreated(false)
    ,   endScreenDisplayTime()
    ,   endScreenTimeLimit  (10)
    ,   laserCoolDownTime   ()
    ,   lengthOfLaserCoolDown(10)
    ,   canLaserSpawn          (true)
    ,   gameMusic            ()
    ,	hit						()
    ,	pickUpCoin				()
    ,	ghostHaunting			()
    ,	hitBuffer				()
    ,	pickUpCoinBuffer		()
    ,	ghostHauntingBuffer		()
   



{
    gameMusic.openFromFile("Assets/Audio/ArcadeMusicLoop.wav");
    gameMusic.setLoop(true);
    gameMusic.setVolume(25);
    gameMusic.play();
    
    hitBuffer.loadFromFile("Assets/Audio/Hit.wav");
    pickUpCoinBuffer.loadFromFile("Assets/Audio/CoinPickUp.wav");
    ghostHauntingBuffer.loadFromFile("Assets/Audio/GhostHaunting.wav");

    hit.setBuffer(hitBuffer);
    hit.setLoop(false);

    pickUpCoin.setBuffer(pickUpCoinBuffer);
    pickUpCoin.setLoop(false);

    ghostHaunting.setBuffer(ghostHauntingBuffer);
    ghostHaunting.setLoop(false);
}

void Game::Run()
{
    SetUpGame();

   
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //call update 
        Update();

        //call draw
        Draw();
    }
}

void Game::Draw()
{
    window.clear();
  
    if (whatScreen == "Title")
    {
        backgroundVector[0]->backgroundDraw(window);
        buttonVector[0]->Draw(window);
    }
    if (whatScreen == "Menu")
    {
        backgroundVector[1]->backgroundDraw(window);
        buttonVector[1]->Draw(window);
        buttonVector[2]->Draw(window);
    }
    if (whatScreen == "Game")
    {
        backgroundVector[2]->backgroundDraw(window);

        if (GameMode == 1)
        {
            playerVector[0]->Draw(window);

            window.draw(p1);
            window.draw(p1Score);

            window.draw(p1PowerUp);

            window.draw(p1Time);
        }
        else if (GameMode == 2)
        {
            for (int i = 0; i < playerVector.size();++i)
            {
                playerVector[i]->Draw(window);
            }
            window.draw(p1);
            window.draw(p2);

            window.draw(p1Score);
            window.draw(p2Score);

            window.draw(p1PowerUp);
            window.draw(p2PowerUp);

            window.draw(p1Time);
            window.draw(p2Time);

            if (isPlayerOneGhost)
            {
                ghostVector[0]->Draw(window);
                ghostVector[0]->SetPosition(sf::Vector2f(700, 100));
            }
            if (isPlayerTwoGhost)
            {
                ghostVector[1]->Draw(window);
                ghostVector[1]->SetPosition(sf::Vector2f(500, 100));
            }
        }


        for (int i = 0; i < enemyVector.size(); ++i)
        {
            enemyVector[i]->Draw(window);
        }

        for (int i = 0; i < powerUpVector.size(); ++i)
        {
            powerUpVector[i]->Draw(window);
        }

        for (int i = 0; i < bulletVector.size(); ++i)
        {
            bulletVector[i]->Draw(window);
        }

      

   
   
}
    else if (whatScreen == "EndScreen")
    {
        backgroundVector[3]->backgroundDraw(window);
        window.draw(winner);
        if (GameMode == 2)
            {
            window.draw(p1Score);
            window.draw(p2Score);
            window.draw(p1Time);
            window.draw(p2Time);
            
        }
        else
        {
            window.draw(p1Score);
            window.draw(p1Time);
            

            
           
        }
          
    }
   
    window.display();
}

void Game::Update()
{
    sf::Time deltaTime = gameClock.restart();




    if (whatScreen == "Title")
    {
        TitleScreen();
        buttonVector[0]->Update(deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            whatScreen = buttonVector[0]->getScreenResult();
        }
    }
    else if (whatScreen == "Menu")
    {
        MenuScreen();
        buttonVector[1]->Update(deltaTime);
        buttonVector[2]->Update(deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            whatScreen = buttonVector[1]->getScreenResult();
            GameMode = 1;
            Reset();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            whatScreen = buttonVector[2]->getScreenResult();
            GameMode = 2;
            Reset();
        }
          
        
       

    }
    else if (whatScreen == "Game")
    {
        if (ghostHaveBeenCreated == false)
        {
            CreateGhost(1);
        }
        gameModeChosen=true;
        GameScreen();
        backgroundVector[2]->Update(deltaTime);
        if (GameMode == 1)
        {
            playerVector[0]->Update(deltaTime);
            player1Pos = playerVector[0]->GetPosition();


            p1Score.setString(  std::to_string(playerVector[0]->GetScore()));

            p1PowerUp.setString(playerVector[0]->GetCurrentPowerUp());
           
            if (playerVector[0]->IsAlive())
            {
                player1Time += deltaTime;
            }
            p1Time.setString(std::to_string(player1Time.asSeconds()));
          
          

        }
        else if (GameMode == 2)
        {
            for (int i = 0;i < playerVector.size();++i)
            {
                playerVector[i]->Update(deltaTime);
            }

            if (isPlayerOneGhost == true)
            {
                ghostVector[0]->Update(deltaTime);
            }
            if (isPlayerTwoGhost == true)
            {
                ghostVector[1]->Update(deltaTime);
            }
            player1Pos = playerVector[0]->GetPosition();
            player2Pos = playerVector[1]->GetPosition();


            p1Score.setString(std::to_string(playerVector[0]->GetScore()));
            p2Score.setString(std::to_string(playerVector[1]->GetScore()));


            if (isPlayerOneGhost == true)
            {
                p1PowerUp.setString(ghostVector[0]->GetCurrentPowerUp());
            }
            else
            {
                p1PowerUp.setString(playerVector[0]->GetCurrentPowerUp());
            }

            if (isPlayerTwoGhost == true)
            {
                p2PowerUp.setString(ghostVector[1]->GetCurrentPowerUp());
            }
            else
            {
                p2PowerUp.setString(playerVector[1]->GetCurrentPowerUp());
            }
           
          

            if (playerVector[0]->IsAlive())
            {
                player1Time += deltaTime;
            }
            
            p1Time.setString(std::to_string(player1Time.asSeconds()));
           
            if (playerVector[1]->IsAlive())
            {
                player2Time += deltaTime;
            }
            p2Time.setString(std::to_string(player2Time.asSeconds()));

            //power up stuff 

            if (playerVector[0]->GetCurrentPowerUp() == "ActiveOldDrink")
            {

                playerVector[1]->SetSpeed(400.0f);

            }
            if (playerVector[1]->GetCurrentPowerUp() == "ActiveOldDrink")
            {

                playerVector[0]->SetSpeed(400.0f);

            }
            else if (playerVector[0]->GetCurrentPowerUp() != "ActiveOldDrink")
            {

                playerVector[1]->SetSpeed(600.0f);
            }
            else if (playerVector[1]->GetCurrentPowerUp() != "ActiveOldDrink")
            {
                playerVector[0]->SetSpeed(600.0f);
            }
        }


        //players stuff

        for (int EnemyIndex = 0;EnemyIndex < enemyVector.size();++EnemyIndex)
        {
            for (int PlayerIndex = 0; PlayerIndex < playerVector.size();++PlayerIndex)
            {
                enemyVector[EnemyIndex]->HandelCollistion(playerVector[PlayerIndex]);
            }

        }



       // for (int Enemy1Index = 0;Enemy1Index < enemyVector.size();++Enemy1Index)
      //  {
        //    if (enemyVector[Enemy1Index]->isLaser() == true)
         //   {
         //       for (int Enemy2Index = 0; Enemy2Index < enemyVector.size();++Enemy2Index)
          //      {
         //           enemyVector[Enemy1Index]->HandelEnemyCollistion(enemyVector[Enemy2Index]);
         //       }
        //    }
          
     //   }

       // for (int PlayerIndex = 0;PlayerIndex < playerVector.size();++PlayerIndex)
       // {
        //    if (!playerVector[PlayerIndex]->IsAlive())
        //    {
         //       playerVector[PlayerIndex]->SetPosition(sf::Vector2f(0, 0));
         //   }
       // }

        for (int PlayerIndex = 0; PlayerIndex < playerVector.size();++PlayerIndex)
        {
            for (int powerUpIndex = 0; powerUpIndex < powerUpVector.size();++powerUpIndex)
            {
                playerVector[PlayerIndex]->HandelCollistion(powerUpVector[powerUpIndex]);
            }

        }





        //enemy stuff
        for (int i = 0; i < enemyVector.size(); ++i)
        {
            enemyVector[i]->Update(deltaTime);
        }

        // spawnRateMultiplyer += deltaTime;
         //if (spawnRateMultiplyer.asSeconds() == 10.0f)
         ///{
         //    enemySpawnRate * 0.75;
        ////     spawnRateMultiplyer = sf::Time();
        // }
         //spawn enemy at random time 
        float enemyFrequencyUpper = 20.0f; //in seconds 
        float enemyFrequencylower = 1.5f; //in seconds 

        float enemySpawnRate = 1 + (rand() % 3);
        //getRandomNum(enemyFrequencyUpper, enemyFrequencylower);


        timeSinceEnemy += deltaTime;
        if (timeSinceEnemy.asSeconds() >= enemySpawnRate)
        {
            SpawnEnemy();
            timeSinceEnemy = sf::Time();
        }
        srand(randomStuff);
        randomStuff++;

        if (canLaserSpawn == false)
        {
            laserCoolDownTime += deltaTime;
            if (laserCoolDownTime.asSeconds() >= lengthOfLaserCoolDown)
            {
                canLaserSpawn = true;

                laserCoolDownTime = sf::Time();
            }
        }
        ///
        ///
        /// Need to fix this att some point if possible
        /// 
        /// 


        /// <summary>
        /// 
        /// Sword stuff
        /// 
        /// </summary>
        for (int i = 0; i < enemyVector.size(); ++i)
        {
            //check if enemy is sword
            if (enemyVector[i]->isSword() == true)
            {

                if (GameMode == 1)
                {
                    enemyVector[i]->SetPlayerPos(playerVector[0]->GetPosition());
                }
                else
                {
                    //if player 1 is closer then move towards them
                    if (enemyVector[i]->GetPosition().x - playerVector[0]->GetPosition().x <= 50.0f && playerVector[0]->IsAlive())
                    {
                        enemyVector[i]->SetPlayerPos(playerVector[0]->GetPosition());
                    }
                    //if player two if closer then move towards them
                    if (enemyVector[i]->GetPosition().x - playerVector[1]->GetPosition().x <= 50.0f && playerVector[0]->IsAlive())
                    {
                        enemyVector[i]->SetPlayerPos(playerVector[1]->GetPosition());
                    }
                    //if neither is within 25 on the x axis then sett default to player 1
                    else if (playerVector[0]->IsAlive())
                    {
                        enemyVector[i]->SetPlayerPos(playerVector[0]->GetPosition());
                    }
                    else
                    {
                        enemyVector[i]->SetPlayerPos(playerVector[1]->GetPosition());
                    }
                }

                ///
                /// This is probabaly not the best way to do this
                /// So future me if i have time mess around and fix this please 
                /// Thanks :D
                /// 

                if (enemyVector[i]->IsItOverTimeToLive() == true)
                {
                    enemyVector[i]->TakeDamage(100);
                }


            }

        }




        for (int i = 0; i < enemyVector.size(); ++i)
        {
            if (!enemyVector[i]->IsAlive())
            {

                //De-allocate the memory 
                delete enemyVector[i]; //this is garbage memory and i cannot acces it :D
                enemyVector[i] = nullptr;

                //remove it from the vecotr as it is dead and no one like dead enemys being in a vector :D
                enemyVector.erase(enemyVector.begin() + i);

            }
            else
            {
                ++i;
            }

        }


        ///
        ///
        /// Power up stuff :D
        /// 
        /// 
        /// 

        for (int i = 0; i < powerUpVector.size(); ++i)
        {
            powerUpVector[i]->Update(deltaTime);
        }


        //spawn power up at random time 
        float powerFrequencyUpper = 20.0f; //in seconds 
        float powerFrequencylower = 7.0f; //in seconds 

        float powerSpawnRate = getRandomNum(powerFrequencyUpper, powerFrequencylower);


        timeSincePowerUp += deltaTime;
        if (timeSincePowerUp.asSeconds() >= powerSpawnRate)
        {
            SpawnPowerUp();
            timeSincePowerUp = sf::Time();
        }
        srand(randomStuff);
        randomStuff++;

        for (int i = 0; i < powerUpVector.size(); ++i)
        {
            if (!powerUpVector[i]->IsAlive())
            {

                //De-allocate the memory 
                delete powerUpVector[i]; //this is garbage memory and i cannot acces it :D
                powerUpVector[i] = nullptr;

                //remove it from the vecotr as it is dead and no one like dead power ups being in a vector :D
                powerUpVector.erase(powerUpVector.begin() + i);

            }
            else
            {
                ++i;
            }

        }


      




            if (GameMode == 2)
            {


                if (playerVector[0]->GetCurrentPowerUp() == "ActiveBrokenWatch")
                {
                    //if it has set the enemy speed to 100
                    for (int enemyIndex = 0;enemyIndex < enemyVector.size();++enemyIndex)
                    {
                        if (enemyVector[enemyIndex]->isLaser() == true)
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(350);
                        }
                        else
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(100);
                        }
                    }
                }

                else if (playerVector[1]->GetCurrentPowerUp() == "ActiveBrokenWatch")
                {
                    //if it has set the enemy speed to 100
                    for (int enemyIndex = 0;enemyIndex < enemyVector.size();++enemyIndex)
                    {
                        if (enemyVector[enemyIndex]->isLaser() == true)
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(350);
                        }
                        else
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(100);
                        }
                    }
                }

                //if not set it to 200
                else
                {
                    for (int enemyIndex = 0;enemyIndex < enemyVector.size();++enemyIndex)
                    {
                        if (enemyVector[enemyIndex]->isLaser() == true)
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(700);
                        }
                        else
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(200);
                        }
                    }
                }
            }

            if (GameMode == 1)
            {


                if (playerVector[0]->GetCurrentPowerUp() == "ActiveBrokenWatch")
                {
                    //if it has set the enemy speed to 100
                    for (int enemyIndex = 0;enemyIndex < enemyVector.size();++enemyIndex)
                    {
                        if (enemyVector[enemyIndex]->isLaser() == true)
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(350);
                        }
                        else
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(100);
                        }
                    }
                }
        
                //if not set it to 200
                else
                {
                    for (int enemyIndex = 0;enemyIndex < enemyVector.size();++enemyIndex)
                    {
                        if (enemyVector[enemyIndex]->isLaser() == true)
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(700);
                        }
                        else
                        {
                            enemyVector[enemyIndex]->SetMoveSpeed(200);
                        }
                      
                    }
                }
            }
        



        for (int i = 0;i < playerVector.size();++i)
        {
            for (int PlayerIndex = 0; PlayerIndex < playerVector.size();++PlayerIndex)
            {
                playerVector[i]->HandelPlayerCollistion(playerVector[PlayerIndex]);
            }
        }



        ///
        ///
        /// Bullet Stuff :D
        /// 
        /// 

        for (int i = 0; i < bulletVector.size(); ++i)
        {
            bulletVector[i]->Update(deltaTime);
        }

        sf::Vector2f screenSize(window.getSize());
        for (int i = 0; i < bulletVector.size();i++)
        {
            bulletVector[i]->SetScreenSize(screenSize);
        }


        for (int BulletIndex = 0;BulletIndex < bulletVector.size();++BulletIndex)
        {
            for (int PlayerIndex = 0; PlayerIndex < playerVector.size();++PlayerIndex)
            {
                bulletVector[BulletIndex]->HandelPlayerCollistion(playerVector[PlayerIndex]);
            }

        }
        for (int BulletIndex = 0;BulletIndex < bulletVector.size();++BulletIndex)
        {
            for (int enemyIndex = 0; enemyIndex < enemyVector.size();++enemyIndex)
            {
                bulletVector[BulletIndex]->HandelEnemyCollistion(enemyVector[enemyIndex]);
            }
        }


       
        ///
        ///
        /// Ghost stuff
        /// 
        /// 
        if (GameMode == 2)
        {
            if (isPlayerOneGhost == false)
            {
                if (!playerVector[0]->IsAlive())
                {
                    playerVector[0]->SetPosition(sf::Vector2f(-100, -100));
                    ghostVector[0]->SetPosition(sf::Vector2f(700, 100));
                    isPlayerOneGhost = true;
                   
                }


            }
            else
            {
                playerVector[0]->SetPosition(sf::Vector2f(-100, -100));
           
            }
            if (isPlayerTwoGhost == false)
            {
                if (!playerVector[1]->IsAlive())
                {
                    playerVector[1]->SetPosition(sf::Vector2f(-100, -100));
                   
                 
                    ghostVector[1]->SetPosition(sf::Vector2f(500, 100));
                    isPlayerTwoGhost = true;
                
                }


            }
            else
            {
                playerVector[1]->SetPosition(sf::Vector2f(-100, -100));
            
            }


            if (isPlayerOneGhost == true)
            {
                ghostVector[0]->IsAGhost("Yes");
            }
            else if (isPlayerTwoGhost == true)
            {
                ghostVector[1]->IsAGhost("Yes");
            }

            if (isPlayerOneGhost == true && isPlayerTwoGhost == true)
            {
                whatScreen = "EndScreen";
               
            }


        }
        else if (GameMode == 1)
        {
            if (isPlayerOneGhost == false)
            {
                if (!playerVector[0]->IsAlive())
                {
                    playerVector[0]->SetPosition(sf::Vector2f(-100, -100));
                    whatScreen = "EndScreen";
                }
            }
        }


        if (GameMode == 2)
        {
            if (isPlayerOneGhost == true)
            {
                if (ghostVector[0]->GetCurrentPowerUp() == "ActiveGhostlyHaunting")
                {
                    playerVector[1]->IsControlsInverted(true);
                }
                else
                {
                    playerVector[1]->IsControlsInverted(false);
                }
            }

            else if (isPlayerTwoGhost == true)
            {
                if (ghostVector[1]->GetCurrentPowerUp() == "ActiveGhostlyHaunting")
                {
                    playerVector[0]->IsControlsInverted(true);
                }
                else
                {
                    playerVector[0]->IsControlsInverted(false);
                }
            }
        }
     
    

        ///
        ///
        /// Sound stuff
        /// 
        /// 


        for (int i = 0;i < playerVector.size();++i)
        {
            if (playerVector[i]->GetPlayHit() == true)
            {
                hit.play();
                playerVector[i]->SetPlayHit(false);
            }
            else if (playerVector[i]->GetPlayCoin() == true)
            {
                pickUpCoin.play();
                playerVector[i]->SetPlayCoin(false);
            }
        }


        for (int i = 0;i < ghostVector.size();++i)
        {
            if (ghostVector[i]->GetPlayGhostt() == true)
            {
                ghostHaunting.play();
                ghostVector[i]->SetPlayGhost(false);
            }
        }

       
    }
   else if (whatScreen == "EndScreen")
   {
        endScreenDisplayTime += deltaTime;

        if (endScreenDisplayTime.asSeconds() >= endScreenTimeLimit)
        {
            whatScreen = "Title";

            if (GameMode == 2)
            {
                delete playerVector[0]; //this is garbage memory and i cannot acces it :D
                playerVector[0] = nullptr;

                

                delete playerVector[1]; //this is garbage memory and i cannot acces it :D
                playerVector[1] = nullptr;


                //remove it from the vecotr as it is dead and no one like dead power ups being in a vector :D
                playerVector.erase(playerVector.begin() + 0);
                //remove it from the vecotr as it is dead and no one like dead power ups being in a vector :D
                playerVector.erase(playerVector.begin() + 0);
            }
            else
            {
                delete playerVector[0]; //this is garbage memory and i cannot acces it :D
                playerVector[0] = nullptr;

                //remove it from the vecotr as it is dead and no one like dead power ups being in a vector :D
                playerVector.erase(playerVector.begin() + 0);
            }
                


            for (int i = 0;i < enemyVector.size();++i)
            {
                delete enemyVector[i]; //this is garbage memory and i cannot acces it :D
                enemyVector[i] = nullptr;

                //remove it from the vecotr as it is dead and no one like dead power ups being in a vector :D
                enemyVector.erase(enemyVector.begin() + i);
                i++;
            }

            for (int i = 0;i < powerUpVector.size();++i)
            {
                delete powerUpVector[i]; //this is garbage memory and i cannot acces it :D
                powerUpVector[i] = nullptr;

                //remove it from the vecotr as it is dead and no one like dead power ups being in a vector :D
                powerUpVector.erase(powerUpVector.begin() + i);
                i++;
            }
            endScreenDisplayTime = sf::Time();
        }
        else
        {
            winner.setPosition(sf::VideoMode::getDesktopMode().width / 2-50, sf::VideoMode::getDesktopMode().height / 2 - 50);

            if (GameMode == 2)
            {
                if (playerVector[0]->GetScore() > playerVector[1]->GetScore())
                {
                    winner.setPosition(sf::VideoMode::getDesktopMode().width / 2 - 125, sf::VideoMode::getDesktopMode().height / 2 - 50);
                    winner.setString("Player 1 is the winner!!");
                    p1Score.setPosition( sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
                    p1Time.setPosition( sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 50);
                }
                else if (playerVector[0]->GetScore() < playerVector[1]->GetScore())
                {
                    winner.setPosition(sf::VideoMode::getDesktopMode().width / 2 - 125, sf::VideoMode::getDesktopMode().height / 2 - 50);
                    winner.setString("Player 2 is the winner!!");
                    p2Score.setPosition( sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
                    p2Time.setPosition( sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 50);
                }
                else
                {
                    winner.setString("Its a Draw!!");
                }
            }
            else 
            {
                winner.setString("Well done!!");

                p1Score.setPosition( sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
                p1Time.setPosition( sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 50);
            }

            
        }
        

   }

}



void Game::SetScreen(std::string _whatScreen)
{
}

void Game::SetUpGame()
{
    sf::Vector2f screenSize(window.getSize());
   
    whatScreen = "Title";
    
    int numOfScreens = 3;

    
    
    

    backgroundVector.push_back(new TitleBackground());
    backgroundVector.push_back(new MenuBackground());
    backgroundVector.push_back(new GameBackground());
    backgroundVector.push_back(new EndScreen());

    for (int i = 0; i < backgroundVector.size();i++)
    {
        backgroundVector[i]->setUpBackground(screenSize);
    }

  
    buttonVector.push_back(new TitleButton(1));
    buttonVector.push_back(new OnePlayerButton(2));
    buttonVector.push_back(new TwoPlayerButton(3));
    


  
        
        
        
    



  
}

void Game::TitleScreen()
{
    buttonVector[0]->SetPosition(sf::Vector2f(600, 580));
    
    buttonVector[0]->TitleButtton();
   
}

void Game::GameScreen()
{
    
}

void Game::MenuScreen()
{
    buttonVector[1]->SetPosition(sf::Vector2f(600, 200));
    buttonVector[2]->SetPosition(sf::Vector2f(600, 800));
   

    buttonVector[1]->MenuButton();

    buttonVector[2]->MenuButton();

  
  
}

void Game::SpawnEnemy()
{

    int choise = rand() % 100;
    int dartEnemyChance = 60;
    int brickEnemyChance = 35;
    int swordEnemyChance = 75;
    int laserEnemyChance = 80;
    int blockEnemyChance = 100;
    
    int whichPlayer = 1+(rand() % 2);
   

     if (choise < brickEnemyChance )
    {
        enemyVector.push_back(new Brick(sf::Vector2f(window.getSize()), "Top"));
    }
     else if (choise < dartEnemyChance && choise > brickEnemyChance)
    {
        enemyVector.push_back(new Dart(sf::Vector2f(window.getSize()), "Right"));

    }
     else if (choise < swordEnemyChance && choise > dartEnemyChance)
     {
         if (whichPlayer == 1&& GameMode==2)
         {
             enemyVector.push_back(new Sword(sf::Vector2f(window.getSize()), "Right", player1Pos));
         }
         else if (whichPlayer == 2 && GameMode == 2)
         {
             enemyVector.push_back(new Sword(sf::Vector2f(window.getSize()), "Right", player2Pos));
         }
         else if (GameMode == 1)
         {
             enemyVector.push_back(new Sword(sf::Vector2f(window.getSize()), "Right", player1Pos));
         }
     }
     else if (choise < laserEnemyChance && choise > swordEnemyChance )
     {
         if (canLaserSpawn == true)
         {
             enemyVector.push_back(new Laser(sf::Vector2f(window.getSize()), "Right"));
             canLaserSpawn = false;
         }
         else if (canLaserSpawn == false)
         {
             enemyVector.push_back(new Brick(sf::Vector2f(window.getSize()), "Top"));
         }
     }
     else if (choise < blockEnemyChance && choise> laserEnemyChance)
     {
         enemyVector.push_back(new Block(sf::Vector2f(window.getSize()), "Right"));
     }
     

    
 }

float Game::getRandomNum(float upper, float lower)
{
    return lower+rand()%(int)(upper-lower);
}

void Game::SpawnPowerUp()
{
    int choise = rand() % 100;
    int whereChoise = rand() % 100;

    int topChance = 50;
    int rightChance = 50;
    int pistolPowerChance = 20;
    int coinPowerChance = 75;
    int spikeShoeChance = 5;
    int brokenWatchChance = 80;
    int oldDrinkChance = 110;

    if (GameMode == 2)
    {
        pistolPowerChance = 20;
        coinPowerChance = 75;
        spikeShoeChance = 5;
        brokenWatchChance = 80;
        oldDrinkChance = 90;
    }
 

   // int whichPlayer = 1 + (rand() % 2);


    if (choise <= pistolPowerChance)
    {
        powerUpVector.push_back(new Pistol(sf::Vector2f(window.getSize()), "Right","Pistol"));
    }
    else if (choise <= coinPowerChance&&choise>pistolPowerChance)
    {
        powerUpVector.push_back(new Coin(sf::Vector2f(window.getSize()), "Right", "Coin"));
    }
    else if (choise >= spikeShoeChance &&choise<brokenWatchChance)
    {
        powerUpVector.push_back(new SpikeShoe(sf::Vector2f(window.getSize()), "Right", "SpikeShoe"));
    }
   else if (choise >= brokenWatchChance&&choise<oldDrinkChance)
  {
        
    powerUpVector.push_back(new BrokenWatch(sf::Vector2f(window.getSize()), "Right", "BrokenWatch"));
  }
    else if (choise <= oldDrinkChance)
    {
        if (whereChoise < topChance)
        {
            powerUpVector.push_back(new OldDrink(sf::Vector2f(window.getSize()), "Top", "OldDrink"));
        }
        if (whereChoise > rightChance)
        {
            powerUpVector.push_back(new OldDrink(sf::Vector2f(window.getSize()), "Right", "OldDrink"));
        }
       
    }
}

void Game::SetUpPlayers()
{
    sf::Vector2f screenSize(window.getSize());
    if (GameMode == 2)
    {
        playerVector.push_back(new Shaun(1, this));
        playerVector.push_back(new John(2, this));

        playerVector[0]->SetPosition(sf::Vector2f(100, screenSize.y - 80-200));
        playerVector[1]->SetPosition(sf::Vector2f(500, screenSize.y -80-200));

        playerVector[0]->SetHealth(100);
        playerVector[1]->SetHealth(100);


        //text stuff 




        mainFont.loadFromFile("Assets/Fonts/Font.ttf");



        p1.setFont(mainFont);
        p1.setFillColor(sf::Color::White);
        p1.setCharacterSize(25);
        p1.setPosition(50, 50);
        p1.setString("Player 1:");


        p2.setFont(mainFont);
        p2.setFillColor(sf::Color::White);
        p2.setCharacterSize(25);
        p2.setPosition(screenSize.x - 200, 50);
        p2.setString("Player 2:");

        p1Score.setFont(mainFont);
        p1Score.setFillColor(sf::Color::White);
        p1Score.setCharacterSize(25);
        p1Score.setPosition(50, 100);

        p2Score.setFont(mainFont);
        p2Score.setFillColor(sf::Color::White);
        p2Score.setCharacterSize(25);
        p2Score.setPosition(screenSize.x - 200, 100);



        p1PowerUp.setFont(mainFont);
        p1PowerUp.setFillColor(sf::Color::White);
        p1PowerUp.setCharacterSize(25);
        p1PowerUp.setPosition(50, 150);


        p2PowerUp.setFont(mainFont);
        p2PowerUp.setFillColor(sf::Color::White);
        p2PowerUp.setCharacterSize(25);
        p2PowerUp.setPosition(screenSize.x - 200, 150);



        p1Time.setFont(mainFont);
        p1Time.setFillColor(sf::Color::White);
        p1Time.setCharacterSize(25);
        p1Time.setPosition(50, 200);


        p2Time.setFont(mainFont);
        p2Time.setFillColor(sf::Color::White);
        p2Time.setCharacterSize(25);
        p2Time.setPosition(screenSize.x - 200, 200);


        winner.setFont(mainFont);
        winner.setFillColor(sf::Color::White);
        winner.setCharacterSize(25);
        winner.setPosition(screenSize.x /2 - (winner.getCharacterSize()), 100);
    
    }
    else if (GameMode == 1)
    {
        playerVector.push_back(new Shaun(1, this));
        playerVector[0]->SetPosition(sf::Vector2f(100, screenSize.y / 2 - 50));


        //text stuff 




        mainFont.loadFromFile("Assets/Fonts/Font.ttf");
        p1Score.setFont(mainFont);
        p1Score.setFillColor(sf::Color::White);
        p1Score.setCharacterSize(25);
        p1Score.setPosition(screenSize.x/2, 100);

        p1.setFont(mainFont);
        p1.setFillColor(sf::Color::White);
        p1.setCharacterSize(25);
        p1.setPosition(screenSize.x / 2 , 50);
        p1.setString("Player 1:");

        p1PowerUp.setFont(mainFont);
        p1PowerUp.setFillColor(sf::Color::White);
        p1PowerUp.setCharacterSize(25);
        p1PowerUp.setPosition(screenSize.x / 2-(p1PowerUp.getCharacterSize()), 150);


        p1Time.setFont(mainFont);
        p1Time.setFillColor(sf::Color::White);
        p1Time.setCharacterSize(25);
        p1Time.setPosition(screenSize.x / 2, 200);

        winner.setFont(mainFont);
        winner.setFillColor(sf::Color::White);
        winner.setCharacterSize(25);
        winner.setPosition(screenSize.x / 2-(winner.getCharacterSize()), 50);
    }

}

void Game::CreateGhost(int playerNum)
{
    ghostVector.push_back(new ShaunGhost(1, this));
    ghostVector.push_back(new JohnGhost(2, this));
  
}

void Game::Reset()
{
    isPlayerOneGhost = false;
    isPlayerTwoGhost = false;
    SetUpPlayers();
    player1Time = sf::Time();
    player2Time = sf::Time();

    if (GameMode == 2)
    {
        playerVector[0]->Reset();
        playerVector[1]->Reset();
        
    }
    else
    {
        playerVector[0]->Reset();
    }

}

void Game::AddBullet(Bullet* bulletToAdd)
{
    bulletVector.push_back(bulletToAdd);
}

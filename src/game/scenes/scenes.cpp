//
//  scenes.cpp
//  sfml game template
//
//  Created by Sunmyoung Yun on 2024/09
//

#include "scenes.hpp"

/* Scene constructure sets up window and sprite respawn times */
Scene::Scene( sf::RenderWindow& gameWindow ) : window(gameWindow), sceneView(Constants::VIEW_RECT) /* initialize other elements here */ { 
    log_info("scene made"); 
}

/* runScene that takes in delta time and global time from GameManager class to execute scene logic */
void Scene::runScene(float deltaT, float globalT){
    deltaTime = deltaT;
    globalTime = globalT; 
    
    /* inside the while loop in game, only runs when gameEnd state is false */
    if (!flagEvents.gameEnd) {
        setTime();
        handleInput();
        respawnAssets(); 
        handleGameEvents(); 
    }
    /* inside the while loop in game, always runs */
    handleGameFlags(); 
    update();
    draw();
}

void Scene::draw(){
    window.clear(sf::Color::Black);
   // log_info("base scene draw call");
    window.display(); 
 }

/* Resets everything for scene to start again. The position, moveState, flagEvents, etc are all reset */
void Scene::restartScene() {
    // re-play background music

    // set sprite movestates to true
   
    // re-set sprite and text positions 

    // clear respawn time vectors or any other unecessary vectors 

    // re-set flagEvents
    sceneEvents.resetFlags(); 
}

/* Handles events from flagEvents; deals with gameEnd state */
void Scene::handleGameFlags(){
    // if flagEvents.gameEnd is true or some event ... do somthing 
    if(flagEvents.gameEnd){
       
    }
}

/* Updates mouse position from GameManager input */
void Scene::setMouseClickedPos(sf::Vector2i mousePos){
    mouseClickedPos = mousePos; 
} 

/* Gets called once before the main game loop to handle cpu-heavy work only once at the beggining */
void gamePlayScene::createAssets() {
    try {
        // Initialize sprites and music here 
         background = std::make_unique<Background>(Constants::BACKGROUND_POSITION, Constants::BACKGROUND_SCALE, Constants::BACKGROUND_TEXTURE);
         sprite1 = std::make_unique<Sprite>(Constants::SPRITE1_POSITION, Constants::SPRITE1_SCALE, Constants::SPRITE1_TEXTURE); 
         tile1 = std::make_unique<Tile>(Constants::TILE1_POSITION, Constants::TILE1_SCALE, Constants::TILE1_TEXTURE, Constants::TILE1_RECT, Constants::TILE1_BOOL);
         tileMap1 = std::make_unique<TileMap>(Constants::MAP_WIDTH, Constants::MAP_HEIGHT, Constants::TILE_WIDTH, Constants::TILE_HEIGHT, std::move(tile1)); 
         backgroundMusic = std::make_unique<MusicClass>(std::move(Constants::BACKGROUNDMUSIC_MUSIC), Constants::BACKGROUNDMUSIC_VOLUME);
        button1 = std::make_unique<Button>(Constants::SPRITE1_POSITION, Constants::SPRITE1_SCALE, Constants::SPRITE1_TEXTURE, 
                                   Constants::BUTTON1_ANIMATIONRECTS, Constants::BUTTON1_INDEXMAX, 
                                   utils::convertToWeakPtrVector(Constants::BUTTON1_BITMASK));
        //  if (backgroundMusic){
        //     backgroundMusic->returnMusic().play(); 
        //  }
        
         playerJumpSound = std::make_unique<SoundClass>(Constants::PLAYERJUMP_SOUNDBUFF, Constants::PLAYERJUMPSOUND_VOLUME); 
          
         text1 = std::make_unique<TextClass>(Constants::TEXT_POSITION, Constants::TEXT_SIZE, Constants::TEXT_COLOR, Constants::TEXT_FONT, Constants::TEXT_MESSAGE);
         
        } 

    catch (const std::exception& e) {
        std::cerr << "Exception caught in createAssets: " << e.what() << std::endl;
    }
}

/* Creates more sprites from exisitng textures; avoids heavy cpu work */
void gamePlayScene::respawnAssets(){
    // if certain respawn time variable is less than a certain value, respawn objects
} 

/* deletes sprites if their visibleState is false for memory management */
void gamePlayScene::deleteInvisibleSprites() {
    // Remove invisible sprites
   
   // Remove large-scale unenecessary texts 
}

/* Updating time from GameManager's deltatime; it updates sprite respawn times and also counts 
elapsed times from when bullets were spawned and when space button was pressed */
void gamePlayScene::setTime(){
    // count respawn time here 
} 

/* deals with inputs from device, let known by flagEvents. If player's MoveState is true and its pointer is not null, it updates player's position */
void gamePlayScene::handleInput() {
    // if player's getMoveState() is true, and flagEvents.somekeypressed is true, updatePlayer(sf::Vector2f newPosition)
    if(flagEvents.aPressed){
        if(sceneView)
            sceneView.getView().move(sf::Vector2f(-1, 0)); 
    }
    if(flagEvents.dPressed){
        if(sceneView)
            sceneView.getView().move(sf::Vector2f(1, 0)); 
    }
    if(flagEvents.sPressed){
        if(sceneView)
            sceneView.getView().move(sf::Vector2f(0, 1)); 
    }
    if(flagEvents.wPressed){
        if(sceneView)
            sceneView.getView().move(sf::Vector2f(0, -1)); 
    }
    if(flagEvents.mouseClicked){
        if (physics::boundingBoxCollisionHelper(mouseClickedPos, *button1)){
            log_info("button clicked"); 
            gameScene1Flags.sceneEnd = true;
            gameSceneNextFlags.sceneStart = true;
            gameSceneNextFlags.sceneEnd = false;

            window.clear();
            return; 
        }
    }
    
}

/* Keeps sprites inside screen bounds, checks for collisions, update scores, and sets flagEvents.gameEnd to true in an event of collision */
void gamePlayScene::handleGameEvents() { 
    // increase score

    // sprite collisions bool collision = physics::checkCollisions(sprite1, sprites, collisiontype) 

   // if collision, modify a sceneEvent

} 

void gamePlayScene::handleSceneFlags(){
    // if flagEvents.gameEnd is true or some event ... do somthing 
    // if(gameScene1Flags.sceneEnd){
    //    return; 
    // }
}

/* Updates sprite and text positions when their moveState is true and their pointers are not null. 
deleteInvisibleSprites is called to destroy invisible sprites for memory management */
void gamePlayScene::update() {
    try {
        //log_info("Starting update in gamePlayScene");

        // Remove invisible sprites
       // log_info("Calling deleteInvisibleSprites...");
        deleteInvisibleSprites();

       // log_info("Setting view...");
        window.setView(sceneView.getView()); 
        
       // log_info("Finished update in gamePlayScene");
    }
    catch (const std::exception& e) {
        log_error("Exception in updateSprites: " + std::string(e.what()));
    }
}

/* Draws only the visible sprite and texts */
void gamePlayScene::draw() {
    try {
        window.clear();

        if (background && background->getVisibleState()) {
            window.draw(*background); 
        }
        if (sprite1 && sprite1->getVisibleState()) {
            window.draw(*sprite1); 
        }
        
        window.display(); 
    } 
    
    catch (const std::exception& e) {
        std::cerr << "Exception in draw: " << e.what() << std::endl;
    }
}

void gamePlayScene2::createAssets() {
 try {
        // Initialize sprites and music here 
         background = std::make_unique<Background>(Constants::BACKGROUND_POSITION, Constants::BACKGROUND_SCALE, Constants::BACKGROUND_TEXTURE2);
        } 

    catch (const std::exception& e) {
        std::cerr << "Exception caught in createAssets: " << e.what() << std::endl;
    }
}

void gamePlayScene2::handleInput() {
    if(flagEvents.aPressed){
        if(sceneView)
            sceneView.getView().move(sf::Vector2f(-1, 0)); 
    }
    if(flagEvents.dPressed){
        if(sceneView)
            sceneView.getView().move(sf::Vector2f(1, 0)); 
    }
    if(flagEvents.sPressed){
        if(sceneView)
            sceneView.getView().move(sf::Vector2f(0, 1)); 
    }
    if(flagEvents.wPressed){
        if(sceneView)
            sceneView.getView().move(sf::Vector2f(0, -1)); 
    }
}

void gamePlayScene2::draw() {
    try {
        window.clear();

        if (background && background->getVisibleState()) {
            window.draw(*background); 
        }
    
        window.display(); 
    } 
    
    catch (const std::exception& e) {
        std::cerr << "Exception in draw: " << e.what() << std::endl;
    }
}
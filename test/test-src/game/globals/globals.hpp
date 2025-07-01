//
//  globals.hpp
//
//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream> 
#include <sstream>
#include <fstream> 
#include <yaml-cpp/yaml.h>
#include <filesystem>

#include "../test-logging/log.hpp"

namespace SpriteComponents {
    enum Direction { NONE, LEFT, RIGHT, UP, DOWN };

    Direction toDirection(const std::string& direction); // convert string from yaml to Direction
    sf::Color toSfColor(const std::string& color); // convert string from yaml to sf::Color
}

namespace MetaComponents{
    inline sf::Vector2i mouseClickedPosition_i {}; 
    inline sf::Vector2f mouseClickedPosition_f {}; 

    inline float globalTime {};
    inline float deltaTime {}; 
    inline float spacePressedElapsedTime{};

    extern sf::Clock clock;
    extern sf::View view;

    extern sf::FloatRect getViewBounds();
    extern float getViewMinX();
    extern float getViewMaxX();
    extern float getViewMinY();
    extern float getViewMaxY();
}

namespace Constants { // not actually "constants" in terms of being fixed, but should never be altered after being read from the config.yaml file
    extern void initialize();

    // make random positions each time
    extern sf::Vector2f makeRandomPosition(); 
    extern sf::Vector2f makeRandomPositionCloud(); 
    extern sf::Vector2f makeRandomPositionCoin(); 

    extern void writeRandomTileMap(const std::filesystem::path filePath); 

    // load textures, fonts, music, and sound
    extern std::shared_ptr<sf::Uint8[]> createBitmask( const std::shared_ptr<sf::Texture>& texture, const sf::IntRect& rect, const float transparency = 0.0f);
    extern std::shared_ptr<sf::Uint8[]> createBitmaskForBottom( const std::shared_ptr<sf::Texture>& texture, const sf::IntRect& rect, const float transparency = 0.0f, int rows = 1);

    extern void printBitmaskDebug(const std::shared_ptr<sf::Uint8[]>& bitmask, unsigned int width, unsigned int height);
    extern void loadAssets(); 
    extern void readFromYaml(const std::filesystem::path configFile); 
    extern void makeRectsAndBitmasks(); 

    // Game display settings
    inline float WORLD_SCALE;
    inline unsigned short WORLD_WIDTH;
    inline unsigned short WORLD_HEIGHT;
    inline unsigned short FRAME_LIMIT;
    inline std::string GAME_TITLE;
    inline sf::Vector2f VIEW_INITIAL_CENTER;
    inline float VIEW_SIZE_X;
    inline float VIEW_SIZE_Y;
    inline sf::FloatRect VIEW_RECT;

    // Score settings
    inline unsigned short INITIAL_SCORE;

    // Animation settings
    inline float ANIMATION_CHANGE_TIME;
    inline short PASSTHROUGH_OFFSET;

    // Sprite and text settings
    inline unsigned short SPRITE_OUT_OF_BOUNDS_OFFSET;
    inline unsigned short SPRITE_OUT_OF_BOUNDS_ADJUSTMENT;
    inline unsigned short PLAYER_Y_POS_BOUNDS_RUN;

    // Background settings
    inline float BACKGROUND_SPEED;
    inline std::filesystem::path BACKGROUNDSPRITE_PATH;
    inline std::filesystem::path BACKGROUNDSPRITE_PATH2;
    inline sf::Vector2f BACKGROUND_POSITION;
    inline sf::Vector2f BACKGROUND_SCALE;
    inline SpriteComponents::Direction BACKGROUND_MOVING_DIRECTION;
    inline std::shared_ptr<sf::Texture> BACKGROUND_TEXTURE = std::make_shared<sf::Texture>();
    inline std::shared_ptr<sf::Texture> BACKGROUND_TEXTURE2 = std::make_shared<sf::Texture>();
  
    // Sprite paths and settings
    inline short SPRITE1_INDEXMAX;
    inline short SPRITE1_ANIMATIONROWS;  
    inline std::filesystem::path SPRITE1_PATH;
    inline sf::Vector2f SPRITE1_POSITION;
    inline sf::Vector2f SPRITE1_SCALE;
    inline sf::Vector2f SPRITE1_JUMP_ACCELERATION;
    inline float SPRITE1_SPEED;
    inline sf::Vector2f SPRITE1_ACCELERATION;
    inline std::shared_ptr<sf::Texture> SPRITE1_TEXTURE = std::make_shared<sf::Texture>();
    inline std::vector<sf::IntRect> SPRITE1_ANIMATIONRECTS;
    inline std::vector<std::shared_ptr<sf::Uint8[]>> SPRITE1_BITMASK;

    // Cloud (blue) settings
    inline std::filesystem::path CLOUDBLUE_PATH;
    inline sf::Vector2f CLOUDBLUE_POSITION;
    inline sf::Vector2f CLOUDBLUE_SCALE;
    inline float CLOUDBLUE_SPEED;
    inline sf::Vector2f CLOUDBLUE_ACCELERATION;
    inline std::shared_ptr<sf::Texture> CLOUDBLUE_TEXTURE = std::make_shared<sf::Texture>();
    inline std::shared_ptr<sf::Uint8[]> CLOUDBLUE_BITMASK;
    inline sf::IntRect CLOUDBLUE_RECT;
    inline float CLOUDBLUE_INITIAL_RESPAWN_TIME;
    inline unsigned short CLOUDBLUE_LIMIT;

    // Cloud (purple) settings
    inline std::filesystem::path CLOUDPURPLE_PATH;
    inline sf::Vector2f CLOUDPURPLE_POSITION;
    inline std::shared_ptr<sf::Texture> CLOUDPURPLE_TEXTURE = std::make_shared<sf::Texture>();
    inline std::shared_ptr<sf::Uint8[]> CLOUDPURPLE_BITMASK;
    inline sf::IntRect CLOUDPURPLE_RECT;
    inline float CLOUDPURPLE_INITIAL_RESPAWN_TIME;
    inline unsigned short CLOUDPURPLE_LIMIT;

    // COin settings
    inline std::filesystem::path COIN_PATH;
    inline sf::Vector2f COIN_POSITION;
    inline sf::Vector2f COIN_SCALE;
    inline float COIN_SPEED;
    inline sf::Vector2f COIN_ACCELERATION;
    inline std::shared_ptr<sf::Texture> COIN_TEXTURE = std::make_shared<sf::Texture>();
    inline std::shared_ptr<sf::Uint8[]> COIN_BITMASK;
    inline sf::IntRect COIN_RECT;
    inline float COIN_INITIAL_RESPAWN_TIME;
    inline unsigned short COIN_LIMIT;

    // Button settings
    inline short BUTTON1_INDEXMAX;
    inline std::filesystem::path BUTTON1_PATH;
    inline sf::Vector2f BUTTON1_POSITION;
    inline sf::Vector2f BUTTON1_SCALE;
    inline std::shared_ptr<sf::Texture> BUTTON1_TEXTURE = std::make_shared<sf::Texture>();
    inline std::vector<sf::IntRect> BUTTON1_ANIMATIONRECTS;
    inline std::vector<std::shared_ptr<sf::Uint8[]>> BUTTON1_BITMASK;

    // Tile settings
    inline sf::Vector2f TILEMAP_POSITION; 
    inline std::filesystem::path TILES_PATH;
    inline unsigned short TILES_ROWS;
    inline unsigned short TILES_COLUMNS;
    inline unsigned short TILES_NUM;
    inline unsigned short const TILES_NUMBER = 60; // should be the same as tiles_num but need to be const 
    inline std::array<bool, TILES_NUMBER> TILES_BOOLS; 

    inline sf::Vector2f TILES_SCALE;
    inline unsigned short TILE_WIDTH;
    inline unsigned short TILE_HEIGHT;
    inline std::shared_ptr<sf::Texture> TILES_TEXTURE = std::make_shared<sf::Texture>();
    inline std::vector<sf::IntRect> TILES_SINGLE_RECTS;
    inline std::vector<std::shared_ptr<sf::Uint8[]>> TILES_BITMASKS;

    // Tilemap settings
    inline size_t TILEMAP_WIDTH;
    inline size_t TILEMAP_HEIGHT;
    inline float TILEMAP_BOUNDARYOFFSET; 
    inline std::filesystem::path TILEMAP_FILEPATH;

    // Text settings
    inline unsigned short TEXT_SIZE;
    inline std::filesystem::path TEXT_PATH;
    inline std::string TEXT_MESSAGE;
    inline sf::Vector2f TEXT_POSITION;
    inline sf::Color TEXT_COLOR;
    inline std::shared_ptr<sf::Font> TEXT_FONT = std::make_shared<sf::Font>(); 

    inline unsigned short SCORETEXT_SIZE;
    inline std::string SCORETEXT_MESSAGE;
    inline sf::Vector2f SCORETEXT_POSITION;
    inline sf::Color SCORETEXT_COLOR;

    inline unsigned short ENDINGTEXT_SIZE;
    inline std::string ENDINGTEXT_MESSAGE;
    inline sf::Vector2f ENDINGTEXT_POSITION;
    inline sf::Color ENDINGTEXT_COLOR;

    // Music settings
    inline std::filesystem::path BACKGROUNDMUSIC_PATH;
    inline float BACKGROUNDMUSIC_VOLUME;
    inline std::unique_ptr<sf::Music> BACKGROUNDMUSIC_MUSIC = std::make_unique<sf::Music>(); 
    inline bool BACKGROUNDMUSIC_LOOP;
    inline float BACKGROUNDMUSIC_ENDINGVOLUME;

    // Sound settings
    inline std::filesystem::path PLAYERJUMPSOUND_PATH;
    inline float PLAYERJUMPSOUND_VOLUME;
    inline std::shared_ptr<sf::SoundBuffer> PLAYERJUMP_SOUNDBUFF = std::make_shared<sf::SoundBuffer>();

    inline std::filesystem::path COINHITSOUND_PATH;
    inline float COINHITSOUND_VOLUME;
    inline std::shared_ptr<sf::SoundBuffer> COINHIT_SOUNDBUFF = std::make_shared<sf::SoundBuffer>();

    inline std::filesystem::path BUTTONCLICKSOUND_PATH;
    inline float BUTTONCLICKSOUND_VOLUME;
    inline std::shared_ptr<sf::SoundBuffer> BUTTONCLICK_SOUNDBUFF = std::make_shared<sf::SoundBuffer>();
}

// New namespace for flag events
namespace FlagSystem {
    
    struct FlagEvents {
        // game states
        bool gameEnd; 

        // keyboard inputs
        bool wPressed;
        bool aPressed;
        bool sPressed;
        bool dPressed;
        bool bPressed;
        bool spacePressed; 
        bool mouseClicked;

        FlagEvents() : wPressed(false), aPressed(false), sPressed(false), dPressed(false), bPressed(false), spacePressed(false), mouseClicked(false) {}

        // resets every flag
        void resetFlags() {
            gameEnd = wPressed = aPressed = sPressed = dPressed = bPressed = spacePressed = mouseClicked = false;
            log_info("General game flags reset complete");
        }

        // resets keyboard flags only 
        void flagKeyReleased() {
            wPressed = false;
            aPressed = false;
            sPressed = false;
            dPressed = false;
            bPressed = false;
            spacePressed = false;
        }
    };

    inline FlagEvents flagEvents; 

    struct SceneEvents {
        bool sceneEnd;
        bool sceneStart; 

        SceneEvents() : sceneEnd(false), sceneStart(false) {} 

        void resetFlags() {
            log_error("failed resetting scene Flags");
            std::memset(this, 0, sizeof(*this));
            log_info("Reset sceneEvents flags");
        }
    };

    struct GameSceneEvents1 {
        bool sceneEnd;
        bool sceneStart; 

        bool playerJumping;
        bool playerFalling; 
        GameSceneEvents1() : sceneEnd(false), sceneStart(true), playerJumping(false), playerFalling(false) {} 

        void resetFlags() {
            log_error("failed resetting scene Flags");
            std::memset(this, 0, sizeof(*this));
            log_info("Reset GameSceneEvents1 flags");
        }
    };

    inline GameSceneEvents1 gameScene1Flags; // accesible from everywhere 
    inline SceneEvents gameSceneNextFlags; // accecible from everywhere 
}

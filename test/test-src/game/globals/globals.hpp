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

#include "log.hpp" 

namespace SpriteComponents {
    enum Direction { NONE, LEFT, RIGHT, UP, DOWN };
}

namespace MetaComponents{
    inline sf::Vector2i mouseClickedPosition {}; 

    inline float globalTime {};
    inline float deltaTime {}; 

    extern sf::Clock clock;
    extern sf::View view;
}

/* constant variables declared here */
namespace Constants {
    // make random positions each time
    extern sf::Vector2f makeRandomPosition(); 
    extern void writeRandomTileMap(const std::string& filePath); 

    // load textures, fonts, music, and sound
    extern void initialize(); 
    extern std::shared_ptr<sf::Uint8[]> createBitmask( const std::shared_ptr<sf::Texture>& texture, const sf::IntRect& rect );
    extern void printBitmaskDebug(const std::shared_ptr<sf::Uint8[]>& bitmask, unsigned int width, unsigned int height);

    // basic game components
    constexpr float SCREEN_SCALE = 0.5f;
    constexpr unsigned short SCREEN_WIDTH = 1920 * SCREEN_SCALE;
    constexpr unsigned short SCREEN_HEIGHT = 1080 * SCREEN_SCALE;

    constexpr unsigned short FRAME_LIMIT = 60;

    constexpr const char* GAME_TITLE = "SFML game template tester";

    constexpr float VIEW_SIZE_X = 1920.0f * SCREEN_SCALE;
    constexpr float VIEW_SIZE_Y = 1080.0f * SCREEN_SCALE;
    inline const sf::FloatRect VIEW_RECT = { 0.0f, 0.0f, VIEW_SIZE_X, VIEW_SIZE_Y };
    inline const sf::Vector2f VIEW_INITIAL_CENTER = { VIEW_SIZE_X / 2.0f, VIEW_SIZE_Y / 2.0f };

    // score components
    constexpr unsigned short INITIAL_SCORE = 0;

    // basic animation standards
    constexpr float ANIMATION_CHANGE_TIME = 0.1f;
    constexpr short PASSTHROUGH_OFFSET = 65; 

    // typical screen buffers for sprites and texts
    constexpr unsigned short SPRITE_OUT_OF_BOUNDS_OFFSET = 110;
    constexpr unsigned short SPRITE_OUT_OF_BOUNDS_ADJUSTMENT = 100;
    constexpr unsigned short PLAYER_Y_POS_BOUNDS_RUN = SCREEN_HEIGHT - SPRITE_OUT_OF_BOUNDS_ADJUSTMENT; 
    
    // background components 
    constexpr float BACKGROUND_SPEED = 35.0;
    constexpr const char* BACKGROUNDSPRITE_PATH = "test/test-assets/sprites/png/background_day.png";
    constexpr const char* BACKGROUNDSPRITE_PATH2 = "test/test-assets/sprites/png/background_night.png";   
    inline const sf::Vector2f BACKGROUND_POSITION = { 0.0f, 0.0f };
    inline const sf::Vector2f BACKGROUND_SCALE = { 1.0f, 1.0f };
    inline std::shared_ptr<sf::Texture> BACKGROUND_TEXTURE = std::make_shared<sf::Texture>();
    inline std::shared_ptr<sf::Texture> BACKGROUND_TEXTURE2 = std::make_shared<sf::Texture>();
    inline SpriteComponents::Direction BACKGROUND_MOVING_DIRECTION = SpriteComponents::Direction::RIGHT; 

    // sprite components
    constexpr const char* SPRITE1SPRITE_PATH = "test/test-assets/sprites/png/Static.png";
    inline const sf::Vector2f SPRITE1_POSITION = { 0.0f, 0.0f };
    inline const sf::Vector2f SPRITE1_SCALE = { 1.0f, 1.0f };
    inline std::shared_ptr<sf::Texture> SPRITE1_TEXTURE = std::make_shared<sf::Texture>();

    constexpr short BUTTON1_INDEXMAX = 6; 
    constexpr const char* BUTTON1_PATH = "test/test-assets/sprites/png/Static.png";
    inline const sf::Vector2f BUTTON1_POSITION = { 0.0f, 0.0f };
    inline const sf::Vector2f BUTTON1_SCALE = { 1.0f, 1.0f };
    inline std::shared_ptr<sf::Texture> BUTTON1_TEXTURE = std::make_shared<sf::Texture>();
    inline std::vector<sf::IntRect> BUTTON1_ANIMATIONRECTS;
    inline std::vector<std::shared_ptr<sf::Uint8[]>> BUTTON1_BITMASK;

    // typical tile components 
    constexpr const char* TILES_PATH = "test/test-assets/tiles/png/Tileset.png";
    constexpr unsigned short TILES_ROWS = 6;
    constexpr unsigned short TILES_COLUMNS = 10;
    constexpr unsigned short TILES_NUMBER = TILES_ROWS * TILES_COLUMNS; 
    inline const sf::Vector2f TILES_SCALE = { 1.0f, 1.0f };
    inline std::shared_ptr<sf::Texture> TILES_TEXTURE = std::make_shared<sf::Texture>();
    inline std::vector<sf::IntRect> TILES_SINGLE_RECTS;
    inline std::vector<std::shared_ptr<sf::Uint8[]>> TILES_BITMASKS;
    inline std::array<bool, TILES_NUMBER> TILES_BOOLS {}; 
    constexpr unsigned short TILE_WIDTH = 32;
    constexpr unsigned short TILE_HEIGHT = 32;

    // typical tile map componenets (number is actual grid size, not pixels)
    constexpr size_t TILEMAP_WIDTH = 320; 
    constexpr size_t TILEMAP_HEIGHT = 192;  
    constexpr const char* TILEMAP_FILEPATH = "test/test-assets/tiles/tilemap.txt";

    // typical text components
    constexpr unsigned short TEXT_SIZE = 40;
    constexpr const char* TEXT_PATH = "test/test-assets/fonts/ttf/font1.ttf";
    constexpr const char* TEXT_MESSAGE = "Some text here";
    inline const sf::Vector2f TEXT_POSITION = { 0.0f, 0.0f };
    inline const sf::Color TEXT_COLOR = sf::Color::Green;
    inline std::shared_ptr<sf::Font> TEXT_FONT = std::make_shared<sf::Font>(); 

    // typical music components 
    constexpr const char* BACKGROUNDMUSIC_PATH = "test/test-assets/sound/mp3/bgm.mp3";
    inline std::unique_ptr<sf::Music> BACKGROUNDMUSIC_MUSIC = std::make_unique<sf::Music>(); 
    constexpr float BACKGROUNDMUSIC_VOLUME = 100.0f;
   
    // typical sound components
    constexpr const char* PLAYERJUMPSOUND_PATH = "test/test-assets/sound/mp3,flac,wav/jump.wav";
    inline std::shared_ptr<sf::SoundBuffer> PLAYERJUMP_SOUNDBUFF = std::make_shared<sf::SoundBuffer>();
    constexpr float PLAYERJUMPSOUND_VOLUME = 100.0f; 
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
            log_info("Flags have been successfully reset.");
        }


        // resets keyboard flags only 
        void flagKeyReleased() {
            wPressed = false;
            aPressed = false;
            sPressed = false;
            dPressed = false;
            bPressed = false;
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
            log_info("Flags have been successfully reset.");
        }
    };

    struct GameSceneEvents1 {
        bool sceneEnd;
        bool sceneStart; 

        GameSceneEvents1() : sceneEnd(false), sceneStart(true) {} 

        void resetFlags() {
            log_error("failed resetting scene Flags");
            std::memset(this, 0, sizeof(*this));
            log_info("Flags have been successfully reset.");
        }
    };

    inline GameSceneEvents1 gameScene1Flags; 
    inline SceneEvents gameSceneNextFlags;
}

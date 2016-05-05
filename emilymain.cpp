//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(799, 700), "SFML window");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    // Background
    sf::Texture background;
    if (!background.loadFromFile(resourcePath() + "background.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite froggerBackground(background);
    
    // Frogger
    sf::Texture frog;
    if (!frog.loadFromFile(resourcePath() + "spritesheet.png")) {
        return EXIT_FAILURE;
    }
    sf::IntRect rectSourceSprite(0, 0, 75, 150);
    sf::Sprite frogger(frog, rectSourceSprite);
    
    // Create a graphical text to display
    //sf::Font font;
    //if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
    //    return EXIT_FAILURE;
    //}
    //sf::Text text("Hello SFML", font, 50);
    //text.setColor(sf::Color::Black);
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "froggerTheme.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    music.play();
    
    // Set Frogger Starting Point
    frogger.setPosition(350, 530);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }// end if
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }// end if
            
            
            // Movement
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                sf::Vector2f pos = frogger.getPosition();
                
                if (pos.x <= 0)
                {
                    frogger.move(0,0);
                }// end if
                else
                {
                    if (rectSourceSprite.left != 225)
                    {
                        rectSourceSprite.left = 225;
                        frogger.setTextureRect(rectSourceSprite);
                    }// end if
                    
                    frogger.move(-35,0);
                    
                }// end else
            }// end if
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                sf::Vector2f pos = frogger.getPosition();
                
                if (pos.x >= 730)
                {
                    frogger.move(0,0);
                }// end if
                else
                {
                    if (rectSourceSprite.left != 85)
                    {
                        rectSourceSprite.left = 85;
                        frogger.setTextureRect(rectSourceSprite);
                    }// end if
                    
                    frogger.move(35,0);
                    
                }// end else
            }// end if
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                sf::Vector2f pos = frogger.getPosition();
                
                if (pos.y <= -30)
                {
                    frogger.move(0,0);
                }// end if
                else
                {
                    if (rectSourceSprite.left != 0)
                    {
                        rectSourceSprite.left = 0;
                        frogger.setTextureRect(rectSourceSprite);
                    }// end if
                    
                    frogger.move(0,-35);
                }
            }// end if
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                sf::Vector2f pos = frogger.getPosition();
                
                if (pos.y >= 530)
                {
                    frogger.move(0,0);
                }// end if
                else
                {
                    if (rectSourceSprite.left != 139)
                    {
                        rectSourceSprite.left = 139;
                        frogger.setTextureRect(rectSourceSprite);
                    }// end if
                    
                    frogger.move(0,35);
            
                }// end else
            }// end if
        }// end game loop
        
        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(froggerBackground);
        window.draw(frogger);
        
        // Draw the string
        //window.draw(text);
        
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}

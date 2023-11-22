#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>


class Texture_Manager{
    static std::unordered_map<std::string, sf::Texture> textures;

public:
    
    static sf::Texture& getTexture(std::string textureName){
        auto result = textures.find(textureName);
        if (result == textures.end()){
            // texture does not already exist in the map, go get it
            sf::Texture newTexture;
            newTexture.loadFromFile("images/" + textureName + ".png");
            textures[textureName] = newTexture;
            return textures[textureName];
        }else{
            return result->second;
        }
    }
};
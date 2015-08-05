#include <iostream>
#include <SFML/Graphics.hpp>

#include "NodeSprite.hpp"

class Game
{
    Path getPath(std::string sequence)
    {
        Path path;
        for(int i = 0; i < sequence.size(); i++)
        {
            if(sequence[i] == 'l')
            {
                path.push_back(Left);
            }
            if(sequence[i] == 'r')
            {
                path.push_back(Right);
            }
            if(sequence[i] == 'u')
            {
                path.push_back(Up);
            }
            if(sequence[i] == 'd')
            {
                path.push_back(Down);
            }
        }
        return path;
    }
public:

    void main(sf::RenderWindow& window)
    {
        sf::Clock clock;

        std::string pathsequence;
        std::getline(std::cin, pathsequence);

        Path path = getPath(pathsequence);

        Node node(path);
        NodeSprite nodeSprite(node);

        std::vector<Node> nodes;
        nodes.push_back(node);

        std::vector<NodeSprite> nodeSprites;
        nodeSprites.push_back(nodeSprite);

        Button start;
        start.setPosition(600, 20);

        Button reset;
        reset.setPosition(600, 150);

        std::vector<Button> buttons;
        buttons.push_back(start);
        buttons.push_back(reset);

        while (window.isOpen())
        {
            float dt = clock.restart().asSeconds();

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            window.clear(sf::Color::White);

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if(start.isPressed(mousePosition))
            {
                for(int i = 0; i < nodeSprites.size(); i++){nodeSprites[i].run();}
            }

            if(reset.isPressed(mousePosition))
            {
                for(int i = 0; i < nodeSprites.size(); i++){nodeSprites[i].reset();}

                Node* node = new Node(nodes.back().mutate());
                nodes.push_back(*node);

                NodeSprite* nodeSprite = new NodeSprite(*node);
                nodeSprites.push_back(*nodeSprite);

                std::cout << "Generation " << nodeSprites.size() << std::endl;
            }

            for(int i = 0; i < nodeSprites.size(); i++){nodeSprites[i].update(dt); window.draw(nodeSprites[i]);}
            for(int i = 0; i < buttons.size(); i++){window.draw(buttons[i]);}
            window.display();
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Evolution");
    Game().main(window);
    return 0;
}

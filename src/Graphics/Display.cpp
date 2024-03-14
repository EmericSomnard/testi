/*
** EPITECH PROJECT, 2024
** B-PDG-300-NCY-3-1-PDGRUSH3-emeric.somnard
** File description:
** Display
*/

#include "Display.hpp"

void blockToDisplay(sf::RenderWindow *window, HostUserName &host, Ram &ram, CPU &cpu, Data &data)
{
    if (host.getHostUserDisplay() == true)
        host.displayHostUserInfo(window, data);
    if (ram.getRamDisplay() == true)
        ram.displayRamInfo(window, data);
    if (cpu.getCpuDisplay() == true)
        cpu.displayCpuInfo(window, data);
}


void Display::display()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "MyGKrellm");
    HostUserName host;
    Ram ram;
    CPU cpu;
    Data data;

    data.refresh();
    sf::Font font;
    font.loadFromFile("./assets/arial.ttf");

    sf::RectangleShape button1(sf::Vector2f(100, 50));
    button1.setPosition(10, 10);
    button1.setFillColor(sf::Color::Green);

    sf::Text text1("OS Info", font, 20);
    text1.setPosition(25, 20);
    text1.setFillColor(sf::Color::White);

    sf::RectangleShape button2(sf::Vector2f(100, 50));
    button2.setPosition(120, 10);
    button2.setFillColor(sf::Color::Green);

    sf::Text text2("RAM", font, 20);
    text2.setPosition(135, 20);
    text2.setFillColor(sf::Color::White);

    sf::RectangleShape button3(sf::Vector2f(100, 50));
    button3.setPosition(230, 10);
    button3.setFillColor(sf::Color::Green);

    sf::Text text3("CPU", font, 20);
    text3.setPosition(245, 20);
    text3.setFillColor(sf::Color::White);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        data.refresh();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (button1.getGlobalBounds().contains(mousePos)) {
                    if (host.getHostUserDisplay() == false) {
                        host.setHostUserDisplay(true);
                        button1.setFillColor(sf::Color::Green);
                    } else {
                        host.setHostUserDisplay(false);
                        button1.setFillColor(sf::Color::Red);
                    }
                }
                else if (button2.getGlobalBounds().contains(mousePos)) {
                    if (ram.getRamDisplay() == false) {
                        ram.setRamDisplay(true);
                        button2.setFillColor(sf::Color::Green);
                    } else {
                        ram.setRamDisplay(false);
                        button2.setFillColor(sf::Color::Red);
                    }
                }
                else if (button3.getGlobalBounds().contains(mousePos)) {
                    if (cpu.getCpuDisplay() == false) {
                        cpu.setCpuDisplay(true);
                        button3.setFillColor(sf::Color::Green);
                    } else {
                        cpu.setCpuDisplay(false);
                        button3.setFillColor(sf::Color::Red);
                    }
                }
            }
        }

        // Rendering
        window.clear();
        window.draw(button1);
        window.draw(text1);
        window.draw(button2);
        window.draw(text2);
        window.draw(button3);
        window.draw(text3);
        blockToDisplay(&window, host, ram, cpu, data);
        window.display();
    }
}

#pragma once

class Application
{
protected:
    int height;
    int width;
public:
    virtual void initGraphics();
    virtual void display();
    virtual void update();
    virtual void resize(int width, int height);
};
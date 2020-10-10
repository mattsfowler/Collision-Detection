#pragma once

class Application
{
protected:
    int height;
    int width;
    float timeInterval;
public:
    void setTimeInterval(float interval);
    virtual void initGraphics();
    virtual void display();
    virtual void update();
    virtual void resize(int width, int height);
};
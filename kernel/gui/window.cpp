#include "window.h"
#include "../BasicRenderer.h"

GUI::Window* windows[];

namespace GUI{
    uint8_t xButton[] = {
                            0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,
                            0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,
                            0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,
                            1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,
                            1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,
                            1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,
                            1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,
                            1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,
                            0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,
                            0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,
                            0,0,0,0,0,1,1,1,1,1,0,0,0,0,0 
                        };
    Window::Window(uint32_t posX, uint32_t posY, uint32_t color){
        this->posX = posX;
        this->posY = posY;
        this->color = color;
    }

    Window::~Window(){
        loadBackground();
    }

    void Window::create(){
        saveBackground();
        drawWindow();
    }

    void Window::saveBackground(){
        for(uint32_t x = 0; x <= this->width; x++){
            for(uint32_t y = 0; y <= this->height; y++){
                windowBuffer[(this->width*y)+x] = GlobalRenderer->GetPix(x+this->posX, y+this->posY);
            }
        }
    }

    void Window::loadBackground(){
        for(uint32_t x = 0; x <= this->width; x++){
            for(uint32_t y = 0; y <= this->height; y++){
                GlobalRenderer->PutPix(x+this->posX, y+this->posY, windowBuffer[(this->width*y)+x]);
            }
        }
    }

    void Window::move(uint32_t x, uint32_t y){
        loadBackground();
        this->posX = x;
        this->posY = y;
        saveBackground();
        drawWindow();
    }

    void Window::drawWindow(){
        GlobalRenderer->DrawRectangle(this->width, this->height, this->posX, this->posY, 0x00FFFFFF);
        GlobalRenderer->DrawRectangle(this->width-4, this->height-24, this->posX+2, this->posY+22, 0x00000000);
        Point oldCursor = GlobalRenderer->CursorPosition;
        GlobalRenderer->CursorPosition = {this->posX+2, this->posY+2};
        GlobalRenderer->Color = 0x00000000;
        GlobalRenderer->Print("Terminal");
        GlobalRenderer->Color = 0x00FFFFFF;
        GlobalRenderer->CursorPosition = oldCursor;
        for(uint16_t c = 0; c <= 14; c++){
            for(uint16_t r = 0; r <= 14; r++){
                uint32_t pixColor;
                if(xButton[(15*r)+c] == 1){
                    pixColor = 0x00FF0000;
                }else{
                    pixColor = 0x00FFFFFF;
                }
                GlobalRenderer->PutPix((this->posX+this->width-16)+c, (this->posY+1)+r, pixColor);
            }
        }
    }

}
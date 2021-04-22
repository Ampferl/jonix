#include "window.h"
#include "../BasicRenderer.h"
#include "../userinput/mouse.h"
#include "icon.h"

GUI::Window* windows[];

namespace GUI{

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
        GlobalRenderer->ClearMouseCursor(GUI::ICON::MousePointer, MousePosition);
        for(uint32_t x = 0; x <= this->width; ++x){
            for(uint32_t y = 0; y <= this->height; ++y){
                windowBuffer[(this->width*y)+x] = GlobalRenderer->GetPix(x+this->posX, y+this->posY);
            }
        }
        GlobalRenderer->DrawOverlayMouseCursor(GUI::ICON::MousePointer, MousePosition, 0xffffffff);
    }

    void Window::loadBackground(){
        for(uint32_t x = 0; x <= this->width; ++x){
            for(uint32_t y = 0; y <= this->height; ++y){
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

    void Window::loadMenuButtons(){
        for(uint16_t c = 0; c <= 14; ++c){
            for(uint16_t r = 0; r <= 14; ++r){
                uint32_t pixColor;
                if(GUI::ICON::closeButton[(15*r)+c] == 1){
                    pixColor = 0x00FF0000;
                }else{
                    pixColor = 0x00A6B8B8;
                }
                GlobalRenderer->PutPix((this->posX+this->width-16)+c, (this->posY+1)+r, pixColor);
            }
        }
        for(uint16_t c = 0; c <= 14; ++c){
            for(uint16_t r = 0; r <= 14; ++r){
                uint32_t pixColor;
                if(GUI::ICON::hideButton[(15*r)+c] == 1){
                    pixColor = 0x00FF7E00;
                }else{
                    pixColor = 0x00A6B8B8;
                }
                GlobalRenderer->PutPix((this->posX+this->width-32)+c, (this->posY+1)+r, pixColor);
            }
        }
    }

    void Window::drawWindow(){
        GlobalRenderer->DrawRectangle(this->width, this->height, this->posX, this->posY, 0x00A6B8B8);
        GlobalRenderer->DrawRectangle(this->width-4, this->height-24, this->posX+2, this->posY+22, 0x00000000);
        Point oldCursor = GlobalRenderer->CursorPosition;
        GlobalRenderer->CursorPosition = {this->posX+2, this->posY+2};
        GlobalRenderer->Color = 0x00000000;
        GlobalRenderer->Print("Terminal");
        GlobalRenderer->Color = 0x00FFFFFF;
        GlobalRenderer->CursorPosition = oldCursor;
        loadMenuButtons();
    }

}
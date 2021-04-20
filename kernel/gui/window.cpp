#include "window.h"
#include "../memory/heap.h"
#include "../BasicRenderer.h"

namespace GUI{

        Window::Window(uint32_t width, uint32_t height, uint32_t posX, uint32_t posY, uint32_t color){
            this->windowBuffer = new uint32_t[width * height];
            this->width = width;
            this->height = height;
            this->posX = posX;
            this->posY = posY;
            this->color = color;
            saveBackground();
            drawWindow();
        }

        Window::~Window(){
            loadBackground();
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
        }

}
#ifndef TYPEBOX_H
#define TYPEBOX_H
#include "Listener.h"

#include <iostream>

class TypeBox:public pg::Listener<char>
{
    public:
        TypeBox();
        virtual ~TypeBox();

         std::string getText(){
            std::string text=phrase;
            text.resize(text.length()-1);
            return text;
            }
        void activate();
        void deactivate();
        void notify(char k);


    protected:
        std::string phrase;
        bool active;
    private:
};

#endif // TYPEBOX_H

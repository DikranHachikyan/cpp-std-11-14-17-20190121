#ifndef WIDGET_H
#define WIDGET_H
#include <memory>

class Widget{
    private:
        class WidgetImpl;
        //WidgetImpl *imp;
        std::unique_ptr<WidgetImpl> pImpl;
    public:
        Widget(int);
        ~Widget();
        //Move Ctor
        Widget(Widget &&)=default;
        Widget(const Widget &)=delete;
        //Move
        Widget &operator=(Widget &&);
        Widget &operator=(const Widget &)=delete;
        //API
        void draw();
        bool isVisible() const;
};

#endif // WIDGET_H

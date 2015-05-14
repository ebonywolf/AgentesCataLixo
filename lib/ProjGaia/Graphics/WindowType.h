#ifndef WINDOWTYPE_H
#define WINDOWTYPE_H


namespace pg{
class WindowType
{
    public:

        /** Default destructor */
        virtual ~WindowType()=default;
        virtual int getWidth()=0;
       virtual int getHeight()=0;
    protected:
    private:
};
}
#endif // WINDOWTYPE_H

#ifndef CAMERAMOUSECONTROL_H
#define CAMERAMOUSECONTROL_H
#include "MouseEvent.h"
#include "Listener.h"
#include "../Graphics/Camera.h"
#include "../Graphics/WindowType.h"
#include "NeedsUpdate.h"
//TODO :Zoom features
namespace pg{
class CameraMouseControl:public Listener<MouseEvent>,public NeedsUpdate
{

    public:
        /** Default constructor */

        CameraMouseControl(Camera*,WindowType*,float speed);
        /** Default destructor */
        float speed;
        float BORDER=0.5;
        bool acceleration=false;

        void update(void*);
        void notify(MouseEvent e);
        virtual ~CameraMouseControl();
    protected:
        WindowType* window;
        Camera* camera;
        pg::Coord move;
    private:

};
}
#endif // CAMERAMOUSECONTROL_H

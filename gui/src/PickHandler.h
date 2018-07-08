//
// Created by jianping on 18-4-7.
//

#ifndef QOSGFRAMEWORK_PICKHANDLER_H
#define QOSGFRAMEWORK_PICKHANDLER_H

#include <osgGA/GUIEventHandler>

class PickHandler : public osgGA::GUIEventHandler
{
public:
    PickHandler( double devicePixelRatio = 1.0 );
    virtual ~PickHandler();

    virtual bool handle( const osgGA::GUIEventAdapter&  ea,
                         osgGA::GUIActionAdapter& aa );

private:
    double devicePixelRatio_;
};



#endif //QOSGFRAMEWORK_PICKHANDLER_H

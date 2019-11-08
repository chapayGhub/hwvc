//
// Created by mingyi.li on 2018/12/25.
//

#ifndef HARDWAREVIDEOCODEC_MAINPIPELINE_H
#define HARDWAREVIDEOCODEC_MAINPIPELINE_H

#include "Object.h"
#include "Message.h"
#include "AlHandlerThread.h"
#include "AlHandler.h"
#include "SimpleLock.h"
#include <vector>

using namespace std;

class Unit;

class UnitPipeline : public Object {
public:
    UnitPipeline(string name);

    virtual ~UnitPipeline();

    void postEvent(Message *msg);

    int registerAnUnit(Unit *unit);

    void release();

private:
    void postEvent(Message *msg, bool front);

    void dispatch(Message *msg);

    void clear();

private:
    AlHandlerThread *mThread = nullptr;
    AlHandler *mHandler = nullptr;
    SimpleLock simpleLock;
    vector<Unit *> units;
    bool available = true;
};


#endif //HARDWAREVIDEOCODEC_MAINPIPELINE_H

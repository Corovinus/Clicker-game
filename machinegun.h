#ifndef MACHINEGUN_H
#define MACHINEGUN_H
#include "gun.h"
class Machinegun: public Gun {

public:
    explicit Machinegun(QObject *parent = nullptr);
};
#endif // MACHINEGUN_H

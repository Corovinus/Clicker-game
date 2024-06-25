#ifndef MACHINEGUN_H
#define MACHINEGUN_H
#include "gun.h"
class Machinegun: public Gun {

protected:
public:
    explicit Machinegun(QObject *parent = nullptr);
};
#endif // MACHINEGUN_H

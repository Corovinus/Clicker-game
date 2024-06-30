#ifndef GUN_H
#define GUN_H

#include "weapon.h"
#include <iostream>


///////////////////////////////////////////////////////////////////////////
/// \brief The Gun class
///////////////////////////////////////////////////////////////////////////


class Gun: public Weapon {
public:
    explicit Gun(QObject *parent = nullptr);
    void Shoot() override;
    void Reload() override;
    bool CheckAmmo();
};


class Pistolet: public Gun {

public:
    explicit Pistolet(QObject *parent = nullptr);
};


///////////////////////////////////////////////////////////////////////////
/// \brief The Machinegun class
///////////////////////////////////////////////////////////////////////////


class Machinegun: public Gun {

public:
    explicit Machinegun(QObject *parent = nullptr);
};


///////////////////////////////////////////////////////////////////////////
/// \brief The AWM class
///////////////////////////////////////////////////////////////////////////


class AWM: public Gun {

public:
    explicit AWM(QObject *parent = nullptr);
};

class Bazoo: public Gun {

public:
    explicit Bazoo(QObject *parent = nullptr);
};

#endif // GUN_H

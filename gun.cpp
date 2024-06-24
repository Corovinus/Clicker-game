#include "gun.h"

Gun::Gun(QObject *parent) : Weapon(parent), max_ammo(30), ammo(30) {

}
void Gun::Shoot(){
    if (CheckAmmo()) {
        return;
    }
    std::cout  << "Piff-Paff" << std::endl;
    ammo--;
}
void Gun::Reload()  {
    std::cout << "Reloading..." << std::endl;
    ammo = max_ammo;
}
bool Gun::CheckAmmo() {
        if (ammo == 0) {
            std::cout << "No Ammo" << std::endl;
            return true;
        }
        return false;
}

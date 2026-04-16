// modelos.h

#pragma once

#include <iostream>

using namespace std;

class Coordenada {

public:

    int x;

    Coordenada(int x = 0){
        this->x = x;
    }

    Coordenada operator+(const Coordenada& o) const {
        return Coordenada(x + o.x);
    }

    Coordenada operator-(const Coordenada& o) const {
        return Coordenada(x - o.x);
    }

    Coordenada operator*(const Coordenada& o) const {
        return Coordenada(x * o.x);
    }

    Coordenada operator/(const Coordenada& o) const {
        return Coordenada(x / o.x);
    }

    bool operator>(const Coordenada& o) const {
        return x > o.x;
    }
};

class Vector3D {

public:

    int mag;

    Vector3D(int mag = 0){
        this->mag = mag;
    }

    Vector3D operator+(const Vector3D& o) const {
        return Vector3D(mag + o.mag);
    }

    Vector3D operator-(const Vector3D& o) const {
        return Vector3D(mag - o.mag);
    }

    Vector3D operator*(const Vector3D& o) const {
        return Vector3D(mag * o.mag);
    }

    Vector3D operator/(const Vector3D& o) const {
        return Vector3D(mag / o.mag);
    }

    bool operator>(const Vector3D& o) const {
        return mag > o.mag;
    }
};

class Esfera {

public:

    int radio;

    Esfera(int radio = 0){
        this->radio = radio;
    }

    Esfera operator+(const Esfera& o) const {
        return Esfera(radio + o.radio);
    }

    Esfera operator-(const Esfera& o) const {
        return Esfera(radio - o.radio);
    }

    Esfera operator*(const Esfera& o) const {
        return Esfera(radio * o.radio);
    }

    Esfera operator/(const Esfera& o) const {
        return Esfera(radio / o.radio);
    }

    bool operator>(const Esfera& o) const {
        return radio > o.radio;
    }
};
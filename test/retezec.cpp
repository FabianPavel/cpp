#include <iostream>
#include "retezec.h"

// Implementace metod třídy Retezec

Retezec::Retezec() {
    obsah = new char[1];
    obsah[0] = '\0';
    delka = 0;
}

Retezec::Retezec(const char *retezec) {
    delka = 0;
    while (retezec[delka] != '\0') {
        delka++;
    }
    obsah = new char[delka + 1];
    for (int i = 0; i <= delka; i++) {
        obsah[i] = retezec[i];
    }
}

Retezec::Retezec(const Retezec &other) {
    delka = other.delka;
    obsah = new char[delka + 1];
    for (int i = 0; i <= delka; i++) {
        obsah[i] = other.obsah[i];
    }
}

Retezec::~Retezec() {
    delete[] obsah;
}

const char* Retezec::ZiskatObsah() const {
    return obsah;
}

void Retezec::NastavitObsah(const char *novyObsah) {
    delka = 0;
    while (novyObsah[delka] != '\0') {
        delka++;
    }
    delete[] obsah;
    obsah = new char[delka + 1];
    for (int i = 0; i <= delka; i++) {
        obsah[i] = novyObsah[i];
    }
}

int Retezec::ZiskatDelku() const {
    return delka;
}

char Retezec::operator[](int index) const {
    if (index >= 0 && index < delka) {
        return obsah[index];
    } else {
        return '\0';
    }
}

Retezec& Retezec::operator=(const Retezec &other) {
    if (this != &other) {
        delete[] obsah;
        delka = other.delka;
        obsah = new char[delka + 1];
        for (int i = 0; i <= delka; i++) {
            obsah[i] = other.obsah[i];
        }
    }
    return *this;
}

Retezec& Retezec::operator+=(const Retezec &other) {
    int novaDelka = delka + other.delka;
    char *novaObsah = new char[novaDelka + 1];
    for (int i = 0; i < delka; i++) {
        novaObsah[i] = obsah[i];
    }
    for (int i = 0; i <= other.delka; i++) {
        novaObsah[i + delka] = other.obsah[i];
    }
    delete[] obsah;
    obsah = novaObsah;
    delka = novaDelka;
    return *this;
}

Retezec operator+(const Retezec &str1, const Retezec &str2) {
    Retezec nova;
    nova.delka = str1.delka + str2.delka;
    nova.obsah = new char[nova.delka + 1];
    for (int i = 0; i < str1.delka; i++) {
        nova.obsah[i] = str1.obsah[i];
    }
    for (int i = 0; i <= str2.delka; i++) {
        nova.obsah[i + str1.delka] = str2.obsah[i];
    }
    return nova;
}


#ifndef RETEZEC_H
#define RETEZEC_H

class Retezec {
private:
    char *obsah;
    int delka;

public:
    Retezec(); // Konstruktor bez parametrů
    Retezec(const char *); // Konstruktor s parametrem typu C-style řetězec
    Retezec(const Retezec &); // Kopírovací konstruktor
    ~Retezec(); // Destruktor

    const char* ZiskatObsah() const; // Metoda pro získání obsahu
    void NastavitObsah(const char *); // Metoda pro změnu obsahu
    int ZiskatDelku() const; // Metoda pro získání délky řetězce

    char operator[](int ) const; // Přetížení operátoru []
    Retezec& operator=(const Retezec &); // Přetížení operátoru =
    Retezec& operator+=(const Retezec &); // Přetížení operátoru +=
    friend Retezec operator+(const Retezec &, const Retezec &); // Přetížení operátoru +
};

#endif // RETEZEC_H

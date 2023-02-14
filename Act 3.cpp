#include <iostream>
#include <string>

class Mamifero
{
public:
    Mamifero(std::string dieta, int year, std::string lugar)
        : dieta(dieta), year(year), lugar(lugar) {}

    std::string getDieta() const
    {
        return dieta;
    }
    int getYear() const
    {
        return year;
    }
    std::string getLugar() const
    {
        return lugar;
    }

    bool operator==(const Mamifero& otro) const
    {
        return dieta == otro.dieta && year == otro.year && lugar == otro.lugar;
    }

    bool operator!=(const Mamifero& otro) const
    {
        return !(*this == otro);
    }

    bool operator<(const Mamifero& otro) const
    {
        return year < otro.year;
    }

    bool operator>(const Mamifero& otro) const
    {
        return otro < *this;
    }

    Mamifero operator+(const Mamifero& otro) const
    {
        return Mamifero(dieta + " " + otro.dieta, year + otro.year,
                        lugar + " " + otro.lugar);
    }
private:
    std::string dieta;
    int year;
    std::string lugar;
};

class Felino : public Mamifero
{
public:
    Felino(std::string dieta, int year, std::string lugar, std::string raza, std::string circo)
        : Mamifero(dieta, year, lugar), raza(raza), circo(circo) {}

    std::string getRaza() const
    {
        return raza;
    }
    std::string getCirco() const
    {
        return circo;
    }

    void setCirco(std::string newCirco)
    {
        circo = newCirco;
    }
private:
    std::string raza;
    std::string circo;
};

class GatoDomestico : public Felino
{
public:
    GatoDomestico(std::string dieta, int year, std::string lugar, std::string raza, std::string duenio): Felino(dieta, year, lugar, raza, ""), duenio(duenio) {}

    std::string getDuenio() const
    {
        return duenio;
    }

    void setDuenio(std::string newDuenio)
    {
        duenio = newDuenio;
    }

private:
    std::string duenio;
};

int main()
{
    GatoDomestico Minino ("Cescado", 2015, "Gudalajara", "Siames", "Caty");
    Felino EstrellaCirco ("Carne", 2012, "Japon", "Leopardo", "El maravilla");

    std::cout << "Dieta de Minino: " << Minino.getDieta() << std::endl;

    std::cout << "Dieta de EstrellaCirco: " << EstrellaCirco.getDieta() << std::endl;

    std::cout << "Anioo de nacimiento de Minino: " << Minino.getYear() << std::endl;
    std::cout << "Lugar de nacimiento de Minino: " << Minino.getLugar() << std::endl;

    std::cout << "Anio de nacimiento de EstrellaCirco: " << EstrellaCirco.getYear() << std::endl;
    std::cout << "Lugar de nacimiento de EstrellaCirco: " << EstrellaCirco.getLugar() << std::endl;

    Minino.setDuenio("Jose");
    std::cout << "Nuevo duenio de Minino: " << Minino.getDuenio() << std::endl;

    std::cout << "Raza de Minino: " << Minino.getRaza() << std::endl;
    std::cout << "Raza de EstrellaCirco: " << EstrellaCirco.getRaza() << std::endl;

    EstrellaCirco.setCirco("Circus Fantasticus");
    std::cout << "Nuevo circo de EstrellaCirco: " << EstrellaCirco.getCirco() << std::endl;

    return 0;
}

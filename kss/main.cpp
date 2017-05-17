#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Planeta{
  public:
    Planeta() { }

    static float delka_dne() { return 1;}
    virtual int cislo_dne() const { return 0; }
    virtual void napis() {}
};

class Merkur : public Planeta{
  public:
    int rok;

    Merkur(int* datum) :
      rok(datum[0])
    { }

    Merkur(int den_) :
      rok(den_)
    { }

    static float delka_dne() { return 87.96935;}
    virtual int cislo_dne() const {
      return rok;
    }
    virtual void napis() {
      cout << rok;
    }
};

class Venuse : public Planeta{
  public:
    int rok;
    int den;

    Venuse(int* datum) :
      rok(datum[1]),
      den(datum[0])
    { }

    Venuse(int den_) :
      rok(),
      den()
    {
      int ustupnych = int(den_ / 25) - int((den_+1) / 1251);
      den = (den_ + ustupnych) % 2 + 1;
      rok = (den_ + ustupnych) / 2 + 1;
    }

    static float delka_dne() { return 116.75;}
    virtual int cislo_dne() const {
      return (rok - 1) * 2 - int((rok-1) / 13) + int((rok-1) / 650) + den - 1;
    }
    virtual void napis() {
      cout << den << "." << rok;
    }
};

class Zeme : public Planeta{
  private:
    bool je_prestupny(int r) const {
      return ((rok % 4 == 0) && (rok % 100 != 0)) || (rok % 400 == 0);
    }

    const int mesice[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int mesice_p[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  public:
    int rok;
    int mesic;
    int den;

    Zeme(int* datum) :
      rok(datum[2]),
      mesic(datum[1]),
      den(datum[0])
    { }

    Zeme(int den_) :
      rok(),
      mesic(),
      den()
    {
      bool uzs = true;
      int prestupnych = int((den_ + 366) / 1461);
      int prestupnych2 = int(prestupnych / 25);
      int prestupnych3 = int(prestupnych2 / 4);
      prestupnych = prestupnych - prestupnych2 + prestupnych3;
      if (((den_ + 366) % 1461 == 0) && ((prestupnych+1) % 25 != 0)) {
        den_++;
        uzs = false;
      }
      if (((prestupnych2+1) % 4 == 0)) {
        uzs = false;
      }
      rok = (den_ - prestupnych) / 365 + 1;
      den_ -= prestupnych + (rok-1) * 365;
      if (je_prestupny(rok)) {
        if (uzs) {
          den_++;
        }
        for (int i = 0; i < 12; i++) {
          if (den_ >= mesice_p[i]) {
            den_ -= mesice_p[i];
          } else {
            den = den_ + 1;
            mesic = i + 1;
            break;
          }
        }
      } else {
        for (int i = 0; i < 12; i++) {
          if (den_ >= mesice[i]) {
            den_ -= mesice[i];
          } else {
            den = den_ + 1;
            mesic = i + 1;
            break;
          }
        }
      }
    }

    static float delka_dne() { return 1; }
    virtual int cislo_dne() const {
      int prestupnych = int(rok / 4);
      int prestupnych2 = int(prestupnych / 25);
      int prestupnych3 = int(prestupnych2 / 4);
      prestupnych = prestupnych - prestupnych2 + prestupnych3;
      int result = (rok-1) * 365 + prestupnych;
      if (je_prestupny(rok)) {
        result--;
        for (int i = mesic - 2; i >= 0; i--) {
          result += mesice_p[i];
        }
      } else {
        for (int i = mesic - 2; i >= 0; i--) {
          result += mesice[i];
        }
      }
      return result + den - 1;
    }
    virtual void napis() {
      cout << den << "." << mesic << "." << rok;
    }
};

class Mars : public Planeta{
  private:
    bool je_prestupny(int r) const {
      return ((rok % 4 == 0) && (rok % 100 != 0)) || (rok % 400 == 0);
    }

    const int mesice[18] = {37, 37, 37, 38, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 38, 37, 37, 37};
    const int mesice_p[18] = {37, 37, 37, 38, 37, 37, 37, 38, 37, 37, 38, 37, 37, 37, 38, 37, 37, 37};
    const int mesice_pn[18] = {37, 37, 37, 38, 37, 37, 37, 38, 37, 37, 37, 37, 37, 37, 38, 37, 37, 37};

  public:
    int rok;
    int mesic;
    int den;

    Mars(int* datum) :
      rok(datum[2]),
      mesic(datum[1]),
      den(datum[0])
    { }

    Mars(int den_) :
      rok(),
      mesic(),
      den()
    {
      bool uzs = true;
      int prestupnych = int((den_ + 670) / 3342);
      int prestupnych2 = int(prestupnych / 30);
      prestupnych = 2*prestupnych - prestupnych2;
      if ((den_ + 670) % 3342 == 0) {
        den_++;
        uzs = false;
      }
      rok = (den_ - prestupnych) / 668 + 1;
      den_ -= prestupnych + (rok-1) * 668;
      if (rok % 150 == 0) {
        if (uzs) {
          den_++;
        }
        for (int i = 0; i < 12; i++) {
          if (den_ >= mesice_pn[i]) {
            den_ -= mesice_pn[i];
          } else {
            den = den_ + 1;
            mesic = i + 1;
            break;
          }
        }
      } else if (rok % 5 == 0) {
        if (uzs) {
          den_+=2;
        } else {
          den_++;
        }
        for (int i = 0; i < 12; i++) {
          if (den_ >= mesice_p[i]) {
            den_ -= mesice_p[i];
          } else {
            den = den_ + 1;
            mesic = i + 1;
            break;
          }
        }
      } else {
        for (int i = 0; i < 12; i++) {
          if (den_ >= mesice[i]) {
            den_ -= mesice[i];
          } else {
            den = den_ + 1;
            mesic = i + 1;
            break;
          }
        }
      }
    }

    static float delka_dne() { return 1.02777777; }//1,02777777
    virtual int cislo_dne() const {
      int prestupnych = int(rok / 5);
      int prestupnych2 = int(prestupnych / 30);
      prestupnych = 2*prestupnych - prestupnych2;
      int result = (rok-1) * 668 + prestupnych;
      if (rok % 150 == 0) {
        result--;
        for (int i = mesic - 2; i >= 0; i--) {
          result += mesice_pn[i];
        }
      } else if (rok % 5 == 0) {
        result -= 2;
        for (int i = mesic - 2; i >= 0; i--) {
          result += mesice_p[i];
        }
      } else {
        for (int i = mesic - 2; i >= 0; i--) {
          result += mesice[i];
        }
      }
      return result + den - 1;
    }
    virtual void napis() {
      cout << den << "." << mesic << "." << rok;
    }
};

class Jupiter : public Planeta{
  private:
    bool je_prestupny(int r) const {
      return (rok % 4 == 0) && (rok % 44 != 0);
    }

    //const int carpa[9] = {29, 29, 29, 29, 30, 29, 29, 29, 29};
    const int callista[30] = {41, 40, 40, 40, 40, 40, 40, 40, 41, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40};
    const int callista_r[30] = {41, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40};

  public:
    int rok;
    int carpo;
    int callisto;
    int den;

    Jupiter(int* datum) :
      rok(datum[3]),
      carpo(datum[2]),
      callisto(datum[1]),
      den(datum[0])
    { }

    Jupiter(int den_) :
      rok(),
      carpo(),
      callisto(),
      den()
    {
      bool uzs = true;
      int prestupnych = int((den_ + 10498) / 41989);
      int prestupnych2 = int(prestupnych / 11);
      prestupnych = prestupnych - prestupnych2;
      if ((den_ + 10498) % 41989 == 0) {
        den_++;
        uzs = false;
      }
      rok = (den_ - prestupnych) / 10497 + 1;
      den_ -= prestupnych + (rok-1) * 10497;
      if (je_prestupny(rok) && uzs) {
        den_++;
      }
      if (den_ < 4648 || den_ >= 5849 + (je_prestupny(rok) ? 1 : 0)) {
        if (den_ > 4648) {
          den_ -= 39 + (je_prestupny(rok) ? 1 : 0);
        }
        carpo = den_ / 1162 + 1;
        den_ -= (carpo-1) * 1162;
      } else {
        carpo = 5;
        den_ -= 4648;
      }
      if ((carpo != 5) || je_prestupny(rok)) {
        for (int i = 0; i < (carpo == 5) ? 30 : 29; i++) {
          if (den_ >= callista[i]) {
            den_ -= callista[i];
          } else {
            den = den_ + 1;
            callisto = i + 1;
            break;
          }
        }
      } else {
        for (int i = 0; i < 30; i++) {
          if (den_ >= callista_r[i]) {
            den_ -= callista_r[i];
          } else {
            den = den_ + 1;
            callisto = i + 1;
            break;
          }
        }
      }
    }

    static float delka_dne() { return 0.413; }//0,413
    virtual int cislo_dne() const {
      int prestupnych = int(rok / 4);
      prestupnych -= int(prestupnych / 11);
      int result = (rok-1) * 10497 + prestupnych + (carpo - 1) * 1162;
      if (carpo > 5) {
        result += je_prestupny(rok) ? 40 : 39;
      }
      if (je_prestupny(rok)) {
        result--;
      }
      if ((carpo != 5) || je_prestupny(rok)) {
        for (int i = callisto - 2; i >= 0; i--) {
          result += callista[i];
        }
      } else {
        for (int i = callisto - 2; i >= 0; i--) {
          result += callista_r[i];
        }
      }
      return result + den - 1;
    }
    virtual void napis() {
      cout << den << "." << callisto << "." << carpo << "." << rok;
    }
};

class Saturn : public Planeta{
  private:
    int titan_p(int t) const {
      if ((t % 12 == 0) && !((phoebe % 4 == 0) && (t == 12))) {
        return 35;
      } else {
        return 36;
      }
    }

  public:
    int rok;
    int phoebe;
    int titan;
    int den;

    Saturn(int* datum) :
      rok(datum[3]),
      phoebe(datum[2]),
      titan(datum[1]),
      den(datum[0])
    { }

    Saturn(int den_) :
      rok(1),
      phoebe(1),
      titan(1),
      den(1)
    {
      while (den_ >= 24425) {
        rok++;
        den_ -= 24425;
      }
      while (den_ >= 4885) {
        phoebe += 4;
        den_ -= 4885;
      }
      while (den_ >= ((phoebe % 4 == 0) ? 1222 : 1221)) {
        phoebe += 1;
        den_ -= (phoebe % 4 == 0) ? 1222 : 1221;
      }
      if (phoebe % 4 == 0) {
        den_++;
      }
      for (int i = 0; i < 34; i++) {
        if (den_ >= titan_p(i)) {
          den_ -= titan_p(i);
        } else {
          den = den_ + 1;
          titan = i + 1;
          break;
        }
      }
    }

    static float delka_dne() { return 0.440428241; }
    virtual int cislo_dne() const {
      int result = (rok-1) * 24425;
      int prestupnych = int((phoebe-1) / 4);
      result += (phoebe-1) * 1221 + prestupnych;
      for (int i = titan - 2; i >= 0; i--) {
        result += titan_p(i);
      }
      return result + den - 1;
    }
    virtual void napis() {
      cout << den << "." << titan << "." << phoebe << "." << rok;
    }
};

class Uran : public Planeta{
  private:
    int oberon_p(int o, int francisco_, int ferdinand_, int rok_) const {
      if ((o % 2 == 0) || ((o == 7) && (francisco_ == 2 || francisco_ == 6 || francisco_ == 12)) ||
          (o == 1 && francisco_ == 14 && ferdinand_ == 1) ||
          (o == 1 && francisco_ == 14 && ferdinand_ == 6 && (rok_ % 40 == 0))) {
        return 19;
      } else {
        return 18;
      }
    }

    int francisco_p(int f, int ferdinand_, int rok_) const {
      if ((f == 2 || f == 6 || f == 12) ||
          (f == 14 && ferdinand_ == 1) ||
          (f == 14 && ferdinand_ == 6 && (rok_ % 40 == 0))) {
        return 260;
      } else {
        return 259;
      }
    }

    int ferdinand_p(int f, int rok_) const {
      if (f == 1 || (f == 6 && (rok_ % 40 == 0))) {
        return 3889;
      } else {
        return 3888;
      }
    }

    int rok_p(int r) const {
      if ((r % 40 == 0)) {
        return 42770;
      } else {
        return 42769;
      }
    }

  public:
    int rok;
    int ferdinand;
    int francisco;
    int oberon;
    int den;

    Uran(int* datum) :
      rok(datum[4]),
      ferdinand(datum[3]),
      francisco(datum[2]),
      oberon(datum[1]),
      den(datum[0])
    { }

    Uran(int den_) :
      rok(1),
      ferdinand(1),
      francisco(1),
      oberon(1),
      den(1)
    {
      while (den_ >= rok_p(rok)) {
        den_ -= rok_p(rok);
        rok++;
      }
      while (den_ >= ferdinand_p(ferdinand, rok)) {
        den_ -= ferdinand_p(ferdinand, rok);
        ferdinand++;
      }
      while (den_ >= francisco_p(francisco, ferdinand, rok)) {
        den_ -= francisco_p(francisco, ferdinand, rok);
        francisco++;
      }
      while (den_ >= oberon_p(oberon, francisco, ferdinand, rok)) {
        den_ -= oberon_p(oberon, francisco, ferdinand, rok);
        oberon++;
      }
      den = den_ + 1;
    }

    static float delka_dne() { return 0.718; }
    virtual int cislo_dne() const {
      int result = 0;
      for (int i = rok; i > 1; i--) {
        result += rok_p(i);
      }
      for (int i = ferdinand; i > 1; i--) {
        result += ferdinand_p(i, rok);
      }
      for (int i = francisco; i > 1; i--) {
        result += francisco_p(i, ferdinand, rok);
      }
      for (int i = oberon; i > 1; i--) {
        result += oberon_p(i, francisco, ferdinand, rok);
      }
      return result + den - 1;
    }
    virtual void napis() {
      cout << den << "." << oberon << "." << francisco << "." << ferdinand << "." << rok;
    }
};

class Neptun : public Planeta{
  private:
    int nereida_p(int n, int halimede_, int neso_, int rok_) const {
      if ((n % 2 == 0) || ((rok_ % 19 == 0) && n == 3 && (neso_ == 2 || neso_ == 2))) {
        if ((rok_ % 779 == 0) || !(halimede_ == 3 && neso_ == 3)) {
          return 513;
        }
      }
      return 512;
    }

    int halimede_p(int h, int neso_, int rok_) const {
      if ((rok_ % 779 != 0) && !(h == 3 && neso_ == 3)) {
        return 2560;
      } else if ((rok_ % 19 == 0) && (neso_ == 2 || neso_ == 2)) {
        return 2563;
      } else {
        return 2562;
      }
    }

    int neso_p(int n, int rok_) const {
      if ((rok_ % 779 != 0) && !(n == 3)) {
        return 12800;
      } else if ((rok_ % 19 == 0) && (n == 2 || n == 2)) {
        return 12815;
      } else {
        return 12810;
      }
    }

    int rok_p(int r) const {
      if (r % 779 == 0) {
        return 89680;
      } else if (r % 19 == 0) {
        return 89678;
      } else {
        return 89668;
      }
    }

  public:
    int rok;
    int neso;
    int halimede;
    int nereida;
    int den;

    Neptun(int* datum) :
      rok(datum[4]),
      neso(datum[3]),
      halimede(datum[2]),
      nereida(datum[1]),
      den(datum[0])
    { }

    Neptun(int den_) :
      rok(1),
      neso(1),
      halimede(1),
      nereida(1),
      den(1)
    {
      while (den_ >= rok_p(rok)) {
        den_ -= rok_p(rok);
        rok++;
      }
      while (den_ >= neso_p(neso, rok)) {
        den_ -= neso_p(neso, rok);
        neso++;
      }
      while (den_ >= halimede_p(halimede, neso, rok)) {
        den_ -= halimede_p(halimede, neso, rok);
        halimede++;
      }
      while (den_ >= nereida_p(nereida, halimede, neso, rok)) {
        den_ -= nereida_p(nereida, halimede, neso, rok);
        nereida++;
      }
      den = den_ + 1;
    }

    static float delka_dne() { return 0.67125; }
    virtual int cislo_dne() const {
      int result = 0;
      for (int i = rok; i > 1; i--) {
        result += rok_p(i);
      }
      for (int i = neso; i > 1; i--) {
        result += neso_p(i, rok);
      }
      for (int i = halimede; i > 1; i--) {
        result += halimede_p(i, neso, rok);
      }
      for (int i = nereida; i > 1; i--) {
        result += nereida_p(i, halimede, neso, rok);
      }
      return result + den - 1;
    }
    virtual void napis() {
      cout << den << "." << nereida << "." << halimede << "." << neso << "." << rok;
    }
};

string int_to_str(int x) {
  if (x == 0) {
    return "0";
  }

  string result = "";
  bool minus = false;
  if (x < 0) {
    x = -x;
    minus = true;
  }
  int zb;
  while (x) {
    zb = x % 10;
    x = ( x-zb ) / 10;
    result.insert(result.begin(), '0' + zb);
  }
  if (minus) {
    result.insert(result.begin(), '-');
  }
  return result;
}

int str_to_int(string s) {
  int result = 0;
  bool minus = false;
  if (s.length() && s[0] == '-') {
    minus = true;
    s.erase(s.begin(),s.begin()+1);
  }
  while (s.length()) {
    result *= 10;
    result += s[0] - '0';
    s.erase(s.begin(),s.begin()+1);
  }
  if (minus) {
    result = -result;
  }
  return result;
}

int main(int argc, char** arg) {
  if (argc < 3) {
    cout << "Použití: program <výchozí planeta> <cílová planeta> <datum...>" << endl;
    cout << "Plantey jsou: MER, VEN, ZEM, MAR, JUP, SAT, URA, NEP" << endl;
    return 1;
  }

  string p_str = arg[1];
  string p2_str = arg[2];
  Planeta* planeta;
  Planeta* planeta2;

  float cislo_dne;
  if (p_str == "MER") {
    if (argc < 4) {
      cout << "Datum na Merkuru: rok" << endl;
      return 1;
    }
    int datum[1] = {str_to_int(arg[3])};
    planeta = new Merkur(datum);
    cislo_dne = planeta->cislo_dne() * Merkur::delka_dne();
  } else if (p_str == "VEN") {
    if (argc < 5) {
      cout << "Datum na Venuši: den(1-2) rok" << endl;
      return 1;
    }
    int datum[2] = {str_to_int(arg[3]), str_to_int(arg[4])};
    planeta = new Venuse(datum);
    cislo_dne = planeta->cislo_dne() * Venuse::delka_dne();
  } else if (p_str == "ZEM") {
    if (argc < 6) {
      cout << "Datum na Zemi: den(1-31) měsíc(1-12) rok" << endl;
      return 1;
    }
    int datum[3] = {str_to_int(arg[3]), str_to_int(arg[4]), str_to_int(arg[5])};
    planeta = new Zeme(datum);
    cislo_dne = planeta->cislo_dne() * Zeme::delka_dne();
  } else if (p_str == "MAR") {
    if (argc < 6) {
      cout << "Datum na Marsu: den(1-38) měsíc(1-18) rok" << endl;
      return 1;
    }
    int datum[3] = {str_to_int(arg[3]), str_to_int(arg[4]), str_to_int(arg[5])};
    planeta = new Mars(datum);
    cislo_dne = planeta->cislo_dne() * Mars::delka_dne();
  } else if (p_str == "JUP") {
    if (argc < 7) {
      cout << "Datum na Jupiteru: den(1-41) callisto(1-30) carpo(1-9) rok" << endl;
      return 1;
    }
    int datum[4] = {str_to_int(arg[3]), str_to_int(arg[4]), str_to_int(arg[5]), str_to_int(arg[6])};
    planeta = new Jupiter(datum);
    cislo_dne = planeta->cislo_dne() * Jupiter::delka_dne();
  } else if (p_str == "SAT") {
    if (argc < 7) {
      cout << "Datum na Saturnu: den(1-37) titan(1-34) phoebe(1-20) rok" << endl;
      return 1;
    }
    int datum[4] = {str_to_int(arg[3]), str_to_int(arg[4]), str_to_int(arg[5]), str_to_int(arg[6])};
    planeta = new Saturn(datum);
    cislo_dne = planeta->cislo_dne() * Saturn::delka_dne();
  } else if (p_str == "URA") {
    if (argc < 8) {
      cout << "Datum na Uranu: den(1-19) oberon(1-14) francisco(1-15) ferdinand(1-11) rok" << endl;
      return 1;
    }
    int datum[5] = {str_to_int(arg[3]), str_to_int(arg[4]), str_to_int(arg[5]), str_to_int(arg[6]), str_to_int(arg[7])};
    planeta = new Uran(datum);
    cislo_dne = planeta->cislo_dne() * Uran::delka_dne();
  } else if (p_str == "NEP") {
    if (argc < 8) {
      cout << "Datum na Naptunu: den(1-513) nereida(1-5) halimede(1-5) neso(1-5) rok" << endl;
      return 1;
    }
    int datum[5] = {str_to_int(arg[3]), str_to_int(arg[4]), str_to_int(arg[5]), str_to_int(arg[6]), str_to_int(arg[7])};
    planeta = new Neptun(datum);
    cislo_dne = planeta->cislo_dne() * Neptun::delka_dne();
  } else {
    cout << "Neznámá planeta: " << p_str << endl;
    return 2;
  }

  if (p2_str == "MER") {
    planeta2 = new Merkur(float(cislo_dne / Merkur::delka_dne()));
  } else if (p2_str == "VEN") {
    planeta2 = new Venuse(float(cislo_dne / Venuse::delka_dne()));
  } else if (p2_str == "ZEM") {
    planeta2 = new Zeme(float(cislo_dne / Zeme::delka_dne()));
  } else if (p2_str == "MAR") {
    planeta2 = new Mars(float(cislo_dne / Mars::delka_dne()));
  } else if (p2_str == "JUP") {
    planeta2 = new Jupiter(float(cislo_dne / Jupiter::delka_dne()));
  } else if (p2_str == "SAT") {
    planeta2 = new Saturn(float(cislo_dne / Saturn::delka_dne()));
  } else if (p2_str == "URA") {
    planeta2 = new Uran(float(cislo_dne / Uran::delka_dne()));
  } else if (p2_str == "NEP") {
    planeta2 = new Neptun(float(cislo_dne / Neptun::delka_dne()));
  } else {
    cout << "Neznámá planeta: " << p2_str << endl;
    delete planeta;
    return 2;
  }

  planeta2->napis();
  cout << endl;

  delete planeta;
  delete planeta2;

  return 0;
}

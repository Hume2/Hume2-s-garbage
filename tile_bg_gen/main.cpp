#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;

string int_to_str(int x) {
  if (x == 0) {
    return "  0";
  }

  string result = "";
  int zb;
  while (x) {
    zb = x % 10;
    x = ( x-zb ) / 10;
    result.insert(result.begin(), '0' + zb);
  }
  return result;
}

int str_to_int(string s) {
  int result = 0;
  while (s.length()) {
    result *= 10;
    result += s[0] - '0';
    s.erase(s.begin(),s.begin()+1);
  }
  return result;
}

int nahodne(int max) {
  int result = rand()%max;
  if (result < 0) {
    result *= -1;
  }
  return result;
}

int** bg_tiles;
int w, h, stred;
int trr;
int var_chance = 1;
int min_y, max_y;

void create_tilemap() {
  int x,y;
  bg_tiles = new int* [w];
  for (x = w-1; x >= 0; x--) {
    bg_tiles[x] = new int [h];
    for (y = h-1; y >= 0; y--) {
      bg_tiles[x][y] = 0;
    }
  }
}

void uloz_tilemap(FILE *f, string zpos, string speed) {
  int x,y;
  string blb = "\n    (tilemap\n      (z-pos " + zpos
      + ")\n      (width " + int_to_str(w)
      + ")\n      (height " + int_to_str(h)
      + ")\n      (speed " + speed
      + ")\n      (speed-y" + speed
      + ")\n      (solid #f"
      + ")\n      (tiles";
  fputs(blb.c_str(),f);
  for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
      blb = " " + int_to_str(bg_tiles[x][y]);
      fputs(blb.c_str(),f);
    }
    fprintf(f,"\n            ");
  }
  fprintf(f,"))\n");
  for (x = w-1; x >= 0; x--) {
    delete[] bg_tiles[x];
  }
  delete[] bg_tiles;
}

void blok(int x, int y, int til) {
  if (x>=0 && x<w && y>=0 && y<h) {
    bg_tiles[x][y] = til;
  }
}

void sloupek(int x, int til, int min_y, int max_y) {
  for (int y = min_y+1; y < max_y; y++) {
    blok(x,y,til);
  }
}

void var_sloupek(int x, int til, int min_y, int max_y) {
  for (int y = min_y+1; y < max_y; y++) {
    blok(x,y,til+5);
    int p = nahodne(100);
    if (p <= var_chance) {
      blok(x,y,til+97);
      p = nahodne(10);
      if (p <= 1) {
        blok(x,y,til+96);
      }
    }
  }
}

void nahorovak(int x, int start, int til, int plus) {
  var_sloupek(x, til, start, h);
  blok(x,start,til+11);
  sloupek(x, til+4, start-plus, start);
  blok(x,start-plus,til+1);
}

void dolovak(int x, int start, int til, int minus) {
  var_sloupek(x, til, start+minus, h);
  blok(x,start+minus,til+10);
  sloupek(x, til+6, start, start+minus);
  blok(x,start,til+3);
}

void stredovak(int x, int start, int til) {
  var_sloupek(x, til, start, h);
  blok(x,start,til+2);
}

void vydlazdickuj(int til) {
  int vyska = stred;
  for (int x = 0; x <= w; x++) {
    int p = 0;
    bool zn = nahodne(2);

    while (nahodne(trr) > 1) {
      p++;
    }

    if (zn) {
      if (vyska+p >= max_y) {
        p = 0;
      } else {
        dolovak(x,vyska,til,p);
        vyska += p;
      }
    } else {
      if (vyska-p < min_y) {
        p = 0;
      } else {
        nahorovak(x,vyska,til,p);
        vyska -= p;
      }
    }
    if (p == 0) {
      stredovak(x,vyska,til);
      continue;
    }
  }
}

void tilemap(FILE *f, string zpos, string speed, int til) {
  cout << "Vytvářím pozadí na z:" << zpos << ", s rychlostí " << speed << endl;
  create_tilemap();
  cout << "Pozadí je připraveno." << endl;
  vydlazdickuj(til);
  cout << "Vydlaždičkováno." << endl;
  uloz_tilemap(f,zpos,speed);
  cout << "Pozadí uloženo." << endl;
}

int main(int argc, char** arg) {
  FILE *f = fopen("out.txt","w");

  if (argc < 3) {
    cout << "A co takhle zadat nějakou výšku a šířku?" << endl;
    cout << "Použití: program <šířka> <výška> [kopcovitost] [výška] [min y] [max y] [semínko]" << endl;
    return 1;
  }

  string w_text = arg[1];
  string h_text = arg[2];

  w = str_to_int(w_text);
  h = str_to_int(h_text);

  if (argc <= 3) {
    trr = 4;
  } else {
    string strext = arg[3];
    trr = str_to_int(strext);
  }

  if (argc <= 4) {
    stred = h/2;
  } else {
    string strext = arg[4];
    stred = str_to_int(strext);
    if (stred > h) {
      cout << "Střední hloubka je větší než výška!" << endl;
      cout << "Zadej parametry znovu a tentokrát se neztrapni." << endl;
      return 2;
    }
  }

  if (argc <= 6) {
    min_y = 0;
    max_y = h;
  } else {
    string strext = arg[5];
    min_y = str_to_int(strext);
    strext = arg[6];
    max_y = str_to_int(strext);
  }

  if (argc <= 7) {
    srandom(time(0));
  } else {
    string strext = arg[7];
    srandom(str_to_int(strext));
  }

  fprintf(f,"    (gradient\n      (top_color 0 0.3137255 1)\n      (bottom_color 1 1 1))");

  cout << "Šířka: " << w << " Výška:" << " " << h << endl;
  cout << "Střední výška terénu: " << stred << endl;
  cout << "Kopcovitost terénu: " << trr << endl;
  cout << "max_y=" << max_y << " min_y=" << min_y << trr << endl;

  trr += 1;
//  string blb = int_to_str(w) + " " + int_to_str(h);
//  fprintf(f,blb.c_str());

  tilemap(f, "-130", "0.5", 148);
  var_chance = 4;
  tilemap(f, "-170", "0.2", 160);

  fclose(f);
  return 0;
}

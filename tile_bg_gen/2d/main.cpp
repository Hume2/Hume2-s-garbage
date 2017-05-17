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
int min_z, max_z;
bool vert = false;
float r_inc_x, r_inc_y;

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

int prumer(int x, int y) {
  if (vert) {
    if (x > 0) {
      if (y > 0) {
        return (bg_tiles[x][y-1] + bg_tiles[x-1][y]) /2;
      } else {
        return bg_tiles[x-1][y];
      }
    } else if (y > 0) {
      return bg_tiles[x][y-1];
    } else {
      return 0;
    }
  } else {
    if (x > 0) {
      if (y < h-1) {
        return (bg_tiles[x][y+1] + bg_tiles[x-1][y]) /2;
      } else {
        return bg_tiles[x-1][y];
      }
    } else if (y < h-1) {
      return bg_tiles[x][y+1];
    } else {
      return 0;
    }
  }
}

void pevnost() {
  int x,y;
  for (x = w-1; x >= 0; x--) {
    for (y = h-1; y >= 0; y--) {
      float mistni_stred = stred + x*r_inc_x + y*r_inc_y;
      bg_tiles[x][y] = bg_tiles[x][y] < mistni_stred;
    }
  }
}

bool je_pevny(int x, int y) {
  if (x < 0) {
    x = 1;
  }
  if (y < 0) {
    y = 1;
  }
  if (x > w-1) {
    x = w-1;
  }
  if (y > h-1) {
    y = h-1;
  }
  return bg_tiles[x][y];
}

bool je_blok_spravne(int x, int y) {
  if (!je_pevny(x,y)) {
    return true;
  }
  bool h = je_pevny(x,y-1), d = je_pevny(x,y+1), l = je_pevny(x-1,y), p = je_pevny(x+1,y);
  if ((!h && !d) || (!l && !p)) {
    return false;
  }

  bool lh = je_pevny(x-1,y-1), ph = je_pevny(x+1,y-1), ld = je_pevny(x-1,y+1), pd = je_pevny(x+1,y+1);
  bool lh2 = l && h, ph2 = p && h, ld2 = l && d, pd2 = p && d;
  bool lh3 = !lh && lh2, ph3 = !ph && ph2, ld3 = !ld && ld2, pd3 = !pd && pd2;
  int rohy = lh3 + ph3 + ld3 + pd3;
  int strany = h + d + l + p;

  if ((strany >= 3) && (rohy <= 1)) {
    return true;
  }

  return !rohy;
}

void x_max(int &x, int &y, int i) {
  if (i & 1) {
    if (i & 4) {
      x = w-1;
    } else {
      x = 0;
    }
  } else {
    if (i & 4) {
      y = h-1;
    } else {
      y = 0;
    }
  }
}

bool x_pod(int x, int y, int i) {
  if (i & 1) {
    if (i & 4) {
      return x >= 0;
    } else {
      return x < w;
    }
  } else {
    if (i & 4) {
      return y >= 0;
    } else {
      return y < h;
    }
  }
}

bool x_inc(int &x, int &y, int i) {
  if (i & 1) {
    if (i & 4) {
      x--;
    } else {
      x++;
    }
  } else {
    if (i & 4) {
      y--;
    } else {
      y++;
    }
  }
}

void uprav_bloky() {
  bool odstraneno = true;
  int i = 1;
  while (odstraneno) {
    i++;
    odstraneno = false;
    int x,y;
    for (x_max(x, y, i); x_pod(x, y, i); x_inc(x, y, i)) {
      for (x_max(x, y, i+1); x_pod(x, y, i+1); x_inc(x, y, i+1)) {
        if (!je_blok_spravne(x,y)) {
          bg_tiles[x][y] = 0; //i;
          odstraneno = true;
        }
      }
    }
  }
}

void blok(int x, int y, int til) {
  if (x>=0 && x<w && y>=0 && y<h) {
    bg_tiles[x][y] = til;
  }
}

void udelej_policko(int x, int y) {
  int p = 0;
  bool zn = nahodne(2);

  while (nahodne(trr) > 1) {
    p++;
  }

  int prum = prumer(x, y);

  if (zn) {
    int zplus = prum + p;
    if (zplus > max_z) {
      bg_tiles[x][y] = prum;
    } else {
      bg_tiles[x][y] = zplus;
    }
  } else {
    int zminus = prum - p;
    if (zminus < min_z) {
      bg_tiles[x][y] = prum;
    } else {
      bg_tiles[x][y] = zminus;
    }
  }
}

void vysky() {
  if (vert) {
    for (int x = 0; x < w; x++) for (int y = 0; y < h; y++) {
      udelej_policko(x, y);
    }
  } else {
    for (int x = 0; x < w; x++) for (int y = h-1; y >= 0; y--) {
      udelej_policko(x, y);
    }
  }
}

void vysky2() {
  vert = true;
  vysky();
  int** prvky2 = bg_tiles;
  create_tilemap();
  vert = false;
  vysky();
  int x,y;
  for (x = w-1; x >= 0; x--) {
    for (y = h-1; y >= 0; y--) {
      bg_tiles[x][y] += prvky2[x][y];
    }
  }
  for (x = w-1; x >= 0; x--) {
    delete[] prvky2[x];
  }
  delete[] prvky2;
}

void dlazdice(int x, int y, int til) {
  if (!je_pevny(x,y)) {
    bg_tiles[x][y] = 0;
    return;
  }
  bool h = je_pevny(x,y-1), d = je_pevny(x,y+1), l = je_pevny(x-1,y), p = je_pevny(x+1,y);

  bool lh = je_pevny(x-1,y-1), ph = je_pevny(x+1,y-1), ld = je_pevny(x-1,y+1), pd = je_pevny(x+1,y+1);
  bool lh2 = l && h, ph2 = p && h, ld2 = l && d, pd2 = p && d;
  bool lh3 = !lh && lh2, ph3 = !ph && ph2, ld3 = !ld && ld2, pd3 = !pd && pd2;
  int rohy = lh3 + ph3 + ld3 + pd3;
  int strany = h + d + l + p;

  if (strany == 4) {
    if (rohy) {
      if (lh3) {
        blok(x,y,til+11);
      } else if (ph3) {
        blok(x,y,til+10);
      } else if (ld3) {
        blok(x,y,til+94);
      } else {
        blok(x,y,til+95);
      }
      return;
    } else {
      blok(x,y,til+5);
      int p = nahodne(100);
      if (p <= var_chance) {
        blok(x,y,til+97);
        p = nahodne(10);
        if (p <= 1) {
          blok(x,y,til+96);
        }
      }
      return;
    }
  }

  bool lh4 = lh && lh2, ph4 = ph && ph2, ld4 = ld && ld2, pd4 = pd && pd2;
  int rohy2 = lh4 + ph4 + ld4 + pd4;

  if (rohy2 >= 2) {
    if (lh4) {
      if (ph4) {
        blok(x,y,til+8);
      } else {
        blok(x,y,til+6);
      }
      return;
    } else {
      if (ph4) {
        blok(x,y,til+4);
      } else {
        blok(x,y,til+2);
      }
      return;
    }
    return;
  }

  if (lh4) {
    blok(x,y,til+9);
  } else if (ph4) {
    blok(x,y,til+7);
  } else if (ld4) {
    blok(x,y,til+3);
  } else {
    blok(x,y,til+1);
  }
}

void vydlazdickuj(int til) {
  int x,y;
  for (x = w-1; x >= 0; x--) {
    for (y = h-1; y >= 0; y--) {
      dlazdice(x, y, til);
    }
  }
}

void tilemap(FILE *f, string zpos, string speed, int til) {
  cout << "Vytvářím pozadí na z:" << zpos << ", s rychlostí " << speed << endl;
  create_tilemap();
  cout << "Pozadí je připraveno." << endl;
  //vydlazdickuj(til);
  vysky2();
  pevnost();
  uprav_bloky();
  vydlazdickuj(til);
  cout << "Vydlaždičkováno." << endl;
  uloz_tilemap(f,zpos,speed);
  cout << "Pozadí uloženo." << endl;
}

int main(int argc, char** arg) {
  FILE *f = fopen("out.txt","w");

  if (argc < 3) {
    cout << "A co takhle zadat nějakou výšku a šířku?" << endl;
    cout << "Použití: program <šířka> <výška> [hrubost] [hustota] [hustota dole] [hustota vpravo] [omezení struktur] [semínko]" << endl;
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
    stred = 0;
  } else {
    string strext = arg[4];
    stred = str_to_int(strext);
  }

  int r_x, r_y;
  if (argc <= 5) {
    r_inc_y = 0;
    r_y = 0;
  } else {
    string strext = arg[5];
    r_y = str_to_int(strext);
    r_inc_y = (r_y - stred) / h;
  }

  if (argc <= 6) {
    r_inc_x = 0;
    r_x = 0;
  } else {
    string strext = arg[6];
    r_x = str_to_int(strext);
    r_inc_x = (r_x - stred) / w;
  }

  if (argc <= 7) {
    min_z = -20;
    max_z = 20;
  } else {
    string strext = arg[7];
    max_z = str_to_int(strext);
    min_z = -max_z;
  }

  if (argc <= 8) {
    srandom(time(0));
  } else {
    string strext = arg[8];
    srandom(str_to_int(strext));
  }

  fprintf(f,"    (gradient\n      (top_color 0 0.3137255 1)\n      (bottom_color 1 1 1))");

  cout << "Šířka: " << w << " Výška:" << " " << h << endl;
  cout << "Hustota ostrovů: " << stred << endl;
  cout << "Hrubost: " << trr << endl;
  cout << "max_z=" << max_z << " min_z=" << min_z << endl;
  cout << "Hustota dole: " << r_y << " Hustota vpravo:" << r_x << endl;

  trr += 1;
//  string blb = int_to_str(w) + " " + int_to_str(h);
//  fprintf(f,blb.c_str());

  tilemap(f, "-130", "0.5", 148);
  var_chance = 4;
  tilemap(f, "-170", "0.2", 160);

  fclose(f);
  return 0;
}

#include <stdio.h>
#include <main.h>

// type def
struct point{
  int x;
  int y;
};

struct point add(struct point a, struct point b){
  struct point c = {0, 0};
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  return c;
}

struct point * add_ref(struct point *_a, struct point *_b){
  struct point a = *_a;
  struct point b = *_b;
  struct point c = {0, 0};
  c.x = a.x + (*_b).x;
  c.y = _a->y + b.y; // variation
  return &c;
}

void st_rct (){
  // var def
  struct point p2d = {1, 1};
  // no-name struct def, val def and assign val
  struct {
    int x;
    int y;
    int z;
  } p3d = {0, 0, 0};
  struct point c = add(p2d, p2d);
  printf("x:%d, y:%d\n", c.x, c.y);
}

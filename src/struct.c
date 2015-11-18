#include <stdio.h>
#include <stdlib.h>
#include <main.h>

// type def
struct point{
  int x;
  int y;
};

struct point add(struct point copy_a, struct point copy_b){
  struct point c = {0, 0};
  c.x = copy_a.x + copy_b.x;
  c.y = copy_a.y + copy_b.y;
  return c;// copy c val to return ptr func
}

struct point * add_ref(struct point * a_ptr, struct point * b_ptr){
  struct point a_stack_val = *a_ptr; // copy val from ptr to add_ref stack
  struct point b_stack_val = *b_ptr; // copy val from ptr to add_ref stack
  struct point * c_heap_ptr = malloc(sizeof(a_stack_val));
  printf("sizeof(char)=%lu\n", sizeof(char));
  printf("sizeof(int)=%lu\n", sizeof(int));
  printf("sizeof(struct point)=%lu\n", sizeof(struct point));
  printf("sizeof(a_stack_val)=%lu\n", sizeof(a_stack_val));
  printf("sizeof(b_stack_val)=%lu\n", sizeof(b_stack_val));
  printf("sizeof(&c_heap_ptr)=%lu\n", sizeof(&c_heap_ptr));
  printf("a_ptr=%08x\n", a_ptr); // caller stack address
  printf("b_ptr=%08x\n", b_ptr); // caller stack address
  printf("&a_stack_val=%08x\n", &a_stack_val); // add_red stack address
  printf("&b_stack_val=%08x\n", &b_stack_val); // add_red stack address
  printf("c_heap_ptr=%08x\n", c_heap_ptr); // heap address
  (*c_heap_ptr).x = a_stack_val.x + b_stack_val.x;
  c_heap_ptr->y = a_ptr->y + (*b_ptr).y; // variation
  return c_heap_ptr;
}

void str_ct (){
  // var def
  struct point p2d = {1, 1};
  // no-name struct def, val def and assign val
  struct {
    int x;
    int y;
    int z;
  } p3d = {0, 0, 0};
  struct point c = add(p2d, p2d);
  struct point * d = add_ref(&p2d, &p2d);
  printf("d->x: %d", (d)->x);
  free(d);
  printf("(&p3d)->x: %d", (&p3d)->x);
  printf("x:%d, y:%d\n", c.x, c.y);
}

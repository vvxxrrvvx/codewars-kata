typedef struct _shape_vtable_t {
  double (*get_area)();
  double (*get_perimeter)();
  void (*destroy)();
} shape_vtable_t;

typedef struct _shape_t {
  shape_vtable_t *vtable;
} shape_t;

double shape_get_area(const void *shape);
double shape_get_perimeter(const void *shape);
void shape_destroy(const void *shape);

typedef struct _right_triangle_t {
  shape_t shape;
  double side1;
  double side2;
} right_triangle_t;

right_triangle_t *right_triangle_create(double side1, double side2);

static double get_area(const right_triangle_t *triangle) {
  return (triangle->side1 * triangle->side2) / 2.0;
}

static double get_perimeter(const right_triangle_t *triangle) {
  double hypotenuse = sqrt((triangle->side1 * triangle->side1) + (triangle->side2 * triangle->side2));
  return triangle->side1 + triangle->side2 + hypotenuse;
}

static void destroy(const right_triangle_t *triangle) {
  free(triangle);
}

static shape_vtable_t right_triangle_vtable = {
  get_area,
  get_perimeter,
  destroy
};

right_triangle_t *right_triangle_create(double side1, double side2) {
  right_triangle_t *triangle = malloc(sizeof(right_triangle_t));
  triangle->shape.vtable = &right_triangle_vtable;
  triangle->side1 = side1;
  triangle->side2 = side2;
  return triangle;
}
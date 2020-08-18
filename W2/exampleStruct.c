#include <stdio.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
        char name[10];
        int age;
        Point location;        
    } Animal;

void initAnimal(Animal *animal) {
    scanf("%9s %d", animal->name, &(animal->age));
    scanf("%d %d", &(animal->location.x), &(animal->location.y));
}

void printAnimal(Animal *animal) {
    printf("%s is %d years old, ", animal->name, animal->age);
    printf("located at (%d, %d)\n", animal->location.x, animal->location.y);
}

void moveAnimal(Animal *animal, Point location) {
    animal->location.x = location.x;
    animal->location.y = location.y;
}

int isEqualPoint(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

int main() {
    Animal hamster;
    Animal snake;
    
    initAnimal(&hamster);
    initAnimal(&snake);
    
    printAnimal(&hamster);
    printAnimal(&snake);
    
    moveAnimal(&snake, hamster.location);
    
    printAnimal(&hamster);
    printAnimal(&snake);
    
    if ( isEqualPoint(snake.location, hamster.location) ) {
        printf("Hamster %s is dead, ", hamster.name);
        printf("snake %s is happy.\n", snake.name);
    }
    
    // Animal hamster = {"Mike", 4, {2, 3}};
    
    // Animal *p = &hamster;
    
    // printf("%p\n", p);
    // printf("%p\n", p->name);
    // printf("%p\n", &p->age);
    // printf("%lu\n", sizeof(hamster));
    
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int width, height;
    float cost;

    int x1, x2, y1, y2;
    cin >> width >> height >> cost >> x1 >> y1 >> x2 >> y2;

    if (x1 > width || x2 > width) {
        cout << "This place isn't on the map";
    }

    if (y1 > height || y2 > height) {
        cout << "This place isn't on the map";
    }

    int blocks_travelled = (int)(abs(x1 - x2) + abs(y1 - y2));
    if (cost == 0) {
        cout << "You got a free ride and you will have traveled "
             << blocks_travelled << "blocks";
    } else {
        float total_cost = cost * blocks_travelled;
        printf("The trip will cost %.2f and you will have travelled %d blocks",
               total_cost, blocks_travelled);
    }
    return 0;
}
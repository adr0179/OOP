#include "methods.cpp"

int main() {
    srand(time(NULL));
    cout << "how many?" << endl;
    int num_of_pos;
    cin >> num_of_pos;
    PhysicsObject* pos = new PhysicsObject[num_of_pos];
    for (int i = 0; i < num_of_pos; i++) {
        cout << pos[i].toString() << endl;
    }
}
#include <iostream>
#include "Headers/hash_table.h"
#include "unordered_map"

struct Point {
    Point(double dval, int ival) 
    : d{dval}
    , i{ival} { }
    friend std::ostream& operator<<(std::ostream& os, const Point& pt);
    bool operator==(const Point& oth) const {
        return (this->d == oth.d) && (this->i == oth.i);
    }
    bool operator!=(const Point& oth) {
        return ! (this == &oth);
    }
    int getI() const {
        return i;
    }
private:
    double d;
    int i;
};

std::ostream& operator<<(std::ostream& os, const Point& pt) {
    os << pt.d << " " << pt.i;
    return os;
}

template<typename Key>
struct PointHash {
    std::size_t operator()(const Key& key) {
        return 0;
    }
};

template <>
struct PointHash<Point> {
    std::size_t operator()(const Point& point) {
        return point.getI();
    }
};

bool test_all_of(HashTable<std::string,int> ht) {
    return std::all_of(ht.begin(), ht.end(),
            [](const auto& pair) { return pair.second > 0; });
}

int main() {
    Point p1(4.34,5);
    HashTable<Point,int, PointHash<Point>> hPoint;
    hPoint[p1] = 4;
    // hPoint.print();
    std::cout << hPoint[p1];

    // HashTable<int,int> h1;
    // h1[4] = 5;
    // std::cout << h1[4];
}
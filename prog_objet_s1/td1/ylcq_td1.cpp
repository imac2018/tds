// Fichtre, il était gros pour un 1er TD !
//
// Compiler avec :
//     g++ -Wall -std=c++11 ylcq_td1.cpp
// Puis:
//     ./a.out
//
// Normalement y'a pas besoin de C++11, c'est juste que
// j'utilise une feature qui permet à Vector2Df d'hériter
// des constucteurs de sa classe parent, Point2Df.

#include <iostream>// std::cout, etc.
#include <complex> // std::complex<>, std::polar()
#include <cmath>   // sqrtf(), etc.
#include <cstdlib> // EXIT_SUCCESS
#include <vector>  // std::vector<>
#include <string>  // std::string

// M_PI n'est pas standard, ni un float.
const float PI_F = acosf(-1.f);

// Un truc tout pourri et discriminatoire des autres pays
class Address {
private:
    unsigned postalCode;
    std::string street;
public:
    void        setStreet(std::string s)  { street = s; }
    std::string getStreet()     const     { return street; }
    void        setPostalCode(unsigned p) { postalCode = p; }
    unsigned    getPostalCode() const     { return postalCode; }
};

class Person {
private:
    std::string name;
    unsigned age, height;
    Address address;
public:
    Person() {}
    ~Person() {}
    void        setName(std::string val) { name = val; }
    std::string getName()        const   { return name; }
    void        setAge(unsigned val)     { age = val; }
    unsigned    getAge()         const   { return age; }
    void        setHeigth(unsigned val)  { height = val; }
    unsigned    getHeigth()      const   { return height; }
    void        setAddress(Address a)    { address = a; }
    Address     getAddress(void) const   { return address; }
    void        printName()      const   { std::cout <<   name << std::endl; }
    void        printAge()       const   { std::cout <<    age << std::endl; }
    void        printHeight()    const   { std::cout << height << std::endl; }
    void        print()          const   { printName(); printAge(); printHeight(); }
};



class Point2Df {
protected: // comme private, mais aussi accessible par les sous-classes.
    float x,y;
public:
    // Construire un Point2Df avec des coordonnées cartésiennes :
    //     Point2Df bar(0.f, 2.f);
    // 
    // Construire un Point2Df avec des coordonnées polaires (magnitude, angle) :
    //     Point2Df foo(std::polar(2.f, PI_F/2.f));
    // 
    // Dans ces exemples, les points foo et bar sont en effet identiques.
    //
    // Autre exemple plus........ **complexe** ?? (toudoum tss)
    //     Point2Df baz(0.5f*cosf(PI_F/3.f), 0.5f*sinf(PI_F/3.f));
    //     Point2Df qux(std::polar(0.5f, PI_F/3.f));
    //
    Point2Df(float x, float y) : x(x), y(y) {}
    Point2Df(std::complex<float> cmplx) {
        x = std::abs(cmplx)*cosf(std::arg(cmplx));
        y = std::abs(cmplx)*sinf(std::arg(cmplx));
    }
    void  printCartesian() const { std::cout << "{ x: " << x << ", y: " << y << " }"; }
    void  print()          const { printCartesian(); }
    void  printPolar()     const { /* TODO, mais au final c'est pas demandé. */ }
    float getX()           const { return x; }
    float getY()           const { return y; }
    void  setX(float xx)         { x = xx; }
    void  setY(float yy)         { y = yy; }
    static float distance(const Point2Df &a, const Point2Df &b) {
        Point2Df v(b.x-a.x, b.y-a.y);
        return sqrtf(v.x*v.x + v.y*v.y);
    }
    float distanceFrom(const Point2Df &p) const { return distance(*this, p); }
    void translate(float xx, float yy) { x += xx, y += yy; };
    // Non testé
    void operator+=(const Point2Df &p) { translate(p.x, p.y); }
};

// 5. Vector doit hériter de Point.
class Vector2Df : public Point2Df {
    // float x,y; 
    // Hérités de Point2Df, et accessibles
    // car leur visibilité est 'protected' et non 'private'.
public:
    // C++11: Hériter des constructeurs de la classe parent.
    // Sans C++11, il faudrait manuellement réécrire un constructeur.
    using Point2Df::Point2Df; 

    // Il demande "scalar product", mais le nom "dot product" est simplement plus répandu.
    static float dotProduct(const Vector2Df &u, const Vector2Df &v) {
        return u.x*v.x + u.y*v.y;
    }
    float     dotProductWith(const Vector2Df &v) const { return dotProduct(*this, v); }
    Vector2Df add(const Vector2Df &v)            const { return Vector2Df(x+v.x, y+v.y); }
    Vector2Df sub(const Vector2Df &v)            const { return Vector2Df(x-v.x, y-v.y); }
    float     getEuclidianNorm()                 const { return sqrtf(x*x + y*y); }
    float     getLength()                        const { return getEuclidianNorm(); }
    static float cosineSimilarity(const Vector2Df &u, const Vector2Df &v) {
        return dotProduct(u, v) / (u.getEuclidianNorm() * v.getEuclidianNorm());
    }
    float cosineSimilarityWith(const Vector2Df &v) const { 
        return cosineSimilarity(*this, v); 
    }
    // void print() {} // Pas besoin, on en hérite.
};


class LineSegment2Df {
private:
    Point2Df a, b;
public:
    Point2Df getA()      const { return a; }
    Point2Df getB()      const { return b; }
    void     setA(Point2Df aa) { a = aa; }
    void     setB(Point2Df bb) { b = bb; }
    float    getLength() const { return a.distanceFrom(b); }
    void     print()     const { 
        std::cout << "{ a: "; a.print();
        std::cout << ",  b: "; b.print();
        std::cout << " }";
    }
};

class Circle2Df {
private:
    Point2Df center;
    float radius;
public:
    float getDiameter()  const { return 2.f*radius; }
    float getRadius()    const { return radius; }
    float getPerimeter() const { return 2.f*M_PI*radius; }
    float getArea()      const { return M_PI*radius*radius; }
    void  print()        const {
        std::cout << "{ center: "; center.print();
        std::cout << ", radius: " << radius << " }";
    }
};

class Rectangle2Df {
private:
    Point2Df center;
    Vector2Df size;
    float rotation; // Ce n'est pas demandé, mais je trouve que ça a du sens.
                    // Sinon, ça serait une AABB (Axis-Aligned Bounding Box).
public:
    float getArea()      const { return size.getX()*size.getY(); }
    float getPerimeter() const { return 2.f*(size.getX() + size.getY()); }
    float getDiagonal()  const { return size.getLength(); }
    void print()         const {
        std::cout << "{ center: "; center.print();
        std::cout << ", size: "; size.print();
        std::cout << ", rotation: " << rotation << " }";
    }
};

typedef Point2Df Vertex2Df;

class Polygon2Df {
private:
    std::vector<Vertex2Df> vertices; // Le premier sommet est aussi le dernier.
public:
    // XXX Cette fonction pré-suppose que notre polygone est convexe.
    //     Les angles concaves seront erronés. Je compte pas changer ça.
    std::vector<float> getInnerAnglesList() { 
        std::vector<float> angles;
        const size_t v_count = vertices.size();
        for(size_t i=0 ; i<v_count ; ++i) {
            //
            //            v1
            //           .
            //          / \     -
            //         /\_/\ <--- L'angle qu'on calcule.
            //        /     \   -
            //       /       \  -
            // . __ .         . ____ .
            //       v0        v2
            //
            const Vertex2Df &v0 = vertices[(i+v_count-1)%v_count];
            const Vertex2Df &v1 = vertices[i];
            const Vertex2Df &v2 = vertices[(i+1)%v_count];
            // Argh. Ca mériterait un constructeur dédié.
            const Vector2Df u(v0.getX()-v1.getX(), v0.getY()-v1.getY());
            const Vector2Df v(v2.getX()-v1.getX(), v2.getY()-v1.getY());
            angles.push_back(acosf(Vector2Df::cosineSimilarity(u, v)));
        }
        return angles;
    }
    float getPerimeter() { 
        float perim = 0.f;
        size_t i; 
        for(i=1 ; i<vertices.size() ; ++i)
            perim += vertices[i-1].distanceFrom(vertices[i]);
        perim += vertices[i-1].distanceFrom(vertices[0]);
        return perim;
    }
    void print() {
        size_t i; 
        std::cout << "{";
        for(i=0 ; i<vertices.size()-1 ; ++i)
            std::cout << "v" << i << ": ", vertices[i].print(), std::cout << ", ";
        std::cout << "v" << i << ": ", vertices[i].print();
        std::cout << "}";
    }
};

int main(void) {
    std::cout 
        << "Quoi, t'as vraiment cru que j'allais tester toutes mes fonctions ? x)" 
        << std::endl;
    return EXIT_SUCCESS;
}
